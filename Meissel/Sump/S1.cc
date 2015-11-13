#include<mylib.h>
#include<meissel_global.h>

//-------------------------------------------------------------------------
//
//   S1 : feuilles speciales binaires avec x^(1/3) < m=p <= y
//
//-------------------------------------------------------------------------



static long128 Somme1=0;

long128 sumS1() {
  
  //tabule_sx();
  cout << "In S1 meissel::sy= " << meissel::sy << endl;
  for (int i = 1+meissel::pi_sqr3_x; i <= meissel::pi_y; i++)
    {
      //cout << "p= " << presieved_primes::prime(i) << "    sx[i]= " << meissel::sx[i] << endl;
      Somme1 += presieved_primes::prime(i)*(meissel::sy-meissel::sx[i]);
    }
  //cout << "S1() = " << Somme1 << endl << endl;
  return Somme1;
}

//-------------------------------------------------------------------------
