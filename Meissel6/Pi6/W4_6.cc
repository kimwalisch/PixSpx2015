#include<mylib.h>
#include<meissel_global6.h>


long128 sumW4() {
  long128 res=0;
  //cout << "In sumW4 pi_sqr2_x_y= " <<  endl;
  for (int ip= 1+meissel6::pi_sqr2_x_y; ip <= meissel6::pi_sqr3_x; ip++) {
    long32 p = primes6::prime(ip);
    double xp= meissel6::x/p;
    double xp2= xp/p;
    double sqrtxp=sqrt(xp);
    int lastiq= primes6::piB(sqrtxp);
    //cout <<  "p= " << p << "    sqrtxp= " << sqrtxp << endl;
    for (int iq= ip+1; iq <= lastiq; iq++) {
      long q= primes6::prime(iq);
      //cout << "   q= " << q << "  ->  " << primes6::piB(xp/q) << endl;
      res += primes6::piB(xp/q);
    }
  }
  if (meissel6::verbose)
    {
      cout << "         W4 = " << res << "\n";
      meissel6::time_msg(9,(char*)"medium_primes:W4"); 
      cout.flush();
    }
  return res;
}
