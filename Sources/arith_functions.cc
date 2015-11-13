#include<mylib.h>

long min(long a, long b) {
  return (a <= b)? a : b;
}

void 
table_invmod32::create(long32 x) 
{
  N = x;
  inverses.resize(N);
  for (long32 i = 0; i < N; i++ )
    inverses[i] = invmod32(i, N);
}

table_invmod32::table_invmod32(long32 x) 
{
  create(x);
}

void 
arith_mod32::create(long32 x)
{
  long32 phix = phi_euler32(x);
  table_invmod32::create(x);
  index.resize(x);
  residue.resize(phix);
  invmul.resize(x);
  invmul_index.resize(phix);

  long32 ind = 0;
  for (long32 a = 0; a < x; a++) 
    {
      if (gcd32(a, x) == 1)
	{
	  residue[ind] = a;
	  index[a] = ind++;
	}
      else
	index[a] = -1;
    }

  for (long32 a = 0; a < x; a++) 
    {
      invmul[a].resize(x);
      for (long32 b = 0; b < x; b++)
	if (gcd32(b, x) != 1) invmul[a][b] = 0; // a.b^-1 is undefined
	else
	  {
	    long32 inv_b = get_inverse(b);
	    invmul[a][b] = mod32(a*inv_b, x);
	  }
    }

  for (long32 i = 0; i < phix; i++)
    {
      invmul_index[i].resize(phix);
      for (long32 j = 0; j < phix; j++)
	invmul_index[i][j] = index[invmul[residue[i]][residue[j]]];
    }
}

arith_mod32::arith_mod32(long32 x)
{
  create(x);
}

long64
squareroot128(long128 x)
{
  long64 n;
  long64 y = (long64)pow128(x, 0.55);
  
  do
    {
      n = y;
      y = (n + (long64)(x/n))>>1;
    } while (y < n);

  return n;
}

long64 
squareroot64(long64 x)
{
  long64 n;
  long64 y = x;
  
  do
    {
      n = y;
      y = (n + x/n)>>1;
    } while (y < n);

  return n;
}

long32 
cuberoot128(long128 x)
{
  long64 n;
  long32 y = (long32)pow128(x, 0.35);
  
  do
    {
      n = y;
      y = (long32)((2*n + (long32)(x/(n*n)))/3);
    } while (y < n);

  return long32(n);
}

double
log128(long128 x)
{
  return log((double)x);
}

double
exp128(long128 x)
{
  return exp((double)x);
}

double
pow128(long128 x, double e)
{
  return pow((double)x, e);
}

int
is_exact_as_double(long128 x)
{
  return !(x > EXACT_DOUBLE_MAX);
}
