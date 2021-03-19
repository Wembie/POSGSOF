#include "menu.h"

int menuUniversidad(){
    int opcion;
    std::cout << "\n---------- Menu Universidad ----------\n" << std::endl;
    std::cout << "1. Crear nueva acta" << std::endl;
    std::cout << "2. Modificar acta" << std::endl;
    std::cout << "3. Calcular calificacion" << std::endl;
    std::cout << "4. Cerrar acta" << std::endl;
    std::cout << "5. Exportar acta" << std::endl;
    std::cout << "6. Listar actas" << std::endl;
    std::cout << "0. Salir\n" << std::endl;
    std::cout << "Digita el numero: ";
    std::cin >> opcion;
    return opcion;
}

int menuActa(){
    int opcion;
    std::cout << "Menu Acta\n" << std::endl;
    std::cout << "0. Salir\n" << std::endl;
    std::cout << "Digita el numero: ";
    std::cin >> opcion;
    return opcion;
}