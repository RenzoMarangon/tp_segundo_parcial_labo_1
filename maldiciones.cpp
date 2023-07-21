#include <iostream>
using namespace std;
#include <string>

#include "dados.h"
#include "funciones.h"
#include "jugador.h"


void guardarMaldicion(int maldicionElegida, Jugador& jugador)
{


    if( maldicionElegida > 0 && maldicionElegida <= 5 && maldicionElegida != 3)
    {
        jugador.maldiciones[ maldicionElegida - 1]++;

    //Maldicion medusa
    }else if( maldicionElegida == 3)
    {
        jugador.maldiciones[ 2 ] = jugador.maldiciones[ 2 ] + 3;
    }else{
        cout << "El numero de maldicion no coincide" << endl;
    }


}



void activarMaldicionCangrejo( Jugador& jugador, Jugador rival, int& dado )
{
    if(jugador.maldiciones[0] > 0)
    {
        cout <<"Oh no! el jugador " << jugador.nombre << " fue afectado con la maldicion del cangrejo." << endl;

        jugadorTiraDado( rival , dado, 10 );


        jugador.puntaje = jugador.puntaje - dado;

        cout << "Se le han descontado " << dado << " puntos al jugador " << jugador.nombre << endl;

        jugador.maldiciones[ 0 ]--;
    }

}

void activarMaldicionHormiga( Jugador& jugador, Jugador rival, int& dado1, int& dado2, int& dado3 )
{
    if(jugador.maldiciones[1])
    {
        cout <<"Oh no! el jugador " << jugador.nombre << " fue afectado con la maldicion de la hormiga." << endl;

        jugadorTiraDado( rival , dado1, 10 );
        jugadorTiraDado( rival , dado2, 10 );

        if( jugador.maldiciones[ 4 ] > 0)
        {
            jugadorTiraDado( rival, dado3, 10 );
        }

        jugador.puntaje = jugador.puntaje - dado1 - dado2;

        cout << "Se le han descontado " << dado1 + dado2 << " puntos al jugador " << jugador.nombre << endl;

        jugador.maldiciones[1]--;
    }

}

void activarMaldicionMedusa(Jugador& jugador)
{
    //Si tiene maldicion de medusa quito un turno no jugado
    limpiarConsola();
    cout << "El jugador " << jugador.nombre <<" fue afectado por la maldicion de la medusa, le quedan " << jugador.maldiciones[2] << " turnos sin jugar." << endl;
    jugador.maldiciones[2]--;
    cout << endl << "Presione ENTER para pasar el turno.";
    esperarEnter();
    limpiarConsola();
}

void activarMaldicionAguila( Jugador jugador, Jugador rival, int& dado1, int& dado2, bool hack )
{

    if(jugador.maldiciones[3] > 0 )
    {
        cout << endl << "Oh no! el jugador " << rival.nombre << " fue afectado con la maldicion del Aguila." << endl;


        if( hack )
        {
            elegirDado(jugador, dado1, 10);
            elegirDado(jugador, dado2, 10);
        }else{

            jugadorTiraDado( jugador , dado1, 10 );
            jugadorTiraDado( jugador , dado2, 10 );
        }


    }


}

void activarMaldicionSalamandra( Jugador jugador, Jugador rival, int& dado, bool hack  )
{
    if( rival.maldiciones[4] > 0 )
    {
        cout << endl << "Tu rival fue afectado por la maldicion de la salamandra." << endl;
        if( hack )
        {
            elegirDado(jugador, dado, 10);
        }else{
           jugadorTiraDado( jugador, dado, 10);
        }
    }

}





