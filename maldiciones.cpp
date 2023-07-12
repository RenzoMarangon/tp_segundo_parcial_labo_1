#include <iostream>
using namespace std;
#include <string>

#include "dados.h"
#include "funciones.h"
#include "jugador.h"

void activarMaldicion(int estatuillaElegida, Jugador jugador, Jugador rival, int dado) {

	switch (estatuillaElegida){
		case 1:
            {
                int dadoaux = 0;
               // maldición cangrejo
               cout << rival.nombre << " lance un dado de 10 caras; su valor se restará de los puntos de victoria de " << jugador.nombre << " al final de la partida." << endl;
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
                 cout << endl <<  jugador.nombre << " fue afectado con la maldicion del aguila. " << endl << endl;
                 cout << rival.nombre << " comenzará a tirar dos veces por turno hasta el fin de la fase." << endl;

                 break;
            }


      case 3:
            {
                int dadoaux = 0;

               //maldición hormiga
               cout << endl <<  jugador.nombre << " fue afectado con la maldicion de la hormiga. " << endl << endl;
               cout << rival.nombre << " lance dos dado de 10 caras; su valor se restará de los puntos de victoria de " << jugador.nombre << " al final de la partida." << endl;
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
           cout << rival.nombre << " jugará con tres dados hasta el fin de la fase." << endl;


            //Si el rival tiene la maldicion de la salamandra, activo el 3er turno

            /*
            if (maldiciones[0][3] > 0){
                cout << endl << "Ya que " << rival.nombre << " posee la maldicion de la salamandra, tire un tercer dado. "<< endl;
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
               cout << jugador.nombre << " pierde tres turnos." << endl;

               break;
            }

	}
}

void guardarMaldicion(int estatuillaElegida, Jugador jugador)
{

    if( estatuillaElegida > 0 && estatuillaElegida <= 5 )
    {
        jugador.estatuillas[ estatuillaElegida - 1]++;
    }else{
        cout << "El numero de estatuilla no coincide" << endl;
    }

}
