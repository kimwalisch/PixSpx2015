// -*- C++ -*-
#include<mylib.h>
#include<math.h>

int main(int argc, char* argv[]) {
  long128 x  = atolong128(argv[1]);
  long64  n  = atolong64(argv[2]);
  long64  h  = atolong64(argv[3]);
  
  cout << "x     =  " << x  << endl;
  cout << "h  =  "    << h  << endl;
  cout << "n  =  "    << n  << endl;
  
  primes::init_prime_table(20000);
  primes::display();
  long64 wsz = min(double(h), double(10000000));
  cout << "wsz= " << wsz << endl;
  sieve_pg sieve(wsz,x);

  cout << "sieve.window_start = " << sieve.window_start << endl;
  cout << "sieve.index_first_prime= " << sieve.index_first_prime << endl;
  cout << "sieve.index_first_prime= " << sieve.index_first_prime << endl;
  long64 p;

  cout << "Here we start \n";
  //sieve.display();
  long64  cntep=0;
  while (cntep < n) {
    p=sieve.next_prime();
    cntep++;
    //cout << cntep << " -> " << p << endl;
  }
  cout << "p= " << p << endl;
  return 0;
}
