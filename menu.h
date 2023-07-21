#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <string>
using namespace std;

#include "juego.h"
#include "jugador.h"

void mostrarMenu(Jugador jugador1, Jugador jugador2);
void mostrarMenuEstatuillas();
void mostrarReglamento();
void mostrarEstadisticas( Jugador jugador1,Jugador jugador2 );
void mostrarCreditos();

#endif // MENU_H_INCLUDED
