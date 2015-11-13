#include"../Include/interval_sieve.h"

int main(int argc, char* argv[]) {
  if (argc==1)
    {
      cout << "ok\n";
      return 0;
    }
  long128 a=atolong128(argv[1]);
  long128 h=atolong128(argv[2]);
  presieved_primes::init_prime_table(100);
  presieved_primes::display();
  cout << "a=   " << a << "     a+h= " << a+h << endl;
  interval_sieve<bit_table,long128> T(a,a+h);
  T.display(T.get_bit_size());
  cout << "ok\n";
  T.eratos();
  T.display(T.get_bit_size());
  return 0;
}
