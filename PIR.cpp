/* PIR library

written by Oskari Rauta
*/

#include "PIR.h"

PIR::PIR(uint8 pin) {
  _pin = pin;
  pinMode(_pin, INPUT);
#if ARDUINO >= 100
  digitalWrite(_pin, LOW);
#endif
  calibrationTime = millis();
  if ( calibrationTime == 0 )
    calibrationTime = 1;
  _state = false;
}

boolean PIR::calibrating(void) {
  return ( calibrationTime != 0 );
}

boolean PIR::update(void) {
  if ( calibrationTime == 0 ) {
    if ( digitalRead(_pin) == HIGH )
      _state = true;
  } else {
    if ( millis() > ( calibrationTime + ( PIR_CAL_TIME * 1000 )))
      calibrationTime = 0;
  }
  return _state;
}

void PIR::resetState(void) {
  _state = false;
}

boolean PIR::state(void) {
  return _state;
}

        