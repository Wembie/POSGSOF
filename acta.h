#include <iostream>
#include <list>
#include "estudiante.h"
#include "profesor.h"
#include "criterio.h"

#ifndef ACTA_H
#define ACTA_H

using std::list;

enum Estado{ CERRADO, ABIERTO, PENDIENTE };

class Acta{
    private:
        int codigoActa;
        std::string fechaHora;
        Estado estado;
        Estudiante autor;
        Profesor director;
        Profesor codirector;
        std::string enfasis;
        list<Profesor> jurados;
        list<Criterio> criterios;
    public:
        //Acta();
        void mostrarActa();
};

#endif