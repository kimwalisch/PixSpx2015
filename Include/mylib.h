#ifndef mylib_h
#define mylib_h
#include<iostream>
#include<fstream>
#include<limits.h>
#include<cstdlib>
#include<time.h>
#include<algorithm>

#include"arith_long128.h"
#include"arith_64_32.h"

inline void error() {exit(0);}

#include"arith_structured_types.h"
#include"arith_basic_functions.h"

#include"index_first_bg.h"
#include"bit_table.h"
#include"bit_table_cnte.h"
#include"sieve_access_frame.h"
#include"sieve_slice6.h"
#include"sieve_slices.h"
#include"prime_tables.h"
#include"bit_table_dynamic.h"
#include"prime_generator.h"
#include"sieve128_pg.h"
#include"nextPrime.h"

long128 nthrightp(long128 x, long64 n);
long128 nthleftp(long128 x, long64 n);


#endif
