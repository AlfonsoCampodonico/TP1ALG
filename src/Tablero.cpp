#include "tablero.h"


void inicializarTablero(Tablero tablero, char celulaMuerta) {
	for (int fila = 0; fila < FILAS; fila++) {
		for (int columna = 0; columna < COLUMNAS; columna++) {
			tablero[fila][columna] = celulaMuerta;
		}
	}
}
void imprimirTablero(Tablero tablero) {
	for (int x = 0; x < FILAS; x++) {
		for (int y = 0; y < COLUMNAS; y++) {
			std::cout << tablero[x][y] << " ";
		}
		std::cout << endl;
	}
}

void crearTableroAnterior(Tablero tablero, Tablero tableroAnterior) {
	for (int a = 0; a < FILAS; a++) {
		for (int b = 0; b < COLUMNAS; b++) {
			tableroAnterior[a][b] = tablero[a][b];
		}
	}
}

bool sonIgualesDosTableros(Tablero tablero, Tablero tableroAnterior) {
	int contadorDesigualdad{};
	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLUMNAS; j++) {
			if (tablero[i][j] != tableroAnterior[i][j]) {
				contadorDesigualdad++;
			}
		}
	}
	bool sonIguales = (contadorDesigualdad == 0);
	return sonIguales;
}