#pragma once
#include <iostream>
#include <ncurses.h>

class Jugador;

class Paquete
{
    public:
    Paquete(void);
    void update(Jugador jugador, int & cargas, int & jetpack);
    void draw();

    private:
    float x, y;
    char tipo;
    bool capturado;
    int animacionCapturado=0;
};