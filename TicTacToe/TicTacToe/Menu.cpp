#include "Menu.h"

Menu::Menu() {
	setGestor(new Gestor());
}

Menu::~Menu() {
}

void Menu::setGestor(Gestor* newGestor)
{
	gestor = newGestor;
}

Gestor* Menu::getGestor()
{
	return gestor;
}

void Menu::setJugador1(string nombre)
{
	jugador1 = nombre;
}

string Menu::getJugador1()
{
	return jugador1;
}

void Menu::setJugador2(string nombre)
{
	jugador2 = nombre;
}

string Menu::getJugador2()
{
	return jugador2;
}

void Menu::seleccionarJugadores()
{
	string nombre;
	cout << "Ingrese el nombre del primer jugador\n";
	getline(cin, nombre);
	setJugador1(nombre);

	cout << "Ingrese el nombre del segundo jugador\n";
	getline(cin, nombre);
	setJugador1(nombre);
}

void Menu::empezarJuego(string)
{
	int option = 0;
	seleccionarJugadores();
	print("Bienvenid@s " + jugador1 + " y " + jugador2 + ".");

	do {
		mostrarPuntaje();
		verEstadoActual();

	} while (option != 0);

}

void Menu::mostrarPuntaje()
{
	print("| " + getJugador2() + " | Empates | "+getJugador1()+" 2\n" + getGestor()->retornarMarcador());
}

void Menu::print(string msg)
{
	cout << msg;
}

void Menu::verEstadoActual()
{
	print(getGestor()->retornarTablero());
}

void Menu::cambiarJugadorActual()
{
	switch (jugadorActual) {
	case 1:
		jugadorActual = 2;
		break;

	case 2:
		jugadorActual = 1;
		break;
	}
}

