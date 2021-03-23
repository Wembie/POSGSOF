#include <iostream>

#ifndef PERSONA_H
#define PERSONA_H

class Persona{
    private:
        int id;
        std::string nombre;
        std::string email;
        std::string celular;
    public:
        Persona();
        Persona( int, std::string, std::string, std::string );
        void mostrarPersona();
        void mostrarNombre();
        int getId();
        void setId( int );
        std::string getNombre();
};

#endif
