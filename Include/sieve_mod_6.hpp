// -*- C++ -*-
#ifndef sieve_mod_6_hpp
#define sieve_mod_6_hpp
#include"mylib.h"
#include"primes.h"
#include"prime_generator6.h"
#include"arith6.h"

const int CACHE_BIT_SIZE = 250000;
//const int CACHE_BIT_SIZE = 20;

template<class btable, class longint> void
sieve_mod_6<btable, longint>::set_next_i1_i5()
{
  bound_p =   (long) std::sqrt((double) w_last);
  next_i1.clear();
  next_i5.clear();
  next_i1.push_back(0);
  next_i5.push_back(0);
  int ip=1;
  cout  << "In set_netx offset_w_first= " << offset(w_first) << endl;
  for (int p= primes_6::prime(ip);  p <= bound_p ; p= primes_6::prime(++ip)) {
    long q= p /6;
    //cout << "p= " << p << " p % 6 " << p% 6 <<  "  q= " << q <<  " offset(p)= " << offset(p) << " image " << image(offset(p)) <<  endl;
    long offset_1p = offset(p);
    long offset_5p = offset(5*p);
    long offset_w_first = offset(w_first);
    
    if (offset_1p  < offset_w_first) {
      long q = 1+(offset_w_first-offset_1p)/(2*p);
      //cout << "offset_1p = " << offset_1p << "    offset_w_first= " << offset_w_first << "   q= " << q <<  endl;
      offset_1p += 2*p*q-offset_w_first;
      //cout << "offset_1p  adjusted to " << offset_1p << endl;
    }
    if (offset_5p < offset_w_first) {
      long q = 1+(offset_w_first-offset_5p)/(2*p);
      //cout << "offset_5p = " << offset_5p << "    offset_w_first= " << offset_w_first << "   q= " << q <<  endl;
      offset_5p += 2*p*q-offset_w_first;
      //cout << "offset_5p  adjusted to " << offset_5p << endl;
    }
    
    if (p % 6 == 1) {
      next_i1.push_back(offset_1p);
      next_i5.push_back(offset_5p);
      }
    else {
      next_i1.push_back(offset_5p);
      next_i5.push_back(offset_1p);
      }
  }
  max_ip = ip-1;
  cout << "max_ip= " << max_ip << "    prime(max_ip)= " << primes_6::prime(max_ip) << endl;


}

template<class btable, class longint> void
sieve_mod_6<btable, longint>::create(long64 w_size_approx, longint w_first_approx, sieve_type t)
{
  sieve_t = t;
  // w_size et w_first doivent être multiples de 6
  w_size = w_size_approx;
  int r = w_size % 6;

  if (r)
    w_size += 6 - r;   // Premier multiple de 6 au moins égal à wsize

  w_first = w_first_approx;
  r = w_first % 6;

  if (r)
    w_first -= r;

  w_last = w_first + w_size - 1;

  if (w_last < w_first_approx + w_size_approx - 1) {
    w_size += 6;
    w_last += 6;
  }
  
  btable::create(1+w_size/3);
  btable::unset_bit(0);
  
  set_next_i1_i5();
  if (sieve_t == AUTO_SIEVE)
    {
#ifdef DEBUG_SV
      cout << "sieve_by_slice<btable>::create: AUTO_SIEVE is set: Eratosthenes_sieve will be done\n";
#endif
      eratosthenes();
    }
}


template<class btable, class longint> void 
sieve_mod_6<btable, longint>::display(int how_many)
{
  cout << "Sieve_mod_6::display : [" << w_first << ", " << w_last << "]    w_size = " << w_size << "   bit_size = " <<  bit_table::bit_size << endl;
  int cnte=0;
  cout<< "Dernier index = " << btable::bit_size-1 << "    d'image " << image(btable::bit_size-1) << endl;
  cout << "Offset de wfirst = " << offset(w_first) << endl;
  for (int i = 0; i < how_many; i++)
    if (btable::get_bit(i))
      {
	cnte++;
	cout.width(8);
	cout << w_first + get_integer(i);
	if (cnte == how_many)
	  break;
      }
  //cout << "\nBit table : \n";
  //btable::display();
  cout << endl;
}

template<class btable, class longint> void 
sieve_mod_6<btable, longint>::display(int i1, int i2)
{
  cout << "Tranche [" << get_integer(i1) << ", " << get_integer(i2) << "]" << endl;
  cout << "Offset de wfirst = " << offset(w_first) << endl;
  //cout << "Sieve_mod_6::display : [" << w_first << ", " << w_last << "]    w_size = " << w_size << "   bit_size = " <<  bit_table::bit_size << endl;
  int cnte=0;
  for (int i = i1; i <= i2; i++)
    if (btable::get_bit(i))
      {
	cnte++;
	cout.width(8);
	cout << w_first + get_integer(i);
      }
  cout << endl;
}

