UNAME := $(shell uname)
ifeq ($(UNAME),Darwin)
	LFLAGS+=-stdlib=libstdc++
	LPATH=-L/opt/local/lib
	EXEC=pidarwin	
else
	EXEC=pidebian
endif

