include dflags6.mk
include lflags6.mk
UNAME := $(shell uname)
ifeq ($(UNAME),Darwin)
        LFLAGS+=-stdlib=libstdc++
        LPATH=-L/opt/local/lib
endif

INCDIR="../../Include"
#LIBDIR="../../"
CXX=g++ -I $(INCDIR) $(DFLAGS) -O3

OBJS=  	meissel_global6.o squarefree_table6.o

all:	$(OBJS)

%	: %.cc
	$(CXX) -I $(INCDIR) $< $(OBJS) $(LFLAGS) $(LPATH) -o $@

clean:
	rm -f *.o

# have a look at https://www.gnu.org/software/make/manual/html_node/index.html#SEC_Contents
