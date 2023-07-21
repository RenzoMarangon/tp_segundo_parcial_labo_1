#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include <string>
#include "jugador.h"
using namespace std;

void iniciarJuego();
void orden(string& j1, string& j2, int& dado1, int& dado2);
void quienEmpieza(Jugador &j1, Jugador &j2, bool hack);
void iniciarFaseExpedicion(Jugador& jugador1, Jugador& jugador2, bool hack);
void iniciarFaseFinal( Jugador& jugador1, Jugador& jugador2, bool hack );
void sumarPuntosGanador(Jugador jugador);

#endif // JUEGO_H_INCLUDED
