#ifndef JURADO_H
#define JURADO_H

#include <iostream>
#include "persona.h"

class Jurado : public Persona{
    private:
        std::string cargo;
    public:
        Jurado( std::string, std::string );
}

#endif