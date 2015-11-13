#include<mylib.h>
#include"../Include/sieve_slices.h"

int main(int argc, char* argv[]) {
  long32 n = (argc==2)? atoi(argv[1]) : 100;
  int nbps=3;
  presieved_primes::init_prime_table(1000000,nbps);
  //presieved_primes::display();
  
  sieve_by_slice<bit_table_cnte,long64> sl(2,1,n,0,30, AUTO_SIEVE);

  sl.display();
  sl.shift_window_forward();
  sl.display();
  sl.display_counts();

  long64 wend= sl.get_window_end();
  cout << "Window_end= " << wend << endl;
  long64 cnte_wend  =sl.count(sl.get_window_end());
  cout << "Count(" << wend << ") = " <<  cnte_wend << endl;
  if (cnte_wend!= 52-nbps)
    {
      cout << "Erreur: ce nombre devrait être égal à " << presieved_primes::number_of_presieve_primes << endl;
  }
  cout << "ok" << endl;
  return 0;
}
