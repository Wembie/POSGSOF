#include "../librerias/persona.h"

Persona::Persona(){

}

Persona::Persona( int id, std::string nombre, std::string email, std::string celular ){
    this->id = id;
    this->nombre = nombre;
    this->email = email;
    this->celular = celular;
}

// Imprime el objeto persona
void Persona::mostrarPersona(){
    std::cout << "\nId: " << this->id << std::endl;
    std::cout << "Nombre: " << this->nombre << std::endl;
    std::cout << "Email: " << this->email << std::endl;
    std::cout << "Celular: " << this->celular << std::endl;
}

void Persona::mostrarNombre(){
    std::cout << this->nombre << std::endl;
}

int Persona::getId(){
    return this->id;
}

void Persona::setId( int id ){
    this->id = id;
}

std::string Persona::getNombre(){
    return this->nombre;
}
