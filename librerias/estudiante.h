<<<<<<< HEAD:librerias/estudiante.h
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
        Estudiante( int, std::string, std::string, int, std::string, int );
        void mostrarEstudiante();
};

=======
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
        Estudiante( int, std::string, std::string, int, std::string, int );
        void mostrarEstudiante();
};

>>>>>>> baad825f270d833108f040b08ded042f1ac36cef:estudiante.h
#endif