#ifndef Lista_h
#define Lista_h

#include <iostream>
#include <string>
#include "Nodo.h"
using namespace std;

class ColaDePrioridad {
public:
	// default constructor
	ColaDePrioridad();

	ColaDePrioridad(int);

	// destructor
	~ColaDePrioridad();

	// accessor functions
	Nodo* getCabeza();
	void setCabeza(Nodo* newCabeza);

	//Fucntions
	string mostrar();
	Nodo* buscar(int);
	void crearNodos(int);
	void insertarDatoEnIndice(int, int info);

private:
	// variable del miembro

	Nodo* cabeza;

	bool colaVacia();
	void insertarAlInicio(int);
};


#endif ColaDePrioridad_h