int i=0;

void setup()
{
  Wire.begin();


//   writeEEPROM(disk1, 10, 54);        //guarda 54 en dirección 10 de la EEPROM
//   writeEEPROM(disk1, 2500, 123);     //guarda 123 en dirección 2500 de la EEPROM   

//Borra calibración
//  LimpiaCal();

  

  GD.begin();
  
  //GD.self_calibrate();
  MPCal();
}


void LimpiaCal()
{
   for(i=0; i<26; i+=1) {
     writeEEPROM(disk1, i, 0);     //guarda 123 en dirección 2500 de la EEPROM
   }  
}


void LimpiaManual()
{


   writeEEPROM(disk1, 0, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 1, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 2, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 3, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 4, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 5, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 6, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 7, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 8, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 9, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 10, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 11, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 12, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 13, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 14, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 15, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 16, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 17, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 18, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 19, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 20, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 21, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 22, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 23, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 24, 0);        //guarda 54 en dirección 10 de la EEPROM
   writeEEPROM(disk1, 25, 0);        //guarda 54 en dirección 10 de la EEPROM  
}



void loop(){}

