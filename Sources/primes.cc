#include<mylib.h>

namespace primes{

  int* table_p;
  int nb_primes;
  int largest_prime;
  
  //prime_table<sieve_by_slice<bit_table_cnte, long> > T;
  sieve_slice6<bit_table_cnte, long64> p_tab;
    
  void init_primes(int upto) {
    long true_bound = next_mult6(upto);
    long size = true_bound;
  
    p_tab.create(size,0, NO_SIEVE);
    p_tab.unset_bit(0);
    p_tab.unset_bit(1);
    
    int p  = 5;
    while (p <= upto/p)  {
      p_tab.sieve_by(p);
      //p_tab.set_long(p); // Reinstaller le premier supprime par le crible
      p_tab.set_bit(offset(p));
      int ip=1+offset(p);
      while (! p_tab.get_bit(ip))
	ip++;
      p=get_integer(ip);
    }
    p_tab.init_counters();
    long cnte = 2+p_tab.count(upto);
    table_p = new int[cnte+2];
    table_p[0] = 1;
    table_p[1] = 2;
    table_p[2] = 3;
    int j=2;
    for (int i=0; i < p_tab.get_bit_size(); i++) {
      if (p_tab.get_bit(i)) 
	table_p[++j]=get_integer(i);
    }
    nb_primes = cnte;
    largest_prime = table_p[cnte];
    table_p[cnte+1] = LONG32_MAX;
  }

  int number_of_primes() {
    return nb_primes;
  };

  
  int max_prime() {
    return table_p[nb_primes];
  }

  int prime(int i) {
    return table_p[i];
  }
  
}
  
  
