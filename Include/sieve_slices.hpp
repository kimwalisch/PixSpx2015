// -*- C++ -*-
#ifndef sieve_by_slice_hpp
#define sieve_by_slice_hpp
#include"mylib.h"
#include"primes.h"
#include"prime_generator.h"

template<class btable, class longint> void 
sieve_by_slice<btable, longint>::create(int k0, int l0, long64 slice_size, 
					longint startx, int presieve_base, sieve_type t)
{
  sieve_t= t;
  k = k0; l = l0;
  access_frame::create(presieve_base, k, l);
  window_start=prev_mult<longint>(startx, get_period());
  window_end=next_mult<longint>(startx+slice_size, get_period())-1;
  window_size=(window_end-window_start+1);
  table_inverses.create((int)get_period());
  //cout << "window_size= " << window_size << endl;
  //cout << "lower_index64 de window_size= " << lower_index64(window_size) << endl;
  btable::create(1 + lower_index64(window_size));
  btable::unset_bit(0);
  last_total = 0;
  if (sieve_t == AUTO_SIEVE)
    {
#ifdef DEBUG_SV
      cout << "sieve_by_slice<btable>::create: AUTO_SIEVE is set: Eratosthenes_sieve will be done\n";
#endif
      eratosthenes();
    }
  //display();
}

template<class btable, class longint> void 
sieve_by_slice<btable, longint>::sieve_by(long64 p)
{
  long64 inc = p<<1;
  long64 true_inc = (p<<2) + (p<<1);
  
  int r  = p % 6;
  longint start;
  long64 index;
  
  if (r==1)
    {
      // j=0
      start = p;
      if (start < window_start)
	start += ((window_start-start)/true_inc + 1) * true_inc;
      index = lower_index64(start-window_start);
      for ( ; index < btable::get_bit_size(); index += inc)
	btable::unset_bit(index);

      // j=1
      start= p+(p<<2);   // 5p
      if (start < window_start)
	start += ((window_start-start)/true_inc + 1) * true_inc;
      index = lower_index64(start-window_start);
      for ( ; index < btable::get_bit_size(); index += inc)
	btable::unset_bit(index);
    }
  else // r=5
    {
      //j=0;
      start= p+(p<<2);
      if (start < window_start)
	start += ((window_start-start)/true_inc + 1) * true_inc;
      index = lower_index64(start-window_start);
      for ( ; index < btable::get_bit_size(); index += inc)
	btable::unset_bit(index);

      //j=1
      start= p;
      if (start < window_start)
	start += ((window_start-start)/true_inc + 1) * true_inc;
      index = lower_index64(start-window_start);
      for ( ; index < btable::get_bit_size(); index += inc)
	btable::unset_bit(index);
    }
}


template<class btable, class longint> void 
sieve_by_slice<btable, longint>::shift_window_forward()
{

#ifdef DEBUG_SV
  cout << "In sieve_slice::shift_window_forward forward start = " << window_start << endl;
  cout << "                                           end  = " << window_start+window_size-1 << endl;
#endif
  
  if (btable::init_counters()) {
    if (sieve_t==AUTO_SIEVE)
      last_total = count(window_start+window_size-1);
  }
  window_start += window_size;
  btable::fill();
  btable::unset_bit(0);
  if (sieve_t == AUTO_SIEVE)
    {
#ifdef DEBUG_SV
      cout << "sieve_slice::forward, AUTO_SIEVE is set: Eratosthenes sieve will be done" << endl;
#endif
      eratosthenes();
    }
}

template<class btable, class longint> void 
sieve_by_slice<btable, longint>::shift_window_backward()
{
  window_start -= window_size;
  btable::fill();
  btable::unset_bit(0);
  if (sieve_t == AUTO_SIEVE)
    {
      eratosthenes();
      last_total -= btable::count((int)lower_index64(window_size-1));  
    }
}

template<class btable, class longint> void 
sieve_by_slice<btable, longint>::display(int how_many)
{
  cout << "Sieve_linear::display size= " << window_size << "   [" << window_start << ", " << window_start + window_size - 1 << "]"  \
       << "    sieve_type= " << sieve_t;
  cout << "    last_total= " << last_total << endl;
  cout << "    btable::get_bit_size= " << btable::get_bit_size() << endl;
  int cnte=0;
  for (int i = 1; i < btable::get_bit_size(); i++)
    if (btable::get_bit(i))
      {
	cnte++;
	cout.width(8);
	cout << get_integer(i);
	if (cnte==how_many)
	  break;
      }
  cout << "\n\n";
}

template<class btable, class longint> void 
sieve_by_slice<btable, longint>::display_counts() {
    cout << "Sieve_linear::display(): Les comptes\n";
    for ( int i = 0 ; i < btable::bit_size ; i++)
      {
	cout.width(8);
	cout << count(get_integer(i));
      }
    cout << "\n\n";
}

