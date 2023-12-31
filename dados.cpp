#include <iostream>
using namespace std;
#include <ctime>
#include "funciones.h"
#include "jugador.h"

void tirarDado( int &dado, int maximo )
{
    srand(time(0));

    dado = random( maximo );

}




void mostrarDado( int dado )
{
      switch(dado){
      case 1:
        {
          cout << "+-------+" << endl;
          cout << "|       |" << endl;
          cout << "|   o   |" << endl;
          cout << "|       |" << endl;
          cout << "+-------+" << endl << endl;
          break;

        }

      case 2:
            {
              cout << "+-------+" << endl;
              cout << "|      o|" << endl;
              cout << "|       |" << endl;
              cout << "|o      |" << endl;
              cout << "+-------+" << endl << endl;
              break;
            }

      case 3:
          cout << "+-------+" << endl;
          cout << "|      o|" << endl;
          cout << "|   o   |" << endl;
          cout << "|o      |" << endl;
          cout << "+-------+" << endl << endl;
          break;

      case 4:
          cout << "+-------+" << endl;
          cout << "|o     o|" << endl;
          cout << "|       |" << endl;
          cout << "|o     o|" << endl;
          cout << "+-------+" << endl << endl;
          break;

      case 5:
          cout << "+-------+" << endl;
          cout << "|o     o|" << endl;
          cout << "|   o   |" << endl;
          cout << "|o     o|" << endl;
          cout << "+-------+" << endl << endl;
          break;

      case 6:
          cout << "+-------+" << endl;
          cout << "|o     o|" << endl;
          cout << "|o     o|" << endl;
          cout << "|o     o|" << endl;
          cout << "+-------+" << endl << endl;
          break;

      case 7:
          cout << "+-------+" << endl;
          cout << "|o     o|" << endl;
          cout << "|o  o  o|" << endl;
          cout << "|o     o|" << endl;
          cout << "+-------+" << endl << endl;
          break;

      case 8:
          cout << "+-------+" << endl;
          cout << "|o  o  o|" << endl;
          cout << "|o     o|" << endl;
          cout << "|o  o  o|" << endl;
          cout << "+-------+" << endl << endl;
          break;

      case 9:
          cout << "+-------+" << endl;
          cout << "|o  o  o|" << endl;
          cout << "|o  o  o|" << endl;
          cout << "|o  o  o|" << endl;
          cout << "+-------+" << endl << endl;
          break;

      case 10:
          cout << "+-------+" << endl;
          cout << "|o  o  o|" << endl;
          cout << "|o o o o|" << endl;
          cout << "|o  o  o|" << endl;
          cout << "+-------+" << endl << endl;
          break;

      default:
        {
            cout << endl << "El dado " << dado << " no esta programado" << endl;
        }
    }
}

void elegirDado( Jugador jugador, int& dado, int numeroDado )
{
    std::cout << "El jugador " << jugador.nombre << " elige un dado: ";
    cin >> dado;

    while( dado < 1 || dado > numeroDado )
    {
        std::cout << "El numero de dado es incorrecto, vuelva a elegir un dado: ";
        cin >> dado;
    }
}

void jugadorTiraDado( Jugador jugador, int& dado, int numeroDado )
{
    cout << endl << jugador.nombre << " presione enter para tirar un dado. " << endl;
    esperarEnter();
    tirarDado(dado, numeroDado);
    mostrarDado(dado);
}


