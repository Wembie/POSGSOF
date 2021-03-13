#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>

class Persona{
    private:
        int id;
        std::string nombre;
        std::string email;
        int celular;
    public:
        Persona( int, std::string, std::string, int );
        void mostrarPersona();
        int getId();
};

//https://www.youtube.com/watch?v=y8Y13enIuUM

#endif