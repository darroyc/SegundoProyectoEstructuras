#ifndef Gestor_h
#define Gestor_h

#include <iostream>
#include <string>

#include "ColaDePrioridad.h"

using namespace std;

class Gestor {
public:
	// default constructor
	Gestor();

	// destructor
	~Gestor();

	// accessor functions
	ColaDePrioridad* getTablero();
	ColaDePrioridad* getMarcador();
	void setMarcador(ColaDePrioridad*);
	void setTablero(ColaDePrioridad*);
	void actualizarMarcador(int);
	string retornarMarcador();
	void realizarMovimiento(int, int);
	void mostrarMovimientos(int);
	string retornarTablero();
	bool verificarSiHayGanador();

private:
	// variable del miembro
	ColaDePrioridad* tablero;
	ColaDePrioridad* marcador;
	void guardarSesion();
};

#endif Gestor_h
