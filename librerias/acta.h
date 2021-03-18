<<<<<<< HEAD:librerias/acta.h
#include <iostream>
#include <list>
#include "estudiante.h"
#include "profesor.h"
#include "criterio.h"

#ifndef ACTA_H
#define ACTA_H

using std::list;

enum Estado{ ABIERTO, PENDIENTE, CERRADO };

class Acta{
    private:
        int codigo;
        std::string fechaHora;
        Estado estado;
        Estudiante autor;
        Profesor director;
        Profesor coDirector;
        std::string enfasis;
        list<Profesor> jurados;
        list<Criterio> criterios;
    public:
        Acta( int, std::string, Estado, Estudiante, Profesor, Profesor, std::string, list<Profesor>, list<Criterio> );
        void mostrarActa();
};

=======
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
        int codigo;
        std::string fechaHora;
        Estado estado;
        Estudiante autor;
        Profesor director;
        Profesor coDirector;
        std::string enfasis;
        list<Profesor> jurados;
        list<Criterio> criterios;
    public:
        Acta( int, std::string, Estado, Estudiante, Profesor, Profesor, std::string, list<Profesor>, list<Criterio> );
        void mostrarActa();
};

>>>>>>> baad825f270d833108f040b08ded042f1ac36cef:acta.h
#endif