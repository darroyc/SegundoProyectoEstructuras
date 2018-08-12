#ifndef NodoCola_h
#define NodoCola_h

#include <iostream>
#include <string>
using namespace std;

class NodoCola {
public:
	// default constructor
	NodoCola();

	NodoCola(int);

	// destructor
	~NodoCola();

	// accessor functions
	int getInfo();
	NodoCola* getSiguiente();
	int getIndice();
	void setInfo(int);
	void setSiguiente(NodoCola*);
	void setIndice(int);

private:
	// variable del miembro
	int info;
	NodoCola* siguiente;
	int indice;
};

#endif NodoCola_h
