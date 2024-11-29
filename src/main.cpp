#include <Arduino.h>
#include <SoftwareSerial.h>

void setup() {
  Serial.begin(9600);       // Giao tiếp với máy tính
  Serial1.begin(9600);      // Giao tiếp với ESP8266 (qua Serial1)
  pinMode(22, INPUT);
}

void loop() {
  int IrValue = digitalRead(22);
  String message = (IrValue == LOW) ? "Co vat can\n" : "Khong co vat can\n";
  Serial1.print(message);

  Serial.print("IR Sensor: ");
  Serial.println((IrValue == LOW) ? "Obstacle detected" : "No obstacle");
  delay(1000);
  if (Serial1.available())
  {
    String response = Serial1.readStringUntil('\n');
    Serial.println(response + "\n");
  }
  
}
