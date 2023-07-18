#include <iostream>
#include <string>
#include <cstdlib>
#include <wchar.h>
#include <conio.h>

#include "funciones.h"
#include "rlutil.h"

using namespace std;

void esperarEnter()
{
    //Ignora si aprete un enter en medio de dos tiradas.
	if (_kbhit()) {
		std::cin.ignore();
	}

	// Limpiar el búfer de salida.
	fflush(stdout);
	fflush(stdin);

	// Esperar a que el usuario presione Enter.
	while (getchar() != '\n');
}

void limpiarConsola()
{
    rlutil::cls();
}

void salir()
{
    cout << endl << "Saliendo del juego..." << endl;
    exit(0);
    return;
}

int random(int limite)
{
    return rand() % limite + 1;
}

bool numerosCorrelativos( int num1, int num2, int num3, int num4, int num5, int num6 )
{

    int numeros[6] = { num1, num2, num3, num4, num5, num6 };

    int aux = 0;

    for( int i = 0; i < 5; i++)
    {
        for( int j = 0; j < 5 ; j++)
        {
                if(numeros[j] > numeros[j +1 ] )
                {
                    aux = numeros[j];
                    numeros[j] = numeros[j +1 ];
                    numeros[j +1 ] = aux;
                }
        }
    }

    for( int i = 0; i < 5; i++ )
    {
        if( numeros[i] != numeros[i+1] - 1 )
        {
            return false;
        }
    }

    return true;

}

bool numerosIguales(  int num1, int num2, int num3, int num4, int num5, int num6  )
{
    int numeros[6] = { num1, num2, num3, num4, num5, num6 };

    for( int i = 0; i < 6; i++ )
    {
        for( int j = 0; j < 5; j++ )
        {
            if( numeros[i] != numeros[j] )
            {
                return false;
            }
        }
    }

    return true;

}



