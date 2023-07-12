#include <iostream>
#include <string>

struct Jugador {

    std::string nombre;

    int puntaje;
    int estatuillas[5];
    int bendiciones[5];
    int maldiciones[5];

};

Jugador crearJugador(const std::string& nombre, int puntaje)
{
    Jugador jugador;

    jugador.nombre = nombre;
    jugador.puntaje = puntaje;

    for( int i = 0; i<5; i++)
    {
        jugador.estatuillas[i] = 0;
        jugador.maldiciones[i] = 0;
        jugador.bendiciones[i] = 0;
    }

    return jugador;

}
