#include <iostream>
#define FILAS    20
#define COLUMNAS 80
using std::endl;

typedef  int Tablero[FILAS][COLUMNAS];
void inicializarTablero(Tablero tablero, int celulaMuerta);
void imprimirTablero(Tablero tablero);
void estadoCelulasInicial(Tablero tablero);
int validarFila();
int validarColumna();
int contarCelulasVivas(Tablero tablero);
void determinarVida(Tablero tablero);
int main() {
    Tablero tablero;
    inicializarTablero(tablero, 0);
    std::cout << "Bienvenido al Juego de la vida 1.0!" << endl;
    estadoCelulasInicial(tablero);
    imprimirTablero(tablero);
    int celulasVivas = contarCelulasVivas(tablero);
    std::cout << "Existen " << celulasVivas << " vivas actualmente" << endl;
    determinarVida(tablero);
    imprimirTablero(tablero);
    celulasVivas = contarCelulasVivas(tablero);
    std::cout << "Existen " << celulasVivas << " vivas actualmente" << endl;
    return 0;
}

void imprimirTablero(Tablero tablero) {

    for (int x = 0; x < FILAS; x++) {

        for (int y = 0; y < COLUMNAS; y++) {

            std::cout << tablero[x][y] << " ";
        }

        std::cout << "\n";
    }
}
void inicializarTablero(Tablero tablero, int celulaMuerta) {

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

        tablero[fila - 1][columna - 1] = 1;
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

            if (tablero[fila][columna] == 1) {
                contador++;
            }
        }
    }
    return contador;
}

void determinarVida(Tablero tablero) {

    for (int a = 0; a < FILAS; a++)
    {
        for (int b = 0; b < COLUMNAS; b++)
        {
            int estaVivo = 0;
            for (int c = -1; c < 2; c++)
            {
                for (int d = -1; d < 2; d++)
                {
                    if (!(c == 0 && d == 0))
                    {
                        if (tablero[a + c][b + d] == 1)
                        {
                            ++estaVivo;
                        }
                    }
                }
            }
            if (estaVivo < 2)
            {
                tablero[a][b] = 0;
            }
            else if (estaVivo == 3)
            {
                tablero[a][b] = 1;
            }
            else if (estaVivo > 3)
            {
                tablero[a][b] = 0;
            }
        }
    }
}