#include "profesor.h"

Profesor::Profesor( int id, std::string nombre, std::string email, int celular, std::string cargo, Tipo tipo ) : Persona( id, nombre, email, celular ){
    this->cargo = cargo;
    this->tipo = tipo;
}

void Profesor::mostrarProfesor(){
    this->mostrarPersona();
    std::cout << "Cargo: " << this->cargo << std::endl;
    std::cout << "Tipo: " << this->tipo<< std::endl;
}