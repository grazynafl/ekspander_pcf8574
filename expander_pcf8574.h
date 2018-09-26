#ifndef expander_pcf8574_h
#define expander_pcf8574_h
#define byte unsigned char

class expander_pcf8574 {
  private:
    int _adres;
    byte _pinStatus;
    byte pobierzPin(int pin);
  public: 
    expander_pcf8574();
    expander_pcf8574(int adres);
    void cyfrowyZapis(int pin, bool value);
    bool cyfrowyOdczyt(int pin);
    void rawZapis(byte value);
    byte rawOdczyt();
};

#endif
