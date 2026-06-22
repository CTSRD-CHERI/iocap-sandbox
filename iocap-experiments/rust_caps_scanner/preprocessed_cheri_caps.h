# 1 "cheri_compressed_cap_lib.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 361 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "cheri_compressed_cap_lib.c" 2




# 1 "./cheri_compressed_cap.h" 1
# 44 "./cheri_compressed_cap.h"
# 1 "/usr/lib/llvm-14/lib/clang/14.0.6/include/stdbool.h" 1 3
# 45 "./cheri_compressed_cap.h" 2
# 1 "/usr/lib/llvm-14/lib/clang/14.0.6/include/stdint.h" 1 3
# 52 "/usr/lib/llvm-14/lib/clang/14.0.6/include/stdint.h" 3
# 1 "/usr/include/stdint.h" 1 3 4
# 26 "/usr/include/stdint.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 33 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 392 "/usr/include/features.h" 3 4
# 1 "/usr/include/features-time64.h" 1 3 4
# 20 "/usr/include/features-time64.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 21 "/usr/include/features-time64.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 1 3 4
# 19 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 20 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 2 3 4
# 22 "/usr/include/features-time64.h" 2 3 4
# 393 "/usr/include/features.h" 2 3 4
# 467 "/usr/include/features.h" 3 4
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 468 "/usr/include/features.h" 2 3 4
# 489 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
# 561 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 562 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 563 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 490 "/usr/include/features.h" 2 3 4
# 513 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 514 "/usr/include/features.h" 2 3 4
# 34 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 2 3 4
# 27 "/usr/include/stdint.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 28 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 1 3 4
# 19 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 20 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 2 3 4
# 29 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;






typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;



typedef long int __quad_t;
typedef unsigned long int __u_quad_t;







typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
# 141 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 1 3 4
# 142 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/time64.h" 1 3 4
# 143 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4


typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;

typedef int __daddr_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void * __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;


typedef long int __fsword_t;

typedef long int __ssize_t;


typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;



typedef __off64_t __loff_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;




typedef int __sig_atomic_t;
# 28 "/usr/include/stdint.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wchar.h" 1 3 4
# 29 "/usr/include/stdint.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 30 "/usr/include/stdint.h" 2 3 4




# 1 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h" 3 4
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
# 35 "/usr/include/stdint.h" 2 3 4


# 1 "/usr/include/x86_64-linux-gnu/bits/stdint-uintn.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/stdint-uintn.h" 3 4
typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;
# 38 "/usr/include/stdint.h" 2 3 4





typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;


typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;





typedef signed char int_fast8_t;

typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
# 71 "/usr/include/stdint.h" 3 4
typedef unsigned char uint_fast8_t;

typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
# 87 "/usr/include/stdint.h" 3 4
typedef long int intptr_t;


typedef unsigned long int uintptr_t;
# 101 "/usr/include/stdint.h" 3 4
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;
# 53 "/usr/lib/llvm-14/lib/clang/14.0.6/include/stdint.h" 2 3
# 46 "./cheri_compressed_cap.h" 2
# 1 "/usr/include/string.h" 1 3 4
# 26 "/usr/include/string.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 27 "/usr/include/string.h" 2 3 4






# 1 "/usr/lib/llvm-14/lib/clang/14.0.6/include/stddef.h" 1 3 4
# 46 "/usr/lib/llvm-14/lib/clang/14.0.6/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 34 "/usr/include/string.h" 2 3 4
# 43 "/usr/include/string.h" 3 4
extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));


extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));





extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
    __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2))) ;




extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));


extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 80 "/usr/include/string.h" 3 4
extern int __memcmpeq (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 107 "/usr/include/string.h" 3 4
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 141 "/usr/include/string.h" 3 4
extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));


extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));


extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
    __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2))) ;



# 1 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__locale_t.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/types/__locale_t.h" 3 4
struct __locale_struct
{

  struct __locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
};

typedef struct __locale_struct *__locale_t;
# 23 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 2 3 4

typedef __locale_t locale_t;
# 173 "/usr/include/string.h" 2 3 4


extern int strcoll_l (const char *__s1, const char *__s2, locale_t __l)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));


extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    locale_t __l) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2, 4)))
                                           ;





extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ )) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));






extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
# 246 "/usr/include/string.h" 3 4
extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 273 "/usr/include/string.h" 3 4
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 293 "/usr/include/string.h" 3 4
extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 323 "/usr/include/string.h" 3 4
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 350 "/usr/include/string.h" 3 4
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2)));



extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2, 3)));

extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2, 3)));
# 407 "/usr/include/string.h" 3 4
extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern char *strerror (int __errnum) __attribute__ ((__nothrow__ ));
# 432 "/usr/include/string.h" 3 4
extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2)))


                                          ;
# 458 "/usr/include/string.h" 3 4
extern char *strerror_l (int __errnum, locale_t __l) __attribute__ ((__nothrow__ ));



# 1 "/usr/include/strings.h" 1 3 4
# 23 "/usr/include/strings.h" 3 4
# 1 "/usr/lib/llvm-14/lib/clang/14.0.6/include/stddef.h" 1 3 4
# 24 "/usr/include/strings.h" 2 3 4
# 34 "/usr/include/strings.h" 3 4
extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bcopy (const void *__src, void *__dest, size_t __n)
  __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));


extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));
# 68 "/usr/include/strings.h" 3 4
extern char *index (const char *__s, int __c)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 96 "/usr/include/strings.h" 3 4
extern char *rindex (const char *__s, int __c)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));






extern int ffs (int __i) __attribute__ ((__nothrow__ )) __attribute__ ((__const__));





extern int ffsl (long int __l) __attribute__ ((__nothrow__ )) __attribute__ ((__const__));
__extension__ extern int ffsll (long long int __ll)
     __attribute__ ((__nothrow__ )) __attribute__ ((__const__));



extern int strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));






extern int strcasecmp_l (const char *__s1, const char *__s2, locale_t __loc)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));



extern int strncasecmp_l (const char *__s1, const char *__s2,
     size_t __n, locale_t __loc)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 4)));
# 463 "/usr/include/string.h" 2 3 4



extern void explicit_bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)))
                                                  ;



extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));




extern char *strsignal (int __sig) __attribute__ ((__nothrow__ ));
# 489 "/usr/include/string.h" 3 4
extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));



extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));
# 47 "./cheri_compressed_cap.h" 2


# 1 "./cheri_compressed_cap_64.h" 1
# 62 "./cheri_compressed_cap_64.h"
typedef uint64_t cc64_length_t;
typedef int64_t cc64_offset_t;
typedef uint32_t cc64_addr_t;
typedef int32_t cc64_saddr_t;
# 1 "./cheri_compressed_cap_macros.h" 1
# 40 "./cheri_compressed_cap_macros.h"
# 1 "/usr/include/assert.h" 1 3 4
# 69 "/usr/include/assert.h" 3 4
extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));


extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));




extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));
# 41 "./cheri_compressed_cap_macros.h" 2
# 67 "./cheri_compressed_cap_64.h" 2
typedef enum CC64_Mode { CC64_MODE_CAP = 1, CC64_MODE_INT = 0 } CC64_Mode;


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
enum {
    CC64_FIELD_HWPERMS_START = (52 - 32), CC64_FIELD_HWPERMS_LAST = (63 - 32), CC64_FIELD_HWPERMS_SIZE = CC64_FIELD_HWPERMS_LAST - CC64_FIELD_HWPERMS_START + 1, CC64_FIELD_HWPERMS_MASK_NOT_SHIFTED = ((1UL << (CC64_FIELD_HWPERMS_SIZE)) - 1UL), CC64_FIELD_HWPERMS_MASK64 = (uint64_t)CC64_FIELD_HWPERMS_MASK_NOT_SHIFTED << CC64_FIELD_HWPERMS_START, CC64_FIELD_HWPERMS_MAX_VALUE = CC64_FIELD_HWPERMS_MASK_NOT_SHIFTED,
    CC64_FIELD_FLAGS_START = (51 - 32), CC64_FIELD_FLAGS_LAST = (51 - 32), CC64_FIELD_FLAGS_SIZE = CC64_FIELD_FLAGS_LAST - CC64_FIELD_FLAGS_START + 1, CC64_FIELD_FLAGS_MASK_NOT_SHIFTED = ((1UL << (CC64_FIELD_FLAGS_SIZE)) - 1UL), CC64_FIELD_FLAGS_MASK64 = (uint64_t)CC64_FIELD_FLAGS_MASK_NOT_SHIFTED << CC64_FIELD_FLAGS_START, CC64_FIELD_FLAGS_MAX_VALUE = CC64_FIELD_FLAGS_MASK_NOT_SHIFTED,
    CC64_FIELD_OTYPE_START = (47 - 32), CC64_FIELD_OTYPE_LAST = (50 - 32), CC64_FIELD_OTYPE_SIZE = CC64_FIELD_OTYPE_LAST - CC64_FIELD_OTYPE_START + 1, CC64_FIELD_OTYPE_MASK_NOT_SHIFTED = ((1UL << (CC64_FIELD_OTYPE_SIZE)) - 1UL), CC64_FIELD_OTYPE_MASK64 = (uint64_t)CC64_FIELD_OTYPE_MASK_NOT_SHIFTED << CC64_FIELD_OTYPE_START, CC64_FIELD_OTYPE_MAX_VALUE = CC64_FIELD_OTYPE_MASK_NOT_SHIFTED,
    CC64_FIELD_EBT_START = (32 - 32), CC64_FIELD_EBT_LAST = (46 - 32), CC64_FIELD_EBT_SIZE = CC64_FIELD_EBT_LAST - CC64_FIELD_EBT_START + 1, CC64_FIELD_EBT_MASK_NOT_SHIFTED = ((1UL << (CC64_FIELD_EBT_SIZE)) - 1UL), CC64_FIELD_EBT_MASK64 = (uint64_t)CC64_FIELD_EBT_MASK_NOT_SHIFTED << CC64_FIELD_EBT_START, CC64_FIELD_EBT_MAX_VALUE = CC64_FIELD_EBT_MASK_NOT_SHIFTED,

    CC64_FIELD_INTERNAL_EXPONENT_START = (46 - 32), CC64_FIELD_INTERNAL_EXPONENT_LAST = (46 - 32), CC64_FIELD_INTERNAL_EXPONENT_SIZE = CC64_FIELD_INTERNAL_EXPONENT_LAST - CC64_FIELD_INTERNAL_EXPONENT_START + 1, CC64_FIELD_INTERNAL_EXPONENT_MASK_NOT_SHIFTED = ((1UL << (CC64_FIELD_INTERNAL_EXPONENT_SIZE)) - 1UL), CC64_FIELD_INTERNAL_EXPONENT_MASK64 = (uint64_t)CC64_FIELD_INTERNAL_EXPONENT_MASK_NOT_SHIFTED << CC64_FIELD_INTERNAL_EXPONENT_START, CC64_FIELD_INTERNAL_EXPONENT_MAX_VALUE = CC64_FIELD_INTERNAL_EXPONENT_MASK_NOT_SHIFTED,
    CC64_FIELD_TOP_ENCODED_START = (40 - 32), CC64_FIELD_TOP_ENCODED_LAST = (45 - 32), CC64_FIELD_TOP_ENCODED_SIZE = CC64_FIELD_TOP_ENCODED_LAST - CC64_FIELD_TOP_ENCODED_START + 1, CC64_FIELD_TOP_ENCODED_MASK_NOT_SHIFTED = ((1UL << (CC64_FIELD_TOP_ENCODED_SIZE)) - 1UL), CC64_FIELD_TOP_ENCODED_MASK64 = (uint64_t)CC64_FIELD_TOP_ENCODED_MASK_NOT_SHIFTED << CC64_FIELD_TOP_ENCODED_START, CC64_FIELD_TOP_ENCODED_MAX_VALUE = CC64_FIELD_TOP_ENCODED_MASK_NOT_SHIFTED,
    CC64_FIELD_BOTTOM_ENCODED_START = (32 - 32), CC64_FIELD_BOTTOM_ENCODED_LAST = (39 - 32), CC64_FIELD_BOTTOM_ENCODED_SIZE = CC64_FIELD_BOTTOM_ENCODED_LAST - CC64_FIELD_BOTTOM_ENCODED_START + 1, CC64_FIELD_BOTTOM_ENCODED_MASK_NOT_SHIFTED = ((1UL << (CC64_FIELD_BOTTOM_ENCODED_SIZE)) - 1UL), CC64_FIELD_BOTTOM_ENCODED_MASK64 = (uint64_t)CC64_FIELD_BOTTOM_ENCODED_MASK_NOT_SHIFTED << CC64_FIELD_BOTTOM_ENCODED_START, CC64_FIELD_BOTTOM_ENCODED_MAX_VALUE = CC64_FIELD_BOTTOM_ENCODED_MASK_NOT_SHIFTED,



    CC64_FIELD_EXP_ZERO_TOP_START = (40 - 32), CC64_FIELD_EXP_ZERO_TOP_LAST = (45 - 32), CC64_FIELD_EXP_ZERO_TOP_SIZE = CC64_FIELD_EXP_ZERO_TOP_LAST - CC64_FIELD_EXP_ZERO_TOP_START + 1, CC64_FIELD_EXP_ZERO_TOP_MASK_NOT_SHIFTED = ((1UL << (CC64_FIELD_EXP_ZERO_TOP_SIZE)) - 1UL), CC64_FIELD_EXP_ZERO_TOP_MASK64 = (uint64_t)CC64_FIELD_EXP_ZERO_TOP_MASK_NOT_SHIFTED << CC64_FIELD_EXP_ZERO_TOP_START, CC64_FIELD_EXP_ZERO_TOP_MAX_VALUE = CC64_FIELD_EXP_ZERO_TOP_MASK_NOT_SHIFTED,
    CC64_FIELD_EXP_ZERO_BOTTOM_START = (32 - 32), CC64_FIELD_EXP_ZERO_BOTTOM_LAST = (39 - 32), CC64_FIELD_EXP_ZERO_BOTTOM_SIZE = CC64_FIELD_EXP_ZERO_BOTTOM_LAST - CC64_FIELD_EXP_ZERO_BOTTOM_START + 1, CC64_FIELD_EXP_ZERO_BOTTOM_MASK_NOT_SHIFTED = ((1UL << (CC64_FIELD_EXP_ZERO_BOTTOM_SIZE)) - 1UL), CC64_FIELD_EXP_ZERO_BOTTOM_MASK64 = (uint64_t)CC64_FIELD_EXP_ZERO_BOTTOM_MASK_NOT_SHIFTED << CC64_FIELD_EXP_ZERO_BOTTOM_START, CC64_FIELD_EXP_ZERO_BOTTOM_MAX_VALUE = CC64_FIELD_EXP_ZERO_BOTTOM_MASK_NOT_SHIFTED,

    CC64_FIELD_EXP_NONZERO_TOP_START = (43 - 32), CC64_FIELD_EXP_NONZERO_TOP_LAST = (45 - 32), CC64_FIELD_EXP_NONZERO_TOP_SIZE = CC64_FIELD_EXP_NONZERO_TOP_LAST - CC64_FIELD_EXP_NONZERO_TOP_START + 1, CC64_FIELD_EXP_NONZERO_TOP_MASK_NOT_SHIFTED = ((1UL << (CC64_FIELD_EXP_NONZERO_TOP_SIZE)) - 1UL), CC64_FIELD_EXP_NONZERO_TOP_MASK64 = (uint64_t)CC64_FIELD_EXP_NONZERO_TOP_MASK_NOT_SHIFTED << CC64_FIELD_EXP_NONZERO_TOP_START, CC64_FIELD_EXP_NONZERO_TOP_MAX_VALUE = CC64_FIELD_EXP_NONZERO_TOP_MASK_NOT_SHIFTED,
    CC64_FIELD_EXPONENT_HIGH_PART_START = (40 - 32), CC64_FIELD_EXPONENT_HIGH_PART_LAST = (42 - 32), CC64_FIELD_EXPONENT_HIGH_PART_SIZE = CC64_FIELD_EXPONENT_HIGH_PART_LAST - CC64_FIELD_EXPONENT_HIGH_PART_START + 1, CC64_FIELD_EXPONENT_HIGH_PART_MASK_NOT_SHIFTED = ((1UL << (CC64_FIELD_EXPONENT_HIGH_PART_SIZE)) - 1UL), CC64_FIELD_EXPONENT_HIGH_PART_MASK64 = (uint64_t)CC64_FIELD_EXPONENT_HIGH_PART_MASK_NOT_SHIFTED << CC64_FIELD_EXPONENT_HIGH_PART_START, CC64_FIELD_EXPONENT_HIGH_PART_MAX_VALUE = CC64_FIELD_EXPONENT_HIGH_PART_MASK_NOT_SHIFTED,
    CC64_FIELD_EXP_NONZERO_BOTTOM_START = (35 - 32), CC64_FIELD_EXP_NONZERO_BOTTOM_LAST = (39 - 32), CC64_FIELD_EXP_NONZERO_BOTTOM_SIZE = CC64_FIELD_EXP_NONZERO_BOTTOM_LAST - CC64_FIELD_EXP_NONZERO_BOTTOM_START + 1, CC64_FIELD_EXP_NONZERO_BOTTOM_MASK_NOT_SHIFTED = ((1UL << (CC64_FIELD_EXP_NONZERO_BOTTOM_SIZE)) - 1UL), CC64_FIELD_EXP_NONZERO_BOTTOM_MASK64 = (uint64_t)CC64_FIELD_EXP_NONZERO_BOTTOM_MASK_NOT_SHIFTED << CC64_FIELD_EXP_NONZERO_BOTTOM_START, CC64_FIELD_EXP_NONZERO_BOTTOM_MAX_VALUE = CC64_FIELD_EXP_NONZERO_BOTTOM_MASK_NOT_SHIFTED,
    CC64_FIELD_EXPONENT_LOW_PART_START = (32 - 32), CC64_FIELD_EXPONENT_LOW_PART_LAST = (34 - 32), CC64_FIELD_EXPONENT_LOW_PART_SIZE = CC64_FIELD_EXPONENT_LOW_PART_LAST - CC64_FIELD_EXPONENT_LOW_PART_START + 1, CC64_FIELD_EXPONENT_LOW_PART_MASK_NOT_SHIFTED = ((1UL << (CC64_FIELD_EXPONENT_LOW_PART_SIZE)) - 1UL), CC64_FIELD_EXPONENT_LOW_PART_MASK64 = (uint64_t)CC64_FIELD_EXPONENT_LOW_PART_MASK_NOT_SHIFTED << CC64_FIELD_EXPONENT_LOW_PART_START, CC64_FIELD_EXPONENT_LOW_PART_MAX_VALUE = CC64_FIELD_EXPONENT_LOW_PART_MASK_NOT_SHIFTED,
    CC64_FIELD_RESERVED_START = (32 - 32), CC64_FIELD_RESERVED_LAST = (31 - 32), CC64_FIELD_RESERVED_SIZE = CC64_FIELD_RESERVED_LAST - CC64_FIELD_RESERVED_START + 1, CC64_FIELD_RESERVED_MASK_NOT_SHIFTED = ((1UL << (CC64_FIELD_RESERVED_SIZE)) - 1UL), CC64_FIELD_RESERVED_MASK64 = (uint64_t)CC64_FIELD_RESERVED_MASK_NOT_SHIFTED << CC64_FIELD_RESERVED_START, CC64_FIELD_RESERVED_MAX_VALUE = CC64_FIELD_RESERVED_MASK_NOT_SHIFTED,
    CC64_FIELD_UPERMS_START = (32 - 32), CC64_FIELD_UPERMS_LAST = (31 - 32), CC64_FIELD_UPERMS_SIZE = CC64_FIELD_UPERMS_LAST - CC64_FIELD_UPERMS_START + 1, CC64_FIELD_UPERMS_MASK_NOT_SHIFTED = ((1UL << (CC64_FIELD_UPERMS_SIZE)) - 1UL), CC64_FIELD_UPERMS_MASK64 = (uint64_t)CC64_FIELD_UPERMS_MASK_NOT_SHIFTED << CC64_FIELD_UPERMS_START, CC64_FIELD_UPERMS_MAX_VALUE = CC64_FIELD_UPERMS_MASK_NOT_SHIFTED,
};
#pragma GCC diagnostic pop
_Static_assert((CC64_FIELD_UPERMS_SIZE) == (0), "");
_Static_assert((CC64_FIELD_RESERVED_SIZE) == (0), "");
# 116 "./cheri_compressed_cap_64.h"
_Static_assert((1 << 11) < CC64_FIELD_HWPERMS_MAX_VALUE, "permissions not representable?");
# 126 "./cheri_compressed_cap_64.h"
enum CC64_OTypes {
    CC64_MAX_REPRESENTABLE_OTYPE = ((1u << CC64_FIELD_OTYPE_SIZE) - 1u),
    CC64_OTYPE_UNSEALED = ((CC64_MAX_REPRESENTABLE_OTYPE - 0u)), CC64_OTYPE_UNSEALED_SIGNED = ((((int64_t)-1) - 0u)),
    CC64_OTYPE_SENTRY = ((CC64_MAX_REPRESENTABLE_OTYPE - 1u)), CC64_OTYPE_SENTRY_SIGNED = ((((int64_t)-1) - 1u)),
    CC64_OTYPE_RESERVED2 = ((CC64_MAX_REPRESENTABLE_OTYPE - 2u)), CC64_OTYPE_RESERVED2_SIGNED = ((((int64_t)-1) - 2u)),
    CC64_OTYPE_RESERVED3 = ((CC64_MAX_REPRESENTABLE_OTYPE - 3u)), CC64_OTYPE_RESERVED3_SIGNED = ((((int64_t)-1) - 3u)),
    CC64_MIN_RESERVED_OTYPE = CC64_OTYPE_RESERVED3,
    CC64_MAX_RESERVED_OTYPE = CC64_OTYPE_UNSEALED,
};





_Static_assert((8) == (CC64_FIELD_EXP_ZERO_BOTTOM_SIZE), "");
# 153 "./cheri_compressed_cap_64.h"
# 1 "./cheri_compressed_cap_common.h" 1
# 40 "./cheri_compressed_cap_common.h"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
enum {


    CC64_RESET_EXP = 26,
    CC64_RESET_T = 1u << (32 - CC64_RESET_EXP - CC64_FIELD_EXPONENT_HIGH_PART_SIZE),







    CC64_NULL_EXP = CC64_RESET_EXP,
    CC64_NULL_T = CC64_RESET_T,

    CC64_RESET_EBT = ((uint64_t)((1) & CC64_FIELD_INTERNAL_EXPONENT_MAX_VALUE) << CC64_FIELD_INTERNAL_EXPONENT_START) | ((uint64_t)(((CC64_RESET_EXP) >> CC64_FIELD_EXPONENT_LOW_PART_SIZE) & CC64_FIELD_EXPONENT_HIGH_PART_MAX_VALUE) << CC64_FIELD_EXPONENT_HIGH_PART_START) | ((uint64_t)((CC64_RESET_EXP) & CC64_FIELD_EXPONENT_LOW_PART_MAX_VALUE) << CC64_FIELD_EXPONENT_LOW_PART_START) |
                       ((uint64_t)((CC64_RESET_T) & CC64_FIELD_EXP_NONZERO_TOP_MAX_VALUE) << CC64_FIELD_EXP_NONZERO_TOP_START) | ((uint64_t)((0) & CC64_FIELD_EXP_NONZERO_BOTTOM_MAX_VALUE) << CC64_FIELD_EXP_NONZERO_BOTTOM_START),
    CC64_RESET_PESBT = CC64_RESET_EBT | (((uint64_t)(((0)) & CC64_FIELD_UPERMS_MAX_VALUE) << CC64_FIELD_UPERMS_START) | ((uint64_t)(((0xfff)) & CC64_FIELD_HWPERMS_MAX_VALUE) << CC64_FIELD_HWPERMS_START)) |
                         ((uint64_t)((CC64_OTYPE_UNSEALED) & CC64_FIELD_OTYPE_MAX_VALUE) << CC64_FIELD_OTYPE_START),
    CC64_NULL_EBT = ((uint64_t)((1) & CC64_FIELD_INTERNAL_EXPONENT_MAX_VALUE) << CC64_FIELD_INTERNAL_EXPONENT_START) | ((uint64_t)(((CC64_NULL_EXP) >> CC64_FIELD_EXPONENT_LOW_PART_SIZE) & CC64_FIELD_EXPONENT_HIGH_PART_MAX_VALUE) << CC64_FIELD_EXPONENT_HIGH_PART_START) | ((uint64_t)((CC64_NULL_EXP) & CC64_FIELD_EXPONENT_LOW_PART_MAX_VALUE) << CC64_FIELD_EXPONENT_LOW_PART_START) |
                      ((uint64_t)((CC64_NULL_T) & CC64_FIELD_EXP_NONZERO_TOP_MAX_VALUE) << CC64_FIELD_EXP_NONZERO_TOP_START) | ((uint64_t)((0) & CC64_FIELD_EXP_NONZERO_BOTTOM_MAX_VALUE) << CC64_FIELD_EXP_NONZERO_BOTTOM_START),
    CC64_NULL_PESBT = CC64_NULL_EBT | ((uint64_t)((CC64_OTYPE_UNSEALED) & CC64_FIELD_OTYPE_MAX_VALUE) << CC64_FIELD_OTYPE_START),

    CC64_MEM_XOR_MASK = CC64_NULL_PESBT,
    CC64_NULL_XOR_MASK __attribute__((deprecated("Use _MEM_XOR_MASK instead"))) = CC64_MEM_XOR_MASK,
    CC64_MAX_LEVEL_VALUE = ((1UL << (1)) - 1UL),
};
#pragma GCC diagnostic pop
# 89 "./cheri_compressed_cap_common.h"
enum { CC64_FIELD_LEN_MSB_SIZE = 0 };



_Static_assert((CC64_FIELD_INTERNAL_EXPONENT_SIZE + CC64_FIELD_EXP_ZERO_TOP_SIZE + CC64_FIELD_LEN_MSB_SIZE + CC64_FIELD_EXP_ZERO_BOTTOM_SIZE) == (CC64_FIELD_EBT_SIZE), "");


_Static_assert((CC64_FIELD_INTERNAL_EXPONENT_SIZE + CC64_FIELD_LEN_MSB_SIZE + CC64_FIELD_TOP_ENCODED_SIZE + CC64_FIELD_BOTTOM_ENCODED_SIZE) == (CC64_FIELD_EBT_SIZE), "");


_Static_assert((CC64_FIELD_INTERNAL_EXPONENT_SIZE + CC64_FIELD_LEN_MSB_SIZE + CC64_FIELD_EXP_NONZERO_TOP_SIZE + CC64_FIELD_EXP_NONZERO_BOTTOM_SIZE + CC64_FIELD_EXPONENT_HIGH_PART_SIZE + CC64_FIELD_EXPONENT_LOW_PART_SIZE) == (CC64_FIELD_EBT_SIZE), "");




_Static_assert((CC64_FIELD_EBT_START) == (0), "");

_Static_assert(CC64_MIN_RESERVED_OTYPE >= 0, "MIN_RESERVED_OTYPE is signed?");
_Static_assert(CC64_MIN_RESERVED_OTYPE < CC64_MAX_RESERVED_OTYPE, "MIN_RESERVED_OTYPE greater than MAX_RESERVED_OTYPE?");

_Static_assert(CC64_MIN_RESERVED_OTYPE <= CC64_MAX_REPRESENTABLE_OTYPE, "MIN_RESERVED_OTYPE out of range?");
_Static_assert(CC64_MAX_RESERVED_OTYPE <= CC64_MAX_REPRESENTABLE_OTYPE, "MAX_RESERVED_OTYPE out of range?");


typedef struct cc64_cap cc64_cap_t;

extern uint8_t cc64_get_flags(const cc64_cap_t* cap);
extern uint32_t cc64_get_otype(const cc64_cap_t* cap);
extern uint32_t cc64_get_level(const cc64_cap_t* cap);
extern cc64_addr_t cc64_get_perms(const cc64_cap_t* cap);
extern cc64_addr_t cc64_get_reserved(const cc64_cap_t* cap);
extern _Bool cc64_reserved_bits_valid(const cc64_cap_t* cap) { return cc64_get_reserved(cap) == 0; }
extern cc64_addr_t cc64_get_uperms(const cc64_cap_t* cap);

extern cc64_addr_t cc64_get_all_permissions(const cc64_cap_t* cap);
extern _Bool cc64_has_permissions(const cc64_cap_t* cap, cc64_addr_t permissions) {
    return (cc64_get_all_permissions(cap) & permissions) == permissions;
}
extern _Bool cc64_set_permissions(cc64_cap_t* cap, cc64_addr_t permissions);

extern CC64_Mode cc64_get_execution_mode(const cc64_cap_t* cap);
extern _Bool cc64_set_execution_mode(cc64_cap_t* cap, CC64_Mode new_mode);



struct cc64_cap {







    cc64_addr_t _cr_cursor;
    cc64_addr_t cr_pesbt;

    cc64_length_t _cr_top;
    cc64_addr_t cr_base;
    uint8_t cr_tag;
    uint8_t cr_bounds_valid;



    uint8_t cr_exp;
    uint8_t cr_extra;
# 179 "./cheri_compressed_cap_common.h"
};

extern _Bool cc64_exactly_equal(const cc64_cap_t* a, const cc64_cap_t* b) {
    return a->cr_tag == b->cr_tag && a->_cr_cursor == b->_cr_cursor && a->cr_pesbt == b->cr_pesbt;
}

extern uint8_t cc64_get_lvbits(__attribute__((unused)) const cc64_cap_t* cap) {



    return 1;

}

extern _Bool cc64_raw_equal(const cc64_cap_t* a, const cc64_cap_t* b) {
    return a->_cr_cursor == b->_cr_cursor && a->cr_pesbt == b->cr_pesbt && a->_cr_top == b->_cr_top &&
           a->cr_base == b->cr_base && a->cr_tag == b->cr_tag && a->cr_bounds_valid == b->cr_bounds_valid &&
           cc64_get_lvbits(a) == cc64_get_lvbits(b) && a->cr_exp == b->cr_exp && a->cr_extra == b->cr_extra;
}


extern uint32_t cc64_idx_MSNZ(uint64_t x) {
# 218 "./cheri_compressed_cap_common.h"
    ((void) sizeof ((x != 0) ? 1 : 0), __extension__ ({ if (x != 0) ; else __assert_fail ("x != 0", "./cheri_compressed_cap_common.h", 218, __extension__ __PRETTY_FUNCTION__); }));
    uint32_t r = 63u - (uint32_t)__builtin_clzll(x);

    return r;
}





extern uint32_t cc64_compute_e(cc64_addr_t rlength, uint32_t bwidth) {
    if (rlength < (1u << (bwidth - 1)))
        return 0;

    return (cc64_idx_MSNZ(rlength) - (bwidth - 2));
}

extern uint32_t cc64_get_exponent(cc64_length_t length) {
    const uint32_t bwidth = 8;
    if (length > (4294967295U)) {
        return 33 - (bwidth - 1);
    } else {
        return cc64_compute_e((cc64_addr_t)length, bwidth);
    }
}

extern uint64_t cc64_getbits(uint64_t src, uint32_t start, uint32_t size) {
    return ((src >> start) & ((1UL << size) - 1UL));
}


extern uint64_t cc64_truncate_addr(cc64_addr_t value, size_t n) { return value & (((cc64_addr_t)1 << n) - 1); }
extern uint64_t cc64_truncate64(uint64_t value, size_t n) { return value & ((1UL << n) - 1); }







extern uint64_t cc64_truncateLSB_8(uint64_t value, size_t n) { _Static_assert(8 <= 64, ""); return value >> (8 - n); }
extern uint64_t cc64_truncateLSB_32(uint64_t value, size_t n) { _Static_assert(32 <= 64, ""); return value >> (32 - n); }
extern uint64_t cc64_truncateLSB_64(uint64_t value, size_t n) { _Static_assert(64 <= 64, ""); return value >> (64 - n); }




struct cc64_bounds_bits {
    uint16_t B;
    uint16_t T;
    uint8_t E;
    _Bool IE;
};
# 283 "./cheri_compressed_cap_common.h"
extern cc64_addr_t cc64_cap_pesbt_extract_otype(cc64_addr_t pesbt) { return cc64_getbits((pesbt), CC64_FIELD_OTYPE_START, CC64_FIELD_OTYPE_SIZE); } extern cc64_addr_t cc64_cap_pesbt_encode_otype(uint32_t value) { return ((uint64_t)((value) & CC64_FIELD_OTYPE_MAX_VALUE) << CC64_FIELD_OTYPE_START); } extern cc64_addr_t cc64_cap_pesbt_deposit_otype(cc64_addr_t pesbt, uint32_t value) { return __extension__({ ((void) sizeof ((value <= CC64_FIELD_OTYPE_MAX_VALUE) ? 1 : 0), __extension__ ({ if (value <= CC64_FIELD_OTYPE_MAX_VALUE) ; else __assert_fail ("value <= CC64_FIELD_OTYPE_MAX_VALUE", "./cheri_compressed_cap_common.h", 283, __extension__ __PRETTY_FUNCTION__); })); ((pesbt) & ~CC64_FIELD_OTYPE_MASK64) | ((uint64_t)((value) & CC64_FIELD_OTYPE_MAX_VALUE) << CC64_FIELD_OTYPE_START); }); } extern uint32_t cc64_get_otype(const cc64_cap_t* cap) { return cc64_cap_pesbt_extract_otype(cap->cr_pesbt); } extern void cc64_update_otype(cc64_cap_t * cap, cc64_addr_t value) { cap->cr_pesbt = cc64_cap_pesbt_deposit_otype(cap->cr_pesbt, value); }
extern cc64_addr_t cc64_cap_pesbt_extract_flags(cc64_addr_t pesbt) { return cc64_getbits((pesbt), CC64_FIELD_FLAGS_START, CC64_FIELD_FLAGS_SIZE); } extern cc64_addr_t cc64_cap_pesbt_encode_flags(uint8_t value) { return ((uint64_t)((value) & CC64_FIELD_FLAGS_MAX_VALUE) << CC64_FIELD_FLAGS_START); } extern cc64_addr_t cc64_cap_pesbt_deposit_flags(cc64_addr_t pesbt, uint8_t value) { return __extension__({ ((void) sizeof ((value <= CC64_FIELD_FLAGS_MAX_VALUE) ? 1 : 0), __extension__ ({ if (value <= CC64_FIELD_FLAGS_MAX_VALUE) ; else __assert_fail ("value <= CC64_FIELD_FLAGS_MAX_VALUE", "./cheri_compressed_cap_common.h", 284, __extension__ __PRETTY_FUNCTION__); })); ((pesbt) & ~CC64_FIELD_FLAGS_MASK64) | ((uint64_t)((value) & CC64_FIELD_FLAGS_MAX_VALUE) << CC64_FIELD_FLAGS_START); }); } extern uint8_t cc64_get_flags(const cc64_cap_t* cap) { return cc64_cap_pesbt_extract_flags(cap->cr_pesbt); } extern void cc64_update_flags(cc64_cap_t * cap, cc64_addr_t value) { cap->cr_pesbt = cc64_cap_pesbt_deposit_flags(cap->cr_pesbt, value); }


extern _Bool cc64_is_cap_sealed(const cc64_cap_t* cp) { return cc64_get_otype(cp) != CC64_OTYPE_UNSEALED; }


extern uint32_t cc64_get_level(const cc64_cap_t* cap) {
    return cc64_get_all_permissions(cap) & (1 << 0) ? 1 : 0;
}
extern void cc64_update_level(cc64_cap_t* cap, uint8_t level) {
    ((void) sizeof (((level <= CC64_MAX_LEVEL_VALUE) && "invalid level") ? 1 : 0), __extension__ ({ if ((level <= CC64_MAX_LEVEL_VALUE) && "invalid level") ; else __assert_fail ("(level <= CC64_MAX_LEVEL_VALUE) && \"invalid level\"", "./cheri_compressed_cap_common.h", 294, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof (((!cap->cr_tag || !cc64_is_cap_sealed(cap)) && "cannot update level on sealed caps") ? 1 : 0), __extension__ ({ if ((!cap->cr_tag || !cc64_is_cap_sealed(cap)) && "cannot update level on sealed caps") ; else __assert_fail ("(!cap->cr_tag || !cc64_is_cap_sealed(cap)) && \"cannot update level on sealed caps\"", "./cheri_compressed_cap_common.h", 295, __extension__ __PRETTY_FUNCTION__); }));
    cc64_addr_t perms = cc64_get_all_permissions(cap);
    if (level)
        perms |= (1 << 0);
    else
        perms &= ~(1 << 0);
    __attribute__((unused)) _Bool ok = cc64_set_permissions(cap, perms);
    ((void) sizeof ((ok && "failed to update level") ? 1 : 0), __extension__ ({ if (ok && "failed to update level") ; else __assert_fail ("ok && \"failed to update level\"", "./cheri_compressed_cap_common.h", 302, __extension__ __PRETTY_FUNCTION__); }));
}



extern cc64_cap_t cc64_make_null_derived_cap(cc64_addr_t addr);
__attribute__((deprecated("Use get_all_permissions"))) extern cc64_addr_t cc64_get_perms(const cc64_cap_t* cap) {

    _Static_assert((15) != 0, "Architectural perms expected to start at offset zero");

    cc64_cap_t null_cap = cc64_make_null_derived_cap(0);
    cc64_addr_t reserved_one_bits = cc64_get_all_permissions(&null_cap);
    cc64_addr_t all_perms_w_reserved = cc64_get_all_permissions(cap);
    return (all_perms_w_reserved & ~reserved_one_bits) & ~0;
}
__attribute__((deprecated("Use get_all_permissions"))) extern cc64_addr_t cc64_get_uperms(const cc64_cap_t* cap) {
    return (cc64_get_all_permissions(cap) & 0) >> (15);
}
__attribute__((deprecated("Use set_permissions"))) extern void cc64_update_perms(cc64_cap_t* cap, cc64_addr_t value) {
    ((void) sizeof ((((value & (0xfff)) == value) && "invalid permission value") ? 1 : 0), __extension__ ({ if (((value & (0xfff)) == value) && "invalid permission value") ; else __assert_fail ("((value & (0xfff)) == value) && \"invalid permission value\"", "./cheri_compressed_cap_common.h", 321, __extension__ __PRETTY_FUNCTION__); }));
    cc64_addr_t current_swperms = (cc64_get_all_permissions(cap) & 0);
    cc64_set_permissions(cap, (value & ~0) | current_swperms);
}
__attribute__((deprecated("Use set_permissions"))) extern void cc64_update_uperms(cc64_cap_t* cap, cc64_addr_t value) {
    ((void) sizeof ((((value & (0)) == value) && "invalid permission value") ? 1 : 0), __extension__ ({ if (((value & (0)) == value) && "invalid permission value") ; else __assert_fail ("((value & (0)) == value) && \"invalid permission value\"", "./cheri_compressed_cap_common.h", 326, __extension__ __PRETTY_FUNCTION__); }));
    cc64_addr_t old_arch_perms = cc64_get_all_permissions(cap) & ~0;
    cc64_set_permissions(cap, ((value << (15)) & 0) | old_arch_perms);
}


extern struct cc64_bounds_bits cc64_extract_bounds_bits(cc64_addr_t pesbt) {
    _Static_assert(8 == CC64_FIELD_EXP_ZERO_BOTTOM_SIZE, "Wrong bot width?");
    uint32_t BWidth = 8;
    uint32_t BMask = (1u << BWidth) - 1;
    uint32_t TMask = BMask >> 2;
    struct cc64_bounds_bits result;
    _Static_assert(sizeof(result.B) * 8 >= 8, "B field too small");
    _Static_assert(sizeof(result.T) * 8 >= 8, "T field too small");
    _Static_assert(sizeof(result.E) * 8 >= CC64_FIELD_EXPONENT_LOW_PART_SIZE + CC64_FIELD_EXPONENT_HIGH_PART_SIZE, "E field too small");


    result.IE = (_Bool)cc64_getbits((pesbt), CC64_FIELD_INTERNAL_EXPONENT_START, CC64_FIELD_INTERNAL_EXPONENT_SIZE);
    uint8_t L_msb;
    if (result.IE) {
        result.E = (uint8_t)(cc64_getbits((pesbt), CC64_FIELD_EXPONENT_LOW_PART_START, CC64_FIELD_EXPONENT_LOW_PART_SIZE) | (cc64_getbits((pesbt), CC64_FIELD_EXPONENT_HIGH_PART_START, CC64_FIELD_EXPONENT_HIGH_PART_SIZE) << CC64_FIELD_EXPONENT_LOW_PART_SIZE));



        result.B = (uint16_t)cc64_getbits((pesbt), CC64_FIELD_EXP_NONZERO_BOTTOM_START, CC64_FIELD_EXP_NONZERO_BOTTOM_SIZE) << CC64_FIELD_EXPONENT_LOW_PART_SIZE;
        result.T = (uint16_t)cc64_getbits((pesbt), CC64_FIELD_EXP_NONZERO_TOP_START, CC64_FIELD_EXP_NONZERO_TOP_SIZE) << CC64_FIELD_EXPONENT_HIGH_PART_SIZE;
        L_msb = 1;
    } else {
        result.E = 0;



        L_msb = 0;

        result.B = (uint16_t)cc64_getbits((pesbt), CC64_FIELD_EXP_ZERO_BOTTOM_START, CC64_FIELD_EXP_ZERO_BOTTOM_SIZE);
        result.T = (uint16_t)cc64_getbits((pesbt), CC64_FIELD_EXP_ZERO_TOP_START, CC64_FIELD_EXP_ZERO_TOP_SIZE);
    }






    uint8_t L_carry = result.T < (result.B & TMask) ? 1 : 0;
    uint64_t BTop2 = cc64_getbits(result.B, 8 - 2, 2);
    uint8_t T_infer = (BTop2 + L_carry + L_msb) & 0x3;
    result.T |= ((uint16_t)T_infer) << (BWidth - 2);
    return result;
}


extern _Bool cc64_bounds_bits_valid(struct cc64_bounds_bits bounds) {

    cc64_addr_t Bmsb = cc64_getbits(bounds.B, 8 - 1, 1);
    cc64_addr_t Bmsb2 = cc64_getbits(bounds.B, 8 - 2, 2);
    cc64_addr_t Tmsb = cc64_getbits(bounds.T, 8 - 1, 1);
    if (bounds.E >= 26) {
        return Tmsb == 0 && Bmsb2 == 0;
    } else if (bounds.E == 26 - 1) {
        return Bmsb == 0;
    } else {
        return 1;
    }
}



extern cc64_addr_t cc64_cap_bounds_address(cc64_addr_t addr) {

    cc64_addr_t cursor = addr & 0xFFFFFFFF;

    if (cursor & ((0xFFFFFFFF >> 1) + 1))
        cursor |= ~0xFFFFFFFF;
    return cursor;
}





extern _Bool cc64_compute_base_top(struct cc64_bounds_bits bounds, cc64_addr_t cursor, cc64_addr_t* base_out,
                                           cc64_length_t* top_out) {





    cursor = cc64_cap_bounds_address(cursor);




    uint8_t E = ((26) < (bounds.E) ? (26) : (bounds.E));




    unsigned a_mid = (unsigned)cc64_truncate64(cursor >> (E + 8 - 3), 3);
    unsigned correction_B = (unsigned)cc64_truncateLSB_8(bounds.B, 3);
    unsigned correction_T = (unsigned)cc64_truncateLSB_8(bounds.T, 3);

    unsigned R = (unsigned)cc64_truncate64(correction_B - 1, 3);
# 440 "./cheri_compressed_cap_common.h"
    int aHi = a_mid < R ? 1 : 0;
    int bHi = correction_B < R ? 1 : 0;
    int tHi = correction_T < R ? 1 : 0;




    int correction_base = bHi - aHi;
    int correction_top = tHi - aHi;

    const unsigned a_top_shift = E + 8;

    cc64_addr_t a_top = a_top_shift >= 32 ? 0 : cursor >> a_top_shift;


    cc64_length_t base = (cc64_addr_t)((int64_t)a_top + correction_base);
    base <<= 8;
    base |= bounds.B;
    base <<= E;
    base &= ((cc64_length_t)1 << 33) - 1;
    ((void) sizeof (((cc64_addr_t)(base >> 32) <= 1) ? 1 : 0), __extension__ ({ if ((cc64_addr_t)(base >> 32) <= 1) ; else __assert_fail ("(cc64_addr_t)(base >> 32) <= 1", "./cheri_compressed_cap_common.h", 460, __extension__ __PRETTY_FUNCTION__); }));

    cc64_length_t top = (cc64_addr_t)((int64_t)a_top + correction_top);
    top <<= 8;
    top |= bounds.T;
    top <<= E;
    top &= ((cc64_length_t)1 << 33) - 1;
    ((void) sizeof (((cc64_addr_t)(top >> 32) <= 1) ? 1 : 0), __extension__ ({ if ((cc64_addr_t)(top >> 32) <= 1) ; else __assert_fail ("(cc64_addr_t)(top >> 32) <= 1", "./cheri_compressed_cap_common.h", 467, __extension__ __PRETTY_FUNCTION__); }));







    unsigned base2 = cc64_truncate64(base >> (32 - 1), 1);

    unsigned top2 = cc64_truncate64(top >> (32 - 1), 2);



    if (E < (26 - 1) && (top2 - base2) > 1) {
        top = top ^ ((cc64_length_t)1 << 32);
    }

    ((void) sizeof (((cc64_addr_t)(top >> 32) <= 1) ? 1 : 0), __extension__ ({ if ((cc64_addr_t)(top >> 32) <= 1) ; else __assert_fail ("(cc64_addr_t)(top >> 32) <= 1", "./cheri_compressed_cap_common.h", 485, __extension__ __PRETTY_FUNCTION__); }));

    if (cc64_bounds_bits_valid(bounds)) {


        ((void) sizeof (((cc64_addr_t)base <= top) ? 1 : 0), __extension__ ({ if ((cc64_addr_t)base <= top) ; else __assert_fail ("(cc64_addr_t)base <= top", "./cheri_compressed_cap_common.h", 490, __extension__ __PRETTY_FUNCTION__); }));
    } else {

    }
    *base_out = (cc64_addr_t)base;
    *top_out = top;

    return 1;
}



extern void cc64_unsafe_decompress_raw(cc64_addr_t pesbt, cc64_addr_t cursor, _Bool tag,
                                                __attribute__((unused)) uint8_t lvbits, cc64_cap_t* cdp) {
    memset(cdp, 0, sizeof(*cdp));
    cdp->cr_tag = tag;
    cdp->_cr_cursor = cursor;
    cdp->cr_pesbt = pesbt;




    struct cc64_bounds_bits bounds = cc64_extract_bounds_bits(pesbt);
    _Bool valid = cc64_compute_base_top(bounds, cursor, &cdp->cr_base, &cdp->_cr_top);
    cdp->cr_bounds_valid = valid;
    cdp->cr_exp = bounds.E;
}

extern void cc64_decompress_raw_ext(cc64_addr_t pesbt, cc64_addr_t cursor, _Bool tag, uint8_t lvbits,
                                             cc64_cap_t* cdp) {
    cc64_unsafe_decompress_raw(pesbt, cursor, tag, lvbits, cdp);
    if (tag) {
        ((void) sizeof ((cdp->cr_base <= (4294967295U)) ? 1 : 0), __extension__ ({ if (cdp->cr_base <= (4294967295U)) ; else __assert_fail ("cdp->cr_base <= (4294967295U)", "./cheri_compressed_cap_common.h", 522, __extension__ __PRETTY_FUNCTION__); }));


        ((void) sizeof ((cdp->_cr_top <= ((cc64_length_t)1u << 32)) ? 1 : 0), __extension__ ({ if (cdp->_cr_top <= ((cc64_length_t)1u << 32)) ; else __assert_fail ("cdp->_cr_top <= ((cc64_length_t)1u << 32)", "./cheri_compressed_cap_common.h", 525, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((cdp->cr_base <= cdp->_cr_top) ? 1 : 0), __extension__ ({ if (cdp->cr_base <= cdp->_cr_top) ; else __assert_fail ("cdp->cr_base <= cdp->_cr_top", "./cheri_compressed_cap_common.h", 526, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((cdp->cr_bounds_valid) ? 1 : 0), __extension__ ({ if (cdp->cr_bounds_valid) ; else __assert_fail ("cdp->cr_bounds_valid", "./cheri_compressed_cap_common.h", 527, __extension__ __PRETTY_FUNCTION__); }));

        ((void) sizeof ((cc64_reserved_bits_valid(cdp)) ? 1 : 0), __extension__ ({ if (cc64_reserved_bits_valid(cdp)) ; else __assert_fail ("cc64_reserved_bits_valid(cdp)", "./cheri_compressed_cap_common.h", 529, __extension__ __PRETTY_FUNCTION__); }));
    }
}

extern void cc64_decompress_raw(cc64_addr_t pesbt, cc64_addr_t cursor, _Bool tag, cc64_cap_t* cdp) {
    cc64_decompress_raw_ext(pesbt, cursor, tag, 1, cdp);
}




extern void cc64_decompress_mem(uint64_t pesbt, uint64_t cursor, _Bool tag, cc64_cap_t* cdp) {
    cc64_decompress_raw_ext(pesbt ^ CC64_MEM_XOR_MASK, cursor, tag, 1, cdp);
}


extern _Bool cc64_pesbt_is_correct(const cc64_cap_t* csp) {
    cc64_cap_t tmp;

    cc64_unsafe_decompress_raw(csp->cr_pesbt, csp->_cr_cursor, csp->cr_tag, cc64_get_lvbits(csp), &tmp);
    tmp.cr_extra = csp->cr_extra;
    if (!cc64_raw_equal(&tmp, csp)) {
        return 0;
    }
    return 1;
}


extern void cc64_update_ebt(cc64_cap_t* csp, cc64_addr_t new_ebt) {
    csp->cr_pesbt = (csp->cr_pesbt & ~CC64_FIELD_EBT_MASK64) | new_ebt;
    csp->cr_exp = cc64_extract_bounds_bits(new_ebt).E;
}






extern cc64_addr_t cc64_compress_raw(const cc64_cap_t* csp) {


    ((void) sizeof (((!csp->cr_tag || (csp->cr_bounds_valid && cc64_reserved_bits_valid(csp))) && "Malformed bounds or unknown reserved bits in tagged capability") ? 1 : 0), __extension__ ({ if ((!csp->cr_tag || (csp->cr_bounds_valid && cc64_reserved_bits_valid(csp))) && "Malformed bounds or unknown reserved bits in tagged capability") ; else __assert_fail ("(!csp->cr_tag || (csp->cr_bounds_valid && cc64_reserved_bits_valid(csp))) && \"Malformed bounds or unknown reserved bits in tagged capability\"", "./cheri_compressed_cap_common.h", 571, __extension__ __PRETTY_FUNCTION__); }));


    ((void) sizeof ((cc64_pesbt_is_correct(csp) && "capability bounds were modified without updating pesbt") ? 1 : 0), __extension__ ({ if (cc64_pesbt_is_correct(csp) && "capability bounds were modified without updating pesbt") ; else __assert_fail ("cc64_pesbt_is_correct(csp) && \"capability bounds were modified without updating pesbt\"", "./cheri_compressed_cap_common.h", 573, __extension__ __PRETTY_FUNCTION__); }));
    return csp->cr_pesbt;
}

extern cc64_addr_t cc64_compress_mem(const cc64_cap_t* csp) {
    return cc64_compress_raw(csp) ^ CC64_MEM_XOR_MASK;
}

static _Bool cc64__fast_is_representable_new_addr(const cc64_cap_t* cap, cc64_addr_t new_addr);


extern _Bool cc64_is_representable_cap_exact(const cc64_cap_t* cap) {
    cc64_addr_t pesbt = cc64_compress_raw(cap);
    cc64_cap_t decompressed_cap;

    cc64_unsafe_decompress_raw(pesbt, cap->_cr_cursor, cap->cr_tag, cc64_get_lvbits(cap), &decompressed_cap);

    ((void) sizeof ((decompressed_cap._cr_cursor == cap->_cr_cursor) ? 1 : 0), __extension__ ({ if (decompressed_cap._cr_cursor == cap->_cr_cursor) ; else __assert_fail ("decompressed_cap._cr_cursor == cap->_cr_cursor", "./cheri_compressed_cap_common.h", 590, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((decompressed_cap.cr_pesbt == cap->cr_pesbt) ? 1 : 0), __extension__ ({ if (decompressed_cap.cr_pesbt == cap->cr_pesbt) ; else __assert_fail ("decompressed_cap.cr_pesbt == cap->cr_pesbt", "./cheri_compressed_cap_common.h", 591, __extension__ __PRETTY_FUNCTION__); }));

    if (decompressed_cap.cr_base != cap->cr_base || decompressed_cap._cr_top != cap->_cr_top) {
        return 0;
    }
    return 1;
}

extern uint32_t cc64_compute_ebt(cc64_addr_t req_base, cc64_length_t req_top, cc64_addr_t* alignment_mask,
                                          _Bool* exact) {
# 609 "./cheri_compressed_cap_common.h"
    ((void) sizeof ((req_base <= req_top && "Cannot invert base and top") ? 1 : 0), __extension__ ({ if (req_base <= req_top && "Cannot invert base and top") ; else __assert_fail ("req_base <= req_top && \"Cannot invert base and top\"", "./cheri_compressed_cap_common.h", 609, __extension__ __PRETTY_FUNCTION__); }));






    cc64_length_t req_length65 = req_top - req_base;
# 625 "./cheri_compressed_cap_common.h"
    uint8_t E = (uint8_t)cc64_get_exponent(req_length65);
    const uint64_t req_length64 = (uint64_t)req_length65;




    const _Bool InternalExponent = E != 0 || cc64_getbits(req_length64, CC64_FIELD_EXP_NONZERO_BOTTOM_SIZE + 1, 1);
    if (!InternalExponent) {






        uint32_t ebt_bits = ((uint64_t)((0) & CC64_FIELD_INTERNAL_EXPONENT_MAX_VALUE) << CC64_FIELD_INTERNAL_EXPONENT_START) | ((uint64_t)((req_top) & CC64_FIELD_EXP_ZERO_TOP_MAX_VALUE) << CC64_FIELD_EXP_ZERO_TOP_START) |
                            ((uint64_t)((req_base) & CC64_FIELD_EXP_ZERO_BOTTOM_MAX_VALUE) << CC64_FIELD_EXP_ZERO_BOTTOM_START);
# 667 "./cheri_compressed_cap_common.h"
        if (alignment_mask)
            *alignment_mask = (4294967295U);
        *exact = 1;
        return ebt_bits;
    }
# 680 "./cheri_compressed_cap_common.h"
    cc64_addr_t bot_ie = cc64_truncate64(req_base >> (E + CC64_FIELD_EXPONENT_LOW_PART_SIZE), CC64_FIELD_EXP_NONZERO_BOTTOM_SIZE);
    if (alignment_mask) {
        *alignment_mask = (18446744073709551615UL) << (E + CC64_FIELD_EXPONENT_LOW_PART_SIZE);
    }
    cc64_addr_t top_ie = cc64_truncate64((cc64_addr_t)(req_top >> (E + CC64_FIELD_EXPONENT_LOW_PART_SIZE)), CC64_FIELD_EXP_NONZERO_BOTTOM_SIZE);







    const cc64_length_t maskLo = (((cc64_length_t)1u) << (E + CC64_FIELD_EXPONENT_LOW_PART_SIZE)) - 1;
    const cc64_length_t zero65 = 0;
    _Bool lostSignificantBase = (req_base & maskLo) != zero65;
    _Bool lostSignificantTop = (req_top & maskLo) != zero65;





    if (lostSignificantTop) {
        top_ie = cc64_truncate64(top_ie + 1, CC64_FIELD_EXP_NONZERO_BOTTOM_SIZE);
    }
# 719 "./cheri_compressed_cap_common.h"
    const cc64_addr_t len_ie = cc64_truncate64(top_ie - bot_ie, CC64_FIELD_EXP_NONZERO_BOTTOM_SIZE);
    _Bool incE = 0;
    if (cc64_getbits(len_ie, CC64_FIELD_EXP_NONZERO_BOTTOM_SIZE - 1, 1)) {
        incE = 1;
        lostSignificantBase = lostSignificantBase || cc64_getbits(bot_ie, 0, 1);
        lostSignificantTop = lostSignificantTop || cc64_getbits(top_ie, 0, 1);
        bot_ie = cc64_truncate64(req_base >> (E + CC64_FIELD_EXPONENT_LOW_PART_SIZE + 1), CC64_FIELD_EXP_NONZERO_BOTTOM_SIZE);

        if (alignment_mask) {
            *alignment_mask = (18446744073709551615UL) << (E + CC64_FIELD_EXPONENT_LOW_PART_SIZE + 1);
        }
        const _Bool incT = lostSignificantTop;
        top_ie = cc64_truncate64((cc64_addr_t)(req_top >> (E + CC64_FIELD_EXPONENT_LOW_PART_SIZE + 1)), CC64_FIELD_EXP_NONZERO_BOTTOM_SIZE);
        if (incT) {
            top_ie = cc64_truncate64(top_ie + 1, CC64_FIELD_EXP_NONZERO_BOTTOM_SIZE);
        }
    }
    const uint8_t newE = E + (incE ? 1 : 0);

    *exact = !lostSignificantBase && !lostSignificantTop;

    const cc64_addr_t expBits = ((uint64_t)(((newE) >> CC64_FIELD_EXPONENT_LOW_PART_SIZE) & CC64_FIELD_EXPONENT_HIGH_PART_MAX_VALUE) << CC64_FIELD_EXPONENT_HIGH_PART_START) | ((uint64_t)((newE) & CC64_FIELD_EXPONENT_LOW_PART_MAX_VALUE) << CC64_FIELD_EXPONENT_LOW_PART_START);
    return expBits | ((uint64_t)((1) & CC64_FIELD_INTERNAL_EXPONENT_MAX_VALUE) << CC64_FIELD_INTERNAL_EXPONENT_START) | ((uint64_t)((top_ie) & CC64_FIELD_EXP_NONZERO_TOP_MAX_VALUE) << CC64_FIELD_EXP_NONZERO_TOP_START) |
           ((uint64_t)((bot_ie) & CC64_FIELD_EXP_NONZERO_BOTTOM_MAX_VALUE) << CC64_FIELD_EXP_NONZERO_BOTTOM_START);
}

extern _Bool cc64__precise_is_representable_new_addr(const cc64_cap_t* oldcap, cc64_addr_t new_cursor) {

    cc64_cap_t newcap = *oldcap;
    newcap._cr_cursor = new_cursor;
    struct cc64_bounds_bits old_bounds_bits = cc64_extract_bounds_bits(cc64_compress_raw(oldcap));
    newcap.cr_bounds_valid = cc64_compute_base_top(old_bounds_bits, new_cursor, &newcap.cr_base, &newcap._cr_top);
    return newcap.cr_base == oldcap->cr_base && newcap._cr_top == oldcap->_cr_top && newcap.cr_bounds_valid &&
           oldcap->cr_bounds_valid;
}

extern _Bool cc64_cap_bounds_uses_value_for_exp(uint8_t exponent) {
    return exponent < (sizeof(cc64_addr_t) * 8) - CC64_FIELD_BOTTOM_ENCODED_SIZE;
}


extern _Bool cc64_cap_bounds_uses_value(const cc64_cap_t* cap) {

    ((void) sizeof ((cc64_pesbt_is_correct(cap)) ? 1 : 0), __extension__ ({ if (cc64_pesbt_is_correct(cap)) ; else __assert_fail ("cc64_pesbt_is_correct(cap)", "./cheri_compressed_cap_common.h", 762, __extension__ __PRETTY_FUNCTION__); }));
    return cc64_cap_bounds_uses_value_for_exp(cap->cr_exp);
}

extern _Bool cc64_cap_sign_change(cc64_addr_t addr1, cc64_addr_t addr2) {



    (void)addr1;
    (void)addr2;
    return 0;

}

extern _Bool cc64_cap_sign_change_causes_unrepresentability(const cc64_cap_t* cap, cc64_addr_t addr1,
                                                                    cc64_addr_t addr2) {
    return cc64_cap_sign_change(addr1, addr2) && cc64_cap_bounds_uses_value(cap);
}

extern _Bool cc64_is_representable_with_addr(const cc64_cap_t* cap, cc64_addr_t new_addr,
                                                     _Bool precise_representable_check) {
# 794 "./cheri_compressed_cap_common.h"
    cc64_addr_t extended_cursor = cc64_cap_bounds_address(new_addr);

    if (__builtin_expect(extended_cursor >= cap->cr_base && extended_cursor < cap->_cr_top, 1)) {
        return 1;
    }
    if (precise_representable_check) {
        return cc64__precise_is_representable_new_addr(cap, new_addr);
    } else {
        return cc64__fast_is_representable_new_addr(cap, new_addr);
    }
}



extern void cc64_set_addr(cc64_cap_t* cap, cc64_addr_t new_addr) {
    if (cap->cr_tag && cc64_is_cap_sealed(cap)) {
        cap->cr_tag = 0;
    }
    if (!cc64_is_representable_with_addr(cap, new_addr, 0)) {

        cap->cr_tag = 0;
        cc64_decompress_raw(cap->cr_pesbt, new_addr, 0, cap);
    } else {
        cap->_cr_cursor = new_addr;
    }
}

static _Bool cc64__fast_is_representable_new_addr(const cc64_cap_t* cap, cc64_addr_t new_addr) {
    if (cap->_cr_top == ((cc64_length_t)1u << 32) && cap->cr_base == 0) {
        return 1;
    }




    struct cc64_bounds_bits bounds = cc64_extract_bounds_bits(cap->cr_pesbt);

    cc64_addr_t inc = cc64_cap_bounds_address(new_addr - cap->_cr_cursor);
    cc64_addr_t cursor = cc64_cap_bounds_address(cap->_cr_cursor);


    size_t i_top_shift = bounds.E + 8;
    if (i_top_shift >= 32) {
        i_top_shift = 32 - 1;
    }
    size_t e_shift = bounds.E >= 32 ? 32 - 1 : bounds.E;
    cc64_saddr_t i_top = (cc64_saddr_t)inc >> i_top_shift;
    cc64_addr_t i_mid = cc64_truncate_addr((cc64_addr_t)inc >> e_shift, 8);
    cc64_addr_t a_mid = cc64_truncate_addr((cc64_addr_t)cursor >> e_shift, 8);
    cc64_addr_t B3 = (cc64_addr_t)cc64_truncateLSB_8(bounds.B, 3);
    cc64_addr_t R3 = cc64_truncate_addr(B3 - 1, 3);
    cc64_addr_t R = cc64_truncate_addr(R3 << (8 - 3), 8);
    cc64_addr_t diff = cc64_truncate_addr(R - a_mid, 8);
    cc64_addr_t diff1 = cc64_truncate_addr(diff - 1, 8);



    _Bool inLimits;
    if (i_top == 0) {
        inLimits = i_mid < diff1;
    } else if (i_top == (cc64_saddr_t)-1) {
        inLimits = i_mid >= diff && R != a_mid;
    } else {
        inLimits = 0;
    }
    return inLimits || bounds.E >= 26 - 2;

}


extern _Bool cc64_setbounds_impl(cc64_cap_t* cap, cc64_length_t req_len, cc64_addr_t* alignment_mask) {
    uint64_t req_base = cap->_cr_cursor;
    if (cc64_is_cap_sealed(cap)) {
        cap->cr_tag = 0;
    }
# 881 "./cheri_compressed_cap_common.h"
    cc64_length_t req_top = (cc64_length_t)req_base + req_len;
    ((void) sizeof ((req_base <= req_top && "Cannot invert base and top") ? 1 : 0), __extension__ ({ if (req_base <= req_top && "Cannot invert base and top") ; else __assert_fail ("req_base <= req_top && \"Cannot invert base and top\"", "./cheri_compressed_cap_common.h", 882, __extension__ __PRETTY_FUNCTION__); }));

    if (req_base < cap->cr_base || req_top > cap->_cr_top) {
        cap->cr_tag = 0;
    }




    _Static_assert(CC64_FIELD_EXPONENT_LOW_PART_SIZE == 3, "expected 3 bits to be used by");
    _Static_assert(CC64_FIELD_EXPONENT_HIGH_PART_SIZE == 3, "expected 3 bits to be used by");






    _Bool exact = 0;
    uint32_t new_ebt = cc64_compute_ebt(req_base, req_top, alignment_mask, &exact);
    cc64_addr_t new_base;
    cc64_length_t new_top;
    _Bool new_bounds_valid = cc64_compute_base_top(cc64_extract_bounds_bits(((uint64_t)((new_ebt) & CC64_FIELD_EBT_MAX_VALUE) << CC64_FIELD_EBT_START)),
                                                    cap->_cr_cursor, &new_base, &new_top);
    if (exact) {




        ((void) sizeof ((new_base == req_base && "Should be exact") ? 1 : 0), __extension__ ({ if (new_base == req_base && "Should be exact") ; else __assert_fail ("new_base == req_base && \"Should be exact\"", "./cheri_compressed_cap_common.h", 910, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((new_top == req_top && "Should be exact") ? 1 : 0), __extension__ ({ if (new_top == req_top && "Should be exact") ; else __assert_fail ("new_top == req_top && \"Should be exact\"", "./cheri_compressed_cap_common.h", 911, __extension__ __PRETTY_FUNCTION__); }));

    } else {
        ((void) sizeof (((new_base != req_base || new_top != req_top) && "Was inexact, but neither base nor top different?") ? 1 : 0), __extension__ ({ if ((new_base != req_base || new_top != req_top) && "Was inexact, but neither base nor top different?") ; else __assert_fail ("(new_base != req_base || new_top != req_top) && \"Was inexact, but neither base nor top different?\"", "./cheri_compressed_cap_common.h", 915, __extension__ __PRETTY_FUNCTION__); }));

    }







    if (cap->cr_tag) {




        ((void) sizeof ((new_top >= new_base) ? 1 : 0), __extension__ ({ if (new_top >= new_base) ; else __assert_fail ("new_top >= new_base", "./cheri_compressed_cap_common.h", 929, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((cc64_reserved_bits_valid(cap) && "Unknown reserved bits set in tagged capability") ? 1 : 0), __extension__ ({ if (cc64_reserved_bits_valid(cap) && "Unknown reserved bits set in tagged capability") ; else __assert_fail ("cc64_reserved_bits_valid(cap) && \"Unknown reserved bits set in tagged capability\"", "./cheri_compressed_cap_common.h", 930, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((new_bounds_valid && "Malformed bounds in tagged capability") ? 1 : 0), __extension__ ({ if (new_bounds_valid && "Malformed bounds in tagged capability") ; else __assert_fail ("new_bounds_valid && \"Malformed bounds in tagged capability\"", "./cheri_compressed_cap_common.h", 931, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((new_base >= cap->cr_base && "Cannot reduce base on tagged capabilities") ? 1 : 0), __extension__ ({ if (new_base >= cap->cr_base && "Cannot reduce base on tagged capabilities") ; else __assert_fail ("new_base >= cap->cr_base && \"Cannot reduce base on tagged capabilities\"", "./cheri_compressed_cap_common.h", 932, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((new_top <= cap->_cr_top && "Cannot increase top on tagged capabilities") ? 1 : 0), __extension__ ({ if (new_top <= cap->_cr_top && "Cannot increase top on tagged capabilities") ; else __assert_fail ("new_top <= cap->_cr_top && \"Cannot increase top on tagged capabilities\"", "./cheri_compressed_cap_common.h", 933, __extension__ __PRETTY_FUNCTION__); }));
    }
    cap->cr_base = new_base;
    cap->_cr_top = new_top;
    cc64_update_ebt(cap, new_ebt);
    cap->cr_bounds_valid = new_bounds_valid;
    return exact;
}


extern _Bool cc64_setbounds(cc64_cap_t* cap, cc64_length_t req_len) {
    __attribute__((unused)) cc64_addr_t old_base = cap->cr_base;
    __attribute__((unused)) cc64_length_t old_top = cap->_cr_top;
    __attribute__((unused)) cc64_addr_t req_base =
        cc64_cap_bounds_uses_value(cap) ? cc64_cap_bounds_address(cap->_cr_cursor) : cap->_cr_cursor;
    __attribute__((unused)) cc64_length_t req_top = req_len + req_base;
    _Bool exact = cc64_setbounds_impl(cap, req_len, ((void*)0));
    if (cap->cr_tag) {

        ((void) sizeof ((!cc64_is_cap_sealed(cap) && "result cannot be sealed and tagged") ? 1 : 0), __extension__ ({ if (!cc64_is_cap_sealed(cap) && "result cannot be sealed and tagged") ; else __assert_fail ("!cc64_is_cap_sealed(cap) && \"result cannot be sealed and tagged\"", "./cheri_compressed_cap_common.h", 952, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((((cap->_cr_top - cap->cr_base) >> 32) <= 1 && "length must be smaller than 1 << 65") ? 1 : 0), __extension__ ({ if (((cap->_cr_top - cap->cr_base) >> 32) <= 1 && "length must be smaller than 1 << 65") ; else __assert_fail ("((cap->_cr_top - cap->cr_base) >> 32) <= 1 && \"length must be smaller than 1 << 65\"", "./cheri_compressed_cap_common.h", 954, __extension__ __PRETTY_FUNCTION__); }));

        ((void) sizeof ((cap->cr_base >= old_base && "cannot remain tagged if base was decreased") ? 1 : 0), __extension__ ({ if (cap->cr_base >= old_base && "cannot remain tagged if base was decreased") ; else __assert_fail ("cap->cr_base >= old_base && \"cannot remain tagged if base was decreased\"", "./cheri_compressed_cap_common.h", 955, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((cap->_cr_top <= old_top && "cannot remain tagged if top was increased") ? 1 : 0), __extension__ ({ if (cap->_cr_top <= old_top && "cannot remain tagged if top was increased") ; else __assert_fail ("cap->_cr_top <= old_top && \"cannot remain tagged if top was increased\"", "./cheri_compressed_cap_common.h", 956, __extension__ __PRETTY_FUNCTION__); }));


        ((void) sizeof (((cap->_cr_top <= ((cc64_length_t)1u << 32) || old_top > ((cc64_length_t)1u << 32)) && "cannot remain tagged if new top greater 1 << 65") ? 1 : 0), __extension__ ({ if ((cap->_cr_top <= ((cc64_length_t)1u << 32) || old_top > ((cc64_length_t)1u << 32)) && "cannot remain tagged if new top greater 1 << 65") ; else __assert_fail ("(cap->_cr_top <= ((cc64_length_t)1u << 32) || old_top > ((cc64_length_t)1u << 32)) && \"cannot remain tagged if new top greater 1 << 65\"", "./cheri_compressed_cap_common.h", 960, __extension__ __PRETTY_FUNCTION__); }));

    }

    if (exact) {
        ((void) sizeof ((cc64_cap_bounds_address(cap->cr_base) == cc64_cap_bounds_address(req_base) && "base changed but still reported exact") ? 1 : 0), __extension__ ({ if (cc64_cap_bounds_address(cap->cr_base) == cc64_cap_bounds_address(req_base) && "base changed but still reported exact") ; else __assert_fail ("cc64_cap_bounds_address(cap->cr_base) == cc64_cap_bounds_address(req_base) && \"base changed but still reported exact\"", "./cheri_compressed_cap_common.h", 965, __extension__ __PRETTY_FUNCTION__); }));

        ((void) sizeof ((cc64_cap_bounds_address(cap->_cr_top) == cc64_cap_bounds_address(req_top) && "top changed but still reported exact") ? 1 : 0), __extension__ ({ if (cc64_cap_bounds_address(cap->_cr_top) == cc64_cap_bounds_address(req_top) && "top changed but still reported exact") ; else __assert_fail ("cc64_cap_bounds_address(cap->_cr_top) == cc64_cap_bounds_address(req_top) && \"top changed but still reported exact\"", "./cheri_compressed_cap_common.h", 967, __extension__ __PRETTY_FUNCTION__); }));

    } else {
        ((void) sizeof (((cap->_cr_top != req_top || cap->cr_base != req_base) && "result is exact but reported inexact") ? 1 : 0), __extension__ ({ if ((cap->_cr_top != req_top || cap->cr_base != req_base) && "result is exact but reported inexact") ; else __assert_fail ("(cap->_cr_top != req_top || cap->cr_base != req_base) && \"result is exact but reported inexact\"", "./cheri_compressed_cap_common.h", 970, __extension__ __PRETTY_FUNCTION__); }));

    }
    return exact;
}


extern _Bool cc64_checked_setbounds(cc64_cap_t* cap, cc64_length_t req_len) {
    __attribute__((unused)) cc64_addr_t req_base =
        cc64_cap_bounds_uses_value(cap) ? cc64_cap_bounds_address(cap->_cr_cursor) : cap->_cr_cursor;
    __attribute__((unused)) cc64_length_t req_top = req_len + req_base;
    if (cap->cr_tag) {

        ((void) sizeof (((!cc64_is_cap_sealed(cap)) && "cannot be used on tagged sealed capabilities") ? 1 : 0), __extension__ ({ if ((!cc64_is_cap_sealed(cap)) && "cannot be used on tagged sealed capabilities") ; else __assert_fail ("(!cc64_is_cap_sealed(cap)) && \"cannot be used on tagged sealed capabilities\"", "./cheri_compressed_cap_common.h", 982, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((req_base >= cap->cr_base) && "cannot decrease base on tagged capabilities") ? 1 : 0), __extension__ ({ if ((req_base >= cap->cr_base) && "cannot decrease base on tagged capabilities") ; else __assert_fail ("(req_base >= cap->cr_base) && \"cannot decrease base on tagged capabilities\"", "./cheri_compressed_cap_common.h", 983, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((req_top <= cap->_cr_top) && "cannot increase top on tagged capabilities") ? 1 : 0), __extension__ ({ if ((req_top <= cap->_cr_top) && "cannot increase top on tagged capabilities") ; else __assert_fail ("(req_top <= cap->_cr_top) && \"cannot increase top on tagged capabilities\"", "./cheri_compressed_cap_common.h", 984, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((req_len < ((cc64_length_t)1u << 32)) && "requested length must be smaller than max length") ? 1 : 0), __extension__ ({ if ((req_len < ((cc64_length_t)1u << 32)) && "requested length must be smaller than max length") ; else __assert_fail ("(req_len < ((cc64_length_t)1u << 32)) && \"requested length must be smaller than max length\"", "./cheri_compressed_cap_common.h", 985, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((req_top < ((cc64_length_t)1u << 32)) && "new top must be smaller than max length") ? 1 : 0), __extension__ ({ if ((req_top < ((cc64_length_t)1u << 32)) && "new top must be smaller than max length") ; else __assert_fail ("(req_top < ((cc64_length_t)1u << 32)) && \"new top must be smaller than max length\"", "./cheri_compressed_cap_common.h", 986, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((cap->_cr_top <= ((cc64_length_t)1u << 32)) && "input capability top must be less than max top") ? 1 : 0), __extension__ ({ if ((cap->_cr_top <= ((cc64_length_t)1u << 32)) && "input capability top must be less than max top") ; else __assert_fail ("(cap->_cr_top <= ((cc64_length_t)1u << 32)) && \"input capability top must be less than max top\"", "./cheri_compressed_cap_common.h", 987, __extension__ __PRETTY_FUNCTION__); }));
    }
    return cc64_setbounds(cap, req_len);
}


extern cc64_cap_t cc64__make_max_perms_cap_common(cc64_addr_t base, cc64_addr_t cursor, cc64_length_t top,
                                                          __attribute__((unused)) uint8_t lvbits) {
    cc64_cap_t creg;
    memset(&creg, 0, sizeof(creg));
    ((void) sizeof ((base <= top && "Invalid arguments") ? 1 : 0), __extension__ ({ if (base <= top && "Invalid arguments") ; else __assert_fail ("base <= top && \"Invalid arguments\"", "./cheri_compressed_cap_common.h", 997, __extension__ __PRETTY_FUNCTION__); }));
    creg.cr_base = base;
    creg._cr_cursor = cursor;
    creg.cr_bounds_valid = 1;
    creg._cr_top = top;
    creg.cr_pesbt = (((uint64_t)(((0)) & CC64_FIELD_UPERMS_MAX_VALUE) << CC64_FIELD_UPERMS_START) | ((uint64_t)(((0xfff)) & CC64_FIELD_HWPERMS_MAX_VALUE) << CC64_FIELD_HWPERMS_START)) | ((uint64_t)((CC64_OTYPE_UNSEALED) & CC64_FIELD_OTYPE_MAX_VALUE) << CC64_FIELD_OTYPE_START);
    creg.cr_tag = 1;
    creg.cr_exp = CC64_RESET_EXP;
    ((void) sizeof ((lvbits <= 1 && "We only support local-global levels.") ? 1 : 0), __extension__ ({ if (lvbits <= 1 && "We only support local-global levels.") ; else __assert_fail ("lvbits <= 1 && \"We only support local-global levels.\"", "./cheri_compressed_cap_common.h", 1005, __extension__ __PRETTY_FUNCTION__); }));



    _Bool exact_input = 0;
    cc64_update_ebt(&creg, cc64_compute_ebt(creg.cr_base, creg._cr_top, ((void*)0), &exact_input));
    ((void) sizeof ((exact_input && "Invalid arguments") ? 1 : 0), __extension__ ({ if (exact_input && "Invalid arguments") ; else __assert_fail ("exact_input && \"Invalid arguments\"", "./cheri_compressed_cap_common.h", 1011, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((cc64_is_representable_cap_exact(&creg)) ? 1 : 0), __extension__ ({ if (cc64_is_representable_cap_exact(&creg)) ; else __assert_fail ("_cc_N(is_representable_cap_exact)(&creg)", "./cheri_compressed_cap_common.h", 1012, __extension__ __PRETTY_FUNCTION__); }));
    return creg;
}




extern cc64_cap_t cc64_make_max_perms_cap_ext(cc64_addr_t base, cc64_addr_t cursor, cc64_length_t top,
                                                      CC64_Mode mode, uint8_t lvbits) {
    cc64_cap_t creg = cc64__make_max_perms_cap_common(base, cursor, top, lvbits);
    _Bool mode_valid = cc64_set_execution_mode(&creg, mode);
    ((void) sizeof ((mode_valid && "Could not set mode on max perms cap") ? 1 : 0), __extension__ ({ if (mode_valid && "Could not set mode on max perms cap") ; else __assert_fail ("mode_valid && \"Could not set mode on max perms cap\"", "./cheri_compressed_cap_common.h", 1023, __extension__ __PRETTY_FUNCTION__); }));
    return creg;
}
extern cc64_cap_t cc64_make_max_perms_cap(cc64_addr_t base, cc64_addr_t cursor, cc64_length_t top) {
    return cc64_make_max_perms_cap_ext(base, cursor, top, CC64_MODE_INT, 1);
}







extern cc64_addr_t cc64_get_alignment_mask(cc64_addr_t req_length) {
    if (req_length == 0) {



        return (4294967295U);
    }


    cc64_cap_t tmpcap = cc64_make_max_perms_cap(0, 0, ((cc64_length_t)1u << 32));
    cc64_addr_t mask = 0;
    cc64_setbounds_impl(&tmpcap, req_length, &mask);
    return mask;
}

extern cc64_cap_t cc64_make_null_derived_cap_ext(cc64_addr_t addr, __attribute__((unused)) uint8_t lvbits) {
    cc64_cap_t creg;
    memset(&creg, 0, sizeof(creg));
    creg._cr_cursor = addr;
    creg._cr_top = ((cc64_length_t)1u << 32);
    creg.cr_pesbt = CC64_NULL_PESBT;
    creg.cr_bounds_valid = 1;
    creg.cr_exp = CC64_NULL_EXP;
    ((void) sizeof ((cc64_is_representable_cap_exact(&creg)) ? 1 : 0), __extension__ ({ if (cc64_is_representable_cap_exact(&creg)) ; else __assert_fail ("cc64_is_representable_cap_exact(&creg)", "./cheri_compressed_cap_common.h", 1059, __extension__ __PRETTY_FUNCTION__); }));



    return creg;
}

extern cc64_cap_t cc64_make_null_derived_cap(cc64_addr_t addr) {
    return cc64_make_null_derived_cap_ext(addr, 1);
}

extern cc64_addr_t cc64_get_required_alignment(cc64_addr_t req_length) {


    return ~cc64_get_alignment_mask(req_length) + 1;
}

extern cc64_addr_t cc64_get_representable_length(cc64_addr_t req_length) {
    cc64_addr_t mask = cc64_get_alignment_mask(req_length);
    return (req_length + ~mask) & mask;
}
# 154 "./cheri_compressed_cap_64.h" 2
# 1 "./cheri_compressed_cap_v9_common.h" 1



extern cc64_addr_t cc64_get_all_permissions(const cc64_cap_t* cap) {
    return ((cc64_addr_t)(cc64_getbits((cap->cr_pesbt), CC64_FIELD_UPERMS_START, CC64_FIELD_UPERMS_SIZE) & (0)) << (15)) |
           (cc64_getbits((cap->cr_pesbt), CC64_FIELD_HWPERMS_START, CC64_FIELD_HWPERMS_SIZE) & (0xfff));
}
extern _Bool cc64_set_permissions(cc64_cap_t* cap, cc64_addr_t permissions) {
    ((void) sizeof ((((permissions & ((0xfff) | 0)) == permissions) && "invalid permissions") ? 1 : 0), __extension__ ({ if (((permissions & ((0xfff) | 0)) == permissions) && "invalid permissions") ; else __assert_fail ("((permissions & ((0xfff) | 0)) == permissions) && \"invalid permissions\"", "./cheri_compressed_cap_v9_common.h", 9, __extension__ __PRETTY_FUNCTION__); }));
    cc64_addr_t arch_perms = permissions & (0xfff);
    cc64_addr_t sw_perms = (permissions >> (15)) & (0);
    cap->cr_pesbt = __extension__({ ((void) sizeof ((arch_perms <= CC64_FIELD_HWPERMS_MAX_VALUE) ? 1 : 0), __extension__ ({ if (arch_perms <= CC64_FIELD_HWPERMS_MAX_VALUE) ; else __assert_fail ("arch_perms <= CC64_FIELD_HWPERMS_MAX_VALUE", "./cheri_compressed_cap_v9_common.h", 12, __extension__ __PRETTY_FUNCTION__); })); ((cap->cr_pesbt) & ~CC64_FIELD_HWPERMS_MASK64) | ((uint64_t)((arch_perms) & CC64_FIELD_HWPERMS_MAX_VALUE) << CC64_FIELD_HWPERMS_START); });
    cap->cr_pesbt = __extension__({ ((void) sizeof ((sw_perms <= CC64_FIELD_UPERMS_MAX_VALUE) ? 1 : 0), __extension__ ({ if (sw_perms <= CC64_FIELD_UPERMS_MAX_VALUE) ; else __assert_fail ("sw_perms <= CC64_FIELD_UPERMS_MAX_VALUE", "./cheri_compressed_cap_v9_common.h", 13, __extension__ __PRETTY_FUNCTION__); })); ((cap->cr_pesbt) & ~CC64_FIELD_UPERMS_MASK64) | ((uint64_t)((sw_perms) & CC64_FIELD_UPERMS_MAX_VALUE) << CC64_FIELD_UPERMS_START); });
    return 1;
}

extern CC64_Mode cc64_get_execution_mode(const cc64_cap_t* cap) {
    return (CC64_Mode)cc64_getbits((cap->cr_pesbt), CC64_FIELD_FLAGS_START, CC64_FIELD_FLAGS_SIZE);
}
extern _Bool cc64_set_execution_mode(cc64_cap_t* cap, CC64_Mode new_mode) {

    cap->cr_pesbt = __extension__({ ((void) sizeof (((unsigned)new_mode <= CC64_FIELD_FLAGS_MAX_VALUE) ? 1 : 0), __extension__ ({ if ((unsigned)new_mode <= CC64_FIELD_FLAGS_MAX_VALUE) ; else __assert_fail ("(unsigned)new_mode <= CC64_FIELD_FLAGS_MAX_VALUE", "./cheri_compressed_cap_v9_common.h", 22, __extension__ __PRETTY_FUNCTION__); })); ((cap->cr_pesbt) & ~CC64_FIELD_FLAGS_MASK64) | ((uint64_t)(((unsigned)new_mode) & CC64_FIELD_FLAGS_MAX_VALUE) << CC64_FIELD_FLAGS_START); });
    return 1;
}

extern cc64_addr_t cc64_get_reserved(const cc64_cap_t* cap) {
    return cap->cr_pesbt & CC64_FIELD_RESERVED_MASK64;
}

enum { CC64_PERMS_RESERVED_ONES = 0 };
# 155 "./cheri_compressed_cap_64.h" 2


_Static_assert((CC64_MEM_XOR_MASK) == (0x7c302U), "");
# 50 "./cheri_compressed_cap.h" 2
# 1 "./cheri_compressed_cap_64r.h" 1
# 68 "./cheri_compressed_cap_64r.h"
typedef uint64_t cc64r_length_t;
typedef int64_t cc64r_offset_t;
typedef uint32_t cc64r_addr_t;
typedef int32_t cc64r_saddr_t;
# 1 "./cheri_compressed_cap_macros.h" 1
# 73 "./cheri_compressed_cap_64r.h" 2
typedef enum CC64R_Mode { CC64R_MODE_CAP = 0, CC64R_MODE_INT = 1 } CC64R_Mode;


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
enum {
    CC64R_FIELD_SDP_START = (62 - 32), CC64R_FIELD_SDP_LAST = (63 - 32), CC64R_FIELD_SDP_SIZE = CC64R_FIELD_SDP_LAST - CC64R_FIELD_SDP_START + 1, CC64R_FIELD_SDP_MASK_NOT_SHIFTED = ((1UL << (CC64R_FIELD_SDP_SIZE)) - 1UL), CC64R_FIELD_SDP_MASK64 = (uint64_t)CC64R_FIELD_SDP_MASK_NOT_SHIFTED << CC64R_FIELD_SDP_START, CC64R_FIELD_SDP_MAX_VALUE = CC64R_FIELD_SDP_MASK_NOT_SHIFTED,
    CC64R_FIELD_AP_M_START = (57 - 32), CC64R_FIELD_AP_M_LAST = (61 - 32), CC64R_FIELD_AP_M_SIZE = CC64R_FIELD_AP_M_LAST - CC64R_FIELD_AP_M_START + 1, CC64R_FIELD_AP_M_MASK_NOT_SHIFTED = ((1UL << (CC64R_FIELD_AP_M_SIZE)) - 1UL), CC64R_FIELD_AP_M_MASK64 = (uint64_t)CC64R_FIELD_AP_M_MASK_NOT_SHIFTED << CC64R_FIELD_AP_M_START, CC64R_FIELD_AP_M_MAX_VALUE = CC64R_FIELD_AP_M_MASK_NOT_SHIFTED,
    CC64R_FIELD_MODE_START = (57 - 32), CC64R_FIELD_MODE_LAST = (57 - 32), CC64R_FIELD_MODE_SIZE = CC64R_FIELD_MODE_LAST - CC64R_FIELD_MODE_START + 1, CC64R_FIELD_MODE_MASK_NOT_SHIFTED = ((1UL << (CC64R_FIELD_MODE_SIZE)) - 1UL), CC64R_FIELD_MODE_MASK64 = (uint64_t)CC64R_FIELD_MODE_MASK_NOT_SHIFTED << CC64R_FIELD_MODE_START, CC64R_FIELD_MODE_MAX_VALUE = CC64R_FIELD_MODE_MASK_NOT_SHIFTED,
    CC64R_FIELD_FLAGS_START = (57 - 32), CC64R_FIELD_FLAGS_LAST = (57 - 32), CC64R_FIELD_FLAGS_SIZE = CC64R_FIELD_FLAGS_LAST - CC64R_FIELD_FLAGS_START + 1, CC64R_FIELD_FLAGS_MASK_NOT_SHIFTED = ((1UL << (CC64R_FIELD_FLAGS_SIZE)) - 1UL), CC64R_FIELD_FLAGS_MASK64 = (uint64_t)CC64R_FIELD_FLAGS_MASK_NOT_SHIFTED << CC64R_FIELD_FLAGS_START, CC64R_FIELD_FLAGS_MAX_VALUE = CC64R_FIELD_FLAGS_MASK_NOT_SHIFTED,
    CC64R_FIELD_LEVEL_START = (56 - 32), CC64R_FIELD_LEVEL_LAST = (56 - 32), CC64R_FIELD_LEVEL_SIZE = CC64R_FIELD_LEVEL_LAST - CC64R_FIELD_LEVEL_START + 1, CC64R_FIELD_LEVEL_MASK_NOT_SHIFTED = ((1UL << (CC64R_FIELD_LEVEL_SIZE)) - 1UL), CC64R_FIELD_LEVEL_MASK64 = (uint64_t)CC64R_FIELD_LEVEL_MASK_NOT_SHIFTED << CC64R_FIELD_LEVEL_START, CC64R_FIELD_LEVEL_MAX_VALUE = CC64R_FIELD_LEVEL_MASK_NOT_SHIFTED,
    CC64R_FIELD_RESERVED1_START = (55 - 32), CC64R_FIELD_RESERVED1_LAST = (55 - 32), CC64R_FIELD_RESERVED1_SIZE = CC64R_FIELD_RESERVED1_LAST - CC64R_FIELD_RESERVED1_START + 1, CC64R_FIELD_RESERVED1_MASK_NOT_SHIFTED = ((1UL << (CC64R_FIELD_RESERVED1_SIZE)) - 1UL), CC64R_FIELD_RESERVED1_MASK64 = (uint64_t)CC64R_FIELD_RESERVED1_MASK_NOT_SHIFTED << CC64R_FIELD_RESERVED1_START, CC64R_FIELD_RESERVED1_MAX_VALUE = CC64R_FIELD_RESERVED1_MASK_NOT_SHIFTED,
    CC64R_FIELD_RESERVED0_START = (53 - 32), CC64R_FIELD_RESERVED0_LAST = (54 - 32), CC64R_FIELD_RESERVED0_SIZE = CC64R_FIELD_RESERVED0_LAST - CC64R_FIELD_RESERVED0_START + 1, CC64R_FIELD_RESERVED0_MASK_NOT_SHIFTED = ((1UL << (CC64R_FIELD_RESERVED0_SIZE)) - 1UL), CC64R_FIELD_RESERVED0_MASK64 = (uint64_t)CC64R_FIELD_RESERVED0_MASK_NOT_SHIFTED << CC64R_FIELD_RESERVED0_START, CC64R_FIELD_RESERVED0_MAX_VALUE = CC64R_FIELD_RESERVED0_MASK_NOT_SHIFTED,
    CC64R_FIELD_OTYPE_START = (52 - 32), CC64R_FIELD_OTYPE_LAST = (52 - 32), CC64R_FIELD_OTYPE_SIZE = CC64R_FIELD_OTYPE_LAST - CC64R_FIELD_OTYPE_START + 1, CC64R_FIELD_OTYPE_MASK_NOT_SHIFTED = ((1UL << (CC64R_FIELD_OTYPE_SIZE)) - 1UL), CC64R_FIELD_OTYPE_MASK64 = (uint64_t)CC64R_FIELD_OTYPE_MASK_NOT_SHIFTED << CC64R_FIELD_OTYPE_START, CC64R_FIELD_OTYPE_MAX_VALUE = CC64R_FIELD_OTYPE_MASK_NOT_SHIFTED,
    CC64R_FIELD_EBT_START = (32 - 32), CC64R_FIELD_EBT_LAST = (51 - 32), CC64R_FIELD_EBT_SIZE = CC64R_FIELD_EBT_LAST - CC64R_FIELD_EBT_START + 1, CC64R_FIELD_EBT_MASK_NOT_SHIFTED = ((1UL << (CC64R_FIELD_EBT_SIZE)) - 1UL), CC64R_FIELD_EBT_MASK64 = (uint64_t)CC64R_FIELD_EBT_MASK_NOT_SHIFTED << CC64R_FIELD_EBT_START, CC64R_FIELD_EBT_MAX_VALUE = CC64R_FIELD_EBT_MASK_NOT_SHIFTED,

    CC64R_FIELD_EXPONENT_FORMAT_START = (51 - 32), CC64R_FIELD_EXPONENT_FORMAT_LAST = (51 - 32), CC64R_FIELD_EXPONENT_FORMAT_SIZE = CC64R_FIELD_EXPONENT_FORMAT_LAST - CC64R_FIELD_EXPONENT_FORMAT_START + 1, CC64R_FIELD_EXPONENT_FORMAT_MASK_NOT_SHIFTED = ((1UL << (CC64R_FIELD_EXPONENT_FORMAT_SIZE)) - 1UL), CC64R_FIELD_EXPONENT_FORMAT_MASK64 = (uint64_t)CC64R_FIELD_EXPONENT_FORMAT_MASK_NOT_SHIFTED << CC64R_FIELD_EXPONENT_FORMAT_START, CC64R_FIELD_EXPONENT_FORMAT_MAX_VALUE = CC64R_FIELD_EXPONENT_FORMAT_MASK_NOT_SHIFTED,
    CC64R_FIELD_LEN_MSB_START = (50 - 32), CC64R_FIELD_LEN_MSB_LAST = (50 - 32), CC64R_FIELD_LEN_MSB_SIZE = CC64R_FIELD_LEN_MSB_LAST - CC64R_FIELD_LEN_MSB_START + 1, CC64R_FIELD_LEN_MSB_MASK_NOT_SHIFTED = ((1UL << (CC64R_FIELD_LEN_MSB_SIZE)) - 1UL), CC64R_FIELD_LEN_MSB_MASK64 = (uint64_t)CC64R_FIELD_LEN_MSB_MASK_NOT_SHIFTED << CC64R_FIELD_LEN_MSB_START, CC64R_FIELD_LEN_MSB_MAX_VALUE = CC64R_FIELD_LEN_MSB_MASK_NOT_SHIFTED,

    CC64R_FIELD_INTERNAL_EXPONENT_SIZE = CC64R_FIELD_EXPONENT_FORMAT_SIZE,
    CC64R_FIELD_TOP_ENCODED_START = (42 - 32), CC64R_FIELD_TOP_ENCODED_LAST = (49 - 32), CC64R_FIELD_TOP_ENCODED_SIZE = CC64R_FIELD_TOP_ENCODED_LAST - CC64R_FIELD_TOP_ENCODED_START + 1, CC64R_FIELD_TOP_ENCODED_MASK_NOT_SHIFTED = ((1UL << (CC64R_FIELD_TOP_ENCODED_SIZE)) - 1UL), CC64R_FIELD_TOP_ENCODED_MASK64 = (uint64_t)CC64R_FIELD_TOP_ENCODED_MASK_NOT_SHIFTED << CC64R_FIELD_TOP_ENCODED_START, CC64R_FIELD_TOP_ENCODED_MAX_VALUE = CC64R_FIELD_TOP_ENCODED_MASK_NOT_SHIFTED,
    CC64R_FIELD_BOTTOM_ENCODED_START = (32 - 32), CC64R_FIELD_BOTTOM_ENCODED_LAST = (41 - 32), CC64R_FIELD_BOTTOM_ENCODED_SIZE = CC64R_FIELD_BOTTOM_ENCODED_LAST - CC64R_FIELD_BOTTOM_ENCODED_START + 1, CC64R_FIELD_BOTTOM_ENCODED_MASK_NOT_SHIFTED = ((1UL << (CC64R_FIELD_BOTTOM_ENCODED_SIZE)) - 1UL), CC64R_FIELD_BOTTOM_ENCODED_MASK64 = (uint64_t)CC64R_FIELD_BOTTOM_ENCODED_MASK_NOT_SHIFTED << CC64R_FIELD_BOTTOM_ENCODED_START, CC64R_FIELD_BOTTOM_ENCODED_MAX_VALUE = CC64R_FIELD_BOTTOM_ENCODED_MASK_NOT_SHIFTED,



    CC64R_FIELD_EXP_ZERO_TOP_START = (42 - 32), CC64R_FIELD_EXP_ZERO_TOP_LAST = (49 - 32), CC64R_FIELD_EXP_ZERO_TOP_SIZE = CC64R_FIELD_EXP_ZERO_TOP_LAST - CC64R_FIELD_EXP_ZERO_TOP_START + 1, CC64R_FIELD_EXP_ZERO_TOP_MASK_NOT_SHIFTED = ((1UL << (CC64R_FIELD_EXP_ZERO_TOP_SIZE)) - 1UL), CC64R_FIELD_EXP_ZERO_TOP_MASK64 = (uint64_t)CC64R_FIELD_EXP_ZERO_TOP_MASK_NOT_SHIFTED << CC64R_FIELD_EXP_ZERO_TOP_START, CC64R_FIELD_EXP_ZERO_TOP_MAX_VALUE = CC64R_FIELD_EXP_ZERO_TOP_MASK_NOT_SHIFTED,
    CC64R_FIELD_EXP_ZERO_BOTTOM_START = (32 - 32), CC64R_FIELD_EXP_ZERO_BOTTOM_LAST = (41 - 32), CC64R_FIELD_EXP_ZERO_BOTTOM_SIZE = CC64R_FIELD_EXP_ZERO_BOTTOM_LAST - CC64R_FIELD_EXP_ZERO_BOTTOM_START + 1, CC64R_FIELD_EXP_ZERO_BOTTOM_MASK_NOT_SHIFTED = ((1UL << (CC64R_FIELD_EXP_ZERO_BOTTOM_SIZE)) - 1UL), CC64R_FIELD_EXP_ZERO_BOTTOM_MASK64 = (uint64_t)CC64R_FIELD_EXP_ZERO_BOTTOM_MASK_NOT_SHIFTED << CC64R_FIELD_EXP_ZERO_BOTTOM_START, CC64R_FIELD_EXP_ZERO_BOTTOM_MAX_VALUE = CC64R_FIELD_EXP_ZERO_BOTTOM_MASK_NOT_SHIFTED,

    CC64R_FIELD_EXP_NONZERO_TOP_START = (44 - 32), CC64R_FIELD_EXP_NONZERO_TOP_LAST = (49 - 32), CC64R_FIELD_EXP_NONZERO_TOP_SIZE = CC64R_FIELD_EXP_NONZERO_TOP_LAST - CC64R_FIELD_EXP_NONZERO_TOP_START + 1, CC64R_FIELD_EXP_NONZERO_TOP_MASK_NOT_SHIFTED = ((1UL << (CC64R_FIELD_EXP_NONZERO_TOP_SIZE)) - 1UL), CC64R_FIELD_EXP_NONZERO_TOP_MASK64 = (uint64_t)CC64R_FIELD_EXP_NONZERO_TOP_MASK_NOT_SHIFTED << CC64R_FIELD_EXP_NONZERO_TOP_START, CC64R_FIELD_EXP_NONZERO_TOP_MAX_VALUE = CC64R_FIELD_EXP_NONZERO_TOP_MASK_NOT_SHIFTED,
    CC64R_FIELD_EXPONENT_HIGH_PART_START = (42 - 32), CC64R_FIELD_EXPONENT_HIGH_PART_LAST = (43 - 32), CC64R_FIELD_EXPONENT_HIGH_PART_SIZE = CC64R_FIELD_EXPONENT_HIGH_PART_LAST - CC64R_FIELD_EXPONENT_HIGH_PART_START + 1, CC64R_FIELD_EXPONENT_HIGH_PART_MASK_NOT_SHIFTED = ((1UL << (CC64R_FIELD_EXPONENT_HIGH_PART_SIZE)) - 1UL), CC64R_FIELD_EXPONENT_HIGH_PART_MASK64 = (uint64_t)CC64R_FIELD_EXPONENT_HIGH_PART_MASK_NOT_SHIFTED << CC64R_FIELD_EXPONENT_HIGH_PART_START, CC64R_FIELD_EXPONENT_HIGH_PART_MAX_VALUE = CC64R_FIELD_EXPONENT_HIGH_PART_MASK_NOT_SHIFTED,
    CC64R_FIELD_EXP_NONZERO_BOTTOM_START = (34 - 32), CC64R_FIELD_EXP_NONZERO_BOTTOM_LAST = (41 - 32), CC64R_FIELD_EXP_NONZERO_BOTTOM_SIZE = CC64R_FIELD_EXP_NONZERO_BOTTOM_LAST - CC64R_FIELD_EXP_NONZERO_BOTTOM_START + 1, CC64R_FIELD_EXP_NONZERO_BOTTOM_MASK_NOT_SHIFTED = ((1UL << (CC64R_FIELD_EXP_NONZERO_BOTTOM_SIZE)) - 1UL), CC64R_FIELD_EXP_NONZERO_BOTTOM_MASK64 = (uint64_t)CC64R_FIELD_EXP_NONZERO_BOTTOM_MASK_NOT_SHIFTED << CC64R_FIELD_EXP_NONZERO_BOTTOM_START, CC64R_FIELD_EXP_NONZERO_BOTTOM_MAX_VALUE = CC64R_FIELD_EXP_NONZERO_BOTTOM_MASK_NOT_SHIFTED,
    CC64R_FIELD_EXPONENT_LOW_PART_START = (32 - 32), CC64R_FIELD_EXPONENT_LOW_PART_LAST = (33 - 32), CC64R_FIELD_EXPONENT_LOW_PART_SIZE = CC64R_FIELD_EXPONENT_LOW_PART_LAST - CC64R_FIELD_EXPONENT_LOW_PART_START + 1, CC64R_FIELD_EXPONENT_LOW_PART_MASK_NOT_SHIFTED = ((1UL << (CC64R_FIELD_EXPONENT_LOW_PART_SIZE)) - 1UL), CC64R_FIELD_EXPONENT_LOW_PART_MASK64 = (uint64_t)CC64R_FIELD_EXPONENT_LOW_PART_MASK_NOT_SHIFTED << CC64R_FIELD_EXPONENT_LOW_PART_START, CC64R_FIELD_EXPONENT_LOW_PART_MAX_VALUE = CC64R_FIELD_EXPONENT_LOW_PART_MASK_NOT_SHIFTED,
};
#pragma GCC diagnostic pop
# 123 "./cheri_compressed_cap_64r.h"
_Static_assert(((0x3)) == (CC64R_FIELD_SDP_MAX_VALUE), "");
# 142 "./cheri_compressed_cap_64r.h"
enum CC64R_OTypes {
    CC64R_MAX_REPRESENTABLE_OTYPE = ((1u << CC64R_FIELD_OTYPE_SIZE) - 1u),
    CC64R_OTYPE_UNSEALED = ((0u)), CC64R_OTYPE_UNSEALED_SIGNED = ((0u)),
    CC64R_OTYPE_SENTRY = ((1u)), CC64R_OTYPE_SENTRY_SIGNED = ((1u)),
    CC64R_MIN_RESERVED_OTYPE = CC64R_OTYPE_UNSEALED,
    CC64R_MAX_RESERVED_OTYPE = CC64R_OTYPE_SENTRY,
};





_Static_assert((10) == (CC64R_FIELD_EXP_ZERO_BOTTOM_SIZE), "");
# 171 "./cheri_compressed_cap_64r.h"
# 1 "./cheri_compressed_cap_common.h" 1
# 40 "./cheri_compressed_cap_common.h"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
enum {


    CC64R_RESET_EXP = 24,
    CC64R_RESET_T = 1u << (32 - CC64R_RESET_EXP - CC64R_FIELD_EXPONENT_HIGH_PART_SIZE),







    CC64R_NULL_EXP = CC64R_RESET_EXP,
    CC64R_NULL_T = CC64R_RESET_T,

    CC64R_RESET_EBT = ((uint64_t)((!(1)) & CC64R_FIELD_EXPONENT_FORMAT_MAX_VALUE) << CC64R_FIELD_EXPONENT_FORMAT_START) | ((uint64_t)(((24 - (CC64R_RESET_EXP)) >> CC64R_FIELD_EXPONENT_LOW_PART_SIZE) & CC64R_FIELD_EXPONENT_HIGH_PART_MAX_VALUE) << CC64R_FIELD_EXPONENT_HIGH_PART_START) | ((uint64_t)((24 - (CC64R_RESET_EXP)) & CC64R_FIELD_EXPONENT_LOW_PART_MAX_VALUE) << CC64R_FIELD_EXPONENT_LOW_PART_START) | ((uint64_t)((((24 - (CC64R_RESET_EXP)) >> 4)) & CC64R_FIELD_LEN_MSB_MAX_VALUE) << CC64R_FIELD_LEN_MSB_START) |
                       ((uint64_t)((CC64R_RESET_T) & CC64R_FIELD_EXP_NONZERO_TOP_MAX_VALUE) << CC64R_FIELD_EXP_NONZERO_TOP_START) | ((uint64_t)((0) & CC64R_FIELD_EXP_NONZERO_BOTTOM_MAX_VALUE) << CC64R_FIELD_EXP_NONZERO_BOTTOM_START),
    CC64R_RESET_PESBT = CC64R_RESET_EBT | (((uint64_t)(((0x3)) & CC64R_FIELD_SDP_MAX_VALUE) << CC64R_FIELD_SDP_START) | ((uint64_t)(((((uint8_t)(1 << 3)) | 1)) & CC64R_FIELD_AP_M_MAX_VALUE) << CC64R_FIELD_AP_M_START) | ((uint64_t)((((1UL << (1)) - 1UL)) & CC64R_FIELD_LEVEL_MAX_VALUE) << CC64R_FIELD_LEVEL_START)) |
                         ((uint64_t)((CC64R_OTYPE_UNSEALED) & CC64R_FIELD_OTYPE_MAX_VALUE) << CC64R_FIELD_OTYPE_START),
    CC64R_NULL_EBT = ((uint64_t)((!(1)) & CC64R_FIELD_EXPONENT_FORMAT_MAX_VALUE) << CC64R_FIELD_EXPONENT_FORMAT_START) | ((uint64_t)(((24 - (CC64R_NULL_EXP)) >> CC64R_FIELD_EXPONENT_LOW_PART_SIZE) & CC64R_FIELD_EXPONENT_HIGH_PART_MAX_VALUE) << CC64R_FIELD_EXPONENT_HIGH_PART_START) | ((uint64_t)((24 - (CC64R_NULL_EXP)) & CC64R_FIELD_EXPONENT_LOW_PART_MAX_VALUE) << CC64R_FIELD_EXPONENT_LOW_PART_START) | ((uint64_t)((((24 - (CC64R_NULL_EXP)) >> 4)) & CC64R_FIELD_LEN_MSB_MAX_VALUE) << CC64R_FIELD_LEN_MSB_START) |
                      ((uint64_t)((CC64R_NULL_T) & CC64R_FIELD_EXP_NONZERO_TOP_MAX_VALUE) << CC64R_FIELD_EXP_NONZERO_TOP_START) | ((uint64_t)((0) & CC64R_FIELD_EXP_NONZERO_BOTTOM_MAX_VALUE) << CC64R_FIELD_EXP_NONZERO_BOTTOM_START),
    CC64R_NULL_PESBT = CC64R_NULL_EBT | ((uint64_t)((CC64R_OTYPE_UNSEALED) & CC64R_FIELD_OTYPE_MAX_VALUE) << CC64R_FIELD_OTYPE_START),

    CC64R_MEM_XOR_MASK = CC64R_NULL_PESBT,
    CC64R_NULL_XOR_MASK __attribute__((deprecated("Use _MEM_XOR_MASK instead"))) = CC64R_MEM_XOR_MASK,
    CC64R_MAX_LEVEL_VALUE = ((1UL << (1)) - 1UL),
};
#pragma GCC diagnostic pop
# 93 "./cheri_compressed_cap_common.h"
_Static_assert((CC64R_FIELD_INTERNAL_EXPONENT_SIZE + CC64R_FIELD_EXP_ZERO_TOP_SIZE + CC64R_FIELD_LEN_MSB_SIZE + CC64R_FIELD_EXP_ZERO_BOTTOM_SIZE) == (CC64R_FIELD_EBT_SIZE), "");


_Static_assert((CC64R_FIELD_INTERNAL_EXPONENT_SIZE + CC64R_FIELD_LEN_MSB_SIZE + CC64R_FIELD_TOP_ENCODED_SIZE + CC64R_FIELD_BOTTOM_ENCODED_SIZE) == (CC64R_FIELD_EBT_SIZE), "");


_Static_assert((CC64R_FIELD_INTERNAL_EXPONENT_SIZE + CC64R_FIELD_LEN_MSB_SIZE + CC64R_FIELD_EXP_NONZERO_TOP_SIZE + CC64R_FIELD_EXP_NONZERO_BOTTOM_SIZE + CC64R_FIELD_EXPONENT_HIGH_PART_SIZE + CC64R_FIELD_EXPONENT_LOW_PART_SIZE) == (CC64R_FIELD_EBT_SIZE), "");




_Static_assert((CC64R_FIELD_EBT_START) == (0), "");

_Static_assert(CC64R_MIN_RESERVED_OTYPE >= 0, "MIN_RESERVED_OTYPE is signed?");
_Static_assert(CC64R_MIN_RESERVED_OTYPE < CC64R_MAX_RESERVED_OTYPE, "MIN_RESERVED_OTYPE greater than MAX_RESERVED_OTYPE?");

_Static_assert(CC64R_MIN_RESERVED_OTYPE <= CC64R_MAX_REPRESENTABLE_OTYPE, "MIN_RESERVED_OTYPE out of range?");
_Static_assert(CC64R_MAX_RESERVED_OTYPE <= CC64R_MAX_REPRESENTABLE_OTYPE, "MAX_RESERVED_OTYPE out of range?");


typedef struct cc64r_cap cc64r_cap_t;

extern uint8_t cc64r_get_flags(const cc64r_cap_t* cap);
extern uint32_t cc64r_get_otype(const cc64r_cap_t* cap);
extern uint32_t cc64r_get_level(const cc64r_cap_t* cap);
extern cc64r_addr_t cc64r_get_perms(const cc64r_cap_t* cap);
extern cc64r_addr_t cc64r_get_reserved(const cc64r_cap_t* cap);
extern _Bool cc64r_reserved_bits_valid(const cc64r_cap_t* cap) { return cc64r_get_reserved(cap) == 0; }
extern cc64r_addr_t cc64r_get_uperms(const cc64r_cap_t* cap);

extern cc64r_addr_t cc64r_get_all_permissions(const cc64r_cap_t* cap);
extern _Bool cc64r_has_permissions(const cc64r_cap_t* cap, cc64r_addr_t permissions) {
    return (cc64r_get_all_permissions(cap) & permissions) == permissions;
}
extern _Bool cc64r_set_permissions(cc64r_cap_t* cap, cc64r_addr_t permissions);

extern CC64R_Mode cc64r_get_execution_mode(const cc64r_cap_t* cap);
extern _Bool cc64r_set_execution_mode(cc64r_cap_t* cap, CC64R_Mode new_mode);



struct cc64r_cap {







    cc64r_addr_t _cr_cursor;
    cc64r_addr_t cr_pesbt;

    cc64r_length_t _cr_top;
    cc64r_addr_t cr_base;
    uint8_t cr_tag;
    uint8_t cr_bounds_valid;

    uint8_t cr_lvbits;

    uint8_t cr_exp;
    uint8_t cr_extra;
# 179 "./cheri_compressed_cap_common.h"
};

extern _Bool cc64r_exactly_equal(const cc64r_cap_t* a, const cc64r_cap_t* b) {
    return a->cr_tag == b->cr_tag && a->_cr_cursor == b->_cr_cursor && a->cr_pesbt == b->cr_pesbt;
}

extern uint8_t cc64r_get_lvbits(__attribute__((unused)) const cc64r_cap_t* cap) {

    return cap->cr_lvbits;



}

extern _Bool cc64r_raw_equal(const cc64r_cap_t* a, const cc64r_cap_t* b) {
    return a->_cr_cursor == b->_cr_cursor && a->cr_pesbt == b->cr_pesbt && a->_cr_top == b->_cr_top &&
           a->cr_base == b->cr_base && a->cr_tag == b->cr_tag && a->cr_bounds_valid == b->cr_bounds_valid &&
           cc64r_get_lvbits(a) == cc64r_get_lvbits(b) && a->cr_exp == b->cr_exp && a->cr_extra == b->cr_extra;
}


extern uint32_t cc64r_idx_MSNZ(uint64_t x) {
# 218 "./cheri_compressed_cap_common.h"
    ((void) sizeof ((x != 0) ? 1 : 0), __extension__ ({ if (x != 0) ; else __assert_fail ("x != 0", "./cheri_compressed_cap_common.h", 218, __extension__ __PRETTY_FUNCTION__); }));
    uint32_t r = 63u - (uint32_t)__builtin_clzll(x);

    return r;
}





extern uint32_t cc64r_compute_e(cc64r_addr_t rlength, uint32_t bwidth) {
    if (rlength < (1u << (bwidth - 1)))
        return 0;

    return (cc64r_idx_MSNZ(rlength) - (bwidth - 2));
}

extern uint32_t cc64r_get_exponent(cc64r_length_t length) {
    const uint32_t bwidth = 10;
    if (length > (4294967295U)) {
        return 33 - (bwidth - 1);
    } else {
        return cc64r_compute_e((cc64r_addr_t)length, bwidth);
    }
}

extern uint64_t cc64r_getbits(uint64_t src, uint32_t start, uint32_t size) {
    return ((src >> start) & ((1UL << size) - 1UL));
}


extern uint64_t cc64r_truncate_addr(cc64r_addr_t value, size_t n) { return value & (((cc64r_addr_t)1 << n) - 1); }
extern uint64_t cc64r_truncate64(uint64_t value, size_t n) { return value & ((1UL << n) - 1); }







extern uint64_t cc64r_truncateLSB_10(uint64_t value, size_t n) { _Static_assert(10 <= 64, ""); return value >> (10 - n); }
extern uint64_t cc64r_truncateLSB_32(uint64_t value, size_t n) { _Static_assert(32 <= 64, ""); return value >> (32 - n); }
extern uint64_t cc64r_truncateLSB_64(uint64_t value, size_t n) { _Static_assert(64 <= 64, ""); return value >> (64 - n); }




struct cc64r_bounds_bits {
    uint16_t B;
    uint16_t T;
    uint8_t E;
    _Bool IE;
};
# 283 "./cheri_compressed_cap_common.h"
extern cc64r_addr_t cc64r_cap_pesbt_extract_otype(cc64r_addr_t pesbt) { return cc64r_getbits((pesbt), CC64R_FIELD_OTYPE_START, CC64R_FIELD_OTYPE_SIZE); } extern cc64r_addr_t cc64r_cap_pesbt_encode_otype(uint32_t value) { return ((uint64_t)((value) & CC64R_FIELD_OTYPE_MAX_VALUE) << CC64R_FIELD_OTYPE_START); } extern cc64r_addr_t cc64r_cap_pesbt_deposit_otype(cc64r_addr_t pesbt, uint32_t value) { return __extension__({ ((void) sizeof ((value <= CC64R_FIELD_OTYPE_MAX_VALUE) ? 1 : 0), __extension__ ({ if (value <= CC64R_FIELD_OTYPE_MAX_VALUE) ; else __assert_fail ("value <= CC64R_FIELD_OTYPE_MAX_VALUE", "./cheri_compressed_cap_common.h", 283, __extension__ __PRETTY_FUNCTION__); })); ((pesbt) & ~CC64R_FIELD_OTYPE_MASK64) | ((uint64_t)((value) & CC64R_FIELD_OTYPE_MAX_VALUE) << CC64R_FIELD_OTYPE_START); }); } extern uint32_t cc64r_get_otype(const cc64r_cap_t* cap) { return cc64r_cap_pesbt_extract_otype(cap->cr_pesbt); } extern void cc64r_update_otype(cc64r_cap_t * cap, cc64r_addr_t value) { cap->cr_pesbt = cc64r_cap_pesbt_deposit_otype(cap->cr_pesbt, value); }
extern cc64r_addr_t cc64r_cap_pesbt_extract_flags(cc64r_addr_t pesbt) { return cc64r_getbits((pesbt), CC64R_FIELD_FLAGS_START, CC64R_FIELD_FLAGS_SIZE); } extern cc64r_addr_t cc64r_cap_pesbt_encode_flags(uint8_t value) { return ((uint64_t)((value) & CC64R_FIELD_FLAGS_MAX_VALUE) << CC64R_FIELD_FLAGS_START); } extern cc64r_addr_t cc64r_cap_pesbt_deposit_flags(cc64r_addr_t pesbt, uint8_t value) { return __extension__({ ((void) sizeof ((value <= CC64R_FIELD_FLAGS_MAX_VALUE) ? 1 : 0), __extension__ ({ if (value <= CC64R_FIELD_FLAGS_MAX_VALUE) ; else __assert_fail ("value <= CC64R_FIELD_FLAGS_MAX_VALUE", "./cheri_compressed_cap_common.h", 284, __extension__ __PRETTY_FUNCTION__); })); ((pesbt) & ~CC64R_FIELD_FLAGS_MASK64) | ((uint64_t)((value) & CC64R_FIELD_FLAGS_MAX_VALUE) << CC64R_FIELD_FLAGS_START); }); } extern uint8_t cc64r_get_flags(const cc64r_cap_t* cap) { return cc64r_cap_pesbt_extract_flags(cap->cr_pesbt); } extern void cc64r_update_flags(cc64r_cap_t * cap, cc64r_addr_t value) { cap->cr_pesbt = cc64r_cap_pesbt_deposit_flags(cap->cr_pesbt, value); }


extern _Bool cc64r_is_cap_sealed(const cc64r_cap_t* cp) { return cc64r_get_otype(cp) != CC64R_OTYPE_UNSEALED; }
# 307 "./cheri_compressed_cap_common.h"
extern cc64r_cap_t cc64r_make_null_derived_cap(cc64r_addr_t addr);
__attribute__((deprecated("Use get_all_permissions"))) extern cc64r_addr_t cc64r_get_perms(const cc64r_cap_t* cap) {

    _Static_assert((6) != 0, "Architectural perms expected to start at offset zero");

    cc64r_cap_t null_cap = cc64r_make_null_derived_cap(0);
    cc64r_addr_t reserved_one_bits = cc64r_get_all_permissions(&null_cap);
    cc64r_addr_t all_perms_w_reserved = cc64r_get_all_permissions(cap);
    return (all_perms_w_reserved & ~reserved_one_bits) & ~((0x3) << (6));
}
__attribute__((deprecated("Use get_all_permissions"))) extern cc64r_addr_t cc64r_get_uperms(const cc64r_cap_t* cap) {
    return (cc64r_get_all_permissions(cap) & ((0x3) << (6))) >> (6);
}
__attribute__((deprecated("Use set_permissions"))) extern void cc64r_update_perms(cc64r_cap_t* cap, cc64r_addr_t value) {
    ((void) sizeof ((((value & (0x7003f)) == value) && "invalid permission value") ? 1 : 0), __extension__ ({ if (((value & (0x7003f)) == value) && "invalid permission value") ; else __assert_fail ("((value & (0x7003f)) == value) && \"invalid permission value\"", "./cheri_compressed_cap_common.h", 321, __extension__ __PRETTY_FUNCTION__); }));
    cc64r_addr_t current_swperms = (cc64r_get_all_permissions(cap) & ((0x3) << (6)));
    cc64r_set_permissions(cap, (value & ~((0x3) << (6))) | current_swperms);
}
__attribute__((deprecated("Use set_permissions"))) extern void cc64r_update_uperms(cc64r_cap_t* cap, cc64r_addr_t value) {
    ((void) sizeof ((((value & (0x3)) == value) && "invalid permission value") ? 1 : 0), __extension__ ({ if (((value & (0x3)) == value) && "invalid permission value") ; else __assert_fail ("((value & (0x3)) == value) && \"invalid permission value\"", "./cheri_compressed_cap_common.h", 326, __extension__ __PRETTY_FUNCTION__); }));
    cc64r_addr_t old_arch_perms = cc64r_get_all_permissions(cap) & ~((0x3) << (6));
    cc64r_set_permissions(cap, ((value << (6)) & ((0x3) << (6))) | old_arch_perms);
}


extern struct cc64r_bounds_bits cc64r_extract_bounds_bits(cc64r_addr_t pesbt) {
    _Static_assert(10 == CC64R_FIELD_EXP_ZERO_BOTTOM_SIZE, "Wrong bot width?");
    uint32_t BWidth = 10;
    uint32_t BMask = (1u << BWidth) - 1;
    uint32_t TMask = BMask >> 2;
    struct cc64r_bounds_bits result;
    _Static_assert(sizeof(result.B) * 8 >= 10, "B field too small");
    _Static_assert(sizeof(result.T) * 8 >= 10, "T field too small");
    _Static_assert(sizeof(result.E) * 8 >= CC64R_FIELD_EXPONENT_LOW_PART_SIZE + CC64R_FIELD_EXPONENT_HIGH_PART_SIZE, "E field too small");


    result.IE = (_Bool)(!cc64r_getbits((pesbt), CC64R_FIELD_EXPONENT_FORMAT_START, CC64R_FIELD_EXPONENT_FORMAT_SIZE));
    uint8_t L_msb;
    if (result.IE) {
        result.E = (uint8_t)(24 - ((cc64r_getbits((pesbt), CC64R_FIELD_LEN_MSB_START, CC64R_FIELD_LEN_MSB_SIZE) << 4) | (cc64r_getbits((pesbt), CC64R_FIELD_EXPONENT_LOW_PART_START, CC64R_FIELD_EXPONENT_LOW_PART_SIZE) | (cc64r_getbits((pesbt), CC64R_FIELD_EXPONENT_HIGH_PART_START, CC64R_FIELD_EXPONENT_HIGH_PART_SIZE) << CC64R_FIELD_EXPONENT_LOW_PART_SIZE))));



        result.B = (uint16_t)cc64r_getbits((pesbt), CC64R_FIELD_EXP_NONZERO_BOTTOM_START, CC64R_FIELD_EXP_NONZERO_BOTTOM_SIZE) << CC64R_FIELD_EXPONENT_LOW_PART_SIZE;
        result.T = (uint16_t)cc64r_getbits((pesbt), CC64R_FIELD_EXP_NONZERO_TOP_START, CC64R_FIELD_EXP_NONZERO_TOP_SIZE) << CC64R_FIELD_EXPONENT_HIGH_PART_SIZE;
        L_msb = 1;
    } else {
        result.E = 0;

        L_msb = cc64r_getbits((pesbt), CC64R_FIELD_LEN_MSB_START, CC64R_FIELD_LEN_MSB_SIZE);



        result.B = (uint16_t)cc64r_getbits((pesbt), CC64R_FIELD_EXP_ZERO_BOTTOM_START, CC64R_FIELD_EXP_ZERO_BOTTOM_SIZE);
        result.T = (uint16_t)cc64r_getbits((pesbt), CC64R_FIELD_EXP_ZERO_TOP_START, CC64R_FIELD_EXP_ZERO_TOP_SIZE);
    }






    uint8_t L_carry = result.T < (result.B & TMask) ? 1 : 0;
    uint64_t BTop2 = cc64r_getbits(result.B, 10 - 2, 2);
    uint8_t T_infer = (BTop2 + L_carry + L_msb) & 0x3;
    result.T |= ((uint16_t)T_infer) << (BWidth - 2);
    return result;
}


extern _Bool cc64r_bounds_bits_valid(struct cc64r_bounds_bits bounds) {

    cc64r_addr_t Bmsb = cc64r_getbits(bounds.B, 10 - 1, 1);
    cc64r_addr_t Bmsb2 = cc64r_getbits(bounds.B, 10 - 2, 2);
    cc64r_addr_t Tmsb = cc64r_getbits(bounds.T, 10 - 1, 1);
    if (bounds.E >= 24) {
        return Tmsb == 0 && Bmsb2 == 0;
    } else if (bounds.E == 24 - 1) {
        return Bmsb == 0;
    } else {
        return 1;
    }
}



extern cc64r_addr_t cc64r_cap_bounds_address(cc64r_addr_t addr) {

    cc64r_addr_t cursor = addr & 0xFFFFFFFF;

    if (cursor & ((0xFFFFFFFF >> 1) + 1))
        cursor |= ~0xFFFFFFFF;
    return cursor;
}


extern _Bool cc64r_compute_base_top_special_cases(struct cc64r_bounds_bits bounds, cc64r_addr_t* base_out,
                                                         cc64r_length_t* top_out, _Bool* valid);

extern _Bool cc64r_compute_base_top(struct cc64r_bounds_bits bounds, cc64r_addr_t cursor, cc64r_addr_t* base_out,
                                           cc64r_length_t* top_out) {

    _Bool valid = 1;
    if (cc64r_compute_base_top_special_cases(bounds, base_out, top_out, &valid))
        return valid;

    cursor = cc64r_cap_bounds_address(cursor);
# 429 "./cheri_compressed_cap_common.h"
    ((void) sizeof ((bounds.E <= 24 && "malformed caps should already be handled") ? 1 : 0), __extension__ ({ if (bounds.E <= 24 && "malformed caps should already be handled") ; else __assert_fail ("bounds.E <= 24 && \"malformed caps should already be handled\"", "./cheri_compressed_cap_common.h", 429, __extension__ __PRETTY_FUNCTION__); }));
    uint8_t E = bounds.E;
    unsigned a_mid = (unsigned)cc64r_truncate64(cursor >> E, 10);
    unsigned correction_B = bounds.B;
    unsigned correction_T = bounds.T;
    unsigned R = cc64r_truncate64((unsigned)bounds.B - (1 << (10 - 2)), 10);





    int aHi = a_mid < R ? 1 : 0;
    int bHi = correction_B < R ? 1 : 0;
    int tHi = correction_T < R ? 1 : 0;




    int correction_base = bHi - aHi;
    int correction_top = tHi - aHi;

    const unsigned a_top_shift = E + 10;

    cc64r_addr_t a_top = a_top_shift >= 32 ? 0 : cursor >> a_top_shift;


    cc64r_length_t base = (cc64r_addr_t)((int64_t)a_top + correction_base);
    base <<= 10;
    base |= bounds.B;
    base <<= E;
    base &= ((cc64r_length_t)1 << 33) - 1;
    ((void) sizeof (((cc64r_addr_t)(base >> 32) <= 1) ? 1 : 0), __extension__ ({ if ((cc64r_addr_t)(base >> 32) <= 1) ; else __assert_fail ("(cc64r_addr_t)(base >> 32) <= 1", "./cheri_compressed_cap_common.h", 460, __extension__ __PRETTY_FUNCTION__); }));

    cc64r_length_t top = (cc64r_addr_t)((int64_t)a_top + correction_top);
    top <<= 10;
    top |= bounds.T;
    top <<= E;
    top &= ((cc64r_length_t)1 << 33) - 1;
    ((void) sizeof (((cc64r_addr_t)(top >> 32) <= 1) ? 1 : 0), __extension__ ({ if ((cc64r_addr_t)(top >> 32) <= 1) ; else __assert_fail ("(cc64r_addr_t)(top >> 32) <= 1", "./cheri_compressed_cap_common.h", 467, __extension__ __PRETTY_FUNCTION__); }));







    unsigned base2 = cc64r_truncate64(base >> (32 - 1), 1);

    unsigned top2 = cc64r_truncate64(top >> (32 - 1), 2);



    if (E < (24 - 1) && (top2 - base2) > 1) {
        top = top ^ ((cc64r_length_t)1 << 32);
    }

    ((void) sizeof (((cc64r_addr_t)(top >> 32) <= 1) ? 1 : 0), __extension__ ({ if ((cc64r_addr_t)(top >> 32) <= 1) ; else __assert_fail ("(cc64r_addr_t)(top >> 32) <= 1", "./cheri_compressed_cap_common.h", 485, __extension__ __PRETTY_FUNCTION__); }));

    if (cc64r_bounds_bits_valid(bounds)) {


        ((void) sizeof (((cc64r_addr_t)base <= top) ? 1 : 0), __extension__ ({ if ((cc64r_addr_t)base <= top) ; else __assert_fail ("(cc64r_addr_t)base <= top", "./cheri_compressed_cap_common.h", 490, __extension__ __PRETTY_FUNCTION__); }));
    } else {

    }
    *base_out = (cc64r_addr_t)base;
    *top_out = top;

    return 1;
}



extern void cc64r_unsafe_decompress_raw(cc64r_addr_t pesbt, cc64r_addr_t cursor, _Bool tag,
                                                __attribute__((unused)) uint8_t lvbits, cc64r_cap_t* cdp) {
    memset(cdp, 0, sizeof(*cdp));
    cdp->cr_tag = tag;
    cdp->_cr_cursor = cursor;
    cdp->cr_pesbt = pesbt;

    cdp->cr_lvbits = lvbits;


    struct cc64r_bounds_bits bounds = cc64r_extract_bounds_bits(pesbt);
    _Bool valid = cc64r_compute_base_top(bounds, cursor, &cdp->cr_base, &cdp->_cr_top);
    cdp->cr_bounds_valid = valid;
    cdp->cr_exp = bounds.E;
}

extern void cc64r_decompress_raw_ext(cc64r_addr_t pesbt, cc64r_addr_t cursor, _Bool tag, uint8_t lvbits,
                                             cc64r_cap_t* cdp) {
    cc64r_unsafe_decompress_raw(pesbt, cursor, tag, lvbits, cdp);
    if (tag) {
        ((void) sizeof ((cdp->cr_base <= (4294967295U)) ? 1 : 0), __extension__ ({ if (cdp->cr_base <= (4294967295U)) ; else __assert_fail ("cdp->cr_base <= (4294967295U)", "./cheri_compressed_cap_common.h", 522, __extension__ __PRETTY_FUNCTION__); }));


        ((void) sizeof ((cdp->_cr_top <= ((cc64r_length_t)1u << 32)) ? 1 : 0), __extension__ ({ if (cdp->_cr_top <= ((cc64r_length_t)1u << 32)) ; else __assert_fail ("cdp->_cr_top <= ((cc64r_length_t)1u << 32)", "./cheri_compressed_cap_common.h", 525, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((cdp->cr_base <= cdp->_cr_top) ? 1 : 0), __extension__ ({ if (cdp->cr_base <= cdp->_cr_top) ; else __assert_fail ("cdp->cr_base <= cdp->_cr_top", "./cheri_compressed_cap_common.h", 526, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((cdp->cr_bounds_valid) ? 1 : 0), __extension__ ({ if (cdp->cr_bounds_valid) ; else __assert_fail ("cdp->cr_bounds_valid", "./cheri_compressed_cap_common.h", 527, __extension__ __PRETTY_FUNCTION__); }));

        ((void) sizeof ((cc64r_reserved_bits_valid(cdp)) ? 1 : 0), __extension__ ({ if (cc64r_reserved_bits_valid(cdp)) ; else __assert_fail ("cc64r_reserved_bits_valid(cdp)", "./cheri_compressed_cap_common.h", 529, __extension__ __PRETTY_FUNCTION__); }));
    }
}

extern void cc64r_decompress_raw(cc64r_addr_t pesbt, cc64r_addr_t cursor, _Bool tag, cc64r_cap_t* cdp) {
    cc64r_decompress_raw_ext(pesbt, cursor, tag, 1, cdp);
}




extern void cc64r_decompress_mem(uint64_t pesbt, uint64_t cursor, _Bool tag, cc64r_cap_t* cdp) {
    cc64r_decompress_raw_ext(pesbt ^ CC64R_MEM_XOR_MASK, cursor, tag, 1, cdp);
}


extern _Bool cc64r_pesbt_is_correct(const cc64r_cap_t* csp) {
    cc64r_cap_t tmp;

    cc64r_unsafe_decompress_raw(csp->cr_pesbt, csp->_cr_cursor, csp->cr_tag, cc64r_get_lvbits(csp), &tmp);
    tmp.cr_extra = csp->cr_extra;
    if (!cc64r_raw_equal(&tmp, csp)) {
        return 0;
    }
    return 1;
}


extern void cc64r_update_ebt(cc64r_cap_t* csp, cc64r_addr_t new_ebt) {
    csp->cr_pesbt = (csp->cr_pesbt & ~CC64R_FIELD_EBT_MASK64) | new_ebt;
    csp->cr_exp = cc64r_extract_bounds_bits(new_ebt).E;
}






extern cc64r_addr_t cc64r_compress_raw(const cc64r_cap_t* csp) {


    ((void) sizeof (((!csp->cr_tag || (csp->cr_bounds_valid && cc64r_reserved_bits_valid(csp))) && "Malformed bounds or unknown reserved bits in tagged capability") ? 1 : 0), __extension__ ({ if ((!csp->cr_tag || (csp->cr_bounds_valid && cc64r_reserved_bits_valid(csp))) && "Malformed bounds or unknown reserved bits in tagged capability") ; else __assert_fail ("(!csp->cr_tag || (csp->cr_bounds_valid && cc64r_reserved_bits_valid(csp))) && \"Malformed bounds or unknown reserved bits in tagged capability\"", "./cheri_compressed_cap_common.h", 571, __extension__ __PRETTY_FUNCTION__); }));


    ((void) sizeof ((cc64r_pesbt_is_correct(csp) && "capability bounds were modified without updating pesbt") ? 1 : 0), __extension__ ({ if (cc64r_pesbt_is_correct(csp) && "capability bounds were modified without updating pesbt") ; else __assert_fail ("cc64r_pesbt_is_correct(csp) && \"capability bounds were modified without updating pesbt\"", "./cheri_compressed_cap_common.h", 573, __extension__ __PRETTY_FUNCTION__); }));
    return csp->cr_pesbt;
}

extern cc64r_addr_t cc64r_compress_mem(const cc64r_cap_t* csp) {
    return cc64r_compress_raw(csp) ^ CC64R_MEM_XOR_MASK;
}

static _Bool cc64r__fast_is_representable_new_addr(const cc64r_cap_t* cap, cc64r_addr_t new_addr);


extern _Bool cc64r_is_representable_cap_exact(const cc64r_cap_t* cap) {
    cc64r_addr_t pesbt = cc64r_compress_raw(cap);
    cc64r_cap_t decompressed_cap;

    cc64r_unsafe_decompress_raw(pesbt, cap->_cr_cursor, cap->cr_tag, cc64r_get_lvbits(cap), &decompressed_cap);

    ((void) sizeof ((decompressed_cap._cr_cursor == cap->_cr_cursor) ? 1 : 0), __extension__ ({ if (decompressed_cap._cr_cursor == cap->_cr_cursor) ; else __assert_fail ("decompressed_cap._cr_cursor == cap->_cr_cursor", "./cheri_compressed_cap_common.h", 590, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((decompressed_cap.cr_pesbt == cap->cr_pesbt) ? 1 : 0), __extension__ ({ if (decompressed_cap.cr_pesbt == cap->cr_pesbt) ; else __assert_fail ("decompressed_cap.cr_pesbt == cap->cr_pesbt", "./cheri_compressed_cap_common.h", 591, __extension__ __PRETTY_FUNCTION__); }));

    if (decompressed_cap.cr_base != cap->cr_base || decompressed_cap._cr_top != cap->_cr_top) {
        return 0;
    }
    return 1;
}

extern uint32_t cc64r_compute_ebt(cc64r_addr_t req_base, cc64r_length_t req_top, cc64r_addr_t* alignment_mask,
                                          _Bool* exact) {
# 609 "./cheri_compressed_cap_common.h"
    ((void) sizeof ((req_base <= req_top && "Cannot invert base and top") ? 1 : 0), __extension__ ({ if (req_base <= req_top && "Cannot invert base and top") ; else __assert_fail ("req_base <= req_top && \"Cannot invert base and top\"", "./cheri_compressed_cap_common.h", 609, __extension__ __PRETTY_FUNCTION__); }));






    cc64r_length_t req_length65 = req_top - req_base;
# 625 "./cheri_compressed_cap_common.h"
    uint8_t E = (uint8_t)cc64r_get_exponent(req_length65);
    const uint64_t req_length64 = (uint64_t)req_length65;




    const _Bool InternalExponent = E != 0 || cc64r_getbits(req_length64, CC64R_FIELD_EXP_NONZERO_BOTTOM_SIZE + 1, 1);
    if (!InternalExponent) {






        uint32_t ebt_bits = ((uint64_t)((!(0)) & CC64R_FIELD_EXPONENT_FORMAT_MAX_VALUE) << CC64R_FIELD_EXPONENT_FORMAT_START) | ((uint64_t)((req_top) & CC64R_FIELD_EXP_ZERO_TOP_MAX_VALUE) << CC64R_FIELD_EXP_ZERO_TOP_START) |
                            ((uint64_t)((req_base) & CC64R_FIELD_EXP_ZERO_BOTTOM_MAX_VALUE) << CC64R_FIELD_EXP_ZERO_BOTTOM_START);
# 663 "./cheri_compressed_cap_common.h"
        _Static_assert(CC64R_FIELD_EXP_ZERO_TOP_SIZE == 8, "We only support formats that use L8");
        uint8_t len_msb = cc64r_getbits(req_length64, CC64R_FIELD_EXP_ZERO_TOP_SIZE, 1);
        ebt_bits |= ((uint64_t)((len_msb) & CC64R_FIELD_LEN_MSB_MAX_VALUE) << CC64R_FIELD_LEN_MSB_START);

        if (alignment_mask)
            *alignment_mask = (4294967295U);
        *exact = 1;
        return ebt_bits;
    }
# 680 "./cheri_compressed_cap_common.h"
    cc64r_addr_t bot_ie = cc64r_truncate64(req_base >> (E + CC64R_FIELD_EXPONENT_LOW_PART_SIZE), CC64R_FIELD_EXP_NONZERO_BOTTOM_SIZE);
    if (alignment_mask) {
        *alignment_mask = (18446744073709551615UL) << (E + CC64R_FIELD_EXPONENT_LOW_PART_SIZE);
    }
    cc64r_addr_t top_ie = cc64r_truncate64((cc64r_addr_t)(req_top >> (E + CC64R_FIELD_EXPONENT_LOW_PART_SIZE)), CC64R_FIELD_EXP_NONZERO_BOTTOM_SIZE);







    const cc64r_length_t maskLo = (((cc64r_length_t)1u) << (E + CC64R_FIELD_EXPONENT_LOW_PART_SIZE)) - 1;
    const cc64r_length_t zero65 = 0;
    _Bool lostSignificantBase = (req_base & maskLo) != zero65;
    _Bool lostSignificantTop = (req_top & maskLo) != zero65;





    if (lostSignificantTop) {
        top_ie = cc64r_truncate64(top_ie + 1, CC64R_FIELD_EXP_NONZERO_BOTTOM_SIZE);
    }
# 719 "./cheri_compressed_cap_common.h"
    const cc64r_addr_t len_ie = cc64r_truncate64(top_ie - bot_ie, CC64R_FIELD_EXP_NONZERO_BOTTOM_SIZE);
    _Bool incE = 0;
    if (cc64r_getbits(len_ie, CC64R_FIELD_EXP_NONZERO_BOTTOM_SIZE - 1, 1)) {
        incE = 1;
        lostSignificantBase = lostSignificantBase || cc64r_getbits(bot_ie, 0, 1);
        lostSignificantTop = lostSignificantTop || cc64r_getbits(top_ie, 0, 1);
        bot_ie = cc64r_truncate64(req_base >> (E + CC64R_FIELD_EXPONENT_LOW_PART_SIZE + 1), CC64R_FIELD_EXP_NONZERO_BOTTOM_SIZE);

        if (alignment_mask) {
            *alignment_mask = (18446744073709551615UL) << (E + CC64R_FIELD_EXPONENT_LOW_PART_SIZE + 1);
        }
        const _Bool incT = lostSignificantTop;
        top_ie = cc64r_truncate64((cc64r_addr_t)(req_top >> (E + CC64R_FIELD_EXPONENT_LOW_PART_SIZE + 1)), CC64R_FIELD_EXP_NONZERO_BOTTOM_SIZE);
        if (incT) {
            top_ie = cc64r_truncate64(top_ie + 1, CC64R_FIELD_EXP_NONZERO_BOTTOM_SIZE);
        }
    }
    const uint8_t newE = E + (incE ? 1 : 0);

    *exact = !lostSignificantBase && !lostSignificantTop;

    const cc64r_addr_t expBits = ((uint64_t)(((24 - (newE)) >> CC64R_FIELD_EXPONENT_LOW_PART_SIZE) & CC64R_FIELD_EXPONENT_HIGH_PART_MAX_VALUE) << CC64R_FIELD_EXPONENT_HIGH_PART_START) | ((uint64_t)((24 - (newE)) & CC64R_FIELD_EXPONENT_LOW_PART_MAX_VALUE) << CC64R_FIELD_EXPONENT_LOW_PART_START) | ((uint64_t)((((24 - (newE)) >> 4)) & CC64R_FIELD_LEN_MSB_MAX_VALUE) << CC64R_FIELD_LEN_MSB_START);
    return expBits | ((uint64_t)((!(1)) & CC64R_FIELD_EXPONENT_FORMAT_MAX_VALUE) << CC64R_FIELD_EXPONENT_FORMAT_START) | ((uint64_t)((top_ie) & CC64R_FIELD_EXP_NONZERO_TOP_MAX_VALUE) << CC64R_FIELD_EXP_NONZERO_TOP_START) |
           ((uint64_t)((bot_ie) & CC64R_FIELD_EXP_NONZERO_BOTTOM_MAX_VALUE) << CC64R_FIELD_EXP_NONZERO_BOTTOM_START);
}

extern _Bool cc64r__precise_is_representable_new_addr(const cc64r_cap_t* oldcap, cc64r_addr_t new_cursor) {

    cc64r_cap_t newcap = *oldcap;
    newcap._cr_cursor = new_cursor;
    struct cc64r_bounds_bits old_bounds_bits = cc64r_extract_bounds_bits(cc64r_compress_raw(oldcap));
    newcap.cr_bounds_valid = cc64r_compute_base_top(old_bounds_bits, new_cursor, &newcap.cr_base, &newcap._cr_top);
    return newcap.cr_base == oldcap->cr_base && newcap._cr_top == oldcap->_cr_top && newcap.cr_bounds_valid &&
           oldcap->cr_bounds_valid;
}

extern _Bool cc64r_cap_bounds_uses_value_for_exp(uint8_t exponent) {
    return exponent < (sizeof(cc64r_addr_t) * 8) - CC64R_FIELD_BOTTOM_ENCODED_SIZE;
}


extern _Bool cc64r_cap_bounds_uses_value(const cc64r_cap_t* cap) {

    ((void) sizeof ((cc64r_pesbt_is_correct(cap)) ? 1 : 0), __extension__ ({ if (cc64r_pesbt_is_correct(cap)) ; else __assert_fail ("cc64r_pesbt_is_correct(cap)", "./cheri_compressed_cap_common.h", 762, __extension__ __PRETTY_FUNCTION__); }));
    return cc64r_cap_bounds_uses_value_for_exp(cap->cr_exp);
}

extern _Bool cc64r_cap_sign_change(cc64r_addr_t addr1, cc64r_addr_t addr2) {



    (void)addr1;
    (void)addr2;
    return 0;

}

extern _Bool cc64r_cap_sign_change_causes_unrepresentability(const cc64r_cap_t* cap, cc64r_addr_t addr1,
                                                                    cc64r_addr_t addr2) {
    return cc64r_cap_sign_change(addr1, addr2) && cc64r_cap_bounds_uses_value(cap);
}

extern _Bool cc64r_is_representable_with_addr(const cc64r_cap_t* cap, cc64r_addr_t new_addr,
                                                     _Bool precise_representable_check) {
# 794 "./cheri_compressed_cap_common.h"
    cc64r_addr_t extended_cursor = cc64r_cap_bounds_address(new_addr);

    if (__builtin_expect(extended_cursor >= cap->cr_base && extended_cursor < cap->_cr_top, 1)) {
        return 1;
    }
    if (precise_representable_check) {
        return cc64r__precise_is_representable_new_addr(cap, new_addr);
    } else {
        return cc64r__fast_is_representable_new_addr(cap, new_addr);
    }
}



extern void cc64r_set_addr(cc64r_cap_t* cap, cc64r_addr_t new_addr) {
    if (cap->cr_tag && cc64r_is_cap_sealed(cap)) {
        cap->cr_tag = 0;
    }
    if (!cc64r_is_representable_with_addr(cap, new_addr, 0)) {

        cap->cr_tag = 0;
        cc64r_decompress_raw(cap->cr_pesbt, new_addr, 0, cap);
    } else {
        cap->_cr_cursor = new_addr;
    }
}

static _Bool cc64r__fast_is_representable_new_addr(const cc64r_cap_t* cap, cc64r_addr_t new_addr) {
    if (cap->_cr_top == ((cc64r_length_t)1u << 32) && cap->cr_base == 0) {
        return 1;
    }


    return cc64r__precise_is_representable_new_addr(cap, new_addr);
# 861 "./cheri_compressed_cap_common.h"
}


extern _Bool cc64r_setbounds_impl(cc64r_cap_t* cap, cc64r_length_t req_len, cc64r_addr_t* alignment_mask) {
    uint64_t req_base = cap->_cr_cursor;
    if (cc64r_is_cap_sealed(cap)) {
        cap->cr_tag = 0;
    }
# 881 "./cheri_compressed_cap_common.h"
    cc64r_length_t req_top = (cc64r_length_t)req_base + req_len;
    ((void) sizeof ((req_base <= req_top && "Cannot invert base and top") ? 1 : 0), __extension__ ({ if (req_base <= req_top && "Cannot invert base and top") ; else __assert_fail ("req_base <= req_top && \"Cannot invert base and top\"", "./cheri_compressed_cap_common.h", 882, __extension__ __PRETTY_FUNCTION__); }));

    if (req_base < cap->cr_base || req_top > cap->_cr_top) {
        cap->cr_tag = 0;
    }

    _Static_assert(CC64R_FIELD_EXPONENT_LOW_PART_SIZE == 2, "expected 2 bits to be used by");
    _Static_assert(CC64R_FIELD_EXPONENT_HIGH_PART_SIZE == 2, "expected 2 bits to be used by");
# 899 "./cheri_compressed_cap_common.h"
    _Bool exact = 0;
    uint32_t new_ebt = cc64r_compute_ebt(req_base, req_top, alignment_mask, &exact);
    cc64r_addr_t new_base;
    cc64r_length_t new_top;
    _Bool new_bounds_valid = cc64r_compute_base_top(cc64r_extract_bounds_bits(((uint64_t)((new_ebt) & CC64R_FIELD_EBT_MAX_VALUE) << CC64R_FIELD_EBT_START)),
                                                    cap->_cr_cursor, &new_base, &new_top);
    if (exact) {




        ((void) sizeof ((new_base == req_base && "Should be exact") ? 1 : 0), __extension__ ({ if (new_base == req_base && "Should be exact") ; else __assert_fail ("new_base == req_base && \"Should be exact\"", "./cheri_compressed_cap_common.h", 910, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((new_top == req_top && "Should be exact") ? 1 : 0), __extension__ ({ if (new_top == req_top && "Should be exact") ; else __assert_fail ("new_top == req_top && \"Should be exact\"", "./cheri_compressed_cap_common.h", 911, __extension__ __PRETTY_FUNCTION__); }));

    } else {
        ((void) sizeof (((new_base != req_base || new_top != req_top) && "Was inexact, but neither base nor top different?") ? 1 : 0), __extension__ ({ if ((new_base != req_base || new_top != req_top) && "Was inexact, but neither base nor top different?") ; else __assert_fail ("(new_base != req_base || new_top != req_top) && \"Was inexact, but neither base nor top different?\"", "./cheri_compressed_cap_common.h", 915, __extension__ __PRETTY_FUNCTION__); }));

    }







    if (cap->cr_tag) {




        ((void) sizeof ((new_top >= new_base) ? 1 : 0), __extension__ ({ if (new_top >= new_base) ; else __assert_fail ("new_top >= new_base", "./cheri_compressed_cap_common.h", 929, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((cc64r_reserved_bits_valid(cap) && "Unknown reserved bits set in tagged capability") ? 1 : 0), __extension__ ({ if (cc64r_reserved_bits_valid(cap) && "Unknown reserved bits set in tagged capability") ; else __assert_fail ("cc64r_reserved_bits_valid(cap) && \"Unknown reserved bits set in tagged capability\"", "./cheri_compressed_cap_common.h", 930, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((new_bounds_valid && "Malformed bounds in tagged capability") ? 1 : 0), __extension__ ({ if (new_bounds_valid && "Malformed bounds in tagged capability") ; else __assert_fail ("new_bounds_valid && \"Malformed bounds in tagged capability\"", "./cheri_compressed_cap_common.h", 931, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((new_base >= cap->cr_base && "Cannot reduce base on tagged capabilities") ? 1 : 0), __extension__ ({ if (new_base >= cap->cr_base && "Cannot reduce base on tagged capabilities") ; else __assert_fail ("new_base >= cap->cr_base && \"Cannot reduce base on tagged capabilities\"", "./cheri_compressed_cap_common.h", 932, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((new_top <= cap->_cr_top && "Cannot increase top on tagged capabilities") ? 1 : 0), __extension__ ({ if (new_top <= cap->_cr_top && "Cannot increase top on tagged capabilities") ; else __assert_fail ("new_top <= cap->_cr_top && \"Cannot increase top on tagged capabilities\"", "./cheri_compressed_cap_common.h", 933, __extension__ __PRETTY_FUNCTION__); }));
    }
    cap->cr_base = new_base;
    cap->_cr_top = new_top;
    cc64r_update_ebt(cap, new_ebt);
    cap->cr_bounds_valid = new_bounds_valid;
    return exact;
}


extern _Bool cc64r_setbounds(cc64r_cap_t* cap, cc64r_length_t req_len) {
    __attribute__((unused)) cc64r_addr_t old_base = cap->cr_base;
    __attribute__((unused)) cc64r_length_t old_top = cap->_cr_top;
    __attribute__((unused)) cc64r_addr_t req_base =
        cc64r_cap_bounds_uses_value(cap) ? cc64r_cap_bounds_address(cap->_cr_cursor) : cap->_cr_cursor;
    __attribute__((unused)) cc64r_length_t req_top = req_len + req_base;
    _Bool exact = cc64r_setbounds_impl(cap, req_len, ((void*)0));
    if (cap->cr_tag) {

        ((void) sizeof ((!cc64r_is_cap_sealed(cap) && "result cannot be sealed and tagged") ? 1 : 0), __extension__ ({ if (!cc64r_is_cap_sealed(cap) && "result cannot be sealed and tagged") ; else __assert_fail ("!cc64r_is_cap_sealed(cap) && \"result cannot be sealed and tagged\"", "./cheri_compressed_cap_common.h", 952, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((((cap->_cr_top - cap->cr_base) >> 32) <= 1 && "length must be smaller than 1 << 65") ? 1 : 0), __extension__ ({ if (((cap->_cr_top - cap->cr_base) >> 32) <= 1 && "length must be smaller than 1 << 65") ; else __assert_fail ("((cap->_cr_top - cap->cr_base) >> 32) <= 1 && \"length must be smaller than 1 << 65\"", "./cheri_compressed_cap_common.h", 954, __extension__ __PRETTY_FUNCTION__); }));

        ((void) sizeof ((cap->cr_base >= old_base && "cannot remain tagged if base was decreased") ? 1 : 0), __extension__ ({ if (cap->cr_base >= old_base && "cannot remain tagged if base was decreased") ; else __assert_fail ("cap->cr_base >= old_base && \"cannot remain tagged if base was decreased\"", "./cheri_compressed_cap_common.h", 955, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((cap->_cr_top <= old_top && "cannot remain tagged if top was increased") ? 1 : 0), __extension__ ({ if (cap->_cr_top <= old_top && "cannot remain tagged if top was increased") ; else __assert_fail ("cap->_cr_top <= old_top && \"cannot remain tagged if top was increased\"", "./cheri_compressed_cap_common.h", 956, __extension__ __PRETTY_FUNCTION__); }));


        ((void) sizeof (((cap->_cr_top <= ((cc64r_length_t)1u << 32) || old_top > ((cc64r_length_t)1u << 32)) && "cannot remain tagged if new top greater 1 << 65") ? 1 : 0), __extension__ ({ if ((cap->_cr_top <= ((cc64r_length_t)1u << 32) || old_top > ((cc64r_length_t)1u << 32)) && "cannot remain tagged if new top greater 1 << 65") ; else __assert_fail ("(cap->_cr_top <= ((cc64r_length_t)1u << 32) || old_top > ((cc64r_length_t)1u << 32)) && \"cannot remain tagged if new top greater 1 << 65\"", "./cheri_compressed_cap_common.h", 960, __extension__ __PRETTY_FUNCTION__); }));

    }

    if (exact) {
        ((void) sizeof ((cc64r_cap_bounds_address(cap->cr_base) == cc64r_cap_bounds_address(req_base) && "base changed but still reported exact") ? 1 : 0), __extension__ ({ if (cc64r_cap_bounds_address(cap->cr_base) == cc64r_cap_bounds_address(req_base) && "base changed but still reported exact") ; else __assert_fail ("cc64r_cap_bounds_address(cap->cr_base) == cc64r_cap_bounds_address(req_base) && \"base changed but still reported exact\"", "./cheri_compressed_cap_common.h", 965, __extension__ __PRETTY_FUNCTION__); }));

        ((void) sizeof ((cc64r_cap_bounds_address(cap->_cr_top) == cc64r_cap_bounds_address(req_top) && "top changed but still reported exact") ? 1 : 0), __extension__ ({ if (cc64r_cap_bounds_address(cap->_cr_top) == cc64r_cap_bounds_address(req_top) && "top changed but still reported exact") ; else __assert_fail ("cc64r_cap_bounds_address(cap->_cr_top) == cc64r_cap_bounds_address(req_top) && \"top changed but still reported exact\"", "./cheri_compressed_cap_common.h", 967, __extension__ __PRETTY_FUNCTION__); }));

    } else {
        ((void) sizeof (((cap->_cr_top != req_top || cap->cr_base != req_base) && "result is exact but reported inexact") ? 1 : 0), __extension__ ({ if ((cap->_cr_top != req_top || cap->cr_base != req_base) && "result is exact but reported inexact") ; else __assert_fail ("(cap->_cr_top != req_top || cap->cr_base != req_base) && \"result is exact but reported inexact\"", "./cheri_compressed_cap_common.h", 970, __extension__ __PRETTY_FUNCTION__); }));

    }
    return exact;
}


extern _Bool cc64r_checked_setbounds(cc64r_cap_t* cap, cc64r_length_t req_len) {
    __attribute__((unused)) cc64r_addr_t req_base =
        cc64r_cap_bounds_uses_value(cap) ? cc64r_cap_bounds_address(cap->_cr_cursor) : cap->_cr_cursor;
    __attribute__((unused)) cc64r_length_t req_top = req_len + req_base;
    if (cap->cr_tag) {

        ((void) sizeof (((!cc64r_is_cap_sealed(cap)) && "cannot be used on tagged sealed capabilities") ? 1 : 0), __extension__ ({ if ((!cc64r_is_cap_sealed(cap)) && "cannot be used on tagged sealed capabilities") ; else __assert_fail ("(!cc64r_is_cap_sealed(cap)) && \"cannot be used on tagged sealed capabilities\"", "./cheri_compressed_cap_common.h", 982, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((req_base >= cap->cr_base) && "cannot decrease base on tagged capabilities") ? 1 : 0), __extension__ ({ if ((req_base >= cap->cr_base) && "cannot decrease base on tagged capabilities") ; else __assert_fail ("(req_base >= cap->cr_base) && \"cannot decrease base on tagged capabilities\"", "./cheri_compressed_cap_common.h", 983, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((req_top <= cap->_cr_top) && "cannot increase top on tagged capabilities") ? 1 : 0), __extension__ ({ if ((req_top <= cap->_cr_top) && "cannot increase top on tagged capabilities") ; else __assert_fail ("(req_top <= cap->_cr_top) && \"cannot increase top on tagged capabilities\"", "./cheri_compressed_cap_common.h", 984, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((req_len < ((cc64r_length_t)1u << 32)) && "requested length must be smaller than max length") ? 1 : 0), __extension__ ({ if ((req_len < ((cc64r_length_t)1u << 32)) && "requested length must be smaller than max length") ; else __assert_fail ("(req_len < ((cc64r_length_t)1u << 32)) && \"requested length must be smaller than max length\"", "./cheri_compressed_cap_common.h", 985, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((req_top < ((cc64r_length_t)1u << 32)) && "new top must be smaller than max length") ? 1 : 0), __extension__ ({ if ((req_top < ((cc64r_length_t)1u << 32)) && "new top must be smaller than max length") ; else __assert_fail ("(req_top < ((cc64r_length_t)1u << 32)) && \"new top must be smaller than max length\"", "./cheri_compressed_cap_common.h", 986, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((cap->_cr_top <= ((cc64r_length_t)1u << 32)) && "input capability top must be less than max top") ? 1 : 0), __extension__ ({ if ((cap->_cr_top <= ((cc64r_length_t)1u << 32)) && "input capability top must be less than max top") ; else __assert_fail ("(cap->_cr_top <= ((cc64r_length_t)1u << 32)) && \"input capability top must be less than max top\"", "./cheri_compressed_cap_common.h", 987, __extension__ __PRETTY_FUNCTION__); }));
    }
    return cc64r_setbounds(cap, req_len);
}


extern cc64r_cap_t cc64r__make_max_perms_cap_common(cc64r_addr_t base, cc64r_addr_t cursor, cc64r_length_t top,
                                                          __attribute__((unused)) uint8_t lvbits) {
    cc64r_cap_t creg;
    memset(&creg, 0, sizeof(creg));
    ((void) sizeof ((base <= top && "Invalid arguments") ? 1 : 0), __extension__ ({ if (base <= top && "Invalid arguments") ; else __assert_fail ("base <= top && \"Invalid arguments\"", "./cheri_compressed_cap_common.h", 997, __extension__ __PRETTY_FUNCTION__); }));
    creg.cr_base = base;
    creg._cr_cursor = cursor;
    creg.cr_bounds_valid = 1;
    creg._cr_top = top;
    creg.cr_pesbt = (((uint64_t)(((0x3)) & CC64R_FIELD_SDP_MAX_VALUE) << CC64R_FIELD_SDP_START) | ((uint64_t)(((((uint8_t)(1 << 3)) | 1)) & CC64R_FIELD_AP_M_MAX_VALUE) << CC64R_FIELD_AP_M_START) | ((uint64_t)((((1UL << (lvbits)) - 1UL)) & CC64R_FIELD_LEVEL_MAX_VALUE) << CC64R_FIELD_LEVEL_START)) | ((uint64_t)((CC64R_OTYPE_UNSEALED) & CC64R_FIELD_OTYPE_MAX_VALUE) << CC64R_FIELD_OTYPE_START);
    creg.cr_tag = 1;
    creg.cr_exp = CC64R_RESET_EXP;
    ((void) sizeof ((lvbits <= 1 && "We only support local-global levels.") ? 1 : 0), __extension__ ({ if (lvbits <= 1 && "We only support local-global levels.") ; else __assert_fail ("lvbits <= 1 && \"We only support local-global levels.\"", "./cheri_compressed_cap_common.h", 1005, __extension__ __PRETTY_FUNCTION__); }));

    creg.cr_lvbits = lvbits;

    _Bool exact_input = 0;
    cc64r_update_ebt(&creg, cc64r_compute_ebt(creg.cr_base, creg._cr_top, ((void*)0), &exact_input));
    ((void) sizeof ((exact_input && "Invalid arguments") ? 1 : 0), __extension__ ({ if (exact_input && "Invalid arguments") ; else __assert_fail ("exact_input && \"Invalid arguments\"", "./cheri_compressed_cap_common.h", 1011, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((cc64r_is_representable_cap_exact(&creg)) ? 1 : 0), __extension__ ({ if (cc64r_is_representable_cap_exact(&creg)) ; else __assert_fail ("_cc_N(is_representable_cap_exact)(&creg)", "./cheri_compressed_cap_common.h", 1012, __extension__ __PRETTY_FUNCTION__); }));
    return creg;
}




extern cc64r_cap_t cc64r_make_max_perms_cap_ext(cc64r_addr_t base, cc64r_addr_t cursor, cc64r_length_t top,
                                                      CC64R_Mode mode, uint8_t lvbits) {
    cc64r_cap_t creg = cc64r__make_max_perms_cap_common(base, cursor, top, lvbits);
    _Bool mode_valid = cc64r_set_execution_mode(&creg, mode);
    ((void) sizeof ((mode_valid && "Could not set mode on max perms cap") ? 1 : 0), __extension__ ({ if (mode_valid && "Could not set mode on max perms cap") ; else __assert_fail ("mode_valid && \"Could not set mode on max perms cap\"", "./cheri_compressed_cap_common.h", 1023, __extension__ __PRETTY_FUNCTION__); }));
    return creg;
}
extern cc64r_cap_t cc64r_make_max_perms_cap(cc64r_addr_t base, cc64r_addr_t cursor, cc64r_length_t top) {
    return cc64r_make_max_perms_cap_ext(base, cursor, top, CC64R_MODE_INT, 1);
}







extern cc64r_addr_t cc64r_get_alignment_mask(cc64r_addr_t req_length) {
    if (req_length == 0) {



        return (4294967295U);
    }


    cc64r_cap_t tmpcap = cc64r_make_max_perms_cap(0, 0, ((cc64r_length_t)1u << 32));
    cc64r_addr_t mask = 0;
    cc64r_setbounds_impl(&tmpcap, req_length, &mask);
    return mask;
}

extern cc64r_cap_t cc64r_make_null_derived_cap_ext(cc64r_addr_t addr, __attribute__((unused)) uint8_t lvbits) {
    cc64r_cap_t creg;
    memset(&creg, 0, sizeof(creg));
    creg._cr_cursor = addr;
    creg._cr_top = ((cc64r_length_t)1u << 32);
    creg.cr_pesbt = CC64R_NULL_PESBT;
    creg.cr_bounds_valid = 1;
    creg.cr_exp = CC64R_NULL_EXP;
    ((void) sizeof ((cc64r_is_representable_cap_exact(&creg)) ? 1 : 0), __extension__ ({ if (cc64r_is_representable_cap_exact(&creg)) ; else __assert_fail ("cc64r_is_representable_cap_exact(&creg)", "./cheri_compressed_cap_common.h", 1059, __extension__ __PRETTY_FUNCTION__); }));

    creg.cr_lvbits = lvbits;

    return creg;
}

extern cc64r_cap_t cc64r_make_null_derived_cap(cc64r_addr_t addr) {
    return cc64r_make_null_derived_cap_ext(addr, 1);
}

extern cc64r_addr_t cc64r_get_required_alignment(cc64r_addr_t req_length) {


    return ~cc64r_get_alignment_mask(req_length) + 1;
}

extern cc64r_addr_t cc64r_get_representable_length(cc64r_addr_t req_length) {
    cc64r_addr_t mask = cc64r_get_alignment_mask(req_length);
    return (req_length + ~mask) & mask;
}
# 172 "./cheri_compressed_cap_64r.h" 2
# 1 "./cheri_compressed_cap_riscv_common.h" 1


extern cc64r_addr_t cc64r_get_reserved(const cc64r_cap_t* cap) {
    cc64r_addr_t reserved = cap->cr_pesbt & (CC64R_FIELD_RESERVED0_MASK64 | CC64R_FIELD_RESERVED1_MASK64);
    if (cap->cr_lvbits == 0) {
        reserved |= cap->cr_pesbt & CC64R_FIELD_LEVEL_MASK64;
    }
    return reserved;
}
extern uint32_t cc64r_get_level(const cc64r_cap_t* cap) {

    return cap->cr_lvbits == 0 ? 1 : cc64r_getbits((cap->cr_pesbt), CC64R_FIELD_LEVEL_START, CC64R_FIELD_LEVEL_SIZE);
}
extern void cc64r_update_level(cc64r_cap_t* cap, uint8_t level) {
    ((void) sizeof (((level <= CC64R_MAX_LEVEL_VALUE) && "invalid level") ? 1 : 0), __extension__ ({ if ((level <= CC64R_MAX_LEVEL_VALUE) && "invalid level") ; else __assert_fail ("(level <= CC64R_MAX_LEVEL_VALUE) && \"invalid level\"", "./cheri_compressed_cap_riscv_common.h", 15, __extension__ __PRETTY_FUNCTION__); }));
    if (cap->cr_lvbits == 0) {
        ((void) sizeof (((level == 1) && "cannot change level when levels are reserved") ? 1 : 0), __extension__ ({ if ((level == 1) && "cannot change level when levels are reserved") ; else __assert_fail ("(level == 1) && \"cannot change level when levels are reserved\"", "./cheri_compressed_cap_riscv_common.h", 17, __extension__ __PRETTY_FUNCTION__); }));
        return;
    }
    cap->cr_pesbt = __extension__({ ((void) sizeof ((level <= CC64R_FIELD_LEVEL_MAX_VALUE) ? 1 : 0), __extension__ ({ if (level <= CC64R_FIELD_LEVEL_MAX_VALUE) ; else __assert_fail ("level <= CC64R_FIELD_LEVEL_MAX_VALUE", "./cheri_compressed_cap_riscv_common.h", 20, __extension__ __PRETTY_FUNCTION__); })); ((cap->cr_pesbt) & ~CC64R_FIELD_LEVEL_MASK64) | ((uint64_t)((level) & CC64R_FIELD_LEVEL_MAX_VALUE) << CC64R_FIELD_LEVEL_START); });
}

extern _Bool cc64r_bounds_malformed(struct cc64r_bounds_bits bounds) {


    _Bool malformedLSB = bounds.E > 24;


    malformedLSB = malformedLSB || (bounds.E == 0);

    _Bool malformedMSB = (bounds.E == 24 && bounds.B != 0) ||
                        (bounds.E == 24 - 1 && (bounds.B & (1u << (10 - 1))) != 0);
    return bounds.IE && (malformedLSB || malformedMSB);
}

extern _Bool cc64r_compute_base_top_special_cases(struct cc64r_bounds_bits bounds, cc64r_addr_t* base_out,
                                                         cc64r_length_t* top_out, _Bool* valid) {
    if (cc64r_bounds_malformed(bounds)) {
        *base_out = 0;
        *top_out = 0;
        *valid = 0;
        return 1;
    }
    return 0;
}


_Static_assert((CC64R_MEM_XOR_MASK) == (0UL), "");
enum { CC64R_PERMS_RESERVED_ONES = ((1UL << ((15) - (6 + CC64R_FIELD_SDP_SIZE) + 1)) - 1UL) << (6 + CC64R_FIELD_SDP_SIZE) | ((1UL << ((23) - (19) + 1)) - 1UL) << (19) };
# 173 "./cheri_compressed_cap_64r.h" 2

extern CC64R_Mode cc64r_get_execution_mode(const cc64r_cap_t* cap) {
    cc64r_addr_t raw_perms = cc64r_getbits((cap->cr_pesbt), CC64R_FIELD_AP_M_START, CC64R_FIELD_AP_M_SIZE);

    if ((raw_perms & ((uint8_t)(3 << 3))) == ((uint8_t)(1 << 3)))
        return (CC64R_Mode)(raw_perms & 1);
    return (CC64R_Mode)0;
}
extern _Bool cc64r_set_execution_mode(cc64r_cap_t* cap, CC64R_Mode new_mode) {

    cc64r_addr_t raw_perms = cc64r_getbits((cap->cr_pesbt), CC64R_FIELD_AP_M_START, CC64R_FIELD_AP_M_SIZE);
    if ((raw_perms & ((uint8_t)(3 << 3))) == ((uint8_t)(1 << 3))) {
        ((void) sizeof ((cc64r_has_permissions(cap, (1 << 17))) ? 1 : 0), __extension__ ({ if (cc64r_has_permissions(cap, (1 << 17))) ; else __assert_fail ("cc64r_has_permissions(cap, (1 << 17))", "./cheri_compressed_cap_64r.h", 185, __extension__ __PRETTY_FUNCTION__); }));
        cap->cr_pesbt = __extension__({ ((void) sizeof (((unsigned)new_mode <= CC64R_FIELD_MODE_MAX_VALUE) ? 1 : 0), __extension__ ({ if ((unsigned)new_mode <= CC64R_FIELD_MODE_MAX_VALUE) ; else __assert_fail ("(unsigned)new_mode <= CC64R_FIELD_MODE_MAX_VALUE", "./cheri_compressed_cap_64r.h", 186, __extension__ __PRETTY_FUNCTION__); })); ((cap->cr_pesbt) & ~CC64R_FIELD_MODE_MASK64) | ((uint64_t)(((unsigned)new_mode) & CC64R_FIELD_MODE_MAX_VALUE) << CC64R_FIELD_MODE_START); });
        return 1;
    }
    ((void) sizeof ((!cc64r_has_permissions(cap, (1 << 17))) ? 1 : 0), __extension__ ({ if (!cc64r_has_permissions(cap, (1 << 17))) ; else __assert_fail ("!cc64r_has_permissions(cap, (1 << 17))", "./cheri_compressed_cap_64r.h", 189, __extension__ __PRETTY_FUNCTION__); }));
    return 0;
}

extern cc64r_addr_t cc64r_get_all_permissions(const cc64r_cap_t* cap) {
    cc64r_addr_t raw_perms = cc64r_getbits((cap->cr_pesbt), CC64R_FIELD_AP_M_START, CC64R_FIELD_AP_M_SIZE);
    cc64r_addr_t res = 0;


    unsigned level_bits = cap->cr_lvbits;
    ((void) sizeof (((level_bits <= 1) && "Invalid number of level bits") ? 1 : 0), __extension__ ({ if ((level_bits <= 1) && "Invalid number of level bits") ; else __assert_fail ("(level_bits <= 1) && \"Invalid number of level bits\"", "./cheri_compressed_cap_64r.h", 199, __extension__ __PRETTY_FUNCTION__); }));

    switch (raw_perms & ((uint8_t)(3 << 3))) {
    case ((uint8_t)(0 << 3)):
        switch (raw_perms & ~((uint8_t)(3 << 3))) {
        case 0:
            break;
        case 1:
            res |= (1 << 18);
            break;
        case 4:
            res |= (1 << 0);
            break;
        case 5:
            res |= (1 << 18) | (1 << 0);
            break;
        default:

            res = 0;
            break;
        }
        break;
    case ((uint8_t)(1 << 3)):

        res |= (1 << 18) | (1 << 17);

        switch ((raw_perms & ~((uint8_t)(3 << 3))) >> 1) {
        case 0:
            res |= (1 << 0) | (1 << 5) | (1 << 1) | (1 << 16) |
                   (1 << 2) | (1 << 3);
            break;
        case 1:
            res |= (1 << 5) | (1 << 1) | (1 << 2) | (1 << 3);
            break;
        case 2:
            res |= (1 << 0) | (1 << 5) | (1 << 1) | (1 << 2) |
                   (1 << 3);
            break;
        case 3:
            res |= (1 << 0);
            break;
        default:
            __builtin_unreachable();
            break;
        }
        break;
    case ((uint8_t)(2 << 3)):
        res |= (1 << 18) | (1 << 5);
        switch (raw_perms & ~((uint8_t)(3 << 3))) {

        case 3:
            break;

        case 6:
            if (level_bits > 0) {
                res |= (1 << 0) | (1 << 1) | (1 << 3);
            } else {
                res = 0;
            }
            break;
        case 7:
            if (level_bits > 0) {
                res |= (1 << 0) | (1 << 1);
            } else {
                res = 0;
            }
            break;
        default:

            res = 0;
            break;
        }
        break;
    case ((uint8_t)(3 << 3)):

        res |= (1 << 18) | (1 << 5) | (1 << 1) | (1 << 2);
        switch (raw_perms & ~((uint8_t)(3 << 3))) {

        case 3:
            break;

        case 6:
            if (level_bits > 0) {
                res |= (1 << 0) | (1 << 3);
            } else {
                res = 0;
            }
            break;
        case 7:
            res |= (1 << 0);
            break;
        default:

            res = 0;
            break;
        }
        break;
    }

    if (level_bits > 0) {
        if (cc64r_getbits((cap->cr_pesbt), CC64R_FIELD_LEVEL_START, CC64R_FIELD_LEVEL_SIZE))
            res |= (1 << 4);
    } else {

        res |= (1 << 2) | (1 << 3) | (1 << 4);
    }
    res |= cc64r_getbits((cap->cr_pesbt), CC64R_FIELD_SDP_START, CC64R_FIELD_SDP_SIZE) << (6);
    res |= CC64R_PERMS_RESERVED_ONES;
    return res;
}

extern _Bool cc64r_set_permissions(cc64r_cap_t* cap, cc64r_addr_t permissions) {
    ((void) sizeof ((((permissions & (((0x7003f) | ((0x3) << (6))) | CC64R_PERMS_RESERVED_ONES)) == permissions) && "invalid permissions") ? 1 : 0), __extension__ ({ if (((permissions & (((0x7003f) | ((0x3) << (6))) | CC64R_PERMS_RESERVED_ONES)) == permissions) && "invalid permissions") ; else __assert_fail ("((permissions & (((0x7003f) | ((0x3) << (6))) | CC64R_PERMS_RESERVED_ONES)) == permissions) && \"invalid permissions\"", "./cheri_compressed_cap_64r.h", 312, __extension__ __PRETTY_FUNCTION__); }));

    uint8_t res = 0;
    unsigned level_bits = cap->cr_lvbits;
    ((void) sizeof (((level_bits <= 1) && "Invalid number of level bits") ? 1 : 0), __extension__ ({ if ((level_bits <= 1) && "Invalid number of level bits") ; else __assert_fail ("(level_bits <= 1) && \"Invalid number of level bits\"", "./cheri_compressed_cap_64r.h", 315, __extension__ __PRETTY_FUNCTION__); }));
    _Bool valid = 1;
    cc64r_addr_t sw_perms = (permissions >> (6)) & (0x3);

    const cc64r_addr_t maybe_el = level_bits > 0 ? (1 << 2) : 0;
    const cc64r_addr_t maybe_sl = level_bits > 0 ? (1 << 3) : 0;
    if (level_bits == 0) {

        permissions &= ~((1 << 3) | (1 << 2) | (1 << 4));
    }
    if (permissions & (1 << 17)) {
        res |= ((uint8_t)(1 << 3));
        res |= cc64r_get_execution_mode(cap);
        switch (permissions & ((1 << 18) | (1 << 0) | (1 << 5) | (1 << 1) |
                               (1 << 16))) {
        case (1 << 18) | (1 << 0) | (1 << 5) | (1 << 1) |
            (1 << 16):
            res |= 0;
            break;
        case (1 << 18) | (1 << 5) | (1 << 1): res |= 2; break;
        case (1 << 18) | (1 << 0) | (1 << 5) | (1 << 1): res |= 4; break;
        case (1 << 18) | (1 << 0): res |= 6; break;
        default: valid = 0;
        }
    } else if (permissions & (1 << 16)) {
        valid = 0;
    } else if ((permissions & ((1 << 18) | (1 << 5) | (1 << 1) | maybe_el)) ==
               ((1 << 18) | (1 << 5) | (1 << 1) | maybe_el)) {
        res |= ((uint8_t)(3 << 3));
        switch (permissions & ((1 << 0) | maybe_sl)) {

        case 0: res |= 3; break;

        case (1 << 0) | (1 << 3): res |= 6; break;
        case (1 << 0): res |= 7; break;
        default: valid = 0;
        }
    } else if ((permissions & ((1 << 18) | (1 << 5) | maybe_el)) ==
               ((1 << 18) | (1 << 5))) {
        res |= ((uint8_t)(2 << 3));
        switch (permissions & ((1 << 0) | (1 << 1) | maybe_sl)) {

        case 0: res |= 3; break;

        case (1 << 0) | (1 << 1) | (1 << 3): res |= 6; break;
        case (1 << 0) | (1 << 1): res |= 7; break;
        default: valid = 0;
        }
    } else {
        res |= ((uint8_t)(0 << 3));
        if (permissions & ((1 << 5) | (1 << 17) | (1 << 16))) {
            valid = 0;
        } else {
            switch (permissions & ((1 << 18) | (1 << 0))) {
            case 0: break;
            case (1 << 18): res |= 1; break;

            case (1 << 0): res |= 4; break;
            case (1 << 18) | (1 << 0):
                res |= 5;
                break;

            }
        }
    }


    if (!valid) {
        res = 0;
    }
    if (level_bits > 0) {
        unsigned new_level = permissions & (1 << 4) ? 1 : 0;
        cap->cr_pesbt = __extension__({ ((void) sizeof ((new_level <= CC64R_FIELD_LEVEL_MAX_VALUE) ? 1 : 0), __extension__ ({ if (new_level <= CC64R_FIELD_LEVEL_MAX_VALUE) ; else __assert_fail ("new_level <= CC64R_FIELD_LEVEL_MAX_VALUE", "./cheri_compressed_cap_64r.h", 387, __extension__ __PRETTY_FUNCTION__); })); ((cap->cr_pesbt) & ~CC64R_FIELD_LEVEL_MASK64) | ((uint64_t)((new_level) & CC64R_FIELD_LEVEL_MAX_VALUE) << CC64R_FIELD_LEVEL_START); });
    }
    cap->cr_pesbt = __extension__({ ((void) sizeof ((res <= CC64R_FIELD_AP_M_MAX_VALUE) ? 1 : 0), __extension__ ({ if (res <= CC64R_FIELD_AP_M_MAX_VALUE) ; else __assert_fail ("res <= CC64R_FIELD_AP_M_MAX_VALUE", "./cheri_compressed_cap_64r.h", 389, __extension__ __PRETTY_FUNCTION__); })); ((cap->cr_pesbt) & ~CC64R_FIELD_AP_M_MASK64) | ((uint64_t)((res) & CC64R_FIELD_AP_M_MAX_VALUE) << CC64R_FIELD_AP_M_START); });
    cap->cr_pesbt = __extension__({ ((void) sizeof ((sw_perms <= CC64R_FIELD_SDP_MAX_VALUE) ? 1 : 0), __extension__ ({ if (sw_perms <= CC64R_FIELD_SDP_MAX_VALUE) ; else __assert_fail ("sw_perms <= CC64R_FIELD_SDP_MAX_VALUE", "./cheri_compressed_cap_64r.h", 390, __extension__ __PRETTY_FUNCTION__); })); ((cap->cr_pesbt) & ~CC64R_FIELD_SDP_MASK64) | ((uint64_t)((sw_perms) & CC64R_FIELD_SDP_MAX_VALUE) << CC64R_FIELD_SDP_START); });
    return valid;
}
# 51 "./cheri_compressed_cap.h" 2
# 1 "./cheri_compressed_cap_128.h" 1
# 62 "./cheri_compressed_cap_128.h"
__extension__ typedef unsigned __int128 cc128_length_t;
__extension__ typedef signed __int128 cc128_offset_t;
typedef uint64_t cc128_addr_t;
typedef int64_t cc128_saddr_t;
# 1 "./cheri_compressed_cap_macros.h" 1
# 67 "./cheri_compressed_cap_128.h" 2
typedef enum CC128_Mode { CC128_MODE_CAP = 1, CC128_MODE_INT = 0 } CC128_Mode;


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
enum {
    CC128_FIELD_UPERMS_START = (124 - 64), CC128_FIELD_UPERMS_LAST = (127 - 64), CC128_FIELD_UPERMS_SIZE = CC128_FIELD_UPERMS_LAST - CC128_FIELD_UPERMS_START + 1, CC128_FIELD_UPERMS_MASK_NOT_SHIFTED = ((1UL << (CC128_FIELD_UPERMS_SIZE)) - 1UL), CC128_FIELD_UPERMS_MASK64 = (uint64_t)CC128_FIELD_UPERMS_MASK_NOT_SHIFTED << CC128_FIELD_UPERMS_START, CC128_FIELD_UPERMS_MAX_VALUE = CC128_FIELD_UPERMS_MASK_NOT_SHIFTED,
    CC128_FIELD_HWPERMS_START = (112 - 64), CC128_FIELD_HWPERMS_LAST = (123 - 64), CC128_FIELD_HWPERMS_SIZE = CC128_FIELD_HWPERMS_LAST - CC128_FIELD_HWPERMS_START + 1, CC128_FIELD_HWPERMS_MASK_NOT_SHIFTED = ((1UL << (CC128_FIELD_HWPERMS_SIZE)) - 1UL), CC128_FIELD_HWPERMS_MASK64 = (uint64_t)CC128_FIELD_HWPERMS_MASK_NOT_SHIFTED << CC128_FIELD_HWPERMS_START, CC128_FIELD_HWPERMS_MAX_VALUE = CC128_FIELD_HWPERMS_MASK_NOT_SHIFTED,
    CC128_FIELD_RESERVED_START = (110 - 64), CC128_FIELD_RESERVED_LAST = (111 - 64), CC128_FIELD_RESERVED_SIZE = CC128_FIELD_RESERVED_LAST - CC128_FIELD_RESERVED_START + 1, CC128_FIELD_RESERVED_MASK_NOT_SHIFTED = ((1UL << (CC128_FIELD_RESERVED_SIZE)) - 1UL), CC128_FIELD_RESERVED_MASK64 = (uint64_t)CC128_FIELD_RESERVED_MASK_NOT_SHIFTED << CC128_FIELD_RESERVED_START, CC128_FIELD_RESERVED_MAX_VALUE = CC128_FIELD_RESERVED_MASK_NOT_SHIFTED,
    CC128_FIELD_FLAGS_START = (109 - 64), CC128_FIELD_FLAGS_LAST = (109 - 64), CC128_FIELD_FLAGS_SIZE = CC128_FIELD_FLAGS_LAST - CC128_FIELD_FLAGS_START + 1, CC128_FIELD_FLAGS_MASK_NOT_SHIFTED = ((1UL << (CC128_FIELD_FLAGS_SIZE)) - 1UL), CC128_FIELD_FLAGS_MASK64 = (uint64_t)CC128_FIELD_FLAGS_MASK_NOT_SHIFTED << CC128_FIELD_FLAGS_START, CC128_FIELD_FLAGS_MAX_VALUE = CC128_FIELD_FLAGS_MASK_NOT_SHIFTED,
    CC128_FIELD_OTYPE_START = (91 - 64), CC128_FIELD_OTYPE_LAST = (108 - 64), CC128_FIELD_OTYPE_SIZE = CC128_FIELD_OTYPE_LAST - CC128_FIELD_OTYPE_START + 1, CC128_FIELD_OTYPE_MASK_NOT_SHIFTED = ((1UL << (CC128_FIELD_OTYPE_SIZE)) - 1UL), CC128_FIELD_OTYPE_MASK64 = (uint64_t)CC128_FIELD_OTYPE_MASK_NOT_SHIFTED << CC128_FIELD_OTYPE_START, CC128_FIELD_OTYPE_MAX_VALUE = CC128_FIELD_OTYPE_MASK_NOT_SHIFTED,
    CC128_FIELD_EBT_START = (64 - 64), CC128_FIELD_EBT_LAST = (90 - 64), CC128_FIELD_EBT_SIZE = CC128_FIELD_EBT_LAST - CC128_FIELD_EBT_START + 1, CC128_FIELD_EBT_MASK_NOT_SHIFTED = ((1UL << (CC128_FIELD_EBT_SIZE)) - 1UL), CC128_FIELD_EBT_MASK64 = (uint64_t)CC128_FIELD_EBT_MASK_NOT_SHIFTED << CC128_FIELD_EBT_START, CC128_FIELD_EBT_MAX_VALUE = CC128_FIELD_EBT_MASK_NOT_SHIFTED,

    CC128_FIELD_INTERNAL_EXPONENT_START = (90 - 64), CC128_FIELD_INTERNAL_EXPONENT_LAST = (90 - 64), CC128_FIELD_INTERNAL_EXPONENT_SIZE = CC128_FIELD_INTERNAL_EXPONENT_LAST - CC128_FIELD_INTERNAL_EXPONENT_START + 1, CC128_FIELD_INTERNAL_EXPONENT_MASK_NOT_SHIFTED = ((1UL << (CC128_FIELD_INTERNAL_EXPONENT_SIZE)) - 1UL), CC128_FIELD_INTERNAL_EXPONENT_MASK64 = (uint64_t)CC128_FIELD_INTERNAL_EXPONENT_MASK_NOT_SHIFTED << CC128_FIELD_INTERNAL_EXPONENT_START, CC128_FIELD_INTERNAL_EXPONENT_MAX_VALUE = CC128_FIELD_INTERNAL_EXPONENT_MASK_NOT_SHIFTED,
    CC128_FIELD_TOP_ENCODED_START = (78 - 64), CC128_FIELD_TOP_ENCODED_LAST = (89 - 64), CC128_FIELD_TOP_ENCODED_SIZE = CC128_FIELD_TOP_ENCODED_LAST - CC128_FIELD_TOP_ENCODED_START + 1, CC128_FIELD_TOP_ENCODED_MASK_NOT_SHIFTED = ((1UL << (CC128_FIELD_TOP_ENCODED_SIZE)) - 1UL), CC128_FIELD_TOP_ENCODED_MASK64 = (uint64_t)CC128_FIELD_TOP_ENCODED_MASK_NOT_SHIFTED << CC128_FIELD_TOP_ENCODED_START, CC128_FIELD_TOP_ENCODED_MAX_VALUE = CC128_FIELD_TOP_ENCODED_MASK_NOT_SHIFTED,
    CC128_FIELD_BOTTOM_ENCODED_START = (64 - 64), CC128_FIELD_BOTTOM_ENCODED_LAST = (77 - 64), CC128_FIELD_BOTTOM_ENCODED_SIZE = CC128_FIELD_BOTTOM_ENCODED_LAST - CC128_FIELD_BOTTOM_ENCODED_START + 1, CC128_FIELD_BOTTOM_ENCODED_MASK_NOT_SHIFTED = ((1UL << (CC128_FIELD_BOTTOM_ENCODED_SIZE)) - 1UL), CC128_FIELD_BOTTOM_ENCODED_MASK64 = (uint64_t)CC128_FIELD_BOTTOM_ENCODED_MASK_NOT_SHIFTED << CC128_FIELD_BOTTOM_ENCODED_START, CC128_FIELD_BOTTOM_ENCODED_MAX_VALUE = CC128_FIELD_BOTTOM_ENCODED_MASK_NOT_SHIFTED,



    CC128_FIELD_EXP_ZERO_TOP_START = (78 - 64), CC128_FIELD_EXP_ZERO_TOP_LAST = (89 - 64), CC128_FIELD_EXP_ZERO_TOP_SIZE = CC128_FIELD_EXP_ZERO_TOP_LAST - CC128_FIELD_EXP_ZERO_TOP_START + 1, CC128_FIELD_EXP_ZERO_TOP_MASK_NOT_SHIFTED = ((1UL << (CC128_FIELD_EXP_ZERO_TOP_SIZE)) - 1UL), CC128_FIELD_EXP_ZERO_TOP_MASK64 = (uint64_t)CC128_FIELD_EXP_ZERO_TOP_MASK_NOT_SHIFTED << CC128_FIELD_EXP_ZERO_TOP_START, CC128_FIELD_EXP_ZERO_TOP_MAX_VALUE = CC128_FIELD_EXP_ZERO_TOP_MASK_NOT_SHIFTED,
    CC128_FIELD_EXP_ZERO_BOTTOM_START = (64 - 64), CC128_FIELD_EXP_ZERO_BOTTOM_LAST = (77 - 64), CC128_FIELD_EXP_ZERO_BOTTOM_SIZE = CC128_FIELD_EXP_ZERO_BOTTOM_LAST - CC128_FIELD_EXP_ZERO_BOTTOM_START + 1, CC128_FIELD_EXP_ZERO_BOTTOM_MASK_NOT_SHIFTED = ((1UL << (CC128_FIELD_EXP_ZERO_BOTTOM_SIZE)) - 1UL), CC128_FIELD_EXP_ZERO_BOTTOM_MASK64 = (uint64_t)CC128_FIELD_EXP_ZERO_BOTTOM_MASK_NOT_SHIFTED << CC128_FIELD_EXP_ZERO_BOTTOM_START, CC128_FIELD_EXP_ZERO_BOTTOM_MAX_VALUE = CC128_FIELD_EXP_ZERO_BOTTOM_MASK_NOT_SHIFTED,

    CC128_FIELD_EXP_NONZERO_TOP_START = (81 - 64), CC128_FIELD_EXP_NONZERO_TOP_LAST = (89 - 64), CC128_FIELD_EXP_NONZERO_TOP_SIZE = CC128_FIELD_EXP_NONZERO_TOP_LAST - CC128_FIELD_EXP_NONZERO_TOP_START + 1, CC128_FIELD_EXP_NONZERO_TOP_MASK_NOT_SHIFTED = ((1UL << (CC128_FIELD_EXP_NONZERO_TOP_SIZE)) - 1UL), CC128_FIELD_EXP_NONZERO_TOP_MASK64 = (uint64_t)CC128_FIELD_EXP_NONZERO_TOP_MASK_NOT_SHIFTED << CC128_FIELD_EXP_NONZERO_TOP_START, CC128_FIELD_EXP_NONZERO_TOP_MAX_VALUE = CC128_FIELD_EXP_NONZERO_TOP_MASK_NOT_SHIFTED,
    CC128_FIELD_EXPONENT_HIGH_PART_START = (78 - 64), CC128_FIELD_EXPONENT_HIGH_PART_LAST = (80 - 64), CC128_FIELD_EXPONENT_HIGH_PART_SIZE = CC128_FIELD_EXPONENT_HIGH_PART_LAST - CC128_FIELD_EXPONENT_HIGH_PART_START + 1, CC128_FIELD_EXPONENT_HIGH_PART_MASK_NOT_SHIFTED = ((1UL << (CC128_FIELD_EXPONENT_HIGH_PART_SIZE)) - 1UL), CC128_FIELD_EXPONENT_HIGH_PART_MASK64 = (uint64_t)CC128_FIELD_EXPONENT_HIGH_PART_MASK_NOT_SHIFTED << CC128_FIELD_EXPONENT_HIGH_PART_START, CC128_FIELD_EXPONENT_HIGH_PART_MAX_VALUE = CC128_FIELD_EXPONENT_HIGH_PART_MASK_NOT_SHIFTED,
    CC128_FIELD_EXP_NONZERO_BOTTOM_START = (67 - 64), CC128_FIELD_EXP_NONZERO_BOTTOM_LAST = (77 - 64), CC128_FIELD_EXP_NONZERO_BOTTOM_SIZE = CC128_FIELD_EXP_NONZERO_BOTTOM_LAST - CC128_FIELD_EXP_NONZERO_BOTTOM_START + 1, CC128_FIELD_EXP_NONZERO_BOTTOM_MASK_NOT_SHIFTED = ((1UL << (CC128_FIELD_EXP_NONZERO_BOTTOM_SIZE)) - 1UL), CC128_FIELD_EXP_NONZERO_BOTTOM_MASK64 = (uint64_t)CC128_FIELD_EXP_NONZERO_BOTTOM_MASK_NOT_SHIFTED << CC128_FIELD_EXP_NONZERO_BOTTOM_START, CC128_FIELD_EXP_NONZERO_BOTTOM_MAX_VALUE = CC128_FIELD_EXP_NONZERO_BOTTOM_MASK_NOT_SHIFTED,
    CC128_FIELD_EXPONENT_LOW_PART_START = (64 - 64), CC128_FIELD_EXPONENT_LOW_PART_LAST = (66 - 64), CC128_FIELD_EXPONENT_LOW_PART_SIZE = CC128_FIELD_EXPONENT_LOW_PART_LAST - CC128_FIELD_EXPONENT_LOW_PART_START + 1, CC128_FIELD_EXPONENT_LOW_PART_MASK_NOT_SHIFTED = ((1UL << (CC128_FIELD_EXPONENT_LOW_PART_SIZE)) - 1UL), CC128_FIELD_EXPONENT_LOW_PART_MASK64 = (uint64_t)CC128_FIELD_EXPONENT_LOW_PART_MASK_NOT_SHIFTED << CC128_FIELD_EXPONENT_LOW_PART_START, CC128_FIELD_EXPONENT_LOW_PART_MAX_VALUE = CC128_FIELD_EXPONENT_LOW_PART_MASK_NOT_SHIFTED,
};
#pragma GCC diagnostic pop
# 116 "./cheri_compressed_cap_128.h"
_Static_assert((1 << 11) < CC128_FIELD_HWPERMS_MAX_VALUE, "permissions not representable?");
_Static_assert(((1 << 11) << 1) > CC128_FIELD_HWPERMS_MAX_VALUE, "all permission bits should be used");
# 129 "./cheri_compressed_cap_128.h"
enum CC128_OTypes {
    CC128_MAX_REPRESENTABLE_OTYPE = ((1u << CC128_FIELD_OTYPE_SIZE) - 1u),
    CC128_OTYPE_UNSEALED = ((CC128_MAX_REPRESENTABLE_OTYPE - 0u)), CC128_OTYPE_UNSEALED_SIGNED = ((((int64_t)-1) - 0u)),
    CC128_OTYPE_SENTRY = ((CC128_MAX_REPRESENTABLE_OTYPE - 1u)), CC128_OTYPE_SENTRY_SIGNED = ((((int64_t)-1) - 1u)),
    CC128_OTYPE_INDIRECT_PAIR = ((CC128_MAX_REPRESENTABLE_OTYPE - 2u)), CC128_OTYPE_INDIRECT_PAIR_SIGNED = ((((int64_t)-1) - 2u)),
    CC128_OTYPE_INDIRECT_SENTRY = ((CC128_MAX_REPRESENTABLE_OTYPE - 3u)), CC128_OTYPE_INDIRECT_SENTRY_SIGNED = ((((int64_t)-1) - 3u)),
    CC128_OTYPE_RESERVED_LAST = ((CC128_MAX_REPRESENTABLE_OTYPE - 3u)), CC128_OTYPE_RESERVED_LAST_SIGNED = ((((int64_t)-1) - 3u)),





    CC128_MIN_RESERVED_OTYPE = CC128_OTYPE_RESERVED_LAST,
    CC128_MAX_RESERVED_OTYPE = CC128_OTYPE_UNSEALED,
};







_Static_assert((14) == (CC128_FIELD_EXP_ZERO_BOTTOM_SIZE), "");
# 164 "./cheri_compressed_cap_128.h"
# 1 "./cheri_compressed_cap_common.h" 1
# 40 "./cheri_compressed_cap_common.h"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
enum {


    CC128_RESET_EXP = 52,
    CC128_RESET_T = 1u << (64 - CC128_RESET_EXP - CC128_FIELD_EXPONENT_HIGH_PART_SIZE),







    CC128_NULL_EXP = CC128_RESET_EXP,
    CC128_NULL_T = CC128_RESET_T,

    CC128_RESET_EBT = ((uint64_t)((1) & CC128_FIELD_INTERNAL_EXPONENT_MAX_VALUE) << CC128_FIELD_INTERNAL_EXPONENT_START) | ((uint64_t)(((CC128_RESET_EXP) >> CC128_FIELD_EXPONENT_LOW_PART_SIZE) & CC128_FIELD_EXPONENT_HIGH_PART_MAX_VALUE) << CC128_FIELD_EXPONENT_HIGH_PART_START) | ((uint64_t)((CC128_RESET_EXP) & CC128_FIELD_EXPONENT_LOW_PART_MAX_VALUE) << CC128_FIELD_EXPONENT_LOW_PART_START) |
                       ((uint64_t)((CC128_RESET_T) & CC128_FIELD_EXP_NONZERO_TOP_MAX_VALUE) << CC128_FIELD_EXP_NONZERO_TOP_START) | ((uint64_t)((0) & CC128_FIELD_EXP_NONZERO_BOTTOM_MAX_VALUE) << CC128_FIELD_EXP_NONZERO_BOTTOM_START),
    CC128_RESET_PESBT = CC128_RESET_EBT | (((uint64_t)(((0xf)) & CC128_FIELD_UPERMS_MAX_VALUE) << CC128_FIELD_UPERMS_START) | ((uint64_t)(((0xfff)) & CC128_FIELD_HWPERMS_MAX_VALUE) << CC128_FIELD_HWPERMS_START)) |
                         ((uint64_t)((CC128_OTYPE_UNSEALED) & CC128_FIELD_OTYPE_MAX_VALUE) << CC128_FIELD_OTYPE_START),
    CC128_NULL_EBT = ((uint64_t)((1) & CC128_FIELD_INTERNAL_EXPONENT_MAX_VALUE) << CC128_FIELD_INTERNAL_EXPONENT_START) | ((uint64_t)(((CC128_NULL_EXP) >> CC128_FIELD_EXPONENT_LOW_PART_SIZE) & CC128_FIELD_EXPONENT_HIGH_PART_MAX_VALUE) << CC128_FIELD_EXPONENT_HIGH_PART_START) | ((uint64_t)((CC128_NULL_EXP) & CC128_FIELD_EXPONENT_LOW_PART_MAX_VALUE) << CC128_FIELD_EXPONENT_LOW_PART_START) |
                      ((uint64_t)((CC128_NULL_T) & CC128_FIELD_EXP_NONZERO_TOP_MAX_VALUE) << CC128_FIELD_EXP_NONZERO_TOP_START) | ((uint64_t)((0) & CC128_FIELD_EXP_NONZERO_BOTTOM_MAX_VALUE) << CC128_FIELD_EXP_NONZERO_BOTTOM_START),
    CC128_NULL_PESBT = CC128_NULL_EBT | ((uint64_t)((CC128_OTYPE_UNSEALED) & CC128_FIELD_OTYPE_MAX_VALUE) << CC128_FIELD_OTYPE_START),

    CC128_MEM_XOR_MASK = CC128_NULL_PESBT,
    CC128_NULL_XOR_MASK __attribute__((deprecated("Use _MEM_XOR_MASK instead"))) = CC128_MEM_XOR_MASK,
    CC128_MAX_LEVEL_VALUE = ((1UL << (1)) - 1UL),
};
#pragma GCC diagnostic pop
# 89 "./cheri_compressed_cap_common.h"
enum { CC128_FIELD_LEN_MSB_SIZE = 0 };



_Static_assert((CC128_FIELD_INTERNAL_EXPONENT_SIZE + CC128_FIELD_EXP_ZERO_TOP_SIZE + CC128_FIELD_LEN_MSB_SIZE + CC128_FIELD_EXP_ZERO_BOTTOM_SIZE) == (CC128_FIELD_EBT_SIZE), "");


_Static_assert((CC128_FIELD_INTERNAL_EXPONENT_SIZE + CC128_FIELD_LEN_MSB_SIZE + CC128_FIELD_TOP_ENCODED_SIZE + CC128_FIELD_BOTTOM_ENCODED_SIZE) == (CC128_FIELD_EBT_SIZE), "");


_Static_assert((CC128_FIELD_INTERNAL_EXPONENT_SIZE + CC128_FIELD_LEN_MSB_SIZE + CC128_FIELD_EXP_NONZERO_TOP_SIZE + CC128_FIELD_EXP_NONZERO_BOTTOM_SIZE + CC128_FIELD_EXPONENT_HIGH_PART_SIZE + CC128_FIELD_EXPONENT_LOW_PART_SIZE) == (CC128_FIELD_EBT_SIZE), "");




_Static_assert((CC128_FIELD_EBT_START) == (0), "");

_Static_assert(CC128_MIN_RESERVED_OTYPE >= 0, "MIN_RESERVED_OTYPE is signed?");
_Static_assert(CC128_MIN_RESERVED_OTYPE < CC128_MAX_RESERVED_OTYPE, "MIN_RESERVED_OTYPE greater than MAX_RESERVED_OTYPE?");

_Static_assert(CC128_MIN_RESERVED_OTYPE <= CC128_MAX_REPRESENTABLE_OTYPE, "MIN_RESERVED_OTYPE out of range?");
_Static_assert(CC128_MAX_RESERVED_OTYPE <= CC128_MAX_REPRESENTABLE_OTYPE, "MAX_RESERVED_OTYPE out of range?");


typedef struct cc128_cap cc128_cap_t;

extern uint8_t cc128_get_flags(const cc128_cap_t* cap);
extern uint32_t cc128_get_otype(const cc128_cap_t* cap);
extern uint32_t cc128_get_level(const cc128_cap_t* cap);
extern cc128_addr_t cc128_get_perms(const cc128_cap_t* cap);
extern cc128_addr_t cc128_get_reserved(const cc128_cap_t* cap);
extern _Bool cc128_reserved_bits_valid(const cc128_cap_t* cap) { return cc128_get_reserved(cap) == 0; }
extern cc128_addr_t cc128_get_uperms(const cc128_cap_t* cap);

extern cc128_addr_t cc128_get_all_permissions(const cc128_cap_t* cap);
extern _Bool cc128_has_permissions(const cc128_cap_t* cap, cc128_addr_t permissions) {
    return (cc128_get_all_permissions(cap) & permissions) == permissions;
}
extern _Bool cc128_set_permissions(cc128_cap_t* cap, cc128_addr_t permissions);

extern CC128_Mode cc128_get_execution_mode(const cc128_cap_t* cap);
extern _Bool cc128_set_execution_mode(cc128_cap_t* cap, CC128_Mode new_mode);



struct cc128_cap {







    cc128_addr_t _cr_cursor;
    cc128_addr_t cr_pesbt;

    cc128_length_t _cr_top;
    cc128_addr_t cr_base;
    uint8_t cr_tag;
    uint8_t cr_bounds_valid;



    uint8_t cr_exp;
    uint8_t cr_extra;
# 179 "./cheri_compressed_cap_common.h"
};

extern _Bool cc128_exactly_equal(const cc128_cap_t* a, const cc128_cap_t* b) {
    return a->cr_tag == b->cr_tag && a->_cr_cursor == b->_cr_cursor && a->cr_pesbt == b->cr_pesbt;
}

extern uint8_t cc128_get_lvbits(__attribute__((unused)) const cc128_cap_t* cap) {



    return 1;

}

extern _Bool cc128_raw_equal(const cc128_cap_t* a, const cc128_cap_t* b) {
    return a->_cr_cursor == b->_cr_cursor && a->cr_pesbt == b->cr_pesbt && a->_cr_top == b->_cr_top &&
           a->cr_base == b->cr_base && a->cr_tag == b->cr_tag && a->cr_bounds_valid == b->cr_bounds_valid &&
           cc128_get_lvbits(a) == cc128_get_lvbits(b) && a->cr_exp == b->cr_exp && a->cr_extra == b->cr_extra;
}


extern uint32_t cc128_idx_MSNZ(uint64_t x) {
# 218 "./cheri_compressed_cap_common.h"
    ((void) sizeof ((x != 0) ? 1 : 0), __extension__ ({ if (x != 0) ; else __assert_fail ("x != 0", "./cheri_compressed_cap_common.h", 218, __extension__ __PRETTY_FUNCTION__); }));
    uint32_t r = 63u - (uint32_t)__builtin_clzll(x);

    return r;
}





extern uint32_t cc128_compute_e(cc128_addr_t rlength, uint32_t bwidth) {
    if (rlength < (1u << (bwidth - 1)))
        return 0;

    return (cc128_idx_MSNZ(rlength) - (bwidth - 2));
}

extern uint32_t cc128_get_exponent(cc128_length_t length) {
    const uint32_t bwidth = 14;
    if (length > (18446744073709551615UL)) {
        return 65 - (bwidth - 1);
    } else {
        return cc128_compute_e((cc128_addr_t)length, bwidth);
    }
}

extern uint64_t cc128_getbits(uint64_t src, uint32_t start, uint32_t size) {
    return ((src >> start) & ((1UL << size) - 1UL));
}


extern uint64_t cc128_truncate_addr(cc128_addr_t value, size_t n) { return value & (((cc128_addr_t)1 << n) - 1); }
extern uint64_t cc128_truncate64(uint64_t value, size_t n) { return value & ((1UL << n) - 1); }







extern uint64_t cc128_truncateLSB_14(uint64_t value, size_t n) { _Static_assert(14 <= 64, ""); return value >> (14 - n); }
extern uint64_t cc128_truncateLSB_32(uint64_t value, size_t n) { _Static_assert(32 <= 64, ""); return value >> (32 - n); }
extern uint64_t cc128_truncateLSB_64(uint64_t value, size_t n) { _Static_assert(64 <= 64, ""); return value >> (64 - n); }




struct cc128_bounds_bits {
    uint16_t B;
    uint16_t T;
    uint8_t E;
    _Bool IE;
};
# 283 "./cheri_compressed_cap_common.h"
extern cc128_addr_t cc128_cap_pesbt_extract_otype(cc128_addr_t pesbt) { return cc128_getbits((pesbt), CC128_FIELD_OTYPE_START, CC128_FIELD_OTYPE_SIZE); } extern cc128_addr_t cc128_cap_pesbt_encode_otype(uint32_t value) { return ((uint64_t)((value) & CC128_FIELD_OTYPE_MAX_VALUE) << CC128_FIELD_OTYPE_START); } extern cc128_addr_t cc128_cap_pesbt_deposit_otype(cc128_addr_t pesbt, uint32_t value) { return __extension__({ ((void) sizeof ((value <= CC128_FIELD_OTYPE_MAX_VALUE) ? 1 : 0), __extension__ ({ if (value <= CC128_FIELD_OTYPE_MAX_VALUE) ; else __assert_fail ("value <= CC128_FIELD_OTYPE_MAX_VALUE", "./cheri_compressed_cap_common.h", 283, __extension__ __PRETTY_FUNCTION__); })); ((pesbt) & ~CC128_FIELD_OTYPE_MASK64) | ((uint64_t)((value) & CC128_FIELD_OTYPE_MAX_VALUE) << CC128_FIELD_OTYPE_START); }); } extern uint32_t cc128_get_otype(const cc128_cap_t* cap) { return cc128_cap_pesbt_extract_otype(cap->cr_pesbt); } extern void cc128_update_otype(cc128_cap_t * cap, cc128_addr_t value) { cap->cr_pesbt = cc128_cap_pesbt_deposit_otype(cap->cr_pesbt, value); }
extern cc128_addr_t cc128_cap_pesbt_extract_flags(cc128_addr_t pesbt) { return cc128_getbits((pesbt), CC128_FIELD_FLAGS_START, CC128_FIELD_FLAGS_SIZE); } extern cc128_addr_t cc128_cap_pesbt_encode_flags(uint8_t value) { return ((uint64_t)((value) & CC128_FIELD_FLAGS_MAX_VALUE) << CC128_FIELD_FLAGS_START); } extern cc128_addr_t cc128_cap_pesbt_deposit_flags(cc128_addr_t pesbt, uint8_t value) { return __extension__({ ((void) sizeof ((value <= CC128_FIELD_FLAGS_MAX_VALUE) ? 1 : 0), __extension__ ({ if (value <= CC128_FIELD_FLAGS_MAX_VALUE) ; else __assert_fail ("value <= CC128_FIELD_FLAGS_MAX_VALUE", "./cheri_compressed_cap_common.h", 284, __extension__ __PRETTY_FUNCTION__); })); ((pesbt) & ~CC128_FIELD_FLAGS_MASK64) | ((uint64_t)((value) & CC128_FIELD_FLAGS_MAX_VALUE) << CC128_FIELD_FLAGS_START); }); } extern uint8_t cc128_get_flags(const cc128_cap_t* cap) { return cc128_cap_pesbt_extract_flags(cap->cr_pesbt); } extern void cc128_update_flags(cc128_cap_t * cap, cc128_addr_t value) { cap->cr_pesbt = cc128_cap_pesbt_deposit_flags(cap->cr_pesbt, value); }


extern _Bool cc128_is_cap_sealed(const cc128_cap_t* cp) { return cc128_get_otype(cp) != CC128_OTYPE_UNSEALED; }


extern uint32_t cc128_get_level(const cc128_cap_t* cap) {
    return cc128_get_all_permissions(cap) & (1 << 0) ? 1 : 0;
}
extern void cc128_update_level(cc128_cap_t* cap, uint8_t level) {
    ((void) sizeof (((level <= CC128_MAX_LEVEL_VALUE) && "invalid level") ? 1 : 0), __extension__ ({ if ((level <= CC128_MAX_LEVEL_VALUE) && "invalid level") ; else __assert_fail ("(level <= CC128_MAX_LEVEL_VALUE) && \"invalid level\"", "./cheri_compressed_cap_common.h", 294, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof (((!cap->cr_tag || !cc128_is_cap_sealed(cap)) && "cannot update level on sealed caps") ? 1 : 0), __extension__ ({ if ((!cap->cr_tag || !cc128_is_cap_sealed(cap)) && "cannot update level on sealed caps") ; else __assert_fail ("(!cap->cr_tag || !cc128_is_cap_sealed(cap)) && \"cannot update level on sealed caps\"", "./cheri_compressed_cap_common.h", 295, __extension__ __PRETTY_FUNCTION__); }));
    cc128_addr_t perms = cc128_get_all_permissions(cap);
    if (level)
        perms |= (1 << 0);
    else
        perms &= ~(1 << 0);
    __attribute__((unused)) _Bool ok = cc128_set_permissions(cap, perms);
    ((void) sizeof ((ok && "failed to update level") ? 1 : 0), __extension__ ({ if (ok && "failed to update level") ; else __assert_fail ("ok && \"failed to update level\"", "./cheri_compressed_cap_common.h", 302, __extension__ __PRETTY_FUNCTION__); }));
}



extern cc128_cap_t cc128_make_null_derived_cap(cc128_addr_t addr);
__attribute__((deprecated("Use get_all_permissions"))) extern cc128_addr_t cc128_get_perms(const cc128_cap_t* cap) {

    _Static_assert((15) != 0, "Architectural perms expected to start at offset zero");

    cc128_cap_t null_cap = cc128_make_null_derived_cap(0);
    cc128_addr_t reserved_one_bits = cc128_get_all_permissions(&null_cap);
    cc128_addr_t all_perms_w_reserved = cc128_get_all_permissions(cap);
    return (all_perms_w_reserved & ~reserved_one_bits) & ~((0xf) << (15));
}
__attribute__((deprecated("Use get_all_permissions"))) extern cc128_addr_t cc128_get_uperms(const cc128_cap_t* cap) {
    return (cc128_get_all_permissions(cap) & ((0xf) << (15))) >> (15);
}
__attribute__((deprecated("Use set_permissions"))) extern void cc128_update_perms(cc128_cap_t* cap, cc128_addr_t value) {
    ((void) sizeof ((((value & (0xfff)) == value) && "invalid permission value") ? 1 : 0), __extension__ ({ if (((value & (0xfff)) == value) && "invalid permission value") ; else __assert_fail ("((value & (0xfff)) == value) && \"invalid permission value\"", "./cheri_compressed_cap_common.h", 321, __extension__ __PRETTY_FUNCTION__); }));
    cc128_addr_t current_swperms = (cc128_get_all_permissions(cap) & ((0xf) << (15)));
    cc128_set_permissions(cap, (value & ~((0xf) << (15))) | current_swperms);
}
__attribute__((deprecated("Use set_permissions"))) extern void cc128_update_uperms(cc128_cap_t* cap, cc128_addr_t value) {
    ((void) sizeof ((((value & (0xf)) == value) && "invalid permission value") ? 1 : 0), __extension__ ({ if (((value & (0xf)) == value) && "invalid permission value") ; else __assert_fail ("((value & (0xf)) == value) && \"invalid permission value\"", "./cheri_compressed_cap_common.h", 326, __extension__ __PRETTY_FUNCTION__); }));
    cc128_addr_t old_arch_perms = cc128_get_all_permissions(cap) & ~((0xf) << (15));
    cc128_set_permissions(cap, ((value << (15)) & ((0xf) << (15))) | old_arch_perms);
}


extern struct cc128_bounds_bits cc128_extract_bounds_bits(cc128_addr_t pesbt) {
    _Static_assert(14 == CC128_FIELD_EXP_ZERO_BOTTOM_SIZE, "Wrong bot width?");
    uint32_t BWidth = 14;
    uint32_t BMask = (1u << BWidth) - 1;
    uint32_t TMask = BMask >> 2;
    struct cc128_bounds_bits result;
    _Static_assert(sizeof(result.B) * 8 >= 14, "B field too small");
    _Static_assert(sizeof(result.T) * 8 >= 14, "T field too small");
    _Static_assert(sizeof(result.E) * 8 >= CC128_FIELD_EXPONENT_LOW_PART_SIZE + CC128_FIELD_EXPONENT_HIGH_PART_SIZE, "E field too small");


    result.IE = (_Bool)cc128_getbits((pesbt), CC128_FIELD_INTERNAL_EXPONENT_START, CC128_FIELD_INTERNAL_EXPONENT_SIZE);
    uint8_t L_msb;
    if (result.IE) {
        result.E = (uint8_t)(cc128_getbits((pesbt), CC128_FIELD_EXPONENT_LOW_PART_START, CC128_FIELD_EXPONENT_LOW_PART_SIZE) | (cc128_getbits((pesbt), CC128_FIELD_EXPONENT_HIGH_PART_START, CC128_FIELD_EXPONENT_HIGH_PART_SIZE) << CC128_FIELD_EXPONENT_LOW_PART_SIZE));



        result.B = (uint16_t)cc128_getbits((pesbt), CC128_FIELD_EXP_NONZERO_BOTTOM_START, CC128_FIELD_EXP_NONZERO_BOTTOM_SIZE) << CC128_FIELD_EXPONENT_LOW_PART_SIZE;
        result.T = (uint16_t)cc128_getbits((pesbt), CC128_FIELD_EXP_NONZERO_TOP_START, CC128_FIELD_EXP_NONZERO_TOP_SIZE) << CC128_FIELD_EXPONENT_HIGH_PART_SIZE;
        L_msb = 1;
    } else {
        result.E = 0;



        L_msb = 0;

        result.B = (uint16_t)cc128_getbits((pesbt), CC128_FIELD_EXP_ZERO_BOTTOM_START, CC128_FIELD_EXP_ZERO_BOTTOM_SIZE);
        result.T = (uint16_t)cc128_getbits((pesbt), CC128_FIELD_EXP_ZERO_TOP_START, CC128_FIELD_EXP_ZERO_TOP_SIZE);
    }






    uint8_t L_carry = result.T < (result.B & TMask) ? 1 : 0;
    uint64_t BTop2 = cc128_getbits(result.B, 14 - 2, 2);
    uint8_t T_infer = (BTop2 + L_carry + L_msb) & 0x3;
    result.T |= ((uint16_t)T_infer) << (BWidth - 2);
    return result;
}


extern _Bool cc128_bounds_bits_valid(struct cc128_bounds_bits bounds) {

    cc128_addr_t Bmsb = cc128_getbits(bounds.B, 14 - 1, 1);
    cc128_addr_t Bmsb2 = cc128_getbits(bounds.B, 14 - 2, 2);
    cc128_addr_t Tmsb = cc128_getbits(bounds.T, 14 - 1, 1);
    if (bounds.E >= 52) {
        return Tmsb == 0 && Bmsb2 == 0;
    } else if (bounds.E == 52 - 1) {
        return Bmsb == 0;
    } else {
        return 1;
    }
}



extern cc128_addr_t cc128_cap_bounds_address(cc128_addr_t addr) {

    cc128_addr_t cursor = addr & 0xFFFFFFFFFFFFFFFF;

    if (cursor & ((0xFFFFFFFFFFFFFFFF >> 1) + 1))
        cursor |= ~0xFFFFFFFFFFFFFFFF;
    return cursor;
}





extern _Bool cc128_compute_base_top(struct cc128_bounds_bits bounds, cc128_addr_t cursor, cc128_addr_t* base_out,
                                           cc128_length_t* top_out) {





    cursor = cc128_cap_bounds_address(cursor);




    uint8_t E = ((52) < (bounds.E) ? (52) : (bounds.E));




    unsigned a_mid = (unsigned)cc128_truncate64(cursor >> (E + 14 - 3), 3);
    unsigned correction_B = (unsigned)cc128_truncateLSB_14(bounds.B, 3);
    unsigned correction_T = (unsigned)cc128_truncateLSB_14(bounds.T, 3);

    unsigned R = (unsigned)cc128_truncate64(correction_B - 1, 3);
# 440 "./cheri_compressed_cap_common.h"
    int aHi = a_mid < R ? 1 : 0;
    int bHi = correction_B < R ? 1 : 0;
    int tHi = correction_T < R ? 1 : 0;




    int correction_base = bHi - aHi;
    int correction_top = tHi - aHi;

    const unsigned a_top_shift = E + 14;

    cc128_addr_t a_top = a_top_shift >= 64 ? 0 : cursor >> a_top_shift;


    cc128_length_t base = (cc128_addr_t)((int64_t)a_top + correction_base);
    base <<= 14;
    base |= bounds.B;
    base <<= E;
    base &= ((cc128_length_t)1 << 65) - 1;
    ((void) sizeof (((cc128_addr_t)(base >> 64) <= 1) ? 1 : 0), __extension__ ({ if ((cc128_addr_t)(base >> 64) <= 1) ; else __assert_fail ("(cc128_addr_t)(base >> 64) <= 1", "./cheri_compressed_cap_common.h", 460, __extension__ __PRETTY_FUNCTION__); }));

    cc128_length_t top = (cc128_addr_t)((int64_t)a_top + correction_top);
    top <<= 14;
    top |= bounds.T;
    top <<= E;
    top &= ((cc128_length_t)1 << 65) - 1;
    ((void) sizeof (((cc128_addr_t)(top >> 64) <= 1) ? 1 : 0), __extension__ ({ if ((cc128_addr_t)(top >> 64) <= 1) ; else __assert_fail ("(cc128_addr_t)(top >> 64) <= 1", "./cheri_compressed_cap_common.h", 467, __extension__ __PRETTY_FUNCTION__); }));







    unsigned base2 = cc128_truncate64(base >> (64 - 1), 1);

    unsigned top2 = cc128_truncate64(top >> (64 - 1), 2);



    if (E < (52 - 1) && (top2 - base2) > 1) {
        top = top ^ ((cc128_length_t)1 << 64);
    }

    ((void) sizeof (((cc128_addr_t)(top >> 64) <= 1) ? 1 : 0), __extension__ ({ if ((cc128_addr_t)(top >> 64) <= 1) ; else __assert_fail ("(cc128_addr_t)(top >> 64) <= 1", "./cheri_compressed_cap_common.h", 485, __extension__ __PRETTY_FUNCTION__); }));

    if (cc128_bounds_bits_valid(bounds)) {


        ((void) sizeof (((cc128_addr_t)base <= top) ? 1 : 0), __extension__ ({ if ((cc128_addr_t)base <= top) ; else __assert_fail ("(cc128_addr_t)base <= top", "./cheri_compressed_cap_common.h", 490, __extension__ __PRETTY_FUNCTION__); }));
    } else {

    }
    *base_out = (cc128_addr_t)base;
    *top_out = top;

    return 1;
}



extern void cc128_unsafe_decompress_raw(cc128_addr_t pesbt, cc128_addr_t cursor, _Bool tag,
                                                __attribute__((unused)) uint8_t lvbits, cc128_cap_t* cdp) {
    memset(cdp, 0, sizeof(*cdp));
    cdp->cr_tag = tag;
    cdp->_cr_cursor = cursor;
    cdp->cr_pesbt = pesbt;




    struct cc128_bounds_bits bounds = cc128_extract_bounds_bits(pesbt);
    _Bool valid = cc128_compute_base_top(bounds, cursor, &cdp->cr_base, &cdp->_cr_top);
    cdp->cr_bounds_valid = valid;
    cdp->cr_exp = bounds.E;
}

extern void cc128_decompress_raw_ext(cc128_addr_t pesbt, cc128_addr_t cursor, _Bool tag, uint8_t lvbits,
                                             cc128_cap_t* cdp) {
    cc128_unsafe_decompress_raw(pesbt, cursor, tag, lvbits, cdp);
    if (tag) {
        ((void) sizeof ((cdp->cr_base <= (18446744073709551615UL)) ? 1 : 0), __extension__ ({ if (cdp->cr_base <= (18446744073709551615UL)) ; else __assert_fail ("cdp->cr_base <= (18446744073709551615UL)", "./cheri_compressed_cap_common.h", 522, __extension__ __PRETTY_FUNCTION__); }));


        ((void) sizeof ((cdp->_cr_top <= ((cc128_length_t)1u << 64)) ? 1 : 0), __extension__ ({ if (cdp->_cr_top <= ((cc128_length_t)1u << 64)) ; else __assert_fail ("cdp->_cr_top <= ((cc128_length_t)1u << 64)", "./cheri_compressed_cap_common.h", 525, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((cdp->cr_base <= cdp->_cr_top) ? 1 : 0), __extension__ ({ if (cdp->cr_base <= cdp->_cr_top) ; else __assert_fail ("cdp->cr_base <= cdp->_cr_top", "./cheri_compressed_cap_common.h", 526, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((cdp->cr_bounds_valid) ? 1 : 0), __extension__ ({ if (cdp->cr_bounds_valid) ; else __assert_fail ("cdp->cr_bounds_valid", "./cheri_compressed_cap_common.h", 527, __extension__ __PRETTY_FUNCTION__); }));

        ((void) sizeof ((cc128_reserved_bits_valid(cdp)) ? 1 : 0), __extension__ ({ if (cc128_reserved_bits_valid(cdp)) ; else __assert_fail ("cc128_reserved_bits_valid(cdp)", "./cheri_compressed_cap_common.h", 529, __extension__ __PRETTY_FUNCTION__); }));
    }
}

extern void cc128_decompress_raw(cc128_addr_t pesbt, cc128_addr_t cursor, _Bool tag, cc128_cap_t* cdp) {
    cc128_decompress_raw_ext(pesbt, cursor, tag, 1, cdp);
}




extern void cc128_decompress_mem(uint64_t pesbt, uint64_t cursor, _Bool tag, cc128_cap_t* cdp) {
    cc128_decompress_raw_ext(pesbt ^ CC128_MEM_XOR_MASK, cursor, tag, 1, cdp);
}


extern _Bool cc128_pesbt_is_correct(const cc128_cap_t* csp) {
    cc128_cap_t tmp;

    cc128_unsafe_decompress_raw(csp->cr_pesbt, csp->_cr_cursor, csp->cr_tag, cc128_get_lvbits(csp), &tmp);
    tmp.cr_extra = csp->cr_extra;
    if (!cc128_raw_equal(&tmp, csp)) {
        return 0;
    }
    return 1;
}


extern void cc128_update_ebt(cc128_cap_t* csp, cc128_addr_t new_ebt) {
    csp->cr_pesbt = (csp->cr_pesbt & ~CC128_FIELD_EBT_MASK64) | new_ebt;
    csp->cr_exp = cc128_extract_bounds_bits(new_ebt).E;
}






extern cc128_addr_t cc128_compress_raw(const cc128_cap_t* csp) {


    ((void) sizeof (((!csp->cr_tag || (csp->cr_bounds_valid && cc128_reserved_bits_valid(csp))) && "Malformed bounds or unknown reserved bits in tagged capability") ? 1 : 0), __extension__ ({ if ((!csp->cr_tag || (csp->cr_bounds_valid && cc128_reserved_bits_valid(csp))) && "Malformed bounds or unknown reserved bits in tagged capability") ; else __assert_fail ("(!csp->cr_tag || (csp->cr_bounds_valid && cc128_reserved_bits_valid(csp))) && \"Malformed bounds or unknown reserved bits in tagged capability\"", "./cheri_compressed_cap_common.h", 571, __extension__ __PRETTY_FUNCTION__); }));


    ((void) sizeof ((cc128_pesbt_is_correct(csp) && "capability bounds were modified without updating pesbt") ? 1 : 0), __extension__ ({ if (cc128_pesbt_is_correct(csp) && "capability bounds were modified without updating pesbt") ; else __assert_fail ("cc128_pesbt_is_correct(csp) && \"capability bounds were modified without updating pesbt\"", "./cheri_compressed_cap_common.h", 573, __extension__ __PRETTY_FUNCTION__); }));
    return csp->cr_pesbt;
}

extern cc128_addr_t cc128_compress_mem(const cc128_cap_t* csp) {
    return cc128_compress_raw(csp) ^ CC128_MEM_XOR_MASK;
}

static _Bool cc128__fast_is_representable_new_addr(const cc128_cap_t* cap, cc128_addr_t new_addr);


extern _Bool cc128_is_representable_cap_exact(const cc128_cap_t* cap) {
    cc128_addr_t pesbt = cc128_compress_raw(cap);
    cc128_cap_t decompressed_cap;

    cc128_unsafe_decompress_raw(pesbt, cap->_cr_cursor, cap->cr_tag, cc128_get_lvbits(cap), &decompressed_cap);

    ((void) sizeof ((decompressed_cap._cr_cursor == cap->_cr_cursor) ? 1 : 0), __extension__ ({ if (decompressed_cap._cr_cursor == cap->_cr_cursor) ; else __assert_fail ("decompressed_cap._cr_cursor == cap->_cr_cursor", "./cheri_compressed_cap_common.h", 590, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((decompressed_cap.cr_pesbt == cap->cr_pesbt) ? 1 : 0), __extension__ ({ if (decompressed_cap.cr_pesbt == cap->cr_pesbt) ; else __assert_fail ("decompressed_cap.cr_pesbt == cap->cr_pesbt", "./cheri_compressed_cap_common.h", 591, __extension__ __PRETTY_FUNCTION__); }));

    if (decompressed_cap.cr_base != cap->cr_base || decompressed_cap._cr_top != cap->_cr_top) {
        return 0;
    }
    return 1;
}

extern uint32_t cc128_compute_ebt(cc128_addr_t req_base, cc128_length_t req_top, cc128_addr_t* alignment_mask,
                                          _Bool* exact) {
# 609 "./cheri_compressed_cap_common.h"
    ((void) sizeof ((req_base <= req_top && "Cannot invert base and top") ? 1 : 0), __extension__ ({ if (req_base <= req_top && "Cannot invert base and top") ; else __assert_fail ("req_base <= req_top && \"Cannot invert base and top\"", "./cheri_compressed_cap_common.h", 609, __extension__ __PRETTY_FUNCTION__); }));






    cc128_length_t req_length65 = req_top - req_base;
# 625 "./cheri_compressed_cap_common.h"
    uint8_t E = (uint8_t)cc128_get_exponent(req_length65);
    const uint64_t req_length64 = (uint64_t)req_length65;




    const _Bool InternalExponent = E != 0 || cc128_getbits(req_length64, CC128_FIELD_EXP_NONZERO_BOTTOM_SIZE + 1, 1);
    if (!InternalExponent) {






        uint32_t ebt_bits = ((uint64_t)((0) & CC128_FIELD_INTERNAL_EXPONENT_MAX_VALUE) << CC128_FIELD_INTERNAL_EXPONENT_START) | ((uint64_t)((req_top) & CC128_FIELD_EXP_ZERO_TOP_MAX_VALUE) << CC128_FIELD_EXP_ZERO_TOP_START) |
                            ((uint64_t)((req_base) & CC128_FIELD_EXP_ZERO_BOTTOM_MAX_VALUE) << CC128_FIELD_EXP_ZERO_BOTTOM_START);
# 667 "./cheri_compressed_cap_common.h"
        if (alignment_mask)
            *alignment_mask = (18446744073709551615UL);
        *exact = 1;
        return ebt_bits;
    }
# 680 "./cheri_compressed_cap_common.h"
    cc128_addr_t bot_ie = cc128_truncate64(req_base >> (E + CC128_FIELD_EXPONENT_LOW_PART_SIZE), CC128_FIELD_EXP_NONZERO_BOTTOM_SIZE);
    if (alignment_mask) {
        *alignment_mask = (18446744073709551615UL) << (E + CC128_FIELD_EXPONENT_LOW_PART_SIZE);
    }
    cc128_addr_t top_ie = cc128_truncate64((cc128_addr_t)(req_top >> (E + CC128_FIELD_EXPONENT_LOW_PART_SIZE)), CC128_FIELD_EXP_NONZERO_BOTTOM_SIZE);







    const cc128_length_t maskLo = (((cc128_length_t)1u) << (E + CC128_FIELD_EXPONENT_LOW_PART_SIZE)) - 1;
    const cc128_length_t zero65 = 0;
    _Bool lostSignificantBase = (req_base & maskLo) != zero65;
    _Bool lostSignificantTop = (req_top & maskLo) != zero65;





    if (lostSignificantTop) {
        top_ie = cc128_truncate64(top_ie + 1, CC128_FIELD_EXP_NONZERO_BOTTOM_SIZE);
    }
# 719 "./cheri_compressed_cap_common.h"
    const cc128_addr_t len_ie = cc128_truncate64(top_ie - bot_ie, CC128_FIELD_EXP_NONZERO_BOTTOM_SIZE);
    _Bool incE = 0;
    if (cc128_getbits(len_ie, CC128_FIELD_EXP_NONZERO_BOTTOM_SIZE - 1, 1)) {
        incE = 1;
        lostSignificantBase = lostSignificantBase || cc128_getbits(bot_ie, 0, 1);
        lostSignificantTop = lostSignificantTop || cc128_getbits(top_ie, 0, 1);
        bot_ie = cc128_truncate64(req_base >> (E + CC128_FIELD_EXPONENT_LOW_PART_SIZE + 1), CC128_FIELD_EXP_NONZERO_BOTTOM_SIZE);

        if (alignment_mask) {
            *alignment_mask = (18446744073709551615UL) << (E + CC128_FIELD_EXPONENT_LOW_PART_SIZE + 1);
        }
        const _Bool incT = lostSignificantTop;
        top_ie = cc128_truncate64((cc128_addr_t)(req_top >> (E + CC128_FIELD_EXPONENT_LOW_PART_SIZE + 1)), CC128_FIELD_EXP_NONZERO_BOTTOM_SIZE);
        if (incT) {
            top_ie = cc128_truncate64(top_ie + 1, CC128_FIELD_EXP_NONZERO_BOTTOM_SIZE);
        }
    }
    const uint8_t newE = E + (incE ? 1 : 0);

    *exact = !lostSignificantBase && !lostSignificantTop;

    const cc128_addr_t expBits = ((uint64_t)(((newE) >> CC128_FIELD_EXPONENT_LOW_PART_SIZE) & CC128_FIELD_EXPONENT_HIGH_PART_MAX_VALUE) << CC128_FIELD_EXPONENT_HIGH_PART_START) | ((uint64_t)((newE) & CC128_FIELD_EXPONENT_LOW_PART_MAX_VALUE) << CC128_FIELD_EXPONENT_LOW_PART_START);
    return expBits | ((uint64_t)((1) & CC128_FIELD_INTERNAL_EXPONENT_MAX_VALUE) << CC128_FIELD_INTERNAL_EXPONENT_START) | ((uint64_t)((top_ie) & CC128_FIELD_EXP_NONZERO_TOP_MAX_VALUE) << CC128_FIELD_EXP_NONZERO_TOP_START) |
           ((uint64_t)((bot_ie) & CC128_FIELD_EXP_NONZERO_BOTTOM_MAX_VALUE) << CC128_FIELD_EXP_NONZERO_BOTTOM_START);
}

extern _Bool cc128__precise_is_representable_new_addr(const cc128_cap_t* oldcap, cc128_addr_t new_cursor) {

    cc128_cap_t newcap = *oldcap;
    newcap._cr_cursor = new_cursor;
    struct cc128_bounds_bits old_bounds_bits = cc128_extract_bounds_bits(cc128_compress_raw(oldcap));
    newcap.cr_bounds_valid = cc128_compute_base_top(old_bounds_bits, new_cursor, &newcap.cr_base, &newcap._cr_top);
    return newcap.cr_base == oldcap->cr_base && newcap._cr_top == oldcap->_cr_top && newcap.cr_bounds_valid &&
           oldcap->cr_bounds_valid;
}

extern _Bool cc128_cap_bounds_uses_value_for_exp(uint8_t exponent) {
    return exponent < (sizeof(cc128_addr_t) * 8) - CC128_FIELD_BOTTOM_ENCODED_SIZE;
}


extern _Bool cc128_cap_bounds_uses_value(const cc128_cap_t* cap) {

    ((void) sizeof ((cc128_pesbt_is_correct(cap)) ? 1 : 0), __extension__ ({ if (cc128_pesbt_is_correct(cap)) ; else __assert_fail ("cc128_pesbt_is_correct(cap)", "./cheri_compressed_cap_common.h", 762, __extension__ __PRETTY_FUNCTION__); }));
    return cc128_cap_bounds_uses_value_for_exp(cap->cr_exp);
}

extern _Bool cc128_cap_sign_change(cc128_addr_t addr1, cc128_addr_t addr2) {



    (void)addr1;
    (void)addr2;
    return 0;

}

extern _Bool cc128_cap_sign_change_causes_unrepresentability(const cc128_cap_t* cap, cc128_addr_t addr1,
                                                                    cc128_addr_t addr2) {
    return cc128_cap_sign_change(addr1, addr2) && cc128_cap_bounds_uses_value(cap);
}

extern _Bool cc128_is_representable_with_addr(const cc128_cap_t* cap, cc128_addr_t new_addr,
                                                     _Bool precise_representable_check) {
# 794 "./cheri_compressed_cap_common.h"
    cc128_addr_t extended_cursor = cc128_cap_bounds_address(new_addr);

    if (__builtin_expect(extended_cursor >= cap->cr_base && extended_cursor < cap->_cr_top, 1)) {
        return 1;
    }
    if (precise_representable_check) {
        return cc128__precise_is_representable_new_addr(cap, new_addr);
    } else {
        return cc128__fast_is_representable_new_addr(cap, new_addr);
    }
}



extern void cc128_set_addr(cc128_cap_t* cap, cc128_addr_t new_addr) {
    if (cap->cr_tag && cc128_is_cap_sealed(cap)) {
        cap->cr_tag = 0;
    }
    if (!cc128_is_representable_with_addr(cap, new_addr, 0)) {

        cap->cr_tag = 0;
        cc128_decompress_raw(cap->cr_pesbt, new_addr, 0, cap);
    } else {
        cap->_cr_cursor = new_addr;
    }
}

static _Bool cc128__fast_is_representable_new_addr(const cc128_cap_t* cap, cc128_addr_t new_addr) {
    if (cap->_cr_top == ((cc128_length_t)1u << 64) && cap->cr_base == 0) {
        return 1;
    }




    struct cc128_bounds_bits bounds = cc128_extract_bounds_bits(cap->cr_pesbt);

    cc128_addr_t inc = cc128_cap_bounds_address(new_addr - cap->_cr_cursor);
    cc128_addr_t cursor = cc128_cap_bounds_address(cap->_cr_cursor);


    size_t i_top_shift = bounds.E + 14;
    if (i_top_shift >= 64) {
        i_top_shift = 64 - 1;
    }
    size_t e_shift = bounds.E >= 64 ? 64 - 1 : bounds.E;
    cc128_saddr_t i_top = (cc128_saddr_t)inc >> i_top_shift;
    cc128_addr_t i_mid = cc128_truncate_addr((cc128_addr_t)inc >> e_shift, 14);
    cc128_addr_t a_mid = cc128_truncate_addr((cc128_addr_t)cursor >> e_shift, 14);
    cc128_addr_t B3 = (cc128_addr_t)cc128_truncateLSB_14(bounds.B, 3);
    cc128_addr_t R3 = cc128_truncate_addr(B3 - 1, 3);
    cc128_addr_t R = cc128_truncate_addr(R3 << (14 - 3), 14);
    cc128_addr_t diff = cc128_truncate_addr(R - a_mid, 14);
    cc128_addr_t diff1 = cc128_truncate_addr(diff - 1, 14);



    _Bool inLimits;
    if (i_top == 0) {
        inLimits = i_mid < diff1;
    } else if (i_top == (cc128_saddr_t)-1) {
        inLimits = i_mid >= diff && R != a_mid;
    } else {
        inLimits = 0;
    }
    return inLimits || bounds.E >= 52 - 2;

}


extern _Bool cc128_setbounds_impl(cc128_cap_t* cap, cc128_length_t req_len, cc128_addr_t* alignment_mask) {
    uint64_t req_base = cap->_cr_cursor;
    if (cc128_is_cap_sealed(cap)) {
        cap->cr_tag = 0;
    }
# 881 "./cheri_compressed_cap_common.h"
    cc128_length_t req_top = (cc128_length_t)req_base + req_len;
    ((void) sizeof ((req_base <= req_top && "Cannot invert base and top") ? 1 : 0), __extension__ ({ if (req_base <= req_top && "Cannot invert base and top") ; else __assert_fail ("req_base <= req_top && \"Cannot invert base and top\"", "./cheri_compressed_cap_common.h", 882, __extension__ __PRETTY_FUNCTION__); }));

    if (req_base < cap->cr_base || req_top > cap->_cr_top) {
        cap->cr_tag = 0;
    }




    _Static_assert(CC128_FIELD_EXPONENT_LOW_PART_SIZE == 3, "expected 3 bits to be used by");
    _Static_assert(CC128_FIELD_EXPONENT_HIGH_PART_SIZE == 3, "expected 3 bits to be used by");






    _Bool exact = 0;
    uint32_t new_ebt = cc128_compute_ebt(req_base, req_top, alignment_mask, &exact);
    cc128_addr_t new_base;
    cc128_length_t new_top;
    _Bool new_bounds_valid = cc128_compute_base_top(cc128_extract_bounds_bits(((uint64_t)((new_ebt) & CC128_FIELD_EBT_MAX_VALUE) << CC128_FIELD_EBT_START)),
                                                    cap->_cr_cursor, &new_base, &new_top);
    if (exact) {




        ((void) sizeof ((new_base == req_base && "Should be exact") ? 1 : 0), __extension__ ({ if (new_base == req_base && "Should be exact") ; else __assert_fail ("new_base == req_base && \"Should be exact\"", "./cheri_compressed_cap_common.h", 910, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((new_top == req_top && "Should be exact") ? 1 : 0), __extension__ ({ if (new_top == req_top && "Should be exact") ; else __assert_fail ("new_top == req_top && \"Should be exact\"", "./cheri_compressed_cap_common.h", 911, __extension__ __PRETTY_FUNCTION__); }));

    } else {
        ((void) sizeof (((new_base != req_base || new_top != req_top) && "Was inexact, but neither base nor top different?") ? 1 : 0), __extension__ ({ if ((new_base != req_base || new_top != req_top) && "Was inexact, but neither base nor top different?") ; else __assert_fail ("(new_base != req_base || new_top != req_top) && \"Was inexact, but neither base nor top different?\"", "./cheri_compressed_cap_common.h", 915, __extension__ __PRETTY_FUNCTION__); }));

    }







    if (cap->cr_tag) {




        ((void) sizeof ((new_top >= new_base) ? 1 : 0), __extension__ ({ if (new_top >= new_base) ; else __assert_fail ("new_top >= new_base", "./cheri_compressed_cap_common.h", 929, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((cc128_reserved_bits_valid(cap) && "Unknown reserved bits set in tagged capability") ? 1 : 0), __extension__ ({ if (cc128_reserved_bits_valid(cap) && "Unknown reserved bits set in tagged capability") ; else __assert_fail ("cc128_reserved_bits_valid(cap) && \"Unknown reserved bits set in tagged capability\"", "./cheri_compressed_cap_common.h", 930, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((new_bounds_valid && "Malformed bounds in tagged capability") ? 1 : 0), __extension__ ({ if (new_bounds_valid && "Malformed bounds in tagged capability") ; else __assert_fail ("new_bounds_valid && \"Malformed bounds in tagged capability\"", "./cheri_compressed_cap_common.h", 931, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((new_base >= cap->cr_base && "Cannot reduce base on tagged capabilities") ? 1 : 0), __extension__ ({ if (new_base >= cap->cr_base && "Cannot reduce base on tagged capabilities") ; else __assert_fail ("new_base >= cap->cr_base && \"Cannot reduce base on tagged capabilities\"", "./cheri_compressed_cap_common.h", 932, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((new_top <= cap->_cr_top && "Cannot increase top on tagged capabilities") ? 1 : 0), __extension__ ({ if (new_top <= cap->_cr_top && "Cannot increase top on tagged capabilities") ; else __assert_fail ("new_top <= cap->_cr_top && \"Cannot increase top on tagged capabilities\"", "./cheri_compressed_cap_common.h", 933, __extension__ __PRETTY_FUNCTION__); }));
    }
    cap->cr_base = new_base;
    cap->_cr_top = new_top;
    cc128_update_ebt(cap, new_ebt);
    cap->cr_bounds_valid = new_bounds_valid;
    return exact;
}


extern _Bool cc128_setbounds(cc128_cap_t* cap, cc128_length_t req_len) {
    __attribute__((unused)) cc128_addr_t old_base = cap->cr_base;
    __attribute__((unused)) cc128_length_t old_top = cap->_cr_top;
    __attribute__((unused)) cc128_addr_t req_base =
        cc128_cap_bounds_uses_value(cap) ? cc128_cap_bounds_address(cap->_cr_cursor) : cap->_cr_cursor;
    __attribute__((unused)) cc128_length_t req_top = req_len + req_base;
    _Bool exact = cc128_setbounds_impl(cap, req_len, ((void*)0));
    if (cap->cr_tag) {

        ((void) sizeof ((!cc128_is_cap_sealed(cap) && "result cannot be sealed and tagged") ? 1 : 0), __extension__ ({ if (!cc128_is_cap_sealed(cap) && "result cannot be sealed and tagged") ; else __assert_fail ("!cc128_is_cap_sealed(cap) && \"result cannot be sealed and tagged\"", "./cheri_compressed_cap_common.h", 952, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((((cap->_cr_top - cap->cr_base) >> 64) <= 1 && "length must be smaller than 1 << 65") ? 1 : 0), __extension__ ({ if (((cap->_cr_top - cap->cr_base) >> 64) <= 1 && "length must be smaller than 1 << 65") ; else __assert_fail ("((cap->_cr_top - cap->cr_base) >> 64) <= 1 && \"length must be smaller than 1 << 65\"", "./cheri_compressed_cap_common.h", 954, __extension__ __PRETTY_FUNCTION__); }));

        ((void) sizeof ((cap->cr_base >= old_base && "cannot remain tagged if base was decreased") ? 1 : 0), __extension__ ({ if (cap->cr_base >= old_base && "cannot remain tagged if base was decreased") ; else __assert_fail ("cap->cr_base >= old_base && \"cannot remain tagged if base was decreased\"", "./cheri_compressed_cap_common.h", 955, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((cap->_cr_top <= old_top && "cannot remain tagged if top was increased") ? 1 : 0), __extension__ ({ if (cap->_cr_top <= old_top && "cannot remain tagged if top was increased") ; else __assert_fail ("cap->_cr_top <= old_top && \"cannot remain tagged if top was increased\"", "./cheri_compressed_cap_common.h", 956, __extension__ __PRETTY_FUNCTION__); }));


        ((void) sizeof (((cap->_cr_top <= ((cc128_length_t)1u << 64) || old_top > ((cc128_length_t)1u << 64)) && "cannot remain tagged if new top greater 1 << 65") ? 1 : 0), __extension__ ({ if ((cap->_cr_top <= ((cc128_length_t)1u << 64) || old_top > ((cc128_length_t)1u << 64)) && "cannot remain tagged if new top greater 1 << 65") ; else __assert_fail ("(cap->_cr_top <= ((cc128_length_t)1u << 64) || old_top > ((cc128_length_t)1u << 64)) && \"cannot remain tagged if new top greater 1 << 65\"", "./cheri_compressed_cap_common.h", 960, __extension__ __PRETTY_FUNCTION__); }));

    }

    if (exact) {
        ((void) sizeof ((cc128_cap_bounds_address(cap->cr_base) == cc128_cap_bounds_address(req_base) && "base changed but still reported exact") ? 1 : 0), __extension__ ({ if (cc128_cap_bounds_address(cap->cr_base) == cc128_cap_bounds_address(req_base) && "base changed but still reported exact") ; else __assert_fail ("cc128_cap_bounds_address(cap->cr_base) == cc128_cap_bounds_address(req_base) && \"base changed but still reported exact\"", "./cheri_compressed_cap_common.h", 965, __extension__ __PRETTY_FUNCTION__); }));

        ((void) sizeof ((cc128_cap_bounds_address(cap->_cr_top) == cc128_cap_bounds_address(req_top) && "top changed but still reported exact") ? 1 : 0), __extension__ ({ if (cc128_cap_bounds_address(cap->_cr_top) == cc128_cap_bounds_address(req_top) && "top changed but still reported exact") ; else __assert_fail ("cc128_cap_bounds_address(cap->_cr_top) == cc128_cap_bounds_address(req_top) && \"top changed but still reported exact\"", "./cheri_compressed_cap_common.h", 967, __extension__ __PRETTY_FUNCTION__); }));

    } else {
        ((void) sizeof (((cap->_cr_top != req_top || cap->cr_base != req_base) && "result is exact but reported inexact") ? 1 : 0), __extension__ ({ if ((cap->_cr_top != req_top || cap->cr_base != req_base) && "result is exact but reported inexact") ; else __assert_fail ("(cap->_cr_top != req_top || cap->cr_base != req_base) && \"result is exact but reported inexact\"", "./cheri_compressed_cap_common.h", 970, __extension__ __PRETTY_FUNCTION__); }));

    }
    return exact;
}


extern _Bool cc128_checked_setbounds(cc128_cap_t* cap, cc128_length_t req_len) {
    __attribute__((unused)) cc128_addr_t req_base =
        cc128_cap_bounds_uses_value(cap) ? cc128_cap_bounds_address(cap->_cr_cursor) : cap->_cr_cursor;
    __attribute__((unused)) cc128_length_t req_top = req_len + req_base;
    if (cap->cr_tag) {

        ((void) sizeof (((!cc128_is_cap_sealed(cap)) && "cannot be used on tagged sealed capabilities") ? 1 : 0), __extension__ ({ if ((!cc128_is_cap_sealed(cap)) && "cannot be used on tagged sealed capabilities") ; else __assert_fail ("(!cc128_is_cap_sealed(cap)) && \"cannot be used on tagged sealed capabilities\"", "./cheri_compressed_cap_common.h", 982, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((req_base >= cap->cr_base) && "cannot decrease base on tagged capabilities") ? 1 : 0), __extension__ ({ if ((req_base >= cap->cr_base) && "cannot decrease base on tagged capabilities") ; else __assert_fail ("(req_base >= cap->cr_base) && \"cannot decrease base on tagged capabilities\"", "./cheri_compressed_cap_common.h", 983, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((req_top <= cap->_cr_top) && "cannot increase top on tagged capabilities") ? 1 : 0), __extension__ ({ if ((req_top <= cap->_cr_top) && "cannot increase top on tagged capabilities") ; else __assert_fail ("(req_top <= cap->_cr_top) && \"cannot increase top on tagged capabilities\"", "./cheri_compressed_cap_common.h", 984, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((req_len < ((cc128_length_t)1u << 64)) && "requested length must be smaller than max length") ? 1 : 0), __extension__ ({ if ((req_len < ((cc128_length_t)1u << 64)) && "requested length must be smaller than max length") ; else __assert_fail ("(req_len < ((cc128_length_t)1u << 64)) && \"requested length must be smaller than max length\"", "./cheri_compressed_cap_common.h", 985, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((req_top < ((cc128_length_t)1u << 64)) && "new top must be smaller than max length") ? 1 : 0), __extension__ ({ if ((req_top < ((cc128_length_t)1u << 64)) && "new top must be smaller than max length") ; else __assert_fail ("(req_top < ((cc128_length_t)1u << 64)) && \"new top must be smaller than max length\"", "./cheri_compressed_cap_common.h", 986, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((cap->_cr_top <= ((cc128_length_t)1u << 64)) && "input capability top must be less than max top") ? 1 : 0), __extension__ ({ if ((cap->_cr_top <= ((cc128_length_t)1u << 64)) && "input capability top must be less than max top") ; else __assert_fail ("(cap->_cr_top <= ((cc128_length_t)1u << 64)) && \"input capability top must be less than max top\"", "./cheri_compressed_cap_common.h", 987, __extension__ __PRETTY_FUNCTION__); }));
    }
    return cc128_setbounds(cap, req_len);
}


extern cc128_cap_t cc128__make_max_perms_cap_common(cc128_addr_t base, cc128_addr_t cursor, cc128_length_t top,
                                                          __attribute__((unused)) uint8_t lvbits) {
    cc128_cap_t creg;
    memset(&creg, 0, sizeof(creg));
    ((void) sizeof ((base <= top && "Invalid arguments") ? 1 : 0), __extension__ ({ if (base <= top && "Invalid arguments") ; else __assert_fail ("base <= top && \"Invalid arguments\"", "./cheri_compressed_cap_common.h", 997, __extension__ __PRETTY_FUNCTION__); }));
    creg.cr_base = base;
    creg._cr_cursor = cursor;
    creg.cr_bounds_valid = 1;
    creg._cr_top = top;
    creg.cr_pesbt = (((uint64_t)(((0xf)) & CC128_FIELD_UPERMS_MAX_VALUE) << CC128_FIELD_UPERMS_START) | ((uint64_t)(((0xfff)) & CC128_FIELD_HWPERMS_MAX_VALUE) << CC128_FIELD_HWPERMS_START)) | ((uint64_t)((CC128_OTYPE_UNSEALED) & CC128_FIELD_OTYPE_MAX_VALUE) << CC128_FIELD_OTYPE_START);
    creg.cr_tag = 1;
    creg.cr_exp = CC128_RESET_EXP;
    ((void) sizeof ((lvbits <= 1 && "We only support local-global levels.") ? 1 : 0), __extension__ ({ if (lvbits <= 1 && "We only support local-global levels.") ; else __assert_fail ("lvbits <= 1 && \"We only support local-global levels.\"", "./cheri_compressed_cap_common.h", 1005, __extension__ __PRETTY_FUNCTION__); }));



    _Bool exact_input = 0;
    cc128_update_ebt(&creg, cc128_compute_ebt(creg.cr_base, creg._cr_top, ((void*)0), &exact_input));
    ((void) sizeof ((exact_input && "Invalid arguments") ? 1 : 0), __extension__ ({ if (exact_input && "Invalid arguments") ; else __assert_fail ("exact_input && \"Invalid arguments\"", "./cheri_compressed_cap_common.h", 1011, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((cc128_is_representable_cap_exact(&creg)) ? 1 : 0), __extension__ ({ if (cc128_is_representable_cap_exact(&creg)) ; else __assert_fail ("_cc_N(is_representable_cap_exact)(&creg)", "./cheri_compressed_cap_common.h", 1012, __extension__ __PRETTY_FUNCTION__); }));
    return creg;
}




extern cc128_cap_t cc128_make_max_perms_cap_ext(cc128_addr_t base, cc128_addr_t cursor, cc128_length_t top,
                                                      CC128_Mode mode, uint8_t lvbits) {
    cc128_cap_t creg = cc128__make_max_perms_cap_common(base, cursor, top, lvbits);
    _Bool mode_valid = cc128_set_execution_mode(&creg, mode);
    ((void) sizeof ((mode_valid && "Could not set mode on max perms cap") ? 1 : 0), __extension__ ({ if (mode_valid && "Could not set mode on max perms cap") ; else __assert_fail ("mode_valid && \"Could not set mode on max perms cap\"", "./cheri_compressed_cap_common.h", 1023, __extension__ __PRETTY_FUNCTION__); }));
    return creg;
}
extern cc128_cap_t cc128_make_max_perms_cap(cc128_addr_t base, cc128_addr_t cursor, cc128_length_t top) {
    return cc128_make_max_perms_cap_ext(base, cursor, top, CC128_MODE_INT, 1);
}







extern cc128_addr_t cc128_get_alignment_mask(cc128_addr_t req_length) {
    if (req_length == 0) {



        return (18446744073709551615UL);
    }


    cc128_cap_t tmpcap = cc128_make_max_perms_cap(0, 0, ((cc128_length_t)1u << 64));
    cc128_addr_t mask = 0;
    cc128_setbounds_impl(&tmpcap, req_length, &mask);
    return mask;
}

extern cc128_cap_t cc128_make_null_derived_cap_ext(cc128_addr_t addr, __attribute__((unused)) uint8_t lvbits) {
    cc128_cap_t creg;
    memset(&creg, 0, sizeof(creg));
    creg._cr_cursor = addr;
    creg._cr_top = ((cc128_length_t)1u << 64);
    creg.cr_pesbt = CC128_NULL_PESBT;
    creg.cr_bounds_valid = 1;
    creg.cr_exp = CC128_NULL_EXP;
    ((void) sizeof ((cc128_is_representable_cap_exact(&creg)) ? 1 : 0), __extension__ ({ if (cc128_is_representable_cap_exact(&creg)) ; else __assert_fail ("cc128_is_representable_cap_exact(&creg)", "./cheri_compressed_cap_common.h", 1059, __extension__ __PRETTY_FUNCTION__); }));



    return creg;
}

extern cc128_cap_t cc128_make_null_derived_cap(cc128_addr_t addr) {
    return cc128_make_null_derived_cap_ext(addr, 1);
}

extern cc128_addr_t cc128_get_required_alignment(cc128_addr_t req_length) {


    return ~cc128_get_alignment_mask(req_length) + 1;
}

extern cc128_addr_t cc128_get_representable_length(cc128_addr_t req_length) {
    cc128_addr_t mask = cc128_get_alignment_mask(req_length);
    return (req_length + ~mask) & mask;
}
# 165 "./cheri_compressed_cap_128.h" 2
# 1 "./cheri_compressed_cap_v9_common.h" 1



extern cc128_addr_t cc128_get_all_permissions(const cc128_cap_t* cap) {
    return ((cc128_addr_t)(cc128_getbits((cap->cr_pesbt), CC128_FIELD_UPERMS_START, CC128_FIELD_UPERMS_SIZE) & (0xf)) << (15)) |
           (cc128_getbits((cap->cr_pesbt), CC128_FIELD_HWPERMS_START, CC128_FIELD_HWPERMS_SIZE) & (0xfff));
}
extern _Bool cc128_set_permissions(cc128_cap_t* cap, cc128_addr_t permissions) {
    ((void) sizeof ((((permissions & ((0xfff) | ((0xf) << (15)))) == permissions) && "invalid permissions") ? 1 : 0), __extension__ ({ if (((permissions & ((0xfff) | ((0xf) << (15)))) == permissions) && "invalid permissions") ; else __assert_fail ("((permissions & ((0xfff) | ((0xf) << (15)))) == permissions) && \"invalid permissions\"", "./cheri_compressed_cap_v9_common.h", 9, __extension__ __PRETTY_FUNCTION__); }));
    cc128_addr_t arch_perms = permissions & (0xfff);
    cc128_addr_t sw_perms = (permissions >> (15)) & (0xf);
    cap->cr_pesbt = __extension__({ ((void) sizeof ((arch_perms <= CC128_FIELD_HWPERMS_MAX_VALUE) ? 1 : 0), __extension__ ({ if (arch_perms <= CC128_FIELD_HWPERMS_MAX_VALUE) ; else __assert_fail ("arch_perms <= CC128_FIELD_HWPERMS_MAX_VALUE", "./cheri_compressed_cap_v9_common.h", 12, __extension__ __PRETTY_FUNCTION__); })); ((cap->cr_pesbt) & ~CC128_FIELD_HWPERMS_MASK64) | ((uint64_t)((arch_perms) & CC128_FIELD_HWPERMS_MAX_VALUE) << CC128_FIELD_HWPERMS_START); });
    cap->cr_pesbt = __extension__({ ((void) sizeof ((sw_perms <= CC128_FIELD_UPERMS_MAX_VALUE) ? 1 : 0), __extension__ ({ if (sw_perms <= CC128_FIELD_UPERMS_MAX_VALUE) ; else __assert_fail ("sw_perms <= CC128_FIELD_UPERMS_MAX_VALUE", "./cheri_compressed_cap_v9_common.h", 13, __extension__ __PRETTY_FUNCTION__); })); ((cap->cr_pesbt) & ~CC128_FIELD_UPERMS_MASK64) | ((uint64_t)((sw_perms) & CC128_FIELD_UPERMS_MAX_VALUE) << CC128_FIELD_UPERMS_START); });
    return 1;
}

extern CC128_Mode cc128_get_execution_mode(const cc128_cap_t* cap) {
    return (CC128_Mode)cc128_getbits((cap->cr_pesbt), CC128_FIELD_FLAGS_START, CC128_FIELD_FLAGS_SIZE);
}
extern _Bool cc128_set_execution_mode(cc128_cap_t* cap, CC128_Mode new_mode) {

    cap->cr_pesbt = __extension__({ ((void) sizeof (((unsigned)new_mode <= CC128_FIELD_FLAGS_MAX_VALUE) ? 1 : 0), __extension__ ({ if ((unsigned)new_mode <= CC128_FIELD_FLAGS_MAX_VALUE) ; else __assert_fail ("(unsigned)new_mode <= CC128_FIELD_FLAGS_MAX_VALUE", "./cheri_compressed_cap_v9_common.h", 22, __extension__ __PRETTY_FUNCTION__); })); ((cap->cr_pesbt) & ~CC128_FIELD_FLAGS_MASK64) | ((uint64_t)(((unsigned)new_mode) & CC128_FIELD_FLAGS_MAX_VALUE) << CC128_FIELD_FLAGS_START); });
    return 1;
}

extern cc128_addr_t cc128_get_reserved(const cc128_cap_t* cap) {
    return cap->cr_pesbt & CC128_FIELD_RESERVED_MASK64;
}

enum { CC128_PERMS_RESERVED_ONES = 0 };
# 166 "./cheri_compressed_cap_128.h" 2


_Static_assert((CC128_MEM_XOR_MASK) == (0x00001ffffc018004UL), "");

__attribute__((deprecated("Use cc128_compress_raw"))) extern uint64_t
compress_128cap_without_xor(const cc128_cap_t* csp) {
    return cc128_compress_raw(csp);
}

__attribute__((deprecated("Use cc128_compress_mem"))) extern uint64_t compress_128cap(const cc128_cap_t* csp) {
    return cc128_compress_mem(csp);
}

__attribute__((deprecated("Use cc128_decompress_raw"))) extern void
decompress_128cap_already_xored(uint64_t pesbt, uint64_t cursor, cc128_cap_t* cdp) {
    cc128_decompress_raw(pesbt, cursor, cdp->cr_tag, cdp);
}

__attribute__((deprecated("Use cc128_decompress_mem"))) extern void
decompress_128cap(uint64_t pesbt, uint64_t cursor, cc128_cap_t* cdp) {
    cc128_decompress_mem(pesbt, cursor, cdp->cr_tag, cdp);
}
# 52 "./cheri_compressed_cap.h" 2
# 1 "./cheri_compressed_cap_128m.h" 1
# 85 "./cheri_compressed_cap_128m.h"
__extension__ typedef unsigned __int128 cc128m_length_t;
__extension__ typedef signed __int128 cc128m_offset_t;
typedef uint64_t cc128m_addr_t;
typedef int64_t cc128m_saddr_t;
# 1 "./cheri_compressed_cap_macros.h" 1
# 90 "./cheri_compressed_cap_128m.h" 2


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
enum {
    CC128M_FIELD_ALL_PERMS_START = (110 - 64), CC128M_FIELD_ALL_PERMS_LAST = (127 - 64), CC128M_FIELD_ALL_PERMS_SIZE = CC128M_FIELD_ALL_PERMS_LAST - CC128M_FIELD_ALL_PERMS_START + 1, CC128M_FIELD_ALL_PERMS_MASK_NOT_SHIFTED = ((1UL << (CC128M_FIELD_ALL_PERMS_SIZE)) - 1UL), CC128M_FIELD_ALL_PERMS_MASK64 = (uint64_t)CC128M_FIELD_ALL_PERMS_MASK_NOT_SHIFTED << CC128M_FIELD_ALL_PERMS_START, CC128M_FIELD_ALL_PERMS_MAX_VALUE = CC128M_FIELD_ALL_PERMS_MASK_NOT_SHIFTED,
    CC128M_FIELD_HWPERMS_START = (110 - 64), CC128M_FIELD_HWPERMS_LAST = (127 - 64), CC128M_FIELD_HWPERMS_SIZE = CC128M_FIELD_HWPERMS_LAST - CC128M_FIELD_HWPERMS_START + 1, CC128M_FIELD_HWPERMS_MASK_NOT_SHIFTED = ((1UL << (CC128M_FIELD_HWPERMS_SIZE)) - 1UL), CC128M_FIELD_HWPERMS_MASK64 = (uint64_t)CC128M_FIELD_HWPERMS_MASK_NOT_SHIFTED << CC128M_FIELD_HWPERMS_START, CC128M_FIELD_HWPERMS_MAX_VALUE = CC128M_FIELD_HWPERMS_MASK_NOT_SHIFTED,

    CC128M_FIELD_UPERMS_START = (112 - 64), CC128M_FIELD_UPERMS_LAST = (115 - 64), CC128M_FIELD_UPERMS_SIZE = CC128M_FIELD_UPERMS_LAST - CC128M_FIELD_UPERMS_START + 1, CC128M_FIELD_UPERMS_MASK_NOT_SHIFTED = ((1UL << (CC128M_FIELD_UPERMS_SIZE)) - 1UL), CC128M_FIELD_UPERMS_MASK64 = (uint64_t)CC128M_FIELD_UPERMS_MASK_NOT_SHIFTED << CC128M_FIELD_UPERMS_START, CC128M_FIELD_UPERMS_MAX_VALUE = CC128M_FIELD_UPERMS_MASK_NOT_SHIFTED,
    CC128M_FIELD_OTYPE_START = (95 - 64), CC128M_FIELD_OTYPE_LAST = (109 - 64), CC128M_FIELD_OTYPE_SIZE = CC128M_FIELD_OTYPE_LAST - CC128M_FIELD_OTYPE_START + 1, CC128M_FIELD_OTYPE_MASK_NOT_SHIFTED = ((1UL << (CC128M_FIELD_OTYPE_SIZE)) - 1UL), CC128M_FIELD_OTYPE_MASK64 = (uint64_t)CC128M_FIELD_OTYPE_MASK_NOT_SHIFTED << CC128M_FIELD_OTYPE_START, CC128M_FIELD_OTYPE_MAX_VALUE = CC128M_FIELD_OTYPE_MASK_NOT_SHIFTED,
    CC128M_FIELD_EBT_START = (64 - 64), CC128M_FIELD_EBT_LAST = (94 - 64), CC128M_FIELD_EBT_SIZE = CC128M_FIELD_EBT_LAST - CC128M_FIELD_EBT_START + 1, CC128M_FIELD_EBT_MASK_NOT_SHIFTED = ((1UL << (CC128M_FIELD_EBT_SIZE)) - 1UL), CC128M_FIELD_EBT_MASK64 = (uint64_t)CC128M_FIELD_EBT_MASK_NOT_SHIFTED << CC128M_FIELD_EBT_START, CC128M_FIELD_EBT_MAX_VALUE = CC128M_FIELD_EBT_MASK_NOT_SHIFTED,




    CC128M_FIELD_FLAGS_START = (65 - 64), CC128M_FIELD_FLAGS_LAST = (64 - 64), CC128M_FIELD_FLAGS_SIZE = CC128M_FIELD_FLAGS_LAST - CC128M_FIELD_FLAGS_START + 1, CC128M_FIELD_FLAGS_MASK_NOT_SHIFTED = ((1UL << (CC128M_FIELD_FLAGS_SIZE)) - 1UL), CC128M_FIELD_FLAGS_MASK64 = (uint64_t)CC128M_FIELD_FLAGS_MASK_NOT_SHIFTED << CC128M_FIELD_FLAGS_START, CC128M_FIELD_FLAGS_MAX_VALUE = CC128M_FIELD_FLAGS_MASK_NOT_SHIFTED,

    CC128M_FIELD_EXPONENT_ZERO_START = (94 - 64), CC128M_FIELD_EXPONENT_ZERO_LAST = (94 - 64), CC128M_FIELD_EXPONENT_ZERO_SIZE = CC128M_FIELD_EXPONENT_ZERO_LAST - CC128M_FIELD_EXPONENT_ZERO_START + 1, CC128M_FIELD_EXPONENT_ZERO_MASK_NOT_SHIFTED = ((1UL << (CC128M_FIELD_EXPONENT_ZERO_SIZE)) - 1UL), CC128M_FIELD_EXPONENT_ZERO_MASK64 = (uint64_t)CC128M_FIELD_EXPONENT_ZERO_MASK_NOT_SHIFTED << CC128M_FIELD_EXPONENT_ZERO_START, CC128M_FIELD_EXPONENT_ZERO_MAX_VALUE = CC128M_FIELD_EXPONENT_ZERO_MASK_NOT_SHIFTED,

    CC128M_FIELD_INTERNAL_EXPONENT_SIZE = CC128M_FIELD_EXPONENT_ZERO_SIZE,
    CC128M_FIELD_TOP_ENCODED_START = (80 - 64), CC128M_FIELD_TOP_ENCODED_LAST = (93 - 64), CC128M_FIELD_TOP_ENCODED_SIZE = CC128M_FIELD_TOP_ENCODED_LAST - CC128M_FIELD_TOP_ENCODED_START + 1, CC128M_FIELD_TOP_ENCODED_MASK_NOT_SHIFTED = ((1UL << (CC128M_FIELD_TOP_ENCODED_SIZE)) - 1UL), CC128M_FIELD_TOP_ENCODED_MASK64 = (uint64_t)CC128M_FIELD_TOP_ENCODED_MASK_NOT_SHIFTED << CC128M_FIELD_TOP_ENCODED_START, CC128M_FIELD_TOP_ENCODED_MAX_VALUE = CC128M_FIELD_TOP_ENCODED_MASK_NOT_SHIFTED,
    CC128M_FIELD_BOTTOM_ENCODED_START = (64 - 64), CC128M_FIELD_BOTTOM_ENCODED_LAST = (79 - 64), CC128M_FIELD_BOTTOM_ENCODED_SIZE = CC128M_FIELD_BOTTOM_ENCODED_LAST - CC128M_FIELD_BOTTOM_ENCODED_START + 1, CC128M_FIELD_BOTTOM_ENCODED_MASK_NOT_SHIFTED = ((1UL << (CC128M_FIELD_BOTTOM_ENCODED_SIZE)) - 1UL), CC128M_FIELD_BOTTOM_ENCODED_MASK64 = (uint64_t)CC128M_FIELD_BOTTOM_ENCODED_MASK_NOT_SHIFTED << CC128M_FIELD_BOTTOM_ENCODED_START, CC128M_FIELD_BOTTOM_ENCODED_MAX_VALUE = CC128M_FIELD_BOTTOM_ENCODED_MASK_NOT_SHIFTED,



    CC128M_FIELD_EXP_ZERO_TOP_START = (80 - 64), CC128M_FIELD_EXP_ZERO_TOP_LAST = (93 - 64), CC128M_FIELD_EXP_ZERO_TOP_SIZE = CC128M_FIELD_EXP_ZERO_TOP_LAST - CC128M_FIELD_EXP_ZERO_TOP_START + 1, CC128M_FIELD_EXP_ZERO_TOP_MASK_NOT_SHIFTED = ((1UL << (CC128M_FIELD_EXP_ZERO_TOP_SIZE)) - 1UL), CC128M_FIELD_EXP_ZERO_TOP_MASK64 = (uint64_t)CC128M_FIELD_EXP_ZERO_TOP_MASK_NOT_SHIFTED << CC128M_FIELD_EXP_ZERO_TOP_START, CC128M_FIELD_EXP_ZERO_TOP_MAX_VALUE = CC128M_FIELD_EXP_ZERO_TOP_MASK_NOT_SHIFTED,
    CC128M_FIELD_EXP_ZERO_BOTTOM_START = (64 - 64), CC128M_FIELD_EXP_ZERO_BOTTOM_LAST = (79 - 64), CC128M_FIELD_EXP_ZERO_BOTTOM_SIZE = CC128M_FIELD_EXP_ZERO_BOTTOM_LAST - CC128M_FIELD_EXP_ZERO_BOTTOM_START + 1, CC128M_FIELD_EXP_ZERO_BOTTOM_MASK_NOT_SHIFTED = ((1UL << (CC128M_FIELD_EXP_ZERO_BOTTOM_SIZE)) - 1UL), CC128M_FIELD_EXP_ZERO_BOTTOM_MASK64 = (uint64_t)CC128M_FIELD_EXP_ZERO_BOTTOM_MASK_NOT_SHIFTED << CC128M_FIELD_EXP_ZERO_BOTTOM_START, CC128M_FIELD_EXP_ZERO_BOTTOM_MAX_VALUE = CC128M_FIELD_EXP_ZERO_BOTTOM_MASK_NOT_SHIFTED,

    CC128M_FIELD_EXP_NONZERO_TOP_START = (83 - 64), CC128M_FIELD_EXP_NONZERO_TOP_LAST = (93 - 64), CC128M_FIELD_EXP_NONZERO_TOP_SIZE = CC128M_FIELD_EXP_NONZERO_TOP_LAST - CC128M_FIELD_EXP_NONZERO_TOP_START + 1, CC128M_FIELD_EXP_NONZERO_TOP_MASK_NOT_SHIFTED = ((1UL << (CC128M_FIELD_EXP_NONZERO_TOP_SIZE)) - 1UL), CC128M_FIELD_EXP_NONZERO_TOP_MASK64 = (uint64_t)CC128M_FIELD_EXP_NONZERO_TOP_MASK_NOT_SHIFTED << CC128M_FIELD_EXP_NONZERO_TOP_START, CC128M_FIELD_EXP_NONZERO_TOP_MAX_VALUE = CC128M_FIELD_EXP_NONZERO_TOP_MASK_NOT_SHIFTED,
    CC128M_FIELD_EXPONENT_HIGH_PART_START = (80 - 64), CC128M_FIELD_EXPONENT_HIGH_PART_LAST = (82 - 64), CC128M_FIELD_EXPONENT_HIGH_PART_SIZE = CC128M_FIELD_EXPONENT_HIGH_PART_LAST - CC128M_FIELD_EXPONENT_HIGH_PART_START + 1, CC128M_FIELD_EXPONENT_HIGH_PART_MASK_NOT_SHIFTED = ((1UL << (CC128M_FIELD_EXPONENT_HIGH_PART_SIZE)) - 1UL), CC128M_FIELD_EXPONENT_HIGH_PART_MASK64 = (uint64_t)CC128M_FIELD_EXPONENT_HIGH_PART_MASK_NOT_SHIFTED << CC128M_FIELD_EXPONENT_HIGH_PART_START, CC128M_FIELD_EXPONENT_HIGH_PART_MAX_VALUE = CC128M_FIELD_EXPONENT_HIGH_PART_MASK_NOT_SHIFTED,
    CC128M_FIELD_EXP_NONZERO_BOTTOM_START = (67 - 64), CC128M_FIELD_EXP_NONZERO_BOTTOM_LAST = (79 - 64), CC128M_FIELD_EXP_NONZERO_BOTTOM_SIZE = CC128M_FIELD_EXP_NONZERO_BOTTOM_LAST - CC128M_FIELD_EXP_NONZERO_BOTTOM_START + 1, CC128M_FIELD_EXP_NONZERO_BOTTOM_MASK_NOT_SHIFTED = ((1UL << (CC128M_FIELD_EXP_NONZERO_BOTTOM_SIZE)) - 1UL), CC128M_FIELD_EXP_NONZERO_BOTTOM_MASK64 = (uint64_t)CC128M_FIELD_EXP_NONZERO_BOTTOM_MASK_NOT_SHIFTED << CC128M_FIELD_EXP_NONZERO_BOTTOM_START, CC128M_FIELD_EXP_NONZERO_BOTTOM_MAX_VALUE = CC128M_FIELD_EXP_NONZERO_BOTTOM_MASK_NOT_SHIFTED,
    CC128M_FIELD_EXPONENT_LOW_PART_START = (64 - 64), CC128M_FIELD_EXPONENT_LOW_PART_LAST = (66 - 64), CC128M_FIELD_EXPONENT_LOW_PART_SIZE = CC128M_FIELD_EXPONENT_LOW_PART_LAST - CC128M_FIELD_EXPONENT_LOW_PART_START + 1, CC128M_FIELD_EXPONENT_LOW_PART_MASK_NOT_SHIFTED = ((1UL << (CC128M_FIELD_EXPONENT_LOW_PART_SIZE)) - 1UL), CC128M_FIELD_EXPONENT_LOW_PART_MASK64 = (uint64_t)CC128M_FIELD_EXPONENT_LOW_PART_MASK_NOT_SHIFTED << CC128M_FIELD_EXPONENT_LOW_PART_START, CC128M_FIELD_EXPONENT_LOW_PART_MAX_VALUE = CC128M_FIELD_EXPONENT_LOW_PART_MASK_NOT_SHIFTED,
};
#pragma GCC diagnostic pop
# 154 "./cheri_compressed_cap_128m.h"
_Static_assert((1 << 17) < CC128M_FIELD_ALL_PERMS_MAX_VALUE, "permissions not representable?");
_Static_assert(((1 << 17) << 1) > CC128M_FIELD_ALL_PERMS_MAX_VALUE, "all permission bits should be used");



enum { CC128M_PERMS_RESERVED_ONES = 0 };

_Static_assert((0x3FFFFUL) == (CC128M_FIELD_ALL_PERMS_MAX_VALUE), "");
_Static_assert((((uint64_t)((0x3FFFFUL) & CC128M_FIELD_ALL_PERMS_MAX_VALUE) << CC128M_FIELD_ALL_PERMS_START)) == (0x3FFFFUL << 46), "");
# 171 "./cheri_compressed_cap_128m.h"
enum CC128M_OTypes {
    CC128M_MAX_REPRESENTABLE_OTYPE = ((1u << CC128M_FIELD_OTYPE_SIZE) - 1u),
    CC128M_OTYPE_UNSEALED = ((0u)), CC128M_OTYPE_UNSEALED_SIGNED = ((0u)),
    CC128M_OTYPE_SENTRY = ((1u)), CC128M_OTYPE_SENTRY_SIGNED = ((1u)),
    CC128M_OTYPE_LOAD_PAIR_BRANCH = ((2u)), CC128M_OTYPE_LOAD_PAIR_BRANCH_SIGNED = ((2u)),
    CC128M_OTYPE_LOAD_BRANCH = ((3u)), CC128M_OTYPE_LOAD_BRANCH_SIGNED = ((3u)),
    CC128M_MIN_RESERVED_OTYPE = CC128M_OTYPE_UNSEALED,
    CC128M_MAX_RESERVED_OTYPE = CC128M_OTYPE_LOAD_BRANCH,
};







_Static_assert((16) == (CC128M_FIELD_EXP_ZERO_BOTTOM_SIZE), "");
# 200 "./cheri_compressed_cap_128m.h"
# 1 "./cheri_compressed_cap_common.h" 1
# 40 "./cheri_compressed_cap_common.h"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
enum {


    CC128M_RESET_EXP = 50,
    CC128M_RESET_T = 1u << (64 - CC128M_RESET_EXP - CC128M_FIELD_EXPONENT_HIGH_PART_SIZE),



    CC128M_NULL_EXP = 63,
    CC128M_NULL_T = 0,





    CC128M_RESET_EBT = ((uint64_t)((!(1)) & CC128M_FIELD_EXPONENT_ZERO_MAX_VALUE) << CC128M_FIELD_EXPONENT_ZERO_START) | ((uint64_t)(((~(CC128M_RESET_EXP)) >> CC128M_FIELD_EXPONENT_LOW_PART_SIZE) & CC128M_FIELD_EXPONENT_HIGH_PART_MAX_VALUE) << CC128M_FIELD_EXPONENT_HIGH_PART_START) | ((uint64_t)((~(CC128M_RESET_EXP)) & CC128M_FIELD_EXPONENT_LOW_PART_MAX_VALUE) << CC128M_FIELD_EXPONENT_LOW_PART_START) |
                       ((uint64_t)((CC128M_RESET_T) & CC128M_FIELD_EXP_NONZERO_TOP_MAX_VALUE) << CC128M_FIELD_EXP_NONZERO_TOP_START) | ((uint64_t)((0) & CC128M_FIELD_EXP_NONZERO_BOTTOM_MAX_VALUE) << CC128M_FIELD_EXP_NONZERO_BOTTOM_START),
    CC128M_RESET_PESBT = CC128M_RESET_EBT | ((uint64_t)((0x3FFFFUL) & CC128M_FIELD_ALL_PERMS_MAX_VALUE) << CC128M_FIELD_ALL_PERMS_START) |
                         ((uint64_t)((CC128M_OTYPE_UNSEALED) & CC128M_FIELD_OTYPE_MAX_VALUE) << CC128M_FIELD_OTYPE_START),
    CC128M_NULL_EBT = ((uint64_t)((!(1)) & CC128M_FIELD_EXPONENT_ZERO_MAX_VALUE) << CC128M_FIELD_EXPONENT_ZERO_START) | ((uint64_t)(((~(CC128M_NULL_EXP)) >> CC128M_FIELD_EXPONENT_LOW_PART_SIZE) & CC128M_FIELD_EXPONENT_HIGH_PART_MAX_VALUE) << CC128M_FIELD_EXPONENT_HIGH_PART_START) | ((uint64_t)((~(CC128M_NULL_EXP)) & CC128M_FIELD_EXPONENT_LOW_PART_MAX_VALUE) << CC128M_FIELD_EXPONENT_LOW_PART_START) |
                      ((uint64_t)((CC128M_NULL_T) & CC128M_FIELD_EXP_NONZERO_TOP_MAX_VALUE) << CC128M_FIELD_EXP_NONZERO_TOP_START) | ((uint64_t)((0) & CC128M_FIELD_EXP_NONZERO_BOTTOM_MAX_VALUE) << CC128M_FIELD_EXP_NONZERO_BOTTOM_START),
    CC128M_NULL_PESBT = CC128M_NULL_EBT | ((uint64_t)((CC128M_OTYPE_UNSEALED) & CC128M_FIELD_OTYPE_MAX_VALUE) << CC128M_FIELD_OTYPE_START),

    CC128M_MEM_XOR_MASK = CC128M_NULL_PESBT,
    CC128M_NULL_XOR_MASK __attribute__((deprecated("Use _MEM_XOR_MASK instead"))) = CC128M_MEM_XOR_MASK,
    CC128M_MAX_LEVEL_VALUE = ((1UL << (1)) - 1UL),
};
#pragma GCC diagnostic pop
# 89 "./cheri_compressed_cap_common.h"
enum { CC128M_FIELD_LEN_MSB_SIZE = 0 };



_Static_assert((CC128M_FIELD_INTERNAL_EXPONENT_SIZE + CC128M_FIELD_EXP_ZERO_TOP_SIZE + CC128M_FIELD_LEN_MSB_SIZE + CC128M_FIELD_EXP_ZERO_BOTTOM_SIZE) == (CC128M_FIELD_EBT_SIZE), "");


_Static_assert((CC128M_FIELD_INTERNAL_EXPONENT_SIZE + CC128M_FIELD_LEN_MSB_SIZE + CC128M_FIELD_TOP_ENCODED_SIZE + CC128M_FIELD_BOTTOM_ENCODED_SIZE) == (CC128M_FIELD_EBT_SIZE), "");


_Static_assert((CC128M_FIELD_INTERNAL_EXPONENT_SIZE + CC128M_FIELD_LEN_MSB_SIZE + CC128M_FIELD_EXP_NONZERO_TOP_SIZE + CC128M_FIELD_EXP_NONZERO_BOTTOM_SIZE + CC128M_FIELD_EXPONENT_HIGH_PART_SIZE + CC128M_FIELD_EXPONENT_LOW_PART_SIZE) == (CC128M_FIELD_EBT_SIZE), "");




_Static_assert((CC128M_FIELD_EBT_START) == (0), "");

_Static_assert(CC128M_MIN_RESERVED_OTYPE >= 0, "MIN_RESERVED_OTYPE is signed?");
_Static_assert(CC128M_MIN_RESERVED_OTYPE < CC128M_MAX_RESERVED_OTYPE, "MIN_RESERVED_OTYPE greater than MAX_RESERVED_OTYPE?");

_Static_assert(CC128M_MIN_RESERVED_OTYPE <= CC128M_MAX_REPRESENTABLE_OTYPE, "MIN_RESERVED_OTYPE out of range?");
_Static_assert(CC128M_MAX_RESERVED_OTYPE <= CC128M_MAX_REPRESENTABLE_OTYPE, "MAX_RESERVED_OTYPE out of range?");


typedef struct cc128m_cap cc128m_cap_t;

extern uint8_t cc128m_get_flags(const cc128m_cap_t* cap);
extern uint32_t cc128m_get_otype(const cc128m_cap_t* cap);
extern uint32_t cc128m_get_level(const cc128m_cap_t* cap);
extern cc128m_addr_t cc128m_get_perms(const cc128m_cap_t* cap);
extern cc128m_addr_t cc128m_get_reserved(const cc128m_cap_t* cap);
extern _Bool cc128m_reserved_bits_valid(const cc128m_cap_t* cap) { return cc128m_get_reserved(cap) == 0; }
extern cc128m_addr_t cc128m_get_uperms(const cc128m_cap_t* cap);

extern cc128m_addr_t cc128m_get_all_permissions(const cc128m_cap_t* cap);
extern _Bool cc128m_has_permissions(const cc128m_cap_t* cap, cc128m_addr_t permissions) {
    return (cc128m_get_all_permissions(cap) & permissions) == permissions;
}
extern _Bool cc128m_set_permissions(cc128m_cap_t* cap, cc128m_addr_t permissions);






struct cc128m_cap {







    cc128m_addr_t _cr_cursor;
    cc128m_addr_t cr_pesbt;

    cc128m_length_t _cr_top;
    cc128m_addr_t cr_base;
    uint8_t cr_tag;
    uint8_t cr_bounds_valid;



    uint8_t cr_exp;
    uint8_t cr_extra;
# 179 "./cheri_compressed_cap_common.h"
};

extern _Bool cc128m_exactly_equal(const cc128m_cap_t* a, const cc128m_cap_t* b) {
    return a->cr_tag == b->cr_tag && a->_cr_cursor == b->_cr_cursor && a->cr_pesbt == b->cr_pesbt;
}

extern uint8_t cc128m_get_lvbits(__attribute__((unused)) const cc128m_cap_t* cap) {



    return 1;

}

extern _Bool cc128m_raw_equal(const cc128m_cap_t* a, const cc128m_cap_t* b) {
    return a->_cr_cursor == b->_cr_cursor && a->cr_pesbt == b->cr_pesbt && a->_cr_top == b->_cr_top &&
           a->cr_base == b->cr_base && a->cr_tag == b->cr_tag && a->cr_bounds_valid == b->cr_bounds_valid &&
           cc128m_get_lvbits(a) == cc128m_get_lvbits(b) && a->cr_exp == b->cr_exp && a->cr_extra == b->cr_extra;
}


extern uint32_t cc128m_idx_MSNZ(uint64_t x) {
# 218 "./cheri_compressed_cap_common.h"
    ((void) sizeof ((x != 0) ? 1 : 0), __extension__ ({ if (x != 0) ; else __assert_fail ("x != 0", "./cheri_compressed_cap_common.h", 218, __extension__ __PRETTY_FUNCTION__); }));
    uint32_t r = 63u - (uint32_t)__builtin_clzll(x);

    return r;
}





extern uint32_t cc128m_compute_e(cc128m_addr_t rlength, uint32_t bwidth) {
    if (rlength < (1u << (bwidth - 1)))
        return 0;

    return (cc128m_idx_MSNZ(rlength) - (bwidth - 2));
}

extern uint32_t cc128m_get_exponent(cc128m_length_t length) {
    const uint32_t bwidth = 16;
    if (length > (18446744073709551615UL)) {
        return 65 - (bwidth - 1);
    } else {
        return cc128m_compute_e((cc128m_addr_t)length, bwidth);
    }
}

extern uint64_t cc128m_getbits(uint64_t src, uint32_t start, uint32_t size) {
    return ((src >> start) & ((1UL << size) - 1UL));
}


extern uint64_t cc128m_truncate_addr(cc128m_addr_t value, size_t n) { return value & (((cc128m_addr_t)1 << n) - 1); }
extern uint64_t cc128m_truncate64(uint64_t value, size_t n) { return value & ((1UL << n) - 1); }







extern uint64_t cc128m_truncateLSB_16(uint64_t value, size_t n) { _Static_assert(16 <= 64, ""); return value >> (16 - n); }
extern uint64_t cc128m_truncateLSB_32(uint64_t value, size_t n) { _Static_assert(32 <= 64, ""); return value >> (32 - n); }
extern uint64_t cc128m_truncateLSB_64(uint64_t value, size_t n) { _Static_assert(64 <= 64, ""); return value >> (64 - n); }




struct cc128m_bounds_bits {
    uint16_t B;
    uint16_t T;
    uint8_t E;
    _Bool IE;
};
# 283 "./cheri_compressed_cap_common.h"
extern cc128m_addr_t cc128m_cap_pesbt_extract_otype(cc128m_addr_t pesbt) { return cc128m_getbits((pesbt), CC128M_FIELD_OTYPE_START, CC128M_FIELD_OTYPE_SIZE); } extern cc128m_addr_t cc128m_cap_pesbt_encode_otype(uint32_t value) { return ((uint64_t)((value) & CC128M_FIELD_OTYPE_MAX_VALUE) << CC128M_FIELD_OTYPE_START); } extern cc128m_addr_t cc128m_cap_pesbt_deposit_otype(cc128m_addr_t pesbt, uint32_t value) { return __extension__({ ((void) sizeof ((value <= CC128M_FIELD_OTYPE_MAX_VALUE) ? 1 : 0), __extension__ ({ if (value <= CC128M_FIELD_OTYPE_MAX_VALUE) ; else __assert_fail ("value <= CC128M_FIELD_OTYPE_MAX_VALUE", "./cheri_compressed_cap_common.h", 283, __extension__ __PRETTY_FUNCTION__); })); ((pesbt) & ~CC128M_FIELD_OTYPE_MASK64) | ((uint64_t)((value) & CC128M_FIELD_OTYPE_MAX_VALUE) << CC128M_FIELD_OTYPE_START); }); } extern uint32_t cc128m_get_otype(const cc128m_cap_t* cap) { return cc128m_cap_pesbt_extract_otype(cap->cr_pesbt); } extern void cc128m_update_otype(cc128m_cap_t * cap, cc128m_addr_t value) { cap->cr_pesbt = cc128m_cap_pesbt_deposit_otype(cap->cr_pesbt, value); }
extern cc128m_addr_t cc128m_cap_pesbt_extract_flags(cc128m_addr_t pesbt) { return cc128m_getbits((pesbt), CC128M_FIELD_FLAGS_START, CC128M_FIELD_FLAGS_SIZE); } extern cc128m_addr_t cc128m_cap_pesbt_encode_flags(uint8_t value) { return ((uint64_t)((value) & CC128M_FIELD_FLAGS_MAX_VALUE) << CC128M_FIELD_FLAGS_START); } extern cc128m_addr_t cc128m_cap_pesbt_deposit_flags(cc128m_addr_t pesbt, uint8_t value) { return __extension__({ ((void) sizeof ((value <= CC128M_FIELD_FLAGS_MAX_VALUE) ? 1 : 0), __extension__ ({ if (value <= CC128M_FIELD_FLAGS_MAX_VALUE) ; else __assert_fail ("value <= CC128M_FIELD_FLAGS_MAX_VALUE", "./cheri_compressed_cap_common.h", 284, __extension__ __PRETTY_FUNCTION__); })); ((pesbt) & ~CC128M_FIELD_FLAGS_MASK64) | ((uint64_t)((value) & CC128M_FIELD_FLAGS_MAX_VALUE) << CC128M_FIELD_FLAGS_START); }); } extern uint8_t cc128m_get_flags(const cc128m_cap_t* cap) { return cc128m_cap_pesbt_extract_flags(cap->cr_pesbt); } extern void cc128m_update_flags(cc128m_cap_t * cap, cc128m_addr_t value) { cap->cr_pesbt = cc128m_cap_pesbt_deposit_flags(cap->cr_pesbt, value); }


extern _Bool cc128m_is_cap_sealed(const cc128m_cap_t* cp) { return cc128m_get_otype(cp) != CC128M_OTYPE_UNSEALED; }


extern uint32_t cc128m_get_level(const cc128m_cap_t* cap) {
    return cc128m_get_all_permissions(cap) & (1 << 0) ? 1 : 0;
}
extern void cc128m_update_level(cc128m_cap_t* cap, uint8_t level) {
    ((void) sizeof (((level <= CC128M_MAX_LEVEL_VALUE) && "invalid level") ? 1 : 0), __extension__ ({ if ((level <= CC128M_MAX_LEVEL_VALUE) && "invalid level") ; else __assert_fail ("(level <= CC128M_MAX_LEVEL_VALUE) && \"invalid level\"", "./cheri_compressed_cap_common.h", 294, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof (((!cap->cr_tag || !cc128m_is_cap_sealed(cap)) && "cannot update level on sealed caps") ? 1 : 0), __extension__ ({ if ((!cap->cr_tag || !cc128m_is_cap_sealed(cap)) && "cannot update level on sealed caps") ; else __assert_fail ("(!cap->cr_tag || !cc128m_is_cap_sealed(cap)) && \"cannot update level on sealed caps\"", "./cheri_compressed_cap_common.h", 295, __extension__ __PRETTY_FUNCTION__); }));
    cc128m_addr_t perms = cc128m_get_all_permissions(cap);
    if (level)
        perms |= (1 << 0);
    else
        perms &= ~(1 << 0);
    __attribute__((unused)) _Bool ok = cc128m_set_permissions(cap, perms);
    ((void) sizeof ((ok && "failed to update level") ? 1 : 0), __extension__ ({ if (ok && "failed to update level") ; else __assert_fail ("ok && \"failed to update level\"", "./cheri_compressed_cap_common.h", 302, __extension__ __PRETTY_FUNCTION__); }));
}



extern cc128m_cap_t cc128m_make_null_derived_cap(cc128m_addr_t addr);
__attribute__((deprecated("Use get_all_permissions"))) extern cc128m_addr_t cc128m_get_perms(const cc128m_cap_t* cap) {

    _Static_assert(2 != 0, "Architectural perms expected to start at offset zero");

    cc128m_cap_t null_cap = cc128m_make_null_derived_cap(0);
    cc128m_addr_t reserved_one_bits = cc128m_get_all_permissions(&null_cap);
    cc128m_addr_t all_perms_w_reserved = cc128m_get_all_permissions(cap);
    return (all_perms_w_reserved & ~reserved_one_bits) & ~(0xfUL << 2);
}
__attribute__((deprecated("Use get_all_permissions"))) extern cc128m_addr_t cc128m_get_uperms(const cc128m_cap_t* cap) {
    return (cc128m_get_all_permissions(cap) & (0xfUL << 2)) >> 2;
}
__attribute__((deprecated("Use set_permissions"))) extern void cc128m_update_perms(cc128m_cap_t* cap, cc128m_addr_t value) {
    ((void) sizeof ((((value & (0x3FFFFUL & ~0xfUL)) == value) && "invalid permission value") ? 1 : 0), __extension__ ({ if (((value & (0x3FFFFUL & ~0xfUL)) == value) && "invalid permission value") ; else __assert_fail ("((value & (0x3FFFFUL & ~0xfUL)) == value) && \"invalid permission value\"", "./cheri_compressed_cap_common.h", 321, __extension__ __PRETTY_FUNCTION__); }));
    cc128m_addr_t current_swperms = (cc128m_get_all_permissions(cap) & (0xfUL << 2));
    cc128m_set_permissions(cap, (value & ~(0xfUL << 2)) | current_swperms);
}
__attribute__((deprecated("Use set_permissions"))) extern void cc128m_update_uperms(cc128m_cap_t* cap, cc128m_addr_t value) {
    ((void) sizeof ((((value & 0xfUL) == value) && "invalid permission value") ? 1 : 0), __extension__ ({ if (((value & 0xfUL) == value) && "invalid permission value") ; else __assert_fail ("((value & 0xfUL) == value) && \"invalid permission value\"", "./cheri_compressed_cap_common.h", 326, __extension__ __PRETTY_FUNCTION__); }));
    cc128m_addr_t old_arch_perms = cc128m_get_all_permissions(cap) & ~(0xfUL << 2);
    cc128m_set_permissions(cap, ((value << 2) & (0xfUL << 2)) | old_arch_perms);
}


extern struct cc128m_bounds_bits cc128m_extract_bounds_bits(cc128m_addr_t pesbt) {
    _Static_assert(16 == CC128M_FIELD_EXP_ZERO_BOTTOM_SIZE, "Wrong bot width?");
    uint32_t BWidth = 16;
    uint32_t BMask = (1u << BWidth) - 1;
    uint32_t TMask = BMask >> 2;
    struct cc128m_bounds_bits result;
    _Static_assert(sizeof(result.B) * 8 >= 16, "B field too small");
    _Static_assert(sizeof(result.T) * 8 >= 16, "T field too small");
    _Static_assert(sizeof(result.E) * 8 >= CC128M_FIELD_EXPONENT_LOW_PART_SIZE + CC128M_FIELD_EXPONENT_HIGH_PART_SIZE, "E field too small");


    result.IE = (_Bool)(!cc128m_getbits((pesbt), CC128M_FIELD_EXPONENT_ZERO_START, CC128M_FIELD_EXPONENT_ZERO_SIZE));
    uint8_t L_msb;
    if (result.IE) {
        result.E = (uint8_t)((~(cc128m_getbits((pesbt), CC128M_FIELD_EXPONENT_LOW_PART_START, CC128M_FIELD_EXPONENT_LOW_PART_SIZE) | (cc128m_getbits((pesbt), CC128M_FIELD_EXPONENT_HIGH_PART_START, CC128M_FIELD_EXPONENT_HIGH_PART_SIZE) << CC128M_FIELD_EXPONENT_LOW_PART_SIZE))) & ((1UL << ((CC128M_FIELD_EXPONENT_LOW_PART_SIZE + CC128M_FIELD_EXPONENT_HIGH_PART_SIZE))) - 1UL));



        result.B = (uint16_t)cc128m_getbits((pesbt), CC128M_FIELD_EXP_NONZERO_BOTTOM_START, CC128M_FIELD_EXP_NONZERO_BOTTOM_SIZE) << CC128M_FIELD_EXPONENT_LOW_PART_SIZE;
        result.T = (uint16_t)cc128m_getbits((pesbt), CC128M_FIELD_EXP_NONZERO_TOP_START, CC128M_FIELD_EXP_NONZERO_TOP_SIZE) << CC128M_FIELD_EXPONENT_HIGH_PART_SIZE;
        L_msb = 1;
    } else {
        result.E = 0;



        L_msb = 0;

        result.B = (uint16_t)cc128m_getbits((pesbt), CC128M_FIELD_EXP_ZERO_BOTTOM_START, CC128M_FIELD_EXP_ZERO_BOTTOM_SIZE);
        result.T = (uint16_t)cc128m_getbits((pesbt), CC128M_FIELD_EXP_ZERO_TOP_START, CC128M_FIELD_EXP_ZERO_TOP_SIZE);
    }






    uint8_t L_carry = result.T < (result.B & TMask) ? 1 : 0;
    uint64_t BTop2 = cc128m_getbits(result.B, 16 - 2, 2);
    uint8_t T_infer = (BTop2 + L_carry + L_msb) & 0x3;
    result.T |= ((uint16_t)T_infer) << (BWidth - 2);
    return result;
}


extern _Bool cc128m_bounds_bits_valid(struct cc128m_bounds_bits bounds) {

    cc128m_addr_t Bmsb = cc128m_getbits(bounds.B, 16 - 1, 1);
    cc128m_addr_t Bmsb2 = cc128m_getbits(bounds.B, 16 - 2, 2);
    cc128m_addr_t Tmsb = cc128m_getbits(bounds.T, 16 - 1, 1);
    if (bounds.E >= 50) {
        return Tmsb == 0 && Bmsb2 == 0;
    } else if (bounds.E == 50 - 1) {
        return Bmsb == 0;
    } else {
        return 1;
    }
}



extern cc128m_addr_t cc128m_cap_bounds_address(cc128m_addr_t addr) {

    cc128m_addr_t cursor = addr & 0x00FFFFFFFFFFFFFF;

    if (cursor & ((0x00FFFFFFFFFFFFFF >> 1) + 1))
        cursor |= ~0x00FFFFFFFFFFFFFF;
    return cursor;
}


extern _Bool cc128m_compute_base_top_special_cases(struct cc128m_bounds_bits bounds, cc128m_addr_t* base_out,
                                                         cc128m_length_t* top_out, _Bool* valid);

extern _Bool cc128m_compute_base_top(struct cc128m_bounds_bits bounds, cc128m_addr_t cursor, cc128m_addr_t* base_out,
                                           cc128m_length_t* top_out) {

    _Bool valid = 1;
    if (cc128m_compute_base_top_special_cases(bounds, base_out, top_out, &valid))
        return valid;

    cursor = cc128m_cap_bounds_address(cursor);




    uint8_t E = ((50) < (bounds.E) ? (50) : (bounds.E));




    unsigned a_mid = (unsigned)cc128m_truncate64(cursor >> (E + 16 - 3), 3);
    unsigned correction_B = (unsigned)cc128m_truncateLSB_16(bounds.B, 3);
    unsigned correction_T = (unsigned)cc128m_truncateLSB_16(bounds.T, 3);

    unsigned R = (unsigned)cc128m_truncate64(correction_B - 1, 3);
# 440 "./cheri_compressed_cap_common.h"
    int aHi = a_mid < R ? 1 : 0;
    int bHi = correction_B < R ? 1 : 0;
    int tHi = correction_T < R ? 1 : 0;




    int correction_base = bHi - aHi;
    int correction_top = tHi - aHi;

    const unsigned a_top_shift = E + 16;

    cc128m_addr_t a_top = a_top_shift >= 64 ? 0 : cursor >> a_top_shift;


    cc128m_length_t base = (cc128m_addr_t)((int64_t)a_top + correction_base);
    base <<= 16;
    base |= bounds.B;
    base <<= E;
    base &= ((cc128m_length_t)1 << 65) - 1;
    ((void) sizeof (((cc128m_addr_t)(base >> 64) <= 1) ? 1 : 0), __extension__ ({ if ((cc128m_addr_t)(base >> 64) <= 1) ; else __assert_fail ("(cc128m_addr_t)(base >> 64) <= 1", "./cheri_compressed_cap_common.h", 460, __extension__ __PRETTY_FUNCTION__); }));

    cc128m_length_t top = (cc128m_addr_t)((int64_t)a_top + correction_top);
    top <<= 16;
    top |= bounds.T;
    top <<= E;
    top &= ((cc128m_length_t)1 << 65) - 1;
    ((void) sizeof (((cc128m_addr_t)(top >> 64) <= 1) ? 1 : 0), __extension__ ({ if ((cc128m_addr_t)(top >> 64) <= 1) ; else __assert_fail ("(cc128m_addr_t)(top >> 64) <= 1", "./cheri_compressed_cap_common.h", 467, __extension__ __PRETTY_FUNCTION__); }));







    unsigned base2 = cc128m_truncate64(base >> (64 - 1), 1);

    unsigned top2 = cc128m_truncate64(top >> (64 - 1), 2);



    if (E < (50 - 1) && (top2 - base2) > 1) {
        top = top ^ ((cc128m_length_t)1 << 64);
    }

    ((void) sizeof (((cc128m_addr_t)(top >> 64) <= 1) ? 1 : 0), __extension__ ({ if ((cc128m_addr_t)(top >> 64) <= 1) ; else __assert_fail ("(cc128m_addr_t)(top >> 64) <= 1", "./cheri_compressed_cap_common.h", 485, __extension__ __PRETTY_FUNCTION__); }));

    if (cc128m_bounds_bits_valid(bounds)) {


        ((void) sizeof (((cc128m_addr_t)base <= top) ? 1 : 0), __extension__ ({ if ((cc128m_addr_t)base <= top) ; else __assert_fail ("(cc128m_addr_t)base <= top", "./cheri_compressed_cap_common.h", 490, __extension__ __PRETTY_FUNCTION__); }));
    } else {

    }
    *base_out = (cc128m_addr_t)base;
    *top_out = top;

    return 1;
}



extern void cc128m_unsafe_decompress_raw(cc128m_addr_t pesbt, cc128m_addr_t cursor, _Bool tag,
                                                __attribute__((unused)) uint8_t lvbits, cc128m_cap_t* cdp) {
    memset(cdp, 0, sizeof(*cdp));
    cdp->cr_tag = tag;
    cdp->_cr_cursor = cursor;
    cdp->cr_pesbt = pesbt;




    struct cc128m_bounds_bits bounds = cc128m_extract_bounds_bits(pesbt);
    _Bool valid = cc128m_compute_base_top(bounds, cursor, &cdp->cr_base, &cdp->_cr_top);
    cdp->cr_bounds_valid = valid;
    cdp->cr_exp = bounds.E;
}

extern void cc128m_decompress_raw_ext(cc128m_addr_t pesbt, cc128m_addr_t cursor, _Bool tag, uint8_t lvbits,
                                             cc128m_cap_t* cdp) {
    cc128m_unsafe_decompress_raw(pesbt, cursor, tag, lvbits, cdp);
    if (tag) {
        ((void) sizeof ((cdp->cr_base <= (18446744073709551615UL)) ? 1 : 0), __extension__ ({ if (cdp->cr_base <= (18446744073709551615UL)) ; else __assert_fail ("cdp->cr_base <= (18446744073709551615UL)", "./cheri_compressed_cap_common.h", 522, __extension__ __PRETTY_FUNCTION__); }));






        ((void) sizeof ((cc128m_reserved_bits_valid(cdp)) ? 1 : 0), __extension__ ({ if (cc128m_reserved_bits_valid(cdp)) ; else __assert_fail ("cc128m_reserved_bits_valid(cdp)", "./cheri_compressed_cap_common.h", 529, __extension__ __PRETTY_FUNCTION__); }));
    }
}

extern void cc128m_decompress_raw(cc128m_addr_t pesbt, cc128m_addr_t cursor, _Bool tag, cc128m_cap_t* cdp) {
    cc128m_decompress_raw_ext(pesbt, cursor, tag, 1, cdp);
}




extern void cc128m_decompress_mem(uint64_t pesbt, uint64_t cursor, _Bool tag, cc128m_cap_t* cdp) {
    cc128m_decompress_raw_ext(pesbt ^ CC128M_MEM_XOR_MASK, cursor, tag, 1, cdp);
}


extern _Bool cc128m_pesbt_is_correct(const cc128m_cap_t* csp) {
    cc128m_cap_t tmp;

    cc128m_unsafe_decompress_raw(csp->cr_pesbt, csp->_cr_cursor, csp->cr_tag, cc128m_get_lvbits(csp), &tmp);
    tmp.cr_extra = csp->cr_extra;
    if (!cc128m_raw_equal(&tmp, csp)) {
        return 0;
    }
    return 1;
}


extern void cc128m_update_ebt(cc128m_cap_t* csp, cc128m_addr_t new_ebt) {
    csp->cr_pesbt = (csp->cr_pesbt & ~CC128M_FIELD_EBT_MASK64) | new_ebt;
    csp->cr_exp = cc128m_extract_bounds_bits(new_ebt).E;
}






extern cc128m_addr_t cc128m_compress_raw(const cc128m_cap_t* csp) {





    ((void) sizeof ((cc128m_pesbt_is_correct(csp) && "capability bounds were modified without updating pesbt") ? 1 : 0), __extension__ ({ if (cc128m_pesbt_is_correct(csp) && "capability bounds were modified without updating pesbt") ; else __assert_fail ("cc128m_pesbt_is_correct(csp) && \"capability bounds were modified without updating pesbt\"", "./cheri_compressed_cap_common.h", 573, __extension__ __PRETTY_FUNCTION__); }));
    return csp->cr_pesbt;
}

extern cc128m_addr_t cc128m_compress_mem(const cc128m_cap_t* csp) {
    return cc128m_compress_raw(csp) ^ CC128M_MEM_XOR_MASK;
}

static _Bool cc128m__fast_is_representable_new_addr(const cc128m_cap_t* cap, cc128m_addr_t new_addr);


extern _Bool cc128m_is_representable_cap_exact(const cc128m_cap_t* cap) {
    cc128m_addr_t pesbt = cc128m_compress_raw(cap);
    cc128m_cap_t decompressed_cap;

    cc128m_unsafe_decompress_raw(pesbt, cap->_cr_cursor, cap->cr_tag, cc128m_get_lvbits(cap), &decompressed_cap);

    ((void) sizeof ((decompressed_cap._cr_cursor == cap->_cr_cursor) ? 1 : 0), __extension__ ({ if (decompressed_cap._cr_cursor == cap->_cr_cursor) ; else __assert_fail ("decompressed_cap._cr_cursor == cap->_cr_cursor", "./cheri_compressed_cap_common.h", 590, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((decompressed_cap.cr_pesbt == cap->cr_pesbt) ? 1 : 0), __extension__ ({ if (decompressed_cap.cr_pesbt == cap->cr_pesbt) ; else __assert_fail ("decompressed_cap.cr_pesbt == cap->cr_pesbt", "./cheri_compressed_cap_common.h", 591, __extension__ __PRETTY_FUNCTION__); }));

    if (decompressed_cap.cr_base != cap->cr_base || decompressed_cap._cr_top != cap->_cr_top) {
        return 0;
    }
    return 1;
}

extern uint32_t cc128m_compute_ebt(cc128m_addr_t req_base, cc128m_length_t req_top, cc128m_addr_t* alignment_mask,
                                          _Bool* exact) {

    if (req_base == 0 && req_top == ((cc128m_length_t)1u << 64)) {
        *exact = 1;
        if (alignment_mask)
            *alignment_mask = (18446744073709551615UL);
        return CC128M_RESET_EBT;
    }
# 616 "./cheri_compressed_cap_common.h"
    cc128m_length_t req_length65 = req_top - req_base;
# 625 "./cheri_compressed_cap_common.h"
    uint8_t E = (uint8_t)cc128m_get_exponent(req_length65);
    const uint64_t req_length64 = (uint64_t)req_length65;




    const _Bool InternalExponent = E != 0 || cc128m_getbits(req_length64, CC128M_FIELD_EXP_NONZERO_BOTTOM_SIZE + 1, 1);
    if (!InternalExponent) {






        uint32_t ebt_bits = ((uint64_t)((!(0)) & CC128M_FIELD_EXPONENT_ZERO_MAX_VALUE) << CC128M_FIELD_EXPONENT_ZERO_START) | ((uint64_t)((req_top) & CC128M_FIELD_EXP_ZERO_TOP_MAX_VALUE) << CC128M_FIELD_EXP_ZERO_TOP_START) |
                            ((uint64_t)((req_base) & CC128M_FIELD_EXP_ZERO_BOTTOM_MAX_VALUE) << CC128M_FIELD_EXP_ZERO_BOTTOM_START);
# 667 "./cheri_compressed_cap_common.h"
        if (alignment_mask)
            *alignment_mask = (18446744073709551615UL);
        *exact = 1;
        return ebt_bits;
    }
# 680 "./cheri_compressed_cap_common.h"
    cc128m_addr_t bot_ie = cc128m_truncate64(req_base >> (E + CC128M_FIELD_EXPONENT_LOW_PART_SIZE), CC128M_FIELD_EXP_NONZERO_BOTTOM_SIZE);
    if (alignment_mask) {
        *alignment_mask = (18446744073709551615UL) << (E + CC128M_FIELD_EXPONENT_LOW_PART_SIZE);
    }
    cc128m_addr_t top_ie = cc128m_truncate64((cc128m_addr_t)(req_top >> (E + CC128M_FIELD_EXPONENT_LOW_PART_SIZE)), CC128M_FIELD_EXP_NONZERO_BOTTOM_SIZE);







    const cc128m_length_t maskLo = (((cc128m_length_t)1u) << (E + CC128M_FIELD_EXPONENT_LOW_PART_SIZE)) - 1;
    const cc128m_length_t zero65 = 0;
    _Bool lostSignificantBase = (req_base & maskLo) != zero65;
    _Bool lostSignificantTop = (req_top & maskLo) != zero65;





    if (lostSignificantTop) {
        top_ie = cc128m_truncate64(top_ie + 1, CC128M_FIELD_EXP_NONZERO_BOTTOM_SIZE);
    }
# 719 "./cheri_compressed_cap_common.h"
    const cc128m_addr_t len_ie = cc128m_truncate64(top_ie - bot_ie, CC128M_FIELD_EXP_NONZERO_BOTTOM_SIZE);
    _Bool incE = 0;
    if (cc128m_getbits(len_ie, CC128M_FIELD_EXP_NONZERO_BOTTOM_SIZE - 1, 1)) {
        incE = 1;
        lostSignificantBase = lostSignificantBase || cc128m_getbits(bot_ie, 0, 1);
        lostSignificantTop = lostSignificantTop || cc128m_getbits(top_ie, 0, 1);
        bot_ie = cc128m_truncate64(req_base >> (E + CC128M_FIELD_EXPONENT_LOW_PART_SIZE + 1), CC128M_FIELD_EXP_NONZERO_BOTTOM_SIZE);

        if (alignment_mask) {
            *alignment_mask = (18446744073709551615UL) << (E + CC128M_FIELD_EXPONENT_LOW_PART_SIZE + 1);
        }
        const _Bool incT = lostSignificantTop;
        top_ie = cc128m_truncate64((cc128m_addr_t)(req_top >> (E + CC128M_FIELD_EXPONENT_LOW_PART_SIZE + 1)), CC128M_FIELD_EXP_NONZERO_BOTTOM_SIZE);
        if (incT) {
            top_ie = cc128m_truncate64(top_ie + 1, CC128M_FIELD_EXP_NONZERO_BOTTOM_SIZE);
        }
    }
    const uint8_t newE = E + (incE ? 1 : 0);

    *exact = !lostSignificantBase && !lostSignificantTop;

    const cc128m_addr_t expBits = ((uint64_t)(((~(newE)) >> CC128M_FIELD_EXPONENT_LOW_PART_SIZE) & CC128M_FIELD_EXPONENT_HIGH_PART_MAX_VALUE) << CC128M_FIELD_EXPONENT_HIGH_PART_START) | ((uint64_t)((~(newE)) & CC128M_FIELD_EXPONENT_LOW_PART_MAX_VALUE) << CC128M_FIELD_EXPONENT_LOW_PART_START);
    return expBits | ((uint64_t)((!(1)) & CC128M_FIELD_EXPONENT_ZERO_MAX_VALUE) << CC128M_FIELD_EXPONENT_ZERO_START) | ((uint64_t)((top_ie) & CC128M_FIELD_EXP_NONZERO_TOP_MAX_VALUE) << CC128M_FIELD_EXP_NONZERO_TOP_START) |
           ((uint64_t)((bot_ie) & CC128M_FIELD_EXP_NONZERO_BOTTOM_MAX_VALUE) << CC128M_FIELD_EXP_NONZERO_BOTTOM_START);
}

extern _Bool cc128m__precise_is_representable_new_addr(const cc128m_cap_t* oldcap, cc128m_addr_t new_cursor) {

    cc128m_cap_t newcap = *oldcap;
    newcap._cr_cursor = new_cursor;
    struct cc128m_bounds_bits old_bounds_bits = cc128m_extract_bounds_bits(cc128m_compress_raw(oldcap));
    newcap.cr_bounds_valid = cc128m_compute_base_top(old_bounds_bits, new_cursor, &newcap.cr_base, &newcap._cr_top);
    return newcap.cr_base == oldcap->cr_base && newcap._cr_top == oldcap->_cr_top && newcap.cr_bounds_valid &&
           oldcap->cr_bounds_valid;
}

extern _Bool cc128m_cap_bounds_uses_value_for_exp(uint8_t exponent) {
    return exponent < (sizeof(cc128m_addr_t) * 8) - CC128M_FIELD_BOTTOM_ENCODED_SIZE;
}


extern _Bool cc128m_cap_bounds_uses_value(const cc128m_cap_t* cap) {

    ((void) sizeof ((cc128m_pesbt_is_correct(cap)) ? 1 : 0), __extension__ ({ if (cc128m_pesbt_is_correct(cap)) ; else __assert_fail ("cc128m_pesbt_is_correct(cap)", "./cheri_compressed_cap_common.h", 762, __extension__ __PRETTY_FUNCTION__); }));
    return cc128m_cap_bounds_uses_value_for_exp(cap->cr_exp);
}

extern _Bool cc128m_cap_sign_change(cc128m_addr_t addr1, cc128m_addr_t addr2) {

    return ((addr1 ^ addr2) & (1ULL << (63 - 8)));





}

extern _Bool cc128m_cap_sign_change_causes_unrepresentability(const cc128m_cap_t* cap, cc128m_addr_t addr1,
                                                                    cc128m_addr_t addr2) {
    return cc128m_cap_sign_change(addr1, addr2) && cc128m_cap_bounds_uses_value(cap);
}

extern _Bool cc128m_is_representable_with_addr(const cc128m_cap_t* cap, cc128m_addr_t new_addr,
                                                     _Bool precise_representable_check) {


    if (__builtin_expect(cc128m_cap_sign_change_causes_unrepresentability(cap, new_addr, cap->_cr_cursor), 0)) {
        return 0;
    }


    if (__builtin_expect(!cap->cr_bounds_valid, 0)) {
        return 0;
    }

    cc128m_addr_t extended_cursor = cc128m_cap_bounds_address(new_addr);

    if (__builtin_expect(extended_cursor >= cap->cr_base && extended_cursor < cap->_cr_top, 1)) {
        return 1;
    }
    if (precise_representable_check) {
        return cc128m__precise_is_representable_new_addr(cap, new_addr);
    } else {
        return cc128m__fast_is_representable_new_addr(cap, new_addr);
    }
}



extern void cc128m_set_addr(cc128m_cap_t* cap, cc128m_addr_t new_addr) {
    if (cap->cr_tag && cc128m_is_cap_sealed(cap)) {
        cap->cr_tag = 0;
    }
    if (!cc128m_is_representable_with_addr(cap, new_addr, 0)) {

        cap->cr_tag = 0;
        cc128m_decompress_raw(cap->cr_pesbt, new_addr, 0, cap);
    } else {
        cap->_cr_cursor = new_addr;
    }
}

static _Bool cc128m__fast_is_representable_new_addr(const cc128m_cap_t* cap, cc128m_addr_t new_addr) {
    if (cap->_cr_top == ((cc128m_length_t)1u << 64) && cap->cr_base == 0) {
        return 1;
    }




    struct cc128m_bounds_bits bounds = cc128m_extract_bounds_bits(cap->cr_pesbt);

    cc128m_addr_t inc = cc128m_cap_bounds_address(new_addr - cap->_cr_cursor);
    cc128m_addr_t cursor = cc128m_cap_bounds_address(cap->_cr_cursor);


    size_t i_top_shift = bounds.E + 16;
    if (i_top_shift >= 64) {
        i_top_shift = 64 - 1;
    }
    size_t e_shift = bounds.E >= 64 ? 64 - 1 : bounds.E;
    cc128m_saddr_t i_top = (cc128m_saddr_t)inc >> i_top_shift;
    cc128m_addr_t i_mid = cc128m_truncate_addr((cc128m_addr_t)inc >> e_shift, 16);
    cc128m_addr_t a_mid = cc128m_truncate_addr((cc128m_addr_t)cursor >> e_shift, 16);
    cc128m_addr_t B3 = (cc128m_addr_t)cc128m_truncateLSB_16(bounds.B, 3);
    cc128m_addr_t R3 = cc128m_truncate_addr(B3 - 1, 3);
    cc128m_addr_t R = cc128m_truncate_addr(R3 << (16 - 3), 16);
    cc128m_addr_t diff = cc128m_truncate_addr(R - a_mid, 16);
    cc128m_addr_t diff1 = cc128m_truncate_addr(diff - 1, 16);



    _Bool inLimits;
    if (i_top == 0) {
        inLimits = i_mid < diff1;
    } else if (i_top == (cc128m_saddr_t)-1) {
        inLimits = i_mid >= diff && R != a_mid;
    } else {
        inLimits = 0;
    }
    return inLimits || bounds.E >= 50 - 2;

}


extern _Bool cc128m_setbounds_impl(cc128m_cap_t* cap, cc128m_length_t req_len, cc128m_addr_t* alignment_mask) {
    uint64_t req_base = cap->_cr_cursor;
    if (cc128m_is_cap_sealed(cap)) {
        cap->cr_tag = 0;
    }

    if (!cap->cr_bounds_valid) {
        cap->cr_tag = 0;
    }
    _Bool from_large = !cc128m_cap_bounds_uses_value(cap);
    if (!from_large) {



        req_base = cc128m_cap_bounds_address(req_base);
    }

    cc128m_length_t req_top = (cc128m_length_t)req_base + req_len;
    ((void) sizeof ((req_base <= req_top && "Cannot invert base and top") ? 1 : 0), __extension__ ({ if (req_base <= req_top && "Cannot invert base and top") ; else __assert_fail ("req_base <= req_top && \"Cannot invert base and top\"", "./cheri_compressed_cap_common.h", 882, __extension__ __PRETTY_FUNCTION__); }));

    if (req_base < cap->cr_base || req_top > cap->_cr_top) {
        cap->cr_tag = 0;
    }




    _Static_assert(CC128M_FIELD_EXPONENT_LOW_PART_SIZE == 3, "expected 3 bits to be used by");
    _Static_assert(CC128M_FIELD_EXPONENT_HIGH_PART_SIZE == 3, "expected 3 bits to be used by");






    _Bool exact = 0;
    uint32_t new_ebt = cc128m_compute_ebt(req_base, req_top, alignment_mask, &exact);
    cc128m_addr_t new_base;
    cc128m_length_t new_top;
    _Bool new_bounds_valid = cc128m_compute_base_top(cc128m_extract_bounds_bits(((uint64_t)((new_ebt) & CC128M_FIELD_EBT_MAX_VALUE) << CC128M_FIELD_EBT_START)),
                                                    cap->_cr_cursor, &new_base, &new_top);
    if (exact) {







    } else {
        ((void) sizeof (((new_base != req_base || new_top != req_top) && "Was inexact, but neither base nor top different?") ? 1 : 0), __extension__ ({ if ((new_base != req_base || new_top != req_top) && "Was inexact, but neither base nor top different?") ; else __assert_fail ("(new_base != req_base || new_top != req_top) && \"Was inexact, but neither base nor top different?\"", "./cheri_compressed_cap_common.h", 915, __extension__ __PRETTY_FUNCTION__); }));

    }

    _Bool to_small = cc128m_cap_bounds_uses_value_for_exp(cc128m_extract_bounds_bits(new_ebt).E);

    if ((from_large && to_small) && cc128m_cap_bounds_address(cap->_cr_cursor) != cap->_cr_cursor) {
        cap->cr_tag = 0;
    }

    if (cap->cr_tag) {




        ((void) sizeof ((new_top >= new_base) ? 1 : 0), __extension__ ({ if (new_top >= new_base) ; else __assert_fail ("new_top >= new_base", "./cheri_compressed_cap_common.h", 929, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((cc128m_reserved_bits_valid(cap) && "Unknown reserved bits set in tagged capability") ? 1 : 0), __extension__ ({ if (cc128m_reserved_bits_valid(cap) && "Unknown reserved bits set in tagged capability") ; else __assert_fail ("cc128m_reserved_bits_valid(cap) && \"Unknown reserved bits set in tagged capability\"", "./cheri_compressed_cap_common.h", 930, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((new_bounds_valid && "Malformed bounds in tagged capability") ? 1 : 0), __extension__ ({ if (new_bounds_valid && "Malformed bounds in tagged capability") ; else __assert_fail ("new_bounds_valid && \"Malformed bounds in tagged capability\"", "./cheri_compressed_cap_common.h", 931, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((new_base >= cap->cr_base && "Cannot reduce base on tagged capabilities") ? 1 : 0), __extension__ ({ if (new_base >= cap->cr_base && "Cannot reduce base on tagged capabilities") ; else __assert_fail ("new_base >= cap->cr_base && \"Cannot reduce base on tagged capabilities\"", "./cheri_compressed_cap_common.h", 932, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((new_top <= cap->_cr_top && "Cannot increase top on tagged capabilities") ? 1 : 0), __extension__ ({ if (new_top <= cap->_cr_top && "Cannot increase top on tagged capabilities") ; else __assert_fail ("new_top <= cap->_cr_top && \"Cannot increase top on tagged capabilities\"", "./cheri_compressed_cap_common.h", 933, __extension__ __PRETTY_FUNCTION__); }));
    }
    cap->cr_base = new_base;
    cap->_cr_top = new_top;
    cc128m_update_ebt(cap, new_ebt);
    cap->cr_bounds_valid = new_bounds_valid;
    return exact;
}


extern _Bool cc128m_setbounds(cc128m_cap_t* cap, cc128m_length_t req_len) {
    __attribute__((unused)) cc128m_addr_t old_base = cap->cr_base;
    __attribute__((unused)) cc128m_length_t old_top = cap->_cr_top;
    __attribute__((unused)) cc128m_addr_t req_base =
        cc128m_cap_bounds_uses_value(cap) ? cc128m_cap_bounds_address(cap->_cr_cursor) : cap->_cr_cursor;
    __attribute__((unused)) cc128m_length_t req_top = req_len + req_base;
    _Bool exact = cc128m_setbounds_impl(cap, req_len, ((void*)0));
    if (cap->cr_tag) {

        ((void) sizeof ((!cc128m_is_cap_sealed(cap) && "result cannot be sealed and tagged") ? 1 : 0), __extension__ ({ if (!cc128m_is_cap_sealed(cap) && "result cannot be sealed and tagged") ; else __assert_fail ("!cc128m_is_cap_sealed(cap) && \"result cannot be sealed and tagged\"", "./cheri_compressed_cap_common.h", 952, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((((cap->_cr_top - cap->cr_base) >> 64) <= 1 && "length must be smaller than 1 << 65") ? 1 : 0), __extension__ ({ if (((cap->_cr_top - cap->cr_base) >> 64) <= 1 && "length must be smaller than 1 << 65") ; else __assert_fail ("((cap->_cr_top - cap->cr_base) >> 64) <= 1 && \"length must be smaller than 1 << 65\"", "./cheri_compressed_cap_common.h", 954, __extension__ __PRETTY_FUNCTION__); }));

        ((void) sizeof ((cap->cr_base >= old_base && "cannot remain tagged if base was decreased") ? 1 : 0), __extension__ ({ if (cap->cr_base >= old_base && "cannot remain tagged if base was decreased") ; else __assert_fail ("cap->cr_base >= old_base && \"cannot remain tagged if base was decreased\"", "./cheri_compressed_cap_common.h", 955, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((cap->_cr_top <= old_top && "cannot remain tagged if top was increased") ? 1 : 0), __extension__ ({ if (cap->_cr_top <= old_top && "cannot remain tagged if top was increased") ; else __assert_fail ("cap->_cr_top <= old_top && \"cannot remain tagged if top was increased\"", "./cheri_compressed_cap_common.h", 956, __extension__ __PRETTY_FUNCTION__); }));


        ((void) sizeof (((cap->_cr_top <= ((cc128m_length_t)1u << 64) || old_top > ((cc128m_length_t)1u << 64)) && "cannot remain tagged if new top greater 1 << 65") ? 1 : 0), __extension__ ({ if ((cap->_cr_top <= ((cc128m_length_t)1u << 64) || old_top > ((cc128m_length_t)1u << 64)) && "cannot remain tagged if new top greater 1 << 65") ; else __assert_fail ("(cap->_cr_top <= ((cc128m_length_t)1u << 64) || old_top > ((cc128m_length_t)1u << 64)) && \"cannot remain tagged if new top greater 1 << 65\"", "./cheri_compressed_cap_common.h", 960, __extension__ __PRETTY_FUNCTION__); }));

    }

    if (exact) {
        ((void) sizeof ((cc128m_cap_bounds_address(cap->cr_base) == cc128m_cap_bounds_address(req_base) && "base changed but still reported exact") ? 1 : 0), __extension__ ({ if (cc128m_cap_bounds_address(cap->cr_base) == cc128m_cap_bounds_address(req_base) && "base changed but still reported exact") ; else __assert_fail ("cc128m_cap_bounds_address(cap->cr_base) == cc128m_cap_bounds_address(req_base) && \"base changed but still reported exact\"", "./cheri_compressed_cap_common.h", 965, __extension__ __PRETTY_FUNCTION__); }));

        ((void) sizeof ((cc128m_cap_bounds_address(cap->_cr_top) == cc128m_cap_bounds_address(req_top) && "top changed but still reported exact") ? 1 : 0), __extension__ ({ if (cc128m_cap_bounds_address(cap->_cr_top) == cc128m_cap_bounds_address(req_top) && "top changed but still reported exact") ; else __assert_fail ("cc128m_cap_bounds_address(cap->_cr_top) == cc128m_cap_bounds_address(req_top) && \"top changed but still reported exact\"", "./cheri_compressed_cap_common.h", 967, __extension__ __PRETTY_FUNCTION__); }));

    } else {
        ((void) sizeof (((cap->_cr_top != req_top || cap->cr_base != req_base) && "result is exact but reported inexact") ? 1 : 0), __extension__ ({ if ((cap->_cr_top != req_top || cap->cr_base != req_base) && "result is exact but reported inexact") ; else __assert_fail ("(cap->_cr_top != req_top || cap->cr_base != req_base) && \"result is exact but reported inexact\"", "./cheri_compressed_cap_common.h", 970, __extension__ __PRETTY_FUNCTION__); }));

    }
    return exact;
}


extern _Bool cc128m_checked_setbounds(cc128m_cap_t* cap, cc128m_length_t req_len) {
    __attribute__((unused)) cc128m_addr_t req_base =
        cc128m_cap_bounds_uses_value(cap) ? cc128m_cap_bounds_address(cap->_cr_cursor) : cap->_cr_cursor;
    __attribute__((unused)) cc128m_length_t req_top = req_len + req_base;
    if (cap->cr_tag) {

        ((void) sizeof (((!cc128m_is_cap_sealed(cap)) && "cannot be used on tagged sealed capabilities") ? 1 : 0), __extension__ ({ if ((!cc128m_is_cap_sealed(cap)) && "cannot be used on tagged sealed capabilities") ; else __assert_fail ("(!cc128m_is_cap_sealed(cap)) && \"cannot be used on tagged sealed capabilities\"", "./cheri_compressed_cap_common.h", 982, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((req_base >= cap->cr_base) && "cannot decrease base on tagged capabilities") ? 1 : 0), __extension__ ({ if ((req_base >= cap->cr_base) && "cannot decrease base on tagged capabilities") ; else __assert_fail ("(req_base >= cap->cr_base) && \"cannot decrease base on tagged capabilities\"", "./cheri_compressed_cap_common.h", 983, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((req_top <= cap->_cr_top) && "cannot increase top on tagged capabilities") ? 1 : 0), __extension__ ({ if ((req_top <= cap->_cr_top) && "cannot increase top on tagged capabilities") ; else __assert_fail ("(req_top <= cap->_cr_top) && \"cannot increase top on tagged capabilities\"", "./cheri_compressed_cap_common.h", 984, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((req_len < ((cc128m_length_t)1u << 64)) && "requested length must be smaller than max length") ? 1 : 0), __extension__ ({ if ((req_len < ((cc128m_length_t)1u << 64)) && "requested length must be smaller than max length") ; else __assert_fail ("(req_len < ((cc128m_length_t)1u << 64)) && \"requested length must be smaller than max length\"", "./cheri_compressed_cap_common.h", 985, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((req_top < ((cc128m_length_t)1u << 64)) && "new top must be smaller than max length") ? 1 : 0), __extension__ ({ if ((req_top < ((cc128m_length_t)1u << 64)) && "new top must be smaller than max length") ; else __assert_fail ("(req_top < ((cc128m_length_t)1u << 64)) && \"new top must be smaller than max length\"", "./cheri_compressed_cap_common.h", 986, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((cap->_cr_top <= ((cc128m_length_t)1u << 64)) && "input capability top must be less than max top") ? 1 : 0), __extension__ ({ if ((cap->_cr_top <= ((cc128m_length_t)1u << 64)) && "input capability top must be less than max top") ; else __assert_fail ("(cap->_cr_top <= ((cc128m_length_t)1u << 64)) && \"input capability top must be less than max top\"", "./cheri_compressed_cap_common.h", 987, __extension__ __PRETTY_FUNCTION__); }));
    }
    return cc128m_setbounds(cap, req_len);
}


extern cc128m_cap_t cc128m__make_max_perms_cap_common(cc128m_addr_t base, cc128m_addr_t cursor, cc128m_length_t top,
                                                          __attribute__((unused)) uint8_t lvbits) {
    cc128m_cap_t creg;
    memset(&creg, 0, sizeof(creg));
    ((void) sizeof ((base <= top && "Invalid arguments") ? 1 : 0), __extension__ ({ if (base <= top && "Invalid arguments") ; else __assert_fail ("base <= top && \"Invalid arguments\"", "./cheri_compressed_cap_common.h", 997, __extension__ __PRETTY_FUNCTION__); }));
    creg.cr_base = base;
    creg._cr_cursor = cursor;
    creg.cr_bounds_valid = 1;
    creg._cr_top = top;
    creg.cr_pesbt = ((uint64_t)((0x3FFFFUL) & CC128M_FIELD_ALL_PERMS_MAX_VALUE) << CC128M_FIELD_ALL_PERMS_START) | ((uint64_t)((CC128M_OTYPE_UNSEALED) & CC128M_FIELD_OTYPE_MAX_VALUE) << CC128M_FIELD_OTYPE_START);
    creg.cr_tag = 1;
    creg.cr_exp = CC128M_RESET_EXP;
    ((void) sizeof ((lvbits <= 1 && "We only support local-global levels.") ? 1 : 0), __extension__ ({ if (lvbits <= 1 && "We only support local-global levels.") ; else __assert_fail ("lvbits <= 1 && \"We only support local-global levels.\"", "./cheri_compressed_cap_common.h", 1005, __extension__ __PRETTY_FUNCTION__); }));



    _Bool exact_input = 0;
    cc128m_update_ebt(&creg, cc128m_compute_ebt(creg.cr_base, creg._cr_top, ((void*)0), &exact_input));
    ((void) sizeof ((exact_input && "Invalid arguments") ? 1 : 0), __extension__ ({ if (exact_input && "Invalid arguments") ; else __assert_fail ("exact_input && \"Invalid arguments\"", "./cheri_compressed_cap_common.h", 1011, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((cc128m_is_representable_cap_exact(&creg)) ? 1 : 0), __extension__ ({ if (cc128m_is_representable_cap_exact(&creg)) ; else __assert_fail ("_cc_N(is_representable_cap_exact)(&creg)", "./cheri_compressed_cap_common.h", 1012, __extension__ __PRETTY_FUNCTION__); }));
    return creg;
}
# 1030 "./cheri_compressed_cap_common.h"
extern cc128m_cap_t cc128m_make_max_perms_cap(cc128m_addr_t base, cc128m_addr_t cursor, cc128m_length_t top) {
    return cc128m__make_max_perms_cap_common(base, cursor, top, 1);
}



extern cc128m_addr_t cc128m_get_alignment_mask(cc128m_addr_t req_length) {
    if (req_length == 0) {



        return (18446744073709551615UL);
    }


    cc128m_cap_t tmpcap = cc128m_make_max_perms_cap(0, 0, ((cc128m_length_t)1u << 64));
    cc128m_addr_t mask = 0;
    cc128m_setbounds_impl(&tmpcap, req_length, &mask);
    return mask;
}

extern cc128m_cap_t cc128m_make_null_derived_cap_ext(cc128m_addr_t addr, __attribute__((unused)) uint8_t lvbits) {
    cc128m_cap_t creg;
    memset(&creg, 0, sizeof(creg));
    creg._cr_cursor = addr;
    creg._cr_top = ((cc128m_length_t)1u << 64);
    creg.cr_pesbt = CC128M_NULL_PESBT;
    creg.cr_bounds_valid = 1;
    creg.cr_exp = CC128M_NULL_EXP;
    ((void) sizeof ((cc128m_is_representable_cap_exact(&creg)) ? 1 : 0), __extension__ ({ if (cc128m_is_representable_cap_exact(&creg)) ; else __assert_fail ("cc128m_is_representable_cap_exact(&creg)", "./cheri_compressed_cap_common.h", 1059, __extension__ __PRETTY_FUNCTION__); }));



    return creg;
}

extern cc128m_cap_t cc128m_make_null_derived_cap(cc128m_addr_t addr) {
    return cc128m_make_null_derived_cap_ext(addr, 1);
}

extern cc128m_addr_t cc128m_get_required_alignment(cc128m_addr_t req_length) {


    return ~cc128m_get_alignment_mask(req_length) + 1;
}

extern cc128m_addr_t cc128m_get_representable_length(cc128m_addr_t req_length) {
    cc128m_addr_t mask = cc128m_get_alignment_mask(req_length);
    return (req_length + ~mask) & mask;
}
# 201 "./cheri_compressed_cap_128m.h" 2

extern cc128m_addr_t cc128m_get_all_permissions(const cc128m_cap_t* cap) {
    return (cc128m_addr_t)cc128m_getbits((cap->cr_pesbt), CC128M_FIELD_ALL_PERMS_START, CC128M_FIELD_ALL_PERMS_SIZE);
}
extern _Bool cc128m_set_permissions(cc128m_cap_t* cap, cc128m_addr_t permissions) {
    ((void) sizeof ((((permissions & 0x3FFFFUL) == permissions) && "invalid permissions") ? 1 : 0), __extension__ ({ if (((permissions & 0x3FFFFUL) == permissions) && "invalid permissions") ; else __assert_fail ("((permissions & 0x3FFFFUL) == permissions) && \"invalid permissions\"", "./cheri_compressed_cap_128m.h", 206, __extension__ __PRETTY_FUNCTION__); }));
    cap->cr_pesbt = __extension__({ ((void) sizeof ((permissions <= CC128M_FIELD_ALL_PERMS_MAX_VALUE) ? 1 : 0), __extension__ ({ if (permissions <= CC128M_FIELD_ALL_PERMS_MAX_VALUE) ; else __assert_fail ("permissions <= CC128M_FIELD_ALL_PERMS_MAX_VALUE", "./cheri_compressed_cap_128m.h", 207, __extension__ __PRETTY_FUNCTION__); })); ((cap->cr_pesbt) & ~CC128M_FIELD_ALL_PERMS_MASK64) | ((uint64_t)((permissions) & CC128M_FIELD_ALL_PERMS_MAX_VALUE) << CC128M_FIELD_ALL_PERMS_START); });
    return 1;
}

extern cc128m_addr_t cc128m_get_reserved(__attribute__((unused)) const cc128m_cap_t* cap) { return 0; }

extern _Bool cc128m_compute_base_top_special_cases(struct cc128m_bounds_bits bounds, cc128m_addr_t* base_out,
                                                         cc128m_length_t* top_out, _Bool* valid) {
    if (bounds.E > 50) {
        *base_out = 0;
        *top_out = ((cc128m_length_t)1u << 64);
        *valid = bounds.E == 63;
        return 1;
    }
    return 0;
}


_Static_assert((CC128M_MEM_XOR_MASK) == (0UL), "");
# 53 "./cheri_compressed_cap.h" 2
# 1 "./cheri_compressed_cap_128r.h" 1
# 67 "./cheri_compressed_cap_128r.h"
__extension__ typedef unsigned __int128 cc128r_length_t;
__extension__ typedef signed __int128 cc128r_offset_t;
typedef uint64_t cc128r_addr_t;
typedef int64_t cc128r_saddr_t;
# 1 "./cheri_compressed_cap_macros.h" 1
# 72 "./cheri_compressed_cap_128r.h" 2
typedef enum CC128R_Mode { CC128R_MODE_CAP = 0, CC128R_MODE_INT = 1 } CC128R_Mode;


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
enum {
    CC128R_FIELD_RESERVED1_START = (121 - 64), CC128R_FIELD_RESERVED1_LAST = (127 - 64), CC128R_FIELD_RESERVED1_SIZE = CC128R_FIELD_RESERVED1_LAST - CC128R_FIELD_RESERVED1_START + 1, CC128R_FIELD_RESERVED1_MASK_NOT_SHIFTED = ((1UL << (CC128R_FIELD_RESERVED1_SIZE)) - 1UL), CC128R_FIELD_RESERVED1_MASK64 = (uint64_t)CC128R_FIELD_RESERVED1_MASK_NOT_SHIFTED << CC128R_FIELD_RESERVED1_START, CC128R_FIELD_RESERVED1_MAX_VALUE = CC128R_FIELD_RESERVED1_MASK_NOT_SHIFTED,
    CC128R_FIELD_SDP_START = (117 - 64), CC128R_FIELD_SDP_LAST = (120 - 64), CC128R_FIELD_SDP_SIZE = CC128R_FIELD_SDP_LAST - CC128R_FIELD_SDP_START + 1, CC128R_FIELD_SDP_MASK_NOT_SHIFTED = ((1UL << (CC128R_FIELD_SDP_SIZE)) - 1UL), CC128R_FIELD_SDP_MASK64 = (uint64_t)CC128R_FIELD_SDP_MASK_NOT_SHIFTED << CC128R_FIELD_SDP_START, CC128R_FIELD_SDP_MAX_VALUE = CC128R_FIELD_SDP_MASK_NOT_SHIFTED,
    CC128R_FIELD_FLAGS_START = (116 - 64), CC128R_FIELD_FLAGS_LAST = (116 - 64), CC128R_FIELD_FLAGS_SIZE = CC128R_FIELD_FLAGS_LAST - CC128R_FIELD_FLAGS_START + 1, CC128R_FIELD_FLAGS_MASK_NOT_SHIFTED = ((1UL << (CC128R_FIELD_FLAGS_SIZE)) - 1UL), CC128R_FIELD_FLAGS_MASK64 = (uint64_t)CC128R_FIELD_FLAGS_MASK_NOT_SHIFTED << CC128R_FIELD_FLAGS_START, CC128R_FIELD_FLAGS_MAX_VALUE = CC128R_FIELD_FLAGS_MASK_NOT_SHIFTED,
    CC128R_FIELD_AP_M_START = (108 - 64), CC128R_FIELD_AP_M_LAST = (116 - 64), CC128R_FIELD_AP_M_SIZE = CC128R_FIELD_AP_M_LAST - CC128R_FIELD_AP_M_START + 1, CC128R_FIELD_AP_M_MASK_NOT_SHIFTED = ((1UL << (CC128R_FIELD_AP_M_SIZE)) - 1UL), CC128R_FIELD_AP_M_MASK64 = (uint64_t)CC128R_FIELD_AP_M_MASK_NOT_SHIFTED << CC128R_FIELD_AP_M_START, CC128R_FIELD_AP_M_MAX_VALUE = CC128R_FIELD_AP_M_MASK_NOT_SHIFTED,
    CC128R_FIELD_MODE_START = (116 - 64), CC128R_FIELD_MODE_LAST = (116 - 64), CC128R_FIELD_MODE_SIZE = CC128R_FIELD_MODE_LAST - CC128R_FIELD_MODE_START + 1, CC128R_FIELD_MODE_MASK_NOT_SHIFTED = ((1UL << (CC128R_FIELD_MODE_SIZE)) - 1UL), CC128R_FIELD_MODE_MASK64 = (uint64_t)CC128R_FIELD_MODE_MASK_NOT_SHIFTED << CC128R_FIELD_MODE_START, CC128R_FIELD_MODE_MAX_VALUE = CC128R_FIELD_MODE_MASK_NOT_SHIFTED,
    CC128R_FIELD_AP_START = (108 - 64), CC128R_FIELD_AP_LAST = (115 - 64), CC128R_FIELD_AP_SIZE = CC128R_FIELD_AP_LAST - CC128R_FIELD_AP_START + 1, CC128R_FIELD_AP_MASK_NOT_SHIFTED = ((1UL << (CC128R_FIELD_AP_SIZE)) - 1UL), CC128R_FIELD_AP_MASK64 = (uint64_t)CC128R_FIELD_AP_MASK_NOT_SHIFTED << CC128R_FIELD_AP_START, CC128R_FIELD_AP_MAX_VALUE = CC128R_FIELD_AP_MASK_NOT_SHIFTED,
    CC128R_FIELD_LEVEL_START = (107 - 64), CC128R_FIELD_LEVEL_LAST = (107 - 64), CC128R_FIELD_LEVEL_SIZE = CC128R_FIELD_LEVEL_LAST - CC128R_FIELD_LEVEL_START + 1, CC128R_FIELD_LEVEL_MASK_NOT_SHIFTED = ((1UL << (CC128R_FIELD_LEVEL_SIZE)) - 1UL), CC128R_FIELD_LEVEL_MASK64 = (uint64_t)CC128R_FIELD_LEVEL_MASK_NOT_SHIFTED << CC128R_FIELD_LEVEL_START, CC128R_FIELD_LEVEL_MAX_VALUE = CC128R_FIELD_LEVEL_MASK_NOT_SHIFTED,
    CC128R_FIELD_RESERVED0_START = (92 - 64), CC128R_FIELD_RESERVED0_LAST = (106 - 64), CC128R_FIELD_RESERVED0_SIZE = CC128R_FIELD_RESERVED0_LAST - CC128R_FIELD_RESERVED0_START + 1, CC128R_FIELD_RESERVED0_MASK_NOT_SHIFTED = ((1UL << (CC128R_FIELD_RESERVED0_SIZE)) - 1UL), CC128R_FIELD_RESERVED0_MASK64 = (uint64_t)CC128R_FIELD_RESERVED0_MASK_NOT_SHIFTED << CC128R_FIELD_RESERVED0_START, CC128R_FIELD_RESERVED0_MAX_VALUE = CC128R_FIELD_RESERVED0_MASK_NOT_SHIFTED,
    CC128R_FIELD_OTYPE_START = (91 - 64), CC128R_FIELD_OTYPE_LAST = (91 - 64), CC128R_FIELD_OTYPE_SIZE = CC128R_FIELD_OTYPE_LAST - CC128R_FIELD_OTYPE_START + 1, CC128R_FIELD_OTYPE_MASK_NOT_SHIFTED = ((1UL << (CC128R_FIELD_OTYPE_SIZE)) - 1UL), CC128R_FIELD_OTYPE_MASK64 = (uint64_t)CC128R_FIELD_OTYPE_MASK_NOT_SHIFTED << CC128R_FIELD_OTYPE_START, CC128R_FIELD_OTYPE_MAX_VALUE = CC128R_FIELD_OTYPE_MASK_NOT_SHIFTED,
    CC128R_FIELD_EBT_START = (64 - 64), CC128R_FIELD_EBT_LAST = (90 - 64), CC128R_FIELD_EBT_SIZE = CC128R_FIELD_EBT_LAST - CC128R_FIELD_EBT_START + 1, CC128R_FIELD_EBT_MASK_NOT_SHIFTED = ((1UL << (CC128R_FIELD_EBT_SIZE)) - 1UL), CC128R_FIELD_EBT_MASK64 = (uint64_t)CC128R_FIELD_EBT_MASK_NOT_SHIFTED << CC128R_FIELD_EBT_START, CC128R_FIELD_EBT_MAX_VALUE = CC128R_FIELD_EBT_MASK_NOT_SHIFTED,

    CC128R_FIELD_EXPONENT_FORMAT_START = (90 - 64), CC128R_FIELD_EXPONENT_FORMAT_LAST = (90 - 64), CC128R_FIELD_EXPONENT_FORMAT_SIZE = CC128R_FIELD_EXPONENT_FORMAT_LAST - CC128R_FIELD_EXPONENT_FORMAT_START + 1, CC128R_FIELD_EXPONENT_FORMAT_MASK_NOT_SHIFTED = ((1UL << (CC128R_FIELD_EXPONENT_FORMAT_SIZE)) - 1UL), CC128R_FIELD_EXPONENT_FORMAT_MASK64 = (uint64_t)CC128R_FIELD_EXPONENT_FORMAT_MASK_NOT_SHIFTED << CC128R_FIELD_EXPONENT_FORMAT_START, CC128R_FIELD_EXPONENT_FORMAT_MAX_VALUE = CC128R_FIELD_EXPONENT_FORMAT_MASK_NOT_SHIFTED,

    CC128R_FIELD_INTERNAL_EXPONENT_SIZE = CC128R_FIELD_EXPONENT_FORMAT_SIZE,
    CC128R_FIELD_TOP_ENCODED_START = (78 - 64), CC128R_FIELD_TOP_ENCODED_LAST = (89 - 64), CC128R_FIELD_TOP_ENCODED_SIZE = CC128R_FIELD_TOP_ENCODED_LAST - CC128R_FIELD_TOP_ENCODED_START + 1, CC128R_FIELD_TOP_ENCODED_MASK_NOT_SHIFTED = ((1UL << (CC128R_FIELD_TOP_ENCODED_SIZE)) - 1UL), CC128R_FIELD_TOP_ENCODED_MASK64 = (uint64_t)CC128R_FIELD_TOP_ENCODED_MASK_NOT_SHIFTED << CC128R_FIELD_TOP_ENCODED_START, CC128R_FIELD_TOP_ENCODED_MAX_VALUE = CC128R_FIELD_TOP_ENCODED_MASK_NOT_SHIFTED,
    CC128R_FIELD_BOTTOM_ENCODED_START = (64 - 64), CC128R_FIELD_BOTTOM_ENCODED_LAST = (77 - 64), CC128R_FIELD_BOTTOM_ENCODED_SIZE = CC128R_FIELD_BOTTOM_ENCODED_LAST - CC128R_FIELD_BOTTOM_ENCODED_START + 1, CC128R_FIELD_BOTTOM_ENCODED_MASK_NOT_SHIFTED = ((1UL << (CC128R_FIELD_BOTTOM_ENCODED_SIZE)) - 1UL), CC128R_FIELD_BOTTOM_ENCODED_MASK64 = (uint64_t)CC128R_FIELD_BOTTOM_ENCODED_MASK_NOT_SHIFTED << CC128R_FIELD_BOTTOM_ENCODED_START, CC128R_FIELD_BOTTOM_ENCODED_MAX_VALUE = CC128R_FIELD_BOTTOM_ENCODED_MASK_NOT_SHIFTED,



    CC128R_FIELD_EXP_ZERO_TOP_START = (78 - 64), CC128R_FIELD_EXP_ZERO_TOP_LAST = (89 - 64), CC128R_FIELD_EXP_ZERO_TOP_SIZE = CC128R_FIELD_EXP_ZERO_TOP_LAST - CC128R_FIELD_EXP_ZERO_TOP_START + 1, CC128R_FIELD_EXP_ZERO_TOP_MASK_NOT_SHIFTED = ((1UL << (CC128R_FIELD_EXP_ZERO_TOP_SIZE)) - 1UL), CC128R_FIELD_EXP_ZERO_TOP_MASK64 = (uint64_t)CC128R_FIELD_EXP_ZERO_TOP_MASK_NOT_SHIFTED << CC128R_FIELD_EXP_ZERO_TOP_START, CC128R_FIELD_EXP_ZERO_TOP_MAX_VALUE = CC128R_FIELD_EXP_ZERO_TOP_MASK_NOT_SHIFTED,
    CC128R_FIELD_EXP_ZERO_BOTTOM_START = (64 - 64), CC128R_FIELD_EXP_ZERO_BOTTOM_LAST = (77 - 64), CC128R_FIELD_EXP_ZERO_BOTTOM_SIZE = CC128R_FIELD_EXP_ZERO_BOTTOM_LAST - CC128R_FIELD_EXP_ZERO_BOTTOM_START + 1, CC128R_FIELD_EXP_ZERO_BOTTOM_MASK_NOT_SHIFTED = ((1UL << (CC128R_FIELD_EXP_ZERO_BOTTOM_SIZE)) - 1UL), CC128R_FIELD_EXP_ZERO_BOTTOM_MASK64 = (uint64_t)CC128R_FIELD_EXP_ZERO_BOTTOM_MASK_NOT_SHIFTED << CC128R_FIELD_EXP_ZERO_BOTTOM_START, CC128R_FIELD_EXP_ZERO_BOTTOM_MAX_VALUE = CC128R_FIELD_EXP_ZERO_BOTTOM_MASK_NOT_SHIFTED,

    CC128R_FIELD_EXP_NONZERO_TOP_START = (81 - 64), CC128R_FIELD_EXP_NONZERO_TOP_LAST = (89 - 64), CC128R_FIELD_EXP_NONZERO_TOP_SIZE = CC128R_FIELD_EXP_NONZERO_TOP_LAST - CC128R_FIELD_EXP_NONZERO_TOP_START + 1, CC128R_FIELD_EXP_NONZERO_TOP_MASK_NOT_SHIFTED = ((1UL << (CC128R_FIELD_EXP_NONZERO_TOP_SIZE)) - 1UL), CC128R_FIELD_EXP_NONZERO_TOP_MASK64 = (uint64_t)CC128R_FIELD_EXP_NONZERO_TOP_MASK_NOT_SHIFTED << CC128R_FIELD_EXP_NONZERO_TOP_START, CC128R_FIELD_EXP_NONZERO_TOP_MAX_VALUE = CC128R_FIELD_EXP_NONZERO_TOP_MASK_NOT_SHIFTED,
    CC128R_FIELD_EXPONENT_HIGH_PART_START = (78 - 64), CC128R_FIELD_EXPONENT_HIGH_PART_LAST = (80 - 64), CC128R_FIELD_EXPONENT_HIGH_PART_SIZE = CC128R_FIELD_EXPONENT_HIGH_PART_LAST - CC128R_FIELD_EXPONENT_HIGH_PART_START + 1, CC128R_FIELD_EXPONENT_HIGH_PART_MASK_NOT_SHIFTED = ((1UL << (CC128R_FIELD_EXPONENT_HIGH_PART_SIZE)) - 1UL), CC128R_FIELD_EXPONENT_HIGH_PART_MASK64 = (uint64_t)CC128R_FIELD_EXPONENT_HIGH_PART_MASK_NOT_SHIFTED << CC128R_FIELD_EXPONENT_HIGH_PART_START, CC128R_FIELD_EXPONENT_HIGH_PART_MAX_VALUE = CC128R_FIELD_EXPONENT_HIGH_PART_MASK_NOT_SHIFTED,
    CC128R_FIELD_EXP_NONZERO_BOTTOM_START = (67 - 64), CC128R_FIELD_EXP_NONZERO_BOTTOM_LAST = (77 - 64), CC128R_FIELD_EXP_NONZERO_BOTTOM_SIZE = CC128R_FIELD_EXP_NONZERO_BOTTOM_LAST - CC128R_FIELD_EXP_NONZERO_BOTTOM_START + 1, CC128R_FIELD_EXP_NONZERO_BOTTOM_MASK_NOT_SHIFTED = ((1UL << (CC128R_FIELD_EXP_NONZERO_BOTTOM_SIZE)) - 1UL), CC128R_FIELD_EXP_NONZERO_BOTTOM_MASK64 = (uint64_t)CC128R_FIELD_EXP_NONZERO_BOTTOM_MASK_NOT_SHIFTED << CC128R_FIELD_EXP_NONZERO_BOTTOM_START, CC128R_FIELD_EXP_NONZERO_BOTTOM_MAX_VALUE = CC128R_FIELD_EXP_NONZERO_BOTTOM_MASK_NOT_SHIFTED,
    CC128R_FIELD_EXPONENT_LOW_PART_START = (64 - 64), CC128R_FIELD_EXPONENT_LOW_PART_LAST = (66 - 64), CC128R_FIELD_EXPONENT_LOW_PART_SIZE = CC128R_FIELD_EXPONENT_LOW_PART_LAST - CC128R_FIELD_EXPONENT_LOW_PART_START + 1, CC128R_FIELD_EXPONENT_LOW_PART_MASK_NOT_SHIFTED = ((1UL << (CC128R_FIELD_EXPONENT_LOW_PART_SIZE)) - 1UL), CC128R_FIELD_EXPONENT_LOW_PART_MASK64 = (uint64_t)CC128R_FIELD_EXPONENT_LOW_PART_MASK_NOT_SHIFTED << CC128R_FIELD_EXPONENT_LOW_PART_START, CC128R_FIELD_EXPONENT_LOW_PART_MAX_VALUE = CC128R_FIELD_EXPONENT_LOW_PART_MASK_NOT_SHIFTED,
};
#pragma GCC diagnostic pop
# 127 "./cheri_compressed_cap_128r.h"
_Static_assert(((0xf)) == (CC128R_FIELD_SDP_MAX_VALUE), "");
# 136 "./cheri_compressed_cap_128r.h"
enum CC128R_OTypes {
    CC128R_MAX_REPRESENTABLE_OTYPE = ((1u << CC128R_FIELD_OTYPE_SIZE) - 1u),
    CC128R_OTYPE_UNSEALED = ((0u)), CC128R_OTYPE_UNSEALED_SIGNED = ((0u)),
    CC128R_OTYPE_SENTRY = ((1u)), CC128R_OTYPE_SENTRY_SIGNED = ((1u)),
    CC128R_MIN_RESERVED_OTYPE = CC128R_OTYPE_UNSEALED,
    CC128R_MAX_RESERVED_OTYPE = CC128R_OTYPE_SENTRY,
};





_Static_assert((14) == (CC128R_FIELD_EXP_ZERO_BOTTOM_SIZE), "");
# 162 "./cheri_compressed_cap_128r.h"
# 1 "./cheri_compressed_cap_common.h" 1
# 40 "./cheri_compressed_cap_common.h"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
enum {


    CC128R_RESET_EXP = 52,
    CC128R_RESET_T = 1u << (64 - CC128R_RESET_EXP - CC128R_FIELD_EXPONENT_HIGH_PART_SIZE),







    CC128R_NULL_EXP = CC128R_RESET_EXP,
    CC128R_NULL_T = CC128R_RESET_T,

    CC128R_RESET_EBT = ((uint64_t)((!(1)) & CC128R_FIELD_EXPONENT_FORMAT_MAX_VALUE) << CC128R_FIELD_EXPONENT_FORMAT_START) | ((uint64_t)(((52 - (CC128R_RESET_EXP)) >> CC128R_FIELD_EXPONENT_LOW_PART_SIZE) & CC128R_FIELD_EXPONENT_HIGH_PART_MAX_VALUE) << CC128R_FIELD_EXPONENT_HIGH_PART_START) | ((uint64_t)((52 - (CC128R_RESET_EXP)) & CC128R_FIELD_EXPONENT_LOW_PART_MAX_VALUE) << CC128R_FIELD_EXPONENT_LOW_PART_START) |
                       ((uint64_t)((CC128R_RESET_T) & CC128R_FIELD_EXP_NONZERO_TOP_MAX_VALUE) << CC128R_FIELD_EXP_NONZERO_TOP_START) | ((uint64_t)((0) & CC128R_FIELD_EXP_NONZERO_BOTTOM_MAX_VALUE) << CC128R_FIELD_EXP_NONZERO_BOTTOM_START),
    CC128R_RESET_PESBT = CC128R_RESET_EBT | (((uint64_t)(((0xf)) & CC128R_FIELD_SDP_MAX_VALUE) << CC128R_FIELD_SDP_START) | ((uint64_t)((1 == 0 ? 0x13f : 0x1ff) & CC128R_FIELD_AP_MAX_VALUE) << CC128R_FIELD_AP_START) | ((uint64_t)((((1UL << (1)) - 1UL)) & CC128R_FIELD_LEVEL_MAX_VALUE) << CC128R_FIELD_LEVEL_START) | ((uint64_t)((1) & CC128R_FIELD_MODE_MAX_VALUE) << CC128R_FIELD_MODE_START)) |
                         ((uint64_t)((CC128R_OTYPE_UNSEALED) & CC128R_FIELD_OTYPE_MAX_VALUE) << CC128R_FIELD_OTYPE_START),
    CC128R_NULL_EBT = ((uint64_t)((!(1)) & CC128R_FIELD_EXPONENT_FORMAT_MAX_VALUE) << CC128R_FIELD_EXPONENT_FORMAT_START) | ((uint64_t)(((52 - (CC128R_NULL_EXP)) >> CC128R_FIELD_EXPONENT_LOW_PART_SIZE) & CC128R_FIELD_EXPONENT_HIGH_PART_MAX_VALUE) << CC128R_FIELD_EXPONENT_HIGH_PART_START) | ((uint64_t)((52 - (CC128R_NULL_EXP)) & CC128R_FIELD_EXPONENT_LOW_PART_MAX_VALUE) << CC128R_FIELD_EXPONENT_LOW_PART_START) |
                      ((uint64_t)((CC128R_NULL_T) & CC128R_FIELD_EXP_NONZERO_TOP_MAX_VALUE) << CC128R_FIELD_EXP_NONZERO_TOP_START) | ((uint64_t)((0) & CC128R_FIELD_EXP_NONZERO_BOTTOM_MAX_VALUE) << CC128R_FIELD_EXP_NONZERO_BOTTOM_START),
    CC128R_NULL_PESBT = CC128R_NULL_EBT | ((uint64_t)((CC128R_OTYPE_UNSEALED) & CC128R_FIELD_OTYPE_MAX_VALUE) << CC128R_FIELD_OTYPE_START),

    CC128R_MEM_XOR_MASK = CC128R_NULL_PESBT,
    CC128R_NULL_XOR_MASK __attribute__((deprecated("Use _MEM_XOR_MASK instead"))) = CC128R_MEM_XOR_MASK,
    CC128R_MAX_LEVEL_VALUE = ((1UL << (1)) - 1UL),
};
#pragma GCC diagnostic pop
# 89 "./cheri_compressed_cap_common.h"
enum { CC128R_FIELD_LEN_MSB_SIZE = 0 };



_Static_assert((CC128R_FIELD_INTERNAL_EXPONENT_SIZE + CC128R_FIELD_EXP_ZERO_TOP_SIZE + CC128R_FIELD_LEN_MSB_SIZE + CC128R_FIELD_EXP_ZERO_BOTTOM_SIZE) == (CC128R_FIELD_EBT_SIZE), "");


_Static_assert((CC128R_FIELD_INTERNAL_EXPONENT_SIZE + CC128R_FIELD_LEN_MSB_SIZE + CC128R_FIELD_TOP_ENCODED_SIZE + CC128R_FIELD_BOTTOM_ENCODED_SIZE) == (CC128R_FIELD_EBT_SIZE), "");


_Static_assert((CC128R_FIELD_INTERNAL_EXPONENT_SIZE + CC128R_FIELD_LEN_MSB_SIZE + CC128R_FIELD_EXP_NONZERO_TOP_SIZE + CC128R_FIELD_EXP_NONZERO_BOTTOM_SIZE + CC128R_FIELD_EXPONENT_HIGH_PART_SIZE + CC128R_FIELD_EXPONENT_LOW_PART_SIZE) == (CC128R_FIELD_EBT_SIZE), "");




_Static_assert((CC128R_FIELD_EBT_START) == (0), "");

_Static_assert(CC128R_MIN_RESERVED_OTYPE >= 0, "MIN_RESERVED_OTYPE is signed?");
_Static_assert(CC128R_MIN_RESERVED_OTYPE < CC128R_MAX_RESERVED_OTYPE, "MIN_RESERVED_OTYPE greater than MAX_RESERVED_OTYPE?");

_Static_assert(CC128R_MIN_RESERVED_OTYPE <= CC128R_MAX_REPRESENTABLE_OTYPE, "MIN_RESERVED_OTYPE out of range?");
_Static_assert(CC128R_MAX_RESERVED_OTYPE <= CC128R_MAX_REPRESENTABLE_OTYPE, "MAX_RESERVED_OTYPE out of range?");


typedef struct cc128r_cap cc128r_cap_t;

extern uint8_t cc128r_get_flags(const cc128r_cap_t* cap);
extern uint32_t cc128r_get_otype(const cc128r_cap_t* cap);
extern uint32_t cc128r_get_level(const cc128r_cap_t* cap);
extern cc128r_addr_t cc128r_get_perms(const cc128r_cap_t* cap);
extern cc128r_addr_t cc128r_get_reserved(const cc128r_cap_t* cap);
extern _Bool cc128r_reserved_bits_valid(const cc128r_cap_t* cap) { return cc128r_get_reserved(cap) == 0; }
extern cc128r_addr_t cc128r_get_uperms(const cc128r_cap_t* cap);

extern cc128r_addr_t cc128r_get_all_permissions(const cc128r_cap_t* cap);
extern _Bool cc128r_has_permissions(const cc128r_cap_t* cap, cc128r_addr_t permissions) {
    return (cc128r_get_all_permissions(cap) & permissions) == permissions;
}
extern _Bool cc128r_set_permissions(cc128r_cap_t* cap, cc128r_addr_t permissions);

extern CC128R_Mode cc128r_get_execution_mode(const cc128r_cap_t* cap);
extern _Bool cc128r_set_execution_mode(cc128r_cap_t* cap, CC128R_Mode new_mode);



struct cc128r_cap {







    cc128r_addr_t _cr_cursor;
    cc128r_addr_t cr_pesbt;

    cc128r_length_t _cr_top;
    cc128r_addr_t cr_base;
    uint8_t cr_tag;
    uint8_t cr_bounds_valid;

    uint8_t cr_lvbits;

    uint8_t cr_exp;
    uint8_t cr_extra;
# 179 "./cheri_compressed_cap_common.h"
};

extern _Bool cc128r_exactly_equal(const cc128r_cap_t* a, const cc128r_cap_t* b) {
    return a->cr_tag == b->cr_tag && a->_cr_cursor == b->_cr_cursor && a->cr_pesbt == b->cr_pesbt;
}

extern uint8_t cc128r_get_lvbits(__attribute__((unused)) const cc128r_cap_t* cap) {

    return cap->cr_lvbits;



}

extern _Bool cc128r_raw_equal(const cc128r_cap_t* a, const cc128r_cap_t* b) {
    return a->_cr_cursor == b->_cr_cursor && a->cr_pesbt == b->cr_pesbt && a->_cr_top == b->_cr_top &&
           a->cr_base == b->cr_base && a->cr_tag == b->cr_tag && a->cr_bounds_valid == b->cr_bounds_valid &&
           cc128r_get_lvbits(a) == cc128r_get_lvbits(b) && a->cr_exp == b->cr_exp && a->cr_extra == b->cr_extra;
}


extern uint32_t cc128r_idx_MSNZ(uint64_t x) {
# 218 "./cheri_compressed_cap_common.h"
    ((void) sizeof ((x != 0) ? 1 : 0), __extension__ ({ if (x != 0) ; else __assert_fail ("x != 0", "./cheri_compressed_cap_common.h", 218, __extension__ __PRETTY_FUNCTION__); }));
    uint32_t r = 63u - (uint32_t)__builtin_clzll(x);

    return r;
}





extern uint32_t cc128r_compute_e(cc128r_addr_t rlength, uint32_t bwidth) {
    if (rlength < (1u << (bwidth - 1)))
        return 0;

    return (cc128r_idx_MSNZ(rlength) - (bwidth - 2));
}

extern uint32_t cc128r_get_exponent(cc128r_length_t length) {
    const uint32_t bwidth = 14;
    if (length > (18446744073709551615UL)) {
        return 65 - (bwidth - 1);
    } else {
        return cc128r_compute_e((cc128r_addr_t)length, bwidth);
    }
}

extern uint64_t cc128r_getbits(uint64_t src, uint32_t start, uint32_t size) {
    return ((src >> start) & ((1UL << size) - 1UL));
}


extern uint64_t cc128r_truncate_addr(cc128r_addr_t value, size_t n) { return value & (((cc128r_addr_t)1 << n) - 1); }
extern uint64_t cc128r_truncate64(uint64_t value, size_t n) { return value & ((1UL << n) - 1); }







extern uint64_t cc128r_truncateLSB_14(uint64_t value, size_t n) { _Static_assert(14 <= 64, ""); return value >> (14 - n); }
extern uint64_t cc128r_truncateLSB_32(uint64_t value, size_t n) { _Static_assert(32 <= 64, ""); return value >> (32 - n); }
extern uint64_t cc128r_truncateLSB_64(uint64_t value, size_t n) { _Static_assert(64 <= 64, ""); return value >> (64 - n); }




struct cc128r_bounds_bits {
    uint16_t B;
    uint16_t T;
    uint8_t E;
    _Bool IE;
};
# 283 "./cheri_compressed_cap_common.h"
extern cc128r_addr_t cc128r_cap_pesbt_extract_otype(cc128r_addr_t pesbt) { return cc128r_getbits((pesbt), CC128R_FIELD_OTYPE_START, CC128R_FIELD_OTYPE_SIZE); } extern cc128r_addr_t cc128r_cap_pesbt_encode_otype(uint32_t value) { return ((uint64_t)((value) & CC128R_FIELD_OTYPE_MAX_VALUE) << CC128R_FIELD_OTYPE_START); } extern cc128r_addr_t cc128r_cap_pesbt_deposit_otype(cc128r_addr_t pesbt, uint32_t value) { return __extension__({ ((void) sizeof ((value <= CC128R_FIELD_OTYPE_MAX_VALUE) ? 1 : 0), __extension__ ({ if (value <= CC128R_FIELD_OTYPE_MAX_VALUE) ; else __assert_fail ("value <= CC128R_FIELD_OTYPE_MAX_VALUE", "./cheri_compressed_cap_common.h", 283, __extension__ __PRETTY_FUNCTION__); })); ((pesbt) & ~CC128R_FIELD_OTYPE_MASK64) | ((uint64_t)((value) & CC128R_FIELD_OTYPE_MAX_VALUE) << CC128R_FIELD_OTYPE_START); }); } extern uint32_t cc128r_get_otype(const cc128r_cap_t* cap) { return cc128r_cap_pesbt_extract_otype(cap->cr_pesbt); } extern void cc128r_update_otype(cc128r_cap_t * cap, cc128r_addr_t value) { cap->cr_pesbt = cc128r_cap_pesbt_deposit_otype(cap->cr_pesbt, value); }
extern cc128r_addr_t cc128r_cap_pesbt_extract_flags(cc128r_addr_t pesbt) { return cc128r_getbits((pesbt), CC128R_FIELD_FLAGS_START, CC128R_FIELD_FLAGS_SIZE); } extern cc128r_addr_t cc128r_cap_pesbt_encode_flags(uint8_t value) { return ((uint64_t)((value) & CC128R_FIELD_FLAGS_MAX_VALUE) << CC128R_FIELD_FLAGS_START); } extern cc128r_addr_t cc128r_cap_pesbt_deposit_flags(cc128r_addr_t pesbt, uint8_t value) { return __extension__({ ((void) sizeof ((value <= CC128R_FIELD_FLAGS_MAX_VALUE) ? 1 : 0), __extension__ ({ if (value <= CC128R_FIELD_FLAGS_MAX_VALUE) ; else __assert_fail ("value <= CC128R_FIELD_FLAGS_MAX_VALUE", "./cheri_compressed_cap_common.h", 284, __extension__ __PRETTY_FUNCTION__); })); ((pesbt) & ~CC128R_FIELD_FLAGS_MASK64) | ((uint64_t)((value) & CC128R_FIELD_FLAGS_MAX_VALUE) << CC128R_FIELD_FLAGS_START); }); } extern uint8_t cc128r_get_flags(const cc128r_cap_t* cap) { return cc128r_cap_pesbt_extract_flags(cap->cr_pesbt); } extern void cc128r_update_flags(cc128r_cap_t * cap, cc128r_addr_t value) { cap->cr_pesbt = cc128r_cap_pesbt_deposit_flags(cap->cr_pesbt, value); }


extern _Bool cc128r_is_cap_sealed(const cc128r_cap_t* cp) { return cc128r_get_otype(cp) != CC128R_OTYPE_UNSEALED; }
# 307 "./cheri_compressed_cap_common.h"
extern cc128r_cap_t cc128r_make_null_derived_cap(cc128r_addr_t addr);
__attribute__((deprecated("Use get_all_permissions"))) extern cc128r_addr_t cc128r_get_perms(const cc128r_cap_t* cap) {

    _Static_assert((6) != 0, "Architectural perms expected to start at offset zero");

    cc128r_cap_t null_cap = cc128r_make_null_derived_cap(0);
    cc128r_addr_t reserved_one_bits = cc128r_get_all_permissions(&null_cap);
    cc128r_addr_t all_perms_w_reserved = cc128r_get_all_permissions(cap);
    return (all_perms_w_reserved & ~reserved_one_bits) & ~((0xf) << (6));
}
__attribute__((deprecated("Use get_all_permissions"))) extern cc128r_addr_t cc128r_get_uperms(const cc128r_cap_t* cap) {
    return (cc128r_get_all_permissions(cap) & ((0xf) << (6))) >> (6);
}
__attribute__((deprecated("Use set_permissions"))) extern void cc128r_update_perms(cc128r_cap_t* cap, cc128r_addr_t value) {
    ((void) sizeof ((((value & (0x7003f)) == value) && "invalid permission value") ? 1 : 0), __extension__ ({ if (((value & (0x7003f)) == value) && "invalid permission value") ; else __assert_fail ("((value & (0x7003f)) == value) && \"invalid permission value\"", "./cheri_compressed_cap_common.h", 321, __extension__ __PRETTY_FUNCTION__); }));
    cc128r_addr_t current_swperms = (cc128r_get_all_permissions(cap) & ((0xf) << (6)));
    cc128r_set_permissions(cap, (value & ~((0xf) << (6))) | current_swperms);
}
__attribute__((deprecated("Use set_permissions"))) extern void cc128r_update_uperms(cc128r_cap_t* cap, cc128r_addr_t value) {
    ((void) sizeof ((((value & (0xf)) == value) && "invalid permission value") ? 1 : 0), __extension__ ({ if (((value & (0xf)) == value) && "invalid permission value") ; else __assert_fail ("((value & (0xf)) == value) && \"invalid permission value\"", "./cheri_compressed_cap_common.h", 326, __extension__ __PRETTY_FUNCTION__); }));
    cc128r_addr_t old_arch_perms = cc128r_get_all_permissions(cap) & ~((0xf) << (6));
    cc128r_set_permissions(cap, ((value << (6)) & ((0xf) << (6))) | old_arch_perms);
}


extern struct cc128r_bounds_bits cc128r_extract_bounds_bits(cc128r_addr_t pesbt) {
    _Static_assert(14 == CC128R_FIELD_EXP_ZERO_BOTTOM_SIZE, "Wrong bot width?");
    uint32_t BWidth = 14;
    uint32_t BMask = (1u << BWidth) - 1;
    uint32_t TMask = BMask >> 2;
    struct cc128r_bounds_bits result;
    _Static_assert(sizeof(result.B) * 8 >= 14, "B field too small");
    _Static_assert(sizeof(result.T) * 8 >= 14, "T field too small");
    _Static_assert(sizeof(result.E) * 8 >= CC128R_FIELD_EXPONENT_LOW_PART_SIZE + CC128R_FIELD_EXPONENT_HIGH_PART_SIZE, "E field too small");


    result.IE = (_Bool)(!cc128r_getbits((pesbt), CC128R_FIELD_EXPONENT_FORMAT_START, CC128R_FIELD_EXPONENT_FORMAT_SIZE));
    uint8_t L_msb;
    if (result.IE) {
        result.E = (uint8_t)(52 - (cc128r_getbits((pesbt), CC128R_FIELD_EXPONENT_LOW_PART_START, CC128R_FIELD_EXPONENT_LOW_PART_SIZE) | (cc128r_getbits((pesbt), CC128R_FIELD_EXPONENT_HIGH_PART_START, CC128R_FIELD_EXPONENT_HIGH_PART_SIZE) << CC128R_FIELD_EXPONENT_LOW_PART_SIZE)));



        result.B = (uint16_t)cc128r_getbits((pesbt), CC128R_FIELD_EXP_NONZERO_BOTTOM_START, CC128R_FIELD_EXP_NONZERO_BOTTOM_SIZE) << CC128R_FIELD_EXPONENT_LOW_PART_SIZE;
        result.T = (uint16_t)cc128r_getbits((pesbt), CC128R_FIELD_EXP_NONZERO_TOP_START, CC128R_FIELD_EXP_NONZERO_TOP_SIZE) << CC128R_FIELD_EXPONENT_HIGH_PART_SIZE;
        L_msb = 1;
    } else {
        result.E = 0;



        L_msb = 0;

        result.B = (uint16_t)cc128r_getbits((pesbt), CC128R_FIELD_EXP_ZERO_BOTTOM_START, CC128R_FIELD_EXP_ZERO_BOTTOM_SIZE);
        result.T = (uint16_t)cc128r_getbits((pesbt), CC128R_FIELD_EXP_ZERO_TOP_START, CC128R_FIELD_EXP_ZERO_TOP_SIZE);
    }






    uint8_t L_carry = result.T < (result.B & TMask) ? 1 : 0;
    uint64_t BTop2 = cc128r_getbits(result.B, 14 - 2, 2);
    uint8_t T_infer = (BTop2 + L_carry + L_msb) & 0x3;
    result.T |= ((uint16_t)T_infer) << (BWidth - 2);
    return result;
}


extern _Bool cc128r_bounds_bits_valid(struct cc128r_bounds_bits bounds) {

    cc128r_addr_t Bmsb = cc128r_getbits(bounds.B, 14 - 1, 1);
    cc128r_addr_t Bmsb2 = cc128r_getbits(bounds.B, 14 - 2, 2);
    cc128r_addr_t Tmsb = cc128r_getbits(bounds.T, 14 - 1, 1);
    if (bounds.E >= 52) {
        return Tmsb == 0 && Bmsb2 == 0;
    } else if (bounds.E == 52 - 1) {
        return Bmsb == 0;
    } else {
        return 1;
    }
}



extern cc128r_addr_t cc128r_cap_bounds_address(cc128r_addr_t addr) {

    cc128r_addr_t cursor = addr & 0xFFFFFFFFFFFFFFFF;

    if (cursor & ((0xFFFFFFFFFFFFFFFF >> 1) + 1))
        cursor |= ~0xFFFFFFFFFFFFFFFF;
    return cursor;
}


extern _Bool cc128r_compute_base_top_special_cases(struct cc128r_bounds_bits bounds, cc128r_addr_t* base_out,
                                                         cc128r_length_t* top_out, _Bool* valid);

extern _Bool cc128r_compute_base_top(struct cc128r_bounds_bits bounds, cc128r_addr_t cursor, cc128r_addr_t* base_out,
                                           cc128r_length_t* top_out) {

    _Bool valid = 1;
    if (cc128r_compute_base_top_special_cases(bounds, base_out, top_out, &valid))
        return valid;

    cursor = cc128r_cap_bounds_address(cursor);
# 429 "./cheri_compressed_cap_common.h"
    ((void) sizeof ((bounds.E <= 52 && "malformed caps should already be handled") ? 1 : 0), __extension__ ({ if (bounds.E <= 52 && "malformed caps should already be handled") ; else __assert_fail ("bounds.E <= 52 && \"malformed caps should already be handled\"", "./cheri_compressed_cap_common.h", 429, __extension__ __PRETTY_FUNCTION__); }));
    uint8_t E = bounds.E;
    unsigned a_mid = (unsigned)cc128r_truncate64(cursor >> E, 14);
    unsigned correction_B = bounds.B;
    unsigned correction_T = bounds.T;
    unsigned R = cc128r_truncate64((unsigned)bounds.B - (1 << (14 - 2)), 14);





    int aHi = a_mid < R ? 1 : 0;
    int bHi = correction_B < R ? 1 : 0;
    int tHi = correction_T < R ? 1 : 0;




    int correction_base = bHi - aHi;
    int correction_top = tHi - aHi;

    const unsigned a_top_shift = E + 14;

    cc128r_addr_t a_top = a_top_shift >= 64 ? 0 : cursor >> a_top_shift;


    cc128r_length_t base = (cc128r_addr_t)((int64_t)a_top + correction_base);
    base <<= 14;
    base |= bounds.B;
    base <<= E;
    base &= ((cc128r_length_t)1 << 65) - 1;
    ((void) sizeof (((cc128r_addr_t)(base >> 64) <= 1) ? 1 : 0), __extension__ ({ if ((cc128r_addr_t)(base >> 64) <= 1) ; else __assert_fail ("(cc128r_addr_t)(base >> 64) <= 1", "./cheri_compressed_cap_common.h", 460, __extension__ __PRETTY_FUNCTION__); }));

    cc128r_length_t top = (cc128r_addr_t)((int64_t)a_top + correction_top);
    top <<= 14;
    top |= bounds.T;
    top <<= E;
    top &= ((cc128r_length_t)1 << 65) - 1;
    ((void) sizeof (((cc128r_addr_t)(top >> 64) <= 1) ? 1 : 0), __extension__ ({ if ((cc128r_addr_t)(top >> 64) <= 1) ; else __assert_fail ("(cc128r_addr_t)(top >> 64) <= 1", "./cheri_compressed_cap_common.h", 467, __extension__ __PRETTY_FUNCTION__); }));







    unsigned base2 = cc128r_truncate64(base >> (64 - 1), 1);

    unsigned top2 = cc128r_truncate64(top >> (64 - 1), 2);



    if (E < (52 - 1) && (top2 - base2) > 1) {
        top = top ^ ((cc128r_length_t)1 << 64);
    }

    ((void) sizeof (((cc128r_addr_t)(top >> 64) <= 1) ? 1 : 0), __extension__ ({ if ((cc128r_addr_t)(top >> 64) <= 1) ; else __assert_fail ("(cc128r_addr_t)(top >> 64) <= 1", "./cheri_compressed_cap_common.h", 485, __extension__ __PRETTY_FUNCTION__); }));

    if (cc128r_bounds_bits_valid(bounds)) {


        ((void) sizeof (((cc128r_addr_t)base <= top) ? 1 : 0), __extension__ ({ if ((cc128r_addr_t)base <= top) ; else __assert_fail ("(cc128r_addr_t)base <= top", "./cheri_compressed_cap_common.h", 490, __extension__ __PRETTY_FUNCTION__); }));
    } else {

    }
    *base_out = (cc128r_addr_t)base;
    *top_out = top;

    return 1;
}



extern void cc128r_unsafe_decompress_raw(cc128r_addr_t pesbt, cc128r_addr_t cursor, _Bool tag,
                                                __attribute__((unused)) uint8_t lvbits, cc128r_cap_t* cdp) {
    memset(cdp, 0, sizeof(*cdp));
    cdp->cr_tag = tag;
    cdp->_cr_cursor = cursor;
    cdp->cr_pesbt = pesbt;

    cdp->cr_lvbits = lvbits;


    struct cc128r_bounds_bits bounds = cc128r_extract_bounds_bits(pesbt);
    _Bool valid = cc128r_compute_base_top(bounds, cursor, &cdp->cr_base, &cdp->_cr_top);
    cdp->cr_bounds_valid = valid;
    cdp->cr_exp = bounds.E;
}

extern void cc128r_decompress_raw_ext(cc128r_addr_t pesbt, cc128r_addr_t cursor, _Bool tag, uint8_t lvbits,
                                             cc128r_cap_t* cdp) {
    cc128r_unsafe_decompress_raw(pesbt, cursor, tag, lvbits, cdp);
    if (tag) {
        ((void) sizeof ((cdp->cr_base <= (18446744073709551615UL)) ? 1 : 0), __extension__ ({ if (cdp->cr_base <= (18446744073709551615UL)) ; else __assert_fail ("cdp->cr_base <= (18446744073709551615UL)", "./cheri_compressed_cap_common.h", 522, __extension__ __PRETTY_FUNCTION__); }));


        ((void) sizeof ((cdp->_cr_top <= ((cc128r_length_t)1u << 64)) ? 1 : 0), __extension__ ({ if (cdp->_cr_top <= ((cc128r_length_t)1u << 64)) ; else __assert_fail ("cdp->_cr_top <= ((cc128r_length_t)1u << 64)", "./cheri_compressed_cap_common.h", 525, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((cdp->cr_base <= cdp->_cr_top) ? 1 : 0), __extension__ ({ if (cdp->cr_base <= cdp->_cr_top) ; else __assert_fail ("cdp->cr_base <= cdp->_cr_top", "./cheri_compressed_cap_common.h", 526, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((cdp->cr_bounds_valid) ? 1 : 0), __extension__ ({ if (cdp->cr_bounds_valid) ; else __assert_fail ("cdp->cr_bounds_valid", "./cheri_compressed_cap_common.h", 527, __extension__ __PRETTY_FUNCTION__); }));

        ((void) sizeof ((cc128r_reserved_bits_valid(cdp)) ? 1 : 0), __extension__ ({ if (cc128r_reserved_bits_valid(cdp)) ; else __assert_fail ("cc128r_reserved_bits_valid(cdp)", "./cheri_compressed_cap_common.h", 529, __extension__ __PRETTY_FUNCTION__); }));
    }
}

extern void cc128r_decompress_raw(cc128r_addr_t pesbt, cc128r_addr_t cursor, _Bool tag, cc128r_cap_t* cdp) {
    cc128r_decompress_raw_ext(pesbt, cursor, tag, 1, cdp);
}




extern void cc128r_decompress_mem(uint64_t pesbt, uint64_t cursor, _Bool tag, cc128r_cap_t* cdp) {
    cc128r_decompress_raw_ext(pesbt ^ CC128R_MEM_XOR_MASK, cursor, tag, 1, cdp);
}


extern _Bool cc128r_pesbt_is_correct(const cc128r_cap_t* csp) {
    cc128r_cap_t tmp;

    cc128r_unsafe_decompress_raw(csp->cr_pesbt, csp->_cr_cursor, csp->cr_tag, cc128r_get_lvbits(csp), &tmp);
    tmp.cr_extra = csp->cr_extra;
    if (!cc128r_raw_equal(&tmp, csp)) {
        return 0;
    }
    return 1;
}


extern void cc128r_update_ebt(cc128r_cap_t* csp, cc128r_addr_t new_ebt) {
    csp->cr_pesbt = (csp->cr_pesbt & ~CC128R_FIELD_EBT_MASK64) | new_ebt;
    csp->cr_exp = cc128r_extract_bounds_bits(new_ebt).E;
}






extern cc128r_addr_t cc128r_compress_raw(const cc128r_cap_t* csp) {


    ((void) sizeof (((!csp->cr_tag || (csp->cr_bounds_valid && cc128r_reserved_bits_valid(csp))) && "Malformed bounds or unknown reserved bits in tagged capability") ? 1 : 0), __extension__ ({ if ((!csp->cr_tag || (csp->cr_bounds_valid && cc128r_reserved_bits_valid(csp))) && "Malformed bounds or unknown reserved bits in tagged capability") ; else __assert_fail ("(!csp->cr_tag || (csp->cr_bounds_valid && cc128r_reserved_bits_valid(csp))) && \"Malformed bounds or unknown reserved bits in tagged capability\"", "./cheri_compressed_cap_common.h", 571, __extension__ __PRETTY_FUNCTION__); }));


    ((void) sizeof ((cc128r_pesbt_is_correct(csp) && "capability bounds were modified without updating pesbt") ? 1 : 0), __extension__ ({ if (cc128r_pesbt_is_correct(csp) && "capability bounds were modified without updating pesbt") ; else __assert_fail ("cc128r_pesbt_is_correct(csp) && \"capability bounds were modified without updating pesbt\"", "./cheri_compressed_cap_common.h", 573, __extension__ __PRETTY_FUNCTION__); }));
    return csp->cr_pesbt;
}

extern cc128r_addr_t cc128r_compress_mem(const cc128r_cap_t* csp) {
    return cc128r_compress_raw(csp) ^ CC128R_MEM_XOR_MASK;
}

static _Bool cc128r__fast_is_representable_new_addr(const cc128r_cap_t* cap, cc128r_addr_t new_addr);


extern _Bool cc128r_is_representable_cap_exact(const cc128r_cap_t* cap) {
    cc128r_addr_t pesbt = cc128r_compress_raw(cap);
    cc128r_cap_t decompressed_cap;

    cc128r_unsafe_decompress_raw(pesbt, cap->_cr_cursor, cap->cr_tag, cc128r_get_lvbits(cap), &decompressed_cap);

    ((void) sizeof ((decompressed_cap._cr_cursor == cap->_cr_cursor) ? 1 : 0), __extension__ ({ if (decompressed_cap._cr_cursor == cap->_cr_cursor) ; else __assert_fail ("decompressed_cap._cr_cursor == cap->_cr_cursor", "./cheri_compressed_cap_common.h", 590, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((decompressed_cap.cr_pesbt == cap->cr_pesbt) ? 1 : 0), __extension__ ({ if (decompressed_cap.cr_pesbt == cap->cr_pesbt) ; else __assert_fail ("decompressed_cap.cr_pesbt == cap->cr_pesbt", "./cheri_compressed_cap_common.h", 591, __extension__ __PRETTY_FUNCTION__); }));

    if (decompressed_cap.cr_base != cap->cr_base || decompressed_cap._cr_top != cap->_cr_top) {
        return 0;
    }
    return 1;
}

extern uint32_t cc128r_compute_ebt(cc128r_addr_t req_base, cc128r_length_t req_top, cc128r_addr_t* alignment_mask,
                                          _Bool* exact) {
# 609 "./cheri_compressed_cap_common.h"
    ((void) sizeof ((req_base <= req_top && "Cannot invert base and top") ? 1 : 0), __extension__ ({ if (req_base <= req_top && "Cannot invert base and top") ; else __assert_fail ("req_base <= req_top && \"Cannot invert base and top\"", "./cheri_compressed_cap_common.h", 609, __extension__ __PRETTY_FUNCTION__); }));






    cc128r_length_t req_length65 = req_top - req_base;
# 625 "./cheri_compressed_cap_common.h"
    uint8_t E = (uint8_t)cc128r_get_exponent(req_length65);
    const uint64_t req_length64 = (uint64_t)req_length65;




    const _Bool InternalExponent = E != 0 || cc128r_getbits(req_length64, CC128R_FIELD_EXP_NONZERO_BOTTOM_SIZE + 1, 1);
    if (!InternalExponent) {






        uint32_t ebt_bits = ((uint64_t)((!(0)) & CC128R_FIELD_EXPONENT_FORMAT_MAX_VALUE) << CC128R_FIELD_EXPONENT_FORMAT_START) | ((uint64_t)((req_top) & CC128R_FIELD_EXP_ZERO_TOP_MAX_VALUE) << CC128R_FIELD_EXP_ZERO_TOP_START) |
                            ((uint64_t)((req_base) & CC128R_FIELD_EXP_ZERO_BOTTOM_MAX_VALUE) << CC128R_FIELD_EXP_ZERO_BOTTOM_START);
# 667 "./cheri_compressed_cap_common.h"
        if (alignment_mask)
            *alignment_mask = (18446744073709551615UL);
        *exact = 1;
        return ebt_bits;
    }
# 680 "./cheri_compressed_cap_common.h"
    cc128r_addr_t bot_ie = cc128r_truncate64(req_base >> (E + CC128R_FIELD_EXPONENT_LOW_PART_SIZE), CC128R_FIELD_EXP_NONZERO_BOTTOM_SIZE);
    if (alignment_mask) {
        *alignment_mask = (18446744073709551615UL) << (E + CC128R_FIELD_EXPONENT_LOW_PART_SIZE);
    }
    cc128r_addr_t top_ie = cc128r_truncate64((cc128r_addr_t)(req_top >> (E + CC128R_FIELD_EXPONENT_LOW_PART_SIZE)), CC128R_FIELD_EXP_NONZERO_BOTTOM_SIZE);







    const cc128r_length_t maskLo = (((cc128r_length_t)1u) << (E + CC128R_FIELD_EXPONENT_LOW_PART_SIZE)) - 1;
    const cc128r_length_t zero65 = 0;
    _Bool lostSignificantBase = (req_base & maskLo) != zero65;
    _Bool lostSignificantTop = (req_top & maskLo) != zero65;





    if (lostSignificantTop) {
        top_ie = cc128r_truncate64(top_ie + 1, CC128R_FIELD_EXP_NONZERO_BOTTOM_SIZE);
    }
# 719 "./cheri_compressed_cap_common.h"
    const cc128r_addr_t len_ie = cc128r_truncate64(top_ie - bot_ie, CC128R_FIELD_EXP_NONZERO_BOTTOM_SIZE);
    _Bool incE = 0;
    if (cc128r_getbits(len_ie, CC128R_FIELD_EXP_NONZERO_BOTTOM_SIZE - 1, 1)) {
        incE = 1;
        lostSignificantBase = lostSignificantBase || cc128r_getbits(bot_ie, 0, 1);
        lostSignificantTop = lostSignificantTop || cc128r_getbits(top_ie, 0, 1);
        bot_ie = cc128r_truncate64(req_base >> (E + CC128R_FIELD_EXPONENT_LOW_PART_SIZE + 1), CC128R_FIELD_EXP_NONZERO_BOTTOM_SIZE);

        if (alignment_mask) {
            *alignment_mask = (18446744073709551615UL) << (E + CC128R_FIELD_EXPONENT_LOW_PART_SIZE + 1);
        }
        const _Bool incT = lostSignificantTop;
        top_ie = cc128r_truncate64((cc128r_addr_t)(req_top >> (E + CC128R_FIELD_EXPONENT_LOW_PART_SIZE + 1)), CC128R_FIELD_EXP_NONZERO_BOTTOM_SIZE);
        if (incT) {
            top_ie = cc128r_truncate64(top_ie + 1, CC128R_FIELD_EXP_NONZERO_BOTTOM_SIZE);
        }
    }
    const uint8_t newE = E + (incE ? 1 : 0);

    *exact = !lostSignificantBase && !lostSignificantTop;

    const cc128r_addr_t expBits = ((uint64_t)(((52 - (newE)) >> CC128R_FIELD_EXPONENT_LOW_PART_SIZE) & CC128R_FIELD_EXPONENT_HIGH_PART_MAX_VALUE) << CC128R_FIELD_EXPONENT_HIGH_PART_START) | ((uint64_t)((52 - (newE)) & CC128R_FIELD_EXPONENT_LOW_PART_MAX_VALUE) << CC128R_FIELD_EXPONENT_LOW_PART_START);
    return expBits | ((uint64_t)((!(1)) & CC128R_FIELD_EXPONENT_FORMAT_MAX_VALUE) << CC128R_FIELD_EXPONENT_FORMAT_START) | ((uint64_t)((top_ie) & CC128R_FIELD_EXP_NONZERO_TOP_MAX_VALUE) << CC128R_FIELD_EXP_NONZERO_TOP_START) |
           ((uint64_t)((bot_ie) & CC128R_FIELD_EXP_NONZERO_BOTTOM_MAX_VALUE) << CC128R_FIELD_EXP_NONZERO_BOTTOM_START);
}

extern _Bool cc128r__precise_is_representable_new_addr(const cc128r_cap_t* oldcap, cc128r_addr_t new_cursor) {

    cc128r_cap_t newcap = *oldcap;
    newcap._cr_cursor = new_cursor;
    struct cc128r_bounds_bits old_bounds_bits = cc128r_extract_bounds_bits(cc128r_compress_raw(oldcap));
    newcap.cr_bounds_valid = cc128r_compute_base_top(old_bounds_bits, new_cursor, &newcap.cr_base, &newcap._cr_top);
    return newcap.cr_base == oldcap->cr_base && newcap._cr_top == oldcap->_cr_top && newcap.cr_bounds_valid &&
           oldcap->cr_bounds_valid;
}

extern _Bool cc128r_cap_bounds_uses_value_for_exp(uint8_t exponent) {
    return exponent < (sizeof(cc128r_addr_t) * 8) - CC128R_FIELD_BOTTOM_ENCODED_SIZE;
}


extern _Bool cc128r_cap_bounds_uses_value(const cc128r_cap_t* cap) {

    ((void) sizeof ((cc128r_pesbt_is_correct(cap)) ? 1 : 0), __extension__ ({ if (cc128r_pesbt_is_correct(cap)) ; else __assert_fail ("cc128r_pesbt_is_correct(cap)", "./cheri_compressed_cap_common.h", 762, __extension__ __PRETTY_FUNCTION__); }));
    return cc128r_cap_bounds_uses_value_for_exp(cap->cr_exp);
}

extern _Bool cc128r_cap_sign_change(cc128r_addr_t addr1, cc128r_addr_t addr2) {



    (void)addr1;
    (void)addr2;
    return 0;

}

extern _Bool cc128r_cap_sign_change_causes_unrepresentability(const cc128r_cap_t* cap, cc128r_addr_t addr1,
                                                                    cc128r_addr_t addr2) {
    return cc128r_cap_sign_change(addr1, addr2) && cc128r_cap_bounds_uses_value(cap);
}

extern _Bool cc128r_is_representable_with_addr(const cc128r_cap_t* cap, cc128r_addr_t new_addr,
                                                     _Bool precise_representable_check) {
# 794 "./cheri_compressed_cap_common.h"
    cc128r_addr_t extended_cursor = cc128r_cap_bounds_address(new_addr);

    if (__builtin_expect(extended_cursor >= cap->cr_base && extended_cursor < cap->_cr_top, 1)) {
        return 1;
    }
    if (precise_representable_check) {
        return cc128r__precise_is_representable_new_addr(cap, new_addr);
    } else {
        return cc128r__fast_is_representable_new_addr(cap, new_addr);
    }
}



extern void cc128r_set_addr(cc128r_cap_t* cap, cc128r_addr_t new_addr) {
    if (cap->cr_tag && cc128r_is_cap_sealed(cap)) {
        cap->cr_tag = 0;
    }
    if (!cc128r_is_representable_with_addr(cap, new_addr, 0)) {

        cap->cr_tag = 0;
        cc128r_decompress_raw(cap->cr_pesbt, new_addr, 0, cap);
    } else {
        cap->_cr_cursor = new_addr;
    }
}

static _Bool cc128r__fast_is_representable_new_addr(const cc128r_cap_t* cap, cc128r_addr_t new_addr) {
    if (cap->_cr_top == ((cc128r_length_t)1u << 64) && cap->cr_base == 0) {
        return 1;
    }


    return cc128r__precise_is_representable_new_addr(cap, new_addr);
# 861 "./cheri_compressed_cap_common.h"
}


extern _Bool cc128r_setbounds_impl(cc128r_cap_t* cap, cc128r_length_t req_len, cc128r_addr_t* alignment_mask) {
    uint64_t req_base = cap->_cr_cursor;
    if (cc128r_is_cap_sealed(cap)) {
        cap->cr_tag = 0;
    }
# 881 "./cheri_compressed_cap_common.h"
    cc128r_length_t req_top = (cc128r_length_t)req_base + req_len;
    ((void) sizeof ((req_base <= req_top && "Cannot invert base and top") ? 1 : 0), __extension__ ({ if (req_base <= req_top && "Cannot invert base and top") ; else __assert_fail ("req_base <= req_top && \"Cannot invert base and top\"", "./cheri_compressed_cap_common.h", 882, __extension__ __PRETTY_FUNCTION__); }));

    if (req_base < cap->cr_base || req_top > cap->_cr_top) {
        cap->cr_tag = 0;
    }




    _Static_assert(CC128R_FIELD_EXPONENT_LOW_PART_SIZE == 3, "expected 3 bits to be used by");
    _Static_assert(CC128R_FIELD_EXPONENT_HIGH_PART_SIZE == 3, "expected 3 bits to be used by");






    _Bool exact = 0;
    uint32_t new_ebt = cc128r_compute_ebt(req_base, req_top, alignment_mask, &exact);
    cc128r_addr_t new_base;
    cc128r_length_t new_top;
    _Bool new_bounds_valid = cc128r_compute_base_top(cc128r_extract_bounds_bits(((uint64_t)((new_ebt) & CC128R_FIELD_EBT_MAX_VALUE) << CC128R_FIELD_EBT_START)),
                                                    cap->_cr_cursor, &new_base, &new_top);
    if (exact) {




        ((void) sizeof ((new_base == req_base && "Should be exact") ? 1 : 0), __extension__ ({ if (new_base == req_base && "Should be exact") ; else __assert_fail ("new_base == req_base && \"Should be exact\"", "./cheri_compressed_cap_common.h", 910, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((new_top == req_top && "Should be exact") ? 1 : 0), __extension__ ({ if (new_top == req_top && "Should be exact") ; else __assert_fail ("new_top == req_top && \"Should be exact\"", "./cheri_compressed_cap_common.h", 911, __extension__ __PRETTY_FUNCTION__); }));

    } else {
        ((void) sizeof (((new_base != req_base || new_top != req_top) && "Was inexact, but neither base nor top different?") ? 1 : 0), __extension__ ({ if ((new_base != req_base || new_top != req_top) && "Was inexact, but neither base nor top different?") ; else __assert_fail ("(new_base != req_base || new_top != req_top) && \"Was inexact, but neither base nor top different?\"", "./cheri_compressed_cap_common.h", 915, __extension__ __PRETTY_FUNCTION__); }));

    }







    if (cap->cr_tag) {




        ((void) sizeof ((new_top >= new_base) ? 1 : 0), __extension__ ({ if (new_top >= new_base) ; else __assert_fail ("new_top >= new_base", "./cheri_compressed_cap_common.h", 929, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((cc128r_reserved_bits_valid(cap) && "Unknown reserved bits set in tagged capability") ? 1 : 0), __extension__ ({ if (cc128r_reserved_bits_valid(cap) && "Unknown reserved bits set in tagged capability") ; else __assert_fail ("cc128r_reserved_bits_valid(cap) && \"Unknown reserved bits set in tagged capability\"", "./cheri_compressed_cap_common.h", 930, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((new_bounds_valid && "Malformed bounds in tagged capability") ? 1 : 0), __extension__ ({ if (new_bounds_valid && "Malformed bounds in tagged capability") ; else __assert_fail ("new_bounds_valid && \"Malformed bounds in tagged capability\"", "./cheri_compressed_cap_common.h", 931, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((new_base >= cap->cr_base && "Cannot reduce base on tagged capabilities") ? 1 : 0), __extension__ ({ if (new_base >= cap->cr_base && "Cannot reduce base on tagged capabilities") ; else __assert_fail ("new_base >= cap->cr_base && \"Cannot reduce base on tagged capabilities\"", "./cheri_compressed_cap_common.h", 932, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((new_top <= cap->_cr_top && "Cannot increase top on tagged capabilities") ? 1 : 0), __extension__ ({ if (new_top <= cap->_cr_top && "Cannot increase top on tagged capabilities") ; else __assert_fail ("new_top <= cap->_cr_top && \"Cannot increase top on tagged capabilities\"", "./cheri_compressed_cap_common.h", 933, __extension__ __PRETTY_FUNCTION__); }));
    }
    cap->cr_base = new_base;
    cap->_cr_top = new_top;
    cc128r_update_ebt(cap, new_ebt);
    cap->cr_bounds_valid = new_bounds_valid;
    return exact;
}


extern _Bool cc128r_setbounds(cc128r_cap_t* cap, cc128r_length_t req_len) {
    __attribute__((unused)) cc128r_addr_t old_base = cap->cr_base;
    __attribute__((unused)) cc128r_length_t old_top = cap->_cr_top;
    __attribute__((unused)) cc128r_addr_t req_base =
        cc128r_cap_bounds_uses_value(cap) ? cc128r_cap_bounds_address(cap->_cr_cursor) : cap->_cr_cursor;
    __attribute__((unused)) cc128r_length_t req_top = req_len + req_base;
    _Bool exact = cc128r_setbounds_impl(cap, req_len, ((void*)0));
    if (cap->cr_tag) {

        ((void) sizeof ((!cc128r_is_cap_sealed(cap) && "result cannot be sealed and tagged") ? 1 : 0), __extension__ ({ if (!cc128r_is_cap_sealed(cap) && "result cannot be sealed and tagged") ; else __assert_fail ("!cc128r_is_cap_sealed(cap) && \"result cannot be sealed and tagged\"", "./cheri_compressed_cap_common.h", 952, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((((cap->_cr_top - cap->cr_base) >> 64) <= 1 && "length must be smaller than 1 << 65") ? 1 : 0), __extension__ ({ if (((cap->_cr_top - cap->cr_base) >> 64) <= 1 && "length must be smaller than 1 << 65") ; else __assert_fail ("((cap->_cr_top - cap->cr_base) >> 64) <= 1 && \"length must be smaller than 1 << 65\"", "./cheri_compressed_cap_common.h", 954, __extension__ __PRETTY_FUNCTION__); }));

        ((void) sizeof ((cap->cr_base >= old_base && "cannot remain tagged if base was decreased") ? 1 : 0), __extension__ ({ if (cap->cr_base >= old_base && "cannot remain tagged if base was decreased") ; else __assert_fail ("cap->cr_base >= old_base && \"cannot remain tagged if base was decreased\"", "./cheri_compressed_cap_common.h", 955, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof ((cap->_cr_top <= old_top && "cannot remain tagged if top was increased") ? 1 : 0), __extension__ ({ if (cap->_cr_top <= old_top && "cannot remain tagged if top was increased") ; else __assert_fail ("cap->_cr_top <= old_top && \"cannot remain tagged if top was increased\"", "./cheri_compressed_cap_common.h", 956, __extension__ __PRETTY_FUNCTION__); }));


        ((void) sizeof (((cap->_cr_top <= ((cc128r_length_t)1u << 64) || old_top > ((cc128r_length_t)1u << 64)) && "cannot remain tagged if new top greater 1 << 65") ? 1 : 0), __extension__ ({ if ((cap->_cr_top <= ((cc128r_length_t)1u << 64) || old_top > ((cc128r_length_t)1u << 64)) && "cannot remain tagged if new top greater 1 << 65") ; else __assert_fail ("(cap->_cr_top <= ((cc128r_length_t)1u << 64) || old_top > ((cc128r_length_t)1u << 64)) && \"cannot remain tagged if new top greater 1 << 65\"", "./cheri_compressed_cap_common.h", 960, __extension__ __PRETTY_FUNCTION__); }));

    }

    if (exact) {
        ((void) sizeof ((cc128r_cap_bounds_address(cap->cr_base) == cc128r_cap_bounds_address(req_base) && "base changed but still reported exact") ? 1 : 0), __extension__ ({ if (cc128r_cap_bounds_address(cap->cr_base) == cc128r_cap_bounds_address(req_base) && "base changed but still reported exact") ; else __assert_fail ("cc128r_cap_bounds_address(cap->cr_base) == cc128r_cap_bounds_address(req_base) && \"base changed but still reported exact\"", "./cheri_compressed_cap_common.h", 965, __extension__ __PRETTY_FUNCTION__); }));

        ((void) sizeof ((cc128r_cap_bounds_address(cap->_cr_top) == cc128r_cap_bounds_address(req_top) && "top changed but still reported exact") ? 1 : 0), __extension__ ({ if (cc128r_cap_bounds_address(cap->_cr_top) == cc128r_cap_bounds_address(req_top) && "top changed but still reported exact") ; else __assert_fail ("cc128r_cap_bounds_address(cap->_cr_top) == cc128r_cap_bounds_address(req_top) && \"top changed but still reported exact\"", "./cheri_compressed_cap_common.h", 967, __extension__ __PRETTY_FUNCTION__); }));

    } else {
        ((void) sizeof (((cap->_cr_top != req_top || cap->cr_base != req_base) && "result is exact but reported inexact") ? 1 : 0), __extension__ ({ if ((cap->_cr_top != req_top || cap->cr_base != req_base) && "result is exact but reported inexact") ; else __assert_fail ("(cap->_cr_top != req_top || cap->cr_base != req_base) && \"result is exact but reported inexact\"", "./cheri_compressed_cap_common.h", 970, __extension__ __PRETTY_FUNCTION__); }));

    }
    return exact;
}


extern _Bool cc128r_checked_setbounds(cc128r_cap_t* cap, cc128r_length_t req_len) {
    __attribute__((unused)) cc128r_addr_t req_base =
        cc128r_cap_bounds_uses_value(cap) ? cc128r_cap_bounds_address(cap->_cr_cursor) : cap->_cr_cursor;
    __attribute__((unused)) cc128r_length_t req_top = req_len + req_base;
    if (cap->cr_tag) {

        ((void) sizeof (((!cc128r_is_cap_sealed(cap)) && "cannot be used on tagged sealed capabilities") ? 1 : 0), __extension__ ({ if ((!cc128r_is_cap_sealed(cap)) && "cannot be used on tagged sealed capabilities") ; else __assert_fail ("(!cc128r_is_cap_sealed(cap)) && \"cannot be used on tagged sealed capabilities\"", "./cheri_compressed_cap_common.h", 982, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((req_base >= cap->cr_base) && "cannot decrease base on tagged capabilities") ? 1 : 0), __extension__ ({ if ((req_base >= cap->cr_base) && "cannot decrease base on tagged capabilities") ; else __assert_fail ("(req_base >= cap->cr_base) && \"cannot decrease base on tagged capabilities\"", "./cheri_compressed_cap_common.h", 983, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((req_top <= cap->_cr_top) && "cannot increase top on tagged capabilities") ? 1 : 0), __extension__ ({ if ((req_top <= cap->_cr_top) && "cannot increase top on tagged capabilities") ; else __assert_fail ("(req_top <= cap->_cr_top) && \"cannot increase top on tagged capabilities\"", "./cheri_compressed_cap_common.h", 984, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((req_len < ((cc128r_length_t)1u << 64)) && "requested length must be smaller than max length") ? 1 : 0), __extension__ ({ if ((req_len < ((cc128r_length_t)1u << 64)) && "requested length must be smaller than max length") ; else __assert_fail ("(req_len < ((cc128r_length_t)1u << 64)) && \"requested length must be smaller than max length\"", "./cheri_compressed_cap_common.h", 985, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((req_top < ((cc128r_length_t)1u << 64)) && "new top must be smaller than max length") ? 1 : 0), __extension__ ({ if ((req_top < ((cc128r_length_t)1u << 64)) && "new top must be smaller than max length") ; else __assert_fail ("(req_top < ((cc128r_length_t)1u << 64)) && \"new top must be smaller than max length\"", "./cheri_compressed_cap_common.h", 986, __extension__ __PRETTY_FUNCTION__); }));
        ((void) sizeof (((cap->_cr_top <= ((cc128r_length_t)1u << 64)) && "input capability top must be less than max top") ? 1 : 0), __extension__ ({ if ((cap->_cr_top <= ((cc128r_length_t)1u << 64)) && "input capability top must be less than max top") ; else __assert_fail ("(cap->_cr_top <= ((cc128r_length_t)1u << 64)) && \"input capability top must be less than max top\"", "./cheri_compressed_cap_common.h", 987, __extension__ __PRETTY_FUNCTION__); }));
    }
    return cc128r_setbounds(cap, req_len);
}


extern cc128r_cap_t cc128r__make_max_perms_cap_common(cc128r_addr_t base, cc128r_addr_t cursor, cc128r_length_t top,
                                                          __attribute__((unused)) uint8_t lvbits) {
    cc128r_cap_t creg;
    memset(&creg, 0, sizeof(creg));
    ((void) sizeof ((base <= top && "Invalid arguments") ? 1 : 0), __extension__ ({ if (base <= top && "Invalid arguments") ; else __assert_fail ("base <= top && \"Invalid arguments\"", "./cheri_compressed_cap_common.h", 997, __extension__ __PRETTY_FUNCTION__); }));
    creg.cr_base = base;
    creg._cr_cursor = cursor;
    creg.cr_bounds_valid = 1;
    creg._cr_top = top;
    creg.cr_pesbt = (((uint64_t)(((0xf)) & CC128R_FIELD_SDP_MAX_VALUE) << CC128R_FIELD_SDP_START) | ((uint64_t)((lvbits == 0 ? 0x13f : 0x1ff) & CC128R_FIELD_AP_MAX_VALUE) << CC128R_FIELD_AP_START) | ((uint64_t)((((1UL << (lvbits)) - 1UL)) & CC128R_FIELD_LEVEL_MAX_VALUE) << CC128R_FIELD_LEVEL_START) | ((uint64_t)((1) & CC128R_FIELD_MODE_MAX_VALUE) << CC128R_FIELD_MODE_START)) | ((uint64_t)((CC128R_OTYPE_UNSEALED) & CC128R_FIELD_OTYPE_MAX_VALUE) << CC128R_FIELD_OTYPE_START);
    creg.cr_tag = 1;
    creg.cr_exp = CC128R_RESET_EXP;
    ((void) sizeof ((lvbits <= 1 && "We only support local-global levels.") ? 1 : 0), __extension__ ({ if (lvbits <= 1 && "We only support local-global levels.") ; else __assert_fail ("lvbits <= 1 && \"We only support local-global levels.\"", "./cheri_compressed_cap_common.h", 1005, __extension__ __PRETTY_FUNCTION__); }));

    creg.cr_lvbits = lvbits;

    _Bool exact_input = 0;
    cc128r_update_ebt(&creg, cc128r_compute_ebt(creg.cr_base, creg._cr_top, ((void*)0), &exact_input));
    ((void) sizeof ((exact_input && "Invalid arguments") ? 1 : 0), __extension__ ({ if (exact_input && "Invalid arguments") ; else __assert_fail ("exact_input && \"Invalid arguments\"", "./cheri_compressed_cap_common.h", 1011, __extension__ __PRETTY_FUNCTION__); }));
    ((void) sizeof ((cc128r_is_representable_cap_exact(&creg)) ? 1 : 0), __extension__ ({ if (cc128r_is_representable_cap_exact(&creg)) ; else __assert_fail ("_cc_N(is_representable_cap_exact)(&creg)", "./cheri_compressed_cap_common.h", 1012, __extension__ __PRETTY_FUNCTION__); }));
    return creg;
}




extern cc128r_cap_t cc128r_make_max_perms_cap_ext(cc128r_addr_t base, cc128r_addr_t cursor, cc128r_length_t top,
                                                      CC128R_Mode mode, uint8_t lvbits) {
    cc128r_cap_t creg = cc128r__make_max_perms_cap_common(base, cursor, top, lvbits);
    _Bool mode_valid = cc128r_set_execution_mode(&creg, mode);
    ((void) sizeof ((mode_valid && "Could not set mode on max perms cap") ? 1 : 0), __extension__ ({ if (mode_valid && "Could not set mode on max perms cap") ; else __assert_fail ("mode_valid && \"Could not set mode on max perms cap\"", "./cheri_compressed_cap_common.h", 1023, __extension__ __PRETTY_FUNCTION__); }));
    return creg;
}
extern cc128r_cap_t cc128r_make_max_perms_cap(cc128r_addr_t base, cc128r_addr_t cursor, cc128r_length_t top) {
    return cc128r_make_max_perms_cap_ext(base, cursor, top, CC128R_MODE_INT, 1);
}







extern cc128r_addr_t cc128r_get_alignment_mask(cc128r_addr_t req_length) {
    if (req_length == 0) {



        return (18446744073709551615UL);
    }


    cc128r_cap_t tmpcap = cc128r_make_max_perms_cap(0, 0, ((cc128r_length_t)1u << 64));
    cc128r_addr_t mask = 0;
    cc128r_setbounds_impl(&tmpcap, req_length, &mask);
    return mask;
}

extern cc128r_cap_t cc128r_make_null_derived_cap_ext(cc128r_addr_t addr, __attribute__((unused)) uint8_t lvbits) {
    cc128r_cap_t creg;
    memset(&creg, 0, sizeof(creg));
    creg._cr_cursor = addr;
    creg._cr_top = ((cc128r_length_t)1u << 64);
    creg.cr_pesbt = CC128R_NULL_PESBT;
    creg.cr_bounds_valid = 1;
    creg.cr_exp = CC128R_NULL_EXP;
    ((void) sizeof ((cc128r_is_representable_cap_exact(&creg)) ? 1 : 0), __extension__ ({ if (cc128r_is_representable_cap_exact(&creg)) ; else __assert_fail ("cc128r_is_representable_cap_exact(&creg)", "./cheri_compressed_cap_common.h", 1059, __extension__ __PRETTY_FUNCTION__); }));

    creg.cr_lvbits = lvbits;

    return creg;
}

extern cc128r_cap_t cc128r_make_null_derived_cap(cc128r_addr_t addr) {
    return cc128r_make_null_derived_cap_ext(addr, 1);
}

extern cc128r_addr_t cc128r_get_required_alignment(cc128r_addr_t req_length) {


    return ~cc128r_get_alignment_mask(req_length) + 1;
}

extern cc128r_addr_t cc128r_get_representable_length(cc128r_addr_t req_length) {
    cc128r_addr_t mask = cc128r_get_alignment_mask(req_length);
    return (req_length + ~mask) & mask;
}
# 163 "./cheri_compressed_cap_128r.h" 2
# 1 "./cheri_compressed_cap_riscv_common.h" 1


extern cc128r_addr_t cc128r_get_reserved(const cc128r_cap_t* cap) {
    cc128r_addr_t reserved = cap->cr_pesbt & (CC128R_FIELD_RESERVED0_MASK64 | CC128R_FIELD_RESERVED1_MASK64);
    if (cap->cr_lvbits == 0) {
        reserved |= cap->cr_pesbt & CC128R_FIELD_LEVEL_MASK64;
    }
    return reserved;
}
extern uint32_t cc128r_get_level(const cc128r_cap_t* cap) {

    return cap->cr_lvbits == 0 ? 1 : cc128r_getbits((cap->cr_pesbt), CC128R_FIELD_LEVEL_START, CC128R_FIELD_LEVEL_SIZE);
}
extern void cc128r_update_level(cc128r_cap_t* cap, uint8_t level) {
    ((void) sizeof (((level <= CC128R_MAX_LEVEL_VALUE) && "invalid level") ? 1 : 0), __extension__ ({ if ((level <= CC128R_MAX_LEVEL_VALUE) && "invalid level") ; else __assert_fail ("(level <= CC128R_MAX_LEVEL_VALUE) && \"invalid level\"", "./cheri_compressed_cap_riscv_common.h", 15, __extension__ __PRETTY_FUNCTION__); }));
    if (cap->cr_lvbits == 0) {
        ((void) sizeof (((level == 1) && "cannot change level when levels are reserved") ? 1 : 0), __extension__ ({ if ((level == 1) && "cannot change level when levels are reserved") ; else __assert_fail ("(level == 1) && \"cannot change level when levels are reserved\"", "./cheri_compressed_cap_riscv_common.h", 17, __extension__ __PRETTY_FUNCTION__); }));
        return;
    }
    cap->cr_pesbt = __extension__({ ((void) sizeof ((level <= CC128R_FIELD_LEVEL_MAX_VALUE) ? 1 : 0), __extension__ ({ if (level <= CC128R_FIELD_LEVEL_MAX_VALUE) ; else __assert_fail ("level <= CC128R_FIELD_LEVEL_MAX_VALUE", "./cheri_compressed_cap_riscv_common.h", 20, __extension__ __PRETTY_FUNCTION__); })); ((cap->cr_pesbt) & ~CC128R_FIELD_LEVEL_MASK64) | ((uint64_t)((level) & CC128R_FIELD_LEVEL_MAX_VALUE) << CC128R_FIELD_LEVEL_START); });
}

extern _Bool cc128r_bounds_malformed(struct cc128r_bounds_bits bounds) {


    _Bool malformedLSB = bounds.E > 52;




    _Bool malformedMSB = (bounds.E == 52 && bounds.B != 0) ||
                        (bounds.E == 52 - 1 && (bounds.B & (1u << (14 - 1))) != 0);
    return bounds.IE && (malformedLSB || malformedMSB);
}

extern _Bool cc128r_compute_base_top_special_cases(struct cc128r_bounds_bits bounds, cc128r_addr_t* base_out,
                                                         cc128r_length_t* top_out, _Bool* valid) {
    if (cc128r_bounds_malformed(bounds)) {
        *base_out = 0;
        *top_out = 0;
        *valid = 0;
        return 1;
    }
    return 0;
}


_Static_assert((CC128R_MEM_XOR_MASK) == (0UL), "");
enum { CC128R_PERMS_RESERVED_ONES = ((1UL << ((15) - (6 + CC128R_FIELD_SDP_SIZE) + 1)) - 1UL) << (6 + CC128R_FIELD_SDP_SIZE) | ((1UL << ((23) - (19) + 1)) - 1UL) << (19) };
# 164 "./cheri_compressed_cap_128r.h" 2


extern cc128r_addr_t cc128r_get_all_permissions(const cc128r_cap_t* cap) {
    cc128r_addr_t sw_perms = cc128r_getbits((cap->cr_pesbt), CC128R_FIELD_SDP_START, CC128R_FIELD_SDP_SIZE);
    cc128r_addr_t arch_perms = cc128r_getbits((cap->cr_pesbt), CC128R_FIELD_AP_START, CC128R_FIELD_AP_SIZE);
    cc128r_addr_t result = sw_perms << (6);

    if (arch_perms & (1UL << (0)))
        result |= (1 << 5);
    if (arch_perms & (1UL << (1)))
        result |= (1 << 0);
    if (arch_perms & (1UL << (2)))
        result |= (1 << 18);
    if (arch_perms & (1UL << (3)))
        result |= (1 << 17);
    if (arch_perms & (1UL << (4)))
        result |= (1 << 16);
    if (arch_perms & (1UL << (5)))
        result |= (1 << 1);
    if (cap->cr_lvbits > 0) {
        if (arch_perms & (1UL << (6)))
            result |= (1 << 2);
        if (arch_perms & (1UL << (7)))
            result |= (1 << 3);
        if (cc128r_getbits((cap->cr_pesbt), CC128R_FIELD_LEVEL_START, CC128R_FIELD_LEVEL_SIZE))
            result |= (1 << 4);
    } else {

        result |= (1 << 4) | (1 << 3) | (1 << 2);
    }
    result |= CC128R_PERMS_RESERVED_ONES;
    return result;
}

extern _Bool cc128r_set_permissions(cc128r_cap_t* cap, cc128r_addr_t permissions) {
    ((void) sizeof ((((permissions & (((0x7003f) | ((0xf) << (6))) | CC128R_PERMS_RESERVED_ONES)) == permissions) && "invalid permissions") ? 1 : 0), __extension__ ({ if (((permissions & (((0x7003f) | ((0xf) << (6))) | CC128R_PERMS_RESERVED_ONES)) == permissions) && "invalid permissions") ; else __assert_fail ("((permissions & (((0x7003f) | ((0xf) << (6))) | CC128R_PERMS_RESERVED_ONES)) == permissions) && \"invalid permissions\"", "./cheri_compressed_cap_128r.h", 200, __extension__ __PRETTY_FUNCTION__); }));


    cc128r_addr_t sw_perms = (permissions >> (6)) & (0xf);
    CC128R_Mode mode = (CC128R_Mode)cc128r_getbits((cap->cr_pesbt), CC128R_FIELD_MODE_START, CC128R_FIELD_MODE_SIZE);

    cc128r_addr_t result = 0;
    if (permissions & (1 << 5))
        result |= (1UL << (0));
    if (permissions & (1 << 0))
        result |= (1UL << (1));
    if (permissions & (1 << 18))
        result |= (1UL << (2));
    if (permissions & (1 << 17))
        result |= (1UL << (3));
    if (permissions & (1 << 16))
        result |= (1UL << (4));
    if (permissions & (1 << 1))
        result |= (1UL << (5));
    if (cap->cr_lvbits > 0) {
        if (permissions & (1 << 2))
            result |= (1UL << (6));
        if (permissions & (1 << 3))
            result |= (1UL << (7));
        unsigned new_level = permissions & (1 << 4) ? 1 : 0;
        cap->cr_pesbt = __extension__({ ((void) sizeof ((new_level <= CC128R_FIELD_LEVEL_MAX_VALUE) ? 1 : 0), __extension__ ({ if (new_level <= CC128R_FIELD_LEVEL_MAX_VALUE) ; else __assert_fail ("new_level <= CC128R_FIELD_LEVEL_MAX_VALUE", "./cheri_compressed_cap_128r.h", 224, __extension__ __PRETTY_FUNCTION__); })); ((cap->cr_pesbt) & ~CC128R_FIELD_LEVEL_MASK64) | ((uint64_t)((new_level) & CC128R_FIELD_LEVEL_MAX_VALUE) << CC128R_FIELD_LEVEL_START); });
    }
    cap->cr_pesbt = __extension__({ ((void) sizeof ((result <= CC128R_FIELD_AP_MAX_VALUE) ? 1 : 0), __extension__ ({ if (result <= CC128R_FIELD_AP_MAX_VALUE) ; else __assert_fail ("result <= CC128R_FIELD_AP_MAX_VALUE", "./cheri_compressed_cap_128r.h", 226, __extension__ __PRETTY_FUNCTION__); })); ((cap->cr_pesbt) & ~CC128R_FIELD_AP_MASK64) | ((uint64_t)((result) & CC128R_FIELD_AP_MAX_VALUE) << CC128R_FIELD_AP_START); });
    cap->cr_pesbt = __extension__({ ((void) sizeof ((sw_perms <= CC128R_FIELD_SDP_MAX_VALUE) ? 1 : 0), __extension__ ({ if (sw_perms <= CC128R_FIELD_SDP_MAX_VALUE) ; else __assert_fail ("sw_perms <= CC128R_FIELD_SDP_MAX_VALUE", "./cheri_compressed_cap_128r.h", 227, __extension__ __PRETTY_FUNCTION__); })); ((cap->cr_pesbt) & ~CC128R_FIELD_SDP_MASK64) | ((uint64_t)((sw_perms) & CC128R_FIELD_SDP_MAX_VALUE) << CC128R_FIELD_SDP_START); });
    if ((permissions & (1 << 17)) == 0 && mode == CC128R_MODE_INT) {
        cap->cr_pesbt = __extension__({ ((void) sizeof (((unsigned)CC128R_MODE_CAP <= CC128R_FIELD_MODE_MAX_VALUE) ? 1 : 0), __extension__ ({ if ((unsigned)CC128R_MODE_CAP <= CC128R_FIELD_MODE_MAX_VALUE) ; else __assert_fail ("(unsigned)CC128R_MODE_CAP <= CC128R_FIELD_MODE_MAX_VALUE", "./cheri_compressed_cap_128r.h", 229, __extension__ __PRETTY_FUNCTION__); })); ((cap->cr_pesbt) & ~CC128R_FIELD_MODE_MASK64) | ((uint64_t)(((unsigned)CC128R_MODE_CAP) & CC128R_FIELD_MODE_MAX_VALUE) << CC128R_FIELD_MODE_START); });
        return 0;
    }
    return 1;
}

extern CC128R_Mode cc128r_get_execution_mode(const cc128r_cap_t* cap) {
    return (CC128R_Mode)cc128r_getbits((cap->cr_pesbt), CC128R_FIELD_MODE_START, CC128R_FIELD_MODE_SIZE);
}

extern _Bool cc128r_set_execution_mode(cc128r_cap_t* cap, CC128R_Mode new_mode) {

    if (!cc128r_has_permissions(cap, (1 << 17)))
        return 0;
    cap->cr_pesbt = __extension__({ ((void) sizeof (((unsigned)new_mode <= CC128R_FIELD_MODE_MAX_VALUE) ? 1 : 0), __extension__ ({ if ((unsigned)new_mode <= CC128R_FIELD_MODE_MAX_VALUE) ; else __assert_fail ("(unsigned)new_mode <= CC128R_FIELD_MODE_MAX_VALUE", "./cheri_compressed_cap_128r.h", 243, __extension__ __PRETTY_FUNCTION__); })); ((cap->cr_pesbt) & ~CC128R_FIELD_MODE_MASK64) | ((uint64_t)(((unsigned)new_mode) & CC128R_FIELD_MODE_MAX_VALUE) << CC128R_FIELD_MODE_START); });
    return 1;
}
# 54 "./cheri_compressed_cap.h" 2



# 1 "./cheri_compressed_cap_256.h" 1
# 13 "./cheri_compressed_cap_256.h"
_Static_assert((15) >= (12) + (3), "");
_Static_assert(((1) + (12) + (3)) == (((1) + (12) + (3))), "");







_Static_assert((((1) + (12) + (3)) + (16)) == ((32)), "");





_Static_assert(((1) + (12) + (3) + (16) + (24) + (8)) == (64), "");





enum CC256_OTypes {
    CC256_MAX_REPRESENTABLE_OTYPE = ((1u << (24)) - 1u),
    CC256_OTYPE_UNSEALED = (CC256_MAX_REPRESENTABLE_OTYPE - 0u),
    CC256_OTYPE_SENTRY = (CC256_MAX_REPRESENTABLE_OTYPE - 1u),
    CC256_MAX_RESERVED_OTYPE = (CC256_MAX_REPRESENTABLE_OTYPE - 0u),
    CC256_MIN_RESERVED_OTYPE = (CC256_MAX_REPRESENTABLE_OTYPE - 15u),
};





typedef struct cc256_cap {
    uint64_t cr_cursor;
    uint64_t cr_base;
    uint64_t cr_length;
    uint32_t cr_otype;
    uint16_t cr_perms;
    uint16_t cr_uperms;
    uint8_t cr_tag;
    uint8_t cr_flags;
    uint8_t cr_reserved;
# 74 "./cheri_compressed_cap_256.h"
} cc256_cap_t;


typedef union _inmemory_chericap256 {
    uint8_t bytes[32];
    uint32_t u32s[8];
    uint64_t u64s[4];
} inmemory_chericap256;

static inline _Bool cc256_is_cap_sealed(const cc256_cap_t* cp) { return cp->cr_otype != CC256_OTYPE_UNSEALED; }

static inline void decompress_256cap(inmemory_chericap256 mem, cc256_cap_t* cdp, _Bool tagged) {

    uint32_t hwperms_mask = tagged ? ((1UL << ((12))) - 1UL) : ((1UL << ((12) + (3))) - 1UL);
    cdp->cr_flags = mem.u64s[0] & ((1UL << ((1))) - 1UL);
    cdp->cr_perms = (mem.u64s[0] >> (1)) & hwperms_mask;
    cdp->cr_uperms = (mem.u64s[0] >> ((1) + (12) + (3))) & ((1UL << ((16))) - 1UL);
    cdp->cr_otype = ((mem.u64s[0] >> (32)) & ((1UL << ((24))) - 1UL)) ^ CC256_OTYPE_UNSEALED;
    cdp->cr_reserved = (mem.u64s[0] >> ((32) + (24))) & ((1UL << ((8))) - 1UL);
    cdp->cr_base = mem.u64s[2];

    uint64_t length = mem.u64s[3] ^ ((cc128_length_t)(18446744073709551615UL));
    cdp->cr_length = length;
    cdp->cr_cursor = mem.u64s[1];
    cdp->cr_tag = tagged;
    ((void) sizeof ((!(cdp->cr_tag && cdp->cr_reserved) && "Unknown reserved bits set it tagged capability") ? 1 : 0), __extension__ ({ if (!(cdp->cr_tag && cdp->cr_reserved) && "Unknown reserved bits set it tagged capability") ; else __assert_fail ("!(cdp->cr_tag && cdp->cr_reserved) && \"Unknown reserved bits set it tagged capability\"", "./cheri_compressed_cap_256.h", 99, __extension__ __PRETTY_FUNCTION__); }));
}

static inline void compress_256cap(inmemory_chericap256* buffer, const cc256_cap_t* csp) {
    ((void) sizeof ((!(csp->cr_tag && csp->cr_reserved) && "Unknown reserved bits set it tagged capability") ? 1 : 0), __extension__ ({ if (!(csp->cr_tag && csp->cr_reserved) && "Unknown reserved bits set it tagged capability") ; else __assert_fail ("!(csp->cr_tag && csp->cr_reserved) && \"Unknown reserved bits set it tagged capability\"", "./cheri_compressed_cap_256.h", 103, __extension__ __PRETTY_FUNCTION__); }));
    _Bool flags_bits = csp->cr_flags & ((1UL << ((1))) - 1UL);

    uint64_t hwperms_mask = csp->cr_tag ? ((1UL << ((12))) - 1UL) : ((1UL << ((12) + (3))) - 1UL);
    buffer->u64s[0] =
        flags_bits | ((csp->cr_perms & hwperms_mask) << (1)) |
        ((csp->cr_uperms & ((1UL << ((16))) - 1UL)) << ((1) + (12) + (3))) |
        ((uint64_t)((csp->cr_otype ^ CC256_OTYPE_UNSEALED) & ((1UL << ((24))) - 1UL)) << (32)) |
        ((uint64_t)(csp->cr_reserved & ((1UL << ((8))) - 1UL)) << ((32) + (24)));
    buffer->u64s[1] = csp->cr_cursor;
    buffer->u64s[2] = csp->cr_base;
    buffer->u64s[3] = csp->cr_length ^ ((cc128_length_t)(18446744073709551615UL));
}
# 58 "./cheri_compressed_cap.h" 2
# 5 "cheri_compressed_cap_lib.c" 2

