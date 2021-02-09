APPL_COBJS += 
INCLUDES += -I$(ETROBO_HRP3_WORKSPACE)/etroboc_common

APPL_CXXOBJS += EtrcRunner.o state_transition.o drive_modes.o Wheels.o \
                game_strategy.o meters.o ColorMeter.o PidControl.o

SRCLANG := c++
