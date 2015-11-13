#include"pi_include.h"

static  access_frame accessf;

long128 sumS0()
{
  long32 b_prime;

#ifdef DEBUG_S0
  cout << "In S0\n";
#endif

  accessf.create(primes::presieve_base, 2, 1);
  long128 res = accessf.lower_index128(meissel::x);

#ifdef DEBUG_S0
  cout << "res initialized  " << res << "\n";
#endif

  for (b_prime = 1; b_prime <= meissel::pi_sqr2_z; b_prime++)
    {
#ifdef DEBUG_S0
      cout << "List #" << b_prime << "  meissel::p_sqf[b_prime].get_dim()= " << meissel::p_sqf[b_prime].get_dim() << "\n";
#endif
      for (long32 i = 0; i < meissel::p_sqf[b_prime].size()-1; i++)
	{
	  meissel::count_unary_terms++;       
	  long32 m = meissel::p_sqf[b_prime][i];
	  long128 xm = meissel::x/abs32(m);
	  //cout << "m= " << m << "  donne " << accessf.lower_index128(xm) << "\n";
	  if (m < 0)
	    res -= accessf.lower_index128(xm);
	  else
	    res += accessf.lower_index128(xm);
	}
#ifdef DEBUG_S0
      cout << "\n";
#endif
    }

#ifdef DEBUG_S0
  cout << "simple_leaves\n";
#endif

  for  ( ; b_prime <= meissel::pi_y; b_prime++)
    { 
      long128 xm = meissel::x/primes::prime(b_prime);
      meissel::count_unary_terms++;
      res -= accessf.lower_index128(xm);
#ifdef DEBUG_S0
      cout <<  primes::prime(b_prime) << "\n";
      cout << " lower_index(xm) = " << accessf.lower_index128(xm) << "\n";
      cout << "  count_unary_terms= " <<       meissel::count_unary_terms++ << endl;
#endif
    }
  return res;
}

