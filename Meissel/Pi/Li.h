#ifndef Li_h
#define Li_h
#include<math.h>
#include<iostream>
using namespace std;


double Ei(double x);

//LI2INV(x) est une approchée de la solution t de Li(t^2) = x
double LI2INV(double x);
double LiMinus1(double x);

double Riemann(double t);
double RiemannInv(double x);

#endif
