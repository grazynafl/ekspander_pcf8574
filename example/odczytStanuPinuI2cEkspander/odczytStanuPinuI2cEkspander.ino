/*
 * Andrzej Pacholik, Wrocław, 26.09.2018
 * 
 * Skryp do odczytu stanu pinu P5 na układzie PCF8574 podłączone poprzez magistralę I2C.
 * 
 */
#include "expander_pcf8574.h"

//expander_pcf8574 expander1(33); // Jeżeli układ PCF8574 jest na innym adresie niż 0x20 (32) należy go podać przy tworzeniu zmiennej
expander_pcf8574 expander1;

void setup() {
  Serial.begin(9600);
  expander1.rawZapis(0); //ustawia wszytkie piny na LOW
}

void loop() {
  if (expander1.cyfrowyOdczyt(5)) {
    Serial.println("Stan WYSOKI na 5-tym pinie");
  } else {
    Serial.println("Stan NISKI na 5-tym pinie");
  }
  delay(5000);
}
