include dflags.mk
include lflags.mk


UNAME := $(shell uname)
ifeq ($(UNAME),Darwin)
        LFLAGS+=-stdlib=libstdc++
        LPATH=-L/opt/local/lib
endif

INCDIR="../../Include"
LIBDIR="../../"

CXX=g++ -I $(INCDIR) $(DFLAGS) -O3

OBJS=  	../Global/meissel_global.o ../Global/squarefree_table.o sump.o p2xy.o sump_fxy.o S0.o S1.o SU.o V1.o\
	S2.o S3.o V2.o W1W2.o  W3W5.o W4.o

# main command
mains:	$(OBJS) .headers
	echo $(DFLAGS)	
	$(CXX) $(CFLAGS) -I $(INCDIR) main.cc -o sumpx $(OBJS)  -lm $(EFLINK) $(LFLAGS) $(LPATH)  -L $(LIBDIR) -lsieve

all:	$(OBJS)

%	: %.cc .headers
	$(CXX) -I $(INCDIR) $< $(OBJS) $(LFLAGS) $(LPATH) -o $@

clean:
	rm -f *.o ithprime sumpx

# headers files
#.headers: ../meissel_global.h
#	@touch $@

# have a look at https://www.gnu.org/software/make/manual/html_node/index.html#SEC_Contents
