void readMSGEQ7()
{
 digitalWrite(res, HIGH);
 digitalWrite(res, LOW);
 for(band=0; band <7; band++)
 {
  digitalWrite(strobe,LOW); 
  delayMicroseconds(30);  
  //leftS[band] = analogRead(PC2)-35;
  //leftS[band] = analogRead(PC2)-80;   //STMCoreGeneric
  leftS[band] = (analogRead(PC2)/3.8)-90; //STMCoreOficial
  digitalWrite(strobe,HIGH); 
 }
}

void lineabaseMSGEQ7()
{
  for (int k=0; k<maxlecturas; k++)
      {
        lectura0[k] = 0;
        lectura1[k] = 0;
        lectura2[k] = 0;
        lectura3[k] = 0;
        lectura4[k] = 0;
        lectura5[k] = 0;
        lectura6[k] = 0;
      }        
  k = maxlecturas;  // al salir de la linea base siempre será i = maxlecturas  
}

int DeltaX=2, DeltaY=-2;
//float DeltaZ=-0.1;

int CTE=0, DeltaZ;

int SFreq=0, Freq63=0, Freq160, Freq400, Freq1000, Freq2500, Freq6250, Freq16000;

void Analizador()
{
  if(CargaAssetNuevo==1){ }
  while(1) {
   //GD.wr(REG_PWM_DUTY, Intensidad);  //0-128
   GD.ClearColorRGB(0x000020);
   GD.Clear();
   GD.get_inputs();

   GD.SaveContext();
     STM32();
   GD.RestoreContext();

   separacion=Divisor*escala;   //separación entre dos puntos de la gráfica
   claroXY = 10*escala;
   RectWidth = (maxlecturas*separacion);
   RectHeight = 10*claroXY;
  
// Diseño de marco para gráfica
   GD.ColorA(255); //color solido      
   GD.ColorRGB(0x202020);
   GD.LineWidth(1 * 16);
   GD.Begin(RECTS);

   GD.ColorA(60); //transparencia
   GD.ColorRGB(0x00ff00);  
   GD.LineWidth(1 * 16);
   GD.Begin(LINES);
     marcadoresverticales();
     marcadoreshorizontales();
// Diseño de marco para gráfica

//Gráfica lineal
   readMSGEQ7();
   GD.ColorA(75); Arraydatos2();
   GD.ColorA(255); 
      if(Freq63==1){Baseactual0();}
     if(Freq160==1){Baseactual1();}
     if(Freq400==1){Baseactual2();}     //  Gráfica lineal   
    if(Freq1000==1){Baseactual3();}
    if(Freq2500==1){Baseactual4();}
    if(Freq6250==1){Baseactual5();}
   if(Freq16000==1){Baseactual6();}
   
   barrasVSegmentadas(225, 185);  
//Gráfica lineal   

   GD.Tag(200);  GD.cmd_button(5, 50, 120, 40, 26, 0,  " ");        GD.Tag(255);
   if (GD.inputs.tag==200)
     {
       XGT=140; YGT=210;   
     }


   GD.Tag(201);  GD.cmd_button(5, 100, 120, 40, 26, 0,  "MP");        GD.Tag(255);
   if (GD.inputs.tag==201)
     {
      CargaAssetNuevo=1; Xbase=0; Avance=1;  Velocidad=5; PIx=0; velP=-5; AvanceC=1;  espera();  MP();  //evita la recarga de asset siempre y cuando no se haya cargado otro en este menu 
     }


   GD.Tag(202);  GD.cmd_button(5, 150, 120, 40, 26, 0,  "Freq");        GD.Tag(255);
   if (GD.inputs.tag==202)
     {
       delay(135);
       SFreq= SFreq+1;
       if(SFreq>=2){SFreq=0;}
     }
   

   GD.Tag(224);  GD.cmd_button(5, 5, 50, 35, 26, 0,  "GY");        GD.Tag(255);
   if (GD.inputs.tag==224)
     {
       YGT=YGT+DeltaY;
       if(YGT<=0){DeltaY=2;}
       if(YGT>=225){DeltaY=-2;}
     }

   GD.Tag(225);  GD.cmd_button(75, 5, 50, 35, 26, 0,  "GX");        GD.Tag(255);
   if (GD.inputs.tag==225)
     {
       XGT=XGT+DeltaX;
       if(XGT<=10){DeltaX=2;}
       if(XGT>=270){DeltaX=-2;}
     }
  if(SFreq==1)
  {
    GD.SaveContext();
    GD.ColorRGB(0,0xaa,0);        GD.Tag(105);  GD.cmd_button(700, 5, 70, 35, 26, 0,       "63 Hz");      GD.Tag(255);
    GD.ColorRGB(0x00,0xff,0x00);  GD.Tag(106);  GD.cmd_button(700, 45, 70, 35, 26, 0,     "160 Hz");      GD.Tag(255);
    GD.ColorRGB(0xFF,0xff,0x00);  GD.Tag(107);  GD.cmd_button(700, 85, 70, 35, 26, 0,     "400 Hz");      GD.Tag(255);
    GD.ColorRGB(0xff,0x00,0xff);  GD.Tag(108);  GD.cmd_button(700, 125, 70, 35, 26, 0,   "1000 Hz");      GD.Tag(255);
    GD.ColorRGB(0x00,0xff,0xff);  GD.Tag(109);  GD.cmd_button(700, 165, 70, 35, 26, 0,   "2500 Hz");      GD.Tag(255);
    GD.ColorRGB(0xff,0x00,0x00);  GD.Tag(110);  GD.cmd_button(700, 205, 70, 35, 26, 0,   "6250 Hz");      GD.Tag(255);
    GD.ColorRGB(0xFF,0xff,0xff);  GD.Tag(111);  GD.cmd_button(700, 245, 70, 35, 26, 0,  "16000 Hz");      GD.Tag(255);
    GD.RestoreContext();
  }
  //GD.ColorRGB(0xffff00);   GD.cmd_number(PX-50, 40, 28, OPT_RIGHTX | OPT_SIGNED, XGT);
  //GD.ColorRGB(0xffff00);   GD.cmd_number(PX, 40, 28, OPT_RIGHTX | OPT_SIGNED, YGT);
  
  if (GD.inputs.tag==105)
     {
      delay(135);
       Freq63=Freq63+1;
       if(Freq63>=2){Freq63=0;}
     }

  if (GD.inputs.tag==106)
     {
      delay(135);
       Freq160=Freq160+1;
       if(Freq160>=2){Freq160=0;}
     }

  if (GD.inputs.tag==107)
     {
      delay(135);
       Freq400=Freq400+1;
       if(Freq400>=2){Freq400=0;}
     }

  if (GD.inputs.tag==108)
     {
      delay(135);
       Freq1000=Freq1000+1;
       if(Freq1000>=2){Freq1000=0;}
     }

  if (GD.inputs.tag==109)
     {
      delay(135);
       Freq2500=Freq2500+1;
       if(Freq2500>=2){Freq2500=0;}
     }

  if (GD.inputs.tag==110)
     {
      delay(135);
       Freq6250=Freq6250+1;
       if(Freq6250>=2){Freq6250=0;}
     }

  if (GD.inputs.tag==111)
     {
      delay(135);
       Freq16000=Freq16000+1;
       if(Freq16000>=2){Freq16000=0;}
     }          

   
   FT8XXLOGO();


//Cortina

  Cortina();

  //GD.cmd_number(110, 350, 28, OPT_RIGHTX | OPT_SIGNED, PIx); 
  //GD.cmd_number(110, 390, 28, OPT_RIGHTX | OPT_SIGNED, AvanceC); 
  //GD.cmd_number(110, 430, 28, OPT_RIGHTX | OPT_SIGNED, velP);

//Cortina


   
   
  GD.swap();}  
}


