#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <map>
#include <random>
#include <iterator>
#include <cctype>
using namespace std;

struct Gracz {
    string imie;
    int punkty;
    int punkty_w_rundzie;
};



//generator losowania
    string losuj_kategorie(map<string, vector<string>> baza_hasel) {
        random_device ziarno_losowosci;
        mt19937 gen(ziarno_losowosci());

        uniform_int_distribution<> losuj_kategorie(0, baza_hasel.size() - 1);
        int wylosowana_kategoria = losuj_kategorie(gen);

        auto it = baza_hasel.begin();
        advance(it, wylosowana_kategoria);

        string nazwa_wylosowanej_kategorii = it->first;

    return nazwa_wylosowanej_kategorii;
}

    string losuj_haslo(map<string, vector<string>> baza_hasel, string kategoria) {
        random_device ziarno_losowosci;
        mt19937 gen(ziarno_losowosci());

        vector<string> hasla = baza_hasel[kategoria];

        uniform_int_distribution<> losuj_indeks_hasla(0, hasla.size() - 1);
        int indeks_hasla = losuj_indeks_hasla(gen);

        string wylosowane_haslo = hasla[indeks_hasla];

    return wylosowane_haslo;
}

void rozpocznij_runde( int liczba_rund, map<string, vector<string>> baza_hasel, vector<Gracz> gracze) {
    bool koniec_gry = false;
    int rozegrane_rundy = 0; //zmienna do zliczania rozegranych rund w celu zqakończenia gry po określonej liczbie rund
     vector<string> wykorzystane_hasla;
    //dla każdej rundy
    for (int i =0; i<liczba_rund && koniec_gry == false; i++) {
        rozegrane_rundy++;

        for (int j = 0; j < gracze.size(); j++) //resetowanie punktów w rundzie dla każdego gracza
        {
            gracze[j].punkty_w_rundzie = 0;
        }

        string nazwa_wylosowanej_kategorii = losuj_kategorie(baza_hasel);
        string wylosowane_haslo;

        //sprawdzanie vektora haseł wykorzystanych w rundzie, jeśli hasło zostało już użyte, losujemy nowe hasło
       
            bool wylosowane_haslo_sie_powtarza = true;

            while (wylosowane_haslo_sie_powtarza == true) 
                {
                    wylosowane_haslo = losuj_haslo(baza_hasel, nazwa_wylosowanej_kategorii);

                     wylosowane_haslo_sie_powtarza= false;

                    for (int j = 0; j < wykorzystane_hasla.size(); j++) //sprawdzamy każde hasło w vektorze
                        {
                            if (wykorzystane_hasla[j] == wylosowane_haslo) 
                                {
                                    wylosowane_haslo_sie_powtarza = true;
                                    break;
                                }
                        }
                }

            wykorzystane_hasla.push_back(wylosowane_haslo);

        vector<char> Wpisane_litery;

        //zakrywanie hasła
        string odkryte_haslo = wylosowane_haslo;
        for (int j = 0; j < odkryte_haslo.length(); j++)
        {
            if (odkryte_haslo[j] != ' ') {
                odkryte_haslo[j] = '_';
            }
            else {
                odkryte_haslo[j] = ' ';
            }
        }

        int aktualny_gracz = 0; //zacznyamy od pierwszego gracza

        bool koniec_rundy = false;
        
        while (koniec_rundy == false && koniec_gry == false) {

            // wyświetlanie ekranu rundy
            system("cls");

            cout << "================================" << endl;
            cout << "          KOLO FORTUNY          " << endl;
            cout << "================================" << endl;

            cout << "Runda " << (i + 1) << " z " << liczba_rund << endl;
        
            //wyświetlanie wyników graczy
            cout << "\nWYNIKI GRACZY:\n" << endl;
            for (int j = 0; j < gracze.size(); j++) {
                cout << gracze[j].imie << ": " << gracze[j].punkty << " pkt\n" << endl;
            }

            cout << "\nGracz: " << gracze[aktualny_gracz].imie << endl;
            cout << "\nPunkty: " << gracze[aktualny_gracz].punkty << endl << endl;

            cout << "Kategoria: " << nazwa_wylosowanej_kategorii << endl << endl;

            cout << "Haslo: " << odkryte_haslo << endl << endl;

            cout << "Uzyte litery: ";
            for (int j = 0; j < Wpisane_litery.size(); j++) {
                cout << Wpisane_litery[j] << " ";
            }
            cout << endl;

            //menu wyboru akcji

            cout << "\n Co chcesz zrobic?" << endl;
            cout << "1. Zakrec kolem fortuny" << endl;
            cout << "2. Zgadnij cale haslo" << endl;
            cout << "3. Wyjdz z gry" << endl;

            char wybor_gracza = _getch();

            if (wybor_gracza == '1')
            {
                cout << "\n Wybrano zakrecenie kolem!" << endl;

                //logika kręcenia kołem fortuny
                int tab[10] = { 100, 200, 300, 400, 500, 600, 800, 1000, 1, 0 };

                random_device ziarno_losowosci;
                mt19937 gen(ziarno_losowosci());

                uniform_int_distribution<> losuj(0, 9);

                int i = losuj(gen);
                int wynik_losowania = tab[i];

                if (wynik_losowania >= 100) {
                    char litera;
                    cout << "Wylosowana wartosc: " << wynik_losowania << endl;
                    cout << "Podaj litere: ";
                    cin >> litera;
                    // zamiana wprowadzonej litery na małą
                    litera = tolower(litera);

                    //sprawdzenie w wektorze hasłaczy litera została już użyta jeśli tak to true
                    bool czy_juz_uzyta = false;

                    for (int j = 0; j < Wpisane_litery.size(); j++)
                    {
                        if (Wpisane_litery[j] == litera) {
                            czy_juz_uzyta = true;
                        }
                    }
                    //warunek przyznania pkt
                    if (czy_juz_uzyta == true) {
                        cout << "\nTa litera byla juz uzyta! Sprobuj ponownie." << endl;
                        cout << "Nacisnij ENTER, aby kontynuowac...";
                        cin.ignore();
                        cin.get();
                    }
                    else
                    {
                        Wpisane_litery.push_back(litera);
                        int liczba_wystapien = 0;

                        for (int j = 0; j < wylosowane_haslo.length(); j++)
                        {
                            if (wylosowane_haslo[j] == litera) //sprawdzenie znak po znaku czy litera występuje w haśle
                            {
                                liczba_wystapien++;
                                odkryte_haslo[j] = litera; //odkrywanie litery w haśle
                            }
                        }

                        if (liczba_wystapien > 0) {
                            int zdobyte_punkty = (wynik_losowania * liczba_wystapien);
                            gracze[aktualny_gracz].punkty += zdobyte_punkty;
                            gracze[aktualny_gracz].punkty_w_rundzie += zdobyte_punkty;

                            cout << "Brawo! Litera wystepuje " << liczba_wystapien << " razy." << endl;
                            cout << "Zdobywasz " << zdobyte_punkty << " punktow!" << endl;
                            cout << "Nacisnij ENTER, aby kontynuowac...";
                            cin.ignore();
                            cin.get();
                            
                            //sprawdzenie czy gracz odkrył całe hasło
                            koniec_rundy = true;

                            for (int j = 0; j < odkryte_haslo.length(); j++) 
                                {
                                    if (odkryte_haslo[j] == '_') 
                                        {
                                            koniec_rundy = false;
                                            break;
                                        }
                                }

                            if (koniec_rundy == true) 
                                {
                                    cout << "\nOdkryles cale haslo!" << endl;
                                }
                        }
                        else {
                            cout << "Nie ma takiej litery! Tracisz kolejke." << endl;
                            cout << "Nacisnij ENTER, aby kontynuowac...";
                            cin.ignore();
                            cin.get();
                            aktualny_gracz++;

                            if (aktualny_gracz >= gracze.size()) // sprawdzenie czy aktualny gracz nie przekroczył liczby graczy
                            {
                                aktualny_gracz = 0;
                            }
                        }
                    }
                } // DODANA KLAMRA - zamyka if (wynik_losowania >= 100)
                else if (wynik_losowania == 1)
                {
                    cout << "\nBANKRUT! Tracisz punkty z tej rundy." << endl;
                    cout << "Nacisnij ENTER, aby kontynuowac...";
                    cin.ignore();
                    cin.get();

                    gracze[aktualny_gracz].punkty = 0;
                    gracze[aktualny_gracz].punkty_w_rundzie = 0;

                    aktualny_gracz++;

                    if (aktualny_gracz >= gracze.size()) {
                        aktualny_gracz = 0;
                    }
                }
                else if (wynik_losowania == 0) {
                    cout << "\nSTOP! Koniec twojej kolejki." << endl;
                    cout << "Nacisnij ENTER, aby kontynuowac...";
                    cin.ignore();
                    cin.get();
                    aktualny_gracz++;

                    if (aktualny_gracz >= gracze.size()) // sprawdzenie czy aktualny gracz nie przekroczył liczby graczy
                    {
                        aktualny_gracz = 0;
                    }
                }

            } // koniec if (wybor_gracza == '1')
            else if (wybor_gracza == '2') {
                cout << "\n Wybrano zgadywanie hasla!" << endl;

                //logika zgadywania hasła
                string odpowiedz_gracza;

                cout << "\nPodaj cale haslo: ";
                getline(cin, odpowiedz_gracza);

                //walidacja odpowiedzi gracza, wszystkie hasła zaczynają się od dużej litery.
                string haslo_male = wylosowane_haslo;
                string haslo_pierwsza_duza = wylosowane_haslo;
                string haslo_duze = wylosowane_haslo;

                // zamiana całego hasła na duże litery
                for (int j = 0; j < haslo_duze.length(); j++)
                {
                    haslo_duze[j] = toupper(haslo_duze[j]);
                }

                // zamiana pierwszej litery na dużą
                haslo_pierwsza_duza[0] = toupper(haslo_pierwsza_duza[0]);

                if (odpowiedz_gracza == haslo_male || odpowiedz_gracza == haslo_pierwsza_duza || odpowiedz_gracza == haslo_duze)
                {
                    cout << "\nBrawo! Odgadles haslo!" << endl;
                    koniec_rundy = true;
                    cout << "Nacisnij ENTER, aby kontynuowac...";
                    cin.ignore();
                    cin.get();
                }
                else
                {
                    cout << "\nNiestety, to nie jest poprawne haslo. Tracisz kolejke." << endl;
                    cout << "Nacisnij ENTER, aby kontynuowac...";
                    cin.ignore();
                    cin.get();

                    aktualny_gracz++;

                    if (aktualny_gracz >= gracze.size()) {
                        aktualny_gracz = 0;
                    }
                }
            }
            else if (wybor_gracza == '3') {
                cout << "\n Koniec gry!" << endl;

                //logika końca gry
                koniec_gry = true;
                break;
            }
            else {
                cout << "\n Niepoprawny wybor! Sprobuj ponownie." << endl;
            }
        } // koniec while
    } // koniec for

    //koniec gry, wyświetlanie wyników
    system("cls");
    cout << "\n=================================" << endl;
    cout << "            KONIEC GRY             " << endl;
    cout << "===================================" << endl;

    cout << "\nWYNIKI:\n" << endl;
    //wyświetlanie wyników graczy
    for (int j = 0; j < gracze.size(); j++) {
        cout << gracze[j].imie << ": " << gracze[j].punkty << " pkt" << endl;
    }

    //sprawdzenie kto wygrał
    int indeks_zwyciezcy = 0; // zakładamy, że zwycięzcą jest pierwszy gracz

    for (int j = 1; j < gracze.size(); j++) 
        {
            if (gracze[j].punkty > gracze[indeks_zwyciezcy].punkty) // jeśli gracz j ma więcej punktów niż obecny zwycięzca, aktualizujemy indeks zwycięzcy
                {
                    indeks_zwyciezcy = j;
                }
        }
    //sprawdzenie czy jest remis
    cout << "\nZWYCIEZCA / ZWYCIEZCY:\n";

    for (int j = 0; j < gracze.size(); j++) 
        {
            if (gracze[j].punkty == gracze[indeks_zwyciezcy].punkty) // jeśli sprawdzany gracz ma tyle samo punktów co zwycięzca, wyświetlamy jego imię
                {
                    cout << gracze[j].imie << endl; // wyświetlenie imienia zwycięzcy lub zwycięzców w przypadku remisu
                }
        }
    
    //wyświetlanie ilości rozegranych rund
    cout << "\nRozegrano " << rozegrane_rundy << " rund." << endl;

    cout << "\nNacisnij ENTER, aby zakonczyc...";
    cin.ignore();
    cin.get();

} // koniec funkcji

