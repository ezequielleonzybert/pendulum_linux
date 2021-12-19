#pragma once
#include <iostream>
#include <ncurses.h>  

using namespace std;

class Soga;

class Pared{
    public:
    Pared(int x, int y, bool inicial);
    void update(Soga soga);
    void draw();
    int getX();
    int getY();
    bool getAcoplada();
    void setX(float x);
    void setAcoplada(bool acoplada);

    private:
    float x;
    float y;
    bool inicial;
    float velocidad;
    bool acoplada;
};