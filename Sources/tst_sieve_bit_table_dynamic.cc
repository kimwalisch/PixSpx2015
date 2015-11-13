#include<mylib.h>


int main(int argc, char* argv[]) {
  //  long32 n = (argc==2)? atoi(argv[1]) : 100;
  long32 wsize = 100;
  presieved_primes::init_prime_table(100000,3);
  
  sieve_by_slice<bit_table_dynamic,long64> sl(2,1,wsize,0,6, NO_SIEVE);
  sl.display();
  sl.display_counts();
  sl.sieve_by(5);
  cout << "Apres sieve by 5\n\n";
  sl.display();
  sl.display_counts();
  cout << "\n\n";
  sl.shift_window_forward();
  sl.display();
  sl.display_counts();

  long64 end = sl.get_window_end();
  int cnte=sl.count(end);
  cout << "Le nombre de bits restant dans la table est " << cnte << endl;

  if (cnte  != 34) {
    cout << "Erreur: ce nombre devrait être égal à " << 0 << endl;
    exit(1);
  }
  cout << "ok" << endl;
  return 0;

}
