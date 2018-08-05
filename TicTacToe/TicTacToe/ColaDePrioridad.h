#ifndef ColaDePrioridad_h
#define ColaDePrioridad_h

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
	bool estaVacia();
	bool estaLlena();
	int retornarLargo();
	void vaciar();

private:
	// variable del miembro

	Nodo* cabeza;

	void insertar(int);
};


#endif ColaDePrioridad_h