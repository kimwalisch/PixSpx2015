// -*- C++ -*-
#ifndef arith_structured_types_h
#define arith_structured_types_h
#include<stdlib.h>
#include<limits.h>
#include<vector>
struct ldiv32 { 
  long32 q, r; 
  inline ldiv32(long32 a, long32 b);
};

struct ldiv64 { 
  long64 q, r; 
  inline ldiv64(long64 a, long64 b);
  inline ldiv64(long64 a);// Quotient et reste de la division par 6
};

class ldiv128 { 
public:
  long128 q;
  long64  r; 
  inline ldiv128(long128 a, long64 b);
  inline ldiv128(long128 a); // Quotient et reste de la division par 6
};

struct gcdex32 {
  long32 u, v, d;
  inline gcdex32(long32 a, long32 b);
};

class table_invmod32 {
private:
  vector<long32> inverses;
protected:
  long32 N;
public:
  table_invmod32() {};
  table_invmod32(long32 N);
  void create(long32 N);
  virtual ~table_invmod32() {}; // to be written down!
  inline long32 get_inverse(long32 a) { return inverses[a]; }
};
  
class arith_mod32:
  public table_invmod32 
{
private:
  vector<vector<long32> > invmul;
  vector<vector<long32> > invmul_index;
  vector<long32> index;
  vector<long32> residue;
public:
  arith_mod32() {};
  arith_mod32(long32 N);
  void create(long32 N);
  inline long32 get_mulinv(long32 a, long64 b); 
  inline long32 get_mulinv_index(long32 a, long32 b); 
  inline long32 get_index(long64 a); 
  inline long32 get_residue(long32 a) { return residue[a]; }
};

#endif
