// -*- C++ -*-
#ifndef arith_basic_functions_h
#define arith_basic_functions_h

#include<math.h>

// number of 1 (hammer weight) of a 64-bit word
inline int number_bit(ulong64 a)
{
  const ulong mask1 = (ulong(0x5555555555555555));
  const ulong mask2 = (ulong(0x3333333333333333));

  a = (a&mask1) + ((a>>1)&mask1);
  a = (a&mask2) + ((a>>2)&mask2);

  ulong b = (a&0xFFFFFFFF)+(a>>32);
  b = (b&0x0F0F0F0F)+((b>>4)&0x0F0F0F0F);
  b = (b&0xFFFF)+(b>>16);
  b = (b&0xFF)+(b>>8);
  return int(b);
}

long min(long a, long b);

long64 squareroot128(long128 x);
long64 squareroot64(long64 x);
long32 cuberoot128(long128 x);
double log128(long128 x);
double exp128(long128 x);
double pow128(long128 x, double e);

template<class longint> longint prev_mult(longint a, int periode) {
  return a - a%periode;
}

template<class longint> longint next_mult(longint b, int periode) {
  int r= b % periode;
  return (r==0) ? b : b - b%periode + periode;
}

inline long32 
gcd32(long32 a, long32 b)
{
  while (b) 
    {
      long32 tmp = a % b;
      a = b;
      b = tmp;
    }
  return a;
}

inline long32
lcm32(long32 a, long32 b)
{
  long32 u = a/(gcd32(a,b));
  return b*u;
}

inline long32 
phi_euler32(long32 x)
{
  if (x == 1)
    return 1;
  long32 res = 1 ;
  while ( x > 1)
    {
      int p = 2 ;
      while (( x % p) && ( p * p <= x))
	p++;
      if ( x % p == 0 )
	{
	  res *= (p-1);
	  x = x / p;
	  while ( x % p == 0)
	    {
	      x /= p ; 
	      res *= p;
	    }
	  p++;
	}
      else 
	{
	  res *= (x-1);
	  x = 1;
	}
    }
  return res;
}

inline 
ldiv32::ldiv32(long32 a, long32 b)
{
  r = a%b;
  q = a/b;
}

inline 
ldiv64::ldiv64(long64 a, long64 b)
{
  /*
    This should be faster...
     ldiv_t division = ldiv(a, b);
     q = division.quot;
     r = division.rem;
  */
  r = a%b;
  q = a/b;
}

// Quotient et reste de la division par 6
inline
ldiv64::ldiv64(long64 a)
{
  long64 y=a;
  q=y;
  while (y > 0) {
    y >>= 2;
    q+=y;
  }
  q >>= 3;
  long64 q6 = (q<<1) + (q<<2);
  r= a-q6;
  while (r >= 6) {
    q+=1;
    r-=6;
  }
}

inline
ldiv128::ldiv128(long128 a)
{
  long128 y=a;
  q=y;
  while (y > 0) {
    y >>= 2;
    q+=y;
  }
  q >>= 3;
  long64 q6 = (q<<1) + (q<<2);
  r= a-q6;
  while (r >= 6) {
    q+=1;
    r-=6;
  }
}








//#if (ULONG_MAX == 0xFFFFFFFFFFFFFFFF)
inline 
ldiv128::ldiv128(long128 a, long64 n)
{
#ifdef DEBUG_SAFE
  if (a < 0 || (n < 0))
    {
      cout << "both arguments most be positive in ldiv128\n";
      error();
    }
#endif
  q = a / n;
  r = a % n;
}


inline long64 
ceil_div64(long64 a, long64 b)
{
  ldiv64 division(a, b);
  if (division.r) 
    return division.q + 1;
  return division.q;
}

inline 
gcdex32::gcdex32(long32 a, long32 b)
{
 long32 v1 = 0, v2 = b ;

 u = 1;  
 d = a;

 while (v2)
   {
     ldiv32 div_d_v2(d, v2);
     long32  q = div_d_v2.q;
     long32 t3 = div_d_v2.r;
     long32 t1 = u - q * v1;
     u  = v1; d  = v2;
     v1 = t1; v2 = t3;
   }
 v = (d -  a * u)/b;
}

inline long32 
invmod32(long32 a, long32 b)
{
  gcdex32 tmp(a, b);

  if (tmp.d != 1) return 0;
  if (tmp.u < 0 ) return tmp.u + b;
  return tmp.u;
}

inline long32 
mod32(long64 a, long32 b)
{
  return (long32)(a%b);
}

inline long64 
mod64(long64 a, long64 b)
{
  return a%b;
}


inline int
compare_long32(long32 a, long32 b)
{
  if (a == b) return 0;
  return (a < b) ? -1 : 1;
}

inline int
compare_abs_long32(long32 a, long32 b)
{
  long32 abs_a = abs(a);
  long32 abs_b = abs(b);
  if (abs_a == abs_b) return 0;
  return (abs_a < abs_b) ? -1 : 1;
}

inline long32
max32(long32 a, long32 b)
{
  if (a < b) return b;
  return a;
}

inline double
max_double(double a, double b)
{
  if (a < b) return b;
  return a;
}

inline long64
max64(long64 a, long64 b)
{
  if (a < b) return b;
  return a;
}

inline long32
min32(long32 a, long32 b)
{
  if (b < a) return b;
  return a;
}

inline long64
min64(long64 a, long64 b)
{
  if (b < a) return b;
  return a;
}

inline long32
abs32(long32 a)
{ 
  if (a < 0) return -a;
  return a;
}

#if (ULONG_MAX == 0xFFFFFFFF)
inline long64 atolong64(char* s)
{
  long64 sum = 0;
  char c;
  while ((c = *s++))
    {
      sum *= 10;
      sum += c - '0';
    }
  return sum;
}
#elif (ULONG_MAX == 0xFFFFFFFFFFFFFFFF)
inline long64 
atolong64(char* s)
{
  return atol(s);
}
#endif

inline long32
arith_mod32::get_index(long64 a)
{ 
  return index[mod32(a,N)]; 
}

inline long32
arith_mod32::get_mulinv(long32 a, long64 b)
{ 
  long32 b0 = index[mod32(b, N)];
  return invmul_index[a][b0];  // return index(class(a).b^-1 (mod N))
} 

inline long32
arith_mod32::get_mulinv_index(long32 a, long32 b)
{ 
  return invmul_index[a][b];  // return index(class(a).class(b)^-1 (mod N))
} 

#endif

