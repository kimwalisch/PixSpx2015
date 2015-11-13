#include<mylib.h>

int main(int argc, char* argv[]) {

  long128 x = (argc>=2)? atolong128(argv[1]) : 1000000000000;
  long64  n = (argc>=3)? atol(argv[2]) : 10000;
  cout << "x = " << x  << "   n= " << n << endl;

  long128 p= nthleftp(x,n);
  cout << "The " << n << " th prime less than " << x << "  is "  << p << endl;

  cout << "ok\n";
  return 0;
}
