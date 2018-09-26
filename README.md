# Biblioteka do obsługi ekspandera opartego na PCF8574

Bibliotek powstała do obsługi ekspandera opartego o układ PCF8574.

### Konstruktor
Konstruktor wystepuje w dwóch wersjach - z parametrem typu int lub bez.
W pierwszym opisanym przypadku należy podać jako paramtr adres I2C ekspandera (układu):
```C
expander_pcf8574 ekspander1(33);
```
Jeżeli zostanie wywołany konstruktor bez paramteru to adres ekspandera (układu) będzie miał wartość 32 czyli piny A0, A1 i A2 powinny być podłączone do "masy":
```C
expander_pcf8574 ekspander1();
```

### Metody
*W przykładach będę używał zmiennej "ekspander1"*

*	void cyfrowyZapis(int pin, bool wartosc);

	Metoda ustawia na podanym pinie stan wysoki (*HIGH*/*TRUE*) lub niski (*LOW*/*FALSE*).

*	bool cyfrowyOdczyt(int pin);

	Metoda zwraca wartość *TRUE* jeżeli na pinie podanym w parametrze jest stan wysoki lub *FALSE* jeżeli nie występuje on.

*	void rawZapis(byte wartosc);

	Metoda ustawia stany 8 pinów na raz. Wartosc maksymalna to 255 i oznacza wszystkie na wystkich pinach stan wysoki.
	Każdy bit liczby oznacza jeden pin a więc:
	| Piny: | P7 | P6 | P5 | P4 | P3 | P2 | P1 | P0 |
	| Liczba reprezentująca bit dla wysokiego stanu: | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 |
	Czyli jeżeli chcemy aby piny P3 i P5 miały stan wysoki a pozostałe niski to musimy dodać do siebie liczby 8 i 32 czyli jako parametr powinniśmy podać 40

*	byte rawOdczyt();
	
	Zwróci liczbę od 0 do 255. Każdy bit liczby reprezentuje stan wysoki (bit = 1) lub niski (bit = 0). Pozycja bitu to numer pinu (dokładnie to samo co zostało zaprezentowane w tabeli dla medtody *rawZapis*).