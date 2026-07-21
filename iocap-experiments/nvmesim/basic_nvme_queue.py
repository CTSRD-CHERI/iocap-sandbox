import abc
import argparse
import datetime
import math
import random
import tomllib
from dataclasses import dataclass
from pathlib import Path
from typing import Dict, Generic, List, Mapping, TextIO, Tuple, TypeVar

import numpy as np
from typing_extensions import override


class Sim:
    time_ns: int
    upcoming_events: List["SimEvent"]
    actors: List["SimActor"]

    def __init__(self) -> None:
        self.time_ns = 0
        self.upcoming_events = []
        self.actors = []

    def loop(self):
        while self.upcoming_events:
            if len(self.upcoming_events) == 1:
                self.time_ns = self.upcoming_events[0].time_ns
                e = self.upcoming_events[0]
                self.upcoming_events.clear()
                e.participant.handle_event(e)
            else:
                self.upcoming_events.sort(key=lambda e: (e.time_ns, e.priority))
                self.time_ns = self.upcoming_events[0].time_ns
                for i in range(len(self.upcoming_events)):
                    if self.upcoming_events[i].time_ns != self.time_ns:
                        break
                current_events = self.upcoming_events[:i]
                self.upcoming_events = self.upcoming_events[i:]
                # print(self.time_ns, current_events)
                for e in current_events:
                    e.participant.handle_event(e)

    def schedule_event(self, event: "SimEvent"):
        assert event.time_ns > self.time_ns
        # this doesnt work :/
        # if event in self.upcoming_events:
        #     return
        self.upcoming_events.append(event)


class SimActor:
    sim: Sim
    name: str
    trace_file: TextIO | None

    def __init__(self, sim: Sim, name: str):
        self.sim = sim
        self.name = name
        sim.actors.append(self)
        self.trace_file = None

    @abc.abstractmethod
    def schedule_pre_sim_events(self): ...

    @abc.abstractmethod
    def handle_event(self, event: "SimEvent"): ...

    def export_stats(self, prefix: str, file: TextIO):
        print(f"\n[{self.name}]", file=file)

    def __hash__(self) -> int:
        return hash(self.name)

    def __eq__(self, value: object, /) -> bool:
        return id(self) == id(value)


class SimEvent:
    participant: SimActor
    time_ns: int
    priority: int

    def __init__(
        self,
        participant: SimActor,
        time_ns: int,
        priority: int,
    ) -> None:
        self.participant = participant
        self.time_ns = time_ns
        self.priority = priority


@dataclass
class SubmissionQueueEntry:
    start_time_ns: int
    is_read: bool
    is_complete: bool
    is_valid: bool

    @staticmethod
    def invalid() -> "SubmissionQueueEntry":
        return SubmissionQueueEntry(
            start_time_ns=-1,
            is_read=False,
            is_complete=False,
            is_valid=False,
        )


T = TypeVar("T")


class Queue(Generic[T]):
    entries: List[T]
    head: int
    tail: int

    def __init__(self, entries: List[T]):
        super().__init__()
        self.entries = entries
        self.head = 0
        self.tail = 0

    def indices_from_head_to(self, new_head) -> List[int]:
        return (
            list(range(self.head, new_head))
            if new_head > self.head
            else (list(range(self.head, len(self.entries))) + list(range(new_head)))
        )

    def indices_from_tail_to(self, new_tail) -> List[int]:
        return (
            list(range(self.tail, new_tail))
            if new_tail > self.tail
            else (list(range(self.tail, len(self.entries))) + list(range(new_tail)))
        )

    def is_empty(self) -> bool:
        return self.head == self.tail

    def is_full(self) -> bool:
        return ((self.tail + 1) % len(self.entries)) == self.head

    def get_head(self) -> T | None:
        if self.is_empty():
            return None
        return self.entries[self.head]


