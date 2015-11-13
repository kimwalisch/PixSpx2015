// -*- C++ -*-
#ifndef sieve_by_slice_h
#define sieve_by_slice_h
#include"mylib.h"
#include"primes.h"
//#include"prime_generator.h"


template<class btable, class longint> class sieve_by_slice: 
  public access_frame,
  public btable
  {
    protected:
    sieve_type sieve_t;
    long32 l;
    long32 k;
    table_invmod32 table_inverses;
    longint last_total;  
    public:
    longint window_start;
    longint window_end;
    long64 window_size;
    
    long64 index_first_prime;
    long64 index_last_prime;
    void create(int k, int l, long64 window_size, longint startx, int presieve_base, sieve_type t);
    sieve_by_slice() {};
    sieve_by_slice(long64 window_size, longint window_first, sieve_type t) {
      create(2,1,window_size, window_first, 6, t);
    }
    sieve_by_slice(int k, int l, long64 window_size, longint startx, int presieve_base, sieve_type t) {
      create(k, l, window_size, startx, presieve_base, t);
    }
    void display(int how_many = 0);
    void display_counts();
    ~sieve_by_slice() {};

    long64 index(long128 u) {return access_frame::lower_index64(u-window_start);}
    long64 index(long64 u) {return access_frame::lower_index64(u-window_start);}
    void sieve_by(long64 p);
    virtual void eratosthenes();
    int get_window_size() const{return window_size; }
    longint get_window_start() const {return window_start;}
    longint get_window_end() const { return window_start + window_size - 1; } 
    longint get_next_window_start() const { return window_start + window_size;}
    longint get_integer(long i) const{
      return window_start+access_frame::get_integer(i); }
    int belong_to_window(longint x);
    void shift_window_forward();
    void shift_window_backward();
    longint count(longint x);
    longint get_first_prime();
    longint get_next_prime();
    longint get_next_prime_without_shifting();
    longint get_previous_prime();
    longint get_previous_prime(longint x);
    void init_primes(longint x); // set index first prime at x position so that next_prime will be the first prime
    // bigger than x
};

#include"sieve_slices.hpp"

#endif
