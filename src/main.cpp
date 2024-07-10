#include <Arduino.h>
#include <driver/dac.h>

#define DAC_CH1 25

int LED = LED_BUILTIN;
float incomingBytes;
float decodedBytes;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(10);
  //dac_output_enable(DAC_CHANNEL_1);
  
}

void loop() {
  if (Serial.available() > 0) {
    incomingBytes = Serial.read();
    decodedBytes = incomingBytes - '0';
  }

  if (decodedBytes > 0){
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }
  Serial.println(incomingBytes);
  Serial.println(decodedBytes);

  dacWrite(DAC_CH1, (decodedBytes/3.3) * 255);

  //dacWrite(DAC_CH1, 255);
  delay(10);
}
