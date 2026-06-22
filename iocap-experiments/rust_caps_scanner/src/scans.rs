pub mod aries;
pub mod cheri256;
pub mod cheriv9;
pub mod iocap2024_11;
pub mod iocap_general;
pub mod lowfat;
pub mod mmachine;
pub mod rv64y;

mod basic_cap;

pub trait LogScan {
    type T: Eq + std::fmt::Debug;

    const HEADER: &'static str;

    fn apply_f(&self, x: u128) -> Self::T;
    fn accept_result(&mut self, x: u128, result: &Self::T);

    fn scan(&mut self, min: u128, max: u128) {
        println!("{}", Self::HEADER);
        let mut x = min;
        let mut seed = (x, self.apply_f(x));
        self.accept_result(seed.0, &seed.1);
        'top: while x < max {
            // Forward pass
            let mut step = 1u128;
            let mut stepped_x = x;
            loop {
                stepped_x = if max - step <= stepped_x {
                    max
                } else {
                    stepped_x + step
                };
                let result = self.apply_f(stepped_x);
                if result != seed.1 {
                    break;
                }
                // If we've hit the max then just take that result and
                if stepped_x == max {
                    self.accept_result(stepped_x, &result);
                    break 'top;
                }
                // otherwise, double the step (panic if >u128)
                step = step * 2;
            }
            // dbg!(stepped_x);
            if stepped_x < seed.0 {
                panic!(
                    "stepped_x wrong seed {:x} stepped_x {:x} max: {:x}",
                    seed.0, stepped_x, max
                );
            }

            // We have now found a stepped_x > seed.0 such that f(stepped_x) != seed.1;
            // Now binary search backwards through (seed.0, stepped_x) to find the largest x where f(x) == seed.1, then say that x+1 is the inflection point
            let mut start = seed.0;
            let mut stop = stepped_x; // always set to an x value that produces f(x) != seed.1
            while start != stop && start != stop - 1 {
                // Use this construction to avoid exceeding u128 with large numbers
                let pivot = start + (stop - start) / 2;
                if self.apply_f(pivot) == seed.1 {
                    // It is further right
                    start = pivot;
                } else {
                    // It is further left
                    stop = pivot;
                }
            }
            // Plot both the before point...
            self.accept_result(start, &seed.1);
            // ...and the after point
            x = start + 1;
            seed = (x, self.apply_f(x));
            // dbg!(&seed);
            self.accept_result(seed.0, &seed.1);
            // and then push x forwards again!
        }
    }
}
