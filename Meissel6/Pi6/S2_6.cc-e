//#include<mylib.h>
#include<meissel_global6.h>

long128 sumU();
long128 sumV1();
long128 sumV2();
//-------------------------------------------------------------------------
//
//    La contribution des feuilles speciales non criblees
//    celles pour lequele x^(1/4) < p <= x^(1/3)
//
//-------------------------------------------------------------------------


long128 Somme2=0;


long128 sumS2() {
  if (meissel6::verbose) {
    cout << "\n    S2 = U + V1 + V2" << endl;
  }
  long128 U  = sumU();
  long128 V1 = sumV1();
  
  long128 V2 = sumV2();
  Somme2 = U+ V1 + V2;
  if (meissel6::verbose) {
    cout << "    S2= " << Somme2 << endl << endl;
  }
  return Somme2;
}
