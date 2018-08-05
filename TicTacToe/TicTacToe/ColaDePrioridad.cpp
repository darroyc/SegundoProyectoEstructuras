#include "ColaDePrioridad.h"

ColaDePrioridad::ColaDePrioridad(){
	cabeza = NULL;
}

ColaDePrioridad::ColaDePrioridad(int cantidad) {
	crearNodos(cantidad);
}

ColaDePrioridad::~ColaDePrioridad(){
}

Nodo * ColaDePrioridad::getCabeza(){
	return cabeza;
}

void ColaDePrioridad::setCabeza(Nodo* newCabeza){
	cabeza = newCabeza;
}

void ColaDePrioridad::insertar(int indice) {
	Nodo* nuevo = new Nodo(indice);
	if (estaVacia()) {
		setCabeza(nuevo);
	}
	else {
		Nodo* aux = getCabeza();
		while (aux->getSiguiente() != NULL) {
			aux = aux->getSiguiente();
		}
		aux->setSiguiente(nuevo);
	}
}

void ColaDePrioridad::crearNodos(int cantidad) {
	for (int i = 0; i < cantidad; i++) {
		insertar(i);
	}
}

string ColaDePrioridad::mostrar()
{
	if (estaVacia()) {
		return "Esta vacia";
	}

	Nodo* aux = getCabeza();
	string contenido;
	while (aux!=NULL) {
		contenido += to_string(aux->getInfo()) + " ";
		aux = aux->getSiguiente();
	}
	return contenido+"\n";
}

Nodo* ColaDePrioridad::buscar(int indice)
{
	if (!estaVacia()) {
		Nodo* aux = this->getCabeza();
		while (aux != NULL) {
			if (aux->getIndice() == indice)
				return aux;
			else
				aux = aux->getSiguiente();
		}
	}
	return NULL;
}

bool ColaDePrioridad::estaVacia()
{
	if (getCabeza() == NULL) {
		return true;
	}
	return false;
}

void ColaDePrioridad::insertarDatoEnIndice(int indice, int info) {
	Nodo* nodo = buscar(indice);
	if (nodo != NULL) {
		nodo->setInfo(info);
	}
}

bool ColaDePrioridad::estaLlena()
{
	bool flag = true;
	for (int i = 0; i < retornarLargo(); i++) {
		if (buscar(i)->getInfo() == 0) {
			flag = false;
		}
	}
	return flag;
}

int ColaDePrioridad::retornarLargo()
{
	if (!estaVacia()) {
		Nodo* aux = this->getCabeza();
		while (aux != NULL) {
			if (aux->getSiguiente() == NULL)
				return aux->getIndice()+1;
			else
				aux = aux->getSiguiente();
		}
	}
	return 0;
}

void ColaDePrioridad::vaciar()
{
	if (!estaVacia()) {
		for (int i = 0; i < retornarLargo(); i++) {
			insertarDatoEnIndice(i, NULL);
		}
	}
}
