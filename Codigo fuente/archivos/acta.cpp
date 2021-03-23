#include "../librerias/acta.h"

Acta::Acta(){

}

// Constructor sin co-director
Acta::Acta( int codigo, std::string fechaHora, Estado estado, EstadoActaCerrada estadoActaCerrada, Estudiante autor, Profesor director, std::string enfasis, std::string modalidad, list<Profesor> jurados, list<Criterio> criterios ){
    this->codigo = codigo;
    this->fechaHora = fechaHora;
    this->estado = estado;
    this->estadoActaCerrada = estadoActaCerrada;
    this->autor = autor;
    this->director = director;
    this->coDirectorActa = "N/A";
    this->enfasis = enfasis;
    this->modalidad = modalidad;
    this->jurados = jurados;
    this->criterios = criterios;
}

// Constructor con co-director
Acta::Acta( int codigo, std::string fechaHora, Estado estado, EstadoActaCerrada estadoActaCerrada, Estudiante autor, Profesor director, Profesor coDirector, std::string enfasis, std::string modalidad, list<Profesor> jurados, list<Criterio> criterios ){
    this->codigo = codigo;
    this->fechaHora = fechaHora;
    this->estado = estado;
    this->estadoActaCerrada = estadoActaCerrada;
    this->autor = autor;
    this->director = director;
    this->coDirector = coDirector;
    this->coDirectorActa = "Si";
    this->enfasis = enfasis;
    this->modalidad = modalidad;
    this->jurados = jurados;
    this->criterios = criterios;
}

// Imprime el objeto acta
void Acta::mostrarActa(){
    std::cout << "\nCodigo Acta: " << codigo << std::endl;
    std::cout << fechaHora << std::endl;
    std::cout << "Estado: ";
    if( estado == CERRADA ){
        std::cout << "Cerrada - ";
    }
    else if( estado == ABIERTA ){
        std::cout << "Abierta - ";
    }
    if( estadoActaCerrada == APROBADA ){
        std::cout << "Aprobada" << std::endl;
    }
    else if( estadoActaCerrada == RECHAZADA ){
        std::cout << "Rechazada" << std::endl;
    }
    else{
        std::cout << "Pendiente" << std::endl;
    }
    std::cout << "Autor: ";
    autor.mostrarNombre();
    std::cout << "Director: ";
    director.mostrarNombre();
    std::cout << "Co-Director: ";
    if( coDirectorActa == "N/A" ){
        std::cout << "No existe" << std::endl;
    }
    else{
        coDirector.mostrarNombre();
    }
    std::cout << "Enfasis: " << enfasis << std::endl;
    std::cout << "Modalidad: " << modalidad << std::endl;
    int i = 1;
    std::cout << "Jurados: ";
    if( jurados.empty() ){
        std::cout << "No hay jurados" << std::endl;
    }
    else{
        std::cout << "\n";
        for( list<Profesor>::iterator jurado = jurados.begin(); jurado != jurados.end(); jurado++ ){
            std::cout << "Jurado " << i << ":" << std::endl;
            jurado->mostrarNombre();
            i++;
        }
    }
    i = 1;
    std::cout << "Criterios: \n";
    if( criterios.empty() ){
        std::cout << "No hay criterios" << std::endl;
    }
    else{
        for( list<Criterio>::iterator criterio = criterios.begin(); criterio != criterios.end(); criterio++ ){
            std::cout << "\nCriterio " << i << std::endl << std::endl;
            criterio->mostrarCriterio();
            i++;
        }
    }
}

// Funciones de retorno y seteo

void Acta::setFechaHora( std::string fechaHora ){
    this->fechaHora = fechaHora;
}

void Acta::setEstado( Estado estado ){
    this->estado = estado;
}

void Acta::setEstadoActaCerrada( EstadoActaCerrada estadoActaCerrada ){
    this->estadoActaCerrada = estadoActaCerrada;
}

void Acta::setAutor( Estudiante autor ){
    this->autor = autor;
}

void Acta::setDirector( Profesor director){
    this->director = director;
}

void Acta::setCoDirectorActa( std::string coDirectorActa ){
    this->coDirectorActa = coDirectorActa;
}

void Acta::setCoDirector( Profesor coDirector ){
    this->coDirector = coDirector;
}

