#include <SPI.h>
#include <GD23STM32.h>

void setup()
{
  GD.begin();


  GD.cmd_loadimage(0, 0);
  GD.load("tree.jpg");
}

void loop()
{

  
//  GD.ClearColorRGB(0x002000);
//  GD.Clear();
//  GD.cmd_text(GD.w / 2, GD.h / 2, 31, OPT_CENTER, "Hello world"); 

//  delay(3000);
  
  GD.Clear();
  GD.Begin(BITMAPS);
  GD.Vertex2ii(0, 0);
  GD.swap();
}

