#include<mylib.h>
#include<meissel_global.h>

namespace meissel{
  int number_of_presieve_primes=2;
  long128 x;
  long64  y;
  long64  z;
  long64  xy;
  long64  sqr2_x;
  long32  sqr3_x;
  long32  sqr4_x;
  long32  sqr2_z;
  long32  sqr2_x_y; // sqr2(x/y)
  long32  x_y2;
  long32  pi_y;
  long64  pi_sqr2_x;
  long32  pi_sqr3_x;
  long32  pi_sqr4_x;
  long32  pi_sqr2_z;
  long32  pi_sqr2_x_y;
  long32  pi_x_y2;
  long32  bound_for_good_primes;
  long32  ifgp;
  long    fgp;
  vector<vector<long32> > p_sqf;
  long64 last_clock;
  long64 starting_clock;
  double log_x;

  long64* sx;
  long64 sy;
  
  long128 binary_sum;
  long128 non_binary_sum;
  long64  count_unary_terms=1;
  long64  count_binary_terms;
  long64  count_non_binary_terms;
  long128  simple_leaves_sum;
  int    verbose;

  void time_msg(int indent, char* s, long64 last_time)
  {
    if (!verbose) return; 
    
    double elapsed_time = (double)(clock() - last_time) / CLOCKS_PER_SEC;
  
    last_clock = clock();

    for (int i=0; i < indent; i++)
      cout << " ";
  
    cout << "timer: computation of " << s << " took: ";  

    if (elapsed_time > 86400) // days
      {
	cout << (long32)elapsed_time/86400 << "d, ";
	elapsed_time -= (long32)(elapsed_time/86400)*86400;
      }
    if (elapsed_time > 3600) // hours
      {
	cout << (long32)elapsed_time/3600 << "h, ";
	elapsed_time -= (long32)(elapsed_time/3600)*3600;
      }
    if (elapsed_time > 60) // minutes
      {
	cout << (long32)elapsed_time/60 << "mn, ";
	elapsed_time -= (long32)(elapsed_time/60)*60;
	
      }
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(1);
    cout << elapsed_time << "s\n";
    cout.flush();
  }

  void tabule_sx() {
  sx = new long64[2+meissel::pi_y];
  sx[0]=0;
  for (int i=1; i <= meissel::pi_y; i++)
    sx[i] = sx[i-1] + presieved_primes::prime(i);
  sy = sx[meissel::pi_y];
}
}

