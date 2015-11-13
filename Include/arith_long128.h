// -*- C++ -*-
#ifndef arith_long128_h
#define arith_long128_h
#include<stdlib.h>
#include<cmath>
#include<limits.h>
#include<iostream>
using namespace std;

typedef __uint128_t uint128;
typedef __int128_t  long128;

std::ostream& operator<<(std::ostream& stream, const long128& x);
long128 atolong128(char* s, int base=10);

double pow128(long128 x, double e);

#endif
