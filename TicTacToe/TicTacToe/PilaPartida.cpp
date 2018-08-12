#include "PilaPartida.h"

PilaPartida::PilaPartida() {
	setTope(NULL);
}

PilaPartida::~PilaPartida() {
}

NodoPila* PilaPartida::getTope() {
	return tope;
}

void PilaPartida::setTope(NodoPila* tope) {
	this->tope = tope;
}

bool PilaPartida::estaVacia() {
	if (this->getTope() == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void PilaPartida::push(string tablero) {
	/* Crear un nodo nuevo */
	 NodoPila* nuevo = new NodoPila();
	 nuevo->setInfo(tablero);

	 nuevo->setSiguiente(getTope());
	setTope(nuevo);
}

string PilaPartida::pop() {
	NodoPila* aux = getTope();
	string tablero;
	if (estaVacia()) {
		return "";
	}
	/* Asignamos a pila toda la pila menos el primer elemento */
	setTope(aux->getSiguiente());
	tablero = aux->getInfo();
	/* Borrar el nodo */
	free(aux);
	return tablero;
}