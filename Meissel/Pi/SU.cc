#include<meissel_global.h>

long128 sumU()
 {
  long128 first_part, second_part;
  first_part  = (long64)(meissel::pi_sqr3_x - meissel::pi_sqr2_x_y) * meissel::pi_y;
  //cout << "first_part= " << first_part << endl;
  second_part = (long128)0;
  for (long32 ip = 1+meissel::pi_sqr2_x_y; ip <= meissel::pi_sqr3_x; ip++)
    {
      //cout << "p= " << presieved_primes::prime(ip) << endl;
      long64 pp = (long64)presieved_primes::prime(ip) * presieved_primes::prime(ip);
      second_part += presieved_primes::piB((long32)(meissel::x/pp));
    }
  // cout << "second_part= " << second_part << endl;
  if (meissel::verbose)
    cout << "    U  = " << first_part - second_part << "\n";
  return first_part - second_part;
}

