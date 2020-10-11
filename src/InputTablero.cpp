#include "InputTablero.h"

void estadoCelulasInicial(Tablero tablero) {
    int fila{};
    int columna{};
    char continuoAgregando{};
    std::cout << "Para comenzar el juego tiene que agregar  celulas vivas" << endl;
    std::cout << "Quiere empezar a agregar? (Y/N)" << endl;
    std::cin >> continuoAgregando;
    while (std::cin && ::tolower(continuoAgregando) == 'y') {
        fila = validarFila();
        columna = validarColumna();
        tablero[fila - 1][columna - 1] = VIVA;
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

            std::cout << "Error NO es un numero, Por favor agregar un numero:";
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

            std::cout << "Error NO es un numero, Por favor agregar un numero:";
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
            std::cout << "Tiene que ser menor a  " << COLUMNAS << " el valor" << endl;
        }

    } while (inputUsuario < 1 || inputUsuario > COLUMNAS);


    return inputUsuario;
}
