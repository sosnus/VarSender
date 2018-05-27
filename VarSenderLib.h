#include <Arduino.h>  

static class VSL
{
  public:
  //VSL();
  void printVar(uint8_t number);
  void setVar(uint8_t var, uint8_t value);
  // void sendVar(uint8_t var);
  void serialEvent(void);


 // private:
uint8_t values[100]; //from A to Z
  
}BANK;
