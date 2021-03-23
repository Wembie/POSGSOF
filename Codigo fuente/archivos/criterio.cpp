#include "../librerias/criterio.h"

Criterio::Criterio(){

}

Criterio::Criterio( std::string tema, float calificacion, float ponderacion, std::string observacion ){
    this->tema = tema;
    this->calificacion = calificacion;
    this->ponderacion = ponderacion;
    this->observacion = observacion;
}

// Imprime el objeto criterio
void Criterio::mostrarCriterio(){
    std::cout << "Tema: " << tema << std::endl;
    std::cout << "Calificacion: " << calificacion << std::endl;
    std::cout << "Ponderacion: " << ponderacion << "%" << std::endl;
    std::cout << "Observacion: " << observacion << std::endl;
}

float Criterio::getCalificacion(){
    return this->calificacion;
}

float Criterio::getPonderacion(){
    return this->ponderacion/100;
}

std::string Criterio::getTema(){
    return this->tema;
}

std::string Criterio::getObservacion(){
    return this->observacion;
}

void Criterio::setObservacion( std::string observacion ){
    this->observacion = observacion;
}
