#include <Arduino.h>

#define SERIAL_PARSER  void serialEvent() \
{\
  BANK.temp = Serial.read();\
  if (BANK.temp < 64); /*nothing */ \
  else if (BANK.temp < 100)BANK.destination = BANK.temp - 65; /*var */ \
  else if (BANK.temp < 201) /* //val */ \
  { \
    BANK.value = BANK.temp - 100;\
    BANK.setVarBuff();\
  }\
  else;\
}


static class VSL
{
  public:
    void printVar(uint8_t number);
    void setVar(uint8_t var, uint8_t value);
    void setAndSendVar(uint8_t var, uint8_t value);
    // void sendVar(uint8_t var);
    void serialEvent(void);
    void decod(void);
    void setVarBuff(void);

    // private:
    uint8_t values[100]; //from A to Z
    uint8_t destination, value;
    uint8_t temp;
} BANK;
