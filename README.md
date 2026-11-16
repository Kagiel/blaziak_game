# Koło Fortuny

## Opis projektu

„Koło Fortuny" to konsolowa gra napisana w języku C++. Gracze kolejno
kręcą kołem, podają litery i próbują odgadnąć ukryte hasło. Gra składa
się z wybranej liczby rund, a punkty zdobyte przez graczy są sumowane w
trakcie całej rozgrywki.

Projekt został przygotowany w środowisku **Visual Studio Code**. Do
kompilacji wykorzystano kompilator **G++** dostępny w środowisku **MSYS2
UCRT64**.

## Wymagania i środowisko

-   Visual Studio Code
-   MSYS2 UCRT64 Shell
-   kompilator G++ (potrzebny do ponownej kompilacji programu)

W repozytorium znajduje się również gotowy plik wykonywalny
`blaziak_game.exe`. Został on skompilowany z opcją `-static`, aby
ograniczyć problem z brakiem biblioteki `libstdc++-6.dll`. Dzięki temu
pobraną wersję gry można uruchomić w terminalu Windows bez instalowania
MSYS2 ani kompilatora G++.

## Pobranie projektu

Sklonuj repozytorium:

``` bash
git clone ADRES_REPOZYTORIUM
```

Następnie przejdź do pobranego katalogu projektu:

``` bash
cd projects_git
```

> Jeśli katalog po sklonowaniu ma inną nazwę, użyj jej zamiast
> `projects_git`.

## Uruchomienie gotowego programu w Windows

Po pobraniu repozytorium można uruchomić dołączony plik wykonywalny z
terminala Windows:

``` cmd
blaziak_game.exe
```

Można też uruchomić go z poziomu terminala znajdującego się w katalogu
projektu.

## Kompilacja programu po zmianie kodu

Po każdej zmianie pliku `blaziak_game.cpp` należy ponownie skompilować
program. W tym celu:

1.  Otwórz **MSYS2 UCRT64 Shell**.
2.  Przejdź do katalogu zawierającego plik `blaziak_game.cpp`, używając
    polecenia `cd` i podając ścieżkę do folderu projektu.
3.  Wykonaj komendę:

``` bash
g++ blaziak_game.cpp -o blaziak_game.exe -static
```

Opcja `-static` powoduje statyczne dołączanie dostępnych bibliotek, co
pozwala przygotować plik wykonywalny, który nie wymaga osobnego
dostarczenia biblioteki `libstdc++-6.dll`.

Do kompilacji i testowania gry w środowisku MSYS2 UCRT64 używano również
poleceń:

``` bash
g++ blaziak_game.cpp -o blaziak_game.exe
./blaziak_game.exe
```

## Instrukcja obsługi gry

1.  Uruchom program.
2.  Wybierz liczbę graczy --- od 1 do 3.
3.  Podaj imię każdego gracza.
4.  Wybierz liczbę rund --- od 1 do 10.
5.  Na początku rundy program losuje kategorię i hasło, a następnie
    wyświetla hasło w ukrytej postaci oraz aktualne wyniki graczy.
6.  Gracze wykonują ruchy po kolei. W swojej turze wybierają jedną z
    opcji:
    -   **Zakręć kołem** --- program losuje wartość punktową albo pole
        specjalne.
    -   **Odgadnij całe hasło** --- gracz próbuje podać rozwiązanie.
    -   **Zakończ grę** --- przerywa rozgrywkę i wyświetla podsumowanie.

### Zasady zdobywania punktów i utraty kolejki

-   Po wylosowaniu pola punktowego gracz podaje jedną literę.
-   Jeśli litera występuje w haśle, program odkrywa wszystkie jej
    wystąpienia i przyznaje punkty: wartość pola pomnożona przez liczbę
    wystąpień litery. Gracz zachowuje kolejkę.
-   Jeśli litery nie ma w haśle, gracz nie zdobywa punktów za ten ruch i
    traci kolejkę.
-   Wylosowanie pola **STOP** powoduje utratę kolejki.
-   Wylosowanie pola **BANKRUT** powoduje utratę wszystkich dotychczas
    zdobytych punktów oraz kolejki.
-   Poprawne odgadnięcie całego hasła kończy rundę.
-   Błędne odgadnięcie całego hasła powoduje utratę kolejki.
-   Runda kończy się również wtedy, gdy wszystkie litery hasła zostaną
    odkryte.

Po zakończeniu gry program wyświetla wyniki graczy, wskazuje zwycięzcę
lub zwycięzców oraz podaje liczbę rozegranych rund.

## Pliki projektu

-   `blaziak_game.cpp` --- kod źródłowy gry.
-   `blaziak_game.exe` --- skompilowany plik wykonywalny.
-   `Informacje.txt` --- dodatkowe informacje o projekcie.
-   Pliki PNG --- schematy działania gry.
