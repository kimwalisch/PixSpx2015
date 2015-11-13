#include<mylib.h>
#include"../Include/primes.h"

int main(int argc, char* argv[]) {
  long32 nmax = (argc>=2)? atoi(argv[1]) : 10000;
  long32 n    = (argc==3)? atoi(argv[2]) : 100;
  
  cout << "\nInit prime_table upto " << nmax << endl;

  primes::init_primes(nmax);

  cout << "Prime table is created, primes::number_of_primes() = " << primes::number_of_primes() << endl;
  cout << "   primes::max_prime() = " << primes::max_prime() << endl << endl;
  cout << "   prime(" <<  0   << ") = " << primes::prime(0) << endl;
  cout << "   prime(" <<  1   << ") = " << primes::prime(1) << endl;
  cout << "   prime(" << primes::number_of_primes()  << ") = " << primes::prime(primes::number_of_primes()) << endl;
  cout << "   prime(" << primes::number_of_primes()+1  << ") = " << primes::prime(primes::number_of_primes() +1) << endl << endl;
  
  cout << "ok\n";
  return 0;
}
