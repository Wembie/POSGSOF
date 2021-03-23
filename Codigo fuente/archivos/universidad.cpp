#include "../librerias/universidad.h"

//Constructor de Universidad
Universidad::Universidad( list<Acta> actas, list<Profesor> profesores, list<Estudiante> estudiantes ){
    this->nombre = "Pontificia Universidad Javeriana Cali";
    this->actas = actas;
    this->profesores = profesores;
    this->estudiantes = estudiantes;
}

//Metodo para crear un profesor
void Universidad::crearProfesor(){
    int id, tipoProfe;
    std::string nombre, celular, email, cargo;
    Tipo tipo;
    while( true ){
        int seRepite = 0;
        std::cout << "Digita el id del profesor a agregar: ";
        std::cin >> id;
        if( id != 0 ){
            // Se recorre la lista de los profesores para verificar que no exista previamente el id digitado
            for( list<Profesor>::iterator profesor = profesores.begin(); profesor != profesores.end(); profesor++ ){
                if( profesor->getId() == id ){
                    seRepite = 1;
                    std::cout << "\nYa hay un profesor registrado con este id, por favor digita uno diferente\n";
                    break;
                }
            }
            if( seRepite == 0 ){
                break;
            }
        }else{
            std::cout << "\nEl id debe de ser diferente de 0\n";
        }
    }
    std::cout << "Digita el nombre del profesor a agregar: ";
    std::cin >> nombre;
    std::cout << "Digita el email del profesor a agregar: ";
    std::cin >> email;
    std::cout << "Digita el celular del profesor a agregar: ";
    std::cin >> celular;
    std::cout << "Digita el cargo del profesor a agregar: ";
    std::cin >> cargo;
    while( true ){
        std::cout << "Digita el tipo del profesor a agregar [ INTERNO = 0, EXTERNO = 1 ]: ";
        std::cin >> tipoProfe;
        if( tipoProfe == 0 || tipoProfe == 1 ){
            tipo = static_cast<Tipo>( tipoProfe );
            break;
        }else{
            std::cout << "\nNumero invalido, por favor ingresalo nuevamente" << std::endl;
        }
    }
    // Luego de pedir y almacenar temporalmente los datos del docente
    // se crea un nuevo objeto de la clase Profesor y se almacena en la lista de la universidad
    profesores.push_back( Profesor( id, nombre, email, celular, cargo, tipo ) );
    std::cout << "\nProfesor agregado exitosamente" << std::endl;
}

//Metodo para crear un estudiante
void Universidad::crearEstudiante(){
    int id, semestre;
    std::string nombre, celular, email, carrera;
    while( true ){
        int seRepite = 0;
        std::cout << "Digita el id del estudiante a agregar: ";
        std::cin >> id;
        if( id != 0 ){
            // Se recorre la lista de los estudiantes para verificar que no exista previamente el id digitado
            for( list<Estudiante>::iterator estudiante = estudiantes.begin(); estudiante != estudiantes.end(); estudiante++ ){
                if( estudiante->getId() == id ){
                    seRepite = 1;
                    std::cout << "\nYa hay un estudiante registrado con este id, por favor digita uno diferente\n";
                    break;
                }
            }
            if( seRepite == 0 ){
                break;
            }
        }else{
            std::cout << "\nEl id debe de ser diferente de 0\n";
        }
    }
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

    // Luego de pedir y almacenar temporalmente los datos del estudiante
    // se crea un nuevo objeto de la clase Estudiante y se almacena en la lista de la universidad
    estudiantes.push_back( Estudiante( id, nombre, email, celular, carrera, semestre ) );
    std::cout << "\nEstudiante agregado exitosamente" << std::endl;
}

//Metodo que retorna un criterio
Criterio Universidad::crearCriterio( int i ){
    std::string tema, observacion;
    float calificacion, ponderacion;
    std::cout << "\nDigita el tema del criterio " << i + 1 << ": ";
    std::cin >> tema;
    while( true ){
        std::cout << "Digita el califacion del criterio " << i + 1 << ": ";
        std::cin >> calificacion;
        if( calificacion >= 0 && calificacion <= 5 ){
            break;
        }
        else{
            std::cout << "\nCalificacion invalida, por favor ingresalo nuevamente" << std::endl;
        }
    }
    std::cout << "Digita la ponderacion en % del criterio " << i + 1 << ": ";
    std::cin >> ponderacion;
    std::cout << "Digita las observaciones del criterio " << i + 1 << ": ";
    std::cin >> observacion;

    // Se retorna un objeto de la clase criterio con los parametros previa y temporalmente almacenados
    return Criterio( tema, calificacion, ponderacion, observacion );
}

