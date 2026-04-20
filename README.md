# CPSE2 2026 - Opdracht OP5 - Nick Teeuwen

## Beschrijving

Een Tic-Tac-Toe (3-op-een-rij) spel geschreven in C++. Het project maakt gebruik van het **MVC-pattern** en het **Command-pattern**. Het spel biedt zowel een grafische (SFML) interface als een tekstgebaseerde interface.

## Type project

**Type:** Visual Studio 2022 (MSVC)  
**SFML versie:** 2.5.1  
**Taal:** C++17

---

## Project structuur

```
cpse2-op5-nick-teeuwen/
├── src/
│   ├── model/
│   │   ├── game.hpp / game.cpp
│   │   ├── move.hpp
│   │   └── inputResult.hpp
│   ├── view/
│   │   ├── Interface.hpp
│   │   ├── SFMLInterface.hpp / SFMLInterface.cpp
│   │   └── textInterface.hpp / textInterface.cpp
│   └── controller/
│       ├── headController.hpp
│       ├── SFMLController.hpp / SFMLController.cpp
│       └── textController.hpp / textController.cpp
├── assets/
│   └── arial.ttf
├── main.cpp
├── cpse2-op5-nick-teeuwen.vcxproj
└── README.md
```

---

## Bouwen

### Vereisten

- Visual Studio 2022
- SFML 2.5.1 geïnstalleerd

### Stappen

1. Open `cpse2-op5-nick-teeuwen.sln` in Visual Studio 2022.
2. Stel de SFML-paden in voor de `Release_SFML` configuratie via **Project → Properties**:
   - **C/C++ → General → Additional Include Directories:** pad naar de `include` map van jouw SFML installatie (bijv. `C:\SFML-2.5.1\include`)
   - **Linker → General → Additional Library Directories:** pad naar de `lib` map van jouw SFML installatie (bijv. `C:\SFML-2.5.1\lib`)
   - **Linker → Input → Additional Dependencies:** `sfml-graphics.lib;sfml-window.lib;sfml-system.lib`
3. Selecteer de gewenste build-configuratie in de toolbar:
   - **Release_SFML** → grafische versie met SFML
   - **Release_Text** → tekstversie zonder SFML (geen SFML vereist)
4. Klik op **Build → Build Solution** (of druk op `Ctrl+Shift+B`).
5. De uitvoerbare bestanden worden aangemaakt in de `x64/Release_SFML/` of `x64/Release_Text/` map.

> **Let op (SFML versie):** Kopieer de benodigde SFML `.dll` bestanden naar dezelfde map als de `.exe`. De benodigde bestanden zijn:
> `sfml-graphics-2.dll`, `sfml-window-2.dll`, `sfml-system-2.dll`
> Deze zijn te vinden in de `bin` map van jouw SFML installatie.

---

## Gebruik

### SFML versie (grafisch)

- **Zet plaatsen:** Klik met de linkermuisknop op een vakje op het bord.
- **Undo:** Druk op de toets `U` om de laatste zet ongedaan te maken.
- **Venster sluiten:** Klik op het kruisje van het venster na afloop van het spel.

### Tekstversie

- **Zet plaatsen:** Voer het rijnummer in (0-2) en druk op Enter, voer daarna het kolomnummer in (0-2) en druk op Enter.
- **Undo:** Typ `u` bij het invoeren van het rijnummer **of** het kolomnummer en druk op Enter.

---

## Ontwerpkeuzes

- **Command-pattern:** Alle zetten worden opgeslagen in een `std::vector<Move>` (STL container). De bordstatus wordt nergens expliciet bijgehouden maar altijd afgeleid door de lijst zetten te doorlopen. Undo werkt door de laatste zet uit de vector te verwijderen met `pop_back()`.
- **MVC-pattern:** Het model (`Game`) weet niets van de view. De view-klassen implementeren de abstracte `Interface`-klasse. De controllers implementeren de abstracte `headController`-klasse.
- **Kleurenblindheid:** In de SFML-versie worden spelers onderscheiden door zowel kleur als vorm (X = rood kruis, O = blauwe cirkel), zodat het spel ook toegankelijk is voor kleurenblinden.
- **Geen code-duplicatie:** De gemeenschappelijke interface (`Interface`) en controller (`headController`) voorkomen duplicatie tussen de twee versies. De keuze tussen SFML en tekstversie wordt bepaald via een `#ifdef USE_SFML` preprocessor define in `main.cpp`.
