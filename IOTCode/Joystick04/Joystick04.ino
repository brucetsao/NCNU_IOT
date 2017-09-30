#define VRX 1
#define VRY 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600) ;
  Serial.println("Program Start") ;
 }

void loop() {
  // put your main code here, to run repeatedly:
    Serial.print("Read X is :(") ;
    Serial.print(analogRead(VRX)) ;
    Serial.print(") \n") ;
    Serial.print("Read Y is :(") ;
    Serial.print(analogRead(VRY)) ;
    Serial.print(") \n") ;
     
}
