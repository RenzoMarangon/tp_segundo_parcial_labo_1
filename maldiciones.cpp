#include <iostream>
using namespace std;
#include <string>

#include "dados.h"
#include "funciones.h"
#include "jugador.h"

void activarMaldicionesRestarPuntos(int maldicionElegida, Jugador& jugador, Jugador& rival) {


	switch (maldicionElegida){
		case 1:
            {
                int dadoaux = 0;
               // maldición cangrejo
               cout << rival.nombre << " Lance un dado de 10 caras, su valor se restará de los puntos de victoria de " << jugador.nombre << " al final de la partida." << endl;
               cout << "Presione enter para tirar..." << endl;
               esperarEnter ();

                tirarDado (dadoaux, 10);
                mostrarDado (dadoaux);

                jugador.puntaje - 10;
                cout << "Se le han restado 10 puntos al jugador " << jugador.nombre << endl;

               break;
            }


      case 3:
            {
                int dadoaux = 0;
                int puntajeADescontar = 0;

               //maldición hormiga
               cout << endl <<  jugador.nombre << " fue afectado con la maldicion de la hormiga. " << endl << endl;
               cout << rival.nombre << " lance dos dado de 10 caras, su valor se restará de los puntos de victoria de " << jugador.nombre << " al final de la partida." << endl;
               cout << "Presione enter para tirar el primer dado." << endl;
               esperarEnter ();

                tirarDado(dadoaux, 10);
                mostrarDado(dadoaux);

                puntajeADescontar += dadoaux;
                dadoaux = 0;

                cout << endl << "Vuelva a presionar ENTER para tirar el segundo dado." << endl;

                tirarDado(dadoaux, 10);
                mostrarDado(dadoaux);

                puntajeADescontar += dadoaux;

                jugador.puntaje - puntajeADescontar;

                cout << endl << "Se le descontaron " << puntajeADescontar << " al jugador " << jugador.nombre << endl;

               break;
            }
	}
}

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

void activarMaldicionAguila( Jugador jugador, Jugador rival, int& dado1, int& dado2, bool hack )
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

void activarMaldicionCangrejo( Jugador jugador, Jugador rival, int dado )
{
    cout <<"Oh no! el jugador " << rival.nombre << " fue afectado con la maldicion del cangrejo." << endl;

    jugadorTiraDado( jugador , dado, 10 );


    jugador.puntaje = jugador.puntaje - dado;

    cout << "Se le han descontado " << dado << " puntos al jugador " << rival.nombre << endl;
}

void activarMaldicionHormiga( Jugador jugador, Jugador rival, int dado1, int dado2, int dado3 )
{
    cout <<"Oh no! el jugador " << rival.nombre << " fue afectado con la maldicion de la hormiga." << endl;

    jugadorTiraDado( jugador , dado1, 10 );
    jugadorTiraDado( jugador , dado2, 10 );

    if( rival.maldiciones[ 4 ] > 0)
    {
        jugadorTiraDado( jugador, dado3, 10 );
    }

    jugador.puntaje = jugador.puntaje - dado1 - dado2;

    cout << "Se le han descontado " << dado1 + dado2 << " puntos al jugador " << rival.nombre << endl;
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

void activarMaldicionSalamandra( Jugador jugador, int& dado, bool hack  )
{
    cout << endl << "Tu rival fue afectado por la maldicion de la salamandra." << endl;
    if( hack )
    {
        elegirDado(jugador, dado, 10);
    }else
    {
           jugadorTiraDado( jugador, dado, 10);
    }


}





