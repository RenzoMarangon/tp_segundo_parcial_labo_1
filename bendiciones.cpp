#include <iostream>

using namespace std;

#include "jugador.h"

int guardarBendicion( int estatuillaElegida, Jugador& jugador ) {

   if( estatuillaElegida > 0 && estatuillaElegida <= 5 )
    {
        jugador.bendiciones[ estatuillaElegida - 1]++;
    }else{
        cout << "El numero de estatuilla no coincide" << endl;
    }
}
