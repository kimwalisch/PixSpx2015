include ../dflags.mk
include ../lflags.mk
UNAME := $(shell uname)
ifeq ($(UNAME),Darwin)
        LFLAGS+=-stdlib=libstdc++
        LPATH=-L/opt/local/lib
endif

INCDIR="../../Include"
#LIBDIR="../../"
CXX=g++ -I $(INCDIR) $(DFLAGS) -O3

OBJS=  	meissel_global.o squarefree_table.o

all:	$(OBJS)

clean:
	rm -f *.o
