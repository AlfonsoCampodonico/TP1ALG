#include "InputTablero.h"

bool estadoCelulasInicial(Tablero tablero) {
	char continuoAgregando{}, comienzoJuego{};
	std::cout << "Para comenzar el juego tiene que agregar  celulas vivas" << endl;
	std::cout << "Quiere empezar a agregar? (S/N)" << endl;
	std::cin >> comienzoJuego;
	bool comenzoElJuego = (std::cin && ::tolower(comienzoJuego) == 's');
	if (comenzoElJuego){
		continuoAgregando = comienzoJuego;
	}
	while (std::cin && ::tolower(continuoAgregando) == 's') {
		int fila = validarInputUsuario(FILAS);
		int columna = validarInputUsuario(COLUMNAS);
		tablero[fila - 1][columna - 1] = VIVA;
		std::cout << "Continua Agregando? (S/N): ";
		std::cin >> continuoAgregando;
	}
	return comenzoElJuego;
}
int validarInputUsuario(int input) {
	int inputUsuario;
	do{
		if (input == FILAS){
			std::cout << "Introduzca un valor para la fila : ";
		}
		else{
			std::cout << "Introduzca un valor para la columna : ";
		}
		std::cin >> inputUsuario;
		while (std::cin.fail()){
			std::cout << "Error NO es un numero, Por favor agregar un numero:";
			std::cin.clear(); std::cin.ignore();
			std::cin >> inputUsuario;
		}
		if (inputUsuario < 1){
			std::cout << "Tiene que ser mayor a 1 el valor" << endl;
		}
		if (inputUsuario > input){
			std::cout << "Tiene que ser menor a  " << input << " el valor" << endl;
		}
	} while (inputUsuario < 1 || inputUsuario > input);
	return inputUsuario;
}