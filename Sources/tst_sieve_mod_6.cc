#include<mylib.h>
#include<sieve_mod_6.h>

int main(int argc, char* argv[]) {
  long w_size_approx   = (argc >= 2)? atol(argv[1]) : 100;
  long w_first_approx  = (argc >= 3)? atol(argv[2]) : 20;
  long x =  (argc >= 4)? atol(argv[3]) : 1000;
  cout << "w_size_approx = " << w_size_approx << endl;
  cout << "w_first_approx = " << w_first_approx << endl;
  
  cout << "Primes will be done \n";
  primes_6::init_primes(100000);
  cout << "Primes done \n";
  
  primes_6::display();
  
  sieve_mod_6<bit_table_cnte, long64> sieve(w_size_approx, w_first_approx, AUTO_SIEVE);
  sieve.show(sieve.bit_size);
  //sieve.display(sieve.bit_size);
  //sieve.init_counters();
  cout << "sieve_bit_size-1= " << sieve.bit_size-1 << endl;
  cout << "Reste " << sieve.count(sieve.bit_size - 1) << "\n";
  long res = sieve.count(x);
  sieve.display(sieve.bit_size);
  sieve.show();
  cout << "x = " << x << "    Compte de x = " << res << endl;
  sieve.display_starts();
  sieve.display(sieve.bit_size);
  exit(0);
}
