// -*- C++ -*-
#ifndef pi_global_h
#define pi_global_h
#include<mylib.h>

namespace meissel6{
  extern long128 x;
  extern long64  y;
  extern long64  z;
  extern long64  xy;
  extern long64  sqr2_x;
  extern long64  pi_sqr2_x;
  extern long32  sqr3_x;
  extern long32  pi_sqr3_x;
  extern long32  sqr2_z;
  extern long32  pi_sqr2_z;
  extern long32  sqr2_x_y;
  extern long32  pi_sqr2_x_y;
  extern long32  sqr4_x;
  extern long32  pi_sqr4_x;
  extern long32  pi_y;
  extern long32  x_y2;
  extern long32  pi_x_y2;

  extern long32  bound_for_good_primes;
  extern long32  ifgp;
  extern long    fgp;
  
  extern vector<vector<long32> > p_sqf;
  extern arith_mod32 arith_zk;

  extern long64* sx; // sx[k]is used to keep sum{f(p_0) + f(p_1) + .... + f(p_k)} p_0 = 5 
  extern long64 sy;

  
  extern long128  binary_sum;
  extern long128  non_binary_sum;
  extern long128  simple_leaves_sum;
  extern long64   count_unary_terms;
  extern long64   count_binary_terms;
  extern long64   count_non_binary_terms;
  extern long64   last_clock;
  extern long64   starting_clock;
  extern int      verbose;

  extern double log_x;

  void tabule_sx();
  void time_msg(int indent, char* s, long64 last_time = last_clock);
  void etoile(long64, long64);
  //  void read_data(int argc, char *argv[]);
  void compute_aux_data(int verbose);
  //long128 pi(long128 x, long64 y, long64 z, int verbose);
  
}
void error();

#endif
