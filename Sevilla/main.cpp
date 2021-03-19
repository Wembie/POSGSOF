#include <iostream>
#include "universidad.h"

int main(){
    list<Acta> actas;
    list<Profesor> profesores;
    list<Estudiante> estudiantes;
    Universidad javeriana( actas, profesores, estudiantes );
    int contadorActa;
    if( encontrarDirectorio( "Actas" ) ){
        contadorActa = 0;
        //guardar el codigo
    }
    else{
        mkdir( "Actas" );
        //cargar el codigo
    }
    int opcion;
    do{
        opcion = menuUniversidad();
        switch( opcion ){
            case 0:
                std::cout << "Hasta pronto" << std::endl;
                break;
            case 1:
                javeriana.crearActa( contadorActa );
                break;
            case 2:
                std::cout << "2" << std::endl;
                break;
            case 3:
                std::cout << "3" << std::endl;
                break;
            case 4:
                std::cout << "4" << std::endl;
                break;
            case 5:
                std::cout << "5" << std::endl;
                break;
            case 6:
                std::cout << "6" << std::endl;
                break;
            default:
                //std::cout << "Cambios guardados con exito" << std::endl;
                std::cout << "Numero invalido, por favor ingresalo nuevamente" << std::endl;
                break;
        }
    }while( opcion != 0 );
    return 0;
}