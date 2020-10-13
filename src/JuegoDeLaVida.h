#pragma once
#ifndef JUEGO_DE_LA_VIDA_H_
#define JUEGO_DE_LA_VIDA_H_
#include  "InputTablero.h"
struct ConteoCelulas
{
    int celulasVivasTurno, celulasMuertasTurno, celulasVivasTotal, celulasMuertasTotal, totalTurnos;
};
void iniciarJuego();
/*Funcion que se encarga de iniciar el juego y toda la logica de turnos de este*/
void  determinarVida(Tablero tablero, ConteoCelulas& celulas);
/*Funcion que se encarga de determinar el proceso de vidas del juego, como se va expandiendo o contrayendo y la recopilacion
 * de datos de este
 */
int contarCelulasVivas(Tablero tablero);
/*Funcion que se encarga de revisar el tablero (arreglo bidimensional fijo) y determinar cuantas parelas tienen vida en un turno determinado
 * PRE: Arreglo bidemensional (tablero)
 * POST: Un entero que representa la cantidad de celulas vivas
 */
bool pantallaInicial(Tablero tablero, int& celulasVivas);
/*Funcion que se encarga de mostrar por consola la carga inicial*/
void pedirInput(int& inputUsuarioJuego, bool& sigueTurno, bool& inicioJuego);
/*Funcion que se encarga de pedir el input de continuar con el turno, resetear el juego o terminarlo*/
#endif // JUEGO_DE_LA_VIDA_H_ 
