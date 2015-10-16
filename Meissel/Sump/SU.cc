//#include<mylib.h>
#include<meissel_global.h>
#include"S2.h"

//-------------------------------------------------------------------------
//   SommeU feullles speciales bianires avec x^(1/4) < p <= x^(1/3)
//   et m=q > x/p^2
//
//   Contribution des feuiles speciales de plus petit facteur p
//   x^(1/4)  < p <= x^(1/3) et telles que m > x/p^2
//   ce qui implique que m est premier, m=q. 
//   Cette contribution est donc   U = sum_{x^(1/4) < p <= x^(1/3) 
//          f(p) sum_{p < q <= y, x/p^2 < q} f(q) Phi(x/pq,p-1)
//   La condition q > x/p^2 implique p^2 > x/q >= x/y, donc
//   p > (x/y)^(1/2)
//   On a donc U = sum_{(x/y)(1/2) < p <= x^(1/3)
//        f(p) sum_{x/p^2 < q <= y} f(q) Phi(x/pq,p-1)
//   et enfin, puisque x/pq < p chaque valeur de Phi est reduite a 1
//   U = sum_{(x/y)(1/2) < p <= x^(1/3) f(p) sum_{x/p^2 < q <= y} f(q)
//   U = sum_{(x/y)(1/2) < p <= x^(1/3) f(p) S(y) - S(x/p^2)
//
//-------------------------------------------------------------------------

static long128 SommeU;
static long64 xp2_long; // ZZ ou long128 ?

inline long fint(long u) {return u;}


long128 sumU() {
  SommeU  = meissel::sx[meissel::pi_sqr3_x];
  //cout << "SommeU 1 = " << SommeU << "\n";
  SommeU -= meissel::sx[meissel::pi_sqr2_x_y];
  //cout << "SommeU 2 = " << SommeU << "\n";
  SommeU *= meissel::sx[meissel::pi_y];
  //cout << "SommeU demarre = " << SommeU << "\n";
  for (int k = 1+meissel::pi_sqr2_x_y; k <= meissel::pi_sqr3_x; k++)
    {
      long p = primes::prime(k);
      xp2_long =meissel::x/p;
      int xp2 = xp2_long/p;
      //cout << "p = " << p << "    xp2= " << xp2 << endl;
      SommeU -= fint(p) * meissel::sx[primes::piB(xp2)];
    }
  if (meissel::verbose) {
    cout << "      U = " << SommeU << endl <<endl;
    cout.flush();
  }
  return SommeU;
}

