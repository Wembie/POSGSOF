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
                      std::cout << "Lo sentimos, ingresa un numero entre 0 y 6";
                }
                break;
            case 3:
                if( !javeriana.getActas().empty() ){
                    while( true ){
                        int idEditarActa, encontro = 0;
                        std::cout << "\nDigita el codigo del acta a editar [ CANCELAR = 0 ]: ";
                        std::cin >> idEditarActa;
                        if( idEditarActa != 0 ){
                            if( javeriana.getActas().size() > 1 ){
                                for( list<Acta>::iterator acta = javeriana.getActas().begin(); acta != javeriana.getActas().end(); acta++ ){
                                    if( acta->getCodigo() == idEditarActa ){
                                        javeriana.editarActa( *acta );
                                        encontro = 1;
                                        break;
                                    }
                                }
                                if( encontro == 0 ){
                                    std::cout << "Codigo invalido, por favor ingresalo nuevamente" << std::endl;
                                }
                                else if( encontro == 1){
                                    break;
                                }
                            }else{
                                if( javeriana.getActas().begin()->getCodigo() == idEditarActa ){
                                    javeriana.editarActa( *javeriana.getActas().begin() );
                                    break;
                                }
                            }
                        }else{
                            break;
                        }
                    }
                }else{
                    std::cout << "\nLo sentimos, la lista de actas esta vacia" << std::endl;
                }
                break;
            case 4:
            {
                if( !javeriana.getActas().empty() ){
                    int idActa;
                    std::cout << "Digita el codigo del acta a calcular la calificacion [ CANCELAR = 0 ]: ";
                    std::cin >> idActa;
                    if( idActa != 0 ){
                        javeriana.calcularCalificacion( idActa );
                    }
                    break;
                }else{
                    std::cout << "\nLo sentimos, la lista de actas esta vacia, Size: " << javeriana.getActas().size() << std::endl;
                }
                break;
            }
            case 666:
                javeriana.elDiablo();
                break;
            default:
                //std::cout << "Cambios guardados con exito" << std::endl;
                std::cout << "codigo invalido, por favor ingresalo nuevamente" << std::endl;
                break;
        }
    }while( opcionUniversidad != 0 );
    return 0;
}
