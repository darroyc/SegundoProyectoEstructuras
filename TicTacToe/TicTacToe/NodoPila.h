#ifndef Nodo_h
#define Nodo_h

#include <iostream>
#include <string>
#include "ColaDePrioridad.h"
using namespace std;

class NodoPila {
public:
	// default constructor
	NodoPila();

	NodoPila(string);

	// destructor
	~NodoPila();

	// accessor functions
	string getInfo();
	NodoPila* getSiguiente();
	void setInfo(string);
	void setSiguiente(NodoPila*);

private:
	// variable del miembro
	string info;
	NodoPila* siguiente;
};

#endif NodoPila_h
