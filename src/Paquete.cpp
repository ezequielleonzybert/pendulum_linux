#include "Paquete.h"
#include "Jugador.h"

int contador = 0;

Paquete::Paquete(void)
{
    x=119;
    y=rand()%10+5;
    capturado = false;
}
void Paquete::update(Jugador jugador, int & cargas, int & jetpack)
{
    if(jugador.getEstado()!='d')
    {
        x-=0.5; 
        switch (contador)
        {
        case 0:
        y++; contador ++;
            break;
        case 1:
        y--; contador++;
            break;
        case 2:
        y--; contador++;
            break;
        case 3:
        y++; contador=0;
            break;
        default:
            break;
        }
    } 
    if((jugador.getX() >= x-3 && jugador.getX() <= x+5)
    && (jugador.getY() >= y-2 && jugador.getY() <= y+3)
    && !capturado)
    {
        delete this; 
        jetpack = 3;
        cargas = 25;
        capturado = true;
        animacionCapturado = 1;
    }
}
void Paquete::draw()
{
    if(!capturado)
    {mvaddch(y,x,'/');
    mvaddch(y,x+1,ACS_S1);
    mvaddch(y,x+2,'\\');
    mvaddch(y+1,x,'\\');
    mvaddch(y+1,x+1,ACS_S9);
    mvaddch(y+1,x+2,'/');}

    if (animacionCapturado)
    {
        if(animacionCapturado%10 < 5)
        {
            mvprintw(30,41,R"(   ___  ______   ____  ___   ___  _______ )");
            mvprintw(31,41,R"(  / _ \/ __/ /  / __ \/ _ | / _ \/ __/ _ \)");
            mvprintw(32,41,R"( / , _/ _// /__/ /_/ / __ |/ // / _// // /)");
            mvprintw(33,41,R"(/_/|_/___/____/\____/_/ |_/____/___/____/ )");
        }
        animacionCapturado++;
        if (animacionCapturado > 25) animacionCapturado = 0;
    }
}
