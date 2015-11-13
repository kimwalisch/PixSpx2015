#include<mylib.h>
#include<cmath>
#include<prime_generator6.h>
#include<iostream>


int main(int argc, char* argv[]) {
  long N1 = (argc>=2)?  atol(argv[1]) : 1000000;
  long N2 = (argc>=3)?  atol(argv[2]) : 2000000;

  cout << "N1 = " << N1 << endl;
  cout << "N2 = " << N2 << endl;


  primes_6::init_primes(100000);
  primes_6::display();

  long wsize = 1000000;
  long p;
  cout << "Creation d'un prime generator de taille " << wsize << endl;
  prime_generator6 pg(100000,N1);
  // pg.display();
  p = pg.next_prime();
  cout << "First p " << p << endl;
  int cnte = 0;

  while (p <= N2) {
    cnte++;
    // cout << "p : " << p << endl;
    p = pg.next_prime();
  }
  cout << " cnte = " << cnte << endl;
  if ((N1==1000000) && (N2=2000000) && (cnte != 70435)) {
    cout << "Echec\n";
    exit(1);
  }
      
  return 0;
}
