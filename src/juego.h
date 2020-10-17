#pragma once
#ifndef JUEGO_H_
#define JUEGO_H_
#include  "inputTablero.h"

/*Structura para almacenar los datos referentes a las celulas que hay que mostrar por pantalla despues de cada turno*/
struct ConteoCelulas
{
	int celulasVivasTurno, celulasMuertasTurno, celulasVivasTotal, celulasMuertasTotal, totalTurnos;
};

/*Funcion que se encarga de iniciar el juego y toda la logica de turnos de este*/
void iniciarJuego();

/*Funcion que se encarga de determinar el proceso de vidas del juego, como se va expandiendo o contrayendo y la recopilacion
 * de datos de este
 */
void  determinarVida(Tablero tablero, ConteoCelulas& celulas);

/*Funcion que se encarga de revisar el tablero (arreglo bidimensional fijo) y determinar cuantas parelas tienen vida en un turno determinado
 * PRE: Arreglo bidemensional (tablero)
 * POST: Un entero que representa la cantidad de celulas vivas
 */
int contarCelulasVivas(Tablero tablero);

/*Funcion que se encarga de mostrar por consola la carga inicial
 * PRE: Arreglo bidemensional (tablero) y un entero al cual se le va a asignar la cantidad de celulas vivas.
 * POST: Devuelve un booleano dependiendo si quiere terminar o no el turnos
 */
bool pantallaInicial(Tablero tablero, int& celulasVivas);

/*Funcion que se encarga de pedir el input de continuar con el turno, resetear el juego o terminarlo*/
void pedirInput(int& inputUsuarioJuego, bool& sigueTurno, bool& inicioJuego);

#endif // JUEGO_H_
