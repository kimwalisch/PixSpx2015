// -*- C++ -*-
#ifndef prime_generator6_h
#define prime_generator6_h
#include"primes.h"
#include"sieve_slice6.h"

class prime_generator6: public sieve_slice6<bit_table, long64> {

public:
  prime_generator6(long64 ws) : sieve_slice6(ws,0,AUTO_SIEVE) {}

  prime_generator6(long64 ws, long64 starting_from): sieve_slice6(ws,starting_from,AUTO_SIEVE) {
    init_primes(starting_from); // next_prime() will be the first prime bigger than starting_from
  }

  long64 next_prime() {return sieve_slice6<bit_table, long64>::get_next_prime();}

  void display() {
    cout << "Prime generator of size " << sieve_slice6<bit_table, long64>::window_size\
	 << ".   Primes will start from = " << get_integer(index_first_prime) << endl;
    cout << "window_first= " << window_first << endl;
    sieve_slice6::display();
  }

};
#endif
