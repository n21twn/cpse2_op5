# CPSE2 2026 - Opdracht 5 - Nick Teeuwen

## Beschrijving

Een Tic-Tac-Toe (3-op-een-rij) spel geschreven in C++. Het project maakt gebruik van het **MVC-pattern** en het **Command-pattern**. Het spel biedt zowel een grafische (SFML) interface als een tekstgebaseerde interface.

## Type project

**Type:** Visual Studio (MSVC)  
**SFML versie:** 2.5.1  
**Taal:** C++17

---


## Bouwen

### Vereisten

- Visual Studio 
- SFML 2.5.1 geïnstalleerd

### Stappen

1. Open `cpse2-op5-nick-teeuwen.sln` in Visual Studio .
2. Stel de SFML-paden in voor de `Release_SFML` configuratie via **Project → Properties**:
   - **C/C++ → General → Additional Include Directories:** pad naar de `include` map van jouw SFML installatie (bijv. `C:\SFML-2.5.1\include`)
   - **Linker → General → Additional Library Directories:** pad naar de `lib` map van jouw SFML installatie (bijv. `C:\SFML-2.5.1\lib`)
   - **Linker → Input → Additional Dependencies:** `sfml-graphics.lib;sfml-window.lib;sfml-system.lib`
3. Selecteer de gewenste build-configuratie in de toolbar:
   - **Release_SFML** → grafische versie met SFML
   - **Release_Text** → tekstversie zonder SFML (geen SFML vereist)
4. Klik op **Build → Build Solution** (of druk op `Ctrl+Shift+B`).
5. De uitvoerbare bestanden worden aangemaakt in de `x64/Release_SFML/` of `x64/Release_Text/` map.

> **Let op (SFML versie):** De `.exe` heeft de SFML `.dll` bestanden nodig om te kunnen starten. Voeg  de `bin`-map van SFML installatie toe aan de Windows `PATH`-variabele:
> 1. Zoek "Omgevingsvariabelen bewerken" in het Startmenu.
> 2. Selecteer onder "Systeemvariabelen" de variabele `Path` → **Bewerken** → **Nieuw**.
> 3. Voeg het pad naar de `bin`-map van jouw SFML installatie toe (bijv. `C:\SFML-2.5.1\bin`).
> 4. Herstart Visual Studio zodat de wijziging actief wordt.
>
> Windows vindt de DLLs dan automatisch, ongeacht waar de `.exe` staat.

---

## Gebruik

### SFML versie (grafisch)

- **Zet plaatsen:** Klik met de linkermuisknop op een vakje op het bord.
- **Undo:** Druk op de toets `U` om de laatste zet ongedaan te maken.
- **Restart:** Druk op de toets `R` om het spel opnieuw te starten.
- **Venster sluiten:** Klik op het kruisje van het venster na afloop van het spel.

### Tekstversie

- **Zet plaatsen:** Voer het rijnummer in (0-2) en druk op Enter, voer daarna het kolomnummer in (0-2) en druk op Enter.
- **Undo:** Typ `u` bij het invoeren van het rijnummer of het kolomnummer en druk op Enter.
- **Restart:** Typ `r` bij het invoeren van het rijnummer en druk op Enter.

---

## Ontwerpkeuzes

**Command-pattern:** Een zet wordt gerepresenteerd door een `MoveCommand`-object (specialisatie van de abstracte `Command`-klasse), dat alle benodigde data bevat (rij, kolom, speler) en zelf controleert of de zet geldig is via `execute()`. De controllers maken dit command-object aan op basis van de spelersinvoer en geven het door aan `Game::executeCommand()`, die het command uitvoert en — alleen bij een geslaagde zet — opslaat in de geschiedenis. Undo werkt door het laatste commando uit deze geschiedenis te verwijderen (`history_.pop_back()`), conform het principe "het laatste commando negeren". Restart is bewust **geen** apart command: een restart wordt nooit bewaard of herhaald, en voldoet daarmee niet aan de kerneigenschap van het pattern (een actie die als object is vastgelegd zodat hij later herhaald of teruggedraaid kan worden). Restart is daarom een directe, eenmalige operatie (`Game::restart()`) die de geschiedenis leegt.
- **STL container:** Alle uitgevoerde commando's worden opgeslagen in een `std::vector<std::unique_ptr<Command>> history_` in `Game`. De bordstatus wordt nergens expliciet bijgehouden, maar wordt afgeleid door deze geschiedenis te doorlopen: elk command kan via `playerAt(row, col)` aangeven of het een bepaald vakje bezet. `Game::getCell()` vraagt dit na aan elk command in de geschiedenis om te bepalen wie waar staat.
- **MVC-pattern:** Het model (`Game`, `Command`-hiërarchie) weet niets van views of controllers. De view-klassen implementeren de abstracte `Interface`-klasse. De controllers implementeren de abstracte `headController`-klasse en vervullen de Client-rol van het Command pattern (zij maken het juiste command-object aan op basis van de input).
- **Minimale code-duplicatie:** De keuze tussen SFML en tekstversie wordt bepaald via een `#ifdef USE_SFML` preprocessor define in `main.cpp`. De gedeelde abstracte klassen (`Interface`, `headController`, `Command`) voorkomen duplicatie tussen de twee versies.
- **Kleurenblindheid:** In de SFML-versie worden spelers onderscheiden door zowel kleur als vorm (X = rood kruis, O = blauwe cirkel), zodat het spel ook toegankelijk is voor kleurenblinden.
