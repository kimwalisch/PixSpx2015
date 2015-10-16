#include"pi_include.h"
#include<string.h>

int main(int argc, char* argv[])
{
  int c=0;
  int verbose=0;
  
  long128 x;
  long64 y=0;
  long64 z=0;
  long128 pix=0;
  
  meissel::starting_clock = clock();


  if (argc > 1) {
    if (strcmp(argv[1],"-v")==0)
      {
	verbose=1;
	c = 1;
      }
  }

  if (argc == c+1) {
    x=long128(1000000000000);
    pix=  meissel::pi(x,0,0,verbose);
  }
  
  if (argc == c+2) {
    x=atolong128(argv[c+1]);
    pix=  meissel::pi(x,0,0,verbose);
  }

  if (argc == c+3) {
    x=atolong128(argv[c+1]);
    y=atolong128(argv[c+2]);
    pix = meissel::pi(x,y,0,verbose);
    }
  
  if (argc == c+4) {
    x=atolong128(argv[c+1]);
    y=atolong128(argv[c+2]);
    z=atolong128(argv[c+3]);
    pix = meissel::pi(x,y,z,verbose);
    }
  cout << "x     = " << x << endl;
  cout << "Pi(x) = " << pix << endl;
  meissel::time_msg(0,(char*)"Pi(x)", meissel::starting_clock);
  return 0;
}
