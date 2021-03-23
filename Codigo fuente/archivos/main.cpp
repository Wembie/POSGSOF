#include <iostream>
#include "../librerias/universidad.h"

int main(){
    list<Acta> actas;
    list<Profesor> profesores;
    list<Estudiante> estudiantes;
    Universidad javeriana( actas, profesores, estudiantes );
    int contadorActa = 2;
    // Pruebas con directorios para crearlo si no existe
    if( encontrarDirectorio( "actas" ) ){
        //guardar el codigo
    }
    else{
        mkdir( "actas" );
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
                switch ( menuConsultarActas() ) {
                    case 0:
                        break;
                    case 1:
                        javeriana.consultarActas( static_cast<EstadoActaCerrada>( 1 ) );
                        break;
                    case 2:
                        javeriana.consultarActas( static_cast<EstadoActaCerrada>( 2 ) );
                        break;
                    default:
                      std::cout << "\bLo sentimos, ingresa un numero entre 0 y 2";
                }
            case 9:
                switch ( menuConsultarJurados() ) {
                    case 0:
                        break;
                    case 1:
                        javeriana.consultarJurados( static_cast<Tipo>( 0 ) );
                        break;
                    case 2:
                        javeriana.consultarJurados( static_cast<Tipo>( 1 ) );
                        break;
                    default:
                      std::cout << "\bLo sentimos, ingresa un numero entre 0 y 2";
                }
            case 10:
                {
                    int codigo;
                    std::cout << "\nDigite el codigo del acta con los criterios a listar: ";
                    std::cin >> codigo;
                    javeriana.listarCriterios( codigo );
                    break;
                }
            case 69:
                javeriana.sorpresa();
            case 666:
                // Simplemente belfegor
                javeriana.elDiablo();
                break;
            default:
                // Comentado por si alcanzamos a hacer la funcionalidad de guardar
                //std::cout << "Cambios guardados con exito" << std::endl;
                std::cout << "\nCodigo invalido, por favor ingresalo nuevamente" << std::endl;
                break;
        }
    }while( opcionUniversidad != 0 );
    return 0;
}
