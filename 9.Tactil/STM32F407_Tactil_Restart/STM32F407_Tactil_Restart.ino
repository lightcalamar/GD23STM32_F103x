#include <AT24Cxx.h>

#include <SPI.h>
#include <GD23STM32.h>

#define i2c_address 0x57  //EEPROM on DS3231
AT24Cxx eep(i2c_address, 32);

char Valor[20];

int Mensaje=0, PY=0;

void setup() {
   GD.begin();
   BorraCal();
}

void loop() {}

void BorraCal()
{
  while(1)
  {
    GD.ClearColorRGB(127, 124, 28);
    GD.Clear(1, 1, 1);
    for (int i = 0 ; i <= 25 ; i++) {
      eep.update(i, 0x00);
      sprintf(Valor, "Adress %04d : %03d", i, eep.read(i)); 
      GD.ColorRGB(0xffffff);   GD.cmd_text(65, 5+(PY*11), 26, OPT_CENTER, Valor);
      PY=i;
      if(i>=24){Mensaje=1;}
    }
   
   if(Mensaje==1){GD.ColorRGB(0x00ff00);  GD.cmd_text(300, GD.h/2, 28, OPT_CENTER, "CALIBRACION REINICIADA");}
   GD.swap();
  }
}

