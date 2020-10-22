#include <Keyboard.h>

//Serial input to keyboard output
//Arduino emulates HID. Useful to bypass "fake-keyboard" detection

void setup() {
  // open the serial port:
  Serial.begin(9600);
  // initialize control over the keyboard after 10 seconds:
  delay(10000);
  Keyboard.begin();
}

void loop() {
  // check for incoming serial data:
  if (Serial.available() > 0) {
    // read incoming serial data:
    char inChar = Serial.read();
    delay(10);
    // Type the next ASCII value from what you received:
    Serial.print("Outputting ");
    Serial.print(inChar);
    Serial.println(" now...");
    Keyboard.write(inChar);
  }
}