class NvmeSubmissionQueue(Queue[SubmissionQueueEntry]):
    def __init__(self, n: int):
        super().__init__([SubmissionQueueEntry.invalid() for i in range(n)])

    def insert_at_tail(self, entry: SubmissionQueueEntry) -> int:
        assert not self.is_full()
        # assert entry.end_time_ns > entry.start_time_ns
        assert not entry.is_complete
        assert entry.is_valid
        inserted_idx = self.tail
        self.entries[inserted_idx] = entry
        self.tail = (self.tail + 1) % len(self.entries)
        return inserted_idx

    def mark_entry_complete(self, idx: int) -> None:
        assert self.entries[idx].is_valid
        assert not self.entries[idx].is_complete
        self.entries[idx].is_complete = True

    def move_head_as_far_as_possible(self) -> None:
        if self.is_empty():
            return
        # assert not self.entries[self.head].is_complete
        idx = self.head
        while (
            idx != self.tail
            and self.entries[idx].is_valid
            and self.entries[idx].is_complete
        ):
            idx = (idx + 1) % len(self.entries)
        if idx != self.head:
            self.move_head(idx)

    def move_head(self, new_head: int) -> None:
        assert not self.is_empty()
        new_head = new_head % len(self.entries)
        touched_entries = self.indices_from_head_to(new_head)
        # print(self.head, new_head, touched_entries)
        assert self.tail not in touched_entries
        assert all(self.entries[i].is_complete for i in touched_entries)
        self.head = new_head


# @dataclass
# class CompletionQueueEntry:
#     completed_idx: int
#     new_head: int
#     is_valid: bool

#     @staticmethod
#     def invalid() -> "CompletionQueueEntry":
#         return CompletionQueueEntry(
#             completed_idx=-1,
#             new_head=-1,
#             is_valid=False,
#         )


# class NvmeCompletionQueue:
#     entries: List[CompletionQueueEntry]
#     head: int
#     tail: int

#     def __init__(self, n: int):
#         super().__init__()
#         self.entries = [CompletionQueueEntry.invalid() for i in range(n)]
#         self.head = 0
#         self.tail = 0


class RateLimiter:
    sim: Sim
    rate_step: int
    last_time: int
    has_scheduled: bool

    def __init__(self, sim: Sim, rate_step: int) -> None:
        self.sim = sim
        self.rate_step = rate_step
        self.last_time = -1

    def available(self) -> bool:
        if self.last_time < 0:
            return True
        return (self.sim.time_ns - self.last_time) >= self.rate_step

    def next_time(self):
        assert not self.available()
        self.has_scheduled = True
        return self.last_time + self.rate_step

    def mark_taken(self) -> None:
        self.last_time = self.sim.time_ns
        self.has_scheduled = False


class NvmeStimulus:
    gen: random.Random
    n_stims: int
    stims_so_far: int
    read_chance: int

    def __init__(self, gen: random.Random, n_stims: int, read_chance: int) -> None:
        super().__init__()
        self.gen = gen
        self.n_stims = n_stims
        self.stims_so_far = 0
        self.read_chance = read_chance

    def has_submission(self) -> bool:
        return self.stims_so_far < self.n_stims

    def next_submission(self, time_ns: int) -> SubmissionQueueEntry:
        assert self.stims_so_far < self.n_stims
        self.stims_so_far += 1
        if self.stims_so_far == self.n_stims:
            print("Exhausted Stims")
        elif self.stims_so_far % 1000 == 0:
            print(f"Executed {self.stims_so_far}")

        if self.read_chance == 0:
            is_read = False
        elif self.read_chance == 100:
            is_read = True
        else:
            is_read = self.gen.uniform(0, 1) * 100 < self.read_chance

        return SubmissionQueueEntry(
            start_time_ns=time_ns,
            is_read=is_read,
            is_complete=False,
            is_valid=True,
        )


@dataclass(unsafe_hash=True)
class NvmeTryPushNewEvent(SimEvent):
    def __init__(self, participant: SimActor, time_ns: int) -> None:
        super().__init__(participant, time_ns, priority=2)


@dataclass(unsafe_hash=True)
class NvmeCompletionEvent(SimEvent):
    completed_idx: int

    def __init__(self, participant: SimActor, time_ns: int, completed_idx: int) -> None:
        super().__init__(participant, time_ns, priority=1)
        self.completed_idx = completed_idx


