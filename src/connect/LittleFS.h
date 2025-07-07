#ifndef INC_TASKLITTLEFS_H_
#define INC_TASKLITTLEFS_H_

#include "globals.h"

extern bool info;

void initLittleFS();
bool loadConfig();
bool saveConfig();

#endif /* INC_TASKLITTLEFS_H_ */