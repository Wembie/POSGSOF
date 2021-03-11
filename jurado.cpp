#include "jurado.h"

Jurado::Jurado( std::string nombre, std::string cargo ) : Persona( nombre ){
    this->cargo = cargo;
}