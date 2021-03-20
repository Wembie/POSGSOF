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
    int opcionUniversidad;
    do{
        opcionUniversidad = menuUniversidad();
        switch( opcionUniversidad ){
            case 0:
                std::cout << "Hasta pronto" << std::endl;
                break;
            case 1:
                javeriana.crearActa( contadorActa );
                break;
            case 2:
                while( true ){
                    int idEditarActa, encontro = 0;
                    std::cout << "Digita el id del acta a editar: ";
                    std::cin >> idEditarActa;
                    for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
                        if( acta->getCodigo() == idEditarActa ){
                            javeriana.editarActa( *acta );
                            encontro = 1;
                            break;
                        }
                    }
                    if( encontro == 0 ){
                        std::cout << "Id invalido" << std::endl;
                    }
                    else if( encontro == 1){
                        break;
                    }
                }
                break;
            case 3:
                javeriana.crearProfesor();
                break;
            case 4:
                javeriana.crearEstudiante();
                break;
            case 5:
                javeriana.listarActas( menuListarActas() );
                break;
            case 6:
                javeriana.mostrarTodosLosProfesores();
                break;
            case 7:
                javeriana.mostrarTodosLosEstudiantes();
                break;
            default:
                //std::cout << "Cambios guardados con exito" << std::endl;
                std::cout << "Numero invalido, por favor ingresalo nuevamente" << std::endl;
                break;
        }
    }while( opcionUniversidad != 0 );
    return 0;
}