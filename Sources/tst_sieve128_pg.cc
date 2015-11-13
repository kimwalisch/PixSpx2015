// -*- C++ -*-
#include<mylib.h>
#include<math.h>

int main(int argc, char* argv[]) {
  if (argc==1) {
    cout << "ok argc=1\n";
    return 0;
    }
  long128 x  =  atolong128(argv[1]);
  long64  wsz  =  atolong64(argv[2]);
  
  
  presieved_primes::init_prime_table(500000);
  presieved_primes::display();


 sieve128pg sieve(wsz,x);
 sieve.display();
 
 sieve.eratos();
 for (int i=0; i < 100; i++)
   if (sieve.get_bit(i))
     cout << "i= " << i << "  ->  " << sieve.get_integer(i) << endl;
 
 cout << "ok" << endl;
 return 0;
}
