#ifndef PUMP_H
#define PUMP_H

#include <Arduino.h>
#define PUMP_INTERVAL 1000



void pump_UpdateZC();


void pumpInit(unsigned char sensePin, unsigned char controlPin,const int powerLineFrequency, 
const float pumpFlowAtZero);
float setPumpPressure(const float targetPressure, const float flowRestriction,
 float currentPressure,float currentFlow,float currentPressureChangeSpeed) ;

float getPumpFlow(const float cps, const float pressure);
float getPumpFlowPerClick(const float pressure);
float getClicksPerSecondForFlow(const float flow, const float pressure);
float setPumpFlow(const float targetFlow, const float pressureRestriction, float currentPressure,float currentFlow,float currentPressureChangeSpeed);
float getPumpPct(const float targetPressure, const float flowRestriction, float currentPressure,float currentFlow,float currentPressureChangeSpeed);

void setPumpOff();

 void setPumpPowerPercentage(float power);

 long getAndResetClickCounter();

void update() ;




#endif
