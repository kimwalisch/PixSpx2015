// -*- C++ -*-
#ifndef index_first_bg_h
#define index_first_bg_h

template<class T> long32 first_bg_than(T x, T* tab, long32 dim) {
  long32 first = 1;
  long32 last  = dim+1;
  //cout << "x   = " << x << endl;

  if (x < tab[first])
    return first;

  while (first+1 < last)
    {
      long32 middle = first + (last-first)/2;
      //cout << first<< "   " << middle << "  " << last << endl;
      //cout << tab[first] << "   " << tab[middle] << "  " << tab[last] << endl;
      if (tab[middle] > x)
        last = middle;
      else first = middle;     
    }
  //  cout << last << "  will be returned " << endl;
  return last;
}

#endif


