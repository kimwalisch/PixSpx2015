#include<mylib.h>
#include<meissel_global.h>


long128 slowsum(long a, long b, long u) {
  //cout << "In slowsum a , b , u = " << a << " " << b << " " << u << endl;
  long128 res=0;
  long imin= 1+presieved_primes::piB(a);
  for (int iq=imin; iq <= presieved_primes::piB(b); iq++) {
    long q=presieved_primes::prime(iq);
    res += q*meissel::sx[presieved_primes::piB(u/q)];
  }	
  return res;
} 

inline long128 quicksum(long a, long b, long z) {
  long128 res=0;
  long32 imin= 1+presieved_primes::piB(a);
  while (imin <= presieved_primes::piB(b)) {
    long q= presieved_primes::prime(imin);
    long32 it= presieved_primes::piB(z/q);
    long32 imax= presieved_primes::piB(min(z/presieved_primes::prime(it),b));
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
    long p=presieved_primes::prime(ip);
    double xp=meissel::x/p;
    double sqrtxp= sqrt(xp);
    //cout << "p= " << p << endl;
    res += p*slowsum(sqrtxp,meissel::y,xp);
    /*
    long32 imin=1+presieved_primes::piB(sqrtxp);
    long32 lastimin=presieved_primes::piB(meissel::y);
    while (imin <= lastimin) {
      long    q= presieved_primes::prime(imin);
      long32 it= presieved_primes::piB(xp/q);
      long32 imax= presieved_primes::piB(min(xp/presieved_primes::prime(it),meissel::y));
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
    long p=presieved_primes::prime(ip);
    double xp= meissel::x/p;
    double sqrtxp=sqrt(xp);
    long xp2= xp/p;
    res += p*slowsum(sqrtxp,xp2,xp);
    /*
    long32 imin=1+presieved_primes::piB(sqrtxp);
    long32 lastimin=presieved_primes::piB(xp2);
    while (imin <= lastimin) {
      long q= presieved_primes::prime(imin);
      long32 it= presieved_primes::piB(xp/q);
      long32 imax= presieved_primes::piB(min(xp/presieved_primes::prime(it),xp2));
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


