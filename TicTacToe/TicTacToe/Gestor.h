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
	bool verificarSiTableroEstaLleno();
	void reiniciarTablero();

private:
	// variable del miembro
	ColaDePrioridad* tablero;
	ColaDePrioridad* marcador;
	void guardarSesion();
	void inicializarMarcador();
	string replaceChar(string str, char ch1, char ch2);
};

#endif Gestor_h
