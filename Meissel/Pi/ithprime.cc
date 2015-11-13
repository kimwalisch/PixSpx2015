#include"pi_include.h"
#include"Li.h"
#include<string.h>

int main(int argc, char* argv[])
{
  int c=0;
  int verbose=0;  
  long128 n;
  long128 x;
  long128 pi_x=0;
  

  if (argc > 1) {
    if (strcmp(argv[1],"-v")==0)
      {
	verbose=1;
	c = 1;
      }
  }
  
  n=atolong128(argv[c+1]);
  if (n <= 2) {
      cout << "\nFor n= " << n << "  the nthprime is " << n+1 << endl;
    return 0;
  }

  
  x=floor(RiemannInv((double)n));
  cout << "n   = " << n << endl;
  cout << "x   = " << x << endl;
  pi_x= meissel::pi(x,0,0,verbose);
  
  cout << "pi_x= " << pi_x << endl;
  long128 delta= pi_x-n;
  cout << "delta= pi(x)-n = " << delta << endl;
  
  long128 p= (delta < 0)?  nthrightp(x,-delta) : nthleftp(x,delta+1);
  cout << "\nFor n= " << n << "  the nthprime is " << p << endl;
}
