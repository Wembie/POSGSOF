#include <iostream>
#include "universidad.h"

int main(){
    if( encontrarDirectorio( "Actas" ) ){
    }
    else{
        mkdir( "Actas" );
    }
    return 0;
}