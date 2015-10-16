// -*- C++ -*-
#ifndef sieve_mod_6_h
#define sieve_mod_6_h
#include <vector>
#include"mylib.h"
#include"primes.h"
#include"arith6.h"


template<class btable, class longint> class sieve_mod_6: 
  public btable
  {
  private:
    std::vector<int> next_i1;
    std::vector<int> next_i5;

    long bound_p;
    void set_next_i1_i5();
    
  protected:
    sieve_type sieve_t;
    long max_ip;

    
  public:

    longint w_first;
    longint w_last;
    long64  w_size;
    
    longint last_total;
    longint image(long index) {return w_first + get_integer(index);}
    
    long64 index_first_prime;
    long64 index_last_prime;

    sieve_mod_6() {};

    void create(long64 w_size_approx, longint w_first_approx, sieve_type t);
    
    sieve_mod_6(long64 w_size_approx, longint w_first_approx, sieve_type t) {
      create(w_size_approx, w_first_approx, t);
    }


    int belong_to_window(longint x);
    void show(int how_many = 0);
    //    void show(int i1, int i2);
    void show_starts();

    void eratosthenes();


    //longint cnt(long64 x);
    longint count(long64 x) {return last_total + btable::count(offset(x));}
    
    void display(int i1, int i2);
    void display(int how_many);
    void display();
    void display_starts();


    //    void sieve_by_ipn(long64 ip);
    //virtual void eratosthenes();

    void shift_forward();

    /*
      void shift_window_backward();
      void display_counts();
      longint get_first_prime();
      longint get_next_prime();
      longint get_previous_prime();
      longint get_previous_prime(longint x);
      longint get_next_prime_without_shifting();
      void init_primes(longint x);
    */

    };

#include"sieve_mod_6.hpp"

#endif
