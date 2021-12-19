#include "Soga.h"
#include "Jugador.h"

void Soga::setEstado(char estado)
{
    this->estado = estado;
}
void Soga::setEjeX(int x)
{
    ejeX = x;
}
void Soga::setEjeY(int y)
{
    ejeY = y;
}
void Soga::setLongitud(int longitud)
{
    this->longitud = longitud;
}
char Soga::getEstado()
{
    return estado;
}
int Soga::getLongitud()
{
    return longitud;
}
char Soga::getDireccionDisparo()
{
    return direccionDisparo;
}
int Soga::getEjeX()
{
    return ejeX;
}
int Soga::getEjeY()
{
    return ejeY;
}
void Soga::setup()
{
    ejeX=60;
    ejeY=5;
    estado = 'a';
    longitud = 5;
    direccionDisparo='d';
}
void Soga::update(vector<Pared> & Paredes, Jugador & jugador)
{
    if(longitud > 5)
    {
        estado = 'n';
        longitud = 0;
        jugador.setEstado('c');
        for(int i = 0; i < Paredes.size(); i++)
        {
            Paredes[i].setAcoplada(false);
        }
    }
    if(estado == 'n')
    {
        ejeX = jugador.getX();
        ejeY = jugador.getY();
    }
    if (estado == 'd')
    {
        if(jugador.getDireccion() == 'd')
        {
            direccionDisparo = 'd';
            ejeX+=2;
            ejeY--;
            longitud ++;
            for(int i = 0; i < Paredes.size(); i++)
            {
                if(Paredes[i].getX() == ejeX && Paredes[i].getY() == ejeY)
                {
                    estado = 'a';
                    jugador.setEstado('a');
                    Paredes[i].setAcoplada(true);
                }
            }
        }
        else
        {
            direccionDisparo = 'i';
            ejeX-=2;
            ejeY--;
            longitud ++;
            for(int i = 0; i < Paredes.size(); i++)
            {
                if(Paredes[i].getX() == ejeX && Paredes[i].getY() == ejeY)
                {
                    estado = 'a';
                    jugador.setEstado('a');
                    Paredes[i].setAcoplada(true);
                }
            }
        }
        
    }  
    if(estado == 'a' && jugador.getEstado() != 'r')
    {
        for(int i = 0; i < Paredes.size(); i++)
        {
            if(Paredes[i].getAcoplada())
            {
                ejeX = Paredes[i].getX();
                ejeY = Paredes[i].getY();
            }
        }
    }
}
void Soga::draw(int vidas, Jugador jugador)
{   
    if(vidas)mvaddch(ejeY, ejeX, 'X');

    for(float y=1; y<40; y++)
    {
        for(float x=1; x<120; x++)
        {
            if(vidas && y<jugador.getY() && y>ejeY)
            {
                if ((ejeX-jugador.getX()) == 0) mvaddch(y,ejeX,'O');
                if(y-jugador.getY() == ((ejeY-jugador.getY())/(ejeX-jugador.getX())*(x-jugador.getX()))) mvaddch(y,x,'O'); 
            }
        }
    }
    
    // if(/*vidas && */(estado == 'd' || estado == 'a') && jugador.getPosicionBalanceo() == 1)
    // {
    //     for(int y = 0; y < 40; y++)
    //     {
    //         for (int x = 0; x < 120; x++)
    //         {
    //             if((y-ejeY == (-x+ejeX)*0.5) && (y > ejeY) && y < jugador.getY()) mvaddch(y,x,'O');
    //         }
    //     }
    //     // switch (longitud)
    //     // {
    //     // case 1:
    //     //     break;
    //     // case 2:
    //     //     mvaddch(ejeY,ejeX, 'O');
    //     //     mvaddch(ejeY+1,ejeX+(jugador.getX()-ejeX)/2, 'O');
    //     //     break;
    //     // case 3:
    //     //     mvaddch(ejeY,ejeX, 'O');
    //     //     mvaddch(ejeY+1,ejeX+(jugador.getX()-ejeX)/3, 'O');
    //     //     mvaddch(ejeY+2,ejeX+(jugador.getX()-ejeX)/1.5, 'O');
    //     //     break;
    //     // case 4:
    //     //     mvaddch(ejeY,ejeX, 'O');
    //     //     mvaddch(ejeY+1,ejeX+(jugador.getX()-ejeX)/4, 'O');
    //     //     mvaddch(ejeY+2,ejeX+(jugador.getX()-ejeX)/2, 'O');
    //     //     mvaddch(ejeY+3,ejeX+(round(jugador.getX()-ejeX)/1.34), 'O');
    //     //     break;
    //     // case 5:
    //     //     mvaddch(ejeY,ejeX, 'O');
    //     //     mvaddch(ejeY+1,ejeX+(jugador.getX()-ejeX)/5, 'O');
    //     //     mvaddch(ejeY+2,ejeX+(jugador.getX()-ejeX)/2.5, 'O');
    //     //     mvaddch(ejeY+3,ejeX+(jugador.getX()-ejeX)/1.67, 'O');
    //     //     mvaddch(ejeY+4,ejeX+(jugador.getX()-ejeX)/1.25, 'O');

    //     //     break;
    //     // default:
    //     //     break;
    //     // }
        
        
    // }
    // if(estado == 'a' && (jugador.getPosicionBalanceo()==2 || jugador.getPosicionBalanceo()==8))
    // {
    //     for(int y = 0; y < 40; y++)
    //     {
    //         for (int x = 0; x < 120; x++)
    //         {
    //             if((y-ejeY == -x+ejeX) && (y > ejeY) && y < jugador.getY()) mvaddch(y,x,'O');
    //         }
    //     }
    // }
    // if(estado == 'a' && (jugador.getPosicionBalanceo()==3 || jugador.getPosicionBalanceo()==7))
    // {
    //     for(int y = 0; y < 40; y++)
    //     {
    //         for (int x = 0; x < 120; x++)
    //         {
    //             if((x == ejeX) && (y > ejeY) && y < jugador.getY()) mvaddch(y,x,'O');
    //         }
    //     }
    // }
    // if(estado == 'a' && (jugador.getPosicionBalanceo()==4 || jugador.getPosicionBalanceo()==6))
    // {
    //     for(int y = 0; y < 40; y++)
    //     {
    //         for (int x = 0; x < 120; x++)
    //         {
    //             if((y-ejeY == x-ejeX) && (y > ejeY) && y < jugador.getY()) mvaddch(y,x,'O');
    //         }
    //     }
    // }
    // if(estado == 'a' && jugador.getPosicionBalanceo()==5)
    // {
    //     for(int y = 0; y < 40; y++)
    //     {
    //         for (int x = 0; x < 120; x++)
    //         {
    //             if((y-ejeY == (x-ejeX)*0.5) && (y > ejeY) && y < jugador.getY()) mvaddch(y,x,'O');
    //         }
    //     }
    // }
    

    
}