//Metodo de crear una acta
void Universidad::crearActa( int codigo ){
    // Intento de serializacion de actas
    /*std::ofstream archivo;
    std::string codigoActa( std::to_string( codigo ) );
    archivo.open( "Actas/" + codigoActa, std::ios::out );
    if( archivo.fail() ){
        std::cout << "Nose pudo abrir el archivo";
        exit( 1 );
    }*/
    //Fecha
    auto t = std::time( nullptr );
    auto tm = *std::localtime( &t );
    std::ostringstream oss;
    oss << std::put_time( &tm, "Fecha: %d-%m-%Y\nHora: %H:%M:%S" );
    auto fecha = oss.str();
    Estado estado;
    Estudiante autor;
    int idDirector = 0;
    Profesor director;
    int idCoDirector = 0;
    Profesor coDirector;
    int coDirectorActa;
    std::string enfasis;
    std::string modalidad;
    int idJurado1 = 0;
    int idJurado2 = 0;
    list<Profesor> jurados;
    list<Criterio> criterios;
    //Si la lista de los estudiantes de la U esta vacia entonces pregunta si desea
    //agregar un estudiante en dicha misma funcion
    if( estudiantes.empty() ){
        int respuestaAgregarNuevoEstudiante;
        while( true ){
            std::cout << "\nNo hay ningun estudiante en nuestra base de datos" << std::endl;
            std::cout << "\nDeseas agregar un nuevo estudiante ahora? [SI = 1, NO = 0]: ";
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
    // Si la lista de los profesores de la U esta vacia entonces pregunta si desea
    // agregar un profesor dentro de la misma funcion
    if( profesores.empty() ){
        int respuestaAgregarNuevoProfesor;
        while( true ){
            std::cout << "\nNo hay ningun profesor en nuestra base de datos" << std::endl;
            std::cout << "\nDeseas agregar un nuevo profesor ahora? [SI = 1, NO = 0]: ";
            std::cin >> respuestaAgregarNuevoProfesor;
            if( respuestaAgregarNuevoProfesor == 1 ){
                std::cout << "\n";
                crearProfesor(); // Se crea el nuevo profesor y se agrega a la lista
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
                std::cout << "\nAutor agregado exitosamente\n";
                break;
            }
        }
        if( encontro == 0 ){
            std::cout << "\nId invalido\n" << std::endl;
        }
        else if( encontro == 1){
            break;
        }
    }
    //Se pregunta por el id del profesor y con ello lo agrega el director del acta
    while( true ){
        int decision;
        std::cout << "\nDIRECTOR" << std::endl;
        std::cout << "\n1. Agregar nuevo profesor\n2. Agregar existente\n0. Omitir\n\n";
        std::cout << "Digita el numero deseado: ";
        std::cin >> decision;
        if( decision == 1 ){
            std::cout << "\n";
            crearProfesor();
        }
        else if( decision == 2 ){
            while( true ){
                int encontro = 0;
                std::cout << "\nPara agregar un director a la acta digite su id: ";
                std::cin >> idDirector;
                // Se verifica que exista el profesor a buscar y que ademas sea de tipo INTERNO
                for( list<Profesor>::iterator profesor = profesores.begin(); profesor != profesores.end(); profesor++ ){
                    if( profesor->getId() == idDirector && profesor->getTipo() == INTERNO ){
                        director = *profesor;
                        encontro = 1;
                        std::cout << "\nDirector agregado exitosamente";
                        break;
                    }
                }
                if( encontro == 0 ){
                    std::cout << "\nId invalido o no es interno\n" << std::endl;
                }
                else if( encontro == 1){
                    break;
                }
            }
            break;
        }
        else if( decision == 0 ){
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
        std::cout << "\n\nCO-DIRECTOR" << std::endl;
        std::cout << "\n1. Agregar nuevo profesor\n2. Agregar existente\n0. Omitir\n\n";
        std::cout << "Digita el numero deseado: ";
        std::cin >> decision;
        if( decision == 1 ){
            std::cout << "\n";
            crearProfesor();
        }
        else if( decision == 2 ){
            while( true ){
                int existeCoDirector;
                std::cout << "Existe un Co-Director? [SI = 1, NO = 0]: ";
                std::cin >> existeCoDirector;
                if( existeCoDirector == 1 ){
                    while( true ){
                        int id, encontro = 0;
                        std::cout << "Para agregar un co-director a la acta digite su id [ CANCELAR = 0 ]: ";
                        std::cin >> idCoDirector;
                        if( idCoDirector == 0 ){
                            break;
                        }
                        if( idDirector != 0 && idCoDirector != idDirector ){
                            // Se verifica que exista el profesor a buscar y que ademas sea de tipo INTERNO
                            for( list<Profesor>::iterator profesor = profesores.begin(); profesor != profesores.end(); profesor++ ){
                                if( profesor->getId() == idCoDirector && profesor->getTipo() == INTERNO ){
                                    coDirector = *profesor;
                                    encontro = 1;
                                    break;
                                }
                            }
                            if( encontro == 0 ){
                                std::cout << "\nId invalido o no interno\n" << std::endl;
                            }
                            else if( encontro == 1){
                                break;
                            }
                        }
                        else{
                            std::cout << "\nEl id del codirector no puede ser igual al id del director\n" << std::endl;
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
        else if( decision == 0 ){
            coDirectorActa = 0;
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
        std::cout << "\nJURADOS" << std::endl;
        std::cout << "\n1. Agregar nuevo profesor\n2. Agregar existentes (2)\n0. Omitir\n\n";
        std::cout << "Digita el numero deseado: ";
        std::cin >> decision;
        if( decision == 1 ){
            std::cout << "\n";
            crearProfesor();
        }
        else if( decision == 2 ){
            int i, capacidadJurados = 2;
            for( i = 0; i < capacidadJurados; i++){
                while( true ){
                    int id, encontro = 0;
                    std::cout << "\nPara agregar el jurado " << i + 1 << " a la acta diga su id [ CANCELAR = 0 ]: ";
                    if( i == 0 ){
                        std::cin >> idJurado1;
                        if( idJurado1 == 0 ){
                            i = 2;
                            break;
                        }
                        if( idDirector != 0 && idDirector != idJurado1 ){
                            if( idCoDirector != 0 && idCoDirector != idJurado1 ){
                                // Se recorre la lista de profesores y si se encuentra el profesor con un id igual al buscado se agrega como nuevo jurado
                                for( list<Profesor>::iterator profesor = profesores.begin(); profesor != profesores.end(); profesor++ ){
                                    if( profesor->getId() == idJurado1 ){
                                        jurados.push_back( *profesor );
                                        encontro = 1;
                                        std::cout << "\nJurado agregado exitosamente\n";
                                        break;
                                    }
                                }
                                if( encontro == 0 ){
                                    std::cout << "\nId invalido\n" << std::endl;
                                }
                                else if( encontro == 1){
                                    break;
                                }
                            }
                            else{
                                std::cout << "\nEl id del jurado 1 no puede ser igual al id del co-director\n";
                            }
                        }
                        else{
                            std::cout << "\nEl id del jurado 1 no puede ser igual al id del director\n";
                        }
                    }
                    else{
                        std::cin >> idJurado2;
                        if( idJurado2 == 0 ){
                            jurados.pop_back();
                            break;
                        }
                        if( idDirector != 0 && idDirector != idJurado2 ){
                            if( idCoDirector != 0 && idCoDirector != idJurado2 ){
                                if( idJurado1 != 0 && idJurado1 != idJurado2 ){
                                    for( list<Profesor>::iterator profesor = profesores.begin(); profesor != profesores.end(); profesor++ ){
                                        if( profesor->getId() == idJurado2 ){
                                            jurados.push_back( *profesor );
                                            encontro = 1;
                                            std::cout << "\nJurado agregado exitosamente\n";
                                            break;
                                        }
                                    }
                                    if( encontro == 0 ){
                                        std::cout << "\nId invalido\n" << std::endl;
                                    }
                                    else if( encontro == 1){
                                        break;
                                    }
                                }
                                else{
                                    std::cout << "\nEl id del jurado 2 no puede ser igual al id del jurado 1\n";
                                }
                            }
                            else{
                                std::cout << "\nEl id del jurado 2 no puede ser igual al id del co-director\n";
                            }
                        }
                        else{
                            std::cout << "\nEl id del jurado 2 no puede ser igual al id del director\n";
                        }
                    }
                }
            }
            break;
        }
        else if( decision == 0 ){
            break;
        }
        else{
            std::cout << "\nNumero invalido, por favor ingresalo nuevamente" << std::endl;
        }
    }
    //Agregacion de los criterios
    while( true ){
        int decision;
        std::cout << "\nCRITERIOS" << std::endl;
        std::cout << "\n1. Agregar criterios\n0. Omitir\n\n";
        std::cout << "Digita el numero deseado: ";
        std::cin >> decision;
        if( decision == 1 ){
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
                // Se crean los criterios a la vez que se agregan a la lista
                criterios.push_back( crearCriterio( i ) );
            }
        }
        else if( decision == 0 ){
            break;
        }
        else{
            std::cout << "\nNumero invalido, por favor ingresalo nuevamente" << std::endl;
        }
    }
    //Se pregunta el estado del acta [ COMENTADO PORQUE CREÍMOS QUE NO ERA PERTINENTE AL CREAR UN ACTA ]
    /*int estadoActa;
    while( true ){
        std::cout << "Digita el estado del acta [ CERRADA = 0, ABIERTA = 1 ]: ";
        std::cin >> estadoActa;
        if( estadoActa == CERRADA || estadoActa == ABIERTA ){
            if( estadoActa == CERRADA ){
                estado = CERRADA;
            }
            else if( estadoActa == ABIERTA ){
                estado = ABIERTA;
            }
            break;
        }
        else{
            std::cout << "Numero invalido, por favor ingresalo nuevamente" << std::endl;
        }
    }*/
    // Verificacion si hay un codirector o no
    // Se crea el acta con o sin co-director
    if( coDirectorActa == 0 ){
        actas.push_back( Acta( codigo, fecha, ABIERTA, PENDIENTE, autor, director, enfasis, modalidad, jurados, criterios ) );
    }
    else if( coDirectorActa == 1 ){
        actas.push_back( Acta( codigo, fecha, ABIERTA, PENDIENTE, autor, director, coDirector, enfasis, modalidad, jurados, criterios ) );
    }
    std::cout << "\nActa creada correctamente" << std::endl;
}

//Metodo para editar un acta
void Universidad::editarActa(){
    if( !actas.empty() ){
        while( true ){
            int idEditarActa, encontro = 0;
            std::cout << "\nDigita el codigo del acta a editar [ CANCELAR = 0 ]: ";
            std::cin >> idEditarActa;
            // Se verifica que el id no sea 0 ya que es la opcion para cancelar
            if( idEditarActa != 0 ){
                for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
                    // Se busca el acta con estado ABIERTA, de lo contrario no se podría editar
                    if( acta->getCodigo() == idEditarActa && acta->getEstado() == ABIERTA ){
                        int opcionActa;
                        int coDirectorActa;
                        Profesor directorEditar = acta->getDirector();
                        Profesor coDirectorEditar = acta->getCoDirector();
                        list<Profesor> juradosEditar = acta->getJurados();
                        int idDirector = directorEditar.getId(), idCoDirector = coDirectorEditar.getId(), idJurado1, idJurado2, i = 0;
                        for( list<Profesor>::iterator profesor = juradosEditar.begin(); profesor != juradosEditar.end(); profesor++ ){
                            if( i == 0 ){
                                idJurado1 = profesor->getId();
                            }
                            else{
                                idJurado2 = profesor->getId();
                            }
                            i++;
                        }
                        do{
                            acta->mostrarActa();
                            opcionActa = menuActa();
                            switch( opcionActa ){
                                case 0:{
                                    return;
                                }
                                case 1:{ //Fecha
                                    auto t = std::time( nullptr );
                                    auto tm = *std::localtime( &t );
                                    std::ostringstream oss;
                                    oss << std::put_time( &tm, "Fecha: %d-%m-%Y\nHora: %H:%M:%S" );
                                    auto fecha = oss.str();
                                    acta->setFechaHora( fecha );
                                    std::cout << "\nFecha y Hora cambiadas" << std::endl;
                                    break;
                                }
                                case 2:{ //Estado
                                    int estadoActa;
                                    while( true ){
                                        std::cout << "Digita el estado del acta a editar [ CERRADA = 0, ABIERTA = 1 ]: ";
                                        std::cin >> estadoActa;
                                        if( estadoActa == 0 && estadoActa == 1 ){
                                            acta->setEstado( static_cast<Estado>( estadoActa ) );
                                            break;
                                        }else{
                                            std::cout << "\nNumero invalido, por favor ingresalo nuevamente" << std::endl;
                                        }
                                    }
                                    std::cout << "\nEstado cambiado" << std::endl;
                                    break;
                                }
                                case 3:{ //Autor
                                    while( true ){
                                        int id, encontro = 0;
                                        std::cout << "Para editar un autor a la acta digite su id: ";
                                        std::cin >> id;
                                        for( list<Estudiante>::iterator estudiante = estudiantes.begin(); estudiante != estudiantes.end(); estudiante++ ){
                                            if( estudiante->getId() == id ){
                                                acta->setAutor( *estudiante );
                                                encontro = 1;
                                                std::cout << "\nAutor agregado exitosamente\n";
                                                break;
                                            }
                                        }
                                        if( encontro == 0 ){
                                            std::cout << "\nId invalido\n" << std::endl;
                                        }
                                        else if( encontro == 1){
                                            break;
                                        }
                                    }
                                    std::cout << "\nAutor cambiado" << std::endl;
                                    break;
                                }
                                case 4:{ //Director
                                    while( true ){
                                        int decision;
                                        std::cout << "\nDIRECTOR" << std::endl;
                                        std::cout << "\n1. Agregar nuevo profesor\n2. Agregar existente\n0. Omitir\n\n";
                                        std::cout << "Digita el numero deseado: ";
                                        std::cin >> decision;
                                        if( decision == 1 ){
                                            std::cout << "\n";
                                            crearProfesor();
                                        }
                                        else if( decision == 2 ){
                                            while( true ){
                                                int encontro = 0;
                                                std::cout << "\nPara agregar un director a la acta digite su id: ";
                                                std::cin >> idDirector;
                                                // Realiza todas las verificaciones correspondientes para que no se repitan los profesores en los roles del acta
                                                if( idCoDirector != 0 && idDirector != idCoDirector ){
                                                    if( idJurado1 != 0 && idDirector != idJurado1 ){
                                                        if( idJurado2 != 0 && idDirector != idJurado2 ){
                                                            for( list<Profesor>::iterator profesor = profesores.begin(); profesor != profesores.end(); profesor++ ){
                                                                if( profesor->getId() == idDirector && profesor->getTipo() == INTERNO ){
                                                                    acta->setDirector( *profesor );
                                                                    encontro = 1;
                                                                    std::cout << "\nDirector agregado exitosamente";
                                                                    break;
                                                                }
                                                            }
                                                            if( encontro == 0 ){
                                                                std::cout << "\nId invalido o no es interno\n" << std::endl;
                                                            }
                                                            else if( encontro == 1){
                                                                break;
                                                            }
                                                        }
                                                        else{
                                                            std::cout << "\nEl id del director no puede ser igual al id del jurado 2" << std::endl;
                                                        }
                                                    }
                                                    else{
                                                        std::cout << "\nEl id del director no puede ser igual al id del jurado 1" << std::endl;
                                                    }
                                                }
                                                else{
                                                    std::cout << "\nEl id del director no puede ser igual al id del codirector" << std::endl;
                                                }
                                            }
                                            break;
                                        }
                                        else if( decision == 0 ){
                                            break;
                                        }
                                        else{
                                            std::cout << "\nNumero invalido, por favor ingresalo nuevamente" << std::endl;
                                        }
                                    }
                                    std::cout << "\nDirector cambiado" << std::endl;
                                    break;
                                }
                                case 5:{ //Co-Director
                                    while( true ){
                                        int decision;
                                        std::cout << "\n\nCO-DIRECTOR" << std::endl;
                                        std::cout << "\n1. Agregar nuevo profesor\n2. Agregar existente\n0. Omitir\n\n";
                                        std::cout << "Digita el numero deseado: ";
                                        std::cin >> decision;
                                        if( decision == 1 ){
                                            std::cout << "\n";
                                            crearProfesor();
                                        }
                                        else if( decision == 2 ){
                                            while( true ){
                                                int existeCoDirector;
                                                std::cout << "Existe un Co-Director? [SI = 1, NO = 0]: ";
                                                std::cin >> existeCoDirector;
                                                if( existeCoDirector == 1 ){
                                                    while( true ){
                                                        int id, encontro = 0;
                                                        std::cout << "Para agregar un co-director a la acta digite su id: ";
                                                        std::cin >> idCoDirector;
                                                        // Realiza todas las verificaciones correspondientes para que no se repitan los profesores en los roles del acta
                                                        if( idDirector != 0 && idCoDirector != idDirector ){
                                                            if( idJurado1 != 0 && idCoDirector != idJurado1 ){
                                                                if( idJurado2 != 0 && idCoDirector != idJurado2 ){
                                                                    for( list<Profesor>::iterator profesor = profesores.begin(); profesor != profesores.end(); profesor++ ){
                                                                        if( profesor->getId() == idCoDirector && profesor->getTipo() == INTERNO ){
                                                                            acta->setCoDirector( *profesor );
                                                                            acta->setCoDirectorActa( "Si" );
                                                                            encontro = 1;
                                                                            break;
                                                                        }
                                                                    }
                                                                    if( encontro == 0 ){
                                                                        std::cout << "\nId invalido o no interno\n" << std::endl;
                                                                    }
                                                                    else if( encontro == 1){
                                                                        break;
                                                                    }
                                                                }
                                                                else{
                                                                    std::cout << "\nEl id del codirector no puede ser igual al id del jurado 2" << std::endl;
                                                                }
                                                            }
                                                            else{
                                                                std::cout << "\nEl id del codirector no puede ser igual al id del jurado 1" << std::endl;
                                                            }
                                                        }
                                                        else{
                                                            std::cout << "\nEl id del codirector no puede ser igual al id del director" << std::endl;
                                                        }
                                                    }
                                                    break;
                                                }
                                                else if( existeCoDirector == 0 ){
                                                    acta->setCoDirectorActa( "N/A" );
                                                    break;
                                                }
                                                else{
                                                    std::cout << "\nNumero invalido, por favor ingresalo nuevamente" << std::endl;
                                                }
                                            }
                                            break;
                                        }
                                        else if( decision == 0 ){
                                            coDirectorActa = 0;
                                            break;
                                        }
                                        else{
                                            std::cout << "\nNumero invalido, por favor ingresalo nuevamente" << std::endl;
                                        }
                                    }
                                    std::cout << "\nCo-Director cambiado" << std::endl;
                                    break;
                                }
                                case 6:{ //Enfasis
                                    std::string enfasis;
                                    std::cout << "Digita el enfasis de la acta: ";
                                    std::cin >> enfasis;
                                    acta->setEnfasis( enfasis );
                                    std::cout << "\nEnfasis cambiada" << std::endl;
                                    break;
                                }
                                case 7:{ //Modalidad
                                    int modalidadActa;
                                    while( true ){
                                        std::cout << "Digita la modalidad de la acta [ APLICADO = 0, INVESTIGACION = 1 ]: ";
                                        std::cin >> modalidadActa;
                                        if( modalidadActa == 0 ){
                                            acta->setModalidad( "Aplicado" );
                                            break;
                                        }
                                        else if( modalidadActa == 1 ){
                                            acta->setModalidad( "Investigacion" );
                                            break;
                                        }
                                        else{
                                            std::cout << "\nNumero invalido, por favor ingresalo nuevamente" << std::endl;
                                        }
                                    }
                                    std::cout << "\nModalidad cambiada" << std::endl;
                                    break;
                                }
                                case 8:{ //Jurados
                                    list<Profesor> juradosActa;
                                    while( true ){
                                        int decision;
                                        std::cout << "\nJURADOS" << std::endl;
                                        std::cout << "\n1. Agregar nuevo profesor\n2. Agregar existentes (2)\n0. Omitir\n\n";
                                        std::cout << "Digita el numero deseado: ";
                                        std::cin >> decision;
                                        if( decision == 1 ){
                                            std::cout << "\n";
                                            crearProfesor();
                                        }
                                        else if( decision == 2 ){
                                            int i, capacidadJurados = 2;
                                            for( i = 0; i < capacidadJurados; i++){
                                                while( true ){
                                                    int encontro = 0;
                                                    std::cout << "\nPara agregar el jurado " << i + 1 << " a la acta diga su id [ CANCELAR = 0 ]: ";
                                                    if( i == 0  ){
                                                        std::cin >> idJurado1;
                                                        if( idJurado1 == 0 ){
                                                            i = 2;
                                                            break;
                                                        }
                                                        // Realiza todas las verificaciones correspondientes para que no se repitan los profesores en los roles del acta
                                                        if( idDirector != 0 && idJurado1 != idDirector ){
                                                            if( idCoDirector != 0 && idJurado1 != idCoDirector ){
                                                                if( idJurado2 != 0 && idJurado1 != idJurado2 ){
                                                                    for( list<Profesor>::iterator profesor = profesores.begin(); profesor != profesores.end(); profesor++ ){
                                                                        if( profesor->getId() == idJurado1 ){
                                                                            juradosActa.push_back( *profesor );
                                                                            encontro = 1;
                                                                            std::cout << "\nJurado agregado exitosamente\n";
                                                                            break;
                                                                        }
                                                                    }
                                                                    if( encontro == 0 ){
                                                                        std::cout << "\nId invalido\n" << std::endl;
                                                                    }
                                                                    else if( encontro == 1){
                                                                        break;
                                                                    }
                                                                }
                                                                else{
                                                                    std::cout << "\nEl id del jurado 1 no puede ser igual al id del jurado 2" << std::endl;
                                                                }
                                                            }
                                                            else{
                                                                std::cout << "\nEl id del jurado 1 no puede ser igual al id del codirector" << std::endl;
                                                            }
                                                        }
                                                        else{
                                                            std::cout << "\nEl id del jurado 1 no puede ser igual al id del director" << std::endl;
                                                        }
                                                    }
                                                    else{
                                                        std::cin >> idJurado2;
                                                        if( idJurado2 == 0 ){
                                                            juradosActa.pop_back();
                                                            break;
                                                        }
                                                        // Realiza todas las verificaciones correspondientes para que no se repitan los profesores en los roles del acta
                                                        if( idDirector != 0 && idJurado2 != idDirector ){
                                                            if( idCoDirector != 0 && idJurado2 != idCoDirector ){
                                                                if( idJurado1 != 0 && idJurado2 != idJurado1 ){
                                                                    for( list<Profesor>::iterator profesor = profesores.begin(); profesor != profesores.end(); profesor++ ){
                                                                        if( profesor->getId() == idJurado2 ){
                                                                            juradosActa.push_back( *profesor );
                                                                            encontro = 1;
                                                                            std::cout << "\nJurado agregado exitosamente\n";
                                                                            break;
                                                                        }
                                                                    }
                                                                    if( encontro == 0 ){
                                                                        std::cout << "\nId invalido\n" << std::endl;
                                                                    }
                                                                    else if( encontro == 1){
                                                                        break;
                                                                    }
                                                                }
                                                                else{
                                                                    std::cout << "\nEl id del jurado 2 no puede ser igual al id del jurado 1" << std::endl;
                                                                }
                                                            }
                                                            else{
                                                                std::cout << "\nEl id del jurado 2 no puede ser igual al id del codirector" << std::endl;
                                                            }
                                                        }
                                                        else{
                                                            std::cout << "\nEl id del jurado 2 no puede ser igual al id del director" << std::endl;
                                                        }
                                                    }
                                                }
                                            }
                                            acta->setJurados( juradosActa );
                                            break;
                                        }
                                        else if( decision == 0 ){
                                            break;
                                        }
                                        else{
                                            std::cout << "\nNumero invalido, por favor ingresalo nuevamente" << std::endl;
                                        }
                                    }
                                    std::cout << "\nJurados cambiados" << std::endl;
                                    break;
                                }
                                case 9:{ //Criterios
                                    list<Criterio> criteriosActa;
                                    while( true ){
                                        int decision;
                                        std::cout << "\nCRITERIOS" << std::endl;
                                        std::cout << "\n1. Agregar criterios\n0. Omitir\n\n";
                                        std::cout << "Digita el numero deseado: ";
                                        std::cin >> decision;
                                        if( decision == 1 ){
                                            int i, cuantosCriterosParaAgregar;
                                            while( true ){
                                                std::cout << "Cuantos criterios deseas agregar al acta?: ";
                                                std::cin >> cuantosCriterosParaAgregar;
                                                if( cuantosCriterosParaAgregar > 0 ){
                                                    break;
                                                }
                                                else{
                                                    std::cout << "\nLa cantidad de criterios debe ser mayor a 0" << std::endl;
                                                }
                                            }
                                            for( i = 0; i < cuantosCriterosParaAgregar; i++){
                                                criteriosActa.push_back( crearCriterio( i ) );
                                            }
                                            acta->setCriterios( criteriosActa );
                                            break;
                                        }
                                        else if( decision == 0 ){
                                            break;
                                        }
                                        else{
                                            std::cout << "\nNumero invalido, por favor ingresalo nuevamente" << std::endl;
                                        }
                                    }
                                    std::cout << "\nCriterios cambiados" << std::endl;
                                    break;
                                }
                                case 10:{//Agregar mas observaciones
                                    std::string observaciones;
                                    int i = 0, omitir;
                                    if( acta->getCriterios().empty() ){
                                        std::cout << "No hay criterios" << std::endl;
                                    }
                                    else{
                                        for( list<Criterio>::iterator criterio = acta->getCriterios().begin(); criterio != acta->getCriterios().end(); criterio++ ){
                                            std::cout << "Digita la opcion para el criterio " << i + 1 << " [ OMITIR = 0, AGREGAR = 1 ]: ";
                                            std::cin >> omitir;
                                            if( omitir != 0 ){
                                                std::cout << "Digita la observacion adicional para el criterio " << i + 1 << " : ";
                                                std::cin >> observaciones;
                                                observaciones.append( ", " );
                                                observaciones.append( criterio->getObservacion() );
                                                //std::cout << std::endl << observaciones << std::endl;
                                                criterio->setObservacion( observaciones );
                                            }
                                            i++;
                                            if( i == acta->getCriterios().size() ){
                                                break;
                                            }
                                        }
                                    }
                                    break;
                                }
                                default:
                                    std::cout << "\nNumero invalido, por favor ingresalo nuevamente" << std::endl;
                                    break;
                            }
                        }while( opcionActa != 0 );
                        encontro = 1;
                        break;
                    }
                    else{
                        std::cout << "\nNo se puede editar una acta cerrada" << std::endl;
                    }
                }
                if( encontro == 0 ){
                    std::cout << "\nCodigo invalido, por favor ingresalo nuevamente" << std::endl;
                }
                else if( encontro == 1){
                    break;
                }
            }
            else{
                break;
            }
        }
    }
    else{
        std::cout << "\nLo sentimos, la lista de actas esta vacia" << std::endl;
    }
}

//listar actas varias
void Universidad::listarActas( int opcion ){
    switch( opcion ){
        case 0:
            break;
        case 1:{ //Todas las actas
            if( actas.size() != 0 ){
                for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
                    acta->mostrarActa();
                }
            }
            else{
                std::cout << "\nNo hay ninguna acta registrada por el momento." << std::endl;
            }
            break;
        }
        case 2:{ //Abiertas
            int impresa = 0;
            if( actas.size() != 0 ){
                for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
                    if( acta->getEstado() == ABIERTA ){
                        acta->mostrarActa();
                        impresa = 1;
                    }
                }
                if( impresa == 0 ){
                    std::cout << "\nLo sentimos, no hay ningun acta abierta por el momento." << std::endl;
                }
            }
            else{
                std::cout << "\nNo hay ninguna acta registrada por el momento." << actas.size() << std::endl;
            }
            break;
        }
        case 3:{ //Cerradas
            int impresa = 0;
            if( actas.size() != 0 ){
                for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
                    if( acta->getEstado() == CERRADA ){
                        acta->mostrarActa();
                        impresa = 1;
                    }
                }
                if( impresa == 0 ){
                    std::cout << "\nLo sentimos, no hay ningun acta cerrada por el momento." << std::endl;
                }
            }
            else{
            std::cout << "\nNo hay ninguna acta registrada por el momento." << actas.size() << std::endl;
            }
            break;
        }
        case 4:
            actasDeUnProfesor();
            break;
        case 5:
            mostrarActasAplicadas();
            break;
        case 6:
            mostrarActasInvestigativas();
            break;
        case 7:
            actasDeUnProfesorJurado();
            break;
        case 8:
            mostrarActasConJurado();
            break;
        default:
            std::cout << "\nLo siento, ingresa una opcion que sea valida\n" << std::endl;
            break;
    }
}

//Metodo para eliminar un acta
void Universidad::eliminarActa(){
    if( !actas.empty() ){
        while( true ){
            int codigoActa, encontro = 0;
            std::cout << "Digita el codigo del acta a eliminar [ CANCELAR = 0 ]: ";
            std::cin >> codigoActa;
            if( codigoActa != 0 ){
                for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
                    if( acta->getEstado() != CERRADA && acta->getCodigo() == codigoActa ){
                        actas.erase( acta );
                        encontro = 1;
                        std::cout << "\nActa con codigo " << codigoActa << " Eliminada" << std::endl;
                        break;
                    }
                    else{
                        std::cout << "\nActa con codigo " << codigoActa << " No puede ser Eliminada" << std::endl;
                        std::cout << "Ya que esta cerrada" << std::endl;
                        encontro = 1;
                    }
                }
                if( encontro == 0 ){
                    std::cout << "\nId invalido\n" << std::endl;
                }
                else if( encontro == 1){
                    break;
                }
            }
            else{
                break;
            }
        }
    }
    else{
        std::cout << "\nNo encontramos ninguna acta en nuestr abase de datos" << std::endl;
    }
}

//Cerrar acta
void Universidad::cerrarActa(){
    if( !actas.empty() ){
        while( true ){
            int codigoActa, encontro = 0;
            std::cout << "Digita el codigo del acta a cerrar [ CANCELAR = 0 ]: ";
            std::cin >> codigoActa;
            if( codigoActa != 0 ){
                for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
                    if( acta->getEstado() != CERRADA && acta->getCodigo() == codigoActa ){
                        acta->setEstado( CERRADA );
                        encontro = 1;
                        std::cout << "\nActa con codigo " << codigoActa << " cerrada " << std::endl;
                        break;
                    }
                    else{
                        std::cout << "\nActa con codigo " << codigoActa << " ya se encuentra cerrada" << std::endl;
                        encontro = 1;
                    }
                }
                if( encontro == 0 ){
                    std::cout << "\nId invalido\n" << std::endl;
                }
                else if( encontro == 1){
                    break;
                }
            }
            else{
                break;
            }
        }
    }
    else{
        std::cout << "\nNo encontramos ninguna acta en nuestr abase de datos" << std::endl;
    }
}

// Recibe por parametro un enum y dependiendo de dicho parametro lista todas las actas segun su estado ABIERTA - CERRADA
void Universidad::consultarActas( EstadoActaCerrada estadoActaCerrada ){
    if( !actas.empty() ){
        if( actas.size() > 1){
            if( estadoActaCerrada == PENDIENTE ){
                std::cout << "\nActas pendientes:\n" << std::endl;
                for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
                    if( acta->getEstadoActaCerrada() == estadoActaCerrada ){
                        acta->mostrarActa();
                        break;
                    }
                }
            }else if( estadoActaCerrada == RECHAZADA ){
                std::cout << "\nActas rechazadas:\n" << std::endl;
                for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
                    if( acta->getEstadoActaCerrada() == estadoActaCerrada ){
                        acta->mostrarActa();
                        break;
                    }
                }
            }
        }else{
            if( estadoActaCerrada == PENDIENTE ){
                if( actas.begin()->getEstadoActaCerrada() == estadoActaCerrada ){
                    std::cout << "\nActas pendientes:\n" << std::endl;
                    actas.begin()->mostrarActa();
                }
            }else if( estadoActaCerrada == RECHAZADA ){
                if( actas.begin()->getEstadoActaCerrada() == estadoActaCerrada ){
                    std::cout << "\nActas rechazadas:\n" << std::endl;
                    actas.begin()->mostrarActa();
                }
            }
        }
    }
    else{
        std::cout << "\nNo encontramos ninguna acta en nuestr abase de datos" << std::endl;
    }
}

