// TicTacToe.cpp : Defines the entry point for the console application.
//
#include <string>
#include <iostream>
#include "Menu.h"


int main()
{
	Menu* menu = new Menu();
	menu->seleccionarJugadores();
	menu->empezarJuego();
}

