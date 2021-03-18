<<<<<<< HEAD:librerias/profesor.h
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
        Profesor();
        Profesor( int, std::string, std::string, int, std::string, Tipo );
        void mostrarProfesor();
};

=======
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
        Profesor();
        Profesor( int, std::string, std::string, int, std::string, Tipo );
        void mostrarProfesor();
};

>>>>>>> baad825f270d833108f040b08ded042f1ac36cef:profesor.h
#endif