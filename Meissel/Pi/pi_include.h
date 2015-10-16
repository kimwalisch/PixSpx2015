// -*- C++ -*-
#ifndef pi_include_h
#define pi_include_h

// system files
#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<time.h>

// external files

//#include"./piglobal.h"
#include<meissel_global.h>

// local files
long128 P2();
long128 pi_fxy();
//long128 sieve_terms();
void simple_leaves_terms();
long128 pi_medium_primes_sum();
namespace meissel{
  long128 pi(long128 x, long64 y, long64 z, int verbose);
  }
#endif
