#include "InputTablero.h"

bool estadoCelulasInicial(Tablero tablero) {
    int fila{};
    int columna{};
    char continuoAgregando{};
    char comienzoJuego{};
    bool comenzoElJuego = true;
    std::cout << "Para comenzar el juego tiene que agregar  celulas vivas" << endl;
    std::cout << "Quiere empezar a agregar? (S/N)" << endl;
    std::cin >> comienzoJuego;
    if (std::cin && ::tolower(comienzoJuego) == 's')
    {
        continuoAgregando = 's';
    }
    else
    {
        comenzoElJuego= false;
    }
    while (std::cin && ::tolower(continuoAgregando) == 's') {
        fila = validarInputUsuario(FILAS);
        columna = validarInputUsuario(COLUMNAS);
        tablero[fila - 1][columna - 1] = VIVA;
        std::cout << "Continua Agregando? (S/N): ";
        std::cin >> continuoAgregando;
    }
    return comenzoElJuego;

}
int validarInputUsuario(int input) {
    int inputUsuario;
    do
    {
	    if (input == FILAS)
	    {
            std::cout << "Introduzca un valor para la fila : ";
	    }
        else
        {
            std::cout << "Introduzca un valor para la columna : ";
        }
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
            std::cout << "Tiene que ser mayor a 1 el valor" << endl;
        }

        if (inputUsuario > input)
        {
            std::cout << "Tiene que ser menor a  " << input << " el valor" << endl;
        }

    } while (inputUsuario < 1 || inputUsuario > input);


    return inputUsuario;

}

