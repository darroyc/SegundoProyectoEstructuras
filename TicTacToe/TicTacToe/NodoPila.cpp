#include "NodoPila.h"

NodoPila::NodoPila() {
	setInfo("");
	setSiguiente(NULL);
}

NodoPila::NodoPila(string info) {
	setInfo(info);
	setSiguiente(NULL);
}

NodoPila::~NodoPila() {
}

string NodoPila::getInfo()
{
	return info;
}

NodoPila* NodoPila::getSiguiente()
{
	return siguiente;
}


void NodoPila::setInfo(string newInfo)
{
	info = newInfo;
}

void NodoPila::setSiguiente(NodoPila* newSig)
{
	siguiente = newSig;
}

