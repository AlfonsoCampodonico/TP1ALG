#include <iostream>
#define FILAS    20
#define COLUMNAS 80
using std::endl;

typedef  char Tablero[FILAS][COLUMNAS];
void inicializarTablero(Tablero tablero, char celulaMuerta);
void imprimirTablero(Tablero tablero);
void estadoCelulasInicial(Tablero tablero);
int validarFila();
int validarColumna();
int contarCelulasVivas(Tablero tablero);
void determinarVida(Tablero tablero);
void crearTableroAnterior(Tablero tablero, char tableroAnterior[FILAS][COLUMNAS]);
void iniciarJuego();
bool sonIguales(Tablero tablero, Tablero tableroAnterior);

struct conteoCelulas
{
    int celulasVivasTurno{};
    int celulasMuertasTurno{};
    int celulasVivasTotal{};
    int celulasMuertasTotal{};
    int totalTurnos{};
};

int main() {
    iniciarJuego();
    return 0;
}

void imprimirTablero(Tablero tablero) {

    for (int x = 0; x < FILAS; x++) {

        for (int y = 0; y < COLUMNAS; y++) {

            std::cout << tablero[x][y] << " ";
        }

        std::cout << endl;
    }
}
void inicializarTablero(Tablero tablero, char celulaMuerta) {

    for (int fila = 0; fila < FILAS; fila++) {

        for (int columna = 0; columna < COLUMNAS; columna++) {

            tablero[fila][columna] = celulaMuerta;
        }
    }
}

void estadoCelulasInicial(Tablero tablero){
    int fila{};
    int columna{};
    char continuoAgregando{};
    std::cout << "Para comenzar el juego tiene que agregar  celulas vivas" << endl;
    std::cout << "Quiere empezar a agregar? (Y/N)" << endl;
    std::cin >> continuoAgregando;
    while (std::cin && ::tolower(continuoAgregando) == 'y') {
        fila = validarFila();
        columna = validarColumna();

        tablero[fila - 1][columna - 1] = '1';
        std::cout << "Continua Agregando? (Y/N): ";
        std::cin >> continuoAgregando;
    }
         
}
int validarFila() {
    int inputUsuario;
    do 
    {
        std::cout << "Introduzca un valor para la fila : ";
        std::cin >> inputUsuario;
        while (std::cin.fail()) 
        {

            std::cout << "Error NO es un numero" << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> inputUsuario;
        }
        if (inputUsuario < 1)
        {
            std::cout << "Tiene que ser mayor a 1 el valor\n";
        }

        if (inputUsuario > FILAS)
        {
            std::cout << "Tiene que ser menor a 20 el valor\n";
        }

    } while (inputUsuario < 1 || inputUsuario > FILAS);


    return inputUsuario;

}

int validarColumna() {
    int inputUsuario{};
    do
    {
        std::cout << "Introduzca un valor para la columna : ";
        std::cin >> inputUsuario;
        while (std::cin.fail())
        {

            std::cout << "Error NO es un numero" << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> inputUsuario;
        }
        if (inputUsuario < 1)
        {
            std::cout << "Tiene que ser mayor a 1 el valor\n";
        }

        if (inputUsuario > COLUMNAS)
        {
            std::cout << "Tiene que ser menor a 80 el valor\n";
        }

    } while (inputUsuario < 1 || inputUsuario > COLUMNAS);


    return inputUsuario;
}

int contarCelulasVivas(Tablero tablero) {
    int contador = 0;
    for (int fila = 0; fila < FILAS; fila++) {
        
        for (int columna = 0; columna < COLUMNAS; columna++) {

            if (tablero[fila][columna] == '1') {
                contador++;
            }
        }
    }
    return contador;
}

void crearTableroAnterior(Tablero tablero, Tablero tableroAnterior) {
    for (int a = 0; a < FILAS; a++)
    {
        for (int b = 0; b < COLUMNAS; b++)
        {
            tableroAnterior[a][b] = tablero[a][b];
        }
    }
	
}


void  determinarVida(Tablero tablero, conteoCelulas &celulas) {
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
                    if (!(c == 0 && d == 0) &&(FILAS> (a + c) >= 0 &&  COLUMNAS>(b+d) >= 0 ) && (tableroAnterior[a + c][b + d] == '1')  )
                    {
	                    ++estaVivo;
                    }
                }
            }
            if ((estaVivo < 2) && (tablero[a][b] != '0'))
            {
               
                    tablero[a][b] = '0';
                    celulas.celulasMuertasTurno++;
                    celulas.celulasMuertasTotal++;
                
            }
            else if (estaVivo == 3 && (tablero[a][b] != '1'))
            {
                tablero[a][b] = '1';
                celulas.celulasVivasTurno++;
                celulas.celulasVivasTotal++;
            }
            else if (estaVivo > 3 && (tablero[a][b] != '0'))
            {
                tablero[a][b] = '0';
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
        inicializarTablero(tablero, '0');
        std::cout << "Bienvenido al Juego de la vida 1.0!" << endl;
        estadoCelulasInicial(tablero);
        imprimirTablero(tablero);
        int celulasVivas = contarCelulasVivas(tablero);
        std::cout << "Existen " << celulasVivas << " vivas al comenzar el juego" << endl;
        char a = 'y';
    	
        do
        {
            determinarVida(tablero,celulas);
            imprimirTablero(tablero);
            celulasVivas = contarCelulasVivas(tablero);
            crearTableroAnterior(tableroUnoAtras, tableroDosAtras);
            crearTableroAnterior(tablero, tableroUnoAtras);
            std::cout << "Existen " << celulasVivas << " vivas actualmente" << endl;
            std::cout << "Nacieron " << celulas.celulasVivasTurno << " en el ultimo turno" << endl;
            std::cout << "Murieron " << celulas.celulasMuertasTurno << " en el ultimo turno" << endl;
            std::cout << "En promedio han nacido " << celulas.celulasVivasTotal / celulas.totalTurnos << " celulas en el transcurso del juego" << endl;
            std::cout << "En promedio han muerto " << celulas.celulasMuertasTotal / celulas.totalTurnos << " celulas en el transcurso del juego" << endl;
            if (sonIguales(tableroDosAtras, tableroUnoAtras) && sonIguales(tablero, tableroUnoAtras))
            {
                std::cout << "Se freezo el juego" << endl;
            }
			std::cout << "Quiere continuar jugando (y/n) ";
            std::cin >> a;
        }
        while (a != 'n');
        std::cout << "Quiere resetear o terminar el juego (y/n) ";
            std::cin >> calculateagain;
    } while (calculateagain != 'n');

}
bool sonIguales(Tablero tablero, Tablero tableroAnterior)
{
    
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {

            if (tablero[i][j] != tableroAnterior[i][j])
            {
                return false;
            }
        }
    }
    return true;
}