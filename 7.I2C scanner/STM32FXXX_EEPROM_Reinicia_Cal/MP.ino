char NumeroE[20];
unsigned int address1=10, address2=2500;

void MP()
{
  while(1)
  {
    //GD.wr(REG_PWM_DUTY, 10);  //0-128  intensidad de la retroiluminación XD
    GD.ClearColorRGB(127, 124, 28);
    GD.Clear(1, 1, 1);
    GD.get_inputs();

      sprintf(NumeroE, "Adress %04d : %03d", 5, readEEPROM(disk1, 5)); 
      GD.ColorRGB(0xffffff);   GD.cmd_text(250, 50, 31, OPT_CENTER, NumeroE);
    
      sprintf(NumeroE, "Adress %04d : %03d", address1, readEEPROM(disk1, address1)); 
      GD.ColorRGB(0xffffff);   GD.cmd_text(250, 100, 31, OPT_CENTER, NumeroE);
      
      sprintf(NumeroE, "Adress %04d : %03d", address2, readEEPROM(disk1, address2)); 
      GD.ColorRGB(0xffffff);   GD.cmd_text(250, 150, 31, OPT_CENTER, NumeroE);

      sprintf(NumeroE, "EEPROM 0x%X", disk1); 
      GD.ColorRGB(0xffffff);   GD.cmd_text(250, 200, 31, OPT_CENTER, NumeroE);
    GD.swap();
  }
}

