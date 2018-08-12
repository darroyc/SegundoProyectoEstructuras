#include "Gestor.h"

Gestor::Gestor() {
	setTablero(new ColaDePrioridad(9));
	setMarcador(new ColaDePrioridad(3));
	setTxtWriter(new TxtWriter("Records.txt"));
	inicializarMarcador();
	setPartida(new PilaPartida());
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

TxtWriter * Gestor::getTxtWriter()
{
	return txtWriter;
}

void Gestor::setMarcador(ColaDePrioridad* colaDePrioridad)
{
	marcador = colaDePrioridad;
}

void Gestor::setTablero(ColaDePrioridad* colaDePrioridad)
{
	tablero = colaDePrioridad;
}

void Gestor::setPartida(PilaPartida* pilaPartida)
{
	partida = pilaPartida;
}

PilaPartida * Gestor::getPartida()
{
	return partida;
}

void Gestor::setTxtWriter(TxtWriter * newTxtWriter)
{
	txtWriter = newTxtWriter;
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

string Gestor::mostrarMovimientoPrevio()
{
	string output = getPartida()->pop();
	if (output == "") {
		return "\nNo hay jugadas previas.";
	}
	return output;
}

string Gestor::retornarTablero()
{
	string output = "             |     |     \n          "
		+ to_string(getTablero()->buscar(0)->getInfo()) 
		+ "  |  " + to_string(getTablero()->buscar(1)->getInfo())
		+ "  |  " + to_string(getTablero()->buscar(2)->getInfo()) + "\n"
		+ "        _____|_____|_____\n"
		+ "             |     |     \n"
		+ "          " + to_string(getTablero()->buscar(3)->getInfo())
		+ "  |  " + to_string(getTablero()->buscar(4)->getInfo())
		+ "  |  " + to_string(getTablero()->buscar(5)->getInfo()) + "\n"
		+ "        _____|_____|_____\n"
		+ "             |     |     \n"
		+ "          " + to_string(getTablero()->buscar(6)->getInfo())
		+ "  |  " + to_string(getTablero()->buscar(7)->getInfo())
		+ "  |  " 
		+ to_string(getTablero()->buscar(8)->getInfo()) + "\n"
		+ "             |     |     \n\n\n";

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

void Gestor::guardarMovimiento(string output)
{
	getPartida()->push(output);
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
	string contenido = readRecordsFile();
	getTxtWriter()->deleteFile();

	if (contenido == "") {
		contenido = "Partidas ganadas por jugador\n";
	}

	if (!reemplazarRecord(contenido, jugador1, retornarIndiceMarcador(0))){
		contenido = contenido + "\n" + jugador1 + " [" + to_string(retornarIndiceMarcador(0)) + "]";
	}
	
	if (!reemplazarRecord(contenido, jugador2, retornarIndiceMarcador(1))) {
		contenido = contenido + "\n" + jugador2 + " [" + to_string(retornarIndiceMarcador(1)) + "]";
	}

	getTxtWriter()->writeFile(contenido);
}

string Gestor::readRecordsFile()
{
	return getTxtWriter()->readFile();
}

void Gestor::reiniciarPila()
{
	setPartida(new PilaPartida());
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
