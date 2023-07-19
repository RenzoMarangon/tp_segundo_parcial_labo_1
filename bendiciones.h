#ifndef BENDICIONES_H_INCLUDED
#define BENDICIONES_H_INCLUDED
#include "jugador.h"

void guardarBendicion(int estatuillaElegida, Jugador& jugador);
void guardarNumeroBendicionHormiga(Jugador& jugador);

void activarBendicionCangrejo( Jugador jugador, bool hack, int& dado1, int& dado2, int& dado3, int& dado4, int& dado5, int& dado6 );
void activarBendicionHormiga( Jugador jugador, int& dado1, int& dado2, int& dado3, int& dado4, int& dado5, int& dado6 );
void activarBendicionSalamandra(Jugador jugador, bool& dadosCorrelativos, int& dado1, int& dado2, int& dado3, int& dado4, int& dado5, int& dado6);
void activarBendicionAguila(Jugador jugador, int& dado1, int& dado2, int& dado3, int& dado4, int& dado5, int& dado6);
void activarBendicionMedusa(Jugador jugador, bool& dadosCorrelativos, int dado1, int dado2, int dado3, int dado4, int dado5, int dado6);

#endif // BENDICIONES_H_INCLUDED
