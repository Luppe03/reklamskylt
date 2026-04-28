# Reklamskylt

## GitHub

https://github.com/Luppe03/reklamskylt.git

## Wokwi

https://wokwi.com/projects/462094442698146817



# Beskrivning

Det här projektet simulerar en digital reklamskylt byggd med Arduino Uno och en 16x2 LCD-display.

Systemet visar reklammeddelanden från olika kunder där varje kund har olika krav på hur reklamen ska visas. Hur ofta reklamen visas baseras på hur mycket kunden har betalat.

Reklamen visas direkt på LCD-skärmen och samma kund visas aldrig två gånger i rad.


# Funktioner

* Viktad slumpning baserat på hur mycket kunden har betalat
* Samma kund visas aldrig två gånger i rad
* Reklam visas på LCD-display
* Kundspecifika regler för visning

## Kundregler

### Hederlige Harrys Bilar

* Slump mellan tre meddelanden

### Farmor Ankas Pajer AB

* Slump mellan två meddelanden

### Svarte Petters Svartbyggen

* Olika meddelanden beroende på jämn eller ojämn minut

### Langbens detektivbyra

* Slump mellan två meddelanden

### IOT:s Reklambyra

* Ett fast meddelande



# Hårdvara

* Arduino Uno
* LCD 16x2 I2C



# Kopplingar

| LCD | Arduino Uno |
| --- | ----------- |
| GND | GND         |
| VCC | 5V          |
| SDA | A4          |
| SCL | A5          |



# Hur projektet fungerar

Programmet använder viktad slumpning för att välja vilken kunds reklam som ska visas.

Sannolikheten baseras på hur mycket kunden har betalat.

När en kund valts visas ett av kundens reklammeddelanden på LCD-displayen i 20 sekunder.

Efter det väljs en ny kund.



# Projektstruktur

```text
reklamskylt/
├── sketch.ino
├── diagram.json
├── libraries.txt
└── README.md
```



# Slutsats

Projektet visar hur ett embedded-system kan användas för att styra en digital reklamskylt med hjälp av Arduino och LCD-display.

Lösningen använder slumpning, prioritering och kundspecifika regler för att simulera ett enklare reklamsystem.
