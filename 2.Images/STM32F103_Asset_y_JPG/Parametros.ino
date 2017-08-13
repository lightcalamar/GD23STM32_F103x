char TXP[50];

void STM32()
{
  GD.ColorRGB(0x00ff00); sprintf(TXP,"F_CPU: %d MHz", (F_CPU/1000000));  GD.cmd_text(GD.w - 105, 0, 26, 0, TXP);
  GD.ColorRGB(0x00ff00); sprintf(TXP,"F_SDIO:  %d MHz", (FreqSDIO/1000000));  GD.cmd_text(GD.w - 105, 20, 26, 0, TXP);
}
