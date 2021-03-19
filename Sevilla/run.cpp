#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

int main()
{
    int codigo = 4;
    std::string codigoActa( std::to_string( codigo ) );
    std::cout << codigoActa;
    std::cout << type(codigo);
    auto t = std::time( nullptr );
    auto tm = *std::localtime( &t );

    std::ostringstream oss;
    oss << std::put_time( &tm, "Fecha: %d-%m-%Y\nHora: %H:%M:%S" );
    auto fecha = oss.str();

    std::cout << fecha << std::endl;

    enum Estado { CERRADO, ABIERTO, PENDIENTE };
    std::cout << CERRADO << std::endl;
}