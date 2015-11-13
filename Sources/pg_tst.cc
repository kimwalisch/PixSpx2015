#include<mylib.h>


int main(int argc, char* argv[]) {
  primes::init_prime_table(100000);
  long pmax= (argc==1)?  995: atol(argv[1]);
  cout << "Primes done \n";
  
  //primes6::display()
  prime_generator pg(1000,pmax);
  pg.display();
  long p = pg.next_prime();
  cout << "in= " << pmax << "   -> p= " << p << endl;
  return 0;
  }
