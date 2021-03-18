#include "../librerias/acta.h"

Acta::Acta( int codigo, std::string fechaHora, Estado estado, Estudiante autor, Profesor director, Profesor coDirector, std::string enfasis, list<Profesor> jurados, list<Criterio> criterios ){
    this->codigo = codigo;
    this->fechaHora = fechaHora;
    this->estado = estado;
    this->autor = autor;
    this->director = director;
    this->coDirector = coDirector;
    this->enfasis = enfasis;
    this->jurados = jurados;
    this->criterios = criterios;
}

void Acta::mostrarActa(){
}