// Recibe por parametro un enum y segun lo que reciba revisa acta por acta verificando que los jurados cumplan ademas la condicion INTERNO - EXTERNO
void Universidad::consultarJurados( Tipo tipo ){
    list<int> idsJurados;
    if( !actas.empty() ){
        for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
            list<Profesor> jurados = acta->getJurados();
            if( !jurados.empty() ){
                if( jurados.size() > 1 ){
                    for( list<Profesor>::iterator jurado = jurados.begin(); jurado != jurados.end(); jurado++ ){
                        if( jurado->getTipo() == tipo ){
                            idsJurados.push_back( jurado->getId() );
                        }
                    }
                }else{
                    if( jurados.begin()->getTipo() == tipo ){
                        idsJurados.push_back( jurados.begin()->getId() );
                    }
                }
            }
        }
        for( list<int>::iterator idJurado = idsJurados.begin(); idJurado != idsJurados.end(); idJurado++ ){
            for( list<Profesor>::iterator profesor = profesores.begin(); profesor != profesores.end(); profesor++ ){
                if( profesor->getId() == *idJurado ){
                    profesor->mostrarProfesor();
                }
            }
        }
    }else{
        std::cout << "\nNo hay ninguna acta registrada por el momento." << std::endl;
    }
}

// Recorre la lista de criterios de un acta almacenada en la lista de actas
void Universidad::listarCriterios( int codigoActa ){
    if( !actas.empty() ){
        for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
            if( acta->getCodigo() == codigoActa ){
                list<Criterio> criterios = acta->getCriterios();
                if( !criterios.empty() ){
                    for( list<Criterio>::iterator criterio = criterios.begin(); criterio != criterios.end(); criterio++ ){
                        criterio->mostrarCriterio();
                    }
                }else{
                    std::cout << "\nN/A";
                }
                std::cout << "\n";
            }
        }
    }else{
        std::cout << "\nNo hay ninguna acta registrada por el momento." << std::endl;
    }
}

