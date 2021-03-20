#include <iostream>
#include <list>
#include "estudiante.h"
#include "profesor.h"
#include "criterio.h"

#ifndef ACTA_H
#define ACTA_H

using std::list;

enum Estado{ CERRADA, ABIERTA, PENDIENTE };

class Acta{
    private:
        int codigo;
        std::string fechaHora;
        Estado estado;
        Estudiante autor;
        Profesor director;
        Profesor coDirector;
        std::string coDirectorActa;
        std::string enfasis;
        std::string modalidad;
        list<Profesor> jurados;
        list<Criterio> criterios;
    public:
        Acta();
        Acta( int, std::string, Estado, Estudiante, Profesor, std::string, std::string, list<Profesor>, list<Criterio> );
        Acta( int, std::string, Estado, Estudiante, Profesor, Profesor, std::string, std::string, list<Profesor>, list<Criterio> );
        ~Acta();
        void mostrarActa();
        void setFechaHora( std::string );
        void setEstado( Estado );
        void setAutor( Estudiante );
        void setDirector( Profesor );
        void setCoDirector( Profesor );
        void setEnfasis( std::string );
        void setModalidad( std::string );
        void setJurados( list<Profesor> );
        void setCriterios( list<Criterio> );
        Estado getEstado();
        int getCodigo();
};

#endif