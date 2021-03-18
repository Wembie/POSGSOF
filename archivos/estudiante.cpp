#include "../librerias/estudiante.h"

Estudiante::Estudiante(){
    
}

Estudiante::Estudiante( int id, std::string nombre, std::string email, int celular, std::string carrera, int semestre ) : Persona( id, nombre, email, celular ){
    this->carrera = carrera;
    this->semestre = semestre;
}

void Estudiante::mostrarEstudiante(){
    this->mostrarPersona();
    std::cout << "Carrera: " << this->carrera << std::endl;
    std::cout << "Semestre: " << this->semestre << std::endl;
}
