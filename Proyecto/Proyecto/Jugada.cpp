#include "stdafx.h"
#include "Jugada.h"


Jugada::Jugada() {
}

Jugada::~Jugada() {
}

Jugada::Jugada(string nombreJugador, int casillaSelect, int prioridad) {
	setCasillaSelect(casillaSelect);
	setPrioridad(prioridad);
	setNombreJugador(nombreJugador);
}

string Jugada::getNombreJugador() {
	return nombreJugador;
}

void Jugada::setNombreJugador(string nombreJugador) {
	this->nombreJugador = nombreJugador;
}

int Jugada::getCasillaSelect() {
	return casillaSelect;
}

void Jugada::setCasillaSelect(int casillaSelect) {
	this->casillaSelect = casillaSelect;

}

int Jugada::getPrioridad() {
	return prioridad;
}

void Jugada::setPrioridad(int prioridad) {
	this->prioridad = prioridad;

}

Jugada* Jugada::getSiguiente() {
	return siguiente;
}

void Jugada::setSiguiente(Jugada* siguiente) {
	this->siguiente = siguiente;

}

string Jugada::toString()
{
	return "Jugador: " + this->getNombreJugador() + "\n" + "Casilla seleccionada: " + to_string(this->getCasillaSelect()) + "\n";
}
