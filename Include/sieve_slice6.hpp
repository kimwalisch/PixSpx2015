// -*- C++ -*-
#ifndef sieve_by_slice6_hpp
#define sieve_by_slice6_hpp
#include"mylib.h"
#include"primes.h"
#include"prime_generator6.h"


template<class btable, class longint> void
sieve_slice6<btable, longint>::create(long64 w_size, longint window_first, sieve_type t)
{
  // w_size et window_first doivent être multiples de 6
  int r=w_size%6;
  if (r)
    w_size += 6 - r;
  r=window_first%6;
  if (r)
    window_first -= r;
  btable::create(1+w_size/3);
  btable::unset_bit(0);
  sieve_t      = t;
  this->window_first = window_first;
  window_size  = w_size;
  window_last  = window_first + window_size - 1;
  last_total=0;
  if (sieve_t == AUTO_SIEVE)
    {
#ifdef DEBUG_SV
      cout << "sieve_by_slice<btable>::create: AUTO_SIEVE is set: Eratosthenes_sieve will be done\n";
#endif
      eratosthenes();
    }
}


template<class btable, class longint> void 
sieve_slice6<btable, longint>::display(int how_many)
{
  cout << "Sieve_slice6::display size= " << window_size\
       <<"   [" << window_first << ", " << window_first + window_size - 1 << "]"  << endl;
  cout << "bit_size= " << btable::get_bit_size() << endl;
  cout << "    last_total= " << last_total << endl;
  int cnte=0;
  for (int i = 0; i < btable::get_bit_size(); i++)
    if (btable::get_bit(i))
      {
	cnte++;
	cout.width(8);
	cout << window_first+get_integer(i);
	if (cnte==how_many)
	  break;
      }
  cout << "\nBit table : \n";
  btable::display();
  cout << endl;
}

template<class btable, class longint> void 
sieve_slice6<btable, longint>::sieve_by(long64 p)
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
      if (start < window_first)
	start += ((window_first-start)/true_inc + 1) * true_inc;
      index = offset(start-window_first);
      for ( ; index < btable::get_bit_size(); index += inc)
	btable::unset_bit(index);

      // j=1
      start= p+(p<<2);   // 5p
      if (start < window_first)
	start += ((window_first-start)/true_inc + 1) * true_inc;
      index = offset(start-window_first);
      for ( ; index < btable::get_bit_size(); index += inc)
	btable::unset_bit(index);
    }
  else // r=5
    {
      //j=0;
      start= p+(p<<2);
      if (start < window_first)
	start += ((window_first-start)/true_inc + 1) * true_inc;
      index = offset(start-window_first);
      for ( ; index < btable::get_bit_size(); index += inc)
	btable::unset_bit(index);

      //j=1
      start= p;
      if (start < window_first)
	start += ((window_first-start)/true_inc + 1) * true_inc;
      index = offset(start-window_first);
      for ( ; index < btable::get_bit_size(); index += inc)
	btable::unset_bit(index);
    }
}


