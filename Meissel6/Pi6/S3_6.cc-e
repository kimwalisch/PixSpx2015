#include"pi6_include.h"

static sieve_slice6<bit_table_dynamic, long64> sieve;
static vector<long64> p_partial_sums;
static long128 xp;
static double  xp_double;
static long32  sieve_begin;
static long32  end;
static long32  pb;

void collect_binary_terms(long32);
void collect_binary_terms_double(long32);
void collect_non_binary_terms(long32);
void collect_non_binary_terms_double(long32);


long128 sumS3()
{
  long32 window_size = 10*meissel6::y;
  int r= window_size%6;
  if (r)
    window_size += 6-r;
  
  long64 xz = meissel6::x/meissel6::z;

  meissel6::binary_sum = 0;
  meissel6::non_binary_sum = 0;

  sieve.create(window_size, 0,  NO_SIEVE);

  p_partial_sums.resize(meissel6::pi_y,0);
  long32 aux_ip = min32(meissel6::ifgp-1, meissel6::pi_sqr4_x);
  if (meissel6::verbose) {
    if (meissel6::ifgp-1 <= 0)  // no bad primes
      cout << "All primes are good" << endl;
    else
      cout << "Bad primes : from  " << primes6::prime(1) << " upto " << primes6::prime(aux_ip) <<  endl;
    cout << "Good primes begin with " << primes6::prime(meissel6::ifgp)<< endl;
  }
  
  do 
    {
#ifdef DEBUG_ST
      cout << "window_start = " << sieve.window_first << "\n";
      cout << "window_end   = " << sieve.window_last << "\n";
      sieve.display();
      cout << "Partial_sums are\n";
      for (int i=0; i < p_partial_sums.size(); i++)
	cout << i << "  " << p_partial_sums[i] << endl;

      //p_partial_sums.display();
#endif
      long32 aux_ip = min32(meissel6::ifgp-1, meissel6::pi_sqr4_x);
      for (long32 b_prime = 1; b_prime <= aux_ip; b_prime++)
	{
	  pb  = primes6::prime(b_prime);
	  xp  = meissel6::x/pb;
	  long32 zpb = meissel6::z/pb;	  
	  long128 end128 = (sieve.window_first)? xp/sieve.window_first : xp;
	  if (end128 > meissel6::z) end = meissel6::z;
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
	  p_partial_sums[b_prime] += sieve.count(sieve.window_last);
	  //cout << "sieve_by " << pb << endl;
	  sieve.sieve_by(pb);
	}

#ifdef DEBUG_ST
      cout << "Now computing with good primes\n";
      cout << "Now computing with good primes begining with " << primes6::prime(meissel6::ifgp)<< endl;
#endif

      for (long32 b_prime = meissel6::ifgp; b_prime <= meissel6::pi_sqr4_x; 
	   b_prime++)
	{
	  pb  = primes6::prime(b_prime);
	  xp_double  = (double)(meissel6::x/pb);
	  double zpb = (double)(meissel6::z/pb);

	  double end_double = xp_double/sieve.window_first;
	  if (end_double > meissel6::z) end = meissel6::z;
	  else end = (long32)end_double;
	  
	  long64 begin64 = (long64)(xp_double/sieve.get_next_window_start());
	  //cout << "xp_double=  " << xp_double << "sieve.get_next_window_start()= " << sieve.get_next_window_start() << endl;
	  //cout << "begin64= " << begin64 << " end= " << end << endl;
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
	  p_partial_sums[b_prime] += sieve.count(sieve.window_last);
	  //cout << "sieve_by " << pb << endl;
	  sieve.sieve_by(pb);
	}
      sieve.shift_window_forward();
    } while (sieve.window_first <= xz);
  
#ifdef DEBUG_ST	 
  cout << "    binary_sum = " << meissel6::binary_sum << "\n";
  cout << "non_binary_sum = " << meissel6::non_binary_sum << "\n";
#endif

  return  meissel6::binary_sum + meissel6::non_binary_sum;
}





void 
collect_binary_terms(long32 b_prime)
{
  long32 s_prime = primes6::index_of_first_prime_bigger_than(sieve_begin);
  s_prime = max32(s_prime, b_prime+1);
  long32 q = primes6::prime(s_prime);

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
      meissel6::count_binary_terms++;
      meissel6::binary_sum += sieve.count(xp/q) 
	+ p_partial_sums[b_prime];
#ifdef DEBUG_ST	 
      cout << "     count  = " << sieve.count(xp/q) 
	   << "\n";
      cout << "     adding = " << sieve.count(xp/q) 
	+ p_partial_sums[b_prime]
	   << "\n";
#endif
      q = primes6::prime(++s_prime);
    }    
}

void 
collect_binary_terms_double(long32 b_prime)
{
  long32 s_prime = primes6::index_of_first_prime_bigger_than(sieve_begin);
  s_prime = max32(s_prime, b_prime+1);
  long32 q = primes6::prime(s_prime);

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

      meissel6::count_binary_terms++;
      meissel6::binary_sum += sieve.count((long64)(xp_double/q))
	+ p_partial_sums[b_prime];
      q = primes6::prime(++s_prime);
    }    
}

void 
collect_non_binary_terms(long32 b_prime)
{
  long32 a_prime = b_prime+1;


  for ( ; a_prime <= meissel6::pi_sqr2_z; a_prime++)
    {
      long32 index = index_of_first_bigger_than(meissel6::p_sqf[a_prime],sieve_begin, compare_abs_long32);
      long32 m = meissel6::p_sqf[a_prime][index];
      
      
      while (abs32(m) <= end)
	{
	  //cout << "   m = " << m << endl;
	  meissel6::count_non_binary_terms++;
	  long64 p_sum = sieve.count((long64)(xp/abs32(m))) + 
				     p_partial_sums[b_prime];
	  if (m < 0)
	    meissel6::non_binary_sum += p_sum;
	  else
	    meissel6::non_binary_sum -= p_sum;
	  m = meissel6::p_sqf[a_prime][++index];
	}
    }
}

void 
collect_non_binary_terms_double(long32 b_prime)
{
#ifdef DEBUG_ST
  cout << "collect_non_binary_terms double" << endl;
  cout << "b_prime= " << b_prime << "     prime(b_prime) = " << primes6::prime(b_prime) << endl;
#endif

  long32 a_prime = b_prime+1;

  for ( ; a_prime <= meissel6::pi_sqr2_z; a_prime++)
    {
      long32 index = index_of_first_bigger_than(meissel6::p_sqf[a_prime],sieve_begin, compare_abs_long32); 
      long32 m = meissel6::p_sqf[a_prime][index];
      while (abs32(m) <= end)
	{
	  //cout << "   m = " << m << endl;
	  meissel6::count_non_binary_terms++;
	  long64 p_sum = sieve.count((long64)(xp_double/abs32(m)))
	    + p_partial_sums[b_prime];
	  if (m < 0)
	    meissel6::non_binary_sum += p_sum;
	  else
	    meissel6::non_binary_sum -= p_sum;
	  m = meissel6::p_sqf[a_prime][++index];
	}
    }
}

