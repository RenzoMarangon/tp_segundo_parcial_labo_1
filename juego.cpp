#include <iostream>
using namespace std;
#include <string>
#include "juego.h"
#include "funciones.h"
#include "dados.h"
#include "menu.h"
#include "estatuillas.h"

void quienEmpieza(string &j1, string &j2, int dado1, int dado2)
{
    do{
    esperarEnter();
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

    string j1, j2;
    int dado1, dado2;
    int estatuillasJ1[] = {};
    int estatuillasJ2[] = {};

    mostrarMenu();

    cout << endl << "Ingresar un nombre del primer jugador: ";
    cin >> j1;
    cout << endl;
    cout << "Ingresar nombre del segundo jugador: ";
    cin >> j2;
    cout << endl << endl;

    quienEmpieza(j1, j2, dado1, dado2);

    iniciarFaseExpedicion( j1, j2, estatuillasJ1, estatuillasJ2, dado1, dado2 );

    cout << estatuillasJ1[0];
}

void iniciarFaseExpedicion(string j1, string j2, int* estatuillasJ1, int* estatuillasJ2, int &dado1, int &dado2)
{
    //DEJO UN ESPACIO
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

    //Inicializo la cantidad de estatuillas en juego, la cantidad que se utilizaron y la que se esta usando en el turno
    int cantEstatuillasEnJuego = 0;
    int estatuillaElegida = 0;
    int estatuillasElegidas[] = {};

    bool trueTiraJ1FalseTiraJ2 = true;

    cout << "  FASE DE EXPEDICION" << endl;

    while( cantEstatuillasEnJuego < 5 )
    {

        //CAMBIO EL TURNO DE CADA JUGADOR (TIRA DADOS Y ELIGE ESTATUILLA)
        if( trueTiraJ1FalseTiraJ2 )
        {
            estatuillaElegida = elegirEstatuilla( j1, estatuillasElegidas );

            esperarEnter();
            cout << endl << j1 <<" presione enter para tirar un dado "<< endl;
            esperarEnter();
            tirarDado(dado1, 6);
            mostrarDado( dado1 );

            cout << endl << "Presione enter para volver a tirar otro dado "<< endl;
            esperarEnter();
            tirarDado(dado2, 6);
            mostrarDado( dado2 );


            if( cumpleConRequisitosEstatuilla( estatuillaElegida, dado1, dado2 ) )
            {
                estatuillasJ1[ estatuillaElegida ]++;
                cout << endl << "Felicidades! usted adquirio la estatuilla." << endl << endl << endl;
            }

            trueTiraJ1FalseTiraJ2 = false;

        }else{
            estatuillaElegida = elegirEstatuilla( j2, estatuillasElegidas );



            esperarEnter();
            cout << endl << j2 <<" presione enter para tirar un dado "<< endl;
            tirarDado(dado1, 6);
            mostrarDado( dado1 );

            cout << endl << "Presione enter para volver a tirar otro dado "<< endl;
            esperarEnter();
            tirarDado(dado2, 6);
            mostrarDado( dado2 );


            if( cumpleConRequisitosEstatuilla( estatuillaElegida, dado1, dado2 ) )
            {
                estatuillasJ2[ estatuillaElegida ]++;
                cout << endl << "Felicidades! usted adquirio la estatuilla." << endl << endl << endl;
            }


            trueTiraJ1FalseTiraJ2 = true;
        }

        estatuillasElegidas[ estatuillaElegida ]++;
        cantEstatuillasEnJuego++;
    }

    for( int i = 0; i<5; i++)
    {
        cout << endl << estatuillasJ1[i] << " ";
    }


}






void mostrarCreditos()
{
    cout << "Integrantes del grupo ... :" << endl << endl;
}

void mostrarEstadisticas()
{
    string jugador1 = "pepe";
    string jugador2 = "elrufian";

    cout << "HITO \t" << jugador1 << "\t" << jugador2 << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "Estatuilla \t " << "PUNTOS 1" << "\t" << "PUNTOS 2" << endl;
    cout << "Estatuilla++ \t " << "PUNTOS 1" << "\t" << "PUNTOS 2" << endl;
    cout << "Estatuilla-- \t " << "PUNTOS 1" << "\t" << "PUNTOS 2" << endl;
    cout << "Ganador \t " << "PUNTOS 1" << "\t" << "PUNTOS 2" << endl;
    cout << "Lanzamiento \t " << "PUNTOS 1" << "\t" << "PUNTOS 2" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "TOTAL \t" << "PUNTOS 1 " << "\t" << " PUNTOS 1 " << "\t" << " PUNTOS 2" << endl;
    cout << "GANADOR: " << "GANADOR" << " con " << "PUNTOS" << "puntos de victoria" << endl;
    cout << endl << endl << endl;
}




