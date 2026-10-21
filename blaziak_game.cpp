#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

int main() {
    char wybor_menu; //zmienna do przechowywania wyboru gracza w menu gry
    
    struct Character // struktura dla każdej postaci w grze 
{
    string name; //name of the character

    int hp; //current health points
    int maxHP; //max health points (on start hp=maxHP)

    int ad; //attack damage
    int ap; //ability power

    int armor; //physical armor
    int mr; //magic resist
};

    //enemy characters
        Character goblin;
        {
    goblin.name = "Goblin";
    goblin.hp = 80;
    goblin.maxHP = 80;
    goblin.ad = 12;
    goblin.ap = 0;
    goblin.armor = 5;
    goblin.mr = 10;}

        Character wilkolak;
        {
wilkolak.name = "Wilkolak";
wilkolak.hp = 150;
wilkolak.maxHP = 150;
wilkolak.ad = 20;
wilkolak.ap = 5;
wilkolak.armor = 12;
wilkolak.mr = 8;}

    //player characters
        Character Dr_Rakieta;
        {
            Dr_Rakieta.name = "Dr. Rakieta";
            Dr_Rakieta.hp = 100;
            Dr_Rakieta.maxHP = 100;
            Dr_Rakieta.ad = 30;
            Dr_Rakieta.ap = 1;
            Dr_Rakieta.armor = 8;
            Dr_Rakieta.mr = 15;
        }
        
        Character Majster_Radziu;
        {
            Majster_Radziu.name = "Majster_Radziu";
            Majster_Radziu.hp = 120;
            Majster_Radziu.maxHP = 120;
            Majster_Radziu.ad = 4;
            Majster_Radziu.ap = 23;
            Majster_Radziu.armor = 10;
            Majster_Radziu.mr = 25;
        }

        //menu gry
            do //pętla do while służy do wyświetlania menu gry i oczekiwania na wybór gracza w nieskończoność w sytuacji wyboru innych opcji niż start gry lub wyjście z gry.
            {
                cout << "Witaj w grze!" << endl;
                cout << "Nacisnij '1', aby rozpoczac gre" << endl;
                cout << "Nacisnij '2', aby wyjsc z gry" << endl;

                wybor_menu = _getch(); //pobranie znaku wprowadzonego przez gracza z klawiatury (bez potrzeby wciskania Enter po wprowadzeniu znaku)

                if (wybor_menu == '1')
                {
                    cout << "Wybrales rozpoczecie gry!" << endl;
                    break; //wyjście z pętli do while i rozpoczęcie gry
                }

                else if (wybor_menu == '2')
                {
                    cout << "Wybrales wyjscie z gry!" << endl;
                    return 0; //zakończenie programu
                }
                else
                {
                    cout << "Niepoprawny wybor! Sprobuj ponownie." << endl;
                    
                }

            } 
            while (true); //pętla do while kończy się dopiero po wybraniu opcji rozpoczęcia gry lub wyjścia z gry, true oznacza, że pętla będzie się wykonywać w nieskończoność dopóki nie zostanie przerwana przez break lub return.

return 0;
}

        


           


        
