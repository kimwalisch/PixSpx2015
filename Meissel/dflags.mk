ifeq ($(SX),1)
	DF_SX= -DEDBUG_SX
endif

ifeq ($(SQF),1)
	DF_SQF = -DDEBUG_SQF
endif

DFLAGS = $(DF_SQF) $(DF_SX)

