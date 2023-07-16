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

void quienEmpieza(Jugador &j1, Jugador &j2, bool hack)
{
    int dado1 = 0, dado2 = 0;
    do{

        if( hack )
        {
            elegirDado(j1, dado1, 6);
            elegirDado(j2, dado2, 6);
        }else{
            jugadorTiraDado( j1 , dado1, 10 );
            jugadorTiraDado( j2 , dado2, 10 );
        }


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


    bool hack = false;

    //Ingreso los nombres y creo  los jugadores
    cout << endl << "Ingresar un nombre del primer jugador: ";
    cin >> j1;
    cout << endl;
    cout << "Ingresar nombre del segundo jugador: ";
    cin >> j2;
    cout << endl << endl;

    Jugador jugador1 = crearJugador( j1, 0 );
    Jugador jugador2 = crearJugador( j2, 0 );




    if ( jugador1.nombre == "Lab1" || jugador1.nombre == "lab1" || jugador1.nombre == "LAB1" )
    {
        hack = true;
    }

    cout << "Recuerden, el jugador que saque menor numero comienza la partida." << endl << endl;

    quienEmpieza(jugador1, jugador2, hack);

    iniciarFaseExpedicion( jugador1, jugador2, hack );

    iniciarFaseFinal( jugador1, jugador2, hack );

}

void iniciarFaseExpedicion( Jugador& jugador1, Jugador& jugador2, bool hack)
{

    int dado1 = 0, dado2 = 0, dado3 = 0;

    //Inicializo la cantidad de estatuillas en juego, la cantidad que se utilizaron y la que se esta usando en el turno
    int cantEstatuillasEnJuego = 0;
    int estatuillaElegida = 0;
    int estatuillasElegidas[5] = {0};

    bool trueTiraJ1FalseTiraJ2 = true;
    bool cumpleRequisitoEstatuilla = false;

    limpiarConsola();
    cout << "  FASE DE EXPEDICION" << endl;

    while( cantEstatuillasEnJuego < 5 )
    {
        //NOTA: se pide tocar 2 veces enter para que cambie el numero random
        if( trueTiraJ1FalseTiraJ2 )
        {
        //TURNO DE JUGADOR 1
            //Pregunto si tiene maldicion de medusa desactivada (no tira x 3 turnos)
            if( jugador1.maldiciones[2] < 1 )
            {
                //Tira J1
                estatuillaElegida = elegirEstatuilla(jugador1.nombre, estatuillasElegidas);

                if( hack )
                {
                    elegirDado(jugador1, dado1, 10);
                    elegirDado(jugador1, dado2, 10);
                }else{
                    jugadorTiraDado( jugador1 , dado1, 10 );
                    jugadorTiraDado( jugador1 , dado2, 10 );
                }


                //Pregunto por maldicion Salamandra (tira 3er dado)
                if( jugador2.maldiciones[3] > 0 )
                {
                    activarMaldicionSalamandra( jugador1, dado3, hack );
                }


                cumpleRequisitoEstatuilla = cumpleConRequisitosEstatuilla( estatuillaElegida, dado1, dado2, dado3 );


                //Pregunto por maldicion de Aguila (tirar 2 veces si no gana estatuilla)
                if( jugador2.maldiciones[1] > 0 && !cumpleRequisitoEstatuilla )
                {
                    activarMaldicionAguila(jugador1, jugador2, dado1, dado2, hack );

                    //Vuelvo a preguntar maldicion salamandra
                    if( jugador2.maldiciones[4] > 0)
                    {
                        activarMaldicionSalamandra( jugador2, dado3, hack );
                    }

                    cumpleRequisitoEstatuilla = cumpleConRequisitosEstatuilla( estatuillaElegida, dado1, dado2, dado3 );
                }


               //Una vez que eligio la estatuilla, si cumple la condicion...
                if( cumpleRequisitoEstatuilla )
                {
                    cout << endl << "Felicidades " << jugador1.nombre << "! usted adquirio la estatuilla # " << estatuillaElegida << endl;

                    guardarBendicion( estatuillaElegida, jugador1 );
                    guardarMaldicion( estatuillaElegida, jugador1);

                    jugador1.estatuillas[ estatuillaElegida - 1 ]++;
                    estatuillasElegidas[ estatuillaElegida - 1 ]++;
                    cantEstatuillasEnJuego++;

                    cout << endl << "Presione ENTER para volver a elegir estatuillas." << endl << endl << endl;
                    esperarEnter();
                    limpiarConsola();

                    cumpleRequisitoEstatuilla = false;
                }else{

                cout << endl << "No cumple con los requisitos de obtencion de la estatuilla, turno del otro jugador." << endl << endl << endl;
                cout << "Presione ENTER para volver al menu de las estatuillas." << endl;
                esperarEnter();

                }

            }else{
                activarMaldicionMedusa(jugador1);
            }

        //TURNO DE JUGADOR 2
        }else{
            //Pregunto si tiene maldicion de medusa desactivada (no tira x 3 turnos)
            if( jugador2.maldiciones[2] < 1 )
            {
                //Tira J2
                estatuillaElegida = elegirEstatuilla(jugador2.nombre, estatuillasElegidas);

                //Si se usa el hack el jugador elige dados, sino los tira random
                if( hack )
                {
                    elegirDado(jugador2, dado1, 10);
                    elegirDado(jugador2, dado2, 10);
                }else{
                    jugadorTiraDado( jugador2 , dado1, 10 );
                    jugadorTiraDado( jugador2 , dado2, 10 );
                }


                //Maldicion de la Salamandra (tira 3er dado)
                if( jugador1.maldiciones[4] > 0 )
                {
                    activarMaldicionSalamandra( jugador2, dado3, hack );
                }


                cumpleRequisitoEstatuilla = cumpleConRequisitosEstatuilla( estatuillaElegida, dado1, dado2, dado3 );



                //Maldicion del Aguila (tirar 2 veces si no gana estatuilla)
                if( jugador1.maldiciones[3] > 0 && !cumpleRequisitoEstatuilla )
                {
                    activarMaldicionAguila( jugador2, jugador1, dado1, dado2, hack );

                    //Vuelvo a preguntar maldicion salamandra
                    if( jugador1.maldiciones[4] > 0)
                    {
                        activarMaldicionSalamandra( jugador2, dado3, hack );
                    }


                    cumpleRequisitoEstatuilla = cumpleConRequisitosEstatuilla( estatuillaElegida, dado1, dado2, dado3 );
                }



                //Una vez que eligio la estatuilla, si cumple la condicion...
                if( cumpleRequisitoEstatuilla )
                {
                    cout << endl << "Felicidades " << jugador2.nombre << "! usted adquirio la estatuilla # " << estatuillaElegida << endl;

                    guardarBendicion( estatuillaElegida, jugador2 );
                    guardarMaldicion( estatuillaElegida, jugador2);

                    jugador2.estatuillas[ estatuillaElegida ]++;
                    estatuillasElegidas[ estatuillaElegida - 1 ]++;
                    cantEstatuillasEnJuego++;

                    cout << endl << "Presione ENTER para volver a elegir estatuillas." << endl << endl << endl;
                    esperarEnter();
                    limpiarConsola();

                    cumpleRequisitoEstatuilla = false;

                }else{

                cout << endl << "No cumple con los requisitos de obtencion de la estatuilla, turno del otro jugador." << endl << endl << endl;
                cout << "Presione ENTER para volver al menu de las estatuillas." << endl;
                esperarEnter();

                }

            }else{
                activarMaldicionMedusa(jugador2);
            }

        }


        //Cambio de turno
        if( trueTiraJ1FalseTiraJ2 ) { trueTiraJ1FalseTiraJ2 = false; } else { trueTiraJ1FalseTiraJ2 = true; }

        dado1 = 0;
        dado2 = 0;
        dado3 = 0;

    }
    limpiarConsola();
    cout << "Fase de expedicion terminada.";
}

void iniciarFaseFinal( Jugador& jugador1, Jugador& jugador2, bool hack )
{

    int dado1 = 0, dado2 = 0, dado3 = 0, dado4 = 0, dado5 = 0, dado6 = 0;
    bool dadosCorrelativos = false;

    limpiarConsola();
    cout << "Fase final iniciada" << endl;



}









