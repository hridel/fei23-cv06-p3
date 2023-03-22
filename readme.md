# Příklad 3
## práce s plně dynamickou maticí

Napište sadu funkcí pro práci s plně dynamickým dvojrozměrným polem (maticí)

Požadované funkce

- “Alokuj”
    - Provede alokaci dvojrozměrného pole (řádky, sloupce) a vrací ukazatel na alokovanou paměť
- “Generuj”
    - Načte matici celých čísel
- “Dealokuj”
    - Dealokace celé matice
- “Vypiš”
    - Vypíše matici na obrazovku
- “Najdi”
    - Hledá zadanou hodnotu v matici, vrací 0 v případě neúspěchu a 1 v případě,  že se hledaný prvek v poli vyskytuje
- “Prohoď”
    - prohodí maximální prvek s minimálním
- “MaxSloupec”
    - Vrátí index sloupce, který má největší součet prvků
- “VynulujSudé”
    - nahradí sudé prvky hodnotou 0

Hlavní program načte od uživatele velikost matice (sloupce a řádky) a provede postupně:
Alokuj → Načti → Vypiš →  Zadej hledanou hodnotu: → Najdi (o výsledku je uživatel informován) → Prohoď → Vypiš → VynulujSudé → Vypiš → MaxSloupec → Dealokuj