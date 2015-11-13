#include<mylib.h>
#include"pi_include.h"

// Check if y and z values are admissible
// If not, adjust these values to some correct values

void check_data(long128 x, long64 y=0, long64 z=0, int verbose=0)
{
  if (verbose)
    cout << "Option -v, verbose mode" << endl;
  meissel::x=x;
  meissel::y=y;
  meissel::z=z;
  meissel::verbose=verbose;
  meissel::sqr2_x = squareroot128(x);
  meissel::sqr3_x = (long32)cuberoot128(x);
  meissel::sqr4_x = (long32)squareroot64(meissel::sqr2_x); 

  if (!meissel::y) 
    {
      double log_x = log128(x);  //ZZZZZZZ
      y = (meissel::sqr3_x * log_x * log_x * log_x)/10000;
      meissel::y = max32(y, meissel::sqr3_x+10);
      if (verbose)
	  cout << "y default value 0, has been replaced by " << meissel::y << endl;
    }

  // this is not optimal for all cases 
  if (!meissel::z) 
    {
      long64 z64 = min64(8*meissel::y, meissel::sqr2_x); 
      meissel::z = min64(z64, LONG32_MAX - 1);
      if (verbose)
	cout << "z default value 0, has been replaced by " << meissel::z << endl;
    }

  if (meissel::y < meissel::sqr3_x+10) // ZZZZZZZZZ 
    {
      cout << "y = " << meissel::y << " must be at least equal to x^(1/3)+10 = "
	   << meissel::sqr3_x+10 << "\n";
      error();
    }
    
  if (meissel::y > meissel::sqr2_x)
    {
      cout << "y = " << meissel::y << " must be at most equal to x^(1/2) = "
	   << meissel::sqr2_x << "\n";
      error();
    }

  if (meissel::z < meissel::y)
    {
      cout << "z = " << meissel::z << " must be at least equal to y = "
	   << meissel::y << "\n";
      error();
    }

  if (meissel::z > meissel::sqr2_x)
    {
      cout << "z = " << meissel::z << " must be at most equal to sqr2(x) = "
	   << meissel::sqr2_x << "\n";
      error();
    }
  
  meissel::sqr2_z = (long32)squareroot64(meissel::z);
  meissel::sqr2_x_y = (long32)squareroot64((long64)(meissel::x/meissel::y));
  meissel::x_y2 = (long32)(meissel::x/meissel::y/meissel::y);
  if (verbose) 
    {
      cout << "Computing pi(x) for : \n";
      cout << "  x = " << meissel::x << "\n";
      cout << "  y = " << meissel::y << "\n";
      cout << "  z = " << meissel::z << "\n";
      cout.flush();
    }

  // initialize the global prime table
  if (verbose) {
    cout << "\nMaking prime table up to y";// << endl;
  }

  presieved_primes::init_prime_table(meissel::y, meissel::number_of_presieve_primes);
  if (verbose) {
    presieved_primes::display();
  }


  // no prime larger than y should be considered
  meissel::sqr2_z = min32(meissel::sqr2_z, meissel::y); 

  // the number of primes up to ...
  meissel::pi_y      = presieved_primes::piB(meissel::y);
  meissel::pi_sqr2_z = presieved_primes::piB(meissel::sqr2_z); 
  meissel::pi_sqr3_x = presieved_primes::piB(meissel::sqr3_x);
  meissel::pi_sqr4_x = presieved_primes::piB(meissel::sqr4_x);
  meissel::pi_sqr2_x_y = presieved_primes::piB(meissel::sqr2_x_y);
  meissel::pi_x_y2   = presieved_primes::piB(meissel::x_y2);
  
  // fgp (first good prime) est le plus petit nombre premier p tel que
  // le quotient x//p est représentable comme un réel sans perte de précision
  // ifgp est le rang de fgp 
  meissel::ifgp = 1+ presieved_primes::piB(x/((long64)EXACT_DOUBLE_MAX+1));
  meissel::fgp  = presieved_primes::prime(meissel::ifgp);

  if (meissel::verbose)
    {
      cout << "Global precomputed variables: \n"; 
      cout << "  x^(1/2)          = " << meissel::sqr2_x << "\n";
      cout << "  x^(1/3)          = " << meissel::sqr3_x << "\n";
      cout << "  x^(1/4)          = " << meissel::sqr4_x << "\n";
      cout << "  z^(1/2)          = " << meissel::sqr2_z << "\n";
      cout << "  (x/y)^(1/2)      = " << meissel::sqr2_x_y << "\n";
      cout << "  x/y^2            = " << meissel::x_y2 << "\n";
      cout << "  pi(y)            = " << meissel::pi_y + presieved_primes::number_of_presieve_primes << "\n";
      cout << "  piB(y)           = " << meissel::pi_y << "    (piB(u) = pi(u) - number-of_presieve_primes)\n";
      cout << "  piB(z^(1/2))     = " << meissel::pi_sqr2_z << "\n";
      cout << "  piB(x^(1/3))     = " << meissel::pi_sqr3_x << "\n";
      cout << "  piB(x^(1/4))     = " << meissel::pi_sqr4_x << "\n";
      cout << "  piB((x/y)^(1/2)) = " << meissel::pi_sqr2_x_y << "\n";
      cout << "  piB(x/y^2)       = " << meissel::pi_x_y2 << "\n";
      cout << "  index of first good prime = " << meissel::ifgp << endl;
      cout << "  first good prime          = " << presieved_primes::prime(meissel::ifgp) << "\n\n";
    }
  else
    cout << "\n";

  meissel::last_clock = clock(); // initialization of the timer
}

namespace meissel{
long128 pi(long128 x, long64 y, long64 z, int verbose)
{
  meissel::x=x;
  meissel::y=y;
  meissel::z=z;
  meissel::verbose=verbose;
  if ((double)meissel::x < 1000)
    {
      if (meissel::verbose) 
	cout << "x < 10000 donc simple crible d'Eratosthène ordinaire jusqu'à " << x << endl;
      if (x < 4)
	return max32(0,x-1);
      else {
	presieved_primes::init_prime_table(meissel::x,meissel::number_of_presieve_primes);
	return presieved_primes::piB(meissel::x) + presieved_primes::number_of_presieve_primes;
      }
    }

  // Change choices of y and z if necessary
  check_data(x,y,z,verbose);

  long128 p2 = P2();
  if (verbose)
    { cout << "\nI Computation of P2(x,y)" << endl;
      cout << "   P2(x,y) = " << p2 << "\n";
      meissel::time_msg(3,(char *)" P2");
      cout.flush();
    }

  
  long128 fxy_term = pi_fxy();
  
  if (meissel::verbose) {
    cout << "   Phi(x,y)   =  S0 + S1 + S2 + S3 = " << fxy_term << "\n\n";
  }
  long128 pi_x = fxy_term - p2 + (long128)(meissel::pi_y - 1) + presieved_primes::number_of_presieve_primes;
    
  if (meissel::verbose) {
    cout << " III Pi(x) = Phi(x,y) - P2(x,y) + Pi(y)-1  = " << pi_x << endl;
    meissel::time_msg(1,(char*)"  Pi(x)", meissel::starting_clock);
  }
  return pi_x;
}
}
