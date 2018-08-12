#ifndef ColaDePrioridad_h
#define ColaDePrioridad_h

#include <iostream>
#include <string>
#include "NodoCola.h"
using namespace std;

class ColaDePrioridad {
public:
	// default constructor
	ColaDePrioridad();

	ColaDePrioridad(int);

	// destructor
	~ColaDePrioridad();

	// accessor functions
	NodoCola* getCabeza();
	void setCabeza(NodoCola* newCabeza);

	//Fucntions
	string mostrar();
	NodoCola* buscar(int);
	void crearNodos(int);
	void insertarDatoEnIndice(int, int info);
	bool estaVacia();
	bool estaLlena();
	int retornarLargo();
	void vaciar();

private:
	// variable del miembro

	NodoCola* cabeza;

	void insertar(int);
};


#endif ColaDePrioridad_h