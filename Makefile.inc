APPL_COBJS += 
INCLUDES += -I$(ETROBO_HRP3_WORKSPACE)/etroboc_common

APPL_CXXOBJS += EtrcRunner.o state_transition.o LinetraceMode.o Wheels.o \
                ColorMeter.o

SRCLANG := c++
