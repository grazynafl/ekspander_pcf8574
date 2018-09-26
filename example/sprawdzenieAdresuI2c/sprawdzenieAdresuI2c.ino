/*
 *  Andrzej Pacholik, Wrocław, 26.09.2018 
 *  
 *  Prosty skrypt, który ma sprawdzić czy na podanym adresie I2C znajduje się 'coś'.
 *  
 *  Układ PCF8574 jeżeli piny oznaczone A0, A1 i A2 są podłączone do GND ma adres 0x20 (czyli w dziesiętnym 32)
 *  
 *  Jest 5 możliwości wyniku:
 *  0:success
 *  1: dane zbyt długie, aby zmieściły się w buforze nadawczym
 *  2: otrzymał NACK* przy transmisji adresu
 *  3: otrzymał NACK* przy transmisji danych
 *  4: inny błąd
 *  [https://www.arduino.cc/en/Reference/WireEndTransmission]
 *  
 *  
 *  * - https://arduino.stackexchange.com/questions/21850/what-does-it-mean-in-i2c-nack-received
 */

#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  while (!Serial);
  //Sprawdzenie czy jest podlaczony pod adres
  Wire.beginTransmission(32);
  byte blad;
  blad = Wire.endTransmission();
  Serial.print("Czy jest (0 - tak): ");
  Serial.println(blad,HEX);
}

void loop() {

}