template<class btable, class longint> void 
sieve_slice6<btable, longint>::eratosthenes()
{
#ifdef DEBUG_SV
  cout << "In ERATOS\n";
#endif
  if (sieve_t == NO_SIEVE)
    {
      cout << "Eratosthenes is not defined for this bit table!\n";
      error();
    }
  long64 p;
  long64 ip =1;
  //  b_table::unset_bit(0);
  if (!window_first)
    btable::unset_bit(1);  // 1 is not a prime
  // bound for the primes we need

  double bound_p = 1+sqrt((double)window_last);
  // primes of primes:: cannot exceed max_prime()
  double bound1_p = min(double(primes6::max_prime()),bound_p);
  while (p = primes6::prime(ip++), p <= bound1_p)
   {
     sieve_by(p);
     if (p >= window_first) {
       btable::set_bit(offset(p-window_first));
     }
     //display();
   }

  if (bound_p > bound1_p) {
    cout << "primes6::max_prime() = " << primes6::max_prime()\
	 << "  is too small to sieve until window_last = " << window_last << endl;
    cout << "We finish eratosthenes_sieve using a prime_generator " << endl;
    prime_generator6 pg(long(min(1.1*bound_p, 4000000000.0)), primes6::max_prime());
    //pg.display();
    p=pg.next_prime();
    while (p < bound_p) {
      sieve_by(p);
      if (p >= window_first) 
	btable::set_bit(offset(p-window_first));
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



template<class btable, class longint> void 
sieve_slice6<btable, longint>::shift_window_forward()
{
#ifdef DEBUG_SV
  cout << "In sieve_slice::shift_window_forward window_first = " << window_first << endl;
  cout << "                                              end  = " << window_first+window_size-1 << endl;
#endif
  if (btable::init_counters()) {
    if (sieve_t==AUTO_SIEVE)
      cout << "last_total was " << last_total << endl;
    last_total = count(window_first+window_size-1);
    cout << "now it is " << last_total << endl;   
  }
  window_first += window_size;
  window_last  += window_size;
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

template<class btable, class longint> longint
sieve_slice6<btable, longint>::count(longint x)
{
  //cout << "In sieve_mod_6 cnt x = " << x << "     last_total= " << last_total << endl;
  //cout << "w_first= " << window_first << "    x-w_first = " << x-window_first << endl;
  if (sieve_t == AUTO_SIEVE)
    while (x >= window_first + window_size) 
      {
	cout << "w_first + w_size = " << window_first + window_size << "   x= " << x << "   must foward " << endl;	
	shift_window_forward();
      }
  //cout << "wfirst = " << window_first << "    last_total= " << last_total << endl;
  return(last_total + 
	 btable::count(offset(x-window_first))); 
}



template<class btable, class longint> void 
sieve_slice6<btable, longint>::shift_window_backward()
{
  window_first -= window_size;
  btable::fill();
  btable::unset_bit(0);
  if (sieve_t == AUTO_SIEVE)
    {
      eratosthenes();
      last_total -= btable::count(offset(window_size-1));  
    }
}


template<class btable, class longint> void 
sieve_slice6<btable, longint>::display_counts() {
    cout << "Sieve_linear::display(): Les comptes\n";
    for ( int i = 0 ; i < btable::bit_size ; i++)
      {
	cout.width(8);
	cout << count(get_integer(i));
      }
    cout << "\n\n";
}


template<class btable, class longint> longint
sieve_slice6<btable, longint>::get_first_prime()
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
sieve_slice6<btable, longint>::get_next_prime()
{
  if (sieve_t == NO_SIEVE)
    {
      cout << "sieve_by_slice de type NO_SIEVE\n";
      cout << "sieve_by_slice::get_next_prime n'est pas défini\n";
      error();
    }
  for (;;)
    {
      //cout << "index first prime= " << index_first_prime << endl;
      while(++index_first_prime < btable::get_bit_size())
	{
	  //cout << "index first prime= " << index_first_prime << endl;	  	  
	  if (btable::get_bit(index_first_prime))
	    return window_first+get_integer(index_first_prime);
	}
      shift_window_forward();
    }
}

template<class btable, class longint> longint
sieve_slice6<btable, longint>::get_next_prime_without_shifting()
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
sieve_slice6<btable, longint>::get_previous_prime()
{
  do
    {
      while (index_last_prime--)
	{
	  if (btable::get_bit(index_last_prime))
	    return window_first + get_integer(index_last_prime);
	}
      if (window_first) 
	{
	  shift_window_backward();
	}
    } while (index_last_prime);
  return 0;
}

template<class btable, class longint> longint
sieve_slice6<btable, longint>::get_previous_prime(longint x)
{
  index_last_prime = offset(x - window_first) + 1;
  return get_previous_prime();
}

template<class btable, class longint> void
sieve_slice6<btable, longint>::init_primes(longint x)
{
  // index_first_prime = 1+offset(x - window_first); remplacé par 
  index_first_prime = offset(x - window_first);
  if (get_integer(index_first_prime) == x) {
    index_first_prime -= 1;
  }
}

/*
template<class btable, class longint> longint
sieve_slice6<btable, longint>::count(longint x)
{
  if (sieve_t == AUTO_SIEVE)
    while (x >= window_first + window_size) 
      {
	shift_window_forward();
      }

  return(last_total + 
	 btable::count(offset(x-window_first))); 
}
*/

template<class btable, class longint> int 
sieve_slice6<btable, longint>::belong_to_window(longint x)
{
  return (x >= window_first) && (x < window_first + window_size);
}

#endif
