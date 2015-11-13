// -*- C++ -*-
#ifndef bit_sum_dynamic_h
#define bit_sum_dynamic_h
#include<mylib.h>

template <class btable, class longint> class sieve_sum_dynamic:
  public sieve_by_slice<btable, longint>
{
  
private:
  long32 BASE;
  longint* partial_sums_array;
  
public:
  sieve_sum_dynamic(long wsize , long end, int pmax);

  void display();
  
  
};


#include"sieve_sum_dynamic.hpp"
#endif
