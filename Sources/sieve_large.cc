// -*- C++ -*-
#include<mylib.h>
#include<math.h>
#include"sieve_large.h"

sieve_large::sieve_large(long64 wsize, long128 startx): sieve_by_slice<bit_table,long128>(2,1,wsize,startx,6,NO_SIEVE) {
  sieve_by_slice<bit_table, long128>::init_primes(startx);
}


long128 sieve_large::next_prime() {
  return sieve_by_slice<bit_table, long128>::get_next_prime();
}
