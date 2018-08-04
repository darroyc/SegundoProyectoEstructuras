#include "Nodo.h"

Nodo::Nodo() {
	setInfo(NULL);
	setSiguiente(NULL);
}

Nodo::Nodo(int indice) {
	setInfo(NULL);
	setSiguiente(NULL);
	setIndice(indice);
}

Nodo::~Nodo() {
}

int Nodo::getInfo()
{
	return info;
}

Nodo* Nodo::getSiguiente()
{
	return siguiente;
}

int Nodo::getIndice()
{
	return info;
}


void Nodo::setInfo(int newInfo)
{
	info = newInfo;
}

void Nodo::setSiguiente(Nodo* newSig)
{
	siguiente = newSig;
}

void Nodo::setIndice(int newIndice)
{
	newIndice = indice;
}
