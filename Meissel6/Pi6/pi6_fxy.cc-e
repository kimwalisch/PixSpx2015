#include"pi6_include.h"
#include"../squarefree_table6.h"
#include<arith6.h>

long128 sumS0();

long128 sumS1()
{
  long64 u = meissel6::pi_y - meissel6::pi_sqr3_x;
  return (long128)(u*(u-1)/2);
}

long128 sumS2();
long128 sumS3();

long128  pi_fxy()
{
  squarefree_table_init();
  if (meissel6::verbose) {
    cout << "\nII Computation of Phi(x,y)" << endl;
    cout << "    Squarefree tables initialized\n";
  }

  long128 S0 = sumS0();
  if (meissel6::verbose)
    {
      cout << "    Number of terms of S0 sum : " 
	   << meissel6::count_unary_terms << "\n";
      cout << "    S0 = " << S0 << endl << endl;
      cout.flush();
    }

  
  long128 S1 = sumS1();
  if (meissel6::verbose)
    {
      cout << "    S1 = " << S1 << endl;
    }

  long128 S2 = sumS2();
  
  long128 S3 = sumS3();
  if (meissel6::verbose) {
    cout <<   "    S3 = " << S3 << endl;
    meissel6::time_msg(8,(char *)"sieve terms");
    cout <<   "        number of binary terms       = " 
	 << meissel6::count_binary_terms << "\n";
    cout <<   "        total of binary terms        = " 
	 << meissel6::binary_sum << "\n";
    cout <<   "        number of non binary terms   = " 
	 << meissel6::count_non_binary_terms << "\n";
    cout <<   "        total of non binary terms    = " 
	 << meissel6::non_binary_sum << "\n";


      cout << endl;
  }



  return S0 + S1 + S2 + S3;
}
