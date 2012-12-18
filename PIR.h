#ifndef PIR_H
#define PIR_H

#if ARDUINO >= 100
 #include "Arduino.h"
#elif defined(__ARM3X8E__)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

/* PIR library 

written by Oskari Rauta
*/

// Calibration time in milliseconds
#define PIR_CAL_TIME 30
  
class PIR {
 private:
  uint8 _pin;
  uint32 calibrationTime;
  boolean _state;

 public:
  boolean state(void);
  PIR(uint8 pin);
  boolean update(void);
  boolean calibrating(void);
  void resetState(void);

};
#endif
  