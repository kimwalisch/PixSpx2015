// -*- C++ -*-
#ifndef arith_6_h
#define arith_6_h

struct div_by6{ 
  long64 q;
  long32 r;
  inline div_by6(long64 a);// Quotient et reste de la division par 6
};


struct div128_by6{ 
  long128 q;
  long32  r;
  inline div128_by6(long128 a);// Quotient et reste de la division par 6
};


inline long64 inverse6(long p) {
  if (p % 6 == 1) {
    return p/6 + 1;
    }
  else
    {
      return 5 * (p % 6 + 1);
    }
}

inline long64 next_mult6(long x) {
  int r= x % 6;
  return (r==0) ? x : x -r + 6;
}

inline long64 get_integer(long i)
{
  if (!i) return 0;
  if (i & 1)  // i impair
    return 6*((i-1)>>1) + 1;
  else
    return 6*((i-1)>>1) + 5;
}

 inline long offset(long u) {
  div_by6 qr(u);
  //cout << "Offset  u = " <<  u <<  " q=  " << qr.q << "  r= " << qr.r << endl;
  long res = qr.q<<1;
  if (qr.r) {
    if (qr.r==5)
      res+=2;
    else
      res+=1;
  }
  return res;
}

 inline long128 offset128(long128 u) {
  div128_by6 qr(u);
  //cout << "Offset  u = " <<  u <<  " q=  " << qr.q << "  r= " << qr.r << endl;
  long128 res = qr.q<<1;
  if (qr.r) {
    if (qr.r==5)
      res+=2;
    else
      res+=1;
  }
  return res;
}


// Quotient et reste de la division par 6
inline div_by6::div_by6(long64 a)
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

inline div128_by6::div128_by6(long128 a)
{
  long128 y=a;
  q=y;
  while (y > 0) {
    y >>= 2;
    q+=y;
  }
  q >>= 3;
  
  long128 q6 = (q<<1) + (q<<2);
  r= a-q6;
  while (r >= 6) {
    q+=1;
    r-=6;
  }
}

#endif
