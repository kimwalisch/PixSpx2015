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
CXX=g++ -I $(INCDIR) $(DFLAGS) -O2

OBJS=  	pi.o ../Global/meissel_global.o pi_compute_p2.o pi_fxy.o ../Global/squarefree_table.o S0.o\
	S2.o S3.o SU.o V1.o V2.o W1W2.o W3W5.o W4.o Li.o

# main command
mains:	$(OBJS) ithprime.cc
	$(CXX) $(CFLAGS) -I $(INCDIR) main.cc -o $(EXEC) $(OBJS)  -lm $(EFLINK) $(LFLAGS) $(LPATH)  -L $(LIBDIR) -lsieve
	$(CXX) $(CFLAGS) -I $(INCDIR) ithprime.cc -o ithprime $(OBJS)  -lm $(EFLINK) $(LFLAGS) $(LPATH)  -L $(LIBDIR) -lsieve


all:	$(OBJS)

%	: %.cc .headers
	$(CXX) -I $(INCDIR) $< $(OBJS) $(LFLAGS) -o $@
#	$(CXX) -I $(INCDIR) $< $(OBJS) $(LFLAGS) $(LPATH) -o $@

clean:
	rm -f *.o ithprime $(EXEC)

# headers files
#.headers: ./piglobal.h
#	@touch $@

# have a look at https://www.gnu.org/software/make/manual/html_node/index.html#SEC_Contents
