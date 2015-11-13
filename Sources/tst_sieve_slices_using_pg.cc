#include<mylib.h>

int main(int argc, char* argv[]) {

  long128 a = (argc>=2)? atolong128(argv[1]) : 1000000000000;
  cout << "a= " << a << endl;

  long64 maxprime = (argc>=3)? atol(argv[2]) : 1000000;

  presieved_primes::init_prime_table(maxprime,2);
  presieved_primes::display();


  sieve_by_slice<bit_table, long128> sieve_table(2,1,1000,a,6,AUTO_SIEVE);

  sieve_table.display();

  cout << "ok\n";
  return 0;
  
}
