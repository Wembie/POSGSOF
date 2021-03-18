#include <iostream>
#include "menu.h"
#include "acta.h"
#include "funciones.h"

#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H

class Universidad{
    private:
        std::string nombre;
        list<Acta> actas;
        list<Profesor> profesores;
        list<Estudiante> estudiantes;
    public:
        Universidad( list<Acta>, list<Profesor>, list<Estudiante> );
        void crearActa();
        void crearProfesor();
        void crearEstudiante();
        void mostrarTodasLasActas();
        void mostrarTodosLosProfesores();
        void mostrarTodosLosEstudiante();
};

#endif