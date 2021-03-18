#include "../librerias/funciones.h"

// Eliminar comentarios si a usted le funciona el #include <dirent.h>

bool encontrarDirectorio( std::string nombreDirectorio ){
    // DIR * directorio;
    // if( directorio = opendir( nombreDirectorio.c_str() ) ){
    //     closedir( directorio );
    //     return true;             
    // }   
    // else{
    //     return false;   
    // }
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