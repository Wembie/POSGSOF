#include "profesor.h"

Profesor::Profesor( int id, std::string nombre, std::string email, int celular std::string cargo ) : Persona( id, nombre, email, celular ){
    this->cargo = cargo;
}