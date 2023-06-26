#include <iostream>
using namespace std;
#include <string>
#include "funciones.h"
#include "menu.h"

int elegirEstatuilla(string jugador, int* estatuillasElegidas)
{
    int estatuillaElegida;
    string estatuillas[] = { "Cangrejo de arena", "Aguila de aire", "Hormiga de tierra", "Salamandra de fuego", "Medusa de agua" };
    bool estatuillaElegidaYaExiste = false;
    string usuarioElige;

    do{
        estatuillaElegidaYaExiste = false;

        cout << endl << "Menu para elegir estatuillas" << endl;
        mostrarMenuEstatuillas();


        cout << endl << jugador << " elija una opcion: " << endl;
        cin >> estatuillaElegida;

        //Verifico que la estatuilla no exista
        for( int i; i<5; i++)
        {
            if( estatuillasElegidas[estatuillaElegida] > 0 )
            {
                estatuillaElegidaYaExiste = true;
            }
        }

        //Si la opcion ingresada no es valida muestro un cartel
        if( estatuillaElegida > 5 || estatuillaElegida < 1 )
        {
            esperarEnter();
            cout << endl << "La opcion elegida es incorrecta, presione enter para volver a elegir. " << endl << endl;
            esperarEnter();
            estatuillaElegidaYaExiste = true;
        }


        if( !estatuillaElegidaYaExiste )
        {
            cout << endl << "Usted eligio la estatuilla: " << estatuillas[estatuillaElegida-1] << ". Escriba 'si' para continuar o 'no' para rechazar " << endl;
            cin >> usuarioElige;
            if( usuarioElige != "si" && usuarioElige != "Si" && usuarioElige != "SI" && usuarioElige != "S" && usuarioElige != "s")
            {
                estatuillaElegidaYaExiste = true;
                esperarEnter();
                cout << "Para volver al menu de estatuillas presione enter." << endl;
                esperarEnter();
            }
        }

    //Mientras el usuario haya ingresado una opcion invalida o la estatuilla ya este en juego vuelvo a repetir
    } while( estatuillaElegida > 5 || estatuillaElegida < 1 || estatuillaElegidaYaExiste );

    //Si esta todo bien retorno la estatuilla elegida
    return estatuillaElegida;
}

bool cumpleConRequisitosEstatuilla(int estatuilla, int dado1, int dado2 )
{
    bool cumple = false;
    switch( estatuilla )
    {
        //1 dado par 1 dado impar
        case 1:
        {
            if ( dado1 % 2 != 0 && dado2 % 2 == 0 || dado1 % 2 == 0 && dado2 % 2 != 0)
            {
                cumple = true;
            }
            break;
        }

        //2 dados menores a 5
        case 2:
        {
            if( dado1 < 5 && dado2 < 5)
            {
                cumple = true;
            }
            break;
        }

        //Suma de los dados == 7
        case 3:
        {
            if( dado1 + dado2 == 7)
            {
                cumple = true;
            }
            break;
        }
        //dado con 1 y dado con 10
        case 4:
        {
            if( dado1 == 1 && dado2 == 10 || dado1 == 10 && dado2 == 1)
            {
                cumple = true;
            }
            break;
        }

        //dados consecutivos
        case 5:
        {
            if( dado1 == dado2+1 || dado2 == dado1+1 )
            {
                cumple = true;
            }
            break;
        }
        default:
        {
            cout << endl  << "Opcion incorrecta " << endl;
            break;
        }
    }

    return cumple;
}
