#include <iostream>
using namespace std;
#include <string>

#include "dados.h"
#include "funciones.h"

void activarMaldicion(int estatuillaElegida, int maldiciones[][5], string jugador, string rival, int numJugador, int numeroRival, int dado) {

	switch (estatuillaElegida){
		case 1:
            {
                int dadoaux = 0;
               // maldición cangrejo
               cout << rival << " lance un dado de 10 caras; su valor se restará de los puntos de victoria de " << jugador << " al final de la partida." << endl;
               cout << "Presione enter para tirar..." << endl;
               esperarEnter ();

                tirarDado (dadoaux, 10);
                mostrarDado (dadoaux);

                //ACA HAY QUE RESTAR PUNTOS

               break;
            }

      case 2:
            {
                 // maldición aguila
                 cout << endl <<  jugador << " fue afectado con la maldicion del aguila. " << endl << endl;
                 cout << rival << " comenzará a tirar dos veces por turno hasta el fin de la fase." << endl;

                 break;
            }


      case 3:
            {
                int dadoaux = 0;

               //maldición hormiga
               cout << endl <<  jugador << " fue afectado con la maldicion de la hormiga. " << endl << endl;
               cout << rival << " lance dos dado de 10 caras; su valor se restará de los puntos de victoria de " << jugador << " al final de la partida." << endl;
               cout << "Presione enter para tirar..." << endl;
               esperarEnter ();

               for(int i=0; i<2; i++){
                    tirarDado (dadoaux, 10);
                    mostrarDado (dadoaux);

                    //ACA HAY QUE RESTAURAR PUNTOS
               }

               break;
            }

      case 4:
            {

           // maldición salamandra
           cout << rival << " jugará con tres dados hasta el fin de la fase." << endl;


            //Si el rival tiene la maldicion de la salamandra, activo el 3er turno

            /*
            if (maldiciones[0][3] > 0){
                cout << endl << "Ya que " << rival << " posee la maldicion de la salamandra, tire un tercer dado. "<< endl;
                esperarEnter();
                tirarDado( dado, 10);
                mostrarDado( dado );
            }
            */

               break;
            }

      case 5:
            {
               // maldición medusa
               cout << jugador << " pierde tres turnos." << endl;

               break;
            }

	}
}

void guardarMaldicion(int estatuillaElegida, int maldiciones[][5],  int numJugador )
{

    if( estatuillaElegida > 0 && estatuillaElegida <= 5 )
    {
        maldiciones[ numJugador ][ estatuillaElegida - 1]++;
    }else{
        cout << "El numero de estatuilla no coincide" << endl;
    }

}
