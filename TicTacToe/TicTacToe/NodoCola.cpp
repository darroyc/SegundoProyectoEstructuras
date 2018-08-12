#include "NodoCola.h"

NodoCola::NodoCola() {
	setInfo(NULL);
	setSiguiente(NULL);
}

NodoCola::NodoCola(int indice) {
	setInfo(NULL);
	setSiguiente(NULL);
	setIndice(indice);
}

NodoCola::~NodoCola() {
}

int NodoCola::getInfo()
{
	return info;
}

NodoCola* NodoCola::getSiguiente()
{
	return siguiente;
}

int NodoCola::getIndice()
{
	return indice;
}


void NodoCola::setInfo(int newInfo)
{
	info = newInfo;
}

void NodoCola::setSiguiente(NodoCola* newSig)
{
	siguiente = newSig;
}

void NodoCola::setIndice(int newIndice)
{
	indice = newIndice;
}
