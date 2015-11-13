#include<mylib.h>
#include<sieve_slice6.h>
using namespace primes_6;

int main(int argc, char* argv[]) {
  long x = (argc>=2)? atol(argv[1]) : 1000000;
  long wsize= (argc>2)? atoi(argv[2]) : next_mult6(x);

  cout << "x= " << x << endl;
  cout << "Table des premiers jusqu'à 10000"  << endl;
  primes_6::init_primes(1000000);
  primes_6::display();

  cout << "wsize = " << wsize << endl;
  sieve_slice6<bit_table_cnte, long64> sieve(wsize,0, AUTO_SIEVE);
  cout << "res = " << sieve.count(x) << endl;
  return 0;
}
