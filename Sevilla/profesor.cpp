#include "profesor.h"

Profesor::Profesor(){
    setId( -1 );
}

Profesor::Profesor( int id, std::string nombre, std::string email, std::string celular, std::string cargo, Tipo tipo ) : Persona( id, nombre, email, celular ){
    this->cargo = cargo;
    this->tipo = tipo;
}

void Profesor::mostrarProfesor(){
    this->mostrarPersona();
    std::cout << "Cargo: " << this->cargo << std::endl;
    if( this->tipo == INTERNO ){
        std::cout << "Tipo: Interno" << std::endl;
    }
    else{
        std::cout << "Tipo: Externo" << std::endl;
    }
}

Tipo Profesor::getTipo(){
    return this->tipo;
}
