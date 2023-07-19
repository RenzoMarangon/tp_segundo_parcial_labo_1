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

void activarBendicionCangrejo( Jugador jugador, bool hack, int& dado1, int& dado2, int& dado3, int& dado4, int& dado5, int& dado6 )
{
    cout << endl << "El jugador " << jugador.nombre << " fue afectado por la bendicion del cangrejo."<< endl;
    cout << "Vuelve a tirar los dados." << endl << endl;


    if( hack )
    {
        elegirDado(jugador2, dado1, 10);
        elegirDado(jugador2, dado2, 10);
        elegirDado(jugador2, dado3, 10);
        elegirDado(jugador2, dado4, 10);
        elegirDado(jugador2, dado5, 10);
        elegirDado(jugador2, dado6, 10);
    }else{
        jugadorTiraDado(jugador2, dado1, 10);
        jugadorTiraDado(jugador2, dado2, 10);
        jugadorTiraDado(jugador2, dado3, 10);
        jugadorTiraDado(jugador2, dado4, 10);
        jugadorTiraDado(jugador2, dado5, 10);
        jugadorTiraDado(jugador2, dado6, 10);
    }
}
