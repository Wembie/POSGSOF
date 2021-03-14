#include "persona.h"

Persona::Persona( int id, std::string nombre, std::string email, int celular ){
    this->id = id;
    this->nombre = nombre;
    this->email = email;
    this->celular = celular;
}

void Persona::mostrarPersona(){
    std::cout << "Id: " << this->id << std::endl;
    std::cout << "Nombre: " << this->nombre << std::endl;
    std::cout << "Email: " << this->email << std::endl;
    std::cout << "Celular: " << this->celular << std::endl;
}

int Persona::getId(){
    return this->id;
}