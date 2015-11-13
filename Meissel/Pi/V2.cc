#include<mylib.h>
long128 sumW1_W2();
long128 sumW3();
long128 sumW4();
long128 sumW5();

long128 sumV2() {
  long128 somme_V2= 0;
  somme_V2 += sumW1_W2();

  presieved_primes::init_sum_primes();
  somme_V2 += sumW3();

  somme_V2 += sumW4();

  somme_V2 += sumW5();

  return somme_V2;
}

