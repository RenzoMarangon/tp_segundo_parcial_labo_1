#include <iostream>
#include "funciones.h"
#include <string>
#include <cstdlib>

using namespace std;

void esperarEnter()
{
    fflush(stdout); // Limpiar el búfer de salida

    // Esperar a que el usuario presione Enter
    while (getchar() != '\n');
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



