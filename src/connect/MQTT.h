#ifndef INC_TASKMQTT_H_
#define INC_TASKMQTT_H_

#include "globals.h"

extern void initMQTT();
extern void reconnectMQTT();
extern void publishData(String feed, String data);

#endif /* INC_TASKMQTT_H_ */