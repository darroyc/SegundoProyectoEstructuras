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
	void setNumeroJugador(int);
	void setJugadorActual(string);
	string getJugadorActual();
	int getNumeroJugador();
	void setMarca(char);
	char getMarca();
	void seleccionarJugadores();
	void empezarJuego();


private:
	// variable del miembro
	string jugador1;
	string jugador2;
	int numeroJugador;
	string jugadorActual;
	char marca;
	Gestor* gestor;
	void print(string);
	void verEstadoActual();
	void cambiarJugadorActual();
	void mostrarMarcador();
	void mostrarMenuDeJugadas();
	int continuar();
	void efectuarMovimiento();
	int leerOpcion(int);
};

#endif Menu_h
