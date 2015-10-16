#include<mylib.h>
#include"bit_table_cnte.h"

int main(int argc, char* argv[]) {
  long lng= (argc==2)? atol(argv[1]) : 100;
  cout << "lng= " << lng << endl;
  bit_table_cnte t(lng);
  t.init_counters();
  t.display();
  cout << "\n\nSuppression de 0,1,2,51,52,52,53 \n\n\n";
  t.unset_bit(0);
  t.unset_bit(1);
  t.unset_bit(2);
  t.unset_bit(50);
  t.unset_bit(51);
  t.unset_bit(52);
  t.unset_bit(53);
  cout << "Apres Suppression\n";
  t.init_counters();
  t.display();

  long cnte=t.count(lng-1);
  cout << "Le nombre de bits restant dans la table est " << cnte << endl;

  if (cnte  != t.get_bit_size() - 7) {
    cout << "Erreur: ce nombre devrait être égal à " << t.get_bit_size() - 7 << endl;
    exit(1);
  }
  cout << "ok" << endl;
  return 0;
}
