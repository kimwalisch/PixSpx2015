// -*- C++ -*-
#ifndef sieve_slice6_h
#define sieve_slice6_h
#include"mylib.h"
#include"primes.h"
#include"arith6.h"

template<class btable, class longint> class sieve_slice6: 
  public btable
  {
  protected:
    sieve_type sieve_t;
  public:
    longint window_first;
    longint window_last;
    longint get_next_window_start() const { return window_first + window_size;}
    longint last_total;
    long64 window_size;
    
    long64 index_first_prime;
    long64 index_last_prime;
    sieve_slice6() {};
    sieve_slice6(long64 window_size, longint window_first, sieve_type t) {
      create(window_size, window_first, t);
    }

    longint count(longint x);
    //longint count(long64 x) {return last_total+btable::count(offset(x));}
    
    void create(long64 window_size, longint window_first, sieve_type t);
    
    void display(int how_many = 0);

    void sieve_by(long64 p);
    //    void sieve_by_ipn(long64 ip);
    virtual void eratosthenes();

    void shift_window_forward();
    void shift_window_backward();
    void display_counts();
    longint get_first_prime();
    longint get_next_prime();
    longint get_previous_prime();
    longint get_previous_prime(longint x);
    longint get_next_prime_without_shifting();
    void init_primes(longint x);
    int belong_to_window(longint x);
				  
    ~sieve_slice6() {};

    };

#include"sieve_slice6.hpp"

#endif
