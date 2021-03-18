#include "funciones.h"

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