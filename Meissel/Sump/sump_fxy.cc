#include<mylib.h>
#include"sump_include.h"
#include"../squarefree_table.h"
long128 sumS0();
long128 sumS1();
long128 sumS2();
long128 sumS3();
long128 sumV1();

long128 sumU();


long128  sump_fxy()
{
  if (meissel::verbose) {
    cout << "\nII Computation of Phi(x,y)" << endl;
  }
  squarefree_table_init();

  long128 S0 =sumS0();
  if (meissel::verbose)
    {
      cout << "      S0 = "  << S0 << endl;
      cout.flush();
    }

  meissel::tabule_sx();
#ifdef DEBUG_SX
  cout << "Valeurs de sx[i] = p_0 + p_1 + p_2 + .... + p_i" << endl;
  for (int i=0; i < meissel::pi_y; i++)
    cout << "sx[" << i << "]= " << meissel::sx[i] << endl;
  cout << endl;
#endif

  
  long128 S1 =  sumS1();
  if (meissel::verbose) {
    cout << "      S1 = " << S1 << endl << endl;
  }
  
  long128 S2 = sumS2();
  if (meissel::verbose) {
    cout << "      S2 = " << S2 << endl << endl;
  }

  long128 S3 = sumS3();
  if (meissel::verbose)
    {
      cout << "     S3 = " << S3 << endl << endl;
      cout.flush();
    }

  if (meissel::verbose)
    {
      cout <<   "        number of binary terms       = " 
	   << meissel::count_binary_terms << "\n";
      cout <<   "        total of binary terms        = " 
	   << meissel::binary_sum << "\n";
      cout <<   "        number of non binary terms   = " 
	   << meissel::count_non_binary_terms << "\n";
      cout <<   "        total of non binary terms    = " 
	   << meissel::non_binary_sum << "\n";

      meissel::time_msg(8,(char *)"sieve terms");
    }

  return S0 + S1  + S2 + S3;
}
