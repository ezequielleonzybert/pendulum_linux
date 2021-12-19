#include "Pared.h"
#include "Soga.h"

int aleatorio;

Pared::Pared(int x, int y, bool inicial)
{
    this->x = x;
    this->y = y;
    this->inicial = inicial;
    this->velocidad = 1; 
    this->acoplada = false;
}
int Pared::getX()
{
    return x;
}
int Pared::getY()
{
    return y;
}
bool Pared::getAcoplada()
{
    return acoplada;
}
void Pared::setX(float x)
{
    this->x = x;
}
void Pared::setAcoplada(bool acoplada)
{
    this->acoplada = acoplada;
}
void Pared::update(Soga soga)
{
    if(soga.getEstado() != 'd')
    {
        if(x>1) x -= velocidad;
        else
        {
            x=118;
            if(inicial) aleatorio=rand()%15+1;    
            y=aleatorio;
        }
    }
}
void Pared::draw()
{
    mvaddch(y, x, ACS_CKBOARD);

}
