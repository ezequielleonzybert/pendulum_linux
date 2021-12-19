//Zybert Ezequiel León

#include <iostream>
#include <ncurses.h>
#include <vector>
#include "Jugador.h"
#include "Soga.h"
#include "Pared.h"
#include "Paquete.h"
#include <string.h>
using namespace std;

int TIEMPO_PAQUETE = 350;
int DELAY = 95;
Jugador jugador;
Soga soga;
vector<Pared> Paredes;
Paquete * paquete;
int vidas = 0, cargas, tiempo, jetpack;
bool pausa = false;
bool menu = true;
bool salir = false;
bool gameOver = false;
bool instrucciones = false;

string arreglo[] = {"1. Iniciar juego", "2. Instrucciones", "3. Salir"};

void setup();
void update();
void draw();
void input();
void menuPrincipal();
void menuInstrucciones();

int main()
{	
	initscr();
	noecho();
	curs_set(false);
	keypad(stdscr, true);
	nodelay(stdscr, true);

	if(COLS < 120 || LINES < 40)
	{
		endwin();
		cout << "El tamaño de La terminal debe ser al menos de 120 x 40" << endl;
		exit(1);
	} 

	for(int i=0; i<5; i++)
	{
		bool inicial = true;
		int aleatorio =rand()%15 + 1;
		for (int j=i*24+1; j<=24*(i+1); j++)
		{
			Paredes.push_back(Pared(j,aleatorio,inicial));
			inicial = false;
		}
	}

	while (!salir)
		{
				input();
				update();
				draw();
		}
	endwin();

	return 0;
}
void setup()
{
		jetpack = 3 ;
		cargas = 25 ;
		jugador.setup();
		soga.setup();
}
void input()
{
	int tecla = getch();
	if(gameOver && !menu && !instrucciones)
	{
		if(tecla == 's' || tecla == 'S')
		{
			gameOver=false;
			vidas = 3;
			tiempo = 0;
			setup();
		}
		if(tecla=='n' || tecla == 'N')
		{
			menu=true;
			tiempo = 0;
		}
	}
	if(menu)
	{
		if(tecla == '1')
		{
			menu = false;
			vidas = 3;
			setup();
		}
		if(tecla == '2')
		{
			instrucciones = true;
			menu = false;
		}
		if(tecla == '3')
		{
			endwin();
			exit(1);
		}
	}
	if(instrucciones)
	{
		if(tecla == '1')
		{
			instrucciones = false;
			menu = true;
		}
	}
	if(vidas)
	{
		switch (tecla)
		{
			
			case ' ':
				if(cargas && !pausa)
				{
					if(soga.getEstado()== 'n')
					{
						soga.setEstado('d');
						jugador.setEstado('d');
						soga.setEjeX(jugador.getX());
						soga.setEjeY(jugador.getY());
						cargas--;
					}
					if(soga.getEstado()=='a')
					{
						jugador.setEstado('s');
						jugador.setPosicionSalto(0);
						jugador.setPosicionBalanceo(0);
						soga.setEstado('n');
						soga.setLongitud(0);
						for(int i = 0; i < Paredes.size(); i++) Paredes[i].setAcoplada(false);
					}
				}
				break;
			case 'z':
				if((jugador.getEstado()=='s' || jugador.getEstado() == 'c') && jetpack && !pausa)
					{
						jugador.setPosicionJetpack(0);
						jugador.setEstado('j');
						jetpack --;
					}
				break;
			case 'Z':
				if((jugador.getEstado()=='s' || jugador.getEstado() == 'c') && jetpack && !pausa)
					{
						jugador.setPosicionJetpack(0);
						jugador.setEstado('j');
						jetpack --;
					}
				break;
			case 'p':
				if(pausa) pausa = false;
				else pausa = true;		
				break;
			case 'P':
				if(pausa) pausa = false;
				else pausa = true;			
				break;
			default:
				break;
		}
	}
	if(pausa)
	{
		if(tecla == '1') 
		{
			menu = true; tiempo = 0; pausa = false; vidas = 0;
		}
	}
}
void update()
{
	if(!pausa)
	{
		for(int i = 0; i < Paredes.size() ; i++)
		{
			Paredes[i].update(soga);
		}
		if(tiempo >= TIEMPO_PAQUETE) paquete->update(jugador, cargas, jetpack);
		if(vidas)
		{
			if(jugador.getX() < 3 || jugador.getY() > 37)
			{
				vidas--;
				setup();
			}
			if(jugador.getEstado() != 'r') tiempo++;
			soga.update(Paredes, jugador);		
			jugador.update(soga);
			if(!(tiempo%TIEMPO_PAQUETE))
			{
				paquete = new Paquete();
			}
		}
		else 
		{
			gameOver = true;
		}
	}
}
void draw()
{
	erase();
	mvvline(1,0,ACS_VLINE,38);
	mvvline(1,119,ACS_VLINE,38);
	mvhline(0,1,ACS_HLINE,119);
	mvhline(39,1,ACS_HLINE,119);
	mvaddch(0,0,ACS_ULCORNER);
	mvaddch(0,119,ACS_URCORNER);
	mvaddch(39,0,ACS_LLCORNER);
	mvaddch(39,119,ACS_LRCORNER);
	for(int i = 0; i< Paredes.size(); i++)
	{
		Paredes[i].draw();
	}
	jugador.draw(vidas);
	if (soga.getEstado()!= 'n')soga.draw(vidas, jugador);
	if(tiempo >= TIEMPO_PAQUETE )paquete->draw();
	if(!menu && !instrucciones)
	{
		mvprintw(0,100,"[VIDAS: %d ]", vidas);
		mvprintw(0,80, "[CARGAS: %d ]", cargas);
		mvprintw(0,10, "[TIEMPO: %d ]", tiempo/10);
		mvprintw(0,60, "[JETPACK: %d ]", jetpack);
	}
	//mvaddch(35,115,soga.getEstado()); 				//testear estado
	if(!vidas && !menu && !instrucciones)
	{
		mvprintw(20, 40,"  ___   _   __  __ ___    _____   _____ ___");
		mvprintw(21, 40," / __| /_\\ |  \\/  | __|  / _ \\ \\ / / __| _ \\");
		mvprintw(22, 40,"| (_ |/ _ \\| |\\/| | _|  | (_) \\ V /| _||   /");
		mvprintw(23, 40," \\___/_/ \\_\\_|  |_|___|  \\___/ \\_/ |___|_|_\\");
		mvprintw(26,50,"¿VOLVER A JUGAR? ( S / N )");
	}
	if(menu)
	{
		menuPrincipal();
	}
	if(instrucciones) menuInstrucciones();
	if(pausa)
	{
	mvprintw(19,50,R"( ___  _  _   _ ___   _ )");
	mvprintw(20,50,R"(| _ \/_\| | | / __| /_\)");
	mvprintw(21,50,R"(|  _/ _ \ |_| \__ \/ _ \)");
	mvprintw(22,50,R"(|_|/_/ \_\___/|___/_/ \_\)");
	mvprintw(25,57,"1. Salir");
	}
	for(int i=0; i < 40; i++)
	{
		mvhline(i,121,' ',20);
	}

	refresh();
	delay_output(DELAY);
}
void menuPrincipal()
{
		mvprintw(20, 37,R"( ____  _____ _   _ ____  _   _ _    _   _ __  __ )");
		mvprintw(21, 37,R"(|  _ \| ____| \ | |  _ \| | | | |  | | | |  \/  |)");
		mvprintw(22, 37,R"(| |_) |  _| |  \| | | | | | | | |  | | | | |\/| |)");
		mvprintw(23, 37,R"(|  __/| |___| |\  | |_| | |_| | |__| |_| | |  | |)");
		mvprintw(24, 37,R"(|_|   |_____|_| \_|____/ \___/|_____\___/|_|  |_|)");
		mvprintw(26, 37,R"(            por Ezequiel León Zybert)");


		mvprintw(29,52,arreglo[0].c_str());
		mvprintw(30,52,arreglo[1].c_str());
		mvprintw(31,52,arreglo[2].c_str());


}
void menuInstrucciones()
{
	mvprintw(20,8, "Bienvenido a PENDULUM, el juego que tiene una metáfora artística tan profunda que ni siquiera la entenderás.");
	mvprintw(21,8, "Intenta mantenerte el mayor tiempo posible balanceandote con tu soga desde las plataformas flotantes.");
	mvprintw(23,8, "Comandos:");
	mvprintw(25,8, "[BARRA ESPACIADORA] Disparar soga / saltar desde la soga");
	mvprintw(27,8, "[Z] Jetpack");
	mvprintw(29,8, "[P] Pausar juego / Reanudar juego");

	mvaddch(31,8, '/');
	mvaddch(31,9, ACS_S1);
	mvaddch(31,10, '\\');
	mvprintw(32,13, "¡Intenta atrapar los diamantes flotantes! Te darán una recarga de sogas y de jetpack.");
	mvprintw(32,8,"\\_/");
	mvprintw(35,50,"1. Volver al menú");
} 