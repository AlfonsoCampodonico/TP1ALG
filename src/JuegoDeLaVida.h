#pragma once
#ifndef JUEGO_DE_LA_VIDA_H_
#define JUEGO_DE_LA_VIDA_H_
#include  "InputTablero.h"
struct conteoCelulas
{
    int celulasVivasTurno{};
    int celulasMuertasTurno{};
    int celulasVivasTotal{};
    int celulasMuertasTotal{};
    int totalTurnos{};
};
void iniciarJuego();
void  determinarVida(Tablero tablero, conteoCelulas& celulas);
int contarCelulasVivas(Tablero tablero);

#endif // JUEGO_DE_LA_VIDA_H_ 
