#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H

#include <iostream>
#include "acta.h"

class Universidad{
    private:
        std::string nombre;
        std::list<Acta> actas;
        std::list<Profesor> profesores;
        std::list<Estudiante> estudiantes;
    public:
        Universidad( std::list, std::list, std::list );
        void crearProfesor();
}

#endif