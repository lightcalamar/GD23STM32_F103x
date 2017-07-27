#include <SPI.h>
#include "SdFat.h"
#include <GD23STM32.h>

File archivo;
SdFat SD2(2);
const uint8_t SD2_CS = PB12;   // chip select for sd2

float xReloj = 600, yReloj =430, yValor;

void setup() {
 Serial.begin(9600);
 SD2.begin(SD2_CS, SD_SCK_MHZ(18));
 GD.begin();
  espera();
  archivo = SD2.open("Fn1.jpg");    
  GD.cmd_loadimage(0, 0);
  GD.loadSdFat(archivo);
}

float XLIzq=0, XLDer=XLIzq+799;
float YLS=380, YLI=YLS+99;
int Intensidad = 40;

void loop() {
  //GD.wr(REG_PWM_DUTY, Intensidad);
  GD.Clear();
   GD.Begin(BITMAPS);  
   GD.Vertex2ii(0, 0); 
  GD.get_inputs();  

  if(xReloj>=850){xReloj=-150;}

//Draw clock
 GD.cmd_bgcolor(0xff0000); //color de fondo
 GD.cmd_clock(xReloj,yReloj-yValor,40,OPT_FLAT,12,33,45,0);

  xReloj = xReloj+4;

   GD.ColorRGB(0x00ff00);  
   GD.LineWidth(1 * 16);
   GD.Begin(LINES);
   GD.Vertex2f(XLIzq * 16, (YLS-yValor)* 16);  GD.Vertex2f(XLDer* 16,  (YLS-yValor)* 16);
   GD.Vertex2f(XLIzq * 16, (YLI-yValor)* 16);  GD.Vertex2f(XLDer* 16,  (YLI-yValor)* 16);
   GD.Vertex2f(XLIzq * 16, (YLS-yValor)* 16);  GD.Vertex2f(XLIzq* 16,  (YLI-yValor)* 16);
   GD.Vertex2f(XLDer * 16, (YLS-yValor)* 16);  GD.Vertex2f(XLDer* 16,  (YLI-yValor)* 16);

   GD.ColorRGB(0xffffff);   GD.cmd_number(390, YLS-yValor, 28, OPT_RIGHTX | OPT_SIGNED, YLS-yValor);
   GD.ColorRGB(0xffffff);   GD.cmd_number(390, YLI-yValor-25, 28, OPT_RIGHTX | OPT_SIGNED, YLI-yValor);

   GD.cmd_text(GD.w / 2, YLI-yValor-450, 31, OPT_CENTER, "Menu superior");
   GD.cmd_text(GD.w / 2, YLI-yValor+350, 31, OPT_CENTER, "Menu inferior");

 GD.ColorA(0);  
  sliderH();
  sliderV();
 GD.ColorA(255);  
   
  GD.swap();
}
