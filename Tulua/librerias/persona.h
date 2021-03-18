<<<<<<< HEAD:librerias/persona.h
#include <iostream>
#include <string>

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
        int getId();
};

//https://www.youtube.com/watch?v=y8Y13enIuUM

=======
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
        int getId();
};

//https://www.youtube.com/watch?v=y8Y13enIuUM

>>>>>>> baad825f270d833108f040b08ded042f1ac36cef:persona.h
#endif