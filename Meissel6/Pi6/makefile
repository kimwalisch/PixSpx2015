include dflags.mk
include lflags.mk
UNAME := $(shell uname)
ifeq ($(UNAME),Darwin)
        LFLAGS+=-stdlib=libstdc++
        LPATH=-L/opt/local/lib
        EXEC=pidarwin   
else
        EXEC=pidebian
endif

INCDIR="../../Include"
LIBDIR="../../"
TEST_SRCS=$(shell find . -name "tst*.cc")
TESTS=$(subst .cc,,$(TEST_SRCS))

#CXX=llvm-g++ $(DFLAGS) -O0
CXX=g++ -I $(INCDIR) $(DFLAGS) -O3

OBJS=  	pi.o ../../Meissel6/Global6/meissel_global6.o pi6_compute_p2.o pi6_fxy.o ../Global6/squarefree_table6.o S0_6.o\
	S2_6.o S3_6.o SU_6.o V1_6.o V2_6.o W1W2_6.o W3W5_6.o W4_6.o Li.o

# main command
mains:	$(OBJS) ithprime.cc
	$(CXX) $(CFLAGS) -I $(INCDIR) main.cc -o $(EXEC) $(OBJS)  -lm $(EFLINK) $(LFLAGS) $(LPATH)  -L $(LIBDIR) -lsieve
	$(CXX) $(CFLAGS) -I $(INCDIR) ithprime.cc -o ithprime $(OBJS)  -lm $(EFLINK) $(LFLAGS) $(LPATH)  -L $(LIBDIR) -lsieve


all:	$(OBJS)

%	: %.cc .headers
	$(CXX) -I $(INCDIR) $< $(OBJS) $(LFLAGS) -o $@
#	$(CXX) -I $(INCDIR) $< $(OBJS) $(LFLAGS) $(LPATH) -o $@

clean:
	rm -f *.o ithprime6 $(EXEC)

# headers files
#.headers: ./piglobal.h
#	@touch $@

# have a look at https://www.gnu.org/software/make/manual/html_node/index.html#SEC_Contents
