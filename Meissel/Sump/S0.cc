#include<mylib.h>
#include<meissel_global.h>
static  access_frame accessf;

long128 sumS0()
{
  long32 b_prime;

#ifdef DEBUG_S0
  cout << "In simple_leaves \n";
#endif

  accessf.create(primes::presieve_base, 2, 1);

  long128 res=  accessf.sum128_6(meissel::x);

#ifdef DEBUG_S0
  cout << "S0 initialized  with " << res << "\n";
#endif

  for (b_prime = 1; b_prime <= meissel::pi_sqr2_z; b_prime++)
    {
#ifdef DEBUG_S0
      cout << "List #" << b_prime << "\n";
#endif
      for (long32 i = 0; i <= meissel::p_sqf[b_prime].size()-1; i++)
	{
	  meissel::count_unary_terms++;       
	  long32 m = meissel::p_sqf[b_prime][i];
	  long128 xm = meissel::x/abs32(m);
	  res += m*accessf.sum128_6(xm);
#ifdef DEBUG_S0
	  cout << "m " << m << "   xm " << xm << "   m*accessf.sum128_6(xm)= " << m*accessf.sum128_6(xm) << "   res " << res << endl;
#endif

	}
#ifdef DEBUG_S0
      cout << "\n";
#endif
    }

#ifdef DEBUG_S0
  cout << "S0\n";
#endif

  for  ( ; b_prime <= meissel::pi_y; b_prime++)
    { 
      long128 xm = meissel::x/primes::prime(b_prime);
      meissel::count_unary_terms++;
      res -=  primes::prime(b_prime)*accessf.sum128_6(xm);
#ifdef DEBUG_S0
      cout <<  primes::prime(b_prime)\
	   << "   primes::prime(b_prime)*accessf.sum128_6(xm) = " << -primes::prime(b_prime) *accessf.sum128_6(xm) << "   res " << res << endl;
#endif
    }
#ifdef DEBUG_S0
  cout << "S0                  = " << res << "\n";
#endif
  return res;
}