template<class btable, class longint> void 
sieve_by_slice<btable, longint>::eratosthenes()
{
#ifdef DEBUG_SV
  cout << "In ERATOS\n";
#endif
  if (!presieved_primes::primes_initialized) {
    cout << "Error in sieve_by_slice::eratosthenes:   prime_table is not initailized\n";
    error();
  }
  if (sieve_t == NO_SIEVE)
    {
      cout << "Eratosthenes is not defined for this bit table!\n";
      error();
    }
  long64 p;
  long64 ip =1;

  if (!window_start && (l == 1)) btable::unset_bit(1);
  // bound for the primes we need
  double bound_p = sqrt((double)get_window_end()+2);
  // primes of primes:: cannot exceed max_prime()
  double bound1_p = min(double(presieved_primes::max_prime()),bound_p);
  while (p = presieved_primes::prime(ip++), p <= bound1_p)
   {
     sieve_by(p);
     if (p >= window_start && mod32(p, k) == l) 
       btable::set_bit(lower_index64(p-window_start));
   }
  if (bound_p > bound1_p) {
    cout << "presieved_primes::max_prime() = " << presieved_primes::max_prime()\
	 << "  is too small to sieve until window_end = " << get_window_end() << endl;
    cout << "We finish eratosthenes_sieve using a prime_generator " << endl;
    prime_generator pg(long(min(1.1*bound_p, 4000000000.0)), presieved_primes::max_prime());
    //pg.display();
    p=pg.next_prime();
    while (p < bound_p) {
      sieve_by(p);
      if (p >= window_start) 
	btable::set_bit(lower_index64(p-window_start)); 
      p=pg.next_prime();
    }
  }
  // cout << "\nTous les sieves sont faits. Faut il réinitialiser des compteurs\n";
  btable::init_counters();
  index_first_prime = 0;
  index_last_prime = btable::get_bit_size();
#ifdef DEBUG_SV
  cout << "OUT ERATOS\n";
#endif
}

template<class btable, class longint> longint
sieve_by_slice<btable, longint>::get_first_prime()
{
  index_first_prime=0;
  for (;;)
    {
      while(++index_first_prime < btable::get_bit_size())
	{
	  if (btable::get_bit(index_first_prime))
	    return get_integer(index_first_prime);
	}
      shift_window_forward();
    }
}

template<class btable, class longint> longint
sieve_by_slice<btable, longint>::get_next_prime()
{
  if (sieve_t == NO_SIEVE)
    {
      cout << "sieve_by_slice de type NO_SIEVE\n";
      cout << "sieve_by_slice::get_next_prime n'est pas défini\n";
      error();
    }
  for (;;)
    {
      while(++index_first_prime < btable::get_bit_size())
	{
	  if (btable::get_bit(index_first_prime))
	    return get_integer(index_first_prime);
	}
      //cout << "sieve_by_slices::forward\n";
      shift_window_forward();
    }
}

template<class btable, class longint> longint
sieve_by_slice<btable, longint>::get_next_prime_without_shifting()
{
  for (;;)
    {
      while(++index_first_prime < btable::get_bit_size())
	{
	  if (btable::get_bit(index_first_prime))
	    return get_integer(index_first_prime);
	}
      return 0;
    }
}

template<class btable, class longint> longint  
sieve_by_slice<btable, longint>::get_previous_prime()
{
  do
    {
      while (index_last_prime--)
	{
	  if (btable::get_bit(index_last_prime))
	    return get_integer(index_last_prime);
	}
      if (window_start) 
	{
	  shift_window_backward();
	}
    } while (index_last_prime);
  return 0;
}

template<class btable, class longint> longint
sieve_by_slice<btable, longint>::get_previous_prime(longint x)
{
  index_last_prime = (int)lower_index64(x - window_start) + 1;
  return get_previous_prime();
}

template<class btable, class longint> void
sieve_by_slice<btable, longint>::init_primes(longint x)
{ 
  // index_first_prime = 1+lower_index64(x - window_start); Remplacé le 13/11/2015 par
  cout << "In init_primes x= " << x << "   window_first= " << window_start << endl;
  index_first_prime = lower_index64(x - window_start);
  cout << "index_first_prime= " << index_first_prime << endl;
  if (get_integer(index_first_prime) == x) {
    index_first_prime -= 1;
  }
}

template<class btable, class longint> longint
sieve_by_slice<btable, longint>::count(longint x)
{
  if (sieve_t == AUTO_SIEVE)
    while (x >= window_start + window_size) 
      {
	shift_window_forward();
      }

  return(last_total + 
	 btable::count((int)lower_index64(x-window_start))); 
}

template<class btable, class longint> int
sieve_by_slice<btable, longint>::belong_to_window(longint x)
{
  return (x >= window_start) && (x < window_start + window_size);
}

#endif
