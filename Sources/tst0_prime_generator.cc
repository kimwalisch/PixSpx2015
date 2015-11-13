#include<mylib.h>
#include<cmath>
#include"prime_generator.h"
#include<iostream>


int main(int argc, char* argv[]) {

  long64 boundp= (argc>=2)? atolong128(argv[1]) : 1000000;

  long64 wsize = (argc>=3)? atol(argv[2]) : 2 * sqrt(double(boundp)); 

  int how_many = (argc>=4)? atol(argv[3]) : 10;
  
  cout << "boundp = " << boundp << endl;

  presieved_primes::init_prime_table(boundp,2);
  presieved_primes::display();

  prime_generator pg(wsize, presieved_primes::max_prime());
  pg.display();

  long64 p;
  for (int n=1; n <= how_many; n++) {
    p=pg.next_prime(); 
    cout << "n= " << n << "  p=  " << p << endl;
  }
  cout << "ok" << endl;
  return 0;
}
