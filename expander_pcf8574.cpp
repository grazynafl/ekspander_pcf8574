#include <Wire.h>
#include "expander_pcf8574.h"
#define byte unsigned char

expander_pcf8574::expander_pcf8574() {
  Wire.begin();
  _adres = 32;
  rawZapis((byte) 0);
}

expander_pcf8574::expander_pcf8574(int adres) {
  Wire.begin();
  _adres = adres;
  rawZapis((byte) 0);
}

byte expander_pcf8574::pobierzPin(int pin) {
  byte zwracanaWartosc = 0;
  switch (pin) {
    case 0: zwracanaWartosc = zwracanaWartosc | 1; break;
    case 1: zwracanaWartosc = zwracanaWartosc | 2; break;
    case 2: zwracanaWartosc = zwracanaWartosc | 4; break;
    case 3: zwracanaWartosc = zwracanaWartosc | 8; break;
    case 4: zwracanaWartosc = zwracanaWartosc | 16; break;
    case 5: zwracanaWartosc = zwracanaWartosc | 32; break;
    case 6: zwracanaWartosc = zwracanaWartosc | 64; break;
    case 7: zwracanaWartosc = zwracanaWartosc | 128; break;
  }
  return zwracanaWartosc;
}

void expander_pcf8574::cyfrowyZapis(int pin, bool wartosc) {
  if (wartosc) {
    _pinStatus |= pobierzPin(pin);
  } else {
    byte odwrotnosc = 255 - pobierzPin(pin);
    _pinStatus &= odwrotnosc;
  }
  rawZapis(_pinStatus);
}

bool expander_pcf8574::cyfrowyOdczyt(int pin) {
  byte wartoscDlaPinu = pobierzPin(pin);
  byte stany = rawOdczyt();
  if ((stany & wartoscDlaPinu) == wartoscDlaPinu) {
    return 1;
  } else return 0;
}

void expander_pcf8574::rawZapis(byte wartosc) {
  Wire.beginTransmission(_adres);
  Wire.write(wartosc);
  Wire.endTransmission();
}

byte expander_pcf8574::rawOdczyt() {
  Wire.requestFrom(_adres, 1);
  byte nowPinStatus;
  if(Wire.available()) {
        nowPinStatus = Wire.read();
  }
  return nowPinStatus;
}

