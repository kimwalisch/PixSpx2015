#include<mylib.h>

namespace presieved_primes{
  long32 presieve_base;
  long32 number_of_presieve_primes;
  long32 sum_of_presieve_primes;
  long32 small_primes[5] = {2, 3, 5, 7, 11};
  int primes_initialized = 0;
  long* Sp;

  void init_presieve(int nbps) {
    switch (nbps) {
    case 2:
      presieve_base = 6;
      number_of_presieve_primes = 2;
      sum_of_presieve_primes = 5;
      number_of_presieve_primes = 2;
      break;
      
    case 3:
      presieve_base = 30;
      number_of_presieve_primes = 3;
      sum_of_presieve_primes = 10;
      number_of_presieve_primes = 3;
      break;
      
    case 4:
      presieve_base = 210;
      number_of_presieve_primes = 4;
      sum_of_presieve_primes = 17;
      number_of_presieve_primes = 4;
      break;
      
    case 5:
      presieve_base = 2310;
      number_of_presieve_primes = 5;
      sum_of_presieve_primes = 28;
      number_of_presieve_primes = 5;
      break;
    }
  }
    prime_table<sieve_by_slice<bit_table_cnte, long> > T;

    long32
      prime(long32 i) { return T.prime(i);}
    
    long32
      piB(long32 i) { return T.piB(i); }
    
    long32
      number_of_primes() { return T.get_number_of_primes(); }
    
    long32
      max_prime() {return prime(T.get_number_of_primes());}
    
    long32 
      index_of_first_prime_bigger_than(long32 x) 
    {
      return T.index_of_first_prime_bigger_than(x);
    }
    
    void   
      init_prime_table(long32 upto, int nbps)
    {
      if (nbps > 5) {
	cout << "init_prime_table error called with upto = " << upto << " and nbps = " << nbps << endl\
	     << "nbps, the number_of_presieved primes must be less or equal to 5\n";
	error();
      }
      init_presieve(nbps);
      //cout << "init_prime_table : presieve_base set to " << presieved_primes::presieve_base << endl;
      T.create(upto, presieved_primes::presieve_base);
      primes_initialized = 1;
#ifdef DEBUG_PRIMES
      cout << "\nprime_table::is_created first non presieved prime = " << presieved_primes::prime(1) << endl;;
      cout << "presieved_primes::number_of_primes() = " << presieved_primes::number_of_primes() << endl;
      cout << "presieved_primes::max_prime() = " << presieved_primes::max_prime() << endl << endl;
#endif
    }
    
    void display() {
      cout << "\nPrime_table created\n";
      cout << "    number of presieved primes  = " << presieved_primes::number_of_presieve_primes << endl;
      cout << "    first non presieved prime   = " << presieved_primes::prime(1) << endl;;
      cout << "    presieved_primes::number_of_primes()  = " << presieved_primes::number_of_primes() << endl;
      cout << "    presieved_primes::max_prime()         = " << presieved_primes::max_prime() << endl << endl;
    }
    
    void
      display_prime_table() { T.display();}

  void init_sum_primes() {
    Sp= new long[1+number_of_primes()];
    long sum=0;
    for (int i=1; i <= number_of_primes(); i++) {
      sum+=T.prime(i);
      Sp[i]=sum;
    }
  }
}
  
  
