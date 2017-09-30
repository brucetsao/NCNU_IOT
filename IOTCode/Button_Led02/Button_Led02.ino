void setup() {
  // put your setup code here, to run once:
      pinMode(13,OUTPUT) ;
      pinMode(7,INPUT);
 }

void loop() {
    if (digitalRead(7) == HIGH)
        {
            Serial.println("Pressed");
            digitalWrite(13,HIGH) ;
        }
}