//Muestra las actas dirigidas por un profesorxito
void Universidad::actasDeUnProfesor(){
    int contadorActasDeProfesor = 0;
    int idProfesor;
    int encontro = 0;
    Profesor profesorcito;
    if( !actas.empty() ){
        while( true ){
            std::cout << "\nDigita el id del profesor a buscar [ CANCELAR = 0 ]: ";
            std:: cin >> idProfesor;
            if( idProfesor == 0 ){
                return;
            }
            for( list<Profesor>::iterator profesor = profesores.begin(); profesor != profesores.end(); profesor++ ){
                if( profesor->getId() == idProfesor ){
                    profesorcito = *profesor;
                    encontro = 1;
                    break;
                }
            }
            if( encontro == 1 ){
                break;
            }
            else{
                std::cout << "\nId invalido\n" << std::endl;
            }
        }
        for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
            if( profesorcito.getId() == acta->getDirector().getId() ){
                contadorActasDeProfesor += 1;
            }
        }
        std::cout << "\nTotal de actas dirigidas por el profesor ";
        profesorcito.mostrarNombre();
        std::cout << "Encontradas:" << contadorActasDeProfesor << std::endl;
    }
    else{
        std::cout << "\nLista de actas vacias\n" << std::endl;
    }
}

//Muestra todas las actas el cual un profesorxito sea jurado
void Universidad::actasDeUnProfesorJurado(){
    /*int contadorActasDeProfesorJurado = 0;
    int idProfesor;
    int encontro = 0;
    Profesor profesorcito;
    if( !actas.empty() ){
        while( true ){
            std::cout << "\nDigita el id del profesor a buscar [ CANCELAR = 0 ]: ";
            std::cin >> idProfesor;
            if( idProfesor == 0 ){
                return;
            }
            if( profesores.size() > 1 ){
                for( list<Profesor>::iterator profesor = profesores.begin(); profesor != profesores.end(); profesor++ ){
                    if( profesor->getId() == idProfesor ){
                        profesorcito = *profesor;
                        encontro = 1;
                        break;
                    }
                }
            }else{
                if( profesores.begin()->getId() == idProfesor ){
                    profesorcito = *profesores.begin();
                    encontro = 1;
                    break;
                }
            }
            if( encontro == 1 ){
                break;
            }
            else{
                std::cout << "\nId invalido\n" << std::endl;
            }
        }
        if( actas.size() > 1 ){
            for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
                if( !acta->getJurados().empty() ){
                    if( acta->getJurados().size() > 1 ){
                        for( list<Profesor>::iterator profesor = acta->getJurados().begin(); profesor != acta->getJurados().end(); profesor++ ){
                            if( profesorcito.getId() == profesor->getId() ){
                                contadorActasDeProfesorJurado += 1;
                                acta->mostrarActa();
                            }
                        }
                    }else{
                        if( profesorcito.getId() == acta->getJurados().begin()->getId() ){
                            contadorActasDeProfesorJurado += 1;
                            acta->mostrarActa();
                        }
                    }
                }
            }
        }else{
            if( actas.begin()->getJurados().size() > 1 ){
                for( list<Profesor>::iterator profesor = actas.begin()->getJurados().begin(); profesor != actas.begin()->getJurados().end(); profesor++ ){
                    if( profesorcito.getId() == profesor->getId() ){
                        contadorActasDeProfesorJurado += 1;
                        actas.begin()->mostrarActa();
                    }
                }
            }else{
                if( profesorcito.getId() == actas.begin()->getJurados().begin()->getId() ){
                    contadorActasDeProfesorJurado += 1;
                    actas.begin()->mostrarActa();
                }
            }
        }
        std::cout << "\nTotal de actas dirigidas por el profesor ";
        profesorcito.mostrarNombre();
        std::cout << "Encontradas:" << contadorActasDeProfesorJurado << std::endl;
    }
    else{
        std::cout << "\nLista de actas vacias\n" << std::endl;
    }*/
    int idProfesor;
    int encontro = 0, cuantasActas = 0;
    Profesor profesorcito;
    if( !actas.empty() ){
        while( true ){
            std::cout << "\nDigita el id del profesor a buscar [ CANCELAR = 0 ]: ";
            std::cin >> idProfesor;
            if( idProfesor == 0 ){
                return;
            }
            else{
                for( list<Profesor>::iterator profesor = profesores.begin(); profesor != profesores.end(); profesor++ ){
                    if( profesor->getId() == idProfesor ){
                        profesorcito = *profesor;
                        encontro = 1;
                        break;
                    }
                }
                if( encontro == 1 ){
                    for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
                        //No se por q entra en un ciclo infinito entonces lo solucionamos con la capacidad total de los jurados la cual es 2
                        int capJurados = 0;
                        if( !acta->getJurados().empty() ){
                            for( list<Profesor>::iterator jurado = acta->getJurados().begin(); jurado != profesores.end(); jurado++ ){
                                if( profesorcito.getId() == jurado->getId() ){
                                    acta->mostrarActa();
                                    cuantasActas++;
                                }
                                capJurados++;
                                if( capJurados == 2 ){
                                    break;
                                }
                            }
                            if( cuantasActas == 0 ){
                                std::cout << "\nNose ha encuentrado ninguna acta en el cual " << profesorcito.getNombre() << " sea jurado" << std::endl;
                            }
                        }
                    }
                    break;
                }
                else{
                    std::cout << "\nId invalido\n" << std::endl;
                }
            }
        }
    }
    else{
        std::cout << "\nLista de actas vacias\n" << std::endl;
    }

}


