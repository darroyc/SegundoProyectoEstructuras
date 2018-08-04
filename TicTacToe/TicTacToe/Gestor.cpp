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
	marcador->insertarDatoEnIndice(indice, marcador->buscar(indice)->getInfo() + 1);
}

string Gestor::mostrarMarcador()
{
	return "| Jugador 1 | Empates | Jugador 2\n" 
		+ marcador->buscar(0)->getInfo() + '   ' + marcador->buscar(1)->getInfo() + '   ' + marcador->buscar(2)->getInfo();
}

void Gestor::realizarMovimiento(int indice, int marca)
{
	tablero->buscar(indice)->setInfo(marca);
}

void Gestor::mostrarMovimientos(int)
{
}

string Gestor::mostrarTablero()
{
	string output = "Player 1 (X)  -  Player 2 (O)\n\n     |     |     \n  "
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

	output = output.replace(output.begin()+35, output.end(), '0', 'X');
	output = output.replace(output.begin()+35, output.end(), '1', 'O');
	
	return output;
}

void Gestor::guardarSesion()
{
}
