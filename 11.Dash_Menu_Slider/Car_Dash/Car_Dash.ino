#include <SPI.h>
#include "SdFat.h"
#include <GD23STM32.h>
#include "Ic1.h"

SdFat Sd2(2);
const uint8_t SD2_CS = PB12;   // chip select for sd2

//Asset 1
char asset1[] = "Ic1.gd2";  File Dash;
String Icon1(asset1);
//Asset 1

void setup() {
  GD.begin();
  Sd2.begin(SD2_CS, SD_SCK_MHZ(18));

  Dash = Sd2.open(Icon1);
  LOAD_ASSETS();
}

int PXL=-390, PXD=400-PXL, SpeedX=40, XMov=1;

void loop() {
  GD.Clear();  
   GD.Begin(BITMAPS);

   if(XMov==1){
               PXL=PXL+SpeedX;
               PXD=400-PXL;
               if(PXL>=0){XMov=0;}
               }

  GD.SaveContext();
    GD.VertexTranslateX(16*PXL);
    GD.Vertex2ii(0, 0, 12);      //left panel
    GD.Vertex2ii(360, 170, 0);
    GD.SaveContext(); GD.ColorRGB(255,0,0);  GD.Vertex2ii(390, 110, 9);   GD.RestoreContext();
    GD.SaveContext(); GD.ColorRGB(0,15,255);  GD.Vertex2ii(390, 340, 10);   GD.RestoreContext();
    GD.SaveContext(); GD.ColorRGB(0,255,0);  GD.Vertex2ii(260, 215, 11);   GD.RestoreContext();    
  GD.RestoreContext();
   
  GD.SaveContext();
    GD.VertexTranslateX(16*PXD);
    GD.Vertex2ii(0, 0, 13);      //right panel
  GD.RestoreContext();

 GD.swap();
}
