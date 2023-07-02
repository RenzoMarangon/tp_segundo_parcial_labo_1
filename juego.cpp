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

void quienEmpieza(string &j1, string &j2, int dado1, int dado2)
{
    do{
    cout << j1 << " presione enter para tira un dado...";
    esperarEnter();
    tirarDado  ( dado1, 10 );
    mostrarDado( dado1 );
    cout << endl;

    cout << j2 << " presione enter para tira un dado...";
    esperarEnter();
    tirarDado  ( dado2, 10 );
    mostrarDado( dado2 );
    cout << endl;
    if( dado1 == dado2)
    {
        cout << endl << "Numeros iguales, presione enter para volver a tirar los dados."<<endl;
    }

    }while( dado1 == dado2 );


    //Si el dado que tiro el segundo jugador es mas chico que el dado del primer jugador...
    //cambio el orden de los jugadores, en j1 pongo el valor del jugador que empieza y j2 el segundo

    string aux = "";
    if( dado2 < dado1 )
    {
        aux = j1;
        j1 = j2;
        j2 = aux;
    }

    cout << j1 << " tira los dados primero. Presione enter para continuar..." << endl << endl;
    esperarEnter();
}



void iniciarJuego()
{

    string jugador1, jugador2, nombre_mj;
    int dado1 = 0, dado2 = 0, dado3 = 0;

    //Inicializo la cantidad de estatuillas en juego, la cantidad que se utilizaron y la que se esta usando en el turno

    int cantEstatuillasEnJuego = 5;

    int estatuillasJ1[5] = {0};

    int estatuillasJ2[5] = {0};

    int bendiciones[2][5] = {0};
    int maldiciones[2][5] = {0};
    int estatuillas[2][5] = {0};


    int puntosPorJugador[2] = { 0 };

    int estatuillasElegidas[5] = {0};

    bool cumple;




    if ( jugador1 != "Lab1" && jugador1 != "lab1" && jugador1 != "LAB1" )
        {
            cout << "Recuerden, el jugador que saque menor numero comienza la partida." << endl << endl;

            cout << endl << "Ingresar un nombre del primer jugador: ";
            cin >> jugador1;
            cout << endl;
            cout << "Ingresar nombre del segundo jugador: ";
            cin >> jugador2;
            cout << endl << endl;

            quienEmpieza(jugador1, jugador2, dado1, dado2);

            iniciarFaseExpedicion( jugador1, jugador2, estatuillasJ1, estatuillasJ2, dado1, dado2, dado3, maldiciones,bendiciones );

        }

}

void iniciarFaseExpedicion(string j1, string j2, int* estatuillasJ1, int* estatuillasJ2, int &dado1, int &dado2, int &dado3, int maldiciones[][5], int bendiciones[][5])
{

    cout << endl << maldiciones[1][3] << endl;

    //Inicializo la cantidad de estatuillas en juego, la cantidad que se utilizaron y la que se esta usando en el turno
    int cantEstatuillasEnJuego = 0;
    int estatuillaElegida = 0;
    int estatuillasElegidas[5] = {0};

    bool trueTiraJ1FalseTiraJ2 = true;

    cout << "  FASE DE EXPEDICION" << endl;

    while( cantEstatuillasEnJuego < 1 )
    {
        //NOTA: se pide tocar 2 veces enter para que cambie el numero random
        if( trueTiraJ1FalseTiraJ2 )
            //Tira J1
        {

            cout << endl << j1 <<" presione enter para tirar un dado "<< endl;
            esperarEnter();
            tirarDado(dado1, 6);
            mostrarDado(dado1);

            cout << endl << j1 <<" presione enter para tirar otro dado "<< endl;
            esperarEnter();
            tirarDado(dado2, 6);
            mostrarDado(dado2);

            for( int i = 0; i < 5; i++ )
            {
                if( maldiciones[0][i] > 0 )
                {

                    //activarMaldicion( i , maldiciones , j1, j2 , 0, 1, dado3);
                }

            }

        }else{
            //Tira J2

            cout << endl << j2 << " presione enter para tirar un dado. " << endl;
            esperarEnter();
            tirarDado(dado1, 6);
            mostrarDado(dado1);

            cout << endl << j2 << " presione enter para tirar otro dado. "<< endl;
            esperarEnter();
            tirarDado(dado2, 6);
            mostrarDado(dado2);

            for( int i = 0; i < 5; i++ )
            {
                if( maldiciones[1][i] > 0 )
                {
                     activarMaldicion( i+1 , maldiciones , j1, j2 , 0, 1, dado3);
                }

            }

        }


        for( int i = 0; i<4; i++)
        {
           cout <<  bendiciones[0][i] << " ";
        }

        //Una vez que eligio la estatuilla, si cumple la condicion...
        if( cumpleConRequisitosEstatuilla( estatuillaElegida, dado1, dado2, dado3 ) )
        {
            //Pregunto si jugador 1 o jugador 2 tiraron los dados
            if( trueTiraJ1FalseTiraJ2 )
            {
                estatuillasJ1[ estatuillaElegida -1 ]++;

                //guardarBendicion( estatuillaElegida, bendiciones, 0 );
                guardarMaldicion( estatuillaElegida, maldiciones , 0);

            }else{
                estatuillasJ2[ estatuillaElegida -1 ]++;

                //guardarBendicion( estatuillaElegida, bendiciones, 1 );
                guardarMaldicion( estatuillaElegida, maldiciones, 1);
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









