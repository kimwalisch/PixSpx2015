// -*- C++ -*-
#ifndef sieve_access_frame_h
#define sieve_access_frame_h
#include"mylib.h"

// sieve of the arithmetic progression de raison k

class access_frame {
private:
  vector<int> classes;
  vector<int> index;

public:
  int period;
  int number_of_classes;
  virtual ~access_frame() {}
  inline long64 lower_index64(long64 x) const;
  inline long128 lower_index128(long128 x) const;
  inline long128 sum128_6(long128 x) const;
  inline long64 get_integer(long i) const;
  access_frame(int B, int k, int l);
  access_frame() {};
  void create(int B, int k, int l);
  inline int get_period() const { return period; }
  inline int get_number_of_classes()const { return number_of_classes; }
  inline int get_class(int n) const { return classes[n]; }
  void display() const;
};

/*
inline long64
access_frame::lower_index64(long64 x) const
{
#ifdef DEBUG_SAFE
  if (x < 0)
    {
      cout << "lower_index: incorrect x = " << x << "\n";
      error();
    }
#endif 
  ldiv64 qr(x, period);
  return (qr.q)*number_of_classes + index[qr.r];
}
*/


// faster lower_index in the cas where period = 6
inline long64
access_frame::lower_index64(long64 x) const
{
#ifdef DEBUG_SAFE
  if (x < 0)
    {
      cout << "lower_index: incorrect x = " << x << "\n";
      error();
    }
#endif 
  ldiv64 qr(x);
  //return (qr.q)*number_of_classes + index[(long32)qr.r];
  return 2*(qr.q) + index[(long32)qr.r];
}



inline long128
access_frame::lower_index128(long128 x) const
{
#ifdef DEBUG_SAFE
  if (x < 0)
    {
      cout << "lower_index: incorrect x = " << x << "\n";
      error();
    }
#endif 
  ldiv128 qr(x, period);
  return (qr.q)*number_of_classes + index[(long32)qr.r];
}

inline long128
access_frame::sum128_6(long128 x) const
{
  ldiv128 qr(x);
  long128 res = 6*qr.q*qr.q;
  if (qr.r) {
    long128 tmp  = 6*qr.q;
    res += tmp+1;
    if (5 <= qr.r)
      {
	res += tmp+5;
      }
  }
  return res;
}

inline long64 
access_frame::get_integer(long i) const
{
  if (!i) return 0;
#ifdef DEBUG_SAFE
  if (i < 0) 
    {
      cout << "get_integer: i = " << i << " is invalid\n";
      error();
    }
#endif
  ldiv64 division(i - 1, number_of_classes);
  return classes[(long32)(division.r)] + period*division.q;
}

#endif
