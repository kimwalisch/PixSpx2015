UNAME := $(shell uname)
ifeq ($(UNAME),Darwin)
	LFLAGS+=-stdlib=libstdc++
	LPATH=-L/opt/local/lib
	EXEC=pidarwin	
else
	EXEC=pidebian
endif

include dflags.mk

INC=-I ~deleglis/SIEVE2015/Include/
LPATH=-L ~deleglis/SIEVE2015/ -lgmp

CXX=g++ $(DFLAGS) -O3 -Wall $(INC) 

OBJS=    arith_long128.o arith_functions.o\
	bit_table.o bit_table_cnte.o bit_table_dynamic.o\
	sieve_access_frame.o presieved_primes.o sieve128_pg.o\
	sieve_large.o nth_rightp.o nth_leftp.o\
	primes.o primes6.o bit_sum_dynamic.o\
	nextPrime.o

%	: %.cc .headers
	$(CXX) $< $(OBJS) $(LFLAGS) $(LPATH) -o $@

libsieve.a:     $(OBJS)  
	ar -r libsieve.a $(OBJS)
	mv libsieve.a ../

# headers files
.headers: ../Include/arith_long128.h ../Include/arith_64_32.h ../Include/bit_table.h ../Include/bit_table_cnte.h\
	../Include/sieve_access_frame.h ../Include/arith_basic_functions.h\
	../Include/arith_structured_types.h ../Include/sieve_slices.h ../Include/bit_table_dynamic.h\
	../Include/mylib.h ../Include/interval_sieve.h ../Include/interval_sieve.hpp\
	../Include/prime_generator.h ../Include/sieve_slices.hpp
	@touch $@

tests: ../libsieve.a
	make_tests

tst_sieve_mod_6:	../Include/sieve_mod_6.h ../Include/sieve_mod_6.hpp tst_sieve_mod_6.cc

moretests: $(OBJ) .headers
	ith15
	ith16
	ith17

clean:
	rm -f *.o $(TESTS)
# have a look at https://www.gnu.org/software/make/manual/html_node/index.html#SEC_Contents