//Muestra todos los jurados sin repetir de todas las actas
void Universidad::mostrarActasConJurado(){
    /*list<Profesor> juradosParaMostrar;
    if( !actas.empty() ){
        if( actas.size() > 1 ){
            for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
                if( !acta->getJurados().empty() ){
                    for( list<Profesor>::iterator profesor = acta->getJurados().begin(); profesor != acta->getJurados().end(); profesor++ ){
                        if( !juradosParaMostrar.empty() ){
                            if( juradosParaMostrar.size() > 1 ){
                                for( list<Profesor>::iterator jurado = juradosParaMostrar.begin(); jurado != juradosParaMostrar.end(); profesor++ ){
                                    if( jurado->getId() != profesor->getId() ){
                                        juradosParaMostrar.push_back( *profesor );
                                    }
                                }
                            }else{
                                if( juradosParaMostrar.begin()->getId() != profesor->getId() ){
                                    juradosParaMostrar.push_back( *profesor );
                                }
                            }
                        }
                        else{
                            juradosParaMostrar.push_back( *profesor );
                        }
                    }
                }
            }
            std::cout << "\nTotal de jurados encontrados: " << std::endl;
            if( juradosParaMostrar.size() > 1 ){
                for( list<Profesor>::iterator jurado = juradosParaMostrar.begin(); jurado != juradosParaMostrar.end(); jurado++ ){
                    jurado->mostrarNombre();
                }
            }else{
                juradosParaMostrar.begin()->mostrarNombre();
            }
        }else{
            if( !actas.begin()->getJurados().empty() ){
                for( list<Profesor>::iterator profesor = actas.begin()->getJurados().begin(); profesor != actas.begin()->getJurados().end(); profesor++ ){
                    if( !juradosParaMostrar.empty() ){
                        if( juradosParaMostrar.size() > 1 ){
                            for( list<Profesor>::iterator jurado = juradosParaMostrar.begin(); jurado != juradosParaMostrar.end(); profesor++ ){
                                if( jurado->getId() != profesor->getId() ){
                                    juradosParaMostrar.push_back( *profesor );
                                }
                            }
                        }else{
                            if( juradosParaMostrar.begin()->getId() != profesor->getId() ){
                                juradosParaMostrar.push_back( *profesor );
                            }
                        }
                    }
                    else{
                        juradosParaMostrar.push_back( *profesor );
                    }
                }
            }
            std::cout << "\nTotal de jurados encontrados: " << std::endl;
            if( juradosParaMostrar.size() > 1 ){
                for( list<Profesor>::iterator jurado = juradosParaMostrar.begin(); jurado != juradosParaMostrar.end(); jurado++ ){
                    jurado->mostrarNombre();
                }
            }else{
                juradosParaMostrar.begin()->mostrarNombre();
            }
        }
    }
    else{
        std::cout << "\nLista de actas vacias\n" << std::endl;
    }*/
    list<int> iDJuradosAMostrar;
    if( !actas.empty() ){
        for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
            //No se por q entra en un ciclo infinito entonces lo solucionamos con la capacidad total de los jurados la cual es 2
            int capJuradosActa = 0;
            if( !acta->getJurados().empty() ){
                for( list<Profesor>::iterator juradoActa = acta->getJurados().begin(); juradoActa != acta->getJurados().end(); juradoActa++ ){
                    if( !iDJuradosAMostrar.empty() ){ 
                        for( list<int>::iterator idJurado = iDJuradosAMostrar.begin(); idJurado != iDJuradosAMostrar.end(); idJurado++ ){               
                            if( juradoActa->getId() != *idJurado ){
                                iDJuradosAMostrar.push_back( juradoActa->getId() );

                            }
                        }
                    }
                    else{
                        iDJuradosAMostrar.push_back( juradoActa->getId() );
                    }
                    capJuradosActa++;
                    if( capJuradosActa == 2 ){
                        break;
                    }
                    
                }
            }
        }
        
        std::cout << "\nJurados encontrados: " << *iDJuradosAMostrar.begin() <<*iDJuradosAMostrar.end() << std::endl;
        for( list<int>::iterator iDJurado = iDJuradosAMostrar.begin(); iDJurado != iDJuradosAMostrar.end(); iDJurado++ ){
            for( list<Profesor>::iterator profesor = profesores.begin(); profesor != profesores.end(); profesor++ ){
                if( profesor->getId() == *iDJurado ){
                    profesor->mostrarNombre();
                }
            }
        }
    }
    else{
        std::cout << "\nLista de actas vacias\n" << std::endl;
    }
    std::cout << "\nOtra Forma\n";
    list<Profesor> juradosAMostrar;
    if( !actas.empty() ){
        for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
            //No se por q entra en un ciclo infinito entonces lo solucionamos con la capacidad total de los jurados la cual es 2
            //int capJuradosActa = 0;
            if( !acta->getJurados().empty() ){
                if( !juradosAMostrar.empty() ){ 
                    for( list<Profesor>::iterator jurado = juradosAMostrar.begin(); jurado != juradosAMostrar.end(); jurado++ ){             
                        if( acta->getJurados().begin()->getId() != jurado->getId() ){
                            juradosAMostrar.push_back( *acta->getJurados().begin() ); 
                        }
                        else if( acta->getJurados().end()->getId() != jurado->getId() ){
                            juradosAMostrar.push_back( *acta->getJurados().begin() ); 
                        }
                    }
                }
                else{
                    juradosAMostrar.push_back( *acta->getJurados().begin() );
                }
                /*capJuradosActa++;
                if( capJuradosActa == 2 ){
                    break;
                }*/
            }
        }  
        std::cout << "\nJurados encontrados: " << std::endl;
        for( list<Profesor>::iterator profesor = juradosAMostrar.begin(); profesor != juradosAMostrar.end(); profesor++ ){
                profesor->mostrarNombre();
        }
    }
    else{
        std::cout << "\nLista de actas vacias\n" << std::endl;
    }
}

