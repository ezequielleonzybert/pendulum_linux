#pragma once
#include <iostream>
#include <ncurses.h>
#include <vector>
#include <math.h>
#include "Pared.h"

using namespace std;

class Jugador;

class Soga{
    public:
    void setup();
    void update(vector<Pared> & Paredes, Jugador & jugador);
    void draw(int vidas, Jugador jugador);
    void setEstado(char estado);
    void setEjeX(int x);
    void setEjeY(int y);
    void setLongitud(int longitud);
    char getEstado();
    int getEjeX();
    int getEjeY();
    int getLongitud();
    char getDireccionDisparo();

    private:
    float ejeX;
    float ejeY;
    char estado;
    int longitud;
    char direccionDisparo;
};