map<string, vector<string>> utworz_baze_hasel() { 
    map<string, vector<string>> baza_hasel; // mapa z kluczem typu string i wartością typu vector<string>

baza_hasel["Zwierzęta"] = {
    "kot", "pies", "lew", "lis", "wilk",
    "tygrys", "kret", "mysz", "sowa", "kruk",
    "paw", "bocian", "kogut", "kura", "kaczka",
    "delfin", "rekin", "goryl", "kameleon", "bizon",
    "borsuk", "karp", "sum", "osa",
    "mucha", "komar", "pszczoła", "motyl", "skorpion"
};

baza_hasel["Jedzenie"] = {
    "pizza", "banan", "ananas", "makaron", "chleb",
    "ser", "miod", "kakao", "ryba", "pomidor",
    "ogorek", "marchew", "kapusta", "fasola", "groch",
    "kukurydza", "czekolada", "kluski", "tost", "bigos",
    "sernik", "baton", "keks", "kompot", "sok"
};

baza_hasel["Przedmioty"] = {
    "telefon", "komputer", "laptop", "monitor", "klawiatura",
    "myszka", "zegar", "lampa", "kanapa", "fotel",
    "lustro", "garnek", "talerz", "kubek", "widelec",
    "namiot", "walizka", "parasol", "rower", "kalendarz",
    "zeszyt", "koperta", "pilot"
};

baza_hasel["Zawody"] = {
    "lekarz", "kucharz", "piekarz", "malarz",
    "policjant", "pilot", "marynarz", "mechanik", "fryzjer",
    "hydraulik", "architekt", "fotograf", "rolnik", "rybak",
    "kelner", "krawiec", "listonosz", "stolarz", "murarz"
};

baza_hasel["Sport"] = {
    "boks", "tenis", "hokej", "golf", "judo",
    "karate", "bieganie", "kolarstwo", "badminton",
    "bilard", "rugby", "squash", "maraton", "slalom",
    "triathlon"
};

baza_hasel["Pojazdy"] = {
    "rower", "motor", "skuter", "traktor", "autobus",
    "samolot", "helikopter", "kajak",
    "prom", "tramwaj", "trolejbus"
};

baza_hasel["Miejsca"] = {
    "szpital", "apteka", "piekarnia", "kino", "teatr",
    "muzeum", "hotel", "lotnisko", "dworzec", "stadion",
    "park", "las", "plaza", "wyspa", "pustynia",
    "jaskinia", "zamek", "biblioteka"
};

baza_hasel["Muzyka"] = {
    "gitara", "pianino", "perkusja", "skrzypce", "flet",
    "akordeon", "koncert", "orkiestra",
    "melodia", "rytm", "opera", "balet", "taniec"
};

baza_hasel["Natura"] = {
    "las", "rzeka", "morze", "ocean", "gora",
    "wulkan", "wodospad", "jezioro", "pustynia",
    "jaskinia", "piasek", "wiatr", "deszcz",
    "burza", "chmura", "trawa", "kwiat"
};
return baza_hasel;
}

