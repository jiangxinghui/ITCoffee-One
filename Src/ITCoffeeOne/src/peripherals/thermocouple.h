#ifndef THERMOCOUPLE_H
#define THERMOCOUPLE_H


#include "pindef.h"
//#if defined SINGLE_BOARD
//#include <Adafruit_MAX31855.h>
//SPIClass thermoSPI(thermoDI, thermoDO, thermoCLK);
//Adafruit_MAX31855 thermocouple(thermoCS, &thermoSPI);
//Adafruit_MAX31855 thermocouple(thermoCLK, thermoCS, thermoDO);

//#else
#include <max6675.h>

 MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

//#endif

static inline void thermocoupleInit(void) {

}


static inline float thermocoupleRead(void) {
  return thermocouple.readCelsius();

}

#endif
