#include "universidad.h"

Universidad::Universidad( std::list actas, std::list profesores, std::list estudiantes ){
    this->nombre = "Pontificia Universidad Javeriana Cali";
    this->actas = actas;
    this->profesores = profesores;
    this->estudiantes = estudiantes;
}

void Universidad::crearActa(){

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

void Universidad::crearEstudiante(){
    int id, celular, semestre;
    std::string nombre, email, carrera;
    std::cout << "Digita el id del estudiante a agregar: ";
    std::cin >> id;
    std::cout << "Digita el nombre del estudiante a agregar: ";
    std::cin >> nombre;
    std::cout << "Digita el email del estudiante a agregar: ";
    std::cin >> email;
    std::cout << "Digita el celular del estudiante a agregar: ";
    std::cin >> celular;
    std::cout << "Digita la carrera del estudiante a agregar: ";
    std::cin >> carrera;
    while( true ){
        std::cout << "Digita el semestre del estudiante a agregar: ";
        std::cin >> semestre;
        if( semestre <= 10 || semestre >= 1 ){
            break;
        }
        else{
            std::cout << "Numero invalido, por favor ingresalo nuevamente" << std::endl;
        }
    }
    
    estudiantes.push_back( Estudiante( id, nombre, email, celular, carrera, semestre ) );
}

void Universidad::mostrarTodasLasActas(){
    if( actas.size() != 0 ){
        for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
            acta->mostrarActa();
        }
    }
    else{
        std::cout << "No hay ninguna acta registrada por el momento." << std::endl;
    }
    
}

void Universidad::mostrarTodosLosProfesores(){
    if( profesores.size() != 0 ){
        for( list<Profesor>::iterator profesor = profesores.begin(); profesor != profesores.end(); profesor++ ){
                profesor->mostrarProfesor();
            }
    }
    else{
        std::cout << "No hay ningun profesor registrado por el momento." << std::endl;
    }
}

void Universidad::mostrarTodosLosEstudiante(){
    if( estudiantes.size() != 0 ){
        for( list<Estudiante>::iterator estudiante = estudiantes.begin(); estudiante != estudiantes.end(); estudiante++ ){
                estudiante->mostrarEstudiante();
            }
}
    else{
        std::cout << "No hay ninguna estudiante registrado por el momento." << std::endl;
    }
}