#include<mylib.h>
#include<vector>
#include<bit_table_cnte.h>

void 
bit_table_cnte::create(long n)
{
  bit_table::create(n);
  //counter_array = new long[get_word_size()];
  counter_array.resize(get_word_size(),0);
}

int
bit_table_cnte::init_counters()
{
  //cout << "Bit table_cnte Init counters word_size= " << get_word_size() << "\n";
  counter_array[0] = number_bit(get_nth_word(0));
  //cout << "counter_array[0] = " <<  counter_array[0] << endl;
  for ( long i = 1 ; i < get_word_size(); i++)
    {
      counter_array[i] = counter_array[i-1] + number_bit(get_nth_word(i));
      //cout << "counter_array[" << i << "] = " << counter_array[i] << endl; 
    }
  return 1;
}

void
bit_table_cnte::display(long n) const{
  cout << "bit_table_cnte:: display bit_size =" << bit_size << endl;
  //#ifdef DEBUG_SV
  bit_table::display(n);
  cout << "Les comptes :\n";
  cout << "bit_size= " << bit_size << endl;
  for ( long i = 0 ; i < bit_size ; i++)
    {
      cout.width(4);
      cout << count(i);
    }
  cout << "\n";
  //#endif
}

/*
bit_table_cnte::~bit_table_cnte()
{
  //#ifdef DEBUG_SV
  cout << "~bit_table_cnte_delete: suppression of " << word_size << " 32-bits integers\n";
  //#endif
  delete [] counter_array;
}
*/

