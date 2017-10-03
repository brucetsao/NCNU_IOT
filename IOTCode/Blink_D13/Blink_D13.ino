#define ButtonPin 7
#define LedPin1 13

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
 initPin() ;
  }

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
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
}

