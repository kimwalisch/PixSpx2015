#include<mylib.h>
#include"../meissel_global.h"
/*
Cf Steklov, Formula (2.19) p. 87
*/


long128 slowsum(long a, long b, long z) {
  long128 res=0;
  long imin= 1+primes::piB(a);
  for (int iq=imin; iq <= primes::piB(b); iq++) {
    long q=primes::prime(iq);
    res += q*meissel::sx[z/q];
  }	
  return res;
} 

long128 quicksum(long a, long b, long z) {
  /*
  cout << "in quicksum a=" << a << "    b= " << b << "  z= " << z << endl;
  cout << "Primes are ";
  for (int i=1; i <= primes::number_of_primes(); i++)
    cout << primes::prime(i) << " ";
  cout << endl;
  */
  long128 res=0;
  long imin= 1+primes::piB(a);
  //cout << "piB(b)= " << primes::piB(b) << endl;
  long imax;
  while (imin <= primes::piB(b)) {
    //cout << "imin=  " << imin << endl;
    long q= primes::prime(imin);
    //cout << "q= " << q << endl;
    //cout << "z/q= " << z/q << endl;
    long it= primes::piB(z/q);
    //cout << "it= " << it << endl;
    imax= primes::piB(min(z/primes::prime(it),b));
    //cout << "   imax= " << imax << endl;
    //cout << "primes::sum(it)= " << primes::sum(it) << endl;
    res += (primes::sum(imax) - primes::sum(imin-1)) * primes::sum(it);
    imin =imax+1;
    //cout << " res= " << res << endl;
  }
  //cout << "quick sum will return res= " << res << endl;
  return res;
}
