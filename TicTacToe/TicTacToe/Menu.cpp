#include "Menu.h"
#include <algorithm>
#include <string> 
#include <cctype>

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
	std::transform(nombre.begin(), nombre.end(), nombre.begin(), ::tolower);
	nombre[0] = toupper(nombre[0]);
	jugador1 = nombre;
}

string Menu::getJugador1()
{
	return jugador1;
}

void Menu::setJugador2(string nombre)
{
	std::transform(nombre.begin(), nombre.end(), nombre.begin(), ::tolower);
	nombre[0] = toupper(nombre[0]);
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


void Menu::verMenuDeIncio()
{
	print("Ha iniciado Tic Tac Toe. Que desea hacer?\n1.Jugar\n2.Ver Records Historicos\n");
	int opcion = leerOpcion(2);
	if (opcion == 2) {
		print("\n" + getGestor()->readRecordsFile());
		print("\n\nQue desea hacer?\n1.Jugar\n2.Salir\n");
		opcion = leerOpcion(2);
		if (opcion == 2) {
			exit(0);
		}
	}
}

void Menu::seleccionarJugadores()
{
	string nombre;
	cout << "\nIngrese el nombre del primer jugador\n";
	getline(cin, nombre);
	setJugador1(nombre);

	cout << "Ingrese el nombre del segundo jugador\n";
	getline(cin, nombre);
	setJugador2(nombre);
	print("\nBienvenid@s " + getJugador1() + " y " + getJugador2() + ".\n");
}

void Menu::empezarPartida()
{
	int option = 1;
	do {
		mostrarMarcador();
		verEstadoActual(true);
		cambiarJugadorActual();
		print("Turno de "+getJugadorActual()+" ("+getMarca()+")\n");
		mostrarMenuDeJugadas();
		efectuarMovimiento();
		if (gestor->verificarSiHayGanador()) {
			gestor->actualizarMarcador(getNumeroJugador());
			print("\nFelicidades " + getJugadorActual() + ", has ganado!\n");
			mostrarMarcador();
			mostrarMovimientosAnteriores();
			option = continuar();
		}
		else if (gestor->verificarSiTableroEstaLleno()) {
			gestor->actualizarMarcador(3);
			print("\nLa partida ha terminado en un empate\n");
			mostrarMarcador();
			mostrarMovimientosAnteriores();
			option = continuar();
		}
	} while (option != 0);

	getGestor()->actualizarRecords(getJugador1(), getJugador2());
}

void Menu::start()
{
	int option = 1;
	do {
		verMenuDeIncio();
		seleccionarJugadores();
		empezarPartida();

		print("\nDesean jugar otra partida? 1. Si. 2. No\n");
		option = leerOpcion(2) - 2;
		setGestor(new Gestor());
	} while (option != 0);
	print("\nGracias por jugar\n");
	cin.get();
}

void Menu::mostrarMarcador()
{
	print("\n| " + getJugador1() + ": "+ to_string(getGestor()->retornarIndiceMarcador(0)) +" | " +getJugador2() + ": " + to_string(getGestor()->retornarIndiceMarcador(1))+ " | Empates: " + to_string(getGestor()->retornarIndiceMarcador(2))+ " |\n\n");
}

void Menu::mostrarMenuDeJugadas()
{
	print("Elija su siguiente jugada\n1.Esquina Superior Izquierda\n2.Centro Superior\n3.Esquina Superior Derecha\n4.Centro Izquierda\n5.Centro\n6.Centro Derecha\n7.Esquina Inferior Izquierda\n8.Centro Inferior\n9.Esquina Inferior Derecha\n\n");
}

int Menu::continuar()
{
	int option;
	print("\nDesean repetir partida? 1. Si. 2. No\n");
	option = leerOpcion(2) - 2;
	getGestor()->reiniciarTablero();
	return option;
}

void Menu::efectuarMovimiento()
{	
	int option = leerOpcion(9);
	if (getGestor()->verificarSiCeldaEstaVacia(option)) {
		getGestor()->realizarMovimiento(option, getNumeroJugador());
	}
	else {
		print("La celda elegida ya se encuentra llena. Por favor elija otra.\n");
		efectuarMovimiento();
	}
}

int Menu::leerOpcion(int max)
{
	int opcion, cont = 0;
	bool continuar;

	do {
		continuar = false;
		cin.clear();
		if (cont > 0) cin.ignore(1024, '\n');
		cin >> opcion;
		cont++;
		if (cin.fail() && cin.rdstate()) {
			print("La opcion selecionada no es numeral. Intente de nuevo.\n");
			continuar = true;
		}
		if (opcion == 0 || opcion > max) {
			print("La opcion selecionada no esta dentro de las mostradas. Intente de nuevo.\n");
			continuar = true;
		}
	} while (continuar);
	cin.get();

	return opcion;
}

void Menu::mostrarMovimientosAnteriores()
{
	int opcion;
	verEstadoActual(false);
	do {
		print("\nVer movimiento anterior? 1. Si. 2. No\n");
		opcion = leerOpcion(2) - 2;
		if (opcion != 0) {
			print(getGestor()->mostrarMovimientoPrevio());
		}
	} while (opcion != 0);
	getGestor()->reiniciarPila();
}

void Menu::print(string msg)
{
	cout << msg;
}

void Menu::verEstadoActual(bool save)
{
	string output = getGestor()->retornarTablero();
	if (save) {
		getGestor()->guardarMovimiento(output);
	}
	print(output);
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

