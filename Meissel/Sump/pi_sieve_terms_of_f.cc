#include"pi_include.h"

static sieve_by_slice<bit_table_dynamic, long64> sieve;
static Vector<long64> p_partial_sums;
static long128 xp;
static double  xp_double;
static long32  sieve_begin;
static long32  end;
static long32  pb;

void 
collect_binary_terms(long32 b_prime)
{
  long32 s_prime = primes::index_of_first_prime_bigger_than(sieve_begin);
  s_prime = max32(s_prime, b_prime+1);
  long32 q = primes::prime(s_prime);

#ifdef DEBUG_ST
  cout << "collect_binary_terms" << endl;
  cout << "     s_prime = " << s_prime << "\n";
  cout << "        p(s) = " << q  << "\n";
#endif
  
  while (q <= end)
    {
#ifdef DEBUG_ST
      cout << "collect_binary_terms" << endl;
      cout << "       q = " << q << "\n";
      cout << "x/p(b)/q = " << xp/q << "\n";
#endif
      meissel::count_binary_terms++;
      meissel::binary_sum += sieve.count(xp/q) 
	+ p_partial_sums[b_prime];
#ifdef DEBUG_ST	 
      cout << "     count  = " << sieve.count(xp/q) 
	   << "\n";
      cout << "     adding = " << sieve.count(xp/q) 
	+ p_partial_sums[b_prime]
	   << "\n";
#endif
      q = primes::prime(++s_prime);
    }    
}

void 
collect_binary_terms_double(long32 b_prime)
{
  long32 s_prime = primes::index_of_first_prime_bigger_than(sieve_begin);
  s_prime = max32(s_prime, b_prime+1);
  long32 q = primes::prime(s_prime);

#ifdef DEBUG_ST
  cout << "collect_binary_terms_double" << endl;
  cout << "     s_prime = " << s_prime << "\n";
  cout << "        p(s) = " << q  << "\n";
#endif

  while (q <= end)
    {
#ifdef DEBUG_ST
      cout << "collect_binary_terms_double end=" << end << endl;
      cout << "       q = " << q << "\n";
      cout << "x/p(b)/q = " << floor(xp_double/q) << "\n";
#endif

      meissel::count_binary_terms++;
      meissel::binary_sum += sieve.count((long64)(xp_double/q))
	+ p_partial_sums[b_prime];
#ifdef DEBUG_ST
      if ((b_prime==4)  && (q==53))
	sieve.display();
      cout << "     count  = " << sieve.count((long64)(xp_double/q))
	   << "\n";
      cout << "     adding = " << sieve.count((long64)(xp_double/q))
	+ p_partial_sums[b_prime]
	   << "\n";
#endif
      q = primes::prime(++s_prime);
    }    
}

void 
collect_non_binary_terms(long32 b_prime)
{
  long32 a_prime = b_prime+1;

  for ( ; a_prime < meissel::pi_sqr2_z; a_prime++)
    {
      long32 index = meissel::p_sqf[a_prime].index_of_first_bigger_than(sieve_begin, 
							  compare_abs_long32);
      long32 m = meissel::p_sqf[a_prime][index];
      while (abs32(m) <= end)
	{
	  meissel::count_non_binary_terms++;
	  long64 p_sum = sieve.count((long64)(xp/abs32(m))) + 
				     p_partial_sums[b_prime];
	  if (m < 0)
	    meissel::non_binary_sum += p_sum;
	  else
	    meissel::non_binary_sum -= p_sum;
	  m = meissel::p_sqf[a_prime][++index];
	}
    }
}

void 
collect_non_binary_terms_double(long32 b_prime)
{
  long32 a_prime = b_prime+1;

  for ( ; a_prime < meissel::pi_sqr2_z; a_prime++)
    {
      long32 index = meissel::p_sqf[a_prime].index_of_first_bigger_than(sieve_begin, 
							   compare_abs_long32);
      long32 m = meissel::p_sqf[a_prime][index];
      while (abs32(m) <= end)
	{
	  meissel::count_non_binary_terms++;
	  long64 p_sum = sieve.count((long64)(xp_double/abs32(m)))
	    + p_partial_sums[b_prime];
	  if (m < 0)
	    meissel::non_binary_sum += p_sum;
	  else
	    meissel::non_binary_sum -= p_sum;
	  m = meissel::p_sqf[a_prime][++index];
	}
    }
}