@dataclass
class IOCapLeaseState:
    opened_at_ns: int | None
    exposed_times: List[int]
    completed_times: List[int]


class IOCapLeaseContext(Generic[T]):
    l_ops: int

    # statistics
    leases: List[IOCapLeaseState]
    op_id_to_lease: Dict[T, int]
    next_lease: int

    exposed_to_unexposed_deltas: List[np.ndarray]
    completed_to_unexposed_deltas: List[np.ndarray]

    def __init__(self, l_ops: int) -> None:
        self.l_ops = l_ops
        self.leases = []
        self.op_id_to_lease = {}
        self.exposed_to_completed_deltas = []
        self.exposed_to_unexposed_deltas = []
        self.completed_to_unexposed_deltas = []

    def op_exposed(self, time_ns: int, op_id: T):
        if op_id in self.op_id_to_lease:
            raise RuntimeError("already exposed")
        # look for an open lease
        if all(len(l.exposed_times) == self.l_ops for l in self.leases):
            # all leases are full, make a new one
            self.next_lease = len(self.leases)
            self.leases.append(
                IOCapLeaseState(
                    opened_at_ns=None,
                    exposed_times=[],
                    completed_times=[],
                )
            )
        else:
            # search through the existing leases for one to use
            while len(self.leases[self.next_lease].exposed_times) == self.l_ops:
                self.next_lease = (self.next_lease + 1) % len(self.leases)

        next_lease = self.leases[self.next_lease]
        assert len(next_lease.exposed_times) < self.l_ops
        if len(next_lease.exposed_times) == 0:
            next_lease.opened_at_ns = time_ns
            next_lease.exposed_times = [time_ns]
            next_lease.completed_times = []
        else:
            next_lease.exposed_times.append(time_ns)
        self.op_id_to_lease[op_id] = self.next_lease

    def op_completed(self, time_ns: int, op_id: T):
        if op_id not in self.op_id_to_lease:
            raise RuntimeError("not already exposed")
        lease_id = self.op_id_to_lease[op_id]
        del self.op_id_to_lease[op_id]
        lease = self.leases[lease_id]
        lease.completed_times.append(time_ns)
        if len(lease.completed_times) == len(lease.exposed_times):
            # TODO accumulate latencies
            exposed_times = np.array(lease.exposed_times, dtype=np.int64)
            completed_times = np.array(lease.completed_times, dtype=np.int64)

            self.exposed_to_unexposed_deltas.append(time_ns - exposed_times)
            self.completed_to_unexposed_deltas.append(time_ns - completed_times)
            lease.opened_at_ns = None
            lease.completed_times = []
            lease.exposed_times = []

    def export_stats(self, prefix: str, file: TextIO):
        print(f"\n[{prefix}iocap{self.l_ops:02d}]", file=file)
        exposed_to_unexposed = np.concat(self.exposed_to_unexposed_deltas)
        completed_to_unexposed = np.concat(self.completed_to_unexposed_deltas)
        dense_percentiles = [99.1, 99.2, 99.3, 99.4, 99.5, 99.6, 99.7, 99.8, 99.9]
        percentiles = range(0, 101)

        print(
            f"max_leases_used = {len(self.leases)}",
            file=file,
        )
        print(
            f"exposed_to_unexposed   = {np.round(np.percentile(exposed_to_unexposed, percentiles), 1).tolist()}",
            file=file,
        )
        print(
            f"exposed_to_unexposed_dense   = {np.round(np.percentile(exposed_to_unexposed, dense_percentiles), 1).tolist()}",
            file=file,
        )

        print(
            f"completed_to_unexposed = {np.round(np.percentile(completed_to_unexposed, percentiles), 1).tolist()}",
            file=file,
        )
        print(
            f"completed_to_unexposed_dense = {np.round(np.percentile(completed_to_unexposed, dense_percentiles), 1).tolist()}",
            file=file,
        )


