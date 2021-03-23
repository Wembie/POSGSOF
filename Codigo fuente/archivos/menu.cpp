#include "../librerias/menu.h"

int menuUniversidad(){
    int opcion;
    std::cout << "\n---------- Menu Universidad ----------\n" << std::endl;

    std::cout << "1. Crear" << std::endl;
    std::cout << "2. Listar\n" << std::endl;

    std::cout << "3. Editar acta" << std::endl;
    std::cout << "4. Calcular calificacion" << std::endl;
    std::cout << "5. Eliminar acta" << std::endl;
    std::cout << "6. Cerrar acta" << std::endl;
    std::cout << "7. Exportar acta\n" << std::endl;

    std::cout << "8. Consultar actas rechazadas/pendientes" << std::endl;
    std::cout << "9. Consultar jurados internos/externos" << std::endl;
    std::cout << "10. Listar criterios de un acta\n" << std::endl;

    std::cout << "69. Sorpresa\n" << std::endl;

    std::cout << "666. Cargar acta, profesores y estudiantes por defecto\n" << std::endl;

    std::cout << "0. Salir\n" << std::endl;
    std::cout << "Digita el numero: ";
    std::cin >> opcion;
    return opcion;
}

int menuCrear(){
    int opcion;
    std::cout << "\n---------- Menu Crear ----------\n" << std::endl;
    std::cout << "1. Crear nueva acta" << std::endl;
    std::cout << "2. Crear profesor" << std::endl;
    std::cout << "3. Crear estudiante" << std::endl;
    std::cout << "0. Atras\n" << std::endl;
    std::cout << "Digita el numero: ";
    std::cin >> opcion;
    return opcion;
}

int menuListar(){
    int opcion;
    std::cout << "\n---------- Menu Listar ----------\n" << std::endl;
    std::cout << "1. Listar actas" << std::endl;
    std::cout << "2. Listar profesores" << std::endl;
    std::cout << "3. Listar estudiantes" << std::endl;
    std::cout << "0. Atras\n" << std::endl;
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

    std::cout << "4. Listar actas dirigidas por profesor" << std::endl;
    std::cout << "5. Listar actas aplicadas" << std::endl;
    std::cout << "6. Listar actas investigativas" << std::endl;
    std::cout << "7. Listar actas en la cual un profesor es jurado" << std::endl;
    std::cout << "8. Mostrar todos los jurados" << std::endl;

    std::cout << "0. Atras\n" << std::endl;
    std::cout << "Digita el numero: ";
    std::cin >> opcion;
    return opcion;
}

int menuActa(){
    int opcion;
    std::cout << "\n---------- Editar Acta ----------\n" << std::endl;
    std::cout << "1. Cambiar Fecha" << std::endl;
    std::cout << "2. Cambiar Estado" << std::endl;
    std::cout << "3. Cambiar Autor" << std::endl;
    std::cout << "4. Cambiar Director" << std::endl;
    std::cout << "5. Cambiar Co-Director" << std::endl;
    std::cout << "6. Cambiar Enfasis" << std::endl;
    std::cout << "7. Cambiar Modalidad" << std::endl;
    std::cout << "8. Cambiar Jurados" << std::endl;
    std::cout << "9. Cambiar Criterios" << std::endl;
    std::cout << "10. Agregar Observaciones" << std::endl;
    std::cout << "0. Atras\n" << std::endl;
    std::cout << "Digita el numero: ";
    std::cin >> opcion;
    return opcion;
}

int menuConsultarActas(){
    int opcion;
    std::cout << "\n---------- Consultar actas ----------\n" << std::endl;
    std::cout << "1. Consultar actas rechazadas" << std::endl;
    std::cout << "2. Consultar actas pendientes" << std::endl;
    std::cout << "0. Atras" << std::endl;
    std::cout << "\nDigita el numero: ";
    std::cin >> opcion;
    return opcion;
}

int menuConsultarJurados(){
    int opcion;
    std::cout << "\n---------- Consultar jurados ----------\n" << std::endl;
    std::cout << "1. Consultar jurados internos" << std::endl;
    std::cout << "2. Consultar jurados externos" << std::endl;
    std::cout << "0. Atras" << std::endl;
    std::cout << "\nDigita el numero: ";
    std::cin >> opcion;
    return opcion;
}
