#include<mylib.h>
#include"../meissel_global.h"


long128 slowsum(long a, long b, long u) {
  //cout << "In slowsum a , b , u = " << a << " " << b << " " << u << endl;
  long128 res=0;
  long imin= 1+primes::piB(a);
  for (int iq=imin; iq <= primes::piB(b); iq++) {
    long q=primes::prime(iq);
    res += q*meissel::sx[primes::piB(u/q)];
  }	
  return res;
} 

inline long128 quicksum(long a, long b, long z) {
  long128 res=0;
  long32 imin= 1+primes::piB(a);
  while (imin <= primes::piB(b)) {
    long q= primes::prime(imin);
    long32 it= primes::piB(z/q);
    long32 imax= primes::piB(min(z/primes::prime(it),b));
    res += (imax - imin +1 ) * it;
    imin =imax+1;
  }
  return res;
}

long128 sumW3() {
  cout << "In sumW3\n";
  long128 res=0;
  int ip;
  int ipmin=1+max(meissel::pi_x_y2,meissel::pi_sqr4_x);
  for (ip=ipmin; ip <= meissel::pi_sqr2_x_y;ip++) {
    long p=primes::prime(ip);
    double xp=meissel::x/p;
    double sqrtxp= sqrt(xp);
    cout << "p= " << p << endl;
    res += p*slowsum(sqrtxp,meissel::y,xp);
    /*
    long32 imin=1+primes::piB(sqrtxp);
    long32 lastimin=primes::piB(meissel::y);
    while (imin <= lastimin) {
      long    q= primes::prime(imin);
      long32 it= primes::piB(xp/q);
      long32 imax= primes::piB(min(xp/primes::prime(it),meissel::y));
      res += (imax - imin +1 ) * it;
      imin =imax+1;
    }
    */
  }
  if (meissel::verbose)
    {
      cout << "         W3 = " << res << "\n";
      meissel::time_msg(9,(char*)"medium_primes:W3"); 
      cout.flush();
    }
    return res;
}

long128 sumW5() {
  long128 res=0;
  int ip;
  for (ip=1+meissel::pi_sqr2_x_y; ip <= meissel::pi_sqr3_x;ip++) {
    long p=primes::prime(ip);
    double xp= meissel::x/p;
    double sqrtxp=sqrt(xp);
    long xp2= xp/p;
    res += p*slowsum(sqrtxp,xp2,xp);
    /*
    long32 imin=1+primes::piB(sqrtxp);
    long32 lastimin=primes::piB(xp2);
    while (imin <= lastimin) {
      long q= primes::prime(imin);
      long32 it= primes::piB(xp/q);
      long32 imax= primes::piB(min(xp/primes::prime(it),xp2));
      res += (imax - imin +1 ) * it;
      imin =imax+1;
    }
    */
 
    
  }
  if (meissel::verbose)
    {
      cout << "         W5 = " << res << "\n";
      meissel::time_msg(9,(char*)"medium_primes:W5"); 
      cout.flush();
    }
    
  return res;
}


