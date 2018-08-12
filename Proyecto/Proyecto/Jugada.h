#pragma once
#include <string>

using namespace std;
class Jugada {
public:
	Jugada();
	virtual ~Jugada();
	Jugada(string, int, int);

	string getNombreJugador();
	void setNombreJugador(string);
	int getCasillaSelect();
	void setCasillaSelect(int);
	int getPrioridad();
	void setPrioridad(int);
	Jugada* getSiguiente();
	void setSiguiente(Jugada*);
	string toString();

private:
	string nombreJugador;
	int casillaSelect;
	int prioridad;
	Jugada* siguiente;
};

