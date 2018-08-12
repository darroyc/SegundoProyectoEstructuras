#include "ColaDePrioridad.h"

ColaDePrioridad::ColaDePrioridad(){
	cabeza = NULL;
}

ColaDePrioridad::ColaDePrioridad(int cantidad) {
	crearNodos(cantidad);
}

ColaDePrioridad::~ColaDePrioridad(){
}

NodoCola * ColaDePrioridad::getCabeza(){
	return cabeza;
}

void ColaDePrioridad::setCabeza(NodoCola* newCabeza){
	cabeza = newCabeza;
}

void ColaDePrioridad::insertar(int indice) {
	NodoCola* nuevo = new NodoCola(indice);
	if (estaVacia()) {
		setCabeza(nuevo);
	}
	else {
		NodoCola* aux = getCabeza();
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

	NodoCola* aux = getCabeza();
	string contenido;
	while (aux!=NULL) {
		contenido += to_string(aux->getInfo()) + " ";
		aux = aux->getSiguiente();
	}
	return contenido+"\n";
}

NodoCola* ColaDePrioridad::buscar(int indice)
{
	if (!estaVacia()) {
		NodoCola* aux = this->getCabeza();
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
	NodoCola* nodo = buscar(indice);
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
		NodoCola* aux = this->getCabeza();
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
