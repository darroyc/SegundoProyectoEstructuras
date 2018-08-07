#ifndef Gestor_h
#define Gestor_h

#include <iostream>
#include <string>

#include "ColaDePrioridad.h"
#include "TxtWriter.h"

using namespace std;

class Gestor {
public:
	// default constructor
	Gestor();

	// destructor
	~Gestor();

	// accessor functions
	void actualizarMarcador(int);
	int retornarIndiceMarcador(int);
	void realizarMovimiento(int, int);
	void mostrarMovimientos(int);
	string retornarTablero();
	bool verificarSiHayGanador();
	bool verificarSiTableroEstaLleno();
	void reiniciarTablero();
	bool verificarSiCeldaEstaVacia(int);
	void actualizarRecords(string, string);
	string readRecordsFile();

private:
	// variable del miembro
	ColaDePrioridad * getTablero();
	ColaDePrioridad* getMarcador();
	TxtWriter* getTxtWriter();
	void setMarcador(ColaDePrioridad*);
	void setTablero(ColaDePrioridad*);
	void setTxtWriter(TxtWriter*);
	ColaDePrioridad* tablero;
	ColaDePrioridad* marcador;
	TxtWriter* txtWriter;
	void guardarSesion();
	void inicializarMarcador();
	string replaceChar(string str, char ch1, char ch2);
	bool reemplazarRecord(string&, string&, int);
};

#endif Gestor_h
