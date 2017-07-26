//prog_uchar        IDE versión anterior, generada por EVE editor  V1.17
//unsigned char     IDE nuevas versiones
//http://forum.arduino.cc/index.php?topic=261093.0

#include <SPI.h>
#include <GD23STM32.h>

#define RAM_ALGER 0

static const PROGMEM unsigned char ALGER[] = {
  #include "ALGER.h"
};

#define RAM_TUFFY_BOLD_ITALIC 96668

static const PROGMEM unsigned char Tuffy_Bold_Italic[] = {
  #include "Tuffy_Bold_Italic.h"
};

#define RAM_RAD1A 131868

static const PROGMEM unsigned char Rad1a[] = {
  #include "Rad1a.h"
};

#define RAM_BATX1 156068

static const PROGMEM unsigned char BatX1[] = {
  #include "BatX1.h"
};

#define RAM_C1A 194468

static const PROGMEM unsigned char C1a[] = {
  #include "C1a.h"
};

#define RAM_C2A 225368

static const PROGMEM unsigned char C2a[] = {
  #include "C2a.h"
};

void setup()
{
  GD.begin();
  MP();
}


void loop(){}

void EncabezadoMP()
{
  GD.cmd_inflate(RAM_ALGER);
  GD.copy(ALGER, sizeof(ALGER));
  GD.cmd_inflate(RAM_TUFFY_BOLD_ITALIC);
  GD.copy(Tuffy_Bold_Italic, sizeof(Tuffy_Bold_Italic));
  GD.cmd_inflate(RAM_RAD1A);
  GD.copy(Rad1a, sizeof(Rad1a));
  GD.cmd_inflate(RAM_BATX1);
  GD.copy(BatX1, sizeof(BatX1));
  GD.cmd_inflate(RAM_C1A);
  GD.copy(C1a, sizeof(C1a));
  GD.cmd_inflate(RAM_C2A);
  GD.copy(C2a, sizeof(C2a));
  GD.BitmapHandle(0);
  GD.BitmapSource(148);
  GD.BitmapLayout(L4, 20, 38);
  GD.BitmapSize(NEAREST, BORDER, BORDER, 40, 38);
  GD.cmd_setfont(0, 0);
  GD.BitmapHandle(1);
  GD.BitmapSource(96816);
  GD.BitmapLayout(L4, 12, 23);
  GD.BitmapSize(NEAREST, BORDER, BORDER, 24, 23);
  GD.cmd_setfont(1, 96668);
  GD.BitmapHandle(2);
  GD.BitmapSource(131868);
  GD.BitmapLayout(ARGB1555, 220, 110);
  GD.BitmapSize(NEAREST, BORDER, BORDER, 110, 110);
  GD.BitmapHandle(3);
  GD.BitmapSource(156068);
  GD.BitmapLayout(ARGB1555, 384, 100);
  GD.BitmapSize(NEAREST, BORDER, BORDER, 192, 100);
  GD.BitmapHandle(4);
  GD.BitmapSource(194468);
  GD.BitmapLayout(ARGB1555, 206, 150);
  GD.BitmapSize(NEAREST, BORDER, BORDER, 103, 150);
  GD.BitmapHandle(5);
  GD.BitmapSource(225368);
  GD.BitmapLayout(ARGB1555, 206, 150);
  GD.BitmapSize(NEAREST, BORDER, BORDER, 103, 150);
}


void MP()
{
  EncabezadoMP();
  while(1)
  {
  GD.ClearColorRGB(31, 63, 127);
  GD.Clear(1, 1, 1);
  
  GD.Begin(BITMAPS);
  GD.Vertex2ii(122, 56, 5, 0);
  GD.End();
  
  GD.Begin(BITMAPS);
  GD.Vertex2ii(349, 5, 2, 0);
  GD.End();
  
  GD.Begin(BITMAPS);
  GD.Vertex2ii(294, 12, 3, 0);
  GD.End();
  
  GD.Begin(BITMAPS);
  GD.Vertex2ii(12, 58, 4, 0);
  GD.End();
  
  GD.cmd_fgcolor(16744255);
  GD.cmd_button(26, 217, 120, 36, 27, 0, "Button");
  GD.cmd_button(158, 217, 120, 36, 27, 0, "Button");
  
  GD.cmd_text(12, 12, 0, 0, "Bateria");
  GD.cmd_text(322, 51, 1, 0, "FT8XX en linea");
  GD.cmd_gauge(339, 158, 36, 0, 4, 8, 40, 100);
  GD.cmd_gauge(431, 158, 36, 0, 4, 8, 40, 100);
  GD.cmd_clock(386, 229, 36, 0, 13, 51, 17, 0);
  GD.cmd_dial(263, 63, 36, 0, 6144);

  STM32();
  GD.swap();
  }
}

extern "C" char* sbrk(int incr);
float freeRam() {
  char top;
  return &top - reinterpret_cast<char*>(sbrk(0));
}

char TX[50];
//int RAM = 65536;   //F103ZET6
int RAM = 131072;   //F407ZGT6

void STM32()
{
  GD.ColorRGB(0x00ff00); sprintf(TX,"F_CPU: %d MHz", (F_CPU/1000000));  GD.cmd_text(GD.w - 105, 0, 26, 0, TX);
 
  float RAMFree = (freeRam()/1)*100/RAM;   
  int RAMUsed= 100-RAMFree;
 
  GD.ColorRGB(0x00ff00); sprintf(TX,"RAM: %d/%d", RAMUsed,100);  GD.cmd_text(GD.w - 105, 20, 26, 0, TX);
}
