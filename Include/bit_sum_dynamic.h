#ifndef bit_sum_dynamic_h
#define bit_sum_dynamic_h
#include<mylib.h>

class bit_sum_dynamic: public bit_table_cnte
{
private:
  long32 BASE;
  long64* partial_sums_array;
  long32 number_of_sums;
  long64 last_cnte;

 public:
  bit_sum_dynamic() {};
  bit_sum_dynamic(long n);
  ~bit_sum_dynamic();
  long64 sum(long i);
  void unset_bit(long);
  void display();
};

#endif
