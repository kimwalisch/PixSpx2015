#include<mylib.h>
#include"../Include/bit_table_dynamic.h"
inline long32  
maxpow2(long32 x)
{
  for (long32 z = x; z ^= ( z & -z); x = z);
  return x;
}


void 
bit_table_dynamic::create(long32 n)
{
  bit_table::create(n);
  long32 m = get_word_size();
  BASE = maxpow2(m);
  if (BASE < m) BASE += BASE;
  number_of_sums = BASE + BASE;
  partial_sums_array = new  long32[number_of_sums];
  if ( partial_sums_array == NULL)
    {
      cout << "Not enough memory for partial_sums_array\n";
      error();
    }
  bit_table_dynamic::fill();
}

void
bit_table_dynamic::display(int n) const
{
  if ((n > bit_size) || (!n)) {
    n = bit_size;
  }
  cout << "b.t.dynamyc display" << endl;   
  bit_table::display(n);
  cout << "Les comptes :\n";
  for ( long32 i = 0 ; i < n ; i++)
    {
      cout.width(4);
      cout << count(i);
    }
  cout << "\n";
}


void 
bit_table_dynamic::fill()
{
  long32 m = BASE, weight = WORDSIZE;
  while (m) {
    for (long32 i = m; i < m+m; i++) {
      partial_sums_array[i] = weight;
      //cout << "i= " << i << "     partial sum array[i] = " << partial_sums_array[i] << endl;
    }
    m = m>>1;
    weight <<= 1;
  }
  bit_table::fill();
}

void 
bit_table_dynamic::unset_bit(long32 x)
{
  if ((x <= get_bit_size()) && (get_bit(x)))
    {
      bit_table::unset_bit(x);
      long32 i = BASE + get_word_index(x);
      do  partial_sums_array[i]--; while (i >>= 1);
    }
}

long32
bit_table_dynamic::count(long32 x) const
{
  long32 bits_at_right = number_bit(get_word(x) & 
					 ~(get_bit_mask2(x)-1));
  long32 i = BASE + get_word_index(x) ;
  do 
    if (i % 2 == 0) bits_at_right += partial_sums_array[i+1];
  while ((i >>= 1) >= 2);
  return partial_sums_array[1] - bits_at_right;
}

bit_table_dynamic::~bit_table_dynamic()
{
#ifdef DEBUG_SV
  cout << "~bit_table_dynamic: suppression of partial_sums_array " << number_of_sums << " 64-bit words deleted\n";
#endif
  delete [] partial_sums_array;
  //delete_words_array();
}

