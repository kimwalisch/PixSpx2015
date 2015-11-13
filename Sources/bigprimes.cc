// -*- C++ -*-
#include<mylib.h>
#include<math.h>
#include"sieve_pg.h"
#include"sieve_slices.h"

#include"prime_generator.h"

int main(int argc, char* argv[]) {
  long128 x  = atolong128(argv[1]);
  long64  n  = atolong64(argv[2]);
  long64  h  = atolong64(argv[3]);
  
  cout << "x     =  " << x  << endl;
  cout << "h  =  "    << h  << endl;
  cout << "n  =  "    << n  << endl;
  
  long64 wsz = min(double(h), double(10000000));

  //  sieve_by_slice<bit_table, long64> sieve(2,1,wsz,x,6,NO_SIEVE);
  sieve_pg sieve(wsz,x);
  cout << "sieve_large open\n";
  cout << "window start= " << sieve.window_start << endl;
  cout << "window end = " << sieve.window_start+sieve.get_window_end() << endl;

  
  primes::init_prime_table(1000000000);
  primes::display();




  cout << "sieve.window_start = " << sieve.window_start << endl;
  cout << "sieve.index_first_prime= " << sieve.index_first_prime << endl;
  sieve.init_first_prime(x);
  cout << "sieve.index_first_prime= " << sieve.index_first_prime << endl;
  long64 p;

  cout << "Here we start \n";
  //sieve.display();
  long64  cntep=1;
  p=sieve.next_prime();
  cout << "first p= " << p << endl;
  while (cntep < n) {
    p=sieve.next_prime();
    cntep++;
    //cout << cntep << " -> " << p << endl;
  }
  cout << "p= " << p << endl;
  return 0;
}
