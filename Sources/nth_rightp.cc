// -*- C++ -*-
#include<mylib.h>
#include<math.h>

long128 nthrightp(long128 x, long64 n) {
  double logx = log(double(x));
  cout << "Computing the " << n << " ith prime bigger than " << x <<  endl;
  long step = min(1.2 * n * logx  , 10000000000.0);
  //cout << "step = " << step << endl;
  //cout << "x= " << x << endl;
  long64 maxprime = min(sqrt(double(x+1.2*n*logx))+200, 1000000000.0);

  presieved_primes::init_prime_table(maxprime,2);
  //primes::display();


  sieve_by_slice<bit_table, long128> sieve_table(2,1,step,x,6,AUTO_SIEVE);
  long128 p=sieve_table.get_next_prime();
  long64  cnte=1;
  //cout << "First prime bigger than x = " << p << endl;
  while (cnte < n) {
    p=sieve_table.get_next_prime();
    cnte++;
  }
  return p;
}
