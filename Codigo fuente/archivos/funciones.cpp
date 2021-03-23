#include "../librerias/funciones.h"

// Busca x directorio y retorna si lo encontró o no
bool encontrarDirectorio( std::string nombreDirectorio ){
    DIR * directorio;
    if( directorio = opendir( nombreDirectorio.c_str() ) ){
        closedir( directorio );
        return true;
    }
    else{
        return false;
    }
}

// Busca x archivo y retorna si lo encontró o no
bool encontrarArchivo( std::string nombreArchivo ){
    FILE * archivo;
    if( archivo = fopen( nombreArchivo.c_str(), "r" ) ){
        fclose( archivo );
        return true;
    }
    else{
        return false;
    }
}
