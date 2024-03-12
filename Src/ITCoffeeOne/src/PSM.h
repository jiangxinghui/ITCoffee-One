#ifndef PSM_h
#define PSM_h

#include "Arduino.h"
#include "pindef.h"
#ifdef STM32_BOARD
#else
#include "TimerOne.h"
#endif
class PSM
{
public:
  PSM(unsigned char sensePin, unsigned char controlPin, unsigned int range, int mode = RISING, unsigned char divider = 1, unsigned char interruptMinTimeDiff = 0);
#ifdef STM32_BOARD
  void initTimer(uint16_t delay, TIM_TypeDef* timerInstance = TIM1);
  #else
  void initTimer(uint16_t delay, TimerOne* timerInstance=&Timer1 );

  #endif

  

  void set(unsigned int value);

  long getCounter(void);
  void resetCounter(void);

  void stopAfter(long counter);

  unsigned int cps(void);
  unsigned long getLastMillis(void);

  unsigned char getDivider(void);
  void setDivider(unsigned char divider = 1);
  void shiftDividerCounter(char value = 1);



private:
  static inline void onZCInterrupt(void);
  static inline void calculateSkipFromZC(void);
  static inline void onPSMTimerInterrupt(void);
  void calculateSkip(void);
  void updateControl(bool forceDisable = true);

  unsigned char _sensePin;
  unsigned char _controlPin;
  unsigned int _range;
  unsigned char _divider = 1;
  unsigned char _dividerCounter = 1;
  unsigned char _interruptMinTimeDiff;
  volatile unsigned int _value;
  volatile unsigned int _a;
  volatile bool _skip = true;
  volatile long _counter;
  volatile long _stopAfter;
  volatile unsigned long _lastMillis = 0;

  bool _psmIntervalTimerInitialized = false;

  #ifdef STM32_BOARD
  HardwareTimer* _psmIntervalTimer;

  #else
TimerOne* _psmIntervalTimer;

  #endif
};

extern PSM* _thePSM;

#endif
