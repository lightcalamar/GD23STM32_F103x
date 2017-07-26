//#include <EEPROM.h> 
#include <SPI.h>
#include <GD23STM32.h>

void setup()
{
  GD.begin();
}

void loop()
{
  GD.ClearColorRGB(0x000020);
  GD.Clear();
  GD.cmd_text(GD.w / 2, GD.h / 2, 31, OPT_CENTER, "Hello world");
  //GD.swap();
}
