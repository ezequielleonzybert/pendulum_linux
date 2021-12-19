#pragma once
#include <iostream>
#include <ncurses.h>
#include "Soga.h"
using namespace std;

class Jugador
{
    public:

    void setup();
    void update(Soga soga);
    void draw(int vidas);
    float getX();
    float getY();
    char getDireccion();
    char getEstado();
    int getPosicionBalanceo();
    void setEstado(char estado);
    void balanceo(Soga soga);
    void setPosicionSalto(int posicionSalto);
    void setPosicionBalanceo(int posicionBalanceo);
    void setPosicionJetpack(int posicionJetpack);
    void saltar();
    void jetpack();

    private:
    char direccion;
    char estado;
    float x;
    float y;
    int posicionBalanceo;
    int posicionSalto;
    int posicionJetpack;
};