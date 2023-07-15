#ifndef MALDICIONES_H_INCLUDED
#define MALDICIONES_H_INCLUDED
#include <string>
#include "jugador.h"

void guardarMaldicion(int maldicionElegida, Jugador& jugador);

void activarMaldicionAguila(Jugador jugador, Jugador rival, int& dado );
void activarMaldicionSalamandra( Jugador jugador, int& dado  );



#endif // MALDICIONES_H_INCLUDED
