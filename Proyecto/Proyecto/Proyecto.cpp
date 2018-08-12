#include "stdafx.h"
#include "ListaJugadas.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string nombreJugador;
	char op;
	ListaJugadas *jugada = new ListaJugadas;
	do {
		cout <<"---------------------------------\n"
			"1. Agregar una jugada"
			"\n2.Ver jugadas \n"
			"-----------------------------------\n";
		op = cin.get();
		cin.get();
		switch (op) {
		case '1':
			
			cout << "Introduzca el nombre del jugador:" << endl;
			getline(cin, nombreJugador);
			int casilla;
			cout << "Introduzca la jugada:" << endl;
			cin >> casilla;
			cin.get();
			jugada->pushJugada(nombreJugador, casilla);
			break;

		case '2':
			cout << jugada->finalCola() << endl;
			break;
		default:
			cout << "Opcion invalida\n";
			break;
		}
	} while (op != '0');
	return 0;
}


