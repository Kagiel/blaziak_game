#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <map>
using namespace std;

struct Gracz {
    string imie;
    int punkty;
};

string losuj_haslo(map<string, vector<string>> baza_hasel){ // funcka otrzymuje baza_hasel o typie danych

    
}

map<string, vector<string>> utworz_baze_hasel() { 
    map<string, vector<string>> baza_hasel; // mapa z kluczem typu string i wartością typu vector<string>

baza_hasel["Zwierzęta"] = {
    "Kot", "Pies", "Lew", "Lis", "Wilk",
    "Tygrys", "Kret", "Mysz", "Sowa", "Kruk",
    "Paw", "Bocian", "Kogut", "Kura", "Kaczka",
    "Delfin", "Rekin", "Goryl", "Kameleon", "Bizon",
    "Borsuk", "Karp", "Sum", "Osa",
    "Mucha", "Komar", "Pszczoła", "Motyl", "Skorpion"
};

baza_hasel["Jedzenie"] = {
    "Pizza", "Banan", "Ananas", "Makaron", "Chleb",
    "Ser", "Miod", "Kakao", "Ryba", "Pomidor",
    "Ogorek", "Marchew", "Kapusta", "Fasola", "Groch",
    "Kukurydza", "Czekolada", "Kluski", "Tost", "Bigos",
    "Sernik", "Baton", "Keks", "Kompot", "Sok"
};

baza_hasel["Przedmioty"] = {
    "Telefon", "Komputer", "Laptop", "Monitor", "Klawiatura",
    "Myszka", "Zegar", "Lampa", "Kanapa", "Fotel",
    "Lustro", "Garnek", "Talerz", "Kubek", "Widelec",
    "Namiot", "Walizka", "Parasol", "Rower", "Kalendarz",
     "Zeszyt", "Koperta", "Pilot"
};

baza_hasel["Zawody"] = {
    "Lekarz", "Kucharz", "Piekarz", "Malarz",
    "Policjant", "Pilot", "Marynarz", "Mechanik", "Fryzjer",
    "Hydraulik", "Architekt", "Fotograf", "Rolnik", "Rybak",
    "Kelner", "Krawiec", "Listonosz", "Stolarz", "Murarz"
};

baza_hasel["Sport"] = {
    "Boks", "Tenis", "Hokej", "Golf", "Judo",
    "Karate", "Bieganie", "Kolarstwo", "Badminton",
    "Bilard", "Rugby", "Squash", "Maraton", "Slalom",
    "Triathlon"
};

baza_hasel["Pojazdy"] = {
    "Rower", "Motor", "Skuter", "Traktor", "Autobus",
    "Samolot", "Helikopter", "Kajak",
    "Prom", "Tramwaj", "Trolejbus"
};

baza_hasel["Miejsca"] = {
    "Szpital", "Apteka", "Piekarnia", "Kino", "Teatr",
    "Muzeum", "Hotel", "Lotnisko", "Dworzec", "Stadion",
    "Park", "Las", "Plaza", "Wyspa", "Pustynia",
    "Jaskinia", "Zamek",  "Biblioteka"
};

baza_hasel["Muzyka"] = {
    "Gitara", "Pianino", "Perkusja", "Skrzypce", "Flet",
     "Akordeon", "Koncert", "Orkiestra",
    "Melodia", "Rytm", "Opera", "Balet", "Taniec"
};

baza_hasel["Natura"] = {
    "Las", "Rzeka", "Morze", "Ocean", "Gora",
    "Wulkan", "Wodospad", "Jezioro", "Pustynia",
    "Jaskinia",  "Piasek", "Wiatr", "Deszcz",
    "Burza", "Chmura", "Trawa", "Kwiat"
};

return baza_hasel;
}

void wczytaj_graczy_i_imiona(int liczba_rund, int liczba_graczy) {
    vector<Gracz> gracze; // vektor typu danych Gracz o nazwie gracze
    cout << liczba_graczy << " graczy zostalo wybranych. \n" << endl;
    cout << liczba_rund << " rund zostalo wybranych. \n" << endl;

    // pętla do wczytywania każdego imienia graczy
    for (int i = 0; i < liczba_graczy; i++) {
        Gracz nowy_gracz;
            cout << "Podaj imie gracza " << (i + 1) << ": ";
            getline(cin, nowy_gracz.imie); // cin >> zatrzymuje sie na spacji, getline() wczytuje całe imię, nawet jeśli zawiera spacje.
            nowy_gracz.punkty = 0; // inicjalizacja punktów gracza na 0
            gracze.push_back(nowy_gracz); // dodanie gracza do wektora
    }

    for (int j=0; j<gracze.size(); j++) {
        cout << "Gracz " << (j + 1) << ": " << gracze[j].imie << "  | Punkty: " << gracze[j].punkty << endl;
    }


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
            wczytaj_graczy_i_imiona(liczba_rund, liczba_graczy);
            utworz_baze_hasel();
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