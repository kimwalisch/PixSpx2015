#include<sieve_sum_dynamic.h>

template<class btable, class longint> 
sieve_sum_dynamic<btable, longint>::sieve_sum_dynamic(long wsize , long64 end, int pmax):
  sieve_by_slice<btable, longint>(wsize, 0, NO_SIEVE)
{
  //cout << "D'abord la bit table " << endl;
  //bit_table::display();

  BASE=1;
  while (BASE < bit_table::get_bit_size())
    BASE *= 2;
  cout << "Creation bit_sum_dynamic de taille " << wsize << "     Base= " << BASE << endl;

  partial_sums_array = new long[BASE];
  int i;
  int j=BASE/2;
  //cout << " remplissage de la première ligne, j= " << j << endl;
  partial_sums_array[0]=0;
  for (i=0; i+1 < bit_table::get_bit_size();  i+=2) {
    partial_sums_array[j++]= get_integer(i) + get_integer(i+1);
  }
  partial_sums_array[j++]= get_integer(i);
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

template<class btable, class longint> 
void sieve_sum_dynamic<btable, longint>::display() {
  cout << "Les images: ";
  for ( int i = 0 ; i < bit_table::get_bit_size() ; i++)
    {
      cout.width(4);
      if (bit_table::get_bit(i))
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
