#ifndef orders_h
#define orders_h

template<class T> long32 
index_of_first_bigger_than(vector<T> vect, T v, int (*comp)(T,T))
{
  long32 first = 0;
  long32 last  = vect.size();

  if (comp(v, vect[first]) < 0)
    return first;

  while (first+1 < last)
    {
      long32 middle = first + (last-first)/2;  
      if (comp(vect[middle], v) > 0)
        last = middle;
      else first = middle;     
    }
  return last;
}

template<class T> void displayv(T vect, int w=2)
{
  for (long32 i = 0; i < vect.size(); i++ )
  {
    cout << vect[i];
    for (long32 j = 0; j < w; j++) cout << " ";  // FIXME!
  }
  cout << "\n";
  cout.flush();
}

// non-recursive quicksort using insertion sort when lenght <= 8
template<class T> void quick_sort(vector<T> vect, int (*comp)(T,T))
{
  long32 start = 0;
  long32 end = vect.size()-1 - 1;
  long32 k = 0;
  long32 stack[60];
  int top = 2;
  
  do
    {
      if (end-start <= 8)
	{
	  insertion_sort0(comp, start, end);
	  end = stack[--top];
	  start = stack[--top];
	}
      else
	{
	  k = best_index(start, end, comp);
	  // k = start;
	  k = partition_wrt(comp, k, start, end);
	  if ((k-start) > (end-k))
	    {
	      stack[top++] = start;
	      stack[top++] = k-1;
	      start = k+1; 
	    }
	  else
	    {
	      stack[top++] = k+1;
	      stack[top++] = end;
	      end = k-1;
	    }
	}
    }
  while (top);
}


#endif
