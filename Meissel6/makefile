include dflags6.mk
include lflags6.mk
UNAME := $(shell uname)
ifeq ($(UNAME),Darwin)
        LFLAGS+=-stdlib=libstdc++
        LPATH=-L/opt/local/lib
endif

INCDIR="../Include"
#LIBDIR="../../"
CXX=g++ -I $(INCDIR) $(DFLAGS) -O3

OBJS=  	./Global6/meissel_global6.o ./Global6/squarefree_table6.o

all:	$(OBJS)
	cd Pi6 && $(MAKE)
	cd Global6 && $(MAKE)

%	: %.cc
	$(CXX) -I $(INCDIR) $< $(OBJS) $(LFLAGS) $(LPATH) -o $@

clean:
	rm -f *.o
	cd Pi6 && $(MAKE) clean
	cd Global6 && $(MAKE) clean

# have a look at https://www.gnu.org/software/make/manual/html_node/index.html#SEC_Contents
