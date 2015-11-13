// -*- C++ -*-
#ifndef primes_h
#define primes_h
#include<mylib.h>

namespace primes{
  void init_primes(long32);
  int number_of_primes();
  int max_prime();
  int prime(int);
}


namespace presieved_primes{
  extern long32 presieve_base;
  extern long32 number_of_presieve_primes;
  extern long32 sum_of_presieve_primes;
  extern long32 small_primes[];
  extern long* Sp;
  
  extern int primes_initialized;
  long32 prime(long32);
  long32 piB(long32 i);
  inline long sum(int i) {return Sp[i];}
  void init_prime_table(long32, long32 nbps=2);
  void display_prime_table();
  long32 number_of_primes();
  long32 max_prime();
  long32 index_of_first_prime_bigger_than(long32);
  void display();
  void init_sum_primes();
}


namespace primes_6{
  extern const int presieve_base;
  extern const int number_of_presieve_primes;
  extern const int sum_of_presieve_primes;

  extern long* Sp;
  extern int* ip_table;
  extern int primes_initialized;
  long32 prime(long32);
  long32 piB(long32 i);
  inline long sum(int i) {return Sp[i];}
  void init_primes(long);
  long32 number_of_primes();
  long32 index_of_first_prime_bigger_than(long x);
  void display();
  long32 number_of_primes();
  long32 max_prime();
  void init_sum_primes();
}
#endif
