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
- SFML 2.5.1 geïnstalleerd (bijv. in `C:\SFML-2.5.1\`)

### Stappen

1. Open `cpse2-op5-nick-teeuwen.sln` in Visual Studio 2022.
2. Selecteer de gewenste build-configuratie in de toolbar:
   - **Release_SFML** → grafische versie met SFML
   - **Release_Text** → tekstversie zonder SFML
3. Klik op **Build → Build Solution** (of druk op `Ctrl+Shift+B`).
4. De uitvoerbare bestanden worden aangemaakt in de `x64/Release_SFML/` of `x64/Release_Text/` map.

> **Let op:** Zorg dat de SFML include- en library-paden correct zijn ingesteld in de projectinstellingen voor de `Release_SFML` configuratie:
> - C/C++ → General → Additional Include Directories: `C:\SFML-2.5.1\include`
> - Linker → General → Additional Library Directories: `C:\SFML-2.5.1\lib`
> - Linker → Input → Additional Dependencies: `sfml-graphics.lib;sfml-window.lib;sfml-system.lib`

---

## Gebruik

### SFML versie (grafisch)

- **Zet plaatsen:** Klik met de linkermuisknop op een vakje op het bord.
- **Undo:** Druk op de toets `U` om de laatste zet ongedaan te maken.
- **Venster sluiten:** Klik op het kruisje van het venster na afloop van het spel.

### Tekstversie

- **Zet plaatsen:** Voer het rijnummer in (0-2) en druk op Enter, voer daarna het kolomnummer in (0-2) en druk op Enter.
- **Undo:** Typ `u` bij het invoeren van het rijnummer en druk op Enter.

---

## Ontwerpkeuzes

- **Command-pattern:** Alle zetten worden opgeslagen in een `std::vector<Move>`. De bordstatus wordt nergens expliciet bijgehouden maar altijd afgeleid door de lijst zetten te doorlopen. Undo werkt door de laatste zet uit de vector te verwijderen.
- **MVC-pattern:** Het model (`Game`) weet niets van de view. De view-klassen implementeren de abstracte `Interface`-klasse. De controllers implementeren de abstracte `headController`-klasse.
- **Kleurenblindheid:** In de SFML-versie worden spelers onderscheiden door zowel kleur als vorm (X = rood kruis, O = blauwe cirkel), zodat het spel ook toegankelijk is voor kleurenblinden.
- **Geen code-duplicatie:** De gemeenschappelijke interface (`Interface`) en controller (`headController`) voorkomen duplicatie tussen de twee versies.
