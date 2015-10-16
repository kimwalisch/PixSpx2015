// -*- C++ -*-
#ifndef sieve_slices_sum_hpp
#define sieve_slices_sum_hpp
#include"mylib.h"
#include"primes.h"
#include"prime_generator.h"


template<class btable, class longint> void 
sieve_slice_sum<btable, longint>::shift_window_forward()
{
  
#ifdef DEBUG_SV
  cout << "In sieve_slice::shift_window_forward forward start = " << window_start << endl;
  cout << "                                           end  = " << window_start+window_size-1 << endl;
#endif
  sieve_by_slice<btable,longint>::shift_window_forward();
  //  Mettre a jour last_sum
}

template<class btable, class longint> void 
sieve_slice_sum<btable, longint>::display(int how_many)
{
  sieve_by_slice<btable,longint>::display(how_many);
  cout << "Maintenant les sommes\n";
  // A faire
}


template<class btable, class longint> void 
sieve_slice_sum<btable, longint>::display_sums() {
    cout << "Sieve_linear::display(): Les comptes\n";
    for ( int i = 0 ; i < btable::bit_size ; i++)
      {
	cout.width(8);
	cout << sum(get_integer(i));
      }
    cout << "\n\n";
}

#endif