class IOCapManyLeaseContext(Generic[T]):
    contexts: List[IOCapLeaseContext[T]]

    def __init__(self, l_ops_s: List[int]) -> None:
        self.contexts = [
            IOCapLeaseContext(l_ops)  #
            for l_ops in l_ops_s
        ]

    def op_exposed(self, time_ns: int, op_id: T):
        for c in self.contexts:
            c.op_exposed(time_ns, op_id)

    def op_completed(self, time_ns: int, op_id: T):
        for c in self.contexts:
            c.op_completed(time_ns, op_id)

    def export_stats(self, prefix: str, file: TextIO):
        for c in self.contexts:
            c.export_stats(prefix, file)


class NvmeQueuePair(SimActor):
    stimulus: NvmeStimulus
    submission: NvmeSubmissionQueue
    # completion: NvmeCompletionQueue
    new_stim_delay_ns: int
    iocap_contexts: IOCapManyLeaseContext[int]

    completer: "NvmeCompleter | None"

    exposed_to_completed_deltas: np.ndarray
    exposed_to_completed_deltas_i: int

    tell_completer_to_pull: bool

    first_submit_time_ns: int = -1
    n_submits: int = 0
    last_submit_time_ns: int = 0

    parent_iocap_context: IOCapManyLeaseContext[Tuple[str, int]]

    rate: RateLimiter

    def __init__(
        self,
        sim: Sim,
        name: str,
        stimulus: NvmeStimulus,
        q_ops: int,
        new_stim_delay_ns: int,
        iocap_l_ops: List[int],
        tell_completer_to_pull: bool,
        parent_iocap_context: IOCapManyLeaseContext,
    ):
        super().__init__(sim, name)
        self.stimulus = stimulus
        self.submission = NvmeSubmissionQueue(q_ops)
        self.new_stim_delay_ns = new_stim_delay_ns
        assert self.new_stim_delay_ns > 0
        self.iocap_contexts = IOCapManyLeaseContext(iocap_l_ops)
        self.exposed_to_completed_deltas = np.zeros(stimulus.n_stims)
        self.exposed_to_completed_deltas_i = 0
        self.completer = None
        self.tell_completer_to_pull = tell_completer_to_pull
        self.parent_iocap_context = parent_iocap_context
        self.rate = RateLimiter(sim, self.new_stim_delay_ns)

    def print_lease_trace(self):
        if self.trace_file:  # TODO allow selecting which context
            iocap_context = self.iocap_contexts.contexts[
                len(self.iocap_contexts.contexts) // 2
            ]

            def str_idx(i):
                return (
                    f"{iocap_context.op_id_to_lease[i]:2d}"
                    if i in iocap_context.op_id_to_lease
                    else " X"
                )

            # print(f"{self.name}", file=self.trace_file)
            print(
                "\n"
                + "".join(
                    [
                        " H"
                        if i == self.submission.head
                        else (" T" if i == self.submission.tail else "  ")
                        for i in range(len(self.submission.entries))
                    ]
                ),
                file=self.trace_file,
            )
            print(
                "".join(str_idx(i) for i in range(len(self.submission.entries))),
                file=self.trace_file,
            )

    def submit_new(self):
        if not self.stimulus.has_submission():
            return
        if not self.rate.available():
            if not self.rate.has_scheduled:
                self.sim.schedule_event(
                    NvmeTryPushNewEvent(participant=self, time_ns=self.rate.next_time())
                )
            return
        self.sim.schedule_event(
            NvmeTryPushNewEvent(
                participant=self,
                time_ns=self.sim.time_ns + self.new_stim_delay_ns,
            )
        )
        if self.submission.is_full():
            return
        self.rate.mark_taken()
        next_sub = self.stimulus.next_submission(self.sim.time_ns)
        inserted_idx = self.submission.insert_at_tail(next_sub)
        self.iocap_contexts.op_exposed(self.sim.time_ns, inserted_idx)
        self.parent_iocap_context.op_exposed(
            self.sim.time_ns, (self.name, inserted_idx)
        )
        self.print_lease_trace()

        # IOPS bookkeeping
        if self.first_submit_time_ns < 0:
            self.first_submit_time_ns = self.sim.time_ns
        self.last_submit_time_ns = self.sim.time_ns
        self.n_submits += 1

        if self.tell_completer_to_pull and self.completer:
            self.sim.schedule_event(
                NvmeTryPullNewEvent(
                    participant=self.completer,
                    time_ns=self.sim.time_ns + 1,
                )
            )

    def handle_completion(self, completed_idx: int) -> None:
        self.submission.mark_entry_complete(completed_idx)
        self.exposed_to_completed_deltas[self.exposed_to_completed_deltas_i] = (
            self.sim.time_ns - self.submission.entries[completed_idx].start_time_ns
        )
        self.exposed_to_completed_deltas_i += 1
        self.iocap_contexts.op_completed(self.sim.time_ns, completed_idx)
        self.parent_iocap_context.op_completed(
            self.sim.time_ns, (self.name, completed_idx)
        )
        self.print_lease_trace()
        self.submission.move_head_as_far_as_possible()

    @override
    def handle_event(self, event: "SimEvent"):
        if isinstance(event, NvmeTryPushNewEvent):
            self.submit_new()
        elif isinstance(event, NvmeCompletionEvent):
            self.handle_completion(event.completed_idx)
            self.submit_new()

    @override
    def schedule_pre_sim_events(self):
        self.submit_new()

    @override
    def export_stats(self, prefix: str, file: TextIO):
        assert not self.stimulus.has_submission()
        super().export_stats(prefix, file)
        period_ns = self.last_submit_time_ns - self.first_submit_time_ns
        # period_s = period_ns / 1e9
        iops = (self.n_submits / period_ns) * 1.0e9
        print(f"iops = {iops}", file=file)

        percentiles = range(0, 101)
        print(
            f"exposed_to_completed   = {np.percentile(self.exposed_to_completed_deltas, percentiles).tolist()}",
            file=file,
        )
        self.iocap_contexts.export_stats(f"{prefix}{self.name}.", file)


