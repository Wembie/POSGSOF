#include "estudiante.h"

Estudiante::Estudiante( std::string nombre, int id ) : Persona( nombre ){
    this->id = id;
}