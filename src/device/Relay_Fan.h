#ifndef _Relay_Fan_h
#define _Relay_Fan_h

#include "globals.h"

enum RelayFanState
{
  RELAY_FAN_OFF = 0,
  RELAY_FAN_ON = 1
};

enum RelayFanOnState
{
  RELAY_ON = 0,
  FAN_ON = 1
};

void initRelayFan();

#endif // _Relay_Fan_h