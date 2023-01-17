#include <iostream>
#include"Gioco.h";
#include"NodoAlbero.h";
#include"Albero.h";

/*

    ZAHID MEHDI
    ZORZI LUCA

    4^AIA

*/


using namespace std;

int Menu();

int main()
{
    Gioco gioco;

    int scelta;

    do{
        scelta = Menu();

        switch (scelta) {
        case 1:

            system("cls");
            gioco.Game();
            system("cls");
            break;

        case 2:
            system("cls");
            gioco.SavePlay();
            break;


        case 3:
            system("cls");
            gioco.LoadGameFromFile();
            break;

        case 4:
            system("cls");
            cout << "Lista giocatori:\n";
            gioco.ViewAllPlayers();
            break;

        case 5:
            system("cls");
            cout << "Lista giocatori che hanno vinto:\n";
            gioco.ViewWinnerPlayers();
            break;

        case 6:
            system("cls");
            cout << "Lista giocatori perdenti:\n";
            gioco.ViewLoserPlayers();
            break;

        }



    } while (scelta < 7);

    
}

int Menu()
{
    int scelta;
    do {
        cout << "\n1. Gioca";
        cout << "\n2. Salva Gioco";
        cout << "\n3. Carica Gioco";
        cout << "\n4. Visualizza Tutti i Giocatori";
        cout << "\n5. Visualizza Tutti i Vincitori";
        cout << "\n6. Visualizza Tutti i Perdenti";
        cout << "\n7. Esci dal Gioco";
        cout << "\nScelta: ";
        cin >> scelta;
    } while (scelta > 7 || scelta < 1);

    return scelta;
}