//Muestra las actas aplicadas
void Universidad::mostrarActasAplicadas(){
    int contadorActas = 0;
    if( !actas.empty() ){
        for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
            if( acta->getModalidad() == "Aplicado" ){
                acta->mostrarActa();
                contadorActas += 1;
            }
        }
        std::cout << "\nTotal de actas aplicadas encontradas: " << contadorActas << std::endl;
    }
    else{
        std::cout << "\nLista de actas vacias\n" << std::endl;
    }
}

//Muestra las actas investigativas
void Universidad::mostrarActasInvestigativas(){
    int contadorActas = 0;
    if( !actas.empty() ){
        for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
            if( acta->getModalidad() == "Investigacion" ){
                acta->mostrarActa();
                contadorActas += 1;
            }
        }
        std::cout << "\nTotal de actas investigativas encontradas: " << contadorActas << std::endl;
    }
    else{
        std::cout << "\nLista de actas vacias\n" << std::endl;
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
void Universidad::mostrarTodosLosEstudiantes(){
    if( estudiantes.size() != 0 ){
        for( list<Estudiante>::iterator estudiante = estudiantes.begin(); estudiante != estudiantes.end(); estudiante++ ){
            estudiante->mostrarEstudiante();
        }
}
    else{
        std::cout << "\nNo hay ninguna estudiante registrado por el momento." << std::endl;
    }
}

// Llama la funcion notaFinal() de acta y dependiendo de lo que retorna le cambia el estado al acta.
void Universidad::calcularCalificacion( int codigoActa ){
    float calificacion;
    int encontrada = 0;
    for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
        if( acta->getCodigo() == codigoActa ){
            encontrada = 1;
            calificacion = acta->notaFinal();
            if( calificacion <= 3.5 ){
                acta->setEstadoActaCerrada( RECHAZADA );
            }
            else{
                acta->setEstadoActaCerrada( APROBADA );
            }
        }
    }
    if( encontrada == 0 ){
        std::cout << "\nLo sentimos, no hemos encontrado ningun acta con el id" << codigoActa << std::endl;
        return;
    }
    else if( calificacion == -1 ){
        std::cout << "\nLo sentimos, revisa que todos los criterios y las ponderaciones esten correctamente diligenciados" << std::endl;
        return;
    }
    std::cout << "\nLa calificacion ponderada del acta con el id " << codigoActa << " es " << calificacion << std::endl;
}

