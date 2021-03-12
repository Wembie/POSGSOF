#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include "persona.h"

class Estudiante : public Persona{
    private:
        std::string carrera;
    public:
        Estudiante( int, std::string, std::string, int, std::string );
}

#endif