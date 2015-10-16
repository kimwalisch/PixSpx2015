#include<mylib.h>
#include<meissel_global6.h>


long128 slowsum(long a, long b, long z) {
  long128 res=0;
  long imin= 1+primes6::piB(a);
  for (int iq=imin; iq <= primes6::piB(b); iq++) {
    long q=primes6::prime(iq);
    res += primes6::piB(z/q);
  }	
  return res;
} 

inline long128 quicksum(long a, long b, long z) {
  long128 res=0;
  long32 imin= 1+primes6::piB(a);
  while (imin <= primes6::piB(b)) {
    long q= primes6::prime(imin);
    long32 it= primes6::piB(z/q);
    long32 imax= primes6::piB(min(z/primes6::prime(it),b));
    res += (imax - imin +1 ) * it;
    imin =imax+1;
  }
  return res;
}

long128 sumW3() {
  long128 res=0;
  int ip;
  int ipmin=1+max(meissel6::pi_x_y2,meissel6::pi_sqr4_x);
  for (ip=ipmin; ip <= meissel6::pi_sqr2_x_y;ip++) {
    long p=primes6::prime(ip);
    double xp=meissel6::x/p;
    double sqrtxp= sqrt(xp);
    //res += quicksum(sqrtxp,meissel6::y,xp);
    long32 imin=1+primes6::piB(sqrtxp);
    long32 lastimin=primes6::piB(meissel6::y);
    while (imin <= lastimin) {
      long    q= primes6::prime(imin);
      long32 it= primes6::piB(xp/q);
      long32 imax= primes6::piB(min(xp/primes6::prime(it),meissel6::y));
      res += (imax - imin +1 ) * it;
      imin =imax+1;
    }
  }
  if (meissel6::verbose)
    {
      cout << "         W3 = " << res << "\n";
      meissel6::time_msg(9,(char*)"medium_primes:W3"); 
      cout.flush();
    }
    return res;
}

long128 sumW5() {
  long128 res=0;
  int ip;
  for (ip=1+meissel6::pi_sqr2_x_y; ip <= meissel6::pi_sqr3_x;ip++) {
    long p=primes6::prime(ip);
    double xp= meissel6::x/p;
    double sqrtxp=sqrt(xp);
    long xp2= xp/p;
    //res += quicksum(sqrtxp,xp2,xp);
    long32 imin=1+primes6::piB(sqrtxp);
    long32 lastimin=primes6::piB(xp2);
    while (imin <= lastimin) {
      long q= primes6::prime(imin);
      long32 it= primes6::piB(xp/q);
      long32 imax= primes6::piB(min(xp/primes6::prime(it),xp2));
      res += (imax - imin +1 ) * it;
      imin =imax+1;
    }
 
    
  }
  if (meissel6::verbose)
    {
      cout << "         W5 = " << res << "\n";
      meissel6::time_msg(9,(char*)"medium_primes:W5"); 
      cout.flush();
    }
    
  return res;
}


