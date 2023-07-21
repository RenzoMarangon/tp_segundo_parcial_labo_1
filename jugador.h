#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

struct Jugador {

    std::string nombre;

    int puntaje;
    int estatuillas[5];
    int bendiciones[5];
    int maldiciones[5];
    bool ganador;
};

Jugador crearJugador(const std::string& nombre, int puntaje);

#endif // JUGADOR_H_INCLUDED