template<class btable, class longint> void 
sieve_mod_6<btable, longint>::display_starts()
{
  cout << "Starts are\n";
  for (int ip=1; ip <= max_ip; ip++) {
    cout << "ip= " << ip << "    p= "  << primes_6::prime(ip) <<  "   i1 = " << next_i1[ip] <<  "   i5 = " << next_i5[ip] << endl;
  }
}



template<class btable, class longint> void 
sieve_mod_6<btable, longint>::eratosthenes()
{
  long limit= offset(w_last);
  
  for (long64 low=1; low < offset(w_last); low += CACHE_BIT_SIZE) {

    long64 high = std::min(low + CACHE_BIT_SIZE -1 , limit);

    //display(low, high);
    int ip=1;
    for (int ip=1 ; ip <= max_ip; ip++) {
      int p=primes_6::prime(ip);
      long inc=p+p;
      //cout << "Crible par p= " << p << " i1= " << next_i1[ip] <<    "    i5 = " << next_i5[ip] << endl;
      
      int i1 = next_i1[ip];
      for (; i1 <= high; i1 += inc) {
	btable::unset_bit(i1);
      }
      next_i1[ip] = i1; // - high;
	
      int i5 = next_i5[ip];
      for (; i5 <= high; i5 += inc) {
	btable::unset_bit(i5);
      }
      next_i5[ip] = i5; // - high;
    }
  }
}


template<class btable, class longint> void 
sieve_mod_6<btable, longint>::shift_forward()
{

  //#ifdef DEBUG_SV
  cout << "In sieve_slice::shift_window_forward window_first = " << w_first << endl;
  cout << "                                              end  = " << w_first+w_size-1 << endl;
  //#endif
  
  if (btable::init_counters()) {
    if (sieve_t==AUTO_SIEVE)
      last_total += btable::count(w_first+w_size-1);
  }
  w_first += w_size;
  w_last  += w_size;
  btable::fill();
  btable::unset_bit(0);
  set_next_i1_i5();

  if (sieve_t == AUTO_SIEVE)
    {
#ifdef DEBUG_SV
      cout << "sieve_slice::forward, AUTO_SIEVE is set: Eratosthenes sieve will be done" << endl;
#endif
      eratosthenes();
    }
}

template<class btable, class longint> void 
sieve_mod_6<btable, longint>::show(int how_many) {
  return;
}

/*
template<class btable, class longint> void 
sieve_slice6<btable, longint>::sieve_by(long64 p)
{
  long64 inc = p<<1;
  long64 true_inc = (p<<2) + (p<<1);

  
  int r  = p % 6;
  long q = p/6;
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

  if (!window_first)
    btable::unset_bit(1);  // 1 is not a prime
  // bound for the primes we need

  double bound_p = 1+sqrt((double)window_last);
  // primes of primes:: cannot exceed max_prime()
  double bound1_p = min(double(primes_6::max_prime()),bound_p);
  while (p = primes_6::prime(ip++), p <= bound1_p)
   {
     sieve_by(p);
     if (p >= window_first) 
       btable::set_bit(offset(p-window_first));
     //display();
   }

  if (bound_p > bound1_p) {
    cout << "primes_6::max_prime() = " << primes_6::max_prime()\
	 << "  is too small to sieve until window_last = " << window_last << endl;
    cout << "We finish eratosthenes_sieve using a prime_generator " << endl;
    prime_generator6 pg(long(min(1.1*bound_p, 4000000000.0)), primes_6::max_prime());
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


template<class btable, class longint> longint
sieve_slice6<btable, longint>::count(longint x)
{
  if (sieve_t == AUTO_SIEVE)
    while (x >= window_first + w_size) 
      {
	shift_window_forward();
      }

  return(last_total + 
	 btable::count(offset(x-window_first))); 
}



template<class btable, class longint> void 
sieve_slice6<btable, longint>::shift_window_backward()
{
  window_first -= w_size;
  btable::fill();
  btable::unset_bit(0);
  if (sieve_t == AUTO_SIEVE)
    {
      eratosthenes();
      last_total -= btable::count(offset(w_size-1));  
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
  index_first_prime = 1+offset(x - window_first);
}


template<class btable, class longint> longint
sieve_slice6<btable, longint>::count(longint x)
{
  if (sieve_t == AUTO_SIEVE)
    while (x >= window_first + w_size) 
      {
	shift_window_forward();
      }

  return(last_total + 
	 btable::count(offset(x-window_first))); 
}
*/

template<class btable, class longint> int 
sieve_mod_6<btable, longint>::belong_to_window(longint x)
{
  return (x >= w_first) && (x <= w_last);
}

#endif
