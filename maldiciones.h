#ifndef MALDICIONES_H_INCLUDED
#define MALDICIONES_H_INCLUDED
#include <string>
#include "jugador.h"

void guardarMaldicion(int maldicionElegida, Jugador& jugador);

void activarMaldicionCangrejo( Jugador& jugador, Jugador rival, int& dado1 );
void activarMaldicionHormiga( Jugador& jugador, Jugador rival, int& dado1, int& dado2, int& dado3 );
void activarMaldicionMedusa( Jugador& jugador);
void activarMaldicionAguila(Jugador jugador, Jugador rival, int& dado1, int& dado2, bool hack );
void activarMaldicionSalamandra( Jugador jugador, Jugador rival, int& dado, bool hack  );

#endif // MALDICIONES_H_INCLUDED
