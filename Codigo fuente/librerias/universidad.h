#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <string>
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
        void crearProfesor();
        void crearEstudiante();
        Criterio crearCriterio( int );
        void crearActa( int );
        void editarActa();
        void listarActas( int );
        void eliminarActa();
        void cerrarActa();
        void actasDeUnProfesor();
        void actasDeUnProfesorJurado();
        void mostrarActasConJurado();
        void mostrarActasAplicadas();
        void mostrarActasInvestigativas();
        void mostrarTodosLosProfesores();
        void mostrarTodosLosEstudiantes();
        void calcularCalificacion( int );
        void exportarActa();
        list<Acta> getActas();
        void elDiablo();
        void consultarActas( EstadoActaCerrada );
        void consultarJurados( Tipo );
        void listarCriterios( int );
        void sorpresa();
};

#endif
