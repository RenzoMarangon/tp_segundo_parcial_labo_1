#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include <string>
using namespace std;

void iniciarJuego();
void mostrarEstadisticas();
void mostrarCreditos();
void orden(string& j1, string& j2, int& dado1, int dado2);
void quienEmpieza(string &j1, string &j2, int dado1, int dado2);
void iniciarFaseExpedicion(string j1, string j2, int* estatuillasJ1, int* estatuillasJ2, int &dado1, int &dado2, int &dado3, int* &maldiciones, int* &bendiciones);


#endif // JUEGO_H_INCLUDED
