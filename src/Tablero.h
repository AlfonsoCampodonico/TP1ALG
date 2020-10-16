#pragma once
#ifndef TABLERO_H_
#define TABLERO_H_
#include <iostream>
using std::endl;
#define  FILAS 20
#define   COLUMNAS 60
extern const char VIVA, MUERTA;

typedef  char Tablero[FILAS][COLUMNAS];

void inicializarTablero(Tablero tablero, char celulaMuerta);
/*Funcion que crea un arreglo bidimensional con longitud y ancho fijo y le asigno un valor de "muerta" a su contenido*/

void imprimirTablero(Tablero tablero);
/*Funcion que se encarga de imprimir por consola el estado actual del tablero*/

void crearTableroAnterior(Tablero tablero, Tablero tableroAnterior);
/*Funcion que se encarga de crear un arreglo bidimensional que se la copia exacta de otro*/

bool sonIgualesDosTableros(Tablero tablero, Tablero tableroAnterior);
/*Funcion que indica si dos arreglos bidimensionales son exactamente iguales
 *PRE: Recibe dos arreglos bidemensionales
 *POST: Devuelve un booleano*/

#endif // TABLERO_H_ 
