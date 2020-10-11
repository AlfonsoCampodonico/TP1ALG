#include "JuegoDeLaVida.h"

int contarCelulasVivas(Tablero tablero) {
    int contador = 0;
    for (int fila = 0; fila < FILAS; fila++) {

        for (int columna = 0; columna < COLUMNAS; columna++) {

            if (tablero[fila][columna] == VIVA) {
                contador++;
            }
        }
    }
    return contador;
}



void  determinarVida(Tablero tablero, conteoCelulas& celulas) {
    Tablero tableroAnterior{};
    crearTableroAnterior(tablero, tableroAnterior);
    celulas.celulasMuertasTurno = 0;
    celulas.celulasVivasTurno = 0;
    celulas.totalTurnos++;
    for (int a = 0; a < FILAS; a++)
    {
        for (int b = 0; b < COLUMNAS; b++)
        {
            int estaVivo = 0;
            for (int c = -1; c <= 1; c++)
            {
                for (int d = -1; d <= 1; d++)
                {
                    if (!(c == 0 && d == 0) && (FILAS > (a + c) >= 0 && COLUMNAS > (b + d) >= 0) && (tableroAnterior[a + c][b + d] == VIVA))
                    {
                        ++estaVivo;
                    }
                }
            }
            if ((estaVivo < 2) && (tablero[a][b] != MUERTA))
            {

                tablero[a][b] = MUERTA;
                celulas.celulasMuertasTurno++;
                celulas.celulasMuertasTotal++;

            }
            else if (estaVivo == 3 && (tablero[a][b] != VIVA))
            {
                tablero[a][b] = VIVA;
                celulas.celulasVivasTurno++;
                celulas.celulasVivasTotal++;
            }
            else if (estaVivo > 3 && (tablero[a][b] != MUERTA))
            {
                tablero[a][b] = MUERTA;
                celulas.celulasMuertasTurno++;
                celulas.celulasMuertasTotal++;

            }
        }
    }



}
void iniciarJuego()
{
    Tablero tablero;
    conteoCelulas celulas;
    Tablero tableroUnoAtras;
    Tablero tableroDosAtras;

    char calculateagain = 'y';
    do
    {
        inicializarTablero(tablero, MUERTA);
        std::cout << "Bienvenido al Juego de la vida 1.0!" << endl;
        estadoCelulasInicial(tablero);
        imprimirTablero(tablero);
        int celulasVivas = contarCelulasVivas(tablero);
        std::cout << "Existen " << celulasVivas << " vivas al comenzar el juego" << endl;
        char a = 'y';

        do
        {
            determinarVida(tablero, celulas);
            imprimirTablero(tablero);
            celulasVivas = contarCelulasVivas(tablero);
            crearTableroAnterior(tableroUnoAtras, tableroDosAtras);
            crearTableroAnterior(tablero, tableroUnoAtras);
            std::cout << "Existen " << celulasVivas << " vivas actualmente" << endl;
            std::cout << "Nacieron " << celulas.celulasVivasTurno << " en el ultimo turno" << endl;
            std::cout << "Murieron " << celulas.celulasMuertasTurno << " en el ultimo turno" << endl;
            std::cout << "En promedio han nacido " << celulas.celulasVivasTotal / celulas.totalTurnos << " celulas en el transcurso del juego" << endl;
            std::cout << "En promedio han muerto " << celulas.celulasMuertasTotal / celulas.totalTurnos << " celulas en el transcurso del juego" << endl;
            if (sonIgualesDosTableros(tableroDosAtras, tableroUnoAtras) && sonIgualesDosTableros(tablero, tableroUnoAtras))
            {
                std::cout << "Se freezo el juego" << endl;
            }
            std::cout << "Quiere continuar jugando (y/n) ";
            std::cin >> a;
        } while (a != 'n');
        std::cout << "Quiere resetear o terminar el juego (y/n) ";
        std::cin >> calculateagain;
    } while (calculateagain != 'n');

}