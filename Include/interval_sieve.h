#ifndef interval_sieve_h
#define interval_sieve_h
#include"mylib.h"

template<class btable, typename longint> class interval_sieve:
  public sieve_by_slice<btable, longint> {
public:
  longint first;
  longint last;
  interval_sieve(longint a, longint b);
  void display(long how_many=0);
  void eratos();
private:
  long first_index;  // index of first in the bit_table.
  long last_index;  // index of last in the bit_table. 
  
};



template<class btable, class longint>
interval_sieve<btable,longint>::interval_sieve(longint a, longint b):
  sieve_by_slice<btable,longint>\
  (2,1,next_mult<longint>(b,6)-prev_mult<longint>(a,6),prev_mult<longint>(a,6), 6, NO_SIEVE)
{
  this->first=a;
  this->last=b;
  //cout << "sieve_by_slice::window_start: " <<  sieve_by_slice<btable,longint>::window_start << endl;
  //cout << "sieve_by_slice::window_last: " <<  sieve_by_slice<btable,longint>::window_last << endl;
  first_index = access_frame::lower_index64(first - sieve_by_slice<btable,longint>::window_start);
  if (sieve_by_slice<btable,longint>::get_integer(first_index) < a)
    {
      btable::unset_bit(first_index);
      first_index++;
    }
  for (int i=0; i < first_index; i++) {
    btable::unset_bit(i);
  }
  last_index = access_frame::lower_index64(last - sieve_by_slice<btable,longint>::window_start);
  //cout << sieve_by_slice<btable,longint>::get_integer(last_index) << "zzz\n";
  //  if (sieve_by_slice<btable,longint>::get_integer(first_index) < a)
}

#include"./interval_sieve.hpp"
#endif
