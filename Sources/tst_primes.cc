#include<mylib.h>
#include"../Include/primes.h"

int main(int argc, char* argv[]) {
  long32 nmax = (argc>=2)? atoi(argv[1]) : 10000;
  long32 n    = (argc==3)? atoi(argv[2]) : 100;
  
  cout << "\nInit prime_table upto " << nmax << endl;

  primes::init_prime_table(nmax,2);

  cout << "Prime table is created, first non presieved prime = " << primes::prime(1) << endl << endl;
  cout << "   primes::number_of_primes() = " << primes::number_of_primes() << endl;
  cout << "   primes::max_prime() = " << primes::max_prime() << endl << endl;
  cout << "   prime(" <<  0   << ") = " << primes::prime(0) << endl;
  cout << "   prime(" <<  1   << ") = " << primes::prime(1) << endl;
  cout << "   prime(" << primes::number_of_primes()  << ") = " << primes::prime(primes::number_of_primes()) << endl;
  cout << "   prime(" << primes::number_of_primes()+1  << ") = " << primes::prime(primes::number_of_primes() +1) << endl << endl;
  cout << "   primes::piB(100)   = " << primes::piB(100) << endl;

  int nbps=primes::number_of_presieve_primes;

  //primes::display();
  //primes::display_prime_table();
  //exit(1);
  
  if ((argc==1) && ( (primes::max_prime() != 9973) || (primes::piB(nmax-1) != 1229-nbps) || (primes::piB(200) != 46-nbps)))
    {
      cout << "Error: for n= 10000 \n";
      cout << "The correct value of primes::piB" << n << ") is 44\n";
      cout << "The correct values of number_of_primes is 1227 "\
	   << "and prime(1226) = 9973\n";
      exit(1);
    }
  cout << "ok\n";
  return 0;
}