vector<Gracz> wczytaj_graczy_i_imiona(int liczba_rund, int liczba_graczy) {
    vector<Gracz> gracze; // vektor typu danych Gracz o nazwie gracze
    cout << liczba_graczy << " graczy zostalo wybranych. \n" << endl;
    cout << liczba_rund << " rund zostalo wybranych. \n" << endl;

    // pętla do wczytywania każdego imienia graczy
    for (int i = 0; i < liczba_graczy; i++) {
        Gracz nowy_gracz;
            cout << "Podaj imie gracza " << (i + 1) << ": ";
            getline(cin, nowy_gracz.imie); // cin >> zatrzymuje sie na spacji, getline() wczytuje całe imię, nawet jeśli zawiera spacje.
            nowy_gracz.punkty = 0; // inicjalizacja punktów gracza na 0
            nowy_gracz.punkty_w_rundzie = 0;
            gracze.push_back(nowy_gracz); // dodanie gracza do wektora
    }

    for (int j=0; j<gracze.size(); j++) {
        cout << "Gracz " << (j + 1) << ": " << gracze[j].imie << "  | Punkty: " << gracze[j].punkty << endl;
    }
    

    return gracze;
}

int wczytaj_il_rund() {
    char wybor_il_rund;

    do
    {
        cout << "Podaj liczbe rund (nacisnij klawisz 1-0 gdzie 0 oznacza 10): ";
        wybor_il_rund = _getch();
        cout << endl;

        if (wybor_il_rund >= '1' && wybor_il_rund <= '9') 
        {
            int liczba_rund = wybor_il_rund - '0'; // konwersja znaku na liczbę całkowitą
            cout << "Wybrano " << liczba_rund << " rund.\n" << endl;
            return liczba_rund;   // oddaje wartość i kończy funkcję (break niepotrzebny)
        }
        else if (wybor_il_rund == '0') // obsługa przypadku, gdy użytkownik wybiera 0 jako 10 rund
        {
            int liczba_rund = 10;
            cout << "Wybrano " << liczba_rund << " rund.\n" << endl;
            return liczba_rund;
        }
        else
        {
            cout << "Niepoprawny wybor! Sprobuj ponownie." << endl;
        }
    } while (true);
}

