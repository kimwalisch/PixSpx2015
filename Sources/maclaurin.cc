#include<iostream>
#include<cmath>
#include<cfloat>
#include<quadmath.h>

using namespace std;

__float128 Bk[21];

void initbernoulli() {
  Bk[2]  = ((__float128)     +1) /    6;
  Bk[4]  = ((__float128)     -1) /   30;
  Bk[6]  = ((__float128)     +1) /   42;
  Bk[8]  = ((__float128)     -1) /   30;
  Bk[10] = ((__float128)     +5) /   66;
  Bk[12] = ((__float128)   -691) / 2730;
  Bk[14] = ((__float128)     +7) /    6;
  Bk[16] = ((__float128)  -3617) /  510;
  Bk[18] = ((__float128) +43867) / 7980;
  Bk[20] = ((__float128)-174611) /  330;
}

__float128 stirling(int N) {
  cout << " In stirlin N= " << N << endl;
  __float128 res = (N+0.5)*log((long double) N) - N + 0.91893853320467274178032973640562;
  cout << "res initialise avec " << (long double)res << endl;
  __float128 den = N;
  __float128 N2  = N * den;
  for (int i=2; i <= 20; i+=2) {
    cout << "i= " << i << "Bi= " << Bk[i] << endl;
    __float128 tmp = (long double) Bk[i];
    cout << "den = " << (long double)den << endl;
    cout << "Ajout de " << (long double)(tmp/i/(i-1)/den) << endl;
    res += tmp/i/(i-1)/den;
    den *= N2;
  }
  return res;
}
