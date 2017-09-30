void setup() {
  // put your setup code here, to run once:
      pinMode(13,OUTPUT) ;
      pinMode(7,INPUT);
 }

void loop() {
    if (digitalRead(7) == HIGH)
        {
            Serial.println("Button Pressed");
            digitalWrite(13,HIGH) ;
        }
        else
        {
            Serial.println("Button Released");
            digitalWrite(13,LOW) ;
        }
}

