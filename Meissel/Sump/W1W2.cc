#include<mylib.h>
#include<meissel_global.h>
#include<sieve_slices_sum.h>


long128 sumW1_W2()
{
#ifdef DEBUG_W1W2	 
  cout << "mp:  hard_part W1 W2  " << endl;
#endif
  long32 window_size = meissel::y;
  long128 sum_W1 = (long128)0;
  long128 sum_W2 = (long128)0;

  cout.precision(2);
  // The smallest values of pq used in the computation of W1 and W2 are
  //  close to x^(1/2). Therefore the largest value of  x/(pq) is x^(1/2)
  //  We don't want to tabulate the values sp(u) up to u=x^(1/2).
  //  These values will be computed using a sieve_by_slices
  
  sieve_slice_sum<bit_table_cnte,long64>  extra_primes(window_size, 0);
  //  extra_primes.create(2, 1, window_size, 0, primes::presieve_base);
  
#ifdef DEBUG_W1W2	 
  cout << "W1 W2 extra_primes-created " << endl;
  //extra_primes.display();
#endif
  do
    {
      long64 start = extra_primes.get_window_start();
      long64 end   = extra_primes.get_window_end();
      long32 aux_ip = min32(meissel::ifgp-1, meissel::pi_x_y2);
      for (long32 ip = 1+meissel::pi_sqr4_x; ip < aux_ip; ip++)
	{
	  long   p = primes::prime(ip);
	  //cout << "p= " << p << endl;
	  long128 xp = meissel::x/p;
	  long64  last_q = (start)? xp/start : xp;
	  long64 first_q = xp/(end+1); 
	  if (last_q  > meissel::y) last_q = meissel::y;
	  if (first_q > meissel::y) continue;

	  long32 first_iq = max32(primes::piB((long32)first_q), ip+1);
	  long32 last_iq  = primes::piB((long32)last_q);

	  for (long32 iq = first_iq; iq <= last_iq; iq++) {
	    long q=primes::prime(iq);
	    //cout << "q= " << q << endl;
	    sum_W1 += p*q*extra_primes.sum((long64)(xp/q));
	  }
	}

      aux_ip = max32(1+meissel::pi_sqr4_x, meissel::ifgp);
      //cout << "aux_ip= " << aux_ip << "  prime(aux_ip)= " << primes::prime(aux_ip) << endl;
      for (long32 ip = aux_ip; ip <= meissel::pi_x_y2; ip++)
	{
	  long     p = primes::prime(ip);
	  double  xp = meissel::x/p;
	  //cout << "p= " << p << "    xp= " << xp << endl;
	  double last_q = (start)? xp/start : xp;
	  double first_q = xp/(end+1);
	  if (first_q > meissel::y) continue;

	  if (last_q  > meissel::y) last_q = meissel::y;

	  long64 first_iq = max32(1+primes::piB((long32)first_q), ip+1);
	  long64 last_iq  = primes::piB((long32)last_q);
	  for (long32 iq = first_iq; iq <= last_iq; iq++) {
	    long q=primes::prime(iq);
	    sum_W1 += p*q*extra_primes.sum((long64)(xp/q));
	  }
	}
      // contribution to W2


      long32 start_ip = 1+max32(meissel::pi_x_y2, meissel::pi_sqr4_x);
      aux_ip = min32(meissel::ifgp-1, meissel::pi_sqr2_x_y);
      for (long32 ip = start_ip; ip <= aux_ip; ip++)
	{
	  long    p = primes::prime(ip);
	  long128 xp = meissel::x/p;
	  long64 last_q  = (start)? xp/start : xp;
	  long64 first_q = xp/(end+1); 
	  long64   max_q = squareroot128(xp);
	  if (first_q > max_q) continue;
	  if (last_q  > max_q) last_q = max_q;

	  
	  long64 first_iq = max32(primes::piB((long32)first_q), ip+1);
	  long64 last_iq  = primes::piB((long32)last_q);
	  for (long32 iq = first_iq; iq <= last_iq; iq++) {
	    long64 q=primes::prime(iq);
	    sum_W2 +=  p*q*extra_primes.sum((long64)(xp/q));
	  }
	}
      
      //cout << "good primes\n";	    
      aux_ip = max32(start_ip, meissel::ifgp-1);
      int lastip=meissel::pi_sqr2_x_y;
      for (long32 ip = aux_ip; ip <= meissel::pi_sqr2_x_y; ip++)
	{
	  long32   p = primes::prime(ip);
	  double  xp = meissel::x/p;
	  double last_q  = (start)? xp/start : xp;
	  double first_q = xp/(end+1);
	  double   max_q = sqrt(xp);
	  if (last_q  > max_q) last_q = max_q;
	  if (first_q > max_q) continue;
	  
	  long64 first_iq = max32(1+primes::piB((long32)first_q), ip+1);
	  long64 last_iq  = primes::piB((long32)last_q);
	  for (long32 iq = first_iq; iq <= last_iq; iq++) {
	    long64 q=primes::prime(iq);
	    sum_W2 += p*q*extra_primes.sum((long64)(xp/q));
	  }
	}
      extra_primes.shift_window_forward();
    }
  while(extra_primes.get_window_start() <= meissel::sqr2_x) ;
  
  if (meissel::verbose)
    {
      cout << "         W1 = " << sum_W1 << "\n";
      cout << "         W2 = " << sum_W2 << "\n";
      meissel::time_msg(9,(char*)"medium_primes:W1_W2"); 
      cout.flush();
    }
  
  return sum_W1 + sum_W2;
}