void
sieve_terms()
{
  long32 window_size = 10*meissel::y;
  long64 xz = meissel::x/meissel::z;

  meissel::binary_sum = 0;
  meissel::non_binary_sum = 0;

  sieve.create(2, 1, window_size, 0, primes::presieve_base, NO_SIEVE);

  p_partial_sums.create(meissel::pi_y);
  p_partial_sums.set_elts_to(0);

  do 
    {
#ifdef DEBUG_ST
      cout << "window_start = " << sieve.get_window_start() << "\n";
      cout << "window_end   = " << sieve.get_window_end() << "\n";
#endif
      long32 aux_ip = min32(meissel::bound_for_good_primes, meissel::pi_sqr4_x);
      for (long32 b_prime = 0; b_prime < aux_ip; b_prime++)
	{
	  pb  = primes::prime(b_prime);
	  xp  = meissel::x/pb;
	  long32 zpb = meissel::z/pb;	  
	  long128 end128 = (sieve.get_window_start())? xp/sieve.get_window_start() : xp;
	  if (end128 > meissel::z) end = meissel::z;
	  else end = (long32)end128;

	  long64 begin64 = (long64)(xp/sieve.get_next_window_start());
	  
	  if (begin64 < end)
	    {
	      sieve_begin = max32((long32)begin64, zpb);
#ifdef DEBUG_ST	 
	      cout << "\n    b_prime  = " << b_prime << "\n";
	      cout << "    prime(b) = " << pb << "\n";
	      cout << "  x/prime(b) = " << xp << "\n";
	      cout << "      sieve_begin  = " << sieve_begin << "\n";
	      cout << "        end  = " << end   << "\n";
#endif
	      collect_binary_terms(b_prime);
	      collect_non_binary_terms(b_prime);
	    }
	  p_partial_sums[b_prime] += sieve.count(sieve.get_window_end());
	  sieve.sieve_by(pb);
	}
#ifdef DEBUG_ST
      cout << "Now computing with good primes\n";
#endif

      for (long32 b_prime = meissel::bound_for_good_primes; b_prime < meissel::pi_sqr4_x; 
	   b_prime++)
	{
	  pb  = primes::prime(b_prime);
	  xp_double  = (double)(meissel::x/pb);
	  double zpb = (double)(meissel::z/pb);

	  double end_double = xp_double/sieve.get_window_start();
	  if (end_double > meissel::z) end = meissel::z;
	  else end = (long32)end_double;
	  
	  long64 begin64 = (long64)(xp_double/sieve.get_next_window_start());
      
	  if (begin64 < end)
	    {
	      sieve_begin = max32((long32)begin64, zpb);
#ifdef DEBUG_ST	 
	      cout << "\n    b_prime  = " << b_prime << "\n";
	      cout << "    prime(b) = " << pb << "\n";
	      cout << "  x/prime(b) = " << floor(xp_double) << "\n";
	      cout << "      sieve_begin  = " << sieve_begin << "\n";
	      cout << "        end  = " << end   << "\n";
#endif
	      collect_binary_terms_double(b_prime);
	      collect_non_binary_terms_double(b_prime);
	    }
	  p_partial_sums[b_prime] += sieve.count(sieve.get_window_end());
	  sieve.sieve_by(pb);
	}
      sieve.shift_window_forward();
    } while (sieve.get_window_start() <= xz);
  
#ifdef DEBUG_ST	 
  cout << "    binary_sum = " << meissel::binary_sum << "\n";
  cout << "non_binary_sum = " << meissel::non_binary_sum << "\n";
#endif
}

