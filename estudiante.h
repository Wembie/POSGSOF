#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include "persona.h"

class Estudiante : public Persona{
    private:
        int id;
    public:
        Estudiante( std::string, int );
}

#endif