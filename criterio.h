#ifndef CRITERIO_H
#define CRITERIO_H

#include <iostream>

class Criterio{
    private:
        std::string tema;
        float calificacion;
        float ponderacion;
        std::string obsarvacion;
    public:
        Criterio( std::string, float, float, std::string );
}

#endif