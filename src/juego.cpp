#include "juego.h"

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

void  determinarVida(Tablero tablero, ConteoCelulas& celulas) {
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
					bool  estaEnElBorde = (FILAS > (a + c) >= 0) && (COLUMNAS > (b + d) >= 0);
					/*Si uno de los dos pivotes (c y d) es diferente de 0, y la suma de la posicion del array
					 *para a y para b es mayor o igual que cero*/
					if ((c != 0 || d != 0) && estaEnElBorde && (tableroAnterior[a + c][b + d] == VIVA))
					{
						estaVivo++;
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
	ConteoCelulas celulas;
	celulas.celulasVivasTotal = 0, celulas.celulasMuertasTotal = 0, celulas.totalTurnos = 0;
	Tablero tablero, tableroUnoAtras, tableroDosAtras;
	bool  inicioJuego = true, sigueTurno = false;
	int celulasVivas{}, inputUsuarioJuego{};
	double promedioVivas{}, promedioMuertas{};
	do
	{
		inicioJuego = pantallaInicial(tablero, celulasVivas);
		if (inicioJuego)
		{
			pedirInput(inputUsuarioJuego, sigueTurno, inicioJuego);
		}

		if (sigueTurno)
		{
			do
			{
				determinarVida(tablero, celulas);
				imprimirTablero(tablero);
				celulasVivas = contarCelulasVivas(tablero);
				crearTableroAnterior(tableroUnoAtras, tableroDosAtras);
				crearTableroAnterior(tablero, tableroUnoAtras);
				promedioMuertas = celulas.celulasMuertasTotal / celulas.totalTurnos;
				promedioVivas = celulas.celulasVivasTotal / celulas.totalTurnos;
				std::cout << "Existen " << celulasVivas << " vivas actualmente" << endl;
				std::cout << "Nacieron " << celulas.celulasVivasTurno << " en el ultimo turno" << endl;
				std::cout << "Murieron " << celulas.celulasMuertasTurno << " en el ultimo turno" << endl;
				std::cout << "En promedio han nacido " << promedioVivas << " celulas en el transcurso del juego" << endl;
				std::cout << "En promedio han muerto " << promedioMuertas << " celulas en el transcurso del juego" << endl;
				if (sonIgualesDosTableros(tableroDosAtras, tableroUnoAtras) && sonIgualesDosTableros(tablero, tableroUnoAtras))
				{
					std::cout << "El juego se congelo, no van a seguir naciendo o muriendo celulas!" << endl;
				}
				pedirInput(inputUsuarioJuego, sigueTurno, inicioJuego);
			} while (sigueTurno);
		}
	} while (inicioJuego);
}
bool pantallaInicial(Tablero tablero, int& celulasVivas)
{
	inicializarTablero(tablero, MUERTA);
	std::cout << "Bienvenido al Juego de la vida 1.0!" << endl;
	bool comienzaJuego = estadoCelulasInicial(tablero);
	if (comienzaJuego)
	{
		imprimirTablero(tablero);
		celulasVivas = contarCelulasVivas(tablero);
		std::cout << "Existen " << celulasVivas << " vivas al comenzar el juego" << endl;
	}
	return  comienzaJuego;
}
void pedirInput(int& inputUsuarioJuego, bool& sigueTurno, bool& inicioJuego)
{
	std::cout << "Quiere ir al siguiente turno  (1) , resetear la partida (2) o terminar (3)" << endl;
	std::cin >> inputUsuarioJuego;
	switch (inputUsuarioJuego) {
	case 1:
		sigueTurno = true;
		break;
	case 2:
		sigueTurno = false;
		break;
	case 3:
		inicioJuego = false;
		sigueTurno = false;
		break;
	default:
		std::cout << "No es una opcion, se comienza el juego";
		sigueTurno = true;
		break;
	}
}