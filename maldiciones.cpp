#include <iostream>
using namespace std;
#include <string>

#include "dados.h"
#include "funciones.h"
#include "jugador.h"

void activarMaldicion(int maldicionElegida, Jugador& jugador, Jugador& rival, int dado) {


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

      case 2:
            {
                 // maldición aguila
                 cout << endl <<  jugador.nombre << " fue afectado con la maldicion del aguila. " << endl << endl;
                 cout << rival.nombre << " comenzará a tirar dos veces por turno hasta el fin de la fase." << endl;

                 break;
            }


      case 3:
            {
                int dadoaux = 0;
                int puntajeADescontar = 0;

               //maldición hormiga
               cout << endl <<  jugador.nombre << " fue afectado con la maldicion de la hormiga. " << endl << endl;
               cout << rival.nombre << " lance dos dado de 10 caras; su valor se restará de los puntos de victoria de " << jugador.nombre << " al final de la partida." << endl;
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

      case 4:
            {

           // maldición salamandra
           cout << rival.nombre << " jugará con tres dados hasta el fin de la fase." << endl;


            //Si el rival tiene la maldicion de la salamandra, activo el 3er turno


            if (rival.maldiciones[3] > 0){
                cout << endl << "Ya que " << rival.nombre << " posee la maldicion de la salamandra, el jugador " << jugador.nombre << " tira un tercer dado" << endl;
                esperarEnter();
                tirarDado( dado, 10);
                mostrarDado( dado );
            }


               break;
            }

      case 5:
            {
               // maldición medusa
               cout << jugador.nombre << " pierde tres turnos." << endl;

               break;
            }

	}
}

void guardarMaldicion(int maldicionElegida, Jugador& jugador)
{

    if( maldicionElegida > 0 && maldicionElegida <= 5 )
    {
        jugador.maldiciones[ maldicionElegida - 1]++;
    }else{
        cout << "El numero de maldicion no coincide" << endl;
    }

}
