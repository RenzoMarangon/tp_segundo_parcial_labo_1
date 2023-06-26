#include <iostream>
using namespace std;
#include <ctime>
#include "funciones.h"

void tirarDado( int &dado, int maximo )
{
    srand(time(0));

    dado = random( maximo );

}

void mostrarDado( int dado )
{
    switch( dado )
    {
        case 1:
        {
            cout << "+-------+" << endl;
            cout << "|       |" << endl;
            cout << "|   x   |" << endl;
            cout << "|       |" << endl;
            cout << "+-------+" << endl;
            break;
        }
        case 2:
        {
            cout << "+-------+" << endl;
            cout << "| x     |" << endl;
            cout << "|       |" << endl;
            cout << "|     x |" << endl;
            cout << "+-------+" << endl;
            break;
        }
        case 3:
        {
            cout << "+-------+" << endl;
            cout << "| x 	|" << endl;
            cout << "|   x   |" << endl;
            cout << "|     x |" << endl;
            cout << "+-------+" << endl;
            break;
        }
        case 4:
        {
            cout << "+-------+" << endl;
            cout << "| x   x |" << endl;
            cout << "|       |" << endl;
            cout << "| x   x |" << endl;
            cout << "+-------+" << endl;
            break;
        }
        case 5:
        {
            cout << "+-------+" << endl;
            cout << "| x   x |" << endl;
            cout << "|   x   |" << endl;
            cout << "| x   x |" << endl;
            cout << "+-------+" << endl;
            break;
        }
        case 6:
        {
            cout << "+-------+" << endl;
            cout << "| x   x |" << endl;
            cout << "| x   x |" << endl;
            cout << "| x   x |" << endl;
            cout << "+-------+" << endl;
            break;
        }
        case 7:
        {
            cout << "+-------+" << endl;
            cout << "| x   x |" << endl;
            cout << "| x x x |" << endl;
            cout << "| x   x |" << endl;
            cout << "+-------+" << endl;
            break;
        }
        case 8:
        {
            cout << "+-------+" << endl;
            cout << "| x x x |" << endl;
            cout << "| x   x |" << endl;
            cout << "| x x x |" << endl;
            cout << "+-------+" << endl;
            break;
        }
        case 9:
        {
            cout << "+-------+" << endl;
            cout << "| x x x |" << endl;
            cout << "| x x x |" << endl;
            cout << "| x x x |" << endl;
            cout << "+-------+" << endl;
            break;
        }
        case 10:
        {
            cout << "+---------+" << endl;
            cout << "| x     x |" << endl;
            cout << "| x  x  x |" << endl;
            cout << "| x     x |" << endl;
            cout << "| x     x |" << endl;
            cout << "+---------+" << endl;
            break;
        }

    }
}