@dataclass(unsafe_hash=True)
class NvmeTryPullNewEvent(SimEvent):
    def __init__(self, participant: SimActor, time_ns: int) -> None:
        super().__init__(participant, time_ns, priority=3)


class NvmeCompleter(SimActor):
    gen: random.Random
    # evenly-distributed histogram
    # TODO these aren't histograms they're percentile maps
    histogram_r: List[int]
    histogram_w: List[int]
    # Save the index within each queue separately from the queue.head
    queues: List[Tuple[NvmeQueuePair, int]]
    round_robin_queue_idx: int
    pull_completion_delay_ns: int
    queues_trigger_pull: bool

    rate: RateLimiter

    first_start_time_ns: int = -1
    n_completions: int = 0
    last_start_time_ns: int = 0

    def __init__(
        self,
        sim: Sim,
        name: str,
        gen: random.Random,
        histogram_r: List[int],
        histogram_w: List[int],
        queues: List[NvmeQueuePair],
        pull_completion_delay_ns: int,
        queues_trigger_pull: bool,
    ):
        super().__init__(sim, name)
        self.gen = gen
        self.histogram_r = histogram_r
        self.histogram_w = histogram_w
        assert len(self.histogram_r) > 1
        assert len(self.histogram_w) > 1
        self.queues = [
            (q, 0)  #
            for q in queues
        ]
        for q in queues:
            q.completer = self
        self.round_robin_queue_idx = 0
        self.pull_completion_delay_ns = pull_completion_delay_ns
        self.queues_trigger_pull = queues_trigger_pull
        self.rate = RateLimiter(sim, self.pull_completion_delay_ns)

    def sample_histogram(self, x: float, histogram: List[int]) -> int:
        if x >= 1.0:
            return histogram[-1]

        # find the two indices x is between and lerp
        x_in_h_space = x * (len(histogram) - 1)
        x_base = math.floor(x_in_h_space)
        x_prog = x_in_h_space - x_base
        start, end = histogram[x_base], histogram[x_base + 1]
        val = round(start + (end - start) * x_prog)
        # print(start, end, val)
        return val

    def schedule_completion(self, queue: NvmeQueuePair, take_from: int) -> bool:
        if queue.submission.is_empty():
            return False

        s = queue.submission.entries[take_from]
        if not s.is_valid or s.is_complete:
            return False

        # assert s.is_valid and not s.is_complete

        length_ns = self.sample_histogram(
            # beta 1-1 has completely linear CDF (i.e. <0.1 is 10% likely, <0.5 is 50% likely, >0.5 is 50% likely, >0.9 is 10% likely etc)
            # which should be exactly what I want for sampling a histogram
            self.gen.betavariate(alpha=1, beta=1),
            self.histogram_r if s.is_read else self.histogram_w,
        )  # TODO tweak distribution?
        assert length_ns > 0

        # IOPS bookkeeping
        if self.first_start_time_ns < 0:
            self.first_start_time_ns = self.sim.time_ns
        self.last_start_time_ns = self.sim.time_ns
        self.n_completions += 1

        self.sim.schedule_event(
            NvmeCompletionEvent(
                participant=queue,
                time_ns=self.sim.time_ns + length_ns,
                completed_idx=take_from,
            )
        )
        return True

    def schedule_pre_sim_events(self):
        if not self.queues_trigger_pull:
            self.sim.schedule_event(
                NvmeTryPullNewEvent(
                    participant=self,
                    time_ns=self.pull_completion_delay_ns,
                )
            )

    def handle_event(self, event: "SimEvent"):
        assert isinstance(event, NvmeTryPullNewEvent)
        # Rate limiting - this is what makes parallel round-robin arbitration on queues match NVMe
        if not self.rate.available():
            self.sim.schedule_event(
                NvmeTryPullNewEvent(
                    participant=self,
                    time_ns=self.rate.next_time(),
                )
            )
            return

        if all(q.submission.is_empty() for q, _ in self.queues):
            return

        for i in range(1, len(self.queues) + 1):
            candidate_idx = (self.round_robin_queue_idx + i) % len(self.queues)
            queue, take_from = self.queues[candidate_idx]
            if self.schedule_completion(queue, take_from):
                self.queues[candidate_idx] = (
                    queue,
                    (take_from + 1) % len(queue.submission.entries),
                )
                self.round_robin_queue_idx = candidate_idx
                self.rate.mark_taken()
                if self.trace_file:
                    print(f"{self.sim.time_ns}\t{candidate_idx}", file=self.trace_file)
                break

        if not self.queues_trigger_pull:
            self.sim.schedule_event(
                NvmeTryPullNewEvent(
                    participant=self,
                    time_ns=self.sim.time_ns + self.pull_completion_delay_ns,
                )
            )

    def export_stats(self, prefix: str, file: TextIO):
        super().export_stats(prefix, file)

        period_ns = self.last_start_time_ns - self.first_start_time_ns
        # period_s = period_ns / 1e9
        iops = (self.n_completions / period_ns) * 1.0e9
        print(f"iops = {iops}", file=file)


