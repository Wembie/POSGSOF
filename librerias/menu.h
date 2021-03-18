#include <iostream>

#ifndef MENU_H
#define MENU_H

class menu
{
private:
    int opcion;
public:
    menu();
    int menuActa();
    int getOpcion();
    void setOpcion( int );
};

#endif