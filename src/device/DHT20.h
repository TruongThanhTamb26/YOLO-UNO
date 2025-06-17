#ifndef INC_DHT20_H_
#define INC_DHT20_H_

#include "globals.h"

void initDHT20();

extern int Humidity;    // Global variable to store humidity
extern int Temperature; // Global variable to store temperature

#endif /* INC_DHT20_H_ */