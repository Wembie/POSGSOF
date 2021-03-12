#include "estudiante.h"

Estudiante::Estudiante( int id, std::string nombre, std::string email, int celular, std::string carrera ) : Persona( id, nombre, email, celular ){
    this->carrera = carrera;
}