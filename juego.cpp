#include <iostream>
using namespace std;
#include "juego.h"
#include "funciones.h"
#include <ctime>
#include <string>

void quienEmpieza(string &j1, string &j2, int dado1, int dado2)
{
    do{
    esperarEnter();
    cout << "Jugador 1 presione enter para tira un dado...";
    esperarEnter();
    tirarDado(dado1);
    cout << endl;

    cout << "Jugador 2 presione enter para tira un dado...";
    esperarEnter();
    tirarDado(dado2);
    }while( dado1 == dado2 );


    //Si el dado que tiro el segundo jugador es mas chico que el dado del primer jugador...
    //cambio el orden de los jugadores, en j1 pongo el valor del jugador que empieza y j2 es el otro jugador

    string aux = "";
    if( dado2 < dado1 )
    {
        aux = j1
        j1 = j2;
        j2 = aux;
    }

    cout << j1 << " empieza" << endl;

}


void iniciarJuego()
{
    string j1, j2;
    int dado1, dado2;

    cout << "Ingresar un nombre del primer jugador";
    cin >> j1;
    cout << endl;
    cout << "Ingresar nombre del segundo jugador ";
    cin >> j2;
    cout << endl << endl;

    quienEmpieza(j1, j2, dado1, dado2);


}

void mostrarCreditos()
{
    cout << "Integrantes del grupo ... :" << endl;
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


void tirarDado( int &dado )
{
    srand(time(0));

    dado = random(10);

    cout << "dado: " << dado << endl;
}


