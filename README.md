Uart controls LED project
===========================

Účel/Zadání/Funkce
-----------------------

Vytvořte program, který pomocí sériového rozhraní ovládá rychlost blikání LED.

1. Program, bude reagovat na číslice 0-9, které uživatel pošle na UART. Ostatní znaky musí být ignorovány.
2. Použijte přerušení UART-Rx.
3. Klávesa 0 blikání LED zastaví v tom stavu v jakém LED je při jejím stisku/přijmu.
4. Klávesa 9 nastavuje nejvyšší rychlost blikání, tedy nejkratší periodu; klávesa 1 nastavuje nejpomalejší blikání a tedy nejdelší periodu.
5. Po změně rychlosti pošlete na UART zprávu o aktuální periodě a frekvenci.
6. Rychlost 1 až 9 se nemusí měnit lineárně -- přesné chování je ponecháno vaší tvořivosti.


Schéma zapojení
-----------------------

![schéma zapojení](./docs/Snímek%20obrazovky%202026-03-24%20111259.png)

Popis funkce
-----------------------

1. Uart má povolené přerušení
2. V rutině přerušení se mění promněnná, která mění rychlost blikání LED
3. Celé se to potom ovládá pomocí číslic na klavesnici přes pyserial
4. v mainu je potom napsaný program pro zobrazovaní aktuálního stavu programu

Zhodnocení
-----------------------

- Na tomhle projektu jsem si osvěžil znalosti Uartu a prohloubil je.
- Projekt nebyl zas tak těžký stačilo si vzpomenout na pár věcí a postavit hlavní funkci bylo potom už jednoduché naprogramovat
- Na zobrazení pyserialu jsem si pomohl trochu umělou intelingencí aby to vypadalo přehledně a dávalo smysl