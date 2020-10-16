#pragma once
#ifndef INPUT_TABLERO_H_
#define INPUT_TABLERO_H_
#include  "Tablero.h"

bool estadoCelulasInicial(Tablero tablero);
/*Funcion que se encarga del llenado inicial del tablero de la funcion,
 *se le pregunta al usuario las posiciones donde quiere alojar las celulas vivas en el tablero
 * PRE: Recibe un arreglo bidemensional de longitud fija
 * POST: Devuelve un booleano
 */

int validarInputUsuario(int input);
/*Funcion que se encarga de validar el dato de entrada del usuario, asegurandose que sea numerico,
 *para el correcto funcionamiento del juego, devuelve un int con la posicion en el tablero.
 * PRE: Recibe un int
 * POST: Devuelve un int validado
 */
#endif // INPUT_TABLERO_H_ 