void Acta::setEnfasis( std::string enfasis ){
    this->enfasis = enfasis;
}

void Acta::setModalidad( std::string modalidad ){
    this->modalidad = modalidad;
}

void Acta::setJurados( list<Profesor> jurados ){
    this->jurados = jurados;
}

void Acta::setCriterios( list<Criterio> criterios ){
    this->criterios = criterios;
}

Estado Acta::getEstado(){
    return this->estado;
}

EstadoActaCerrada Acta::getEstadoActaCerrada(){
    return this->estadoActaCerrada;
}

int Acta::getCodigo(){
    return this->codigo;
}

Profesor Acta::getDirector(){
    	return this->director;
}

Profesor Acta::getCoDirector(){
    return this->coDirector;
}

list<Profesor> Acta::getJurados(){
    return this->jurados;
}

list<Criterio> Acta::getCriterios(){
    return this->criterios;
}

std::string Acta::getModalidad(){
    return this->modalidad;
}

// Funcion para calcular nota del acta
float Acta::notaFinal(){
    float calificacion, ponderacionTotal;
    for( list<Criterio>::iterator criterio = criterios.begin(); criterio != criterios.end(); criterio++ ){
        ponderacionTotal += criterio->getPonderacion();
    }
    // Se verifica que la suma de las ponderaciones de exactamente 100%
    if( ponderacionTotal == 1 ){
        for( list<Criterio>::iterator criterio = criterios.begin(); criterio != criterios.end(); criterio++ ){
            if( criterio->getCalificacion() >= 0 && criterio->getCalificacion() <= 5 ){ // Se verifica que la calificacion se encuentre entre 0 y 5
                calificacion += criterio->getCalificacion()*criterio->getPonderacion(); // Se multiplica la calificacion por la ponderacion y se suma
            }
            else{
                return -1; // retorna error
            }
        }
        return calificacion;
    }
    else{
        return -1; // retorna error
    }
}

void Acta::exportar( int id ){
    int juradoNo = 1;
    std::ofstream file;
    file.open("actas/Acta " + std::to_string( id ) + ".txt"); // Crea en el directorio previamente creado "actas", un nuevo archivo con el id del acta donde almacena toda la informacion temporalmente archivada en el programa
    file << "ACTA DE EVALUACION DE TRABAJO DE GRADO\n\n";
    file << "Autor: " << autor.getNombre() << " ID: " << autor.getId();
    file << "\n" << fechaHora;
    file << "\nDirector: " << director.getNombre();
    file << "\nCo-Director: " << coDirector.getNombre();
    file << "\nEnfasis en: " << enfasis;
    file << "\nModalidad: " << modalidad;
    file << "\n\nJurados:\n";
    if( !jurados.empty() ){
        for( list<Profesor>::iterator jurado = jurados.begin(); jurado != jurados.end(); jurado++ ){
            file << "\nJurado " << juradoNo << ": " << jurado->getNombre();
        }
    }else{
        file << "\nN/A";
    }
    file << "\n\nEn atencion al desarrollo de este Trabajo de Grado y al documento y sustentacion que presento el(la) autor(a), los Jurados damos las siguientes calificaciones parciales y observaciones (los criterios a evaluar y sus ponderaciones se estipulan en el articulo 7.1 de las Directrices para Trabajo de Grado de Maestria):\n";
    file << "\nCriterios:\n\n";
    if( !criterios.empty() ){
        for( list<Criterio>::iterator criterio = criterios.begin(); criterio != criterios.end(); criterio++ ){
            file << criterio->getTema();
            file << "\nCalificacion parcial: " << criterio->getCalificacion();
            file << "\nPonderacion: " << criterio->getPonderacion() << "%";
            file << "\nObservaciones: " << criterio->getObservacion();
        }
    }else{
        file << "\nN/A";
    }
    file << "\n\nComo resultado de estas calificaciones parciales y sus ponderaciones, la calificación del Trabajo de Grado es: " << notaFinal();
    file << "\n\n__________\n";
    file << "Firma del jurado 1\n\n";
    file << "__________\n";
    file << "Firma del jurado 2";
    file.close();
    std::cout << "\nActa con codigo " << id << " exportada" << std::endl;
}
