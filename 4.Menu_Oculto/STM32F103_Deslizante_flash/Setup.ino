void setup() {
  pinMode(res, OUTPUT); 
  pinMode(strobe, OUTPUT); 
  digitalWrite(res,LOW); 
  digitalWrite(strobe,HIGH);  
  GD.begin();
  lineabaseMSGEQ7();  //linea base en 0
  
  CargaAssetNuevo =1; MP();
}
void loop() {}
