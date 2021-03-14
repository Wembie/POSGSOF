#include <iostream>
#include "persona.h"

#ifndef ESTUDIANTEH
#define ESTUDIANTE_H

class Estudiante : public Persona{
    private:
        std::string carrera;
        int semestre;
    public:
        Estudiante( int, std::string, std::string, int, std::string, int );
        void mostrarEstudiante();
};

#endif