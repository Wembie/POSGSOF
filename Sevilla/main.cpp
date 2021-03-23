#include <iostream>
#include "universidad.h"

int main(){
    list<Acta> actas;
    list<Profesor> profesores;
    list<Estudiante> estudiantes;
    Universidad javeriana( actas, profesores, estudiantes );
    int contadorActa = 2;
    if( encontrarDirectorio( "Actas" ) ){
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
                std::cout << "\nHasta pronto";
                break;
            case 1:
                switch ( menuCrear() ) {
                    case 0:
                        break;
                    case 1:
                        javeriana.crearActa( contadorActa );
                        break;
                    case 2:
                        javeriana.crearProfesor();
                        break;
                    case 3:
                        javeriana.crearEstudiante();
                        break;
                    default:
                        std::cout << "Lo sentimos, ingresa un numero entre 0 y 3";
                }
                break;
            case 2:
                switch ( menuListar() ) {
                    case 0:
                        break;
                    case 1:
                        javeriana.listarActas( menuListarActas() );
                        break;
                    case 2:
                        javeriana.mostrarTodosLosProfesores();
                        break;
                    case 3:
                        javeriana.mostrarTodosLosEstudiantes();
                        break;
                    default:
                      std::cout << "\bLo sentimos, ingresa un numero entre 0 y 3";
                }
                break;
            case 3:
                javeriana.editarActa();
                break;
            case 4:{
                if( !javeriana.getActas().empty() ){
                    int idActa;
                    std::cout << "Digita el codigo del acta a calcular la calificacion [ CANCELAR = 0 ]: ";
                    std::cin >> idActa;
                    if( idActa != 0 ){
                        javeriana.calcularCalificacion( idActa );
                    }
                    break;
                }
                else{
                    std::cout << "\nLo sentimos, la lista de actas esta vacia" << std::endl;
                }
                break;
            }
            case 5:
                javeriana.eliminarActa();
                break;
            case 6:
                javeriana.cerrarActa();
                break;
            case 7:
                javeriana.exportarActa();
                break;
            case 8:
                {
                    int opcion;
                    do {
                        std::cout << "\n---------- Consultar actas ----------\n" << std::endl;
                        std::cout << "1. Consultar actas rechazadas" << std::endl;
                        std::cout << "2. Consultar actas pendientes" << std::endl;
                        std::cout << "0. Atras" << std::endl;
                        std::cout << "\nDigita el numero: ";
                        std::cin >> opcion;
                        if( opcion != 0 ){
                            javeriana.consultarActas( static_cast<EstadoActaCerrada>( opcion ) );
                        }
                    } while( opcion != 0 );
                    break;
                }
            case 9:
                {
                    int opcion;
                    do {
                        std::cout << "\n---------- Consultar jurados ----------\n" << std::endl;
                        std::cout << "1. Consultar jurados internos" << std::endl;
                        std::cout << "2. Consultar jurados externos" << std::endl;
                        std::cout << "0. Atras" << std::endl;
                        std::cout << "\nDigita el numero: ";
                        std::cin >> opcion;
                        if( opcion != 0 ){
                            javeriana.consultarJurados( static_cast<Tipo>( opcion - 1 ) );
                        }
                    } while( opcion != 0 );
                    break;
                }
            case 10:
                {
                    int codigo;
                    std::cout << "\nDigite el codigo del acta con los criterios a listar: ";
                    std::cin >> codigo;
                    javeriana.listarCriterios( codigo );
                    break;
                }
            case 666:
                javeriana.elDiablo();
                break;
            default:
                //std::cout << "Cambios guardados con exito" << std::endl;
                std::cout << "\nCodigo invalido, por favor ingresalo nuevamente" << std::endl;
                break;
        }
    }while( opcionUniversidad != 0 );
    return 0;
}
