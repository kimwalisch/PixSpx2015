// -*- C++ -*-
#ifndef prime_generator_h
#define prime_generator_h
#include"primes.h"
//#include"sieve_slices.h"

class prime_generator: public sieve_by_slice<bit_table, long64> {

public:
  prime_generator(long64 ws) : sieve_by_slice(2,1,ws,0,primes::presieve_base,AUTO_SIEVE) {}

  prime_generator(long64 ws, long64 starting_from): sieve_by_slice(2,1,ws,starting_from,primes::presieve_base,AUTO_SIEVE) {
    init_primes(starting_from); // next_prime() will be the first prime bigger than starting_from
  }

  long64 next_prime() {return sieve_by_slice<bit_table, long64>::get_next_prime();}

  void display() {
    cout << "Prime generator of size " << sieve_by_slice<bit_table, long64>::window_size\
	 << ".   Primes will start from = " << sieve_by_slice::get_integer(index_first_prime) << endl;
    cout << "window_start= " << sieve_by_slice::window_start << endl;
    sieve_by_slice::display();
  }

};
#endif
