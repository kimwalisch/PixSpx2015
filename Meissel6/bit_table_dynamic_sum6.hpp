#ifndef bit_table_dynamic_sum6_hpp
#define bit_table_dynamic_sum6_hpp
#include<mylib.h>
#include "bit_table_dynamic_sum6.h"

bit_table_dynamic_sum6::bit_table_dynamic_sum6(long window_size, int psb, int nbp):
  sieve_by_slice(k, l, window_size, 0, psb, NO_SIEVE) {
  cout << "bit_table_dynamic_sum6 initalized. Table count is to be done\n";
  cout << "bit_size= " << bit_table::get_bit_size() << endl;
  previous_totals= new long128[nbp];
  BASE=1;
  while (BASE < bit_table::get_bit_size())
    BASE *= 2;
  local_sums= new long[BASE];
  int i;
  int j=BASE/2;
  //cout << " remplissage de la première ligne, j= " << j << endl;
  local_sums[0]=0;
  for (i=0; i < get_bit_size()-1;  i+=2) {
    //cout << "j= " << j <<  " recoit  " << get_integer(i) + get_integer(i+1) << endl;
    local_sums[j++]= get_integer(i) + get_integer(i+1);
  }
  //cout << "Enfin j = " << j <<  " recoit  " << get_integer(get_bit_size()-1) << endl;
  local_sums[j++] = get_integer(get_bit_size()-1);
  // puis que des 0
  while (j < BASE) 
    local_sums[j++]=0;

  int m = BASE>>2;
  while (m) {
    cout << "m=  " << m << endl;
    for (j = m; j  < m+m; j++) {
      local_sums[j]  = local_sums[2*j];
      local_sums[j] += local_sums[2*j+1];
      cout << "     j= " << j << "   recoit " << local_sums[2*j] + local_sums[2*j+1] << endl;
    }
    m = m>>1;
  }
  cout << "Sums are " << endl;
  show_sums();
}

void bit_table_dynamic_sum6::show_sums() {
  cout << "BASE= " << BASE << endl;
  cout << "get_bit_size()= " << get_bit_size() << endl;

  for (int j=1; j < BASE; j++) {
    cout << local_sums[j];
    cout << " " ;
    }
  cout << endl;
}

long bit_table_dynamic_sum6::local_count(int offset)
{
  long som=local_sums[1];
  if (offset==get_bit_size()-1)
    return som;
  if (offset==get_bit_size()-2)
    return som-get_integer(get_bit_size()-1);
  
  if (offset %2 == 0) {
    som -= get_integer(offset+1);
  }
  
  int i=(offset+BASE)/2;
  while (i > 0) {
    if ((i % 2) == 0) {
      som -= local_sums[i+1];
    }
    i /= 2;
  }
  return som;
}




#endif
