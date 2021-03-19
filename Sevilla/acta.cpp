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

void Acta::mostrarActa(){
    std::cout << "Codigo Acta: " << codigo << std::endl;
    std::cout << fechaHora << std::endl;
    std::cout << "Estado:";
    if( estado == CERRADA ){
        std::cout << "Cerrada" << std::endl;
    }
    else if( estado == ABIERTA ){
        std::cout << "Abierta" << std::endl;
    }
    else if( estado == PENDIENTE ){
        std::cout << "Pendiente" << std::endl;
    }
    std::cout << "Autor:" << std::endl;
    autor.mostrarEstudiante();
    std::cout << "Director:" << std::endl;
    director.mostrarProfesor();
    std::cout << "Co-Director:" << std::endl;
    if( coDirectorActa == "N/A" ){
        std::cout << "No existe" << std::endl;
    }
    else{
        coDirector.mostrarProfesor();
    }
    std::cout << "Enfasis:" << enfasis << std::endl;
    int i;
    i = 1;
    for( list<Profesor>::iterator profesor = jurados.begin(); profesor != jurados.end(); profesor++ ){
        std::cout << "Jurado " << i << ":" << std::endl;
        profesor->mostrarProfesor();
        i++;
    }
    i = 1;
    for( list<Criterio>::iterator criterio = criterios.begin(); criterio != criterios.end(); criterio++ ){
        criterio->mostrarCriterio();
        i++;
    }
}