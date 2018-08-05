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

void Menu::setNumeroJugador(int number)
{
	numeroJugador = number;
}

void Menu::setJugadorActual(string nombre)
{
	jugadorActual = nombre;
}

string Menu::getJugadorActual()
{
	return jugadorActual;
}

int Menu::getNumeroJugador()
{
	return numeroJugador;
}

void Menu::setMarca(char sign)
{
	marca = sign;
}

char Menu::getMarca()
{
	return marca;
}

void Menu::seleccionarJugadores()
{
	string nombre;
	cout << "Ingrese el nombre del primer jugador\n";
	getline(cin, nombre);
	setJugador1(nombre);

	cout << "Ingrese el nombre del segundo jugador\n";
	getline(cin, nombre);
	setJugador2(nombre);
	print("Bienvenid@s " + jugador1 + " y " + jugador2 + ".\n");
}

void Menu::empezarJuego()
{
	int option = 1;
	mostrarPuntaje();
	do {
		verEstadoActual();
		cambiarJugadorActual();
		print("Turno de "+getJugadorActual()+" ("+getMarca()+")\n");
		mostrarMenuDeJugadas();
		cin >> option;
		getGestor()->realizarMovimiento(option - 1, getNumeroJugador());
		if (gestor->verificarSiHayGanador()) {
			gestor->actualizarMarcador(getNumeroJugador()-1);
			verEstadoActual();
			print("\nFelicidades " + getJugadorActual() + ", has ganado!\n");
			option = continuar();
		}
		else if (gestor->verificarSiTableroEstaLleno()) {
			verEstadoActual();
			print("\nLa partida ha terminado en un empate\n");
			gestor->actualizarMarcador(2);
			option = continuar();
		}

	} while (option != 0);

	print("Gracias por jugar");
}

void Menu::mostrarPuntaje()
{
	print("| " + getJugador1() + " | " +getJugador2()+ " | Empates |\n" + getGestor()->retornarMarcador() +"\n");
}

void Menu::mostrarMenuDeJugadas()
{
	print("Elija su siguiente jugada\n1.Esquina Superior Izquierda\n2.Centro Superior\n3.Esquina Superior Derecha\n4.Centro Izquierda\n5.Centro\n6.Centro Derecha\n7.Esquina Inferior Izquierda\n8.Centro Inferior\n9.Esquina Inferior Derecha\n\n");
}

int Menu::continuar()
{
	int option;
	print("Desean jugar otra partida? 1. Si. 2. No\n");
	cin >> option;
	option = option - 2;
	getGestor()->reiniciarTablero();
	return option;
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
	if (getNumeroJugador() == 1) {
		setJugadorActual(getJugador2());
		setNumeroJugador(2);
		setMarca('O');
	}
	else {
		setJugadorActual(getJugador1());
		setNumeroJugador(1);
		setMarca('X');
	}
}

