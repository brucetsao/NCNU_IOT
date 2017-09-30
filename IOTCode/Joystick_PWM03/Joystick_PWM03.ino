#define VRX A1
#define VRY A2
#define LED1 11
#define LED2 12
int rx = 0 ;
int ry = 0 ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600) ;
  Serial.println("Program Start") ;
 }

void loop() {
  // put your main code here, to run repeatedly:
    rx = analogRead(VRX) ;
    ry = analogRead(VRY) ;
    
    Serial.print("Read X is :(") ;
    Serial.print(analogRead(VRX)) ;
    Serial.print(") \n") ;
    Serial.print("Read Y is :(") ;
    Serial.print(analogRead(VRY)) ;
    Serial.print(") \n") ;
    delay(300) ; 
}
