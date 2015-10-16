#include<mylib.h>
#include"pi6_include.h"

// Check if y and z values are admissible
// If not, adjust these values to some correct values

void check_data(long128 x, long64 y=0, long64 z=0, int verbose=0)
{
  if (verbose)
    cout << "Option -v, verbose mode" << endl;
  meissel6::x=x;
  meissel6::y=y;
  meissel6::z=z;
  meissel6::verbose=verbose;
  meissel6::sqr2_x = squareroot128(x);
  meissel6::sqr3_x = (long32)cuberoot128(x);
  meissel6::sqr4_x = (long32)squareroot64(meissel6::sqr2_x); 

  if (!meissel6::y) 
    {
      double log_x = log128(x);  //ZZZZZZZ
      y = (meissel6::sqr3_x * log_x * log_x * log_x)/10000;
      meissel6::y = max32(y, meissel6::sqr3_x+10);
      if (verbose)
	  cout << "y default value 0, has been replaced by " << meissel6::y << endl;
    }

  // this is not optimal for all cases 
  if (!meissel6::z) 
    {
      long64 z64 = min64(8*meissel6::y, meissel6::sqr2_x); 
      meissel6::z = min64(z64, LONG32_MAX - 1);
      if (verbose)
	cout << "z default value 0, has been replaced by " << meissel6::z << endl;
    }

  if (meissel6::y < meissel6::sqr3_x+10) // ZZZZZZZZZ 
    {
      cout << "y = " << meissel6::y << " must be at least equal to x^(1/3)+10 = "
	   << meissel6::sqr3_x+10 << "\n";
      error();
    }
    
  if (meissel6::y > meissel6::sqr2_x)
    {
      cout << "y = " << meissel6::y << " must be at most equal to x^(1/2) = "
	   << meissel6::sqr2_x << "\n";
      error();
    }

  if (meissel6::z < meissel6::y)
    {
      cout << "z = " << meissel6::z << " must be at least equal to y = "
	   << meissel6::y << "\n";
      error();
    }

  if (meissel6::z > meissel6::sqr2_x)
    {
      cout << "z = " << meissel6::z << " must be at most equal to sqr2(x) = "
	   << meissel6::sqr2_x << "\n";
      error();
    }
  
  meissel6::sqr2_z = (long32)squareroot64(meissel6::z);
  meissel6::sqr2_x_y = (long32)squareroot64((long64)(meissel6::x/meissel6::y));
  meissel6::x_y2 = (long32)(meissel6::x/meissel6::y/meissel6::y);
  if (verbose) 
    {
      cout << "Computing pi(x) for : \n";
      cout << "  x = " << meissel6::x << "\n";
      cout << "  y = " << meissel6::y << "\n";
      cout << "  z = " << meissel6::z << "\n";
      cout.flush();
    }

  // initialize the global prime table
  if (verbose) {
    cout << "\nMaking prime table up to y";// << endl;
  }

  primes6::init_primes(meissel6::y);
  if (verbose) {
    primes6::display();
  }


  // no prime larger than y should be considered
  meissel6::sqr2_z = min32(meissel6::sqr2_z, meissel6::y); 

  // the number of primes up to ...
  meissel6::pi_y      = primes6::piB(meissel6::y);
  meissel6::pi_sqr2_z = primes6::piB(meissel6::sqr2_z); 
  meissel6::pi_sqr3_x = primes6::piB(meissel6::sqr3_x);
  meissel6::pi_sqr4_x = primes6::piB(meissel6::sqr4_x);
  meissel6::pi_sqr2_x_y = primes6::piB(meissel6::sqr2_x_y);
  meissel6::pi_x_y2   = primes6::piB(meissel6::x_y2);
  
  // fgp (first good prime) est le plus petit nombre premier p tel que
  // le quotient x//p est représentable comme un réel sans perte de précision
  // ifgp est le rang de fgp 
  meissel6::ifgp = 1+ primes6::piB(x/((long64)EXACT_DOUBLE_MAX+1));
  meissel6::fgp  = primes6::prime(meissel6::ifgp);

  if (meissel6::verbose)
    {
      cout << "Global precomputed variables: \n"; 
      cout << "  x^(1/2)          = " << meissel6::sqr2_x << "\n";
      cout << "  x^(1/3)          = " << meissel6::sqr3_x << "\n";
      cout << "  x^(1/4)          = " << meissel6::sqr4_x << "\n";
      cout << "  z^(1/2)          = " << meissel6::sqr2_z << "\n";
      cout << "  (x/y)^(1/2)      = " << meissel6::sqr2_x_y << "\n";
      cout << "  x/y^2            = " << meissel6::x_y2 << "\n";
      cout << "  pi(y)            = " << meissel6::pi_y + 2 << "\n";
      cout << "  piB(y)           = " << meissel6::pi_y << "    (piB(u) = pi(u) - number-of_presieve_primes)\n";
      cout << "  piB(z^(1/2))     = " << meissel6::pi_sqr2_z << "\n";
      cout << "  piB(x^(1/3))     = " << meissel6::pi_sqr3_x << "\n";
      cout << "  piB(x^(1/4))     = " << meissel6::pi_sqr4_x << "\n";
      cout << "  piB((x/y)^(1/2)) = " << meissel6::pi_sqr2_x_y << "\n";
      cout << "  piB(x/y^2)       = " << meissel6::pi_x_y2 << "\n";
      cout << "  index of first good prime = " << meissel6::ifgp << endl;
      cout << "  first good prime          = " << primes6::prime(meissel6::ifgp) << "\n\n";
    }
  else
    cout << "\n";

  meissel6::last_clock = clock(); // initialization of the timer
}

namespace meissel6{
long128 pi(long128 x, long64 y, long64 z, int verbose)
{
  meissel6::x=x;
  meissel6::y=y;
  meissel6::z=z;
  meissel6::verbose=verbose;
  if ((double)meissel6::x < 1000)
    {
      if (meissel6::verbose) 
	cout << "x < 10000 donc simple crible d'Eratosthène ordinaire jusqu'à " << x << endl;
      if (x < 4)
	return max32(0,x-1);
      else {
	primes6::init_primes(meissel6::x);
	return primes6::piB(meissel6::x) + 2;
      }
    }

  // Change choices of y and z if necessary
  check_data(x,y,z,verbose);

  long128 p2 = P2();
  if (verbose)
    { cout << "\nI Computation of P2(x,y)" << endl;
      cout << "   P2(x,y) = " << p2 << "\n";
      meissel6::time_msg(3,(char *)" P2");
      cout.flush();
    }

  long128 fxy_term = pi_fxy();
  if (meissel6::verbose) {
    cout << "   Phi(x,y)   =  S0 + S1 + S2 + S3 = " << fxy_term << "\n\n";
  }
  long128 pi_x = fxy_term - p2 + (long128)(meissel6::pi_y - 1) + 2;
    
  if (meissel6::verbose) {
    cout << " III Pi(x) = Phi(x,y) - P2(x,y) + Pi(y)-1  = " << pi_x << endl;
    meissel6::time_msg(1,(char*)"  Pi(x)", meissel6::starting_clock);
  }
  return pi_x;
}
}
