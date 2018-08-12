#pragma once
#include <string>
#include "NodoPila.h"

class PilaPartida {
public:
	PilaPartida();
	~PilaPartida();

	NodoPila* getTope();
	void setTope(NodoPila*);

	bool estaVacia();
	void push(string);
	string pop();

private:
	NodoPila* tope;
};

