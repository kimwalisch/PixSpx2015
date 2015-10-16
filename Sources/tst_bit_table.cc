#include<mylib.h>
#include"bit_table.h"

int main(int argc, char* argv[]) {
  long lng= (argc==2)? atol(argv[1]) : 100;
  bit_table t(lng);
  //t.display();
  cout << "\n\nSuppression de 0,2,4,6,8,10,11,12\n\n\n";
  t.unset_bit(0);
  t.unset_bit(2);
  t.unset_bit(4);
  t.unset_bit(6);
  t.unset_bit(8);
  t.unset_bit(10);
  t.unset_bit(11);
  t.unset_bit(12);
  //t.display();

  cout << "t.get_bit_size()= " << t.get_bit_size() << endl;

  cout << "Quelques valeurs de t.get(i)\n";
  for (int i=0; i<=10; i++)
    cout << "get_bit(" << i << ")= " << t.get_bit(i)  << endl;
  cout << "get_bit(" << 98 << ")= " << t.get_bit(98)  << endl;
  cout << "get_bit(" << 99 << ")= " << t.get_bit(99)  << endl;

  // test if ok
  long cnte=0;
  for (long i=0; i < lng; i++)
    if (t.get_bit(i))
      cnte++;

  cout << "Le nombre de bits restant dans la table est " << cnte << endl;
  if (cnte  != t.get_bit_size() - 8) {
    cout << "Erreur: ce nombre devrait être égal à " << t.get_bit_size() - 8 << endl;
    exit(1);
  }
  cout << "ok" << endl;
  return 0;
}
