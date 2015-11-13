#include<mylib.h>
#ifndef sieve_slices_sum6_h
#define sieve_slices_sum6_h

class sieve_slice_sum6: public sieve_slice6<bit_table, long64> {
 private:
  long64* sums;
  long128 last_total;
public:
  sieve_slice_sum6(long window_size, long startx);
  long128 sum(long64 n) {return last_total + sums[offset(n)];}
  void shift_window_forward();
  void display();
};


#include"sieve_slices_sum6.hpp"
#endif
