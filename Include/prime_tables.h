// -*- C++ -*-
#ifndef prime_tables_h 
#define prime_tables_h
#include<orders.h>

template<class sieve_class> class prime_table : public sieve_class
{
  vector<long32> p_table;
public:
  void display() const; 
  prime_table() {};
  prime_table(long32 upto, long32 B);
  void create(long32 upto, long32 B);
  inline long32 piB(long32 x);
  long32 prime(long32 i) { return p_table[i];}
  void display();
  long32 get_number_of_primes() {
    return p_table.size() - 2;
  }
  long32 last_prime() {
    return prime(get_number_of_primes());
  }
  long32 max_prime() {
    return prime(get_number_of_primes()); 
  }
  long32 first_prime() {
    return prime(1);
  }
  long32 index_of_first_prime_bigger_than(long32);
};



template<class sieve_class> prime_table<sieve_class>::prime_table(long32 upto, long32 B)
{
  create(upto, B);
}

template<class sieve_class> inline long32 prime_table<sieve_class>::piB(long32 x) {
#ifdef DEBUG_PRIMES
  if (!sieve_class::belong_to_window(x)) {
    cout << "\n Error in prime_table::piB\n   x= " << x << " does not belong to current window = ["\
	 << sieve_class::window_start << ", " << sieve_class::window_start+sieve_class::window_size-1 << "]\n";
    error();
  }
#endif
  return (long32)sieve_class::count((long64)x);
}

template<class sieve_class> void prime_table<sieve_class>::create(long32 upto, long32 B)
{
  long32 count_primes = 0;
  sieve_class::create(2, 1, upto, 0, B, NO_SIEVE);

  sieve_class::unset_bit(0);
  sieve_class::unset_bit(1);
  long32 j = 2;
  long32 p = (long32)sieve_class::get_integer(j);
  while ( p <= sieve_class::get_window_size()/p) 
    {
#if DEBUG_PRIMES
      cout << "prime_table::sieve by p= " << p << " will be done\n";
#endif
      sieve_class::sieve_by(p);
      sieve_class::set_bit((long32)sieve_class::lower_index64(p));
      while (!sieve_class::get_bit(++j)); 
      p =  (long32)sieve_class::get_integer(j);
    }

  int more = 1;
  for (j = 2 ; (j < sieve_class::get_bit_size()) && more; j++)
    if (sieve_class::get_bit(j)) 
      {	  
	long32 x = (long32)sieve_class::get_integer(j);
	if (x <= upto) {
	  count_primes++;
	  //cout << "new prime x= " << x << "   count_primes= " << count_primes << endl;
	}
	else more = 0;
      }
  sieve_class::init_counters();
  p_table.resize(count_primes+2);
  p_table[0]=1;
  long32 s = 1;
  for (j = 2 ; s <= count_primes; j++)
    {
      if (sieve_class::get_bit(j)) {
	p_table[s++] = (long32)sieve_class::get_integer(j);
      }
      }
  p_table[count_primes+1] = LONG32_MAX;
  //sieve_class::delete_words_array(); // words_array now useless (if not needed by count)
  //#ifdef DEBUG_PRIMES
  cout << "\nPrimes_table done, number_of_primes = " << count_primes << "\n";
  //#endif
}

template<class sieve_class> void prime_table<sieve_class>::display()
{
  cout << "sieve_prime_table::<sieve_class>   display\n";
  //cout << "Prime table contains:\n";
  //p_table.display(8);
} 

template<class sieve_class>  
long32 prime_table<sieve_class>::index_of_first_prime_bigger_than(long32 x)
{
  return (long32)index_of_first_bigger_than<long32>(p_table, x, compare_long32);
}

#endif
