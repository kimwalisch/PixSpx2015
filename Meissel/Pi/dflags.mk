ifeq ($(PRIMES),1)
	DF_PRIMES = -DDEBUG_PRIMES
endif

ifeq ($(V1),1)
	DF_V1= -DDEBUG_V1
endif

ifeq ($(SQF),1)
	DF_SQF = -DDEBUG_SQF
endif

ifeq ($(W1W2),1)
	DF_W1W2= -DDEBUG_W1W2
endif

ifeq ($(P2),1)
	DF_P2 = -DDEBUG_P2
endif

ifeq ($(MP),1)
	DF_MP = -DDEBUG_MP
endif

ifeq ($(ST),1)
	DF_ST = -DDEBUG_ST
endif

ifeq ($(S0),1)
	DF_S0 = -DDEBUG_S0
endif

ifeq ($(SV),1)
	DF_SV = -DDEBUG_SV
endif

ifeq ($(VC),1)
	DF_VC = -DDEBUG_VC
endif

ifeq ($(LG),1)
	DF_LG = -DDEBUG_LG
endif

ifeq ($(SAFE),1)
	DF_SF = -DDEBUG_SAFE
endif

ifeq ($(DEBUG),1)
	CXX = g++
	CFLAGS = -g -O2 -Wall -I. -DDEBUG
	CPPFLAGS = -DDEBUG
endif

# flags for Electric Fence
ifeq ($(EFENCE),1)
	CXX = g++
	CFLAGS = -g -Wall -I. -DDEBUG
	CPPFLAGS = -DDEBUG
	EFLINK = -lefence
endif

DFLAGS = $(DF_SQF) $(DF_P2) $(DF_MP) $(DF_ST) $(DF_S0) $(DF_SV) $(DF_V1) $(DF_LG) $(DF_SF) $(DF_PRIMES)\
	$(DF_W1W2) $(DDEBUG)  $(EFENCE)

