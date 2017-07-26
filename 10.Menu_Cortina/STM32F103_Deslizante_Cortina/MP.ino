void MP()
{
  if(CargaAssetNuevo==1){
    AV3 = Sd2.open(STRAsset2);
    LOAD_ASSETS2();  
    CargaAssetNuevo =0;}
  while(1)
  {
    GD.get_inputs();
    GD.Clear();
    
    GD.Begin(BITMAPS);
       GD.Vertex2ii(0, 0, 0);

     if(Avance==1)
       { 
         Xbase=Xbase+Velocidad;
         if(Xbase>=290){Avance=0;}
       }

      if(Avance==2)
       { 
         Xbase=Xbase+Velocidad;
         if(Xbase<=0){Avance=0;}
       }       
       GD.End();
         FT8XXLOGO();
         GD.SaveContext();
           STM32();
         GD.RestoreContext();

       GD.Begin(BITMAPS);
       
       GD.SaveContext();
         GD.VertexTranslateX(16*520);
         GD.Tag(2);  GD.Vertex2ii(0, 150, 5);  GD.Tag(255);
         GD.Tag(3);  GD.Vertex2ii(35, 320, 4);  GD.Tag(255);  
       GD.RestoreContext();
       
       GD.SaveContext();
       
         GD.VertexTranslateX(16*Xbase);
         GD.Tag(1);  GD.Vertex2ii(510, 0, 1);  GD.Tag(255);
       GD.RestoreContext();

       if (GD.inputs.tag==1){delay(135);  Avance=1;  Velocidad=5;}
       if (GD.inputs.tag==2){delay(135);  Avance=2;  Velocidad=-5;}
       if (GD.inputs.tag==3){delay(135); PIx=0; velP=-5; AvanceC=1;   Analizador(); CargaAssetNuevo =0;}

//Cortina

 if (GD.inputs.tag==210)
    { 
      delay(105);  
      AvanceC=AvanceC+1;
      if(AvanceC==1){velP=-5;}
      if(AvanceC==2){velP=5;  AvanceC=0;}
    }

 Cortina();

 GD.Tag(210);   
  //GD.cmd_number(110, 350, 28, OPT_RIGHTX | OPT_SIGNED, PIx); 
  //GD.cmd_number(110, 390, 28, OPT_RIGHTX | OPT_SIGNED, AvanceC); 
  //GD.cmd_number(110, 430, 28, OPT_RIGHTX | OPT_SIGNED, velP);

  GD.ColorA(0);
   GD.ColorRGB(0xffff00);   GD.LineWidth(1 * 16);
   GD.Begin(RECTS);
   GD.Vertex2f(0*16, 0*16); GD.Vertex2f(512*16,480*16);
  GD.ColorA(255);
 GD.Tag(255); 

//Cortina
    
    GD.swap();
  }
}
