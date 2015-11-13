#include<iostream>
#include<sieve_slice6.h>

using namespace std;

namespace primes_6{

  int* ip_table;
  int nb_primes = 0;
  long32 largest_prime = 0;
  long* Sp;
  sieve_slice6<bit_table_cnte, long64> p_tab;
  
  
  void init_primes(long upto) {
    long true_bound = next_mult6(upto);
    cout << "init_primes upto= " << upto << "   true_bound= " << true_bound << endl;
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
    long cnte = p_tab.count(upto);
    int j=0;
    ip_table = new int[cnte+2];
    ip_table[0] = 1;
    for (int i=0; i < p_tab.get_bit_size(); i++) {
      if (p_tab.get_bit(i)) 
	ip_table[++j]=get_integer(i);
    }
    nb_primes = cnte;
    largest_prime = ip_table[cnte];
    ip_table[cnte+1] = LONG32_MAX;
  }
  
  long32 max_prime() {
    return largest_prime;
    }

  long32 number_of_primes() {
    return nb_primes;
    }
  
  long32 piB(long32 u) {
    return p_tab.count(u);
  }

  long32 prime(int i) {
    return ip_table[i];
  }
  
  long32 index_of_first_prime_bigger_than(long x) {
    return first_bg_than<int>(x, ip_table, nb_primes);
  }    

  void display() {

    cout << "nb_primes= " << number_of_primes() << endl;
    cout << "max_prime= " << max_prime() << endl;

    cout << "iptab[0] = " << ip_table[0] << endl;
    cout << "iptab[1] = " << ip_table[1] << endl << endl;
    cout << "piB(" << largest_prime << ")   = " << piB(largest_prime) << endl;
    cout << "iptab[" << piB(max_prime())   <<  "]   = " << ip_table[piB(max_prime())] << endl;
    cout << "iptab[" << 1+piB(max_prime()) <<  "]   = "  << ip_table[piB(max_prime())+1] << endl;
  }


  
  void init_sum_primes() {
    Sp= new long[1+number_of_primes()];
    long sum=0;
    for (int i=1; i <= number_of_primes(); i++) {
      sum+=ip_table[i];
      Sp[i]=sum;
    }
  }
}
  


