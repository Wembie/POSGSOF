#include "universidad.h"

Universidad::Universidad( std::list actas, std::list profesores, std::list estudiantes ){
    this->nombre = "Pontificia Universidad Javeriana Cali";
    this->actas = actas;
    this->profesores = profesores;
    this->estudiantes = estudiantes;
}

void Universidad::crearProfesor(){
    int id, celular;
    std::string nombre, email, cargo;
    Tipo tipo;
    std::cout << "Digita el id del profesor a agregar: ";
    std::cin >> id;
    std::cout << "Digita el nombre del profesor a agregar: ";
    std::cin >> nombre;
    std::cout << "Digita el email del profesor a agregar: ";
    std::cin >> email;
    std::cout << "Digita el celular del profesor a agregar: ";
    std::cin >> celular;
    std::cout << "Digita el cargo del profesor a agregar: ";
    std::cin >> cargo;
    while( true ){
        std::cout << "Digita el tipo del profesor a agregar [ 0 = INTERNO, 1 = EXTERNO ]: ";
        std::cin >> tipo;
        if( tipo == INTERNO || tipo == EXTERNO ){
            break;
        }
        else{
            std::cout << "Numero invalido, por favor ingresalo nuevamente" << std::endl;
        }
    }
    profesores.push_back( Profesor( id, nombre, email, celular, cargo, tipo ) );
}