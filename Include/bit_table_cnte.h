// -*- C++ -*-
#ifndef bit_table_cnte_h
#define bit_table_cnte_h
#include<vector>
#include <cstdlib>
#include"./mylib.h"

class bit_table_cnte: public bit_table{

public:
  std::vector<long> counter_array;
  bit_table_cnte(long ell): bit_table(ell) {
    //counter_array = new long[get_word_size()];
    counter_array.resize(get_word_size(),0);
  }
  void create(long);
  int init_counters();
  bit_table_cnte() {};
  
  void display(long n=0) const;
  
  long count(long x) const { 
    return counter_array[get_word_index(x)]
      - number_bit_at_right(x);
  }

  /*
protected:
  ~bit_table_cnte();
  */
  };
#endif
