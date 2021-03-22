#include "criterio.h"

Criterio::Criterio(){

}

Criterio::Criterio( std::string tema, float calificacion, float ponderacion, std::string observacion ){
    this->tema = tema;
    this->calificacion = calificacion;
    this->ponderacion = ponderacion;
    this->observacion = observacion;
}

void Criterio::mostrarCriterio(){
    std::cout << "Tema: " << tema << std::endl;
    std::cout << "Calificacion: " << calificacion << std::endl;
    std::cout << "Ponderacion: " << ponderacion << "%" << std::endl;
    std::cout << "Observacion: " << observacion << std::endl;
}

float Criterio::getCalificacion(){
  return calificacion;
}

float Criterio::getPonderacion(){
  return ponderacion/100;
}