//Exportarla
void Universidad::exportarActa(){
    if( !actas.empty() ){
        while( true ){
            int codigoActa, encontro = 0;
            std::cout << "Digita el codigo del acta a exportar [ CANCELAR = 0 ]: ";
            std::cin >> codigoActa;
            if( codigoActa != 0 ){
                for( list<Acta>::iterator acta = actas.begin(); acta != actas.end(); acta++ ){
                    if( acta->getEstado() == CERRADA && acta->getCodigo() == codigoActa ){
                        acta->exportar( codigoActa ); // En esta funcion se crea el archivo .txt
                        encontro = 1;
                        break;
                    }
                    else{
                        std::cout << "\nActa con codigo " << codigoActa << " no puede ser exportada debido a que se encuentra abierta" << std::endl;
                        encontro = 1;
                    }
                }
                if( encontro == 0 ){
                    std::cout << "\nNo hay ningun acta con ese id, intentalo de nuevo\n" << std::endl;
                }
                else if( encontro == 1){
                    break;
                }
            }
            else{
                break;
            }
        }
    }
    else{
        std::cout << "\nNo encontramos ninguna acta en nuestra base de datos" << std::endl;
    }
}

//tomar actas
list<Acta> Universidad::getActas(){
  return this->actas;
}

//Hacks, trucos, el diablo en codigo, la mejor inversion que hicimos en tiempo
void Universidad::elDiablo(){
    estudiantes.push_back( Estudiante( 1, "Juan Esteban Acosta Lopez", "wembie@javerianacali.edu.co", "3148771423", "Ingenieria de Sistemas y Computacion", 3) );
    estudiantes.push_back( Estudiante( 2, "Sebastian Tobar Quintero", "sebastianq@javerianacali.edu.co", "3152784840", "Ingenieria de Sistemas y Computacion", 3) );
    profesores.push_back( Profesor( 1, "Luisa Guachene", "luisaguachene@javerianacali.edu.co", "3146875478", "Profe de POO", INTERNO ) );
    profesores.push_back( Profesor( 2, "Gonzalo NoreNa", "gozocongonzo@javerianacali.edu.co", "3176175172", "Esposo de Guachene", INTERNO) );
    profesores.push_back( Profesor( 3, "Yoan Pinzon", "Hijitos@javerianacali.edu.co", "31687454423", "Hijitos los Quiero Mucho", EXTERNO ) );
    profesores.push_back( Profesor( 4, "ChupapiMuyaNo", "Chupapi@gmail.com", "3199999999", "Tiktoker", INTERNO ) );
    list<Profesor> jurados;
    jurados.push_back( Profesor( 3, "Yoan Pinzon", "Hijitos@javerianacali.edu.co", "31687454423", "Hijitos los Quiero Mucho", EXTERNO ) );
    jurados.push_back( Profesor( 4, "ChupapiMuyaNo", "Chupapi@gmail.com", "3199999999", "Tiktoker", INTERNO ) );
    list<Criterio> criterios;
    criterios.push_back( Criterio( "Desarrollo y profundidad en el tratamiento del tema: ", 5.0, 50, "Se desarrollo apropiadamente el tema y con la profundidad suficiente para su culminacion" ) );
    criterios.push_back( Criterio( "Desafio academico y cientifico del tema: ", 3.0, 50, "El trabajo estuvo bien soportado y con rigor cientifico" ) );
    auto t = std::time( nullptr );
    auto tm = *std::localtime( &t );
    std::ostringstream oss;
    oss << std::put_time( &tm, "Fecha: %d-%m-%Y\nHora: %H:%M:%S" );
    auto fecha = oss.str();
    actas.push_back( Acta( 1, fecha, ABIERTA, PENDIENTE, Estudiante( 1, "Juan Esteban Acosta Lopez", "wembie@javerianacali.edu.co", "3148771423", "Ingenieria de Sistemas y Computacion", 3), Profesor( 1, "Luisa Guachene", "luisaguachene@javerianacali.edu.co", "3146875478", "Profe de POO", INTERNO ),  Profesor( 2, "Gonzalo NoreNa", "gozocongonzo@javerianacali.edu.co", "3176175172", "Esposo de Guachene", INTERNO ), "Sistemas Operativos", "Aplicado", jurados, criterios ) );
}

