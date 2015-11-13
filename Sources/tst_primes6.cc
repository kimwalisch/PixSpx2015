#include<iostream>
#include<sieve_slice6.h>

using namespace std;
using namespace primes6;

int main(int argc, char* argv[]) {
  long32 nmax = (argc>=2)? atoi(argv[1]) : 10000;
  long32 n    = (argc==3)? atoi(argv[2]) : 100;

  long upto = atol(argv[1]);
  primes6::init_primes(nmax);
  primes6::display();
  cout << "First ip bigger than " << 100 << "  = " << index_of_first_prime_bigger_than(100) << endl;
}

