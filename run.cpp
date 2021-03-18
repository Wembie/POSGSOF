#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

int main()
{
    auto t = std::time( nullptr );
    auto tm = *std::localtime( &t );

    std::ostringstream oss;
    oss << std::put_time( &tm, "Fecha: %d-%m-%Y\nHora: %H:%M:%S" );
    auto fecha = oss.str();

    std::cout << fecha << std::endl;

    enum Estado { CERRADO, ABIERTO, PENDIENTE };
    std::cout << CERRADO << std::endl;
    int codigo;
    codigo = 0;
    std::string a(std::to_string(codigo));
    std::cout << "Actas/" + a;
}