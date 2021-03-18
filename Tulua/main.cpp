#include <iostream>
#include "librerias/universidad.h"

menu menuNuevo; // Se instancia el menú

int main(){
    // Descomentar codigo cuando vaya a probar el mkdir y todo eso

    // if( encontrarDirectorio( "Actas" ) ){

    // }
    // else{
    //     mkdir( "Actas" );
    // }


    // Se repite el do while hasta que el usuario decida salir
    do{
        switch (menuNuevo.menuActa()) // Se llama la funcion menuActa() la cual retorna el numero escogido por el usuario
        {
        case 1:
        {
            // Parametros acta de grado
            int codigo; // To do - cargar el ultimo codigo del archivo de configuración
            std::string fechaHora, enfasis; // To do -  cargar automáticamente la fecha y la hora del sistema
            Estado estado = Estado::ABIERTO;
            Estudiante autor;
            Profesor director;
            Profesor coDirector;
            list<Profesor> jurados;
            list<Criterio> criterios;

            // Parametros estudiante
            int id, celular, semestre;
            std::string nombre, email, carrera;

            std::cout << "\n----- Crear nueva acta -----\n" << std::endl;
            std::cout << "Id del estudiante: ";
            std::cin >> id;
            std::cout << "Nombre del estudiante: ";
            std::cin >> nombre;
            std::cout << "Email del estudiante: ";
            std::cin >> email;
            std::cout << "Celular del estudiante: ";
            std::cin >> celular;
            std::cout << "Carrera del estudiante: ";
            std::cin >> carrera;
            std::cout << "Semestre del estudiante: ";
            std::cin >> semestre;
            autor = Estudiante(id, nombre, email, celular, carrera, semestre); // Se rellena el autor con los datos

            // Parametros director
            std::string cargo; 
            Tipo tipo = Tipo::INTERNO;

            std::cout << "\n----- Crear nueva acta -----\n" << std::endl;
            std::cout << "Id del director: ";
            std::cin >> id;
            std::cout << "Nombre del director: ";
            std::cin >> nombre;
            std::cout << "Celular del director: ";
            std::cin >> celular;
            std::cout << "Cargo del director: ";
            std::cin >> cargo;
            std::cout << "Email del director: ";
            std::cin >> email;
            
            director = Profesor(id, nombre, email, celular, cargo, tipo);

            std::cout << "Existe un codirector?: ";
            if(std::cin){
                // Parametros codirector
                std::cout << "Id del codirector: ";
                std::cin >> id;
                std::cout << "Nombre del codirector: ";
                std::cin >> nombre;
                std::cout << "Celular del codirector: ";
                std::cin >> celular;
                std::cout << "Cargo del codirector: ";
                std::cin >> cargo;
                std::cout << "Email del codirector: ";
                std::cin >> email;
                
                coDirector = Profesor(id, nombre, email, celular, cargo, tipo);
            }else{
                std::cout << "\nDe acuerdo" << std::endl;
            }

            // Rellenar lista jurados
            // to do - ciclo while para rellenar la lista con los jurados que se necesiten

                // Parametros jurados

            // Rellenar lista criterios
            // to do - ciclo while para rellenar la lista con los criterios que se necesiten

            Acta actaNueva(codigo, fechaHora, estado, autor, director, coDirector, enfasis, jurados, criterios);

            // to do - guardar acta como .json para continuar editando en un futuro

            break;
        }
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
            std::cout << "Cambios guardados con exito" << std::endl;
            std::cout << "Hasta pronto" << std::endl;
            break;
        }
    }while(menuNuevo.getOpcion() != 0);

    return 0;
}