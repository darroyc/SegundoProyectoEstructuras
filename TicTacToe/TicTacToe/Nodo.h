#ifndef Nodo_h
#define Nodo_h

#include <iostream>
#include <string>
using namespace std;

class Nodo {
public:
	// default constructor
	Nodo();

	Nodo(int);

	// destructor
	~Nodo();

	// accessor functions
	int getInfo();
	Nodo* getSiguiente();
	int getIndice();
	void setInfo(int);
	void setSiguiente(Nodo*);
	void setIndice(int);

private:
	// variable del miembro
	int info;
	Nodo* siguiente;
	int indice;
};

#endif Nodo_h
