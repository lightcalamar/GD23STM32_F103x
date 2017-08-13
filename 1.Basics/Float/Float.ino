#include <SPI.h>
#include <GD23STM32.h>

void setup()
{
  GD.begin();
}

float latitud, latitudint, latituddec;
float longitud, longitudint, longituddec;

void loop()
{
  GD.ClearColorRGB(0x000020);
  GD.Clear();

  latitudint = random(35,45);
  latituddec=  random(9999);
  latitud = ((latitudint*10000)+latituddec)/10000;

  GD.cmd_text(100, 100, 31, 0, "latitud:");
   GD.printNfloat(325, 100, latitud, 5, 31);

  longitudint = random(1,5);
  longituddec=  random(9999);
  longitud = ((longitudint*10000)+longituddec)/10000;

  GD.cmd_text(100, 150, 31, 0, "longitud:");
   GD.printNfloat(325, 150, longitud, 5, 31);

  delay(1000);
  GD.swap();
}
