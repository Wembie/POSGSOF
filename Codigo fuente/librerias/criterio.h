#include <iostream>

#ifndef CRITERIO_H
#define CRITERIO_H

class Criterio{
    private:
        std::string tema;
        float calificacion;
        float ponderacion;
        std::string observacion;
    public:
        Criterio();
        Criterio( std::string, float, float, std::string );
        void mostrarCriterio();
        float getCalificacion();
        float getPonderacion();
        std::string getTema();
        std::string getObservacion();
        void setObservacion( std::string );
};

#endif
