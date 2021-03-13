#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include "persona.h"

class Estudiante : public Persona{
    private:
        std::string carrera;
        int semestre;
    public:
        Estudiante( int, std::string, std::string, int, std::string, int );
        void mostrarEstudiante();
};

#endif