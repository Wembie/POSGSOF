#ifndef PROFESOR_H
#define PROFESOR_H

#include <iostream>
#include "persona.h"

class Profesor : public Persona{
    private:
        std::string cargo;
    public:
        Profesor( int, std::string, std::string, int, std::string );
}

#endif