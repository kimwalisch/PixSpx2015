#include<mylib.h>

#include<mylib.h>
using namespace presieved_primes;

int main(int argc, char* argv[]) {
  long x = (argc>=2)? atol(argv[1]) : 1000000;
  long wsize= (argc>2)? atoi(argv[2]) : next_mult6(x);

  cout << "x= " << x << endl;
  cout << "Table des premiers jusqu'à 100000"  << endl;
  presieved_primes::init_prime_table(100000);
  //presieved_primes::display();
  
  sieve_by_slice<bit_table_cnte, long64> sieve(2,1,wsize,0, presieved_primes::presieve_base, AUTO_SIEVE);

  
  long res= sieve.count(x);
  cout << "res = " << sieve.count(x) << endl;
  if (res != 78496) {
    cout << "Erreur: ce nombre devrait être égal à " << 78496 << endl;
    exit(1);
  }
  return 0;
}
