<<<<<<< HEAD:archivos/profesor.cpp
#include "../librerias/profesor.h"

Profesor::Profesor(){
    
}

Profesor::Profesor( int id, std::string nombre, std::string email, int celular, std::string cargo, Tipo tipo ) : Persona( id, nombre, email, celular ){
    this->cargo = cargo;
    this->tipo = tipo;
}

void Profesor::mostrarProfesor(){
    this->mostrarPersona();
    std::cout << "Cargo: " << this->cargo << std::endl;
    std::cout << "Tipo: " << this->tipo<< std::endl;
=======
#include "profesor.h"

Profesor::Profesor(){
    
}

Profesor::Profesor( int id, std::string nombre, std::string email, int celular, std::string cargo, Tipo tipo ) : Persona( id, nombre, email, celular ){
    this->cargo = cargo;
    this->tipo = tipo;
}

void Profesor::mostrarProfesor(){
    this->mostrarPersona();
    std::cout << "Cargo: " << this->cargo << std::endl;
    std::cout << "Tipo: " << this->tipo<< std::endl;
>>>>>>> baad825f270d833108f040b08ded042f1ac36cef:profesor.cpp
}