def sim(
    seed: int,
    histogram_r: List[int],
    histogram_w: List[int],
    q_ops: int,
    n_queues: int,
    n_ops: int,
    one_over_iops: int,
    read_chance: int,
    iocap_l_ops: List[int],
    output_folder: Path,
    trace: List[str] = [],
    queues_trigger_pull: bool = True,  # TODO setting this to true when completion lengths are very short nukes performance
):
    sim = Sim()

    gen = random.Random(seed)

    parent_iocap_context = IOCapManyLeaseContext(iocap_l_ops)

    queues = [
        NvmeQueuePair(
            sim,
            name=f"queue{i:02d}",
            stimulus=NvmeStimulus(
                gen=gen,
                n_stims=n_ops // n_queues,
                read_chance=read_chance,
            ),
            q_ops=q_ops,
            new_stim_delay_ns=one_over_iops
            * n_queues,  # Multiple queues are usually selected due to a CPU bottleneck
            iocap_l_ops=iocap_l_ops,
            tell_completer_to_pull=queues_trigger_pull,
            parent_iocap_context=parent_iocap_context,
        )
        for i in range(n_queues)
    ]
    completer = NvmeCompleter(
        sim,
        "completer",
        gen,
        histogram_r=histogram_r,
        histogram_w=histogram_w,
        queues=queues,
        pull_completion_delay_ns=one_over_iops,
        # I noticed that the final completion-unexpose delta had a 98th percentile that matched the expected 99th percentile and thought the pull completion delay may be a culprit. it does not appear so?
        # see results-pull-at-{10,}iops.toml
        # pull_completion_delay_ns=one_over_iops // 10,
        # queues_trigger_pull doesn't help with this either.
        # !!! solved it.
        # consider slow joiners.
        # the lease opens, the thing starts, worst case your thing completes but just beforehand the new thing shows up and takes the max time. etc.
        # that can only happen if the new thing can't join instantly. i.e. the queue is blocked up.
        # so my projected p99 is going to happen in the 99%th percentile of cases where the queue is NOT blocked up like that
        # I hypothesize this is also a chance of 99% not blocked up - TODO: WHY? COULD BE PARAMETER DEPENDENT
        queues_trigger_pull=queues_trigger_pull,
    )

    # Open trace files
    for actor in sim.actors:
        if actor.name in trace:
            actor.trace_file = open(
                output_folder / f"{actor.name}.txt",
                "w",
                encoding="utf-8",
            )

    for actor in sim.actors:
        actor.schedule_pre_sim_events()

    sim.loop()

    # Close trace files
    for actor in sim.actors:
        if actor.trace_file:
            actor.trace_file.close()

    output_name = output_folder.stem

    with open(output_folder / f"{output_name}.toml", "w", encoding="utf-8") as f:
        print(f'timestamp = "{datetime.datetime.now().isoformat()}"', file=f)
        print(f'generated_by = "basic_nvme_queue.py"', file=f)
        print(f'git_hash = "TODO"', file=f)
        # TODO add config
        for actor in sim.actors:
            actor.export_stats(prefix="", file=f)
        parent_iocap_context.export_stats(prefix="top_iocaps.", file=f)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--seed", default=123, type=int)
    parser.add_argument("-n", default=400_000, type=int)
    parser.add_argument("--config", type=str)
    parser.add_argument(
        "--trace",
        type=str,
        help="Comma-separated list of names to open trace files for",
        default="",
    )
    parser.add_argument("output_dir", type=Path)
    args = parser.parse_args()

    assert args.output_dir.is_dir()

    if args.config:
        with open(args.config, "rb") as f:
            config = tomllib.load(f)
        histogram_r = config["histogram_r"]
        histogram_w = config["histogram_w"]
        read_chance = config["read_chance"]
        iops = config["iops"]
        q_ops = config["q_ops"]
        queues = config["queues"]
        iocap_l_ops = config["iocap_l_ops"]
    else:
        # haas fig17b assume t = 175us, t_99 = 400us, => 10M IOPS with 63 queues => 159k IOPS per queue,  d_t_99 * IOPS per queue = 225E-6 * 159E3 = ceil35.7 = 36.
        # 10M IOPS = roughly 375 entries per device = ~8 per queue
        # estimated over99 = overavg + d_t_99 = (l_ops - 1) / q_iops) *  + d_t_99
        #  = (2 - 1)/159E3 + 225E-6
        #  = ~231E-6
        # NOPE
        #  = (2 - 1)/(159E3/8) + 225E-6
        #  = 1/20k + 225E-6
        #

        t_50 = 175_000
        t_99 = 400_000
        histogram = (
            [t_50] * 50
            + [
                int(t_50 + (t_99 - t_50) * mix / 50.0)  #
                for mix in range(50)
            ]
            + [t_99]
        )
        histogram_r = histogram_w = histogram
        read_chance = 100  # all read
        iops = 159e3
        q_ops = 8
        queues = 1
        iocap_l_ops = [1, 2, 4, 8]

    sim(
        seed=args.seed,
        histogram_r=histogram_r,
        histogram_w=histogram_w,
        read_chance=read_chance,
        q_ops=q_ops,
        n_queues=queues,
        n_ops=args.n,
        one_over_iops=int(1e9 / iops),
        iocap_l_ops=iocap_l_ops,
        output_folder=args.output_dir,
        trace=args.trace.split(","),
    )
