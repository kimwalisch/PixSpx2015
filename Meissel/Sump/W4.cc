#include<mylib.h>
#include<meissel_global.h>


long128 sumW4() {
  long128 res=0;
  //cout << "In sumW4 pi_sqr2_x_y= " <<  endl;
  for (int ip= 1+meissel::pi_sqr2_x_y; ip <= meissel::pi_sqr3_x; ip++) {
    long32 p = presieved_primes::prime(ip);
    double xp= meissel::x/p;
    double xp2= xp/p;
    double sqrtxp=sqrt(xp);
    int lastiq= presieved_primes::piB(sqrtxp);
    //cout <<  "p= " << p << "    sqrtxp= " << sqrtxp << endl;
    for (int iq= ip+1; iq <= lastiq; iq++) {
      long q= presieved_primes::prime(iq);
      //cout << "   q= " << q << "  ->  " << presieved_primes::piB(xp/q) << endl;
      res += p*q*meissel::sx[presieved_primes::piB(xp/q)];
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
