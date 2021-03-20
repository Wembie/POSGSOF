#include "universidad.h"



//Constructor de Universidad
Universidad::Universidad( list<Acta> actas, list<Profesor> profesores, list<Estudiante> estudiantes ){
    this->nombre = "Pontificia Universidad Javeriana Cali";
    this->actas = actas;
    this->profesores = profesores;
    this->estudiantes = estudiantes;
}

//Metodo para crear un profesor
void Universidad::crearProfesor(){
    int id, celular, tipoProfe;
    std::string nombre, email, cargo;
    Tipo tipo;
    std::cout << "Digita el id del profesor a agregar: ";
    std::cin >> id;
    std::cout << "Digita el nombre del profesor a agregar: ";
    std::cin >> nombre;
    std::cout << "Digita el email del profesor a agregar: ";
    std::cin >> email;
    std::cout << "Digita el celular del profesor a agregar: ";
    std::cin >> celular;
    std::cout << "Digita el cargo del profesor a agregar: ";
    std::cin >> cargo;
    while( true ){
        std::cout << "Digita el tipo del profesor a agregar [ 0 = INTERNO, 1 = EXTERNO ]: ";
        std::cin >> tipoProfe;
        if( tipoProfe == INTERNO || tipo == EXTERNO ){
            if( tipoProfe == INTERNO ){
                tipo = INTERNO;
            }
            else if( tipoProfe == EXTERNO ){
                tipo = EXTERNO;
            }
            break;
        }
        else{
            std::cout << "Numero invalido, por favor ingresalo nuevamente" << std::endl;
        }
    }
    profesores.push_back( Profesor( id, nombre, email, celular, cargo, tipo ) );
}

//Metodo para crear un estudiante
void Universidad::crearEstudiante(){
    int id, celular, semestre;
    std::string nombre, email, carrera;
    std::cout << "Digita el id del estudiante a agregar: ";
    std::cin >> id;
    std::cout << "Digita el nombre del estudiante a agregar: ";
    std::cin >> nombre;
    std::cout << "Digita el email del estudiante a agregar: ";
    std::cin >> email;
    std::cout << "Digita el celular del estudiante a agregar: ";
    std::cin >> celular;
    std::cout << "Digita la carrera del estudiante a agregar: ";
    std::cin >> carrera;
    while( true ){
        std::cout << "Digita el semestre del estudiante a agregar: ";
        std::cin >> semestre;
        if( semestre <= 10 || semestre >= 1 ){
            break;
        }
        else{
            std::cout << "Numero invalido, por favor ingresalo nuevamente" << std::endl;
        }
    }
    
    estudiantes.push_back( Estudiante( id, nombre, email, celular, carrera, semestre ) );
}

//Metodo que retorna un criterio
Criterio Universidad::crearCriterio( int i ){
    std::string tema, observacion;
    float calificacion, ponderacion;
    std::cout << "Digita el tema del criterio " << i << ":" << std::endl;
    std::cin >> tema;
    while( true ){
        std::cout << "Digita el califacion del criterio: " << i << ":" << std::endl;
        std::cin >> calificacion;
        if( calificacion >= 0 || calificacion <= 5 ){
            break;
        }
        else{
            std::cout << "Calificacion invalida, por favor ingresalo nuevamente" << std::endl;
        }
    }
    std::cout << "Digita la ponderacion en % del criterio " << i << ":" << std::endl;
    std::cin >> ponderacion;
    std::cout << "Digita las observaciones del criterio " << i << ":" << std::endl;
    std::cin >> observacion;
    return Criterio( tema, calificacion, ponderacion, observacion );
}

