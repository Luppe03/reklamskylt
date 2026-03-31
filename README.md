#Reklamskylt

#GIT:
https://github.com/Luppe03/reklamskylt.git 

#WOKWI:
https://wokwi.com/projects/459561730226414593 

#Beskrivning
Den här uppgiften simulerar en digital reklamtavla som visar olika reklammeddelanden från flera kunder, där varje kund har olika krav på hur deras reklam ska visas samt att de har betalat olika mycket. Vilket påverkar hur ofta deras meddelanden kommer att visas.

Programmet är skrivet i C++ och körs i terminalen där utskriften ska representera reklamtavlan som kunden har beställt.

#Funktioner
- Viktad slumpning baserat på hur mycket kunden har betalat.
- Samma kund visas aldrig två gånger i rad.
- Kundspecifika regler för visning:
* Hederlige Harrys Bilar: slump mellan tre meddelanden
* Farmor Ankas Pajer: slump mellan två meddelanden 
* Svarte Petter: olika meddelanden beroende på jämn/ojämn minut 
* Långben: slump mellan två meddelanden 
* IOT:s Reklambyrå: ett meddelande
Där varje reklamskylt visas i 20 sekunder

Programmet väljer en kund med hjälp av viktad slumpning där sannolikheten baseras på hur mycket kunden har betalat för sin reklamskylt. När en kund då valts så hämtas ett meddelande enligt kundens regler och skrivs ut i terminalen.

Kunden sparas för att säkerställa att samma kund inte visas två gånger i rad.

#Kompilering:
g++ main.cpp -o reklamskylt

./reklamskylt eller reklamskylt.exe

reklamskylt/
├── main.cpp
└── README.md

#Slutsats
Projektet visar hur man kan bygga ett enkelt system för att hantera flera reklammeddelanden med olika prioritet. Lösningen uppfyller kraven genom att kombinera slumpning, regler samt enkel tidsstyrning.


#Kopplingsschema:
![Kopplingsschema](kopplingsschema.png)

+----------------------+
|      Dator (PC)      |
|                      |
|  C++ Program         |
|  (main.cpp)          |
+----------+-----------+
           |
           v
+----------------------+
|   Terminalfönster    |
| (Simulerad skylt)    |
+----------------------+