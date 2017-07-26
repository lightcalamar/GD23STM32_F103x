#include "NGf407.h"  //ASSETSNG()  números grandes
#include "AV3.h"




void MP()
{
  if(CargaAssetNuevo==1){LOAD_ASSETSAV3();  CargaAssetNuevo =0;}
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
       if (GD.inputs.tag==3){delay(135);  Analizador(); CargaAssetNuevo =0;}

    
    
    GD.swap();
  }
}