void Universidad::sorpresa(){
    std::cout << "------------------------- LUISA CON GONZO CASADOS :D --------------------------" << std::endl;
    std::cout << "+++++++++++++++++::+:::::::::::::::::::::::*@@WWWWWWWWWWWWWWWW@@+--------------" << std::endl;
    std::cout << "++++++++++++::::::::::::::::::::::::::::::#WWWWWWW@@@@@@@@@@WWW@@+---.........." << std::endl;
    std::cout << "::++++++++++:::::::::+@@@WWWWWWWW@@+.....:@WWW@@#######======##@@@+--.........." << std::endl;
    std::cout << ":::++++++++::::::::#@@@@WWWWWWWWWWWWW@+.*WWW@#==================#@@*---........" << std::endl;
    std::cout << ":::::::::::::----=@@@@@@@@@@@@@WWWWWWWWWWW@@=*******==============@@=----------" << std::endl;
    std::cout << "::::::::-------:#@@@@@@@@@@W@@@@@@@WWWWWW@@=******===============*=@@*---------" << std::endl;
    std::cout << "+++++:+*......:##@#@@@@@@@#=======##@WWW@@#=*********=====*=#@@#==*=@#......-.-" << std::endl;
    std::cout << ":::::::*:...-:##@@###@@=***********==#@W@@#***=#####==***=#@##==#===#=........." << std::endl;
    std::cout << "::::::::+...:###@@###=**++**********=##@@@#=*****===*+=#####@@@#===+:*.....----" << std::endl;
    std::cout << "::::::::+:..:=####*+:::*=*++++++***==##@W@#=*=*==#@##====##=####===*++---:::-::" << std::endl;
    std::cout << ":::::::::+--:+**++++#=@#*+++:+++*===###@WW@===****=====**===###====**++--::::::" << std::endl;
    std::cout << ":::::::::::-+*+++++*++*==*+++******=*=#@W@@=*****==**===*===*=#====**++----::::" << std::endl;
    std::cout << ":::+++::::::+++:++++***+++++*====#@#@###**#=*++++**=*******======##===:....----" << std::endl;
    std::cout << ":::++++::*:=#+:::::+++++*++**==****=##=*-+#**++++*=******====##=###===*.....--." << std::endl;
    std::cout << "::++++++::*==+:::::++++++::+*==****==#*-.-***++++*=*******+*+***@##==**----...-" << std::endl;
    std::cout << "++++++++:+*#+::::+++::+++++****+++*==*:....-*++++*=*@=++:::++*=#======+........" << std::endl;
    std::cout << "+++++++++*##*+:::+++=*:::+******++*=*+----..-*++++****==========**===*........." << std::endl;
    std::cout << "+++++++++=##@##+::::::+*====##=***=:--.......-**++*****+++***=======*+##@@@@##=" << std::endl;
    std::cout << "+:--..--.:##@@W#+::::+++++**==*==*..:+::+=##WWW@=*************======::=W@#@@WWW" << std::endl;
    std::cout << "****+::+.-:=@@W@#*+::::++***=#@##@@@@@@@WWW@W@WWWW@#=**********=##*:::+=WW@#@@@" << std::endl;
    std::cout << "**====*:.-::*=@W@@=****++*#@WWWWWWWWWWWWWWWWWW@WWWWWWW@====###@@WWW@@*++*@WW@#@" << std::endl;
    std::cout << "====###+-.-:+*=@W@@#==#@@@W@@@WWWWWWWWWWWWWWWW@WWWWWWWWW#+++#@WWWWWW@@#**=@WWW@" << std::endl;
    std::cout << "======*+-..::**#@@@@@@@@@@@WW@@@@WWWWWWWWWWWWWWWWWWWWWWWWW=*=WW@@WW@WW@@=*=@WWW" << std::endl;
    std::cout << "**====*+:-.--:++#@W@@@#@@@@@WW@@@@@@WWWWWWWWWWWWWWWWWWWWWWW@*=@@@@@@WWWW@===@@W" << std::endl;
    std::cout << "*====##=*+:+-:+++#@W@@##@@@@@WW@@@@@@@WWWWWWWWWWWWWWWWWWWWWW@++#@@#@@WWW@@###@W" << std::endl;
    std::cout << "@##@##@@@@@#@@==**@WW==@@@@@@@W@@@@@@@@WWWWWWWWWWWWWWWWWWWWWW@*=#@@@@WWWWW@@@@W" << std::endl;
    std::cout << "\nhttps://www.facebook.com/photo?fbid=10202209451493052&set=a.1389655056726" << std::endl;
    std::cout << "ARCHIVO = 'PARA LUISIS.txt' es un regalito para ti de parte de nosotros" << std::endl;
}