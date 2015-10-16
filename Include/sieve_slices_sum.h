// -*- C++ -*-
#include<mylib.h>
#ifndef sieve_slices_sum_h
#define sieve_slices_sum_h

template<class btable, class longint> class sieve_slice_sum: public sieve_by_slice<btable, longint> {
 private:
  long128 last_sum;
  long128* sums;
public:
 sieve_slice_sum(long window_size, long startx) :
   sieve_by_slice<btable,longint>(2,1,window_size,startx,6,AUTO_SIEVE) {
    last_sum=0;
  }
  //void create(int k0, int l0, long64 slice_size, longint startx, int presieve_base, sieve_type t);
  void sieve_by(long64 p);
  long128 sum(long64 n) {return last_sum + sums[offset(n)];}
  void shift_window_forward();
  void display(int);
  void display_sums();
};

#include"sieve_slices_sum.hpp"
#endif
