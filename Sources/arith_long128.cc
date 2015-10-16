#include"../Include/mylib.h"

static char buff[100];
static char alphabet[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
static int base=10;

std::ostream& operator<<(std::ostream& stream, const long128& x) {
  long128 y=x;
  int lng=0;

  if (x==0) {
    stream << '0';
    return stream;
  }

  if (x < 0) {
    stream << "-";
    y=-x;
  }
  else {
    y=x;
  }

  while (y != 0) {
    buff[lng++] = alphabet[y % base];
    y /= base;

  }
  for (int i=lng-1; i >=0; i--)
    stream << buff[i];
  return stream;
}

long128 atolong128(char* s, int base)
{
  long128 sum = (long128)0;
  char c;
  while ((c = *s++))
    {
      sum *= base;
      sum += c - '0';
    }
  return sum;
}

