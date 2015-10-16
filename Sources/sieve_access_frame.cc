#include<mylib.h>
#include<orders.h>

access_frame::access_frame(long32 B, long32 k, long32 l)
{
  create(B,k,l);
}

void 
access_frame::create(long32 B, long32 k, long32 l)
{
#ifdef DEBUG_SV
  cout << "access_frame::create with B = " << B <<", k = " << k <<", l = " << l << "\n";  
#endif
  period = lcm32(B,k);
  number_of_classes = phi_euler32(B)/phi_euler32(gcd32(k,B));
  index.resize(period);
  classes.resize(number_of_classes);
  
  for (long32 x = 0, cnt = 0; x < period; x++)
    {
      if ((gcd32(x,B) == 1) && ( long32(x)%k == l))
	{
	  classes[cnt] = x;
	  index[x] = ++cnt;
	}
      else index[x] = cnt;
    }
#ifdef DEBUG_SV
  display();
#endif
}

void 
access_frame::display() const
{
  cout << "access_frame: period " << period << "  cardinal " << number_of_classes << "\n";
  cout << "  classes  = "; displayv< vector<int> >(classes);
  cout << "  index    = "; displayv< vector<int> >(index);
}

