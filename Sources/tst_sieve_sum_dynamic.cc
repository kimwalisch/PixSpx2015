#include<mylib.h>
#include<sieve_sum_dynamic.h>

int main(int argc, char* argv[]) {
  int ws= (argc > 1)? atoi(argv[1]) : 1000;
  sieve_sum_dynamic<bit_table, long> sieve(ws, 1000, 100);
  sieve.display();
}
