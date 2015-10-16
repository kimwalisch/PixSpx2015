#include"../Include/interval_sieve.h"

template<class btable, class longint>
void interval_sieve<btable,longint>::eratos() {
  cout << "Eratos is to be done" << endl;
}


template<class btable, class longint>
void interval_sieve<btable,longint>::display(long how_many) {
  cout << "interval_sieve::display:  [" << first << ", " << last << "]\n";
#ifdef DEBUG_SV
  cout << "sieve_by_slice::window_start: " <<  sieve_by_slice<btable,longint>::window_start << endl;
  cout << "sieve_by_slice::window_last: " <<  sieve_by_slice<btable,longint>::window_last << endl;
#endif
  for (int i=first_index; i <= min(first_index+how_many-1,last_index); i++) {
    //cout<< "i= " << i << " bit = " << btable::get_bit(i) << endl;
    if (btable::get_bit(i))
      cout << sieve_by_slice<btable,longint>::get_integer(i) << " " << endl;
  }
    cout << endl;
}

