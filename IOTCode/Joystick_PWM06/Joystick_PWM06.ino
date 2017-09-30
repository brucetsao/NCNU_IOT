#define VRX A1
#define VRY A2
#define LED1 11
#define LED2 12
int rx = 0 ;
int ry = 0 ;
int rxPWM = 0 ;
int ryPWM = 0 ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600) ;
  Serial.println("Program Start") ;
 }

void loop() {
  // put your main code here, to run repeatedly:
    rx = analogRead(VRX) ;
    ry = analogRead(VRY) ;
    rxPWM = map(rx,0,1023,0,255) ;
    ryPWM = map(ry,0,1023,0,255) ;
    
    Serial.print("Read X is :(") ;
    Serial.print(rx) ;
    Serial.print(") \n") ;
    Serial.print("Read Y is :(") ;
    Serial.print(ry) ;
    Serial.print(") \n") ;
    analogWrite(LED1,rxPWM) ;
    analogWrite(LED2,ryPWM) ;
    
    delay(300) ; 
}
