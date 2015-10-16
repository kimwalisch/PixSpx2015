#include"pi6_include.h"

long128 sumS0()
{
  long32 b_prime;

#ifdef DEBUG_S0
  cout << "In S0\n";
#endif

  long128 res = offset128(meissel6::x);

#ifdef DEBUG_S0
  cout << "res initialized  " << res << "\n";
#endif

  for (b_prime = 1; b_prime <= meissel6::pi_sqr2_z; b_prime++)
    {
#ifdef DEBUG_S0
      cout << "List #" << b_prime << "  meissel6::p_sqf[b_prime].get_dim()= " << meissel6::p_sqf[b_prime].get_dim() << "\n";
      #endif
      for (long32 i = 0; i < meissel6::p_sqf[b_prime].size()-1; i++)
	{
	  meissel6::count_unary_terms++;       
	  long32 m = meissel6::p_sqf[b_prime][i];
	  long128 xm = meissel6::x/abs32(m);
	  //cout << "m= " << m << "  donne " << get_integer128(xm) << "\n";
	  if (m < 0)
	    res -= offset128(xm);
	  else
	    res += offset128(xm);
	}
      #ifdef DEBUG_S0
      cout << "\n";
#endif
    }

  #ifdef DEBUG_S0
  cout << "simple_leaves\n";
  #endif

  for  ( ; b_prime <= meissel6::pi_y; b_prime++)
    { 
      long128 xm = meissel6::x/primes6::prime(b_prime);
      meissel6::count_unary_terms++;
      res -= offset128(xm);
      #ifdef DEBUG_S0
      cout <<  primes6::prime(b_prime) << "\n";
      cout << " lower_index(xm) = " << offset128(xm) << "\n";
      cout << "  count_unary_terms= " <<       meissel6::count_unary_terms++ << endl;
#endif
    }
  return res;
}

