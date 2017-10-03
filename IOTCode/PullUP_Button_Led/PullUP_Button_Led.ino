#define ButtonPin 7
#define LedPin1 13

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
        initPin() ;
   }

// the loop function runs over and over again forever
void loop() {
    if (digitalRead(ButtonPin) == LOW)
        {
            Serial.println("Button is pressed") ;
            digitalWrite(LedPin1,HIGH) ;
        }
        else
        {
            Serial.println("Button is released") ;
            digitalWrite(LedPin1,LOW) ;
        }        
    
 
  delay(1000);                       // wait for a second
}
void initPin()
{
  // input
   pinMode(ButtonPin, INPUT);
   //----- output
   pinMode(LedPin1, OUTPUT);
// default 
   digitalWrite(LedPin1,LOW) ;
Serial.begin(9600) ;
Serial.println("Program Start") ;
   
}

