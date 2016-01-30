#include<stdlib.h>
#include<iostream>
#include<gmp.h>

using namespace std;


long next_prime(long p) {
  mpz_t P,P1;
  mpz_init(P1);
  mpz_init_set_si(P,p);
  mpz_nextprime(P1,P);
  if (mpz_fits_slong_p(P1)) {
    long res = mpz_get_si(P1);
    mpz_clear(P);
    mpz_clear(P1);
    return res;
  }
  else {
    cout << "P1 is bigger to fit in long\n";
    exit(0);
  }
}

int is_prime(long p) {
  mpz_t P;
  int ok;
  mpz_init_set_si(P,p);
  ok = mpz_probab_prime_p(P,25);
  mpz_clear(P);
  return ok;
}

long previous_prime(long p) {
  if (p <= 3) {
    cout << "Previous prime p trop petit" << endl;
    exit(0);
  }
  p=p-1;
  while (!is_prime(p))
    p--;
  return p;
}
