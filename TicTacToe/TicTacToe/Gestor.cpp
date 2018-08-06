#include "Gestor.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>

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

int Gestor::retornarIndiceMarcador(int index)
{
	return getMarcador()->buscar(index)->getInfo();
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
	string output = "             █     █     \n          "
		+ to_string(getTablero()->buscar(0)->getInfo()) 
		+ "  █  " + to_string(getTablero()->buscar(1)->getInfo())
		+ "  █  " + to_string(getTablero()->buscar(2)->getInfo()) + "\n"
		+ "        _____█_____█_____\n"
		+ "             █     █     \n"
		+ "          " + to_string(getTablero()->buscar(3)->getInfo())
		+ "  █  " + to_string(getTablero()->buscar(4)->getInfo())
		+ "  █  " + to_string(getTablero()->buscar(5)->getInfo()) + "\n"
		+ "        _____█_____█_____\n"
		+ "             █     █     \n"
		+ "          " + to_string(getTablero()->buscar(6)->getInfo())
		+ "  █  " + to_string(getTablero()->buscar(7)->getInfo())
		+ "  █  " 
		+ to_string(getTablero()->buscar(8)->getInfo()) + "\n"
		+ "             █     █     \n\n\n";

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

void Gestor::actualizarRecords(string jugador1, string jugador2)
{
	string contenido = "";
	string linea;
	int nuevoNumero;
	ifstream myfile("Records.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, linea))
		{
			if (contenido != "") {
				contenido = contenido + "\n" + linea;
			}
			else {
				contenido = linea;
			}
		}
		myfile.close();
	}

	else cout << "Unable to open file";

	if (remove("Records.txt") != 0) {
		perror("Error deleting file");
	}
	else {
	puts("File successfully deleted");
	}

	if (!reemplazarRecord(contenido, jugador1, retornarIndiceMarcador(0))){
		contenido = contenido + "\n" + jugador1 + " [" + to_string(retornarIndiceMarcador(0)) + "]";
	}
	
	if (!reemplazarRecord(contenido, jugador2, retornarIndiceMarcador(1))) {
		contenido = contenido + "\n" + jugador2 + " [" + to_string(retornarIndiceMarcador(1)) + "]";
	}

	ofstream ofile("Records.txt");
	if (ofile.is_open())
	{
		ofile << contenido;
		ofile.close();
	}
	else cout << "Unable to open file";
}

bool Gestor::reemplazarRecord(string &contenido, string &jugador, int cantidadGanadas)
{
	int nuevoValor;
	int posicionUltimoDigito;
	string antiguoValorString = "";
	size_t found = contenido.find(jugador);
	size_t brFound = contenido.find_first_of("]", found);
	if (found != std::string::npos) {
		for (int i = found; i < brFound; ++i) {
			if (isdigit(contenido[i])) {
				antiguoValorString = antiguoValorString + contenido[i];
				posicionUltimoDigito = i;
			}
		}

		nuevoValor = stoi(antiguoValorString) + cantidadGanadas;
		contenido.replace(found, posicionUltimoDigito-found+2, jugador + " [" + to_string(nuevoValor) + "]");
		return true;
	}
	
	return false;

}

void Gestor::reiniciarTablero()
{
	getTablero()->vaciar();
}

bool Gestor::verificarSiCeldaEstaVacia(int indice)
{
	return getTablero()->buscar(indice - 1)->getInfo() == 0;
}