void barrasVSegmentadas(int xi, int yi)
{
  GD.ColorA(115); //transparencia     75
  GD.ColorRGB(255,255,255);   //Color del texto
  GD.cmd_text(xi, yi+7, 16, 0, " 63          400   1000  2500  6250  16000 Hz");   GD.cmd_text(402, 10, 28, OPT_CENTER, "Quad-MSGEQ7");
  GD.cmd_text(xi+54, yi+7, 16, 0, "160");        
    
  GD.ColorA(255);
  GD.Begin(LINES);
  GD.LineWidth(35);
  GD.ColorRGB(0xffffff);   //color de los segmentos

    for (int j = 0; j < band; j++) 
      { 
      int dato = map(leftS[j], 0, 1023, 0, segmentos);
      for (int i = 0; i < dato; i++) 
        { 
          GD.Vertex2f((xi+(j*largoX+j*sepX))*16, (yi - (i*sepY))*16); // inicio
          GD.Vertex2f((xi+((j+1)*largoX+j*sepX))*16, (yi - (i*sepY))*16); //  fin   
        }
      }  
}

void marcadoresverticales()
{
//  for (int k=0; k<15; k++)
  for (int k=0; k<=(RectWidth/claroXY); k++)
   {    
     GD.Vertex2f((XGT+(k*claroXY)) * 16, YGT* 16);  //starting coordinates
     GD.Vertex2f((XGT+(k*claroXY)) * 16, (YGT+RectHeight) * 16);  //ending coordinates
   }  
}

void marcadoreshorizontales()
{
  for (int k=0; k<=(RectHeight/claroXY); k++)
   {    
    GD.Vertex2f((XGT) * 16, (YGT+(k*claroXY))* 16);  //starting coordinates
    GD.Vertex2f((XGT+RectWidth) * 16, (YGT+(k*claroXY)) * 16);  //ending coordinates  140
   }     
}
