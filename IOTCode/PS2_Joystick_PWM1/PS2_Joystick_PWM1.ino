#define VRX A0
#define VRY A2
#define Led1 13
#define Led2 12

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600) ;
    Serial.println("Progarm Star") ;
    


}

void loop() {
  // put your main code here, to run repeatedly:
      int Xvalue =0 ; 
      int Yvalue = 0 ;
      Xvalue = analogRead(VRX) ;
      Yvalue = analogRead(VRY) ;
   Serial.print("The X POS is :(") ;
    Serial.print(Xvalue) ;
     Serial.print(") , ") ;
     Serial.print("The T POS is :(") ;
    Serial.print(Yvalue) ;
     Serial.print(") \n") ;
     analogWrite(Led1,map(Xvalue,0,1023,0,255) ;

   delay(30) ;
}
