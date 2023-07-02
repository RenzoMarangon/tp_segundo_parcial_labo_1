#include <iostream>
using namespace std;
#include <string>

#include "dados.h"
#include "funciones.h"

int activarMaldicion(int estatuillaElegida, string jugador, string rival, int numJugador, int* maldiciones) {

   int dadoaux, maldicion;

	switch (estatuillaElegida){
		case 1:
            {
               // maldici�n cangrejo
               cout << rival << " lance un dado de 10 caras; su valor se restar� de los puntos de victoria de " << jugador << " al final de la partida." << endl;
               cout << "Presione enter para tirar..." << endl;
               esperarEnter ();

               tirarDado (dadoaux, 10);
               mostrarDado (dadoaux);

               maldiciones[ numJugador ][0]++;

               return dadoaux;
               break;
            }

      case 2:
            {
                 // maldici�n aguila
                 cout << endl <<  jugador << " fue afectado con la maldicion del aguila. " << endl << endl;
                 cout << rival << " comenzar� a tirar dos veces por turno hasta el fin de la fase." << endl;
                 maldiciones[ numJugador ][1]++;
                 return 1;
                 break;
            }


      case 3:
            {
               //maldici�n hormiga
               cout << endl <<  jugador << " fue afectado con la maldicion de la hormiga. " << endl << endl;
               cout << rival << " lance dos dado de 10 caras; su valor se restar� de los puntos de victoria de " << jugador << " al final de la partida." << endl;
               cout << "Presione enter para tirar..." << endl;
               esperarEnter ();

               for(int i=0; i<2; i++){
                    tirarDado (dadoaux, 10);
                    mostrarDado (dadoaux);

                    maldicion += dadoaux;
               }

               maldiciones[ numJugador ][2]++;
               return maldicion;
               break;
            }

      case 4:
            {

               // maldici�n salamandra
               cout << rival << " jugar� con tres dados hasta el fin de la fase." << endl;
               maldiciones[ numJugador ][3]++;

               return 1;
               break;
            }

      case 5:
            {
               // maldici�n medusa
               cout << jugador << " pierde tres turnos." << endl;
               maldiciones[ numJugador ][4]++;
               return 1;
               break;
            }

	}
}
