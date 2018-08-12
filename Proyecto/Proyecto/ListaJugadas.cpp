#include "stdafx.h"
#include "ListaJugadas.h"
#include "Jugada.h"
#include <string>
#include <iostream>


ListaJugadas::ListaJugadas() {
	setFrente(NULL);
	setFin(NULL);
	setLongitud(0);
}

ListaJugadas::~ListaJugadas() {
}

int ListaJugadas::getLongitud() {
	return longitud;
}

void ListaJugadas::setLongitud(int longitud) {
	this->longitud = longitud;
}

Jugada* ListaJugadas::getFrente() {
	return frente;
}

void ListaJugadas::setFrente(Jugada* frente) {
	this->frente = frente;
}

Jugada* ListaJugadas::getFin() {
	return fin;
}

void ListaJugadas::setFin(Jugada* fin) {
	this->fin = fin;
}

bool ListaJugadas::estaVacia() {
	if (this->getFin() == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void ListaJugadas::pushJugada(string nombreJugador, int casillaSelect) {
	int prioridad = 1;
	Jugada *nueva = new Jugada(nombreJugador, casillaSelect, prioridad);

	if (this->estaVacia()) {
		frente = nueva;
		fin = nueva;
	}
	else {
		nueva->setPrioridad(fin->getPrioridad() + 1); //obtiene la prioridad del último fin para la nueva jugada y le suma 1
		fin->setSiguiente(nueva); // al que está apuntando al anterior que es el fin le dice que apunte a la nueva jugada 
		fin = nueva; // asigna como fin a la nueva jugada
	}
	longitud++;
}

string ListaJugadas::finalCola() {
	if (!this->estaVacia()) {
		string cola;
		Jugada* nueva = frente;

		while (nueva != NULL) {
			cola += nueva->toString();

			nueva = nueva->getSiguiente();
		}
		return cola;
	}
	else {
		return "No hay jugadas registradas";
	}
}

//string ListaJugadas::verJugadasPorJugador(string jugador) {
//	if (!this->estaVacia()) {
//		string cola;
//		Jugada* nueva = this->getFrente();
//
//		while (nueva != NULL) {
//			if(nueva->getNombreJugador() == jugador) {
//				cola += nueva->toString();
//			}
//			else {
//				nueva = nueva->getSiguiente();
//			}
//		}
//		return cola;
//	}
//	else {
//		return "No hay jugadas registradas";
//	}
//}


