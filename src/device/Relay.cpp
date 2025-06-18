#include "Relay.h"

void initRelay()
{
  // Initialize the relay pin
  pinMode(MY_RELAY, OUTPUT);
  digitalWrite(MY_RELAY, LOW); // Ensure the relay is off initially
}