#include "Jugador.h"

float Jugador::getX()
{
    return x;
}
float Jugador::getY()
{
    return y;
}
char Jugador::getDireccion()
{
    return direccion;
}
char Jugador::getEstado()
{
    return estado;
}
int Jugador::getPosicionBalanceo()
{
    return posicionBalanceo;
}
void Jugador::setEstado(char estado)
{
    this->estado = estado;
}
void Jugador::setPosicionSalto(int posicionSalto)
{
    this->posicionSalto = posicionSalto;
}
void Jugador::setPosicionBalanceo(int posicionBalanceo)
{
    this->posicionBalanceo = posicionBalanceo;
}
void Jugador::setPosicionJetpack(int posicionJetpack)
{
    this->posicionJetpack = posicionJetpack;
}
void Jugador::setup()
{
    estado='r';
    x = 70;
    y = 10;
    posicionBalanceo=0;
    posicionSalto=0;
}
void Jugador::update(Soga soga)
{
    if((estado == 'c' || soga.getEstado()=='n') && estado != 'j')
    {
        if(posicionSalto>0) saltar();
        else 
        y++;
    } 
    if(soga.getEstado()=='a') balanceo(soga);
    if(estado == 's') saltar();
    if(estado == 'j') jetpack();
}
void Jugador::draw(int vidas)
{
    if(vidas)
    {
        mvaddch(y-1, x-2, ACS_ULCORNER);
        mvaddch(y-1, x+2, ACS_URCORNER);
        mvaddch(y+1, x-2, ACS_LLCORNER);
        mvaddch(y+1, x+2, ACS_LRCORNER);
        mvhline(y-1, x-1, ACS_HLINE, 3);
        mvhline(y+1, x-1, ACS_HLINE, 3);
        mvaddch(y, x-2, ACS_VLINE);
        mvaddch(y, x+2, ACS_VLINE);
        mvhline(y, x-1, ' ', 3);
    }
}
void Jugador::balanceo(Soga soga)
{
    if(soga.getDireccionDisparo() == 'd')
    {
        switch (soga.getLongitud())
        {
            case 1:
                switch (posicionBalanceo)
                {
                    case 0:
                        x = soga.getEjeX()-2;
                        y = soga.getEjeY()+1;
                        posicionBalanceo++;
                        break;
                    case 1:
                        x = soga.getEjeX();
                        y = soga.getEjeY()+2;
                        posicionBalanceo++;
                        direccion = 'd';
                        break;
                    case 2:
                        x = soga.getEjeX()+2;
                        y = soga.getEjeY()+1;
                        posicionBalanceo++;
                        break;
                    case 3:
                        x = soga.getEjeX();
                        y = soga.getEjeY()+2;
                        posicionBalanceo++;
                        direccion = 'i';
                        break;
                    case 4:
                        x = soga.getEjeX()-2;
                        y = soga.getEjeY()+1;
                        posicionBalanceo=1;
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                switch (posicionBalanceo)
                {
                    case 0:
                        x = soga.getEjeX()-4;
                        y = soga.getEjeY()+2;
                        posicionBalanceo++;
                        break;
                    case 1:
                        x = soga.getEjeX()-3;
                        y = soga.getEjeY()+3;
                        posicionBalanceo++;
                        direccion = 'd';
                        break;
                    case 2:
                        x = soga.getEjeX();
                        y = soga.getEjeY()+4;
                        posicionBalanceo++;
                        break;
                    case 3:
                        x = soga.getEjeX()+3;
                        y = soga.getEjeY()+3;
                        posicionBalanceo++;
                        break;
                    case 4:
                        x = soga.getEjeX()+4;
                        y = soga.getEjeY()+2;
                        posicionBalanceo++;
                        break;
                    case 5:
                        x = soga.getEjeX()+3;
                        y = soga.getEjeY()+3;
                        posicionBalanceo++;
                        direccion = 'i';
                        break;
                    case 6:
                        x = soga.getEjeX();
                        y = soga.getEjeY()+4;
                        posicionBalanceo++;
                        break;
                    case 7:
                        x = soga.getEjeX()-3;
                        y = soga.getEjeY()+3;
                        posicionBalanceo++;
                        break;
                    case 8:
                        x = soga.getEjeX()-4;
                        y = soga.getEjeY()+2;
                        posicionBalanceo=1;
                        break;
                    default:
                        break;
                }
                break;
            case 3:
                switch (posicionBalanceo)
                {
                    case 0:
                        x = soga.getEjeX()-6;
                        y = soga.getEjeY()+3;
                        posicionBalanceo++;
                        break;
                    case 1:
                        x = soga.getEjeX()-4;
                        y = soga.getEjeY()+4;
                        posicionBalanceo++;
                        direccion = 'd';
                        break;
                    case 2:
                        x = soga.getEjeX();
                        y = soga.getEjeY()+5;
                        posicionBalanceo++;
                        break;
                    case 3:
                        x = soga.getEjeX()+4;
                        y = soga.getEjeY()+4;
                        posicionBalanceo++;
                        break;
                    case 4:
                        x = soga.getEjeX()+6;
                        y = soga.getEjeY()+3;
                        posicionBalanceo++;
                        break;
                    case 5:
                        x = soga.getEjeX()+4;
                        y = soga.getEjeY()+4;
                        posicionBalanceo++;
                        direccion = 'i';
                        break;
                    case 6:
                        x = soga.getEjeX();
                        y = soga.getEjeY()+5;
                        posicionBalanceo++;
                        break;
                    case 7:
                        x = soga.getEjeX()-4;
                        y = soga.getEjeY()+4;
                        posicionBalanceo++;
                        break;
                    case 8:
                        x = soga.getEjeX()-6;
                        y = soga.getEjeY()+3;
                        posicionBalanceo=1;
                        break;
                    default:
                        break;
                }
                break;
            case 4:
                switch (posicionBalanceo)
                {
                    case 0:
                        x = soga.getEjeX()-8;
                        y = soga.getEjeY()+4;
                        posicionBalanceo++;
                        break;
                    case 1:
                        x = soga.getEjeX()-5;
                        y = soga.getEjeY()+5;
                        posicionBalanceo++;
                        direccion = 'd';
                        break;
                    case 2:
                        x = soga.getEjeX();
                        y = soga.getEjeY()+6;
                        posicionBalanceo++;
                        break;
                    case 3:
                        x = soga.getEjeX()+5;
                        y = soga.getEjeY()+5;
                        posicionBalanceo++;
                        break;
                    case 4:
                        x = soga.getEjeX()+8;
                        y = soga.getEjeY()+4;
                        posicionBalanceo++;
                        break;
                    case 5:
                        x = soga.getEjeX()+5;
                        y = soga.getEjeY()+5;
                        posicionBalanceo++;
                        direccion = 'i';
                        break;
                    case 6:
                        x = soga.getEjeX();
                        y = soga.getEjeY()+6;
                        posicionBalanceo++;
                        break;
                    case 7:
                        x = soga.getEjeX()-5;
                        y = soga.getEjeY()+5;
                        posicionBalanceo++;
                        break;
                    case 8:
                        x = soga.getEjeX()-8;
                        y = soga.getEjeY()+4;
                        posicionBalanceo=1;
                        break;
                    default:
                        break;
                }
                break;
            case 5:
                switch (posicionBalanceo)
                {
                    case 0:
                        x = soga.getEjeX()-10;
                        y = soga.getEjeY()+5;
                        posicionBalanceo++;
                        break;
                    case 1:
                        x = soga.getEjeX()-6;
                        y = soga.getEjeY()+6;
                        posicionBalanceo++;
                        direccion = 'd';
                        break;
                    case 2:
                        x = soga.getEjeX();
                        y = soga.getEjeY()+7;
                        posicionBalanceo++;
                        break;
                    case 3:
                        x = soga.getEjeX()+6;
                        y = soga.getEjeY()+6;
                        posicionBalanceo++;
                        break;
                    case 4:
                        x = soga.getEjeX()+10;
                        y = soga.getEjeY()+5;
                        posicionBalanceo++;
                        break;
                    case 5:
                        x = soga.getEjeX()+6;
                        y = soga.getEjeY()+6;
                        posicionBalanceo++;
                        direccion = 'i';
                        break;
                    case 6:
                        x = soga.getEjeX();
                        y = soga.getEjeY()+7;
                        posicionBalanceo++;
                        break;
                    case 7:
                        x = soga.getEjeX()-6;
                        y = soga.getEjeY()+6;
                        posicionBalanceo++;
                        break;
                    case 8:
                        x = soga.getEjeX()-10;
                        y = soga.getEjeY()+5;
                        posicionBalanceo=1;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
    else
    {
        switch (soga.getLongitud())
        {
            case 1:
                switch (posicionBalanceo)
                {
                    case 0:
                        x = soga.getEjeX()+2;
                        y = soga.getEjeY()+1;
                        posicionBalanceo++;
                        break;
                    case 1:
                        x = soga.getEjeX();
                        y = soga.getEjeY()+2;
                        posicionBalanceo++;
                        direccion = 'i';
                        break;
                    case 2:
                        x = soga.getEjeX()-2;
                        y = soga.getEjeY()+1;
                        posicionBalanceo++;
                        break;
                    case 3:
                        x = soga.getEjeX();
                        y = soga.getEjeY()+2;
                        posicionBalanceo++;
                        direccion = 'd';
                        break;
                    case 4:
                        x = soga.getEjeX()+2;
                        y = soga.getEjeY()+1;
                        posicionBalanceo=1;
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                switch (posicionBalanceo)
                {
                    case 0:
                        x = soga.getEjeX()+4;
                        y = soga.getEjeY()+2;
                        posicionBalanceo++;
                        break;
                    case 1:
                        x = soga.getEjeX()+3;
                        y = soga.getEjeY()+3;
                        posicionBalanceo++;
                        direccion = 'i';
                        break;
                    case 2:
                        x = soga.getEjeX();
                        y = soga.getEjeY()+4;
                        posicionBalanceo++;
                        break;
                    case 3:
                        x = soga.getEjeX()-3;
                        y = soga.getEjeY()+3;
                        posicionBalanceo++;
                        break;
                    case 4:
                        x = soga.getEjeX()-4;
                        y = soga.getEjeY()+2;
                        posicionBalanceo++;
                        break;
                    case 5:
                        x = soga.getEjeX()-3;
                        y = soga.getEjeY()+3;
                        posicionBalanceo++;
                        direccion = 'd';
                        break;
                    case 6:
                        x = soga.getEjeX();
                        y = soga.getEjeY()+4;
                        posicionBalanceo++;
                        break;
                    case 7:
                        x = soga.getEjeX()+3;
                        y = soga.getEjeY()+3;
                        posicionBalanceo++;
                        break;
                    case 8:
                        x = soga.getEjeX()+4;
                        y = soga.getEjeY()+2;
                        posicionBalanceo=1;
                        break;
                    default:
                        break;
                }
                break;
            case 3:
                switch (posicionBalanceo)
                {
                    case 0:
                        x = soga.getEjeX()+6;
                        y = soga.getEjeY()+3;
                        posicionBalanceo++;
                        break;
                    case 1:
                        x = soga.getEjeX()+4;
                        y = soga.getEjeY()+4;
                        posicionBalanceo++;
                        direccion = 'i';
                        break;
                    case 2:
                        x = soga.getEjeX();
                        y = soga.getEjeY()+5;
                        posicionBalanceo++;
                        break;
                    case 3:
                        x = soga.getEjeX()-4;
                        y = soga.getEjeY()+4;
                        posicionBalanceo++;
                        break;
                    case 4:
                        x = soga.getEjeX()-6;
                        y = soga.getEjeY()+3;
                        posicionBalanceo++;
                        break;
                    case 5:
                        x = soga.getEjeX()-4;
                        y = soga.getEjeY()+4;
                        posicionBalanceo++;
                        direccion = 'd';
                        break;
                    case 6:
                        x = soga.getEjeX();
                        y = soga.getEjeY()+5;
                        posicionBalanceo++;
                        break;
                    case 7:
                        x = soga.getEjeX()+4;
                        y = soga.getEjeY()+4;
                        posicionBalanceo++;
                        break;
                    case 8:
                        x = soga.getEjeX()+6;
                        y = soga.getEjeY()+3;
                        posicionBalanceo=1;
                        break;
                    default:
                        break;
                }
                break;
            case 4:
                switch (posicionBalanceo)
                {
                    case 0:
                        x = soga.getEjeX()+8;
                        y = soga.getEjeY()+4;
                        posicionBalanceo++;
                        break;
                    case 1:
                        x = soga.getEjeX()+5;
                        y = soga.getEjeY()+5;
                        posicionBalanceo++;
                        direccion = 'i';
                        break;
                    case 2:
                        x = soga.getEjeX();
                        y = soga.getEjeY()+6;
                        posicionBalanceo++;
                        break;
                    case 3:
                        x = soga.getEjeX()-5;
                        y = soga.getEjeY()+5;
                        posicionBalanceo++;
                        break;
                    case 4:
                        x = soga.getEjeX()-8;
                        y = soga.getEjeY()+4;
                        posicionBalanceo++;
                        break;
                    case 5:
                        x = soga.getEjeX()-5;
                        y = soga.getEjeY()+5;
                        posicionBalanceo++;
                        direccion = 'd';
                        break;
                    case 6:
                        x = soga.getEjeX();
                        y = soga.getEjeY()+6;
                        posicionBalanceo++;
                        break;
                    case 7:
                        x = soga.getEjeX()+5;
                        y = soga.getEjeY()+5;
                        posicionBalanceo++;
                        break;
                    case 8:
                        x = soga.getEjeX()+8;
                        y = soga.getEjeY()+4;
                        posicionBalanceo=1;
                        break;
                    default:
                        break;
                }
                break;
            case 5:
                switch (posicionBalanceo)
                {
                    case 0:
                        x = soga.getEjeX()+10;
                        y = soga.getEjeY()+5;
                        posicionBalanceo++;
                        break;
                    case 1:
                        x = soga.getEjeX()+6;
                        y = soga.getEjeY()+6;
                        posicionBalanceo++;
                        direccion = 'i';
                        break;
                    case 2:
                        x = soga.getEjeX();
                        y = soga.getEjeY()+7;
                        posicionBalanceo++;
                        break;
                    case 3:
                        x = soga.getEjeX()-6;
                        y = soga.getEjeY()+6;
                        posicionBalanceo++;
                        break;
                    case 4:
                        x = soga.getEjeX()-10;
                        y = soga.getEjeY()+5;
                        posicionBalanceo++;
                        break;
                    case 5:
                        x = soga.getEjeX()-6;
                        y = soga.getEjeY()+6;
                        posicionBalanceo++;
                        direccion = 'd';
                        break;
                    case 6:
                        x = soga.getEjeX();
                        y = soga.getEjeY()+7;
                        posicionBalanceo++;
                        break;
                    case 7:
                        x = soga.getEjeX()+6;
                        y = soga.getEjeY()+6;
                        posicionBalanceo++;
                        break;
                    case 8:
                        x = soga.getEjeX()+10;
                        y = soga.getEjeY()+5;
                        posicionBalanceo=1;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
    
}
void Jugador::saltar()
{   
    if (direccion == 'd')
    {
        switch (posicionSalto)
        {
        case 0:
            x+=2; y-=4; posicionSalto++;
            break;
        case 1:
            x+=3; y-=3; posicionSalto++;
            break;
        case 2:
            x+=2; posicionSalto++;
            break;
        case 3:
            x+=3; y+=1; posicionSalto++;
            break;
        case 4:
            x+=2; y+=1; posicionSalto++;
            break;
        case 5:
            x+=1; y+=1; posicionSalto=0;
            estado = 'c';
            break;
        default:
            break;
        }
    }
    if (direccion =='i')
    {
        switch (posicionSalto)
        {
        case 0:
            x-=2; y-=4; posicionSalto++;
            break;
        case 1:
            x-=3; y-=3; posicionSalto++;
            break;
        case 2:
            x-=2; posicionSalto++;
            break;
        case 3:
            x-=3; y+=1; posicionSalto++;
            break;
        case 4:
            x-=2; y+=1; posicionSalto++;
            break;
        case 5:
            x-=1; y+=1; posicionSalto=0;
            estado = 'c';
            break;
        default:
            break;
        }
    } 
}
void Jugador::jetpack()
{
    if (direccion == 'd')
    {
        switch (posicionJetpack)
        {
        case 0:
            x++; y--; posicionJetpack++;
            break;
        case 1:
            x++; y--; posicionJetpack++;
            break;
        case 2:
            x++; y--; posicionJetpack++;
            break;
        case 3:
            x++; posicionJetpack++;
            break;
        case 4:
            x++; y++; posicionJetpack++;
            break;
        case 5:
            x++; y++; posicionJetpack++;
            break;
        case 6:
            x++; y--; posicionJetpack++;
            break;
        case 7:
            x++; y--; posicionJetpack++;
            break;
        case 8:
            x++; y--; posicionJetpack++;
            break;
        case 9:
            x++; posicionJetpack++;
            break;
        case 10:
            x++; y++; posicionJetpack++;
            break;
        case 11:
            x++; y++; posicionJetpack=0;
            estado = 'c';
            break;
        default:
            break;
        }
    }
    if (direccion =='i')
    {
        switch (posicionJetpack)
        {
        case 0:
            x--; y--; posicionJetpack++;
            break;
        case 1:
            x--; y--; posicionJetpack++;
            break;
        case 2:
            x--; y--; posicionJetpack++;
            break;
        case 3:
            x--; posicionJetpack++;
            break;
        case 4:
            x--; y++; posicionJetpack++;
            break;
        case 5:
            x--; y++; posicionJetpack++;
            break;
        case 6:
            x--; y--; posicionJetpack++;
            break;
        case 7:
            x--; y--; posicionJetpack++;
            break;
        case 8:
            x--; y--; posicionJetpack++;
            break;
        case 9:
            x--; posicionJetpack++;
            break;
        case 10:
            x--; y++; posicionJetpack++;
            break;
        case 11:
            x--; y++; posicionJetpack=0;
            estado = 'c';
            break;
        default:
            break;
        }
    }
    
}