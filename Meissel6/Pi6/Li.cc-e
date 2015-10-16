#include<math.h>
#include<iostream>
using namespace std;
const double gamma_euler_const =  0.57721566490153286061;

double Ei(double x) {
  double tn = x;
  double res = gamma_euler_const + log(x) + tn;
  for (int n=2; n < 250; n++)
    {
      tn *= x*(n-1)/n/n;
      res += tn;
    }
  return res;
}

//LI2INV(x) est une approchée de la solution t de Li(t^2) = x
double LI2INV(double x) {
  double t = sqrt(x*log(x));
  for (int i=1; i < 12; i++)
    t = t-(Ei(2*log(t))-x)*log(t)/t;
  return t;
}

double LiMinus1(double x) {
  double t = x*log(x);
  for (int i=1; i < 12; i++)
    t = t-(Ei(log(t))-x)*log(t);
  return t;
}

double Riemann(double t) {
  double logt = log(t);
  //  cout << "In Riemann(t) avec logt = " << logt; 
  //cout << "    ->  " <<  Ei(logt) - Ei(logt/2)/2 - Ei(logt/3)/3 << endl;
  return Ei(logt) - Ei(logt/2)/2 - Ei(logt/3)/3;
}

double RiemannInv(double x) {
  double t = x*log(x);
  //cout << "tinit = " << t << endl;
  for (int i=1; i < 8; i++) {
    t = t-(Riemann(t)-x)*log(t/(1-0.5/pow(x,0.5)-0.333333333333/pow(x,0.3333)));
    //cout << "i = " << i << "  t  = " << t << endl;
  }
  return t;
}
