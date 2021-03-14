#include <iostream>
#include "persona.h"

#ifndef PROFESOR_H
#define PROFESOR_H

enum Tipo{ INTERNO, EXTERNO };

class Profesor : public Persona{
    private:
        std::string cargo;
        Tipo tipo;
    public:
        Profesor( int, std::string, std::string, int, std::string, Tipo );
        void mostrarProfesor();
};

#endif