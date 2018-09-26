/*
 * Andrzej Pacholik, Wrocław, 26.09.2018
 * 
 * Kod mryga diodą LED, która jest podłaczona do pinu P2 w układzie PCF8574 poprzez magistrale I2C
 * 
 */
#include <expander_pcf8574.h>

//expander_pcf8574 expander1(33); // Jeżeli układ PCF8574 jest na innym adresie niż 0x20 (32) należy go podać przy tworzeniu zmiennej
expander_pcf8574 expander1;

void setup() {
  expander1.rawZapis(0); //ustawia wszytkie piny na LOW
}

void loop() {
  expander1.cyfrowyZapis(2, HIGH);
  delay(5000);
  expander1.cyfrowyZapis(2, LOW);
  delay(5000);
}
