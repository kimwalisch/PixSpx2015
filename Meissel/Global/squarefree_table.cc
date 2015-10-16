#include<mylib.h>
#include<meissel_global.h>


static long32 dim;
static long32 cnt = 0;
static vector<long32>  buff;

void
squarefree_table_recursive_step(long32 u, long32 i)
{
  long32 j = i;
  long32 v;
  long32 zu = min32(abs(meissel::z/u),meissel::y);

  while (primes::prime(j) <= zu)
    {
      v = -(long32)primes::prime(j++)*u;
      //cout << "primes::prime(j)= " << primes::prime(j) << endl;
      //cout << "v= " << v << endl;
      buff[cnt++] = v;
      squarefree_table_recursive_step(v, j);
    }
} 

bool comp_abs(int i, int j) {
  return abs(i) < abs(j);
}
  

void 
squarefree_table_p_init(long32 i)
{
  buff[0] = -(long32)primes::prime(i);
  cnt = 1;
  squarefree_table_recursive_step(-(long32)primes::prime(i), i+1);
  meissel::p_sqf[i].resize(cnt+1);
  for (long32 j = 0; j < cnt; j++)
    meissel::p_sqf[i][j] = buff[j];
  meissel::p_sqf[i][cnt] = LONG32_MAX;
  //  std::sort(meissel::p_sqf[i].begin(), meissel::p_sqf[i].end(), compare_abs_long32);
  std::sort(meissel::p_sqf[i].begin(), meissel::p_sqf[i].end(), comp_abs);
}

void 
squarefree_table_init() 
{
  dim = meissel::z/2;
  buff.resize(dim);

  meissel::p_sqf.resize(1+meissel::pi_sqr2_z);

  for (long32 i = 1; i <= meissel::pi_sqr2_z; i++)
    {
      squarefree_table_p_init(i);
 #ifdef DEBUG_SQF
      cout << "Square-free list by smallest prime factor = " 
	   << primes::prime(i) << "\n";
      meissel::p_sqf[i].display(8);
#endif
#ifdef DEBUG_SAFE
      for (long32 j = 1 ;j < meissel::p_sqf[i].get_dim() ; j++)
	{
	  if (abs32(meissel::p_sqf[i][j]) < abs32( meissel::p_sqf[i][j-1]))
	    {
	      cout << "The square-free list is not sorted for i = " 
		   << i << "\n";
	      error();
	    }
	}
#endif
    }
}