//Metodo de crear una acta
void Universidad::crearActa( int codigo ){
    std::ofstream archivo;
    std::string codigoActa( std::to_string( codigo ) );
    archivo.open( "Actas/" + codigoActa, std::ios::out );
    if( archivo.fail() ){
        std::cout << "Nose pudo abrir el archivo";
        exit( 1 );
    }
    auto t = std::time( nullptr );
    auto tm = *std::localtime( &t );
    std::ostringstream oss;
    oss << std::put_time( &tm, "Fecha: %d-%m-%Y\nHora: %H:%M:%S" );
    auto fecha = oss.str();
    Estado estado;
    Estudiante autor;
    Profesor director;
    Profesor coDirector;
    int coDirectorActa;
    std::string enfasis;
    std::string modalidad;
    list<Profesor> jurados;
    list<Criterio> criterios;
    //Si la lista de los estudiantes de la U esta vacia entonces pregunta si desea
    //agregar un estudiante en dicha misma funcion
    if( estudiantes.empty() ){
        int respuestaAgregarNuevoEstudiante;
        while( true ){
            std::cout << "\nNo hay ningun estudiante en nuestra base de datos" << std::endl;
            std::cout << "Deseas agregar un nuevo estudiante ahora? [SI = 1, NO = 0]: ";
            std::cin >> respuestaAgregarNuevoEstudiante;
            if( respuestaAgregarNuevoEstudiante == 1 ){
                std::cout << "\n";
                crearEstudiante();
                break;
            }
            else if( respuestaAgregarNuevoEstudiante == 0 ){
                return;
            }
            else{
                std::cout << "\nNumero invalido, por favor ingresalo nuevamente" << std::endl;
            }
        }
    }
    //Si la lista de los profesores de la U esta vacia entonces pregunta si desea
    //agregar un profesor en dicha misma funcion
    if( profesores.empty() ){
        int respuestaAgregarNuevoProfesor;
        while( true ){
            std::cout << "\nNo hay ningun profesor en nuestra base de datos" << std::endl;
            std::cout << "Deseas agregar un nuevo profesor ahora? [SI = 1, NO = 0]: ";
            std::cin >> respuestaAgregarNuevoProfesor;
            if( respuestaAgregarNuevoProfesor == 1 ){
                std::cout << "\n";
                crearProfesor();
                break;
            }
            else if( respuestaAgregarNuevoProfesor == 0 ){
                return;
            }
            else{
                std::cout << "\nNumero invalido, por favor ingresalo nuevamente" << std::endl;
            }
        }
    }
    //Se pregunta por el id del estudiante y con ello lo agrega el autor del acta
    while( true ){
        int id, encontro = 0;
        std::cout << "Para agregar un autor a la acta digite su id: ";
        std::cin >> id;
        for( list<Estudiante>::iterator estudiante = estudiantes.begin(); estudiante != estudiantes.end(); estudiante++ ){
            if( estudiante->getId() == id ){
                autor = *estudiante;
                encontro = 1;
                std::cout << "Autor agregado exitosamente";
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
    //Se pregunta por el id del profesor y con ello lo agrega el director del acta
    while( true ){
        int decision;
        std::cout << "DIRECTOR" << std::endl;
        std::cout << "0. Agregar nuevo profesor\n1. Agregar existente\n2. Omitir";
        std::cout << "Digita el numero deseado: ";
        std::cin >> decision;
        if( decision == 0 ){
            std::cout << "\n";
            crearProfesor();
        }
        else if( decision == 1 ){
            while( true ){
                int id, encontro = 0;
                std::cout << "Para agregar un director a la acta digite su id: ";
                std::cin >> id;
                for( list<Profesor>::iterator profesor = profesores.begin(); profesor != profesores.end(); profesor++ ){
                    if( profesor->getId() == id && profesor->getTipo() == INTERNO ){
                        director = *profesor;
                        encontro = 1;
                        std::cout << "Director agregado exitosamente";
                        break;
                    }
                }
                if( encontro == 0 ){
                    std::cout << "Id invalido o no es interno" << std::endl;
                }
                else if( encontro == 1){
                    break;
                }
            }
            break;
        }
        else if( decision == 2 ){
            break;
        }
        else{
            std::cout << "\nNumero invalido, por favor ingresalo nuevamente" << std::endl;
        }
    }
    //En caso de que exista un co-director
    //Se pregunta por el id del profesor y con ello lo agrega el co-director del acta
    while( true ){
        int decision;
        std::cout << "CO-DIRECTOR" << std::endl;
        std::cout << "0. Agregar nuevo profesor\n1. Agregar existente\n2. Omitir";
        std::cout << "Digita el numero deseado: ";
        std::cin >> decision;
        if( decision == 0 ){
            std::cout << "\n";
            crearProfesor();
        }
        else if( decision == 1 ){
            while( true ){
                int existeCoDirector;
                std::cout << "Existe un Co-Director? [SI = 1, NO = 0]: ";
                std::cin >> existeCoDirector;
                if( existeCoDirector == 1 ){
                    while( true ){
                        int id, encontro = 0;
                        std::cout << "Para agregar un co-director a la acta digite su id: ";
                        std::cin >> id;
                        for( list<Profesor>::iterator profesor = profesores.begin(); profesor != profesores.end(); profesor++ ){
                            if( profesor->getId() == id && profesor->getTipo() == INTERNO ){
                                coDirector = *profesor;
                                encontro = 1;
                                break;
                            }
                        }
                        if( encontro == 0 ){
                            std::cout << "Id invalido o no interno" << std::endl;
                        }
                        else if( encontro == 1){
                            break;
                        }   
                    }
                    break;
                }
                else if( existeCoDirector == 0 ){
                    coDirectorActa = 1;
                    break;
                }
                else{
                    std::cout << "Numero invalido, por favor ingresalo nuevamente" << std::endl;
                }
            }            
            break;
        }
        else if( decision == 2 ){
            break;
        }
        else{
            std::cout << "\nNumero invalido, por favor ingresalo nuevamente" << std::endl;
        }
    }
    //Se pregunta por el enfasis del acta
    std::cout << "Digita el enfasis de la acta: ";
    std::cin >> enfasis;
    //Se pregunta por la modalidad del aca
    int modalidadActa;
    while( true ){
        std::cout << "Digita la modalidad de la acta [ APLICADO = 0, INVESTIGACION = 1 ]: ";
        std::cin >> modalidadActa;
        if( modalidadActa == 0 ){
            modalidad = "Aplicado";
            break;
        }
        else if( modalidadActa == 1 ){
            modalidad = "Investigacion";
            break;
        }
        else{
            std::cout << "Numero invalido, por favor ingresalo nuevamente" << std::endl;
        }
    }
    //Agregacion de los jurados
    while( true ){
        int decision;
        std::cout << "JURADOS" << std::endl;
        std::cout << "0. Agregar nuevo profesor\n1. Agregar existentes (2)\n2. Omitir";
        std::cout << "Digita el numero deseado: ";
        std::cin >> decision;
        if( decision == 0 ){
            std::cout << "\n";
            crearProfesor();
        }
        else if( decision == 1 ){
            int i, capacidadJurados = 2;
            for( i = 0; i < capacidadJurados; i++){
                while( true ){
                    int id, encontro = 0;
                    std::cout << "Para agregar el jurado " << i << " a la acta diga su id: ";
                    std::cin >> id;
                    for( list<Profesor>::iterator profesor = profesores.begin(); profesor != profesores.end(); profesor++ ){
                        if( profesor->getId() == id ){
                            jurados.push_back( *profesor );
                            encontro = 1;
                            std::cout << "Jurado agregado exitosamente";
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
            }
        }
        else if( decision == 2 ){
            break;
        }
        else{
            std::cout << "\nNumero invalido, por favor ingresalo nuevamente" << std::endl;
        }
    }
    //Agregacion de los criterios
    while( true ){
        int decision;
        std::cout << "CRITERIOS" << std::endl;
        std::cout << "0. Agregar Criterios (2)\n1. Omitir";
        std::cout << "Digita el numero deseado: ";
        std::cin >> decision;
        if( decision == 0 ){
            int i, cuantosCriterosParaAgregar;
            while( true ){
                std::cout << "Cuantos criterios deseas agregar al acta?: ";
                std::cin >> cuantosCriterosParaAgregar;
                if( cuantosCriterosParaAgregar > 0 ){
                    break;
                }
                else{
                    std::cout << "La cantidad de criterios debe ser mayor a 0" << std::endl;
                }
            }
            for( i = 0; i < cuantosCriterosParaAgregar; i++){
                criterios.push_back( crearCriterio( i ) );
            }
        }
        else if( decision == 1 ){
            break;
        }
        else{
            std::cout << "\nNumero invalido, por favor ingresalo nuevamente" << std::endl;
        }
    }
    //Se pregunta el estado del acta
    int estadoActa;
    while( true ){
        std::cout << "Digita el estado de la acta: ";
        std::cin >> estadoActa; 
        if( estadoActa == CERRADA || estadoActa == ABIERTA || estadoActa == PENDIENTE ){
            if( estadoActa == CERRADA ){
                estado = CERRADA;
            }
            else if( estadoActa == ABIERTA ){
                estado = ABIERTA;
            }
            else if( estadoActa == PENDIENTE ){
                estado = PENDIENTE;
            }
            break;
        }
        else{
            std::cout << "Numero invalido, por favor ingresalo nuevamente" << std::endl;
        }
    }
    //Verificacion si hay un codirector o no
    if( coDirectorActa == 0){
        actas.push_back( Acta( codigo, fecha, estado, autor, director, enfasis, modalidad, jurados, criterios ) );
    }
    else if( coDirectorActa == 1 ){
        actas.push_back( Acta( codigo, fecha, estado, autor, director, coDirector, enfasis, modalidad, jurados, criterios ) );
    }  
   
}

//Metodo para editar un acta
void Universidad::editarActa( int codigo ){

}

//Metodo para eliminar un acta
void Universidad::eliminarActa(){
    int codigoActa;
    std::cout << "Digita el codigo del acta a eliminar: ";
    std::cin >> codigoActa;
    if( actas.size() != 0 ){
        for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
            if( acta->getEstado() != CERRADA && acta->getCodigo() == codigoActa ){
                acta->~Acta();
                std::cout << "Acta con codigo " << codigoActa << " Eliminada" << std::endl;
            }
            else{
                std::cout << "Acta con codigo " << codigoActa << " No puede ser Eliminada" << std::endl;
                std::cout << "Ya que esta cerrada" << std::endl;
            }
        }
    }
    else{
        std::cout << "\nNo hay ninguna acta registrada por el momento." << std::endl;
    }
}

//Metodo para mostrar todas las actas
void Universidad::mostrarTodasLasActas(){
    if( actas.size() != 0 ){
        for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
            acta->mostrarActa();
        }
    }
    else{
        std::cout << "\nNo hay ninguna acta registrada por el momento." << std::endl;
    }
    
}

//Metodo para mostrar todos los profesores
void Universidad::mostrarTodosLosProfesores(){
    if( profesores.size() != 0 ){
        for( list<Profesor>::iterator profesor = profesores.begin(); profesor != profesores.end(); profesor++ ){
            profesor->mostrarProfesor();
        }
    }
    else{
        std::cout << "\nNo hay ningun profesor registrado por el momento." << std::endl;
    }
}

//Metodo para mostrar todos los estudiantes
void Universidad::mostrarTodosLosEstudiante(){
    if( estudiantes.size() != 0 ){
        for( list<Estudiante>::iterator estudiante = estudiantes.begin(); estudiante != estudiantes.end(); estudiante++ ){
            estudiante->mostrarEstudiante();
        }
}
    else{
        std::cout << "\nNo hay ninguna estudiante registrado por el momento." << std::endl;
    }
}