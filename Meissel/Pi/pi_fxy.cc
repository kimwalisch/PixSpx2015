#include"pi_include.h"
#include"../squarefree_table.h"

long128 sumS0();

long128 sumS1()
{
  long64 u = meissel::pi_y - meissel::pi_sqr3_x;
  return (long128)(u*(u-1)/2);
}

long128 sumS2();
long128 sumS3();

long128  pi_fxy()
{
  squarefree_table_init();

  if (meissel::verbose) {
    cout << "\nII Computation of Phi(x,y)" << endl;
    cout << "    Squarefree tables initialized\n";
  }

  long128 S0 = sumS0();
  if (meissel::verbose)
    {
      cout << "    Number of terms of S0 sum : " 
	   << meissel::count_unary_terms << "\n";
      cout << "    S0 = " << S0 << endl << endl;
      cout.flush();
    }

  
  long128 S1 = sumS1();
  if (meissel::verbose)
    {
      cout << "    S1 = " << S1 << endl;
    }

  long128 S2 = sumS2();
  
  long128 S3 = sumS3();
  if (meissel::verbose) {
    cout <<   "    S3 = " << S3 << endl;
    meissel::time_msg(8,(char *)"sieve terms");
    cout <<   "        number of binary terms       = " 
	 << meissel::count_binary_terms << "\n";
    cout <<   "        total of binary terms        = " 
	 << meissel::binary_sum << "\n";
    cout <<   "        number of non binary terms   = " 
	 << meissel::count_non_binary_terms << "\n";
    cout <<   "        total of non binary terms    = " 
	 << meissel::non_binary_sum << "\n";


      cout << endl;
  }



  return S0 + S1 + S2 + S3;
}
