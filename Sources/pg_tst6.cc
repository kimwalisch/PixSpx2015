#include<mylib.h>

int main(int argc, char* argv[]) {
  primes6::init_primes(100000);
  long pmax= (argc==1)? 995 : atol(argv[1]);
  cout << "Primes done \n";
  
  //primes6::display()
  prime_generator6 pg(5000000,pmax);
  long p = pg.next_prime();
  cout << "in= " << pmax << "   -> p= " << p << endl;
  return 0;
  }
