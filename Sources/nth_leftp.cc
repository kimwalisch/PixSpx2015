// -*- C++ -*-
#include<mylib.h>
#include<math.h>

long128 nthleftp(long128 x, long64 n) {
  double logx = log(double(x));
  cout << "Computing the " << n << " ith prime smaller than " << x <<  endl;
  long step = min(1.2 * n * logx  , 10000000000.0);
  long64 maxprime = min(sqrt(double(x+210.0)), 1000000000.0);

  presieved_primes::init_prime_table(maxprime,2);

  sieve_by_slice<bit_table, long128> sieve_table(2,1,step,x-step,6,AUTO_SIEVE);
  long128 p=sieve_table.get_previous_prime();
  while (p > x)
    p=sieve_table.get_previous_prime();
  long64  cnte=1;
  //cout << "First prime less than x = " << p << endl;
  while (cnte < n) {
    p=sieve_table.get_previous_prime();
    cnte++;
  }
  return p;
}
