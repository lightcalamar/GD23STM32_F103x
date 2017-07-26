int Mensaje=0;

void MPCal()
{
  LimpiaCal();
  GD.self_calibrate();
  while(1)
  {
    GD.ClearColorRGB(127, 124, 28);
    GD.Clear(1, 1, 1);
    GD.get_inputs();


   


    GD.Tag(1);    GD.cmd_button(GD.w/2-(100/2), 105, 100, 100, 31, 0,  "Test");  GD.Tag(255);  
    if (GD.inputs.tag==1){
       delay(145);
       Mensaje=Mensaje+1;  
       if(Mensaje>=2){Mensaje=0;}
      }
    
    if(Mensaje==1){GD.ColorRGB(0x00ff00);  GD.cmd_text(GD.w/2, GD.h/2, 28, OPT_CENTER, "CALIBRACION REINICIADA");}


    STM32();
    
    GD.swap();
  }
}
