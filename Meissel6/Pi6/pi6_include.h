// -*- C++ -*-
#ifndef pi_include6_h
#define pi_include6_h

// system files
#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<time.h>

// external files

#include<meissel_global6.h>

// local files
long128 P2();
long128 pi_fxy();
void simple_leaves_terms();
long128 pi_medium_primes_sum();
namespace meissel6{
  long128 pi(long128 x, long64 y, long64 z, int verbose);
  }
#endif
