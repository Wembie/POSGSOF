#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "menu.h"
#include "acta.h"
#include "funciones.h"

#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H

class Universidad{
    private:
        std::string nombre;
        //list<int> codigosActas;
        list<Acta> actas;
        list<Profesor> profesores;
        list<Estudiante> estudiantes;
    public:
        Universidad( list<Acta>, list<Profesor>, list<Estudiante> );
        void crearCriterio();
        void crearActa( int );
        void crearProfesor();
        void crearEstudiante();
        void mostrarTodasLasActas();
        void mostrarTodosLosProfesores();
        void mostrarTodosLosEstudiante();
};

#endif