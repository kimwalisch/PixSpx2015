#include<mylib.h>
#include"../meissel_global.h"

static long128 tmpv1;
static long128 tmpv2;


static long128 xp2_long;

inline long128 fint(long128 u) {return u;}

/*****************************************************
Steklov page 107
V1 = sum(x^(1/4) <= p < x(1/3))
       f(p) (1-pif(p-1)) [pif(min(x/p^2,y))-pif(p-1)]
******************************************************/


long128 sumV1(){
  long128 V1=0;
  for (int ip = 1+max(meissel::pi_sqr4_x,primes::number_of_presieve_primes); ip <= meissel::pi_sqr3_x; ip++)
    {
      int p = primes::prime(ip);
      long xp2 = (meissel::x/p)/p; // p > x^(1/4) dont xp2 < x^(1/2);
      long minxp2y = min(xp2,meissel::y);
      long iqmax   = primes::piB(minxp2y);
#ifdef DEBUG_V1    
      cout << "p= " << p << "    xp2= " << xp2 << "    min(xp2,y)= " << minxp2y << "    iqmax= " << iqmax\
	   << " sx[iqmax]= " << meissel::sx[iqmax] <<  "  sx[ip-1]= " <<  meissel::sx[ip-1] << endl;
#endif
      long pifpm1 = meissel::sx[ip-1];
      V1 += fint(p) * (1-meissel::sx[ip-1])*(meissel::sx[iqmax]-meissel::sx[ip]);
    }
  if (meissel::verbose)
    cout << "      V1 = " << V1  << "\n";
  return V1;
}
