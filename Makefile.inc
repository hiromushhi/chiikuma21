APPL_COBJS += 
INCLUDES += -I$(ETROBO_HRP3_WORKSPACE)/etroboc_common

APPL_CXXOBJS += etrc_info.o device_io.o driving.o utils.o behavior.o parameter.o

SRCLANG := c++
