#pragma once
#include <string>
#include "Jugada.h"

class ListaJugadas {
public:
	ListaJugadas();
	~ListaJugadas();

	int getLongitud();
	void setLongitud(int);
	Jugada* getFrente();
	void setFrente(Jugada*);
	Jugada* getFin();
	void setFin(Jugada*);
	void pushJugada(string, int);
	bool estaVacia();
	string finalCola();
	//string verJugadasPorJugador(string);

private:
	Jugada * frente;
	Jugada* fin;
	int longitud;
};

