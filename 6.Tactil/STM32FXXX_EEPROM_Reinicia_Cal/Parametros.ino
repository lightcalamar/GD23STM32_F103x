extern "C" char* sbrk(int incr);
float freeRam() {
  char top;
  return &top - reinterpret_cast<char*>(sbrk(0));
}

char TXP[50];

void STM32()
{
  GD.ColorRGB(0x00ff00); sprintf(TXP,"F_CPU: %d MHz", (F_CPU/1000000));  GD.cmd_text(GD.w - 105, 5, 26, 0, TXP);
 
  float RAMFree = (freeRam()/1)*100/ST_RAM;   
  int RAMUsed= 100-RAMFree;
 
  GD.ColorRGB(0x00ff00); sprintf(TXP,"RAM: %d/%d", RAMUsed,100);  GD.cmd_text(GD.w - 105, 25, 26, 0, TXP);
}
