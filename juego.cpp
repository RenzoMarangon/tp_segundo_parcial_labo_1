#include <iostream>
using namespace std;
#include <string>
#include "juego.h"
#include "funciones.h"
#include "dados.h"
#include "menu.h"
#include "estatuillas.h"
#include "maldiciones.h"
#include "bendiciones.h"
#include "jugador.h"

void quienEmpieza(Jugador &j1, Jugador &j2, int dado1, int dado2)
{
    do{
        jugadorTiraDado( j1 , dado1, 10 );

        jugadorTiraDado( j2 , dado2, 10 );

        cout << endl;
        if( dado1 == dado2)
        {
            cout << endl << "Numeros iguales, presione enter para volver a tirar los dados."<<endl;
            esperarEnter();
        }

    }while( dado1 == dado2 );


    //Si el dado que tiro el segundo jugador es mas chico que el dado del primer jugador...
    //cambio el orden de los jugadores, en j1 pongo el valor del jugador que empieza y j2 el segundo

    Jugador aux;
    if( dado2 < dado1 )
    {
        aux = j1;
        j1 = j2;
        j2 = aux;
    }

    cout << j1.nombre << " tira los dados primero. Presione enter para continuar..." << endl << endl;
    esperarEnter();
}



void iniciarJuego()
{


    string j1, j2, nombre_mj;
    int dado1 = 0, dado2 = 0, dado3 = 0;

    bool cumple;

    //Ingreso los nombres y creo  los jugadores
    cout << endl << "Ingresar un nombre del primer jugador: ";
    cin >> j1;
    cout << endl;
    cout << "Ingresar nombre del segundo jugador: ";
    cin >> j2;
    cout << endl << endl;

    Jugador jugador1 = crearJugador( j1, 0 );
    Jugador jugador2 = crearJugador( j2, 0 );




    if ( jugador1.nombre != "Lab1" && jugador1.nombre != "lab1" && jugador1.nombre != "LAB1" )
        {
            cout << "Recuerden, el jugador que saque menor numero comienza la partida." << endl << endl;



            quienEmpieza(jugador1, jugador2, dado1, dado2);

            iniciarFaseExpedicion( jugador1, jugador2, dado1, dado2, dado3 );

        }

      std::cout << jugador1.nombre << std::endl;
    for( int i = 0; i<5; i++)
    {
        std::cout << jugador1.estatuillas[i] << std::endl;

    }

    std::cout << jugador2.nombre << std::endl;
        for( int i = 0; i<5; i++)
    {
        std::cout << jugador2.estatuillas[i] << std::endl;

    }



}

void iniciarFaseExpedicion( Jugador& jugador1, Jugador& jugador2, int &dado1, int &dado2, int &dado3)
{



    //Inicializo la cantidad de estatuillas en juego, la cantidad que se utilizaron y la que se esta usando en el turno
    int cantEstatuillasEnJuego = 0;
    int estatuillaElegida = 0;
    int estatuillasElegidas[5] = {0};

    bool trueTiraJ1FalseTiraJ2 = true;
    bool cumpleRequisitoEstatuilla = false;

    limpiarConsola();
    cout << "  FASE DE EXPEDICION" << endl;

    while( cantEstatuillasEnJuego < 2 )
    {
        //NOTA: se pide tocar 2 veces enter para que cambie el numero random
        if( trueTiraJ1FalseTiraJ2 )
            //Tira J1
        {

            estatuillaElegida = elegirEstatuilla(jugador1.nombre, estatuillasElegidas);

            jugadorTiraDado( jugador1 , dado1, 6 );

            jugadorTiraDado( jugador1 , dado2, 6 );

            for( int i = 0; i < 5; i++ )
            {
                if( jugador1.maldiciones[i] > 0 )
                {

                    activarMaldicion(i, jugador1, jugador2, dado3);
                }

            }

        }else{
            //Tira J2

            estatuillaElegida = elegirEstatuilla(jugador2.nombre, estatuillasElegidas);

            jugadorTiraDado( jugador2 , dado1, 6 );
            jugadorTiraDado( jugador2 , dado2, 6 );

            cumpleRequisitoEstatuilla = cumpleConRequisitosEstatuilla( estatuillaElegida, dado1, dado2, dado3 );


            if(cumpleRequisitoEstatuilla)
            {
                jugador2.estatuillas[ estatuillaElegida - 1 ]++;

                guardarBendicion( estatuillaElegida, jugador2 );
                guardarMaldicion( estatuillaElegida, jugador2);
            }


            //Pregunto por maldicion de Aguila (tirar 2 veces)
            if( jugador1.maldiciones[1] > 0 && !cumpleRequisitoEstatuilla )
            {
                cout << endl << "El jugador " << jugador1.nombre << " fue afectado con la maldicion del Aguila, vuelva a tirar los dados.";
            }


            for( int i = 0; i < 5; i++ )
            {
                if( jugador2.maldiciones[i] > 0 )
                {
                     activarMaldicion(i, jugador2, jugador1, dado3);
                }

            }

        }


        //Una vez que eligio la estatuilla, si cumple la condicion...
        if( cumpleConRequisitosEstatuilla( estatuillaElegida, dado1, dado2, dado3 ) )
        {
            //Pregunto si jugador 1 o jugador 2 tiraron los dados
            if( trueTiraJ1FalseTiraJ2 )
            {
                jugador1.estatuillas[ estatuillaElegida -1 ]++;

                //guardarBendicion( estatuillaElegida, bendiciones, 0 );
                guardarMaldicion( estatuillaElegida, jugador1);

            }else{

            }

            cout << endl << "Felicidades! usted adquirio la estatuilla #" << estatuillaElegida << endl;
            cout << endl << "Presione ENTER para volver a elegir estatuillas." << endl << endl << endl;
            estatuillasElegidas[ estatuillaElegida - 1 ]++;
            cantEstatuillasEnJuego++;
            esperarEnter();

        }else{

            cout << endl << "No cumple con los requisitos de obtencion de la estatuilla, turno del otro jugador." << endl << endl << endl;
            cout << "Presione ENTER para volver al menu de las estatuillas." << endl;
            esperarEnter();

        }

        //Cambio de turno
        if( trueTiraJ1FalseTiraJ2 ) { trueTiraJ1FalseTiraJ2 = false; } else { trueTiraJ1FalseTiraJ2 = true; }

    }


}









