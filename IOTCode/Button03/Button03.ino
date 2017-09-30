void setup() {
  // put your setup code here, to run once:
      pinMode(7,INPUT);
      Serial.begin(9600);
      Serial.println("Program Start");
}

void loop() {
    if (digitalRead(7) == HIGH)
        {
            Serial.println("Pressed");
        }
}
