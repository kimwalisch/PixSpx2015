#include<mylib.h>

void
bit_table::display(long n) const
{
  cout << "bit_size:  " << bit_size  << "\n";
  cout << "word_size: " << word_size << "\n";
  if ((n > bit_size) || (!n)) 
    n = bit_size;
 
  for ( long i = 0 ; i < n ; i++)
    {
      cout.width(4);
      if (get_bit(i)) cout << 1 ;
      else cout << 0 ;
    }
  cout << "\n";
}

void 
bit_table::fill()
{
  for (long i = 0 ; i < word_size ; i++)	
    words_array[i] = ~0;
}

/*
bit_table::~bit_table()
{
  //#ifdef DEBUG_SV
      cout << "~bit_table: suppression of "  << word_size << " 64-bit words\n" ;
  //#endif
      //  delete [] words_array;
}
*/

void 
bit_table::create(long n)
{
#ifdef DEBUG_SV
  cout << "bit_table::bit_table(long n) with  n = " << n << "\n";
#endif
  last_cnte=0;
  bit_size = n;
  word_size  = 
    (n & WORDSIZE1)?   (n >> WORDSIZE2)  + 1 : n >> WORDSIZE2;
  /*
 words_array = new ulong[word_size];
  if ( words_array == NULL)
    {
      cout << "Not enough memory to initialize words_array\n";
      error();
    }
  */
  words_array.resize(word_size, 0);
  for (long i = 0; i < word_size; i++)
    words_array[i] = ~0;
}

