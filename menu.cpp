#include <iostream>
#include "menu.h"
#include "funciones.h"
#include "juego.h"
using namespace std;

void mostrarMenu()
{
    int i;



    do{
        cout << "IRWIN'S REVENGE" << endl;
        cout << "------------------------------" << endl;
        cout << "1 - JUGAR PARA DOS JUGADORES" << endl;
        cout << "2 - ESTADISTICAS" << endl;
        cout << "3 - CREDITOS" << endl;
        cout << "------------------------------" << endl;
        cout << "0 - SALIR" << endl;

        cout << endl << "INGRESAR OPCION: ";
        cin >> i;
        cout << endl << endl << endl;

        switch(i)
        {
            case 1:
                {
                    iniciarJuego();
                    break;
                }
            case 2:
                {
                    mostrarEstadisticas();
                    mostrarMenu();
                    break;
                }
            case 3:
                {
                    mostrarCreditos();
                    mostrarMenu();
                    break;
                }
            case 0:
                {
                    salir();
                    break;
                }
            default:{}
        }
    }while( i < 0 || i > 4 );


}


