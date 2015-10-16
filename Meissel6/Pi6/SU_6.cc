#include<meissel_global6.h>

long128 sumU()
 {
  long128 first_part, second_part;
  first_part  = (long64)(meissel6::pi_sqr3_x - meissel6::pi_sqr2_x_y) * meissel6::pi_y;
  //cout << "first_part= " << first_part << endl;
  second_part = (long128)0;
  for (long32 ip = 1+meissel6::pi_sqr2_x_y; ip <= meissel6::pi_sqr3_x; ip++)
    {
      //cout << "p= " << primes::prime(ip) << endl;
      long64 pp = (long64)primes6::prime(ip) * primes6::prime(ip);
      second_part += primes6::piB((long32)(meissel6::x/pp));
    }
  // cout << "second_part= " << second_part << endl;
  if (meissel6::verbose)
    cout << "    U  = " << first_part - second_part << "\n";
  return first_part - second_part;
}

