# CPSE2 2026 - Opdracht OP5 - Nick Teeuwen

## Beschrijving

Een Tic-Tac-Toe (3-op-een-rij) spel geschreven in C++. Het project maakt gebruik van het **MVC-pattern** en het **Command-pattern**. Het spel biedt zowel een grafische (SFML) interface als een tekstgebaseerde interface.

## Type project

**Type:** Visual Studio 2022 (MSVC)  
**SFML versie:** 2.5.1  
**Taal:** C++17

---


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
6. Voor de `Release_SFML` moet er nog 1 stap worden gedaan voor dat het werkt
   - Kopieer naar `x64/release_SFML/ ` de sfml `.dll` bestanden naast de `.exe`. De benodigde bestanden zijn: `sfml-graphics-2.dll`, `sfml-window-2.dll`, `sfml-system-2.dll`. Deze zijn te vinden in de `C:\SFML-2.5.1\bin` map van jouw SFML installatie.

---

## Gebruik

### SFML versie (grafisch)

- **Zet plaatsen:** Klik met de linkermuisknop op een vakje op het bord.
- **Undo:** Druk op de toets `u` om de laatste zet ongedaan te maken.
- **Venster sluiten:** Klik op het kruisje van het venster na afloop van het spel.

### Tekstversie

- **Zet plaatsen:** Voer het rijnummer in (0-2) en druk op Enter, voer daarna het kolomnummer in (0-2) en druk op Enter.
- **Undo:** Typ `u` bij het invoeren van het rijnummer **of** het kolomnummer en druk op Enter.

---

