#pragma once
#ifndef TABLERO_H_
#define TABLERO_H_
#include <iostream>
using namespace std;
const int FILAS = 20;
const int COLUMNAS = 80;
const char VIVA = '#';
const char MUERTA = '.';
typedef  char Tablero[FILAS][COLUMNAS];
void inicializarTablero(Tablero tablero, char celulaMuerta);
void imprimirTablero(Tablero tablero);
void crearTableroAnterior(Tablero tablero, Tablero tableroAnterior);
bool sonIgualesDosTableros(Tablero tablero, Tablero tableroAnterior);
#endif // TABLERO_H_ 
