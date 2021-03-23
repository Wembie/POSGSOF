#include <iostream>
#include "persona.h"

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

class Estudiante : public Persona{
    private:
        std::string carrera;
        int semestre;
    public:
        Estudiante();
        Estudiante( int, std::string, std::string, std::string, std::string, int );
        void mostrarEstudiante();
};

#endif
