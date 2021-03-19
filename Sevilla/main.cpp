#include <iostream>
#include "universidad.h"

int main(){
    int contadorActa;
    if( encontrarDirectorio( "Actas" ) ){
        contadorActa = 0;
        //guardar el codigo
    }
    else{
        mkdir( "Actas" );
        //cargar el codigo
    }
    return 0;
}