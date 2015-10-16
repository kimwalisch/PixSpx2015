// -*- C++ -*-
#ifndef sieve128_pg_h
#define sieve128_pg_h
#include"mylib.h"
#include"sieve_slices.h"

typedef sieve_by_slice<bit_table, long128> sieve_128_btable;

class sieve128pg: public sieve_128_btable 
{
public:
  long128 startx;
  long64 size;
  sieve128pg(long64 sz, long128 x) {create(sz,x);}
  void create(long64 sz, long128 x);

  long128 pg_start() {return window_start;}
  long128 pg_end() {return get_window_end();}

  void display() {
    cout << "sieve_pg startx = " << "[" << pg_start() << ", " << get_window_end() << "]" << endl;
  };
  void eratos();
};


#endif