int wczytaj_il_graczy() {
    char wybor_il_graczy;

    do
    {
        cout << "Podaj liczbe graczy (nacisnij klawisz 1-3): ";
        wybor_il_graczy = _getch();
        cout << endl;

        if (wybor_il_graczy >= '1' && wybor_il_graczy <= '3')
        {
            int liczba_graczy = wybor_il_graczy - '0';
            cout << "Wybrano " << liczba_graczy << " graczy. \n" << endl;
            return liczba_graczy;
        }
        else
        {
            cout << "Niepoprawny wybor! Sprobuj ponownie." << endl;
        }
    } while (true);
}

int menu_start() {
    char wybor_menu;

    do
    {
        cout << "Witaj w grze Kolo Fortuny!" << endl;
        cout << "Nacisnij 'ENTER', aby rozpoczac gre" << endl;
        cout << "Nacisnij 'Esc', aby wyjsc z gry" << endl;

        wybor_menu = _getch();

        if (wybor_menu == 13)
        {
            cout << "Zaczynajmy!" << endl;

            int liczba_graczy = wczytaj_il_graczy();
            int liczba_rund = wczytaj_il_rund();
            vector<Gracz> gracze = wczytaj_graczy_i_imiona(liczba_rund, liczba_graczy); //przypisanie do zmiennej gracze wektora zwróconego przez funkcję wczytaj_graczy_i_imiona
            map<string, vector<string>> baza_hasel = utworz_baze_hasel();
            rozpocznij_runde(liczba_rund, baza_hasel, gracze);
            break;
        }
        else if (wybor_menu == 27)
        {
            cout << "Do zobaczenia!" << endl;
            return 0;
        }
        else
        {
            cout << "Niepoprawny wybor! Sprobuj ponownie." << endl;
        }
    } while (true);

    return 0;
}

int main() {
    menu_start();
    return 0;
}
