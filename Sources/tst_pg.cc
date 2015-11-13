#include<mylib.h>
#include<cmath>
#include<prime_generator.h>
#include<iostream>


int main(int argc, char* argv[]) {

  long64 N= (argc==2)? atolong128(argv[1]) : 10000;

  cout << "N = " << N << endl;
  cout << "\nPrime table upto " << N << endl;

  presieved_primes::init_prime_table(N,2);
  presieved_primes::display();

  long wsize = 5000000;
  long p;
  cout << "Creation d'un prime generator de taille " << wsize << endl;
  prime_generator pg(1200,N);
  pg.display();
  //long p=pg.get_first_prime();
  //cout << "Firsyp = " << p << endl;


  for (int i= 1; i<= 10; i++) {
    p=pg.next_prime(); 
    cout << "p=  " << p << endl;
  }
  return 0;
}
