#ifndef arith64_32_h
#define arith64_32_h

#define LONG32_MAX 2147483647
#define EXACT_DOUBLE_MAX 9007199254740992
#define WORDSIZE  64
#define WORDSIZE1 63
#define WORDSIZE2  6

typedef unsigned long ulong64;
typedef long          long64;
typedef unsigned long ulong;

long64 squareroot128(long128 u);

#define LONG32_MAX 2147483647
typedef int  long32;

long32 phi_euler32(long32 x);
long32 gcd32(long32 a, long32 b);
long32 mod32(long64 a, long32 b);

#endif
