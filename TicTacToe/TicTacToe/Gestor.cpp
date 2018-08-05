#include "Gestor.h"

Gestor::Gestor() {
	setTablero(new ColaDePrioridad(9));
	setMarcador(new ColaDePrioridad(3));
	inicializarMarcador();
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

void Gestor::actualizarMarcador(int index)
{
	index = index - 1;
	getMarcador()->insertarDatoEnIndice(index, getMarcador()->buscar(index)->getInfo() + 1);
}

string Gestor::retornarMarcador()
{
	return "      "+to_string(getMarcador()->buscar(0)->getInfo()) + "      " 
		+ to_string(getMarcador()->buscar(1)->getInfo()) + "      "
		+ to_string(getMarcador()->buscar(2)->getInfo()) + "\n\n";
}

void Gestor::realizarMovimiento(int indice, int jugador)
{
	getTablero()->buscar(indice-1)->setInfo(jugador);
}

void Gestor::mostrarMovimientos(int)
{
}

string Gestor::retornarTablero()
{
	string output = "         |     |     \n      "
		+ to_string(getTablero()->buscar(0)->getInfo()) 
		+ "  |  " + to_string(getTablero()->buscar(1)->getInfo())
		+ "  |  " + to_string(getTablero()->buscar(2)->getInfo()) + "\n"
		+ "    _____|_____|_____\n"
		+ "         |     |     \n"
		+ "      " + to_string(getTablero()->buscar(3)->getInfo())
		+ "  |  " + to_string(getTablero()->buscar(4)->getInfo())
		+ "  |  " + to_string(getTablero()->buscar(5)->getInfo()) + "\n"
		+ "    _____|_____|_____\n"
		+ "         |     |     \n"
		+ "      " + to_string(getTablero()->buscar(6)->getInfo())
		+ "  |  " + to_string(getTablero()->buscar(7)->getInfo())
		+ "  |  " 
		+ to_string(getTablero()->buscar(8)->getInfo()) + "\n"
		+ "         |     |     \n\n\n";

	output = replaceChar(output, '1', 'X');
	output = replaceChar(output, '2', 'O');
	output = replaceChar(output, '0', ' ');
	
	return output;
}

bool Gestor::verificarSiHayGanador()
{	
	if (getTablero()->buscar(0)->getInfo() != 0
		&& getTablero()->buscar(0)->getInfo() == getTablero()->buscar(1)->getInfo()
		&& getTablero()->buscar(1)->getInfo() == getTablero()->buscar(2)->getInfo()) {
		return true;
	}
	else if (getTablero()->buscar(3)->getInfo() != 0
		&& getTablero()->buscar(3)->getInfo() == getTablero()->buscar(4)->getInfo()
		&& getTablero()->buscar(4)->getInfo() == getTablero()->buscar(5)->getInfo()) {
		return true;
	}
	else if (getTablero()->buscar(6)->getInfo() != 0
		&& getTablero()->buscar(6)->getInfo() == getTablero()->buscar(7)->getInfo()
		&& getTablero()->buscar(7)->getInfo() == getTablero()->buscar(8)->getInfo()) {
		return true;
	}
	else if (getTablero()->buscar(0)->getInfo() != 0
		&& getTablero()->buscar(0)->getInfo() == getTablero()->buscar(3)->getInfo()
		&& getTablero()->buscar(3)->getInfo() == getTablero()->buscar(6)->getInfo()) {
		return true;
	}
	else if (getTablero()->buscar(1)->getInfo() != 0
		&& getTablero()->buscar(1)->getInfo() == getTablero()->buscar(4)->getInfo()
		&& getTablero()->buscar(4)->getInfo() == getTablero()->buscar(7)->getInfo()) {
		return true;
	}
	else if (getTablero()->buscar(2)->getInfo() != 0
		&& getTablero()->buscar(2)->getInfo() == getTablero()->buscar(5)->getInfo()
		&& getTablero()->buscar(5)->getInfo() == getTablero()->buscar(8)->getInfo()) {
		return true;
	}
	else if (getTablero()->buscar(0)->getInfo() != 0
		&& getTablero()->buscar(0)->getInfo() == getTablero()->buscar(4)->getInfo()
		&& getTablero()->buscar(4)->getInfo() == getTablero()->buscar(8)->getInfo()) {
		return true;
	}
	else if (getTablero()->buscar(2)->getInfo() != 0
		&& getTablero()->buscar(2)->getInfo() == getTablero()->buscar(4)->getInfo()
		&& getTablero()->buscar(4)->getInfo() == getTablero()->buscar(6)->getInfo()) {
		return true;
	}
	return false;
}

bool Gestor::verificarSiTableroEstaLleno()
{
	return getTablero()->estaLlena();
}

void Gestor::guardarSesion()
{
}

void Gestor::inicializarMarcador()
{
	for (int i = 0; i < getMarcador()->retornarLargo(); i++) {
		getMarcador()->insertarDatoEnIndice(i,0);
	}
}

string Gestor::replaceChar(string str, char ch1, char ch2) {
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == ch1)
			str[i] = ch2;
	}

	return str;
}

void Gestor::reiniciarTablero()
{
	getTablero()->vaciar();
}

bool Gestor::verificarSiCeldaEstaVacia(int indice)
{
	return getTablero()->buscar(indice - 1)->getInfo() == 0;
}
