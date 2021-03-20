#include "menu.h"

int menuUniversidad(){
    int opcion;
    std::cout << "\n---------- Menu Universidad ----------\n" << std::endl;
    std::cout << "1. Crear Nueva Acta" << std::endl;
    std::cout << "2. Editar Acta" << std::endl;
    std::cout << "3. Crear Profesor" << std::endl;
    std::cout << "4. Crear Estudiante" << std::endl;
    std::cout << "5. Listar Actas" << std::endl;
    std::cout << "6. Listar Profesores" << std::endl;
    std::cout << "7. Listar Estudiantes" << std::endl;
    std::cout << "0. Salir\n" << std::endl;
    std::cout << "Digita el numero: ";
    std::cin >> opcion;
    return opcion;
}

int menuActa(){
    int opcion;
    std::cout << "\n---------- Menu Acta ----------\n" << std::endl;
    std::cout << "1. Cambiar Fecha" << std::endl;
    std::cout << "2. Cambiar Estado" << std::endl;
    std::cout << "3. Cambiar Autor" << std::endl;
    std::cout << "4. Cambiar Director" << std::endl;
    std::cout << "5. Cambiar Co-Director" << std::endl;
    std::cout << "6. Cambiar Enfasis" << std::endl;
    std::cout << "7. Cambiar Modalidad" << std::endl;
    std::cout << "8. Cambiar Jurados" << std::endl;
    std::cout << "9. Cambiar Criterios" << std::endl;
    std::cout << "0. Salir\n" << std::endl;
    std::cout << "Digita el numero: ";
    std::cin >> opcion;
    return opcion;
}

int menuListarActas(){
    int opcion;
    std::cout << "\n---------- Listar Actas ----------\n" << std::endl;
    std::cout << "1. Listar todas las actas del sistema" << std::endl;
    std::cout << "2. Listar actas abiertas" << std::endl;
    std::cout << "3. Listar actas cerradas" << std::endl;
    std::cout << "0. Salir\n" << std::endl;
    std::cout << "Digita el numero: ";
    std::cin >> opcion;
    return opcion;
}