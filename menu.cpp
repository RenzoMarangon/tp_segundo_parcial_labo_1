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

    int opcion;
    bool flag_estadisticas=false;
    char confirmacion;

    do{
        cout <<" " << g << b << h << b << b << b << "IRWIN'S" << b << "REVENGE" << j << endl;
        cout << a << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << c << endl;
        cout << d << "   1 - JUGAR           " << d << endl;
        cout << d << "   2 - ESTADISTICAS    " << d << endl;
        cout << d << "   1 - CREDITOS        " << d << endl;
        cout << d << "   0 - SALIR           " << d << endl;
        cout << e << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << f << endl;

        cout << endl << "INGRESAR OPCION: ";
        cin >> opcion;
        cout << endl;

        switch(opcion)
        {
            case 1:
                {
                    iniciarJuego();
                    break;
                }
            case 2:
                {
                    //mostrarReglamento();
                    break;
                }
            case 3:
                {
                    if (flag_estadisticas==false){
                        cout << "Las estadísticas muestran al jugador con la mayor cantidad de puntos de victoria." << endl;
                        cout << "Desafia a un amigo a jugar Irwin's Revange para desbloquear la sección." << endl << endl;
                    }else{
                        mostrarEstadisticas();
                    }
                    break;
                }
            case 4:
                {
                    mostrarCreditos();
                }
            case 0:
                {
                     cout << "¿Está seguro de que quiere salir? (S/ N)" << endl;
                     cin >> confirmacion;

                     if (confirmacion == 'S' || confirmacion == 's'){
                        salir();
                     }
                    break;
                }
            default:{
                esperarEnter();
                cout << endl << "Opcion incorrecta, presione enter para volver al menu." << endl << endl << endl;
                esperarEnter();
            }
        }
    }while( opcion < 0 || opcion > 4 );
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



