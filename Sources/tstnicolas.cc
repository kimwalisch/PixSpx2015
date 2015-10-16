#include<mylib.h>
#include<iostream>
#include<iomanip>

using namespace primes;

double gamma_euler   = 0.57721566490153286061;
double gamma1 = -0.07281584548367672486;
double  pif   = 3.14159265358979323846;
double lb    = lb     =  abs(gamma_euler*gamma_euler + 2*gamma1 + 1 - pif*pif/8);

long pip=0;
double thetap=0;
long pmax=1;
double qp=0;
double qpmax=0;
long cnte = 0;

double Ei(double x) {
  double tn = x;
  double res = gamma_euler + log(x) + tn;
  for (int n=2; n < 250; n++)
    {
      tn *= x*(n-1)/n/n;
      res += tn;
    }
  return res;
}

double li(double x) {
  return Ei(log(x));
}

void traite(long p) {
  cnte += 1;
  double logp=log((double) p);
  thetap += logp;
  double Ap= li(thetap) - cnte;
  qp = Ap/sqrt((double) p) * logp*logp;
  if (cnte % 10000000 == 0)
    cout << "cnte= " << cnte << "   p= " << p << "    li(thetap) = " <<  li(thetap)  << "   Ap= " << Ap << "  qp= " << qp << endl;


  if (qp > qpmax) {
    pmax=p;
    qpmax=qp;
  }
}

int main(int argc, char* argv[]) {
  long x = (argc>=2)? atol(argv[1]) : 1000000;
  long wsize= (argc>2)? atoi(argv[2]) : next_mult6(x);
  std::cout << std::setprecision(12);
  cout << "x= " << x << endl;
  cout << "Table des premiers jusqu'à 1000000"  << endl;
  primes::init_prime_table(1000000);
  //primes::display();

 
  sieve_by_slice<bit_table_cnte, long64> sieve(2,1,wsize,0, primes::presieve_base, AUTO_SIEVE);

  traite(2);
  traite(3);
  long64 p = sieve.get_next_prime();
  while (p <= x) {
    traite(p);
    p= sieve.get_next_prime();

  }

  long res= sieve.count(x);
  /*
  cout << "res = " << sieve.count(x) << endl;
  if (res != 78496) {
    cout << "Erreur: ce nombre devrait être égal à " << 78496 << endl;
    exit(1);
  }
  */
  return 0;
}
