#include "../librerias/menu.h"

menu::menu(){  
}

// Se despliegan todas las opciones del menu
int menu::menuActa(){
    int opcionTemporal;
    std::cout << "\n---------- Menu Acta ----------\n" << std::endl;
    std::cout << "1. Crear nueva acta" << std::endl;
    std::cout << "2. Modificar acta" << std::endl;
    std::cout << "3. Calcular calificacion" << std::endl;
    std::cout << "4. Cerrar acta" << std::endl;
    std::cout << "5. Exportar acta" << std::endl;
    std::cout << "6. Listar actas" << std::endl;
    std::cout << "0. Salir\n" << std::endl;
    std::cout << "Digita el numero: ";
    std::cin >> opcionTemporal;
    setOpcion(opcionTemporal);
    return opcionTemporal;
}

// Obtenemos la opción actual
int menu::getOpcion(){
    return opcion;
}

// Sobreescribimos la opcion escogida por el usuario
void menu::setOpcion( int opcionSeleccionada ){
    this->opcion = opcionSeleccionada;
}