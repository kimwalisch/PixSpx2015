// -*- C++ -*-
#include<mylib.h>
#include<math.h>


void sieve128pg::create(long64 sz, long128 startx){
  sieve_128_btable::create(2,1,sz,startx,6,NO_SIEVE);
}

void sieve128pg::eratos() {
  double boundp = 1.1*sqrt(double(get_window_end()));
  cout << "In eratos: bound for sieving primes : " << boundp << endl;

  long prime_gen_size = min(boundp,10000000000.0);
  prime_generator prime_gen(prime_gen_size);
  prime_gen.display();
  long64 p=prime_gen.next_prime();
  while (p <= boundp) {
    sieve_by(p);
    p=prime_gen.next_prime();
    }
}
