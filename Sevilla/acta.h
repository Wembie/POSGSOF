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
        auto coDirector;
        std::string enfasis;
        list<Profesor> jurados;
        list<Criterio> criterios;
    public:
        Acta();
        Acta( int, std::string, Estado, Estudiante, Profesor, Profesor, std::string, list<Profesor>, list<Criterio> );
        void mostrarActa();
};

#endif