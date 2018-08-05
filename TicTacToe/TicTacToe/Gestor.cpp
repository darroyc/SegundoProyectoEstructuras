#include "Gestor.h"

Gestor::Gestor() {
	setTablero(new ColaDePrioridad(9));
	setMarcador(new ColaDePrioridad(3));
}

Gestor::~Gestor() {
}

ColaDePrioridad* Gestor::getTablero()
{
	return tablero;
}

ColaDePrioridad* Gestor::getMarcador()
{
	return marcador;
}

void Gestor::setMarcador(ColaDePrioridad* colaDePrioridad)
{
	marcador = colaDePrioridad;
}

void Gestor::setTablero(ColaDePrioridad* colaDePrioridad)
{
	tablero = colaDePrioridad;
}

void Gestor::actualizarMarcador(int indice)
{
	getMarcador()->insertarDatoEnIndice(indice, getMarcador()->buscar(indice)->getInfo() + 1);
}

string Gestor::retornarMarcador()
{
	return to_string(getMarcador()->buscar(0)->getInfo()) + "   " 
		+ to_string(getMarcador()->buscar(1)->getInfo()) + "   "
		+ to_string(getMarcador()->buscar(2)->getInfo()) + "\n\n";
}

void Gestor::realizarMovimiento(int indice, int jugador)
{
	getTablero()->buscar(indice)->setInfo(jugador);
}

void Gestor::mostrarMovimientos(int)
{
}

string Gestor::retornarTablero()
{
	string output = "     |     |     \n  "
		+ to_string(tablero->buscar(0)->getInfo()) 
		+ "  |  " + to_string(tablero->buscar(1)->getInfo()) 
		+ "  |  " + to_string(tablero->buscar(2)->getInfo()) + "\n"
		+ "_____|_____|_____\n"
		+ "     |     |     \n"
		+ "  " + to_string(tablero->buscar(3)->getInfo())
		+ "  |  " + to_string(tablero->buscar(4)->getInfo()) 
		+ "  |  " + to_string(tablero->buscar(5)->getInfo()) + "\n"
		+ "_____|_____|_____\n"
		+ "     |     |     \n"
		+ "  " + to_string(tablero->buscar(6)->getInfo())
		+ "  |  " + to_string(tablero->buscar(7)->getInfo())
		+ "  |  " 
		+ to_string(tablero->buscar(8)->getInfo()) + "\n"
		+ "     |     |     \n";

	output = output.replace(output.begin()+35, output.end(), '1', 'X');
	output = output.replace(output.begin()+35, output.end(), '2', 'O');
	
	return output;
}

bool Gestor::verificarSiHayGanador()
{ 
	return false;
}

void Gestor::guardarSesion()
{
}
