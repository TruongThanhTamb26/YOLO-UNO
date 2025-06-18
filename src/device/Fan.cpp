#include "Fan.h"

void initFan()
{
  // Initialize the fan pin
  pinMode(MY_FAN, OUTPUT);
  digitalWrite(MY_FAN, LOW); // Ensure the fan is off initially
}