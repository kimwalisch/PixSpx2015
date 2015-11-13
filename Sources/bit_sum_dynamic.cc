#include<bit_sum_dynamic.h>

bit_sum_dynamic::bit_sum_dynamic(long sze): bit_table_cnte(sze)
{
  //cout << "D'abord la bit table " << endl;
  //bit_table::display();

  BASE=1;
  while (BASE < bit_table::get_bit_size())
    BASE *= 2;
  cout << "Creation bit_sum_dynamic de taille " << sze << "     Base= " << BASE << endl;

  partial_sums_array = new long[BASE];
  int i;
  int j=BASE/2;
  //cout << " remplissage de la première ligne, j= " << j << endl;
  partial_sums_array[0]=0;
  for (i=0; i < get_bit_size();  i+=2) {
    partial_sums_array[j++]= get_integer(i) + get_integer(i+1);
  }
  while (j < BASE) {
    partial_sums_array[j++]=0;
  }

  int m = BASE>>2;
  while (m) {
    for (j = m; j  < m+m; j++) {
      partial_sums_array[j]  = partial_sums_array[2*j];
      partial_sums_array[j] += partial_sums_array[2*j+1];
    }
    m = m>>1;
  }
}

bit_sum_dynamic::~bit_sum_dynamic()
{
  //#ifdef DEBUG_SV
  cout << "~bit_table_cnte_delete: suppression of " << word_size << " 32-bits integers\n";
  //#endif
  delete [] partial_sums_array;
}

long64 bit_sum_dynamic::sum(long i)
{
  long64 left_at_right = (i % 2) ? 0 : get_integer(i+1);
  i = (BASE + i) / 2;
  do {
    if (i % 2 == 0)
      left_at_right += partial_sums_array[i+1];
  }
  while ((i >>= 1) >= 2);
  return partial_sums_array[1] - left_at_right;
}



void bit_sum_dynamic::unset_bit(long i) {
  if (!get_bit(i))
    return;
  long ivalue = get_integer(i);
  bit_table_cnte::unset_bit(i);

  i = (BASE+i)/2;
  do {
    partial_sums_array[i] -= ivalue;
  }
  while ((i >>= 1) >= 1);
}

void bit_sum_dynamic::display() {
  cout << "Les images: ";
  for ( int i = 0 ; i < get_bit_size() ; i++)
    {
      cout.width(4);
      if (get_bit(i))
	cout << get_integer(i) ;
      else cout << 0 ;
    }
  cout << "\n";
    
  cout << "Sums are " << endl;
  long m= BASE>>1;
  while (m) {
    cout << "m= " << m << "   : ";
      for (int j = m; j < 2*m; j++)
	{
	  cout.width(4);
	  cout << partial_sums_array[j];
	}
    m /= 2;
    cout << "\n";
    }
}
