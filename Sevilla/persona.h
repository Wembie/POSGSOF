#include <iostream>

#ifndef PERSONA_H
#define PERSONA_H

class Persona{
    private:
        int id;
        std::string nombre;
        std::string email;
        int celular;
    public:
        Persona();
        Persona( int, std::string, std::string, int );
        void mostrarPersona();
        void mostrarNombre();
        int getId();
};

#endif