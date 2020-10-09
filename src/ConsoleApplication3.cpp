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

int main() {
    Tablero tablero;
    inicializarTablero(tablero, 0);
    std::cout << "Bienvenido al Juego de la vida 1.0!" << endl;
    estadoCelulasInicial(tablero);
    imprimirTablero(tablero);
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
    int fila;
    int columna;
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
    int userInput;
    do 
    {
        std::cout << "Introduzca un valor para la fila : ";
        std::cin >> userInput;
        while (std::cin.fail()) 
        {

            std::cout << "Error NO es un numero" << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> userInput;
        }
        if (userInput < 1)
        {
            std::cout << "Tiene que ser mayor a 1 el valor\n";
        }

        if (userInput > FILAS)
        {
            std::cout << "Tiene que ser menor a 20 el valor\n";
        }

    } while (userInput < 1 || userInput > FILAS);


    return userInput;

}

int validarColumna() {
    int userInput;
    do
    {
        std::cout << "Introduzca un valor para la columna : ";
        std::cin >> userInput;
        while (std::cin.fail())
        {

            std::cout << "Error NO es un numero" << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> userInput;
        }
        if (userInput < 1)
        {
            std::cout << "Tiene que ser mayor a 1 el valor\n";
        }

        if (userInput > COLUMNAS)
        {
            std::cout << "Tiene que ser menor a 80 el valor\n";
        }

    } while (userInput < 1 || userInput > COLUMNAS);


    return userInput;
}