#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include <string>
#include "jugador.h"
using namespace std;

void iniciarJuego();
void mostrarEstadisticas();
void mostrarCreditos();
void orden(string& j1, string& j2, int& dado1, int& dado2);
void quienEmpieza(Jugador &j1, Jugador &j2, int dado1, int dado2);
void iniciarFaseExpedicion(Jugador& jugador1, Jugador& jugador2, int &dado1, int &dado2, int &dado3);


#endif // JUEGO_H_INCLUDED
