#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct Customer {
  String name;
  int weight;
};

Customer customers[] = {
  {"Harry", 5000},
  {"Farmor", 3000},
  {"Petter", 1500},
  {"Langben", 4000},
  {"IOT", 1000}
};

int lastCustomer = -1;


int weightedRandomCustomer() {

  int totalWeight = 0;

  for (int i = 0; i < 5; i++) {

    if (i != lastCustomer) {
      totalWeight += customers[i].weight;
    }
  }

  int randomValue = random(totalWeight);

  for (int i = 0; i < 5; i++) {

    if (i == lastCustomer) {
      continue;
    }

    if (randomValue < customers[i].weight) {
      return i;
    }

    randomValue -= customers[i].weight;
  }

  return 0;
}


String getMessage(int customerIndex) {

  switch (customerIndex) {

    case 0: {

      int msg = random(3);

      switch (msg) {

        case 0:
          return "Kop bil";

        case 1:
          return "Bilaffar";

        case 2:
          return "Harry Bilar";
      }
    }

    case 1: {

      if (random(2) == 0) {
        return "Kop paj";
      }

      return "Skynda!";
    }

    case 2: {

      unsigned long minutes = millis() / 60000;

      if (minutes % 2 == 0) {
        return "Bygg m Petter";
      }

      return "Ring Petter";
    }

    case 3: {

      if (random(2) == 0) {
        return "Ring Langben";
      }

      return "Fixar biff";
    }

    case 4:
      return "Synas har?";

  }

  return "";
}


void setup() {

  lcd.init();
  lcd.backlight();

  randomSeed(analogRead(A0));
}


void loop() {

  int customer = weightedRandomCustomer();

  String message = getMessage(customer);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(customers[customer].name);

  lcd.setCursor(0, 1);
  lcd.print(message);

  lastCustomer = customer;

  delay(20000);
}
