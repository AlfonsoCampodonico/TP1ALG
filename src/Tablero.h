#pragma once
#ifndef TABLERO_H_
#define TABLERO_H_
#include <iostream>
#define  FILAS 20
#define   COLUMNAS 60
#define VIVA '#'
#define MUERTA  '.'
using std::endl;

typedef  char Tablero[FILAS][COLUMNAS];

/*Funcion que crea un arreglo bidimensional con longitud y ancho fijo y le asigno un valor de "muerta" a su contenido*/
void inicializarTablero(Tablero tablero, char celulaMuerta);

/*Funcion que se encarga de imprimir por consola el estado actual del tablero*/
void imprimirTablero(Tablero tablero);

/*Funcion que se encarga de crear un arreglo bidimensional que se la copia exacta de otro*/
void crearTableroAnterior(Tablero tablero, Tablero tableroAnterior);

/*Funcion que indica si dos arreglos bidimensionales son exactamente iguales
 *PRE: Recibe dos arreglos bidemensionales
 *POST: Devuelve un booleano*/
bool sonIgualesDosTableros(Tablero tablero, Tablero tableroAnterior);

#endif // TABLERO_H_
