#ifndef ACTA_H
#define ACTA_H

#include <iostream>
#include <list>
#include "estudiante.h"
#include "profesor.h"
#include "criterio.h"

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
        std::list<Profesor> jurados;
        std::list<Criterio> criterios;
    public:
        Acta();
        void mostrarTodasLasActas();
};

#endif