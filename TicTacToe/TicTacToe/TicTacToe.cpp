// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include "Gestor.h"

int main()
{
	char op;
	int cont = 0;
	bool continuar = true;

	string nombre;
	string apellido;
	string direccion;
	int telefono;


	do {
		cout << "1. Agregar al directorio\n2. Ver directorio\n3. Salir\nOpcion: \n";
		op = cin.get();


		if (op == '1') {

			//system("cls");

			cout << "Ingrese el nombre\n";
			getline(cin, nombre);
			cout << "Ingrese el apellido\n";
			getline(cin, apellido);
			cout << "Ingrese la direccion\n";
			getline(cin, direccion);
			cout << "Ingrese el telefono\n";

			while (!(cin >> telefono)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Ingresar solo numeros. Intentelo de nuevo ";
			}

			Directorio dir(nombre, apellido, direccion, telefono);

			historial[cont] = dir;
			cont++;
		}

		if (op == '2') {

			for (int x = 0; x < LENGTH; x++) {
				if (historial[x].getTelefono() != -1) {
					cout << "Nombre: " << historial[x].getNombre() << ". Apellido: " << historial[x].getApellido() << ". Direccion: " << historial[x].getDireccion() << ". Telefono: " << historial[x].getTelefono() << ".\n";
				}
			}
		}



		if (op == '3') {
			continuar = false;
		}

		if (op != '1' && op != '2' && op != '3' && op != 3) {
			cout << "Opcion invalida.\n";
		}

		cout << "Presione cualquier tecla para continuar\n";
		cin.get();
		cin.get();
		system("cls");

	} while (continuar == true);

	cout << "Gracias por utilizar el programa";



	return 0;
}

