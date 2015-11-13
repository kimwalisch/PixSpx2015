#include<mylib.h>
#include"../Include/sieve_slices.h"

int main(int argc, char* argv[]) {
  long32 wsize = (argc==2)? atoi(argv[1]) : 100;
  presieved_primes::init_prime_table(1000,3);

  cout << "Sieve par tranche avec crible d'Eratosthène automatique\n";
  sieve_by_slice<bit_table,long64> sl(2,1,wsize,0,6, AUTO_SIEVE);

  for (int n=0; n < 3; n++) {
    sl.display();
    cout << "Shift_forward\n";
    sl.shift_window_forward();
  }
  cout << "ok" << endl;
  return 0;
}
