#include <Arduino.h>  

static class VarSender
{
  public:
  //VarSender();
  void printVar(uint8_t number);
  void setVar(uint8_t var, uint8_t value);
  // void sendVar(uint8_t var);
  

  private:
uint8_t values[100]; //from A to Z
  
};
