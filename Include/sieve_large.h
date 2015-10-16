// -*- C++ -*-
#ifndef sieve_large_h
#define sieve_large_h

class sieve_large: public sieve_by_slice<bit_table, long128> {
 public:
  sieve_large(long wsize, long128 startx);
  long128 next_prime();
};
  
#endif

