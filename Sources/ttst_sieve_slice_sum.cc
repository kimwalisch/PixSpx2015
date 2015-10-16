#include<mylib.h>
#include"../Include/sieve_slices_sum.h"

int main() {
  primes::init_prime_table(10000,2);
  sieve_slice_sum sieve(2, 1, 1002, 0, primes::presieve_base);
  sieve.display();
  sieve.shift_window_forward();
  sieve.display();
}
