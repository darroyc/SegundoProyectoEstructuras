#include "ColaDePrioridad.h"

ColaDePrioridad::ColaDePrioridad(){
	cabeza = NULL;
}

ColaDePrioridad::ColaDePrioridad(int cantidad) {
	cabeza = new Nodo();
}

ColaDePrioridad::~ColaDePrioridad(){
}

Nodo * ColaDePrioridad::getCabeza(){
	return cabeza;
}

void ColaDePrioridad::setCabeza(Nodo* newCabeza){
	cabeza = newCabeza;
}

void ColaDePrioridad::insertarAlInicio(int indice){
	Nodo* nuevo = new Nodo(indice);
	if (colaVacia()) {
		cabeza = nuevo;
	}
	else {
		nuevo->setSiguiente(cabeza);
		setCabeza(nuevo);
	}

}

void ColaDePrioridad::crearNodos(int cantidad) {
	if(cantidad != 0){
		insertarAlInicio(cantidad - 1);
		crearNodos(cantidad - 1);
	}
}

string ColaDePrioridad::mostrar()
{

	if (colaVacia()) {
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
	if (!colaVacia()) {
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

bool ColaDePrioridad::colaVacia()
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
