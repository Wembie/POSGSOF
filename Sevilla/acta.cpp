#include "acta.h"

Acta::Acta(){

}

Acta::Acta( int codigo, std::string fechaHora, Estado estado, Estudiante autor, Profesor director, std::string enfasis, std::string modalidad, list<Profesor> jurados, list<Criterio> criterios ){
    this->codigo = codigo;
    this->fechaHora = fechaHora;
    this->estado = estado;
    this->autor = autor;
    this->director = director;
    this->coDirectorActa = "N/A";
    this->enfasis = enfasis;
    this->modalidad = modalidad;
    this->jurados = jurados;
    this->criterios = criterios;
}

Acta::Acta( int codigo, std::string fechaHora, Estado estado, Estudiante autor, Profesor director, Profesor coDirector, std::string enfasis, std::string modalidad, list<Profesor> jurados, list<Criterio> criterios ){
    this->codigo = codigo;
    this->fechaHora = fechaHora;
    this->estado = estado;
    this->autor = autor;
    this->director = director;
    this->coDirector = coDirector;
    this->coDirectorActa = "Si";
    this->enfasis = enfasis;
    this->modalidad = modalidad;
    this->jurados = jurados;
    this->criterios = criterios;
}

Acta::~Acta(){

}

void Acta::mostrarActa(){
    std::cout << "\nCodigo Acta: " << codigo << std::endl;
    std::cout << fechaHora << std::endl;
    std::cout << "Estado: ";
    if( estado == CERRADA ){
        std::cout << "Cerrada" << std::endl;
    }
    else if( estado == ABIERTA ){
        std::cout << "Abierta" << std::endl;
    }
    else if( estado == PENDIENTE ){
        std::cout << "Pendiente" << std::endl;
    }
    std::cout << "Autor: ";
    autor.mostrarNombre();
    std::cout << "Director: ";
    director.mostrarNombre();
    std::cout << "Co-Director: ";
    if( coDirectorActa == "N/A" ){
        std::cout << "No existe" << std::endl;
    }
    else{
        coDirector.mostrarNombre();
    }
    std::cout << "Enfasis: " << enfasis << std::endl;
    std::cout << "Modalidad: " << modalidad << std::endl;
    int i = 1;
    std::cout << "Jurados: ";
    if( jurados.empty() ){
        std::cout << "No hay jurados" << std::endl;
    }
    else{
        for( list<Profesor>::iterator jurado = jurados.begin(); jurado != jurados.end(); jurado++ ){
            std::cout << "Jurado " << i << ":" << std::endl;
            jurado->mostrarNombre();
            i++;
        }
    }
    i = 1;
    std::cout << "Criterios: \n\n";
    if( criterios.empty() ){
        std::cout << "No hay criterios" << std::endl;
    }
    else{
        for( list<Criterio>::iterator criterio = criterios.begin(); criterio != criterios.end(); criterio++ ){
            std::cout << "Criterio " << i << std::endl << std::endl;
            criterio->mostrarCriterio();
            i++;
        }
    }
}

void Acta::setFechaHora( std::string fechaHora ){
    this->fechaHora = fechaHora;
}

void Acta::setEstado( Estado estado ){
    this->estado = estado;
}

void Acta::setAutor( Estudiante autor ){
    this->autor = autor;
}

void Acta::setDirector( Profesor director){
    this->director = director;
}

void Acta::setCoDirectorActa( std::string coDirectorActa ){
    this->coDirectorActa = coDirectorActa;
}

void Acta::setCoDirector( Profesor coDirector ){
    this->coDirector = coDirector;
}

void Acta::setEnfasis( std::string enfasis ){
    this->enfasis = enfasis;
}

void Acta::setModalidad( std::string modalidad ){
    this->modalidad = modalidad;
}

void Acta::setJurados( list<Profesor> jurados ){
    this->jurados = jurados;
}

void Acta::setCriterios( list<Criterio> criterios ){
    this->criterios = criterios;
}

Estado Acta::getEstado(){
    return this->estado;
}

int Acta::getCodigo(){
    return this->codigo;
}

Profesor Acta::getDirector(){
    	return this->director;
}

Profesor Acta::getCoDirector(){
    return this->coDirector;
}

list<Profesor> Acta::getJurados(){
    return this->jurados;
}

std::string Acta::getModalidad(){
    return this->modalidad;
}

float Acta::notaFinal(){
  float calificacion, ponderacionTotal;
  for( list<Criterio>::iterator criterio = criterios.begin(); criterio != criterios.end(); criterio++ ){
      ponderacionTotal += criterio->getPonderacion();
  }
  if(ponderacionTotal == 1){
      for( list<Criterio>::iterator criterio = criterios.begin(); criterio != criterios.end(); criterio++ ){
          if(criterio->getCalificacion() > 0 && criterio->getCalificacion() < 5){
          calificacion += criterio->getCalificacion()*criterio->getPonderacion();
      }else{
        return -1;
      }
    }
    return calificacion;
  }else{
    return -1;
  }
}
