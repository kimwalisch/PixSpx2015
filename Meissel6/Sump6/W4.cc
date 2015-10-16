#include<mylib.h>
#include"../meissel_global.h"


long128 sumW4() {
  long128 res=0;
  //cout << "In sumW4 pi_sqr2_x_y= " <<  endl;
  for (int ip= 1+meissel::pi_sqr2_x_y; ip <= meissel::pi_sqr3_x; ip++) {
    long32 p = primes::prime(ip);
    double xp= meissel::x/p;
    double xp2= xp/p;
    double sqrtxp=sqrt(xp);
    int lastiq= primes::piB(sqrtxp);
    //cout <<  "p= " << p << "    sqrtxp= " << sqrtxp << endl;
    for (int iq= ip+1; iq <= lastiq; iq++) {
      long q= primes::prime(iq);
      //cout << "   q= " << q << "  ->  " << primes::piB(xp/q) << endl;
      res += p*q*meissel::sx[primes::piB(xp/q)];
    }
  }
  if (meissel::verbose)
    {
      cout << "         W4 = " << res << "\n";
      meissel::time_msg(9,(char*)"medium_primes:W4"); 
      cout.flush();
    }
  return res;
}
