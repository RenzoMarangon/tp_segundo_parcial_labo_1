#include <iostream>
#include "menu.h"
#include "funciones.h"
#include "juego.h"
using namespace std;

void mostrarMenu()
{

    char a = 201; // ╔
    char b = 205; // ═
    char c = 187; // ╗
    char d = 186; // ║
    char e = 200; // ╚
    char f = 188; // ╝
    char h = 185; // ╣
    char g = 174; //«
    char j = 175; //»

    int i;

    do{
        cout <<" " << g << b << h << b << b << b << "IRWIN'S" << b << "REVENGE" << j << endl;
        cout << a << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << c << endl;
        cout << d << "   1 - JUGAR           " << d << endl;
        cout << d << "   2 - ESTADISTICAS    " << d << endl;
        cout << d << "   1 - CREDITOS        " << d << endl;
        cout << d << "   0 - SALIR           " << d << endl;
        cout << e << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << f << endl;

        cout << endl << "INGRESAR OPCION: ";
        cin >> i;

        switch(i)
        {
            case 1:
                {
                    return;
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
            default:{
                esperarEnter();
                cout << endl << "Opcion incorrecta, presione enter para volver al menu." << endl << endl << endl;
                esperarEnter();
            }
        }
    }while( i < 0 || i > 3 );
}

void mostrarMenuEstatuillas()
{
    // INICIO DEL MENU ELEGIR ESTATUILLA
    char a = 201; // ╔
    char b = 205; // ═
    char c = 187; // ╗
    char d = 186; // ║
    char e = 200; // ╚
    char f = 188; // ╝
    char h = 185; // ╣
    char g = 174; //«
    char j = 175; //»

    cout << a << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << c << endl;
    cout << d << "  1 - Cangrejo de arena    " << d << endl;
    cout << d << "  2 - Aguila de aire       " << d << endl;
    cout << d << "  3 - Hormiga de tierra    " << d << endl;
    cout << d << "  4 - Salamandra de fuego  " << d << endl;
    cout << d << "  5 - Medusa de agua       " << d << endl;
    cout << e << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << f << endl;
    // FIN DEL MENU ELEGIR ESTATUILLA
}



