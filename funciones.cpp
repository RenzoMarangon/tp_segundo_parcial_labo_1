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



