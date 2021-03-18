<<<<<<< HEAD:librerias/criterio.h
#include <iostream>

#ifndef CRITERIO_H
#define CRITERIO_H

class Criterio{
    private:
        std::string tema;
        float calificacion;
        float ponderacion;
        std::string obsarvacion;
    public:
        Criterio( std::string, float, float, std::string );
};

=======
#include <iostream>

#ifndef CRITERIO_H
#define CRITERIO_H

class Criterio{
    private:
        std::string tema;
        float calificacion;
        float ponderacion;
        std::string obsarvacion;
    public:
        Criterio( std::string, float, float, std::string );
        void mostrarCriterio();
};

>>>>>>> baad825f270d833108f040b08ded042f1ac36cef:criterio.h
#endif