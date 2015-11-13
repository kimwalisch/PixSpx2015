#include<mylib.h>
#include<cmath>
#include"prime_generator.h"
#include<iostream>


int main(int argc, char* argv[]) {

  long64 N= (argc==2)? atolong128(argv[1]) : 10000;

  double logN = log(double(N));
  long64 boundp = (long64) 2.2 * sqrt(N*logN);
  long64 wsize = boundp; 

  
  cout << "N = " << N << endl;
  cout << "\nPrime table upto " << boundp <<  " would be sufficient\n";

  presieved_primes::init_prime_table(boundp,2);
  presieved_primes::display();

  cout << "Creation d'un prime generator de taille " << wsize << endl;
  prime_generator pg(wsize);
  //pg.display();

  long64 p;
  for (int n=1+presieved_primes::number_of_presieve_primes; n <= N; n++) {
    p=pg.next_prime(); {
      if (n==N)
	cout << "For n= " << n << "\n  the nth prime is p=  " << p << endl;
    }
  }
  cout << p << endl;
  
  if ((N == 10000) && (p != 104729)) {
    cout << "Erreur: ce nombre devrait être égal à " << 124729 << endl;
    exit(1);
  }
  cout << "ok" << endl;
  return 0;

}
