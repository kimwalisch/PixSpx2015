#include<mylib.h>
#include<meissel_global.h>
#define P2XY_VERBOSE 0

long128
sum_p2xy() {
  long128 Sqp=0;
  long128 Sfp=0;
  long128 p2xy=0;

  if (meissel::verbose) {
    cout << "CALCUL DE SUMP2(x,y)\n\n";
    cout.flush();
    }
  long main_sieve_size = next_mult(2*meissel::y,primes::presieve_base);
  long aux_sieve_size = next_mult(meissel::y/3,primes::presieve_base);
  sieve_by_slice<bit_table,long64> aux_sieve(2,1,aux_sieve_size,0,primes::presieve_base,AUTO_SIEVE);
  sieve_by_slice<bit_table,long64> main_sieve(2,1,main_sieve_size,0,primes::presieve_base,AUTO_SIEVE);
  
  long64 p = aux_sieve.get_next_prime();
  while (p <= meissel::sqr2_x)
    {
      Sfp += p; // f=Id
      p = aux_sieve.get_next_prime();
    }
#if P2XY_VERBOSE > 0      
  cerr << "Somme des f(p) jusqu'a sqrt(x) = " << Sfp << "\n";
#endif
  while (p > meissel::sqr2_x)
    p =  aux_sieve.get_previous_prime();
#if P2XY_VERBOSE > 0      
  cerr << "Dernier p avant sqrt(x) " << p << "\n";
#endif

  main_sieve.init_primes(p);
  main_sieve.eratosthenes();
#if P2XY_VERBOSE > 1 
  printf("Main sieve first window : \n");
  main_sieve.display();
#endif
  long64 q = main_sieve.get_next_prime();
  while (p > meissel::y) {
    long64 xp = meissel::x/p;
#if P2XY_VERBOSE > 2
    cerr << "pm = " << p << "  -> meissel::x/p = " << xp << "\n";
    cerr << "Sfp = " << Sfp << "\n";
#endif
    while(q <= xp)
      {
#if P2XY_VERBOSE > 2
	cerr << "q = " << q << "\n";
#endif
	Sqp += q; // f=Id
	q = main_sieve.get_next_prime();
      }
#if P2XY_VERBOSE > 1 
      cerr << "q  = " << q << "    Sqp = " << Sqp << "\n";
#endif
    Sfp -= p;// f=Id
    p2xy += p * (Sqp-Sfp);
    p = aux_sieve.get_previous_prime();
  }
  cout << "Before living p2 Premier 9 = primes::prime(9)= " << primes::prime(9) << endl;
  return p2xy;
}
