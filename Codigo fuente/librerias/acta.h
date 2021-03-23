#include <iostream>
#include <list>
#include <fstream>
#include "estudiante.h"
#include "profesor.h"
#include "criterio.h"

#ifndef ACTA_H
#define ACTA_H

using std::list;

enum Estado{ CERRADA, ABIERTA };

enum EstadoActaCerrada{ APROBADA, RECHAZADA, PENDIENTE };

class Acta{
    private:
        int codigo;
        std::string fechaHora;
        Estado estado;
        EstadoActaCerrada estadoActaCerrada;
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
        Acta( int, std::string, Estado, EstadoActaCerrada, Estudiante, Profesor, std::string, std::string, list<Profesor>, list<Criterio> );
        Acta( int, std::string, Estado, EstadoActaCerrada, Estudiante, Profesor, Profesor, std::string, std::string, list<Profesor>, list<Criterio> );
        void mostrarActa();
        void setFechaHora( std::string );
        void setEstado( Estado );
        void setEstadoActaCerrada( EstadoActaCerrada );
        void setAutor( Estudiante );
        void setDirector( Profesor );
        void setCoDirector( Profesor );
        void setCoDirectorActa( std::string );
        void setEnfasis( std::string );
        void setModalidad( std::string );
        void setJurados( list<Profesor> );
        void setCriterios( list<Criterio> );
        Estado getEstado();
        EstadoActaCerrada getEstadoActaCerrada();
        int getCodigo();
        Profesor getDirector();
        Profesor getCoDirector();
        list<Profesor> getJurados();
        list<Criterio> getCriterios();
        std::string getModalidad();
        float notaFinal();
        void exportar( int );
};

#endif
