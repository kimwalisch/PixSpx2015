#include<mylib.h>
#include<bit_sum_dynamic.h>

int main(int argc, char* argv[]) {
  long32 lng= (argc==2)? lng=atoi(argv[1]) : 12;
  bit_sum_dynamic t(lng);
  t.display();
  t.unset_bit(6);
  t.display();
  t.unset_bit(3);
  t.display();
  t.unset_bit(1);
  t.unset_bit(2);
  t.unset_bit(4);
  t.unset_bit(5);
  t.unset_bit(7);
  t.unset_bit(8);
  t.unset_bit(9);
  t.unset_bit(10);
  t.unset_bit(11);
  t.display();
  return 0;
}

