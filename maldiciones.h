#ifndef MALDICIONES_H_INCLUDED
#define MALDICIONES_H_INCLUDED
#include <string>
#include "jugador.h"
void activarMaldicion(int maldicionElegida, Jugador& jugador, Jugador& rival, int dado);
void guardarMaldicion(int maldicionElegida, Jugador& jugador);


#endif // MALDICIONES_H_INCLUDED
