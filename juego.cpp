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
    //Ingreso los nombres y creo  los jugadores
    string j1, j2, nombre_mj;

    Jugador jugador1 = crearJugador( j1, 0 );
    Jugador jugador2 = crearJugador( j2, 0 );

    mostrarMenu(jugador1, jugador2);

    bool hack = false;

    cout << endl << "Ingresar un nombre del primer jugador: ";
    cin >> j1;
    cout << endl;
    cout << "Ingresar nombre del segundo jugador: ";
    cin >> j2;
    cout << endl << endl;

    jugador1.nombre = j1;
    jugador2.nombre = j2;

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
    int intentos[2] = { 0 };

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

                //Sumo el intento
                intentos[0]++;

                if( hack )
                {
                    elegirDado(jugador1, dado1, 10);
                    elegirDado(jugador1, dado2, 10);
                }else{
                    jugadorTiraDado( jugador1 , dado1, 10 );
                    jugadorTiraDado( jugador1 , dado2, 10 );
                }


                //Pregunto por maldicion Salamandra (tira 3er dado)
                activarMaldicionSalamandra( jugador1, jugador2, dado3, hack );


                cumpleRequisitoEstatuilla = cumpleConRequisitosEstatuilla( estatuillaElegida, dado1, dado2, dado3 );


                //Si no cumple requisitos para ganar la estatuilla activo la maldicion
                if( !cumpleRequisitoEstatuilla )
                {
                    activarMaldicionAguila(jugador1, jugador2, dado1, dado2, hack );

                    //Vuelvo a activar maldicion y preguntar si puede ganar la estatuilla
                    activarMaldicionSalamandra( jugador2, jugador1, dado3, hack );
                    cumpleRequisitoEstatuilla = cumpleConRequisitosEstatuilla( estatuillaElegida, dado1, dado2, dado3 );
                }


               //Una vez que eligio la estatuilla, si cumple la condicion...
                if( cumpleRequisitoEstatuilla )
                {
                    cout << endl << "Felicidades " << jugador1.nombre << "! usted adquirio la estatuilla # " << estatuillaElegida << endl;

                    guardarBendicion( estatuillaElegida, jugador1 );
                    guardarMaldicion( estatuillaElegida, jugador1);

                    activarMaldicionHormiga(jugador1, jugador2, dado1, dado2, dado3 );
                    activarMaldicionCangrejo( jugador1, jugador2, dado1 );

                    jugador1.estatuillas[ estatuillaElegida - 1 ]++;
                    estatuillasElegidas[ estatuillaElegida - 1 ]++;
                    cantEstatuillasEnJuego++;

                    //PUNTAJE
                    if(intentos[0] > 1) jugador1.puntaje += 5; else jugador1.puntaje += 10;
                    jugador2.puntaje -=3;
                    intentos[0] = 0;
                    intentos[1] = 0;

                    //Volver al menu
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

                //Sumo el intento
                intentos[1]++;

                //Si se usa el hack el jugador elige dados, sino los tira random
                if( hack )
                {
                    elegirDado(jugador2, dado1, 10);
                    elegirDado(jugador2, dado2, 10);
                }else{
                    jugadorTiraDado( jugador2 , dado1, 10 );
                    jugadorTiraDado( jugador2 , dado2, 10 );
                }


                activarMaldicionSalamandra( jugador2, jugador1, dado3, hack );

                cumpleRequisitoEstatuilla = cumpleConRequisitosEstatuilla( estatuillaElegida, dado1, dado2, dado3 );



                //Maldicion del Aguila (tirar 2 veces si no gana estatuilla)
                if( !cumpleRequisitoEstatuilla )
                {
                    activarMaldicionAguila( jugador2, jugador1, dado1, dado2, hack );

                    //Vuelvo a activar maldicion y preguntar si puede ganar la estatuilla
                    activarMaldicionSalamandra( jugador2, jugador1, dado3, hack );
                    cumpleRequisitoEstatuilla = cumpleConRequisitosEstatuilla( estatuillaElegida, dado1, dado2, dado3 );
                }



                //Una vez que eligio la estatuilla, si cumple la condicion...
                if( cumpleRequisitoEstatuilla )
                {
                    cout << endl << "Felicidades " << jugador2.nombre << "! usted adquirio la estatuilla # " << estatuillaElegida << endl;

                    guardarBendicion( estatuillaElegida, jugador2 );
                    guardarMaldicion( estatuillaElegida, jugador2);

                    activarMaldicionHormiga(jugador2, jugador1, dado1, dado2, dado3 );
                    activarMaldicionCangrejo( jugador2, jugador1, dado1 );

                    jugador2.estatuillas[ estatuillaElegida ]++;
                    estatuillasElegidas[ estatuillaElegida - 1 ]++;
                    cantEstatuillasEnJuego++;

                    //PUNTAJE
                    if(intentos[1] > 1) jugador2.puntaje += 5; else jugador2.puntaje += 10;
                    jugador1.puntaje -=3;
                    intentos[0] = 0;
                    intentos[1] = 0;


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
        trueTiraJ1FalseTiraJ2 = !trueTiraJ1FalseTiraJ2;

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
    bool trueTiraJ1FalseTiraJ2 = true;
    int intentos[2] = {}; //Pos 0 para j1 pos 1 para j2

    limpiarConsola();
    cout << "Fase final iniciada" << endl;

    do{
        //TIRA J1
        if( trueTiraJ1FalseTiraJ2 )
        {

            if( hack )
            {
                elegirDado(jugador1, dado1, 10);
                elegirDado(jugador1, dado2, 10);
                elegirDado(jugador1, dado3, 10);
                elegirDado(jugador1, dado4, 10);
                elegirDado(jugador1, dado5, 10);
                elegirDado(jugador1, dado6, 10);
            }else{
                jugadorTiraDado(jugador1, dado1, 10);
                jugadorTiraDado(jugador1, dado2, 10);
                jugadorTiraDado(jugador1, dado3, 10);
                jugadorTiraDado(jugador1, dado4, 10);
                jugadorTiraDado(jugador1, dado5, 10);
                jugadorTiraDado(jugador1, dado6, 10);
            }

            jugador1.puntaje--;
            intentos[0]++;

            activarBendicionAguila( jugador1, dado1, dado2, dado3, dado4, dado5, dado6 );

            dadosCorrelativos = numerosCorrelativos(6, dado1, dado2, dado3, dado4, dado5, dado6 );

            activarBendicionMedusa( jugador1, dadosCorrelativos, dado1, dado2, dado3, dado4, dado5, dado6 );
            activarBendicionSalamandra( jugador1, dadosCorrelativos, dado1, dado2, dado3, dado4, dado5, dado6 );

            activarBendicionCangrejo( jugador1, intentos[0], dadosCorrelativos, hack, dado1, dado2, dado3, dado4, dado5, dado6 );

        //TIRA J2
        }else{

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

            jugador2.puntaje--;
            intentos[1]++;


            activarBendicionAguila( jugador2, dado1, dado2, dado3, dado4, dado5, dado6 );

            dadosCorrelativos = numerosCorrelativos(6, dado1, dado2, dado3, dado4, dado5, dado6 );

            activarBendicionMedusa( jugador2, dadosCorrelativos, dado1, dado2, dado3, dado4, dado5, dado6 );
            activarBendicionSalamandra( jugador2, dadosCorrelativos, dado1, dado2, dado3, dado4, dado5, dado6 );

            activarBendicionCangrejo( jugador2, intentos[1], dadosCorrelativos, hack, dado1, dado2, dado3, dado4, dado5, dado6 );

        }

        //Cambio de turno
        trueTiraJ1FalseTiraJ2 = !trueTiraJ1FalseTiraJ2;
        dado1 = 0;
        dado2 = 0;
        dado3 = 0;
        dado4 = 0;
        dado5 = 0;
        dado6 = 0;

    }while( !dadosCorrelativos );

    limpiarConsola();

    if( trueTiraJ1FalseTiraJ2 )
    {
        jugador1.ganador = true;
        cout << "Felicidades " << jugador1.nombre << " ganaste el juego!." << endl << endl;

    }else{
        jugador2.ganador = true;
        cout << "Felicidades " << jugador2.nombre << " ganaste el juego!." << endl << endl;
    }

    cout << "Para volver al menu presione ENTER." << endl;
    esperarEnter();
    mostrarMenu( jugador1, jugador2 );
}

void sumarPuntosGanador(Jugador jugador)
{
    //Sumo los puntos
    bool ganoSinEstatuillas = true;
    for( int i = 0; i < 5; i++ )
    {
        if( jugador.ganador )
        {
            if( jugador.estatuillas[i] > 0 ) ganoSinEstatuillas = false;
        }
    }

    if( ganoSinEstatuillas ) jugador.puntaje += 50; else jugador.puntaje += 15;
}









