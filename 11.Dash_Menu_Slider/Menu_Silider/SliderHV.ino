#define Seguidor1  201
#define Seguidor2  202

int PX=350, PXS=100, PYS=35;
float Valor1=125,  Valor2=0;

void sliderH()
{
//Horizontal
  GD.SaveContext();
  GD.Tag(Seguidor1);
  GD.cmd_fgcolor(0xff0000);                          //color del deslizador
  GD.ColorRGB(0x000000);  GD.cmd_bgcolor(0x000000); //color de la base

  GD.cmd_slider(PXS,95,200,20,OPT_FLAT,Valor1,255);
  //            x,   y,  largo, espesor, tag a seguir 
  GD.cmd_track( PXS,95,200,20,Seguidor1);

  switch (GD.inputs.track_tag & 0xff) {
  case Seguidor1:
    Valor1 = GD.inputs.track_val * 255L / 65535;    //Horizontal
    Serial.println(Valor1);
    break;
    }
  GD.RestoreContext();
//Horizontal
}

float PXSliderV=YLS;

void sliderV()
{
//Vertical
  GD.SaveContext();  
  GD.Tag(Seguidor2);  
  GD.cmd_fgcolor(0x00ff00);                         //color del deslizador
  GD.ColorRGB(0x000000);  GD.cmd_bgcolor(0x000000); //color de la base

  //             x,  y, largo, espesor, tag a seguir 
  GD.cmd_slider(30,50,40,PXSliderV,OPT_FLAT,PXSliderV-Valor2,PXSliderV);
  GD.cmd_track( 30,50,40,PXSliderV,Seguidor2);

  switch (GD.inputs.track_tag & 0xff) {
  case Seguidor2:
    Valor2 = PXSliderV-(GD.inputs.track_val * PXSliderV / 65535);    //Vertical
    yValor=Valor2;
    Serial.println(Valor2);
    break;    
   }
  GD.RestoreContext();
//Vertical
  
  GD.ColorRGB(0xffffff);   GD.cmd_number(PX, 10+10+50, 28, OPT_RIGHTX | OPT_SIGNED, Valor1); 
  GD.ColorRGB(0xffffff);   GD.cmd_number(100, 400, 28, OPT_RIGHTX | OPT_SIGNED, Valor2);
}
