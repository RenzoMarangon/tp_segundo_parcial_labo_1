#include <iostream>
using namespace std;

#include "jugador.h"
#include "dados.h"
#include "funciones.h"

void guardarBendicion( int estatuillaElegida, Jugador& jugador ) {

   if( estatuillaElegida > 0 && estatuillaElegida <= 5 )
    {
        jugador.bendiciones[ estatuillaElegida - 1]++;
    }else{
        cout << "El numero de estatuilla no coincide" << endl;
    }
}


void guardarNumeroBendicionHormiga(Jugador& jugador)
{
    if( jugador.estatuillas[1] )
    {
        cout << jugador.nombre << " ha recibido la bendicion de la Hormiga." << endl << endl;
        int numero;

        do{
            cout << "Elija un numero del 1 al 6: ";
            cin >> numero;
            cout << endl << endl;

            jugador.bendiciones[1] = jugador.bendiciones[1] * 0 + numero; //Lo vuelvo a 0 y sumo el numero para guardarlo
        } while( numero < 1 || numero > 6 );
    }
}

void activarBendicionCangrejo( Jugador jugador, int intentos, bool& dadosCorrelativos,  bool hack, int& dado1, int& dado2, int& dado3, int& dado4, int& dado5, int& dado6 )
{
    if( jugador.estatuillas[0] > 0 && intentos < 1 && !dadosCorrelativos )
    {
        if( hack )
        {
            elegirDado(jugador, dado1, 10);
            elegirDado(jugador, dado2, 10);
            elegirDado(jugador, dado3, 10);
            elegirDado(jugador, dado4, 10);
            elegirDado(jugador, dado5, 10);
            elegirDado(jugador, dado6, 10);
        }else{
            jugadorTiraDado(jugador, dado1, 10);
            jugadorTiraDado(jugador, dado2, 10);
            jugadorTiraDado(jugador, dado3, 10);
            jugadorTiraDado(jugador, dado4, 10);
            jugadorTiraDado(jugador, dado5, 10);
            jugadorTiraDado(jugador, dado6, 10);
        }

        dadosCorrelativos = numerosCorrelativos( 6, dado1, dado2, dado3, dado4, dado5, dado6);
    }
}

void activarBendicionHormiga( Jugador jugador, int& dado1, int& dado2, int& dado3, int& dado4, int& dado5, int& dado6 )
{
    int dadoElegido;

    if( jugador.estatuillas[1] )
    {
        do
        {
            cout << "Elegir un dado del 1 al 6 para ser cambiado por el numero: " << jugador.bendiciones[1];
            cin >> dadoElegido;
            cout << endl << endl;
        }while(dadoElegido < 1 || dadoElegido > 6);

        switch( dadoElegido )
        {
            case 1:
            {
                dado1 = jugador.bendiciones[1];
            }
            case 2:
            {
                dado2 = jugador.bendiciones[1];
            }
            case 3:
            {
                dado3 = jugador.bendiciones[1];
            }

            case 4:
            {
                dado4 = jugador.bendiciones[1];
            }

            case 5:
            {
                dado5 = jugador.bendiciones[1];
            }

            case 6:
            {
                dado6 = jugador.bendiciones[1];
            }
        }
    }
}

void activarBendicionMedusa(Jugador jugador, bool& dadosCorrelativos, int dado1, int dado2, int dado3, int dado4, int dado5, int dado6)
{
    if( jugador.estatuillas[2] ){

        dadosCorrelativos = numerosIguales( dado1, dado2, dado3, dado4, dado5, dado6 );

    }
}

void activarBendicionAguila(Jugador jugador, int& dado1, int& dado2, int& dado3, int& dado4, int& dado5, int& dado6)
{
    int dadoElegido;
    int numeroElegido;

    if( jugador.estatuillas[3] )
    {
        do
        {
            cout << "Elegir un numero del 1 al 10: " << jugador.bendiciones[1];
            cin >> numeroElegido;
            cout << endl << endl;

            cout << "Elegir un dado del 1 al 6 para ser cambiado por el numero: " << jugador.bendiciones[1];
            cin >> dadoElegido;
            cout << endl << endl;
        }while(dadoElegido < 1 || dadoElegido > 6 || numeroElegido < 1 || numeroElegido > 10);

        switch( dadoElegido )
        {
            case 1:
            {
                dado1 = numeroElegido;
            }
            case 2:
            {
                dado2 = numeroElegido;
            }
            case 3:
            {
                dado3 = numeroElegido;
            }

            case 4:
            {
                dado4 = numeroElegido;
            }

            case 5:
            {
                dado5 = numeroElegido;
            }

            case 6:
            {
                dado6 = numeroElegido;
            }
        }
    }
}

void activarBendicionSalamandra(Jugador jugador, bool& dadosCorrelativos, int& dado1, int& dado2, int& dado3, int& dado4, int& dado5, int& dado6)
{
    dadosCorrelativos = numerosCorrelativos(5, dado1, dado2, dado3, dado4, dado5, dado6 );
}



