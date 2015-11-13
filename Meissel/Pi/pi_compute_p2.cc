#include"pi_include.h"

// Local sieve_tables
static sieve_by_slice<bit_table, long64> aux_sieve;
static sieve_by_slice<bit_table_cnte, long64> main_sieve;

long128 
main_term_of_p2() 
{
  long64 aux_window_size  = min64(10*((long64)meissel::y), 2000000);
  long64 main_window_size = min64(10*((long64)meissel::y), 2000000);
  long64 q;
  long128 sum = (long128)0;
  aux_sieve.create (2, 1, aux_window_size, meissel::sqr2_x, presieved_primes::presieve_base, AUTO_SIEVE);
  q = aux_sieve.get_previous_prime(meissel::sqr2_x);

  main_sieve.create(2, 1, main_window_size, 0, presieved_primes::presieve_base, AUTO_SIEVE);

  // Computation of the largest prime p not greater than sqr2 x

  meissel::pi_sqr2_x = main_sieve.count(meissel::sqr2_x);

#ifdef DEBUG_P2
  cout << "pi(sqr2_x) = " << meissel::pi_sqr2_x << "\n";
  int cnt=0;
  int step = (meissel::pi_sqr2_x - meissel::pi_y)/100;
  cout << "step= " << step << endl;
#endif

  while (q > meissel::y)
    {
      long64 xq;
      long64 pi_xq;
      xq = meissel::x/q;
      pi_xq = main_sieve.count(xq);
#ifdef DEBUG_P2
      cnt++;
      cout.width(8); cout << "main_term_of_p2: q =  " ;
      cout.width(5); cout << q ;
      cout.width(8); cout << "   x/q = ";
      cout.width(10); cout << xq << "\n";
      cout.width(8); cout << "pi(x/q) = ";
      cout.width(10); cout << pi_xq << "\n";
      cout << "cnt= " << cnt << endl;
      if (cnt > step )
	{
	  cout << "*";
	  cout.flush();
	  cnt=0;
	}
#endif

      sum += pi_xq;
      q = aux_sieve.get_previous_prime();
    } 
#ifdef DEBUG_P2
  cout  << "cnt= " << cnt  << endl;
#endif
  return sum;
}

long128 
P2()
{
  cout.flush();
  if (meissel::y >= meissel::sqr2_x) return (long128)0;
  long128 main_term = main_term_of_p2();
  long64  a = meissel::pi_y;

  long128 aux_term = (long128)(meissel::pi_sqr2_x - a);
  aux_term *= meissel::pi_sqr2_x + a  -  1;
  aux_term /= 2;

#ifdef DEBUG_P2
  cout << "a = " << a << "\n";
  cout << "main_term = " << main_term << "\n";
  cout << "aux_term = " << aux_term << "\n";
#endif



  return main_term - aux_term;
}
