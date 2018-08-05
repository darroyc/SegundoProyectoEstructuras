#ifndef Menu_h
#define Menu_h

#include <iostream>
#include <string>

#include "Gestor.h"

using namespace std;

class Menu {
public:
	// default constructor
	Menu();

	// destructor
	~Menu();

	// accessor functions
	void setGestor(Gestor*);
	Gestor* getGestor();
	void setJugador1(string);
	string getJugador1();
	void setJugador2(string);
	string getJugador2();
	void seleccionarJugadores();
	void empezarJuego(string);
	void mostrarPuntaje();

private:
	// variable del miembro
	string jugador1;
	string jugador2;
	int jugadorActual;
	Gestor* gestor;
	void print(string);
	void verEstadoActual();
	void cambiarJugadorActual();
};

#endif Menu_h
