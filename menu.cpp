#include "menu.h"

int menuActa(){
    int opcion;
    std::cout << "Menu Acta\n" << std::endl;
    std::cout << "0. Salir\n" << std::endl;
    std::cout << "Digita el numero: ";
    std::cin >> opcion;
    return opcion;
}