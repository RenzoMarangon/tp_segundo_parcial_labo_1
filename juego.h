#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include <string>
using namespace std;

void iniciarJuego();
void mostrarEstadisticas();
void mostrarCreditos();

void quienEmpieza(string &j1, string &j2, int dado1, int dado2);
void iniciarFaseExpedicion(string j1, string j2, int* estatuillasJ1, int* estatuillasJ2, int &dado1, int &dado2);


#endif // JUEGO_H_INCLUDED
