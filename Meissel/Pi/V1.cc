#include<mylib.h>
#include<meissel_global.h>

static long128 xp2_long;

inline long128 fint(long128 u) {return u;}

/*****************************************************
Steklov page 107
V1 = sum(x^(1/4) <= p < x(1/3))
       f(p) (1-pif(p-1)) [pif(min(x/p^2,y))-pif(p-1)]
******************************************************/


long128 sumV1(){
  long128 V1=0;
  for (int ip = 1+max(meissel::pi_sqr4_x,presieved_primes::number_of_presieve_primes); ip <= meissel::pi_sqr3_x; ip++)
    {
      int p = presieved_primes::prime(ip);
      long xp2 = (meissel::x/p)/p; // p > x^(1/4) dont xp2 < x^(1/2);
      long minxp2y = min(xp2,meissel::y);
      long iqmax   = presieved_primes::piB(minxp2y);
#ifdef DEBUG_V1    
      cout << "p= " << p << "    xp2= " << xp2 << "    min(xp2,y)= " << minxp2y << "    iqmax= " << iqmax\
	   << " iqmax= " << iqmax <<  "  ip-1= " <<  ip-1 << endl;
#endif
      V1 +=  (2-ip)*(iqmax-ip);
    }
  if (meissel::verbose) {
    cout << "    V1 = " << V1  << "\n";
    cout << "    V2 = W1 + W2 + W3 + W4 + W5" << endl;
      }
  return V1;
}
