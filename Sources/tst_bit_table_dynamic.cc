#include<mylib.h>
#include"../Include/bit_table_dynamic.h"

int main(int argc, char* argv[]) {
  long32 lng= (argc==2)? lng=atoi(argv[1]) : 100;
  cout << "lng = " << lng << endl;
  bit_table_dynamic t(lng);
  t.display();
  t.unset_bit(0);
  t.unset_bit(1);
  t.unset_bit(2);
  t.unset_bit(50);
  t.unset_bit(51);
  t.unset_bit(52);
  t.unset_bit(53);
  cout << "\n\nApres suppressions de 0,1,2,50,52,52,53 \n\n\n";
  t.display();

  int cnte=t.count(lng-1);
  cout << "Le nombre de bits restant dans la table est " << cnte << endl;

  if (cnte  != t.get_bit_size() - 7) {
    cout << "Erreur: ce nombre devrait être égal à " << t.get_bit_size() - 7 << endl;
    exit(1);
  }
  cout << "ok" << endl;
  return 0;

}
