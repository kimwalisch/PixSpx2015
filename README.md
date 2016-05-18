#Pix2015 Counting primes up to x

Let us denote pi(x) the number of primes up to x

The primes up to 10 are 2, 3, 5, 7, thus pi(10 = 4  

This repository contains files to compute pi(x) in time
O(x^(2/3)/(log x)^2)  

and to compute the nth prime in time O(n^(2/3)/(log n)^(4/3))

The algorithm for computing pi(x) is presented in:

Computing Psi(x), M. Deléglise and  J. Rivat. Math. Comp. 67 (1998), no. 224, 1691-1696.

# How to use these files

These files, written in C++,  can be compiled using
the gnu compiler g++ and the library GNU MP.
I tested them  on a PC using linux Ubuntu
and on a mac-book pro 64 bits.

Once we have got the sources ant put them in a directory, open a
command window in this this directory and execute

> make

After a few seconds, in the subfolder Meissel/Pi,

you will find two executable programs the program pi and the program ithprime

> pi x

computes pi(x) .

For example, on my macbook pro retina (2012)

> pi 10000000000000

gives pi(10^12) in about 0.2s

and

> pi 100000000000000000000

gives pi(10^20) in about 10h. 40minutes.

> ithprime n

computes the nth prime.For example 

> ithprime 1000000000000

gives the 10^12 nth prime,  p = 29996224275833,  in about 1.55 s.


> pi 1000000000000000000000

gives pi(10^21) in 31h 23m on a linux computer running at 3.2 Mhz.






