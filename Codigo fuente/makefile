all: compilar
compilar: funciones menu criterio persona estudiante profesor acta universidad main
		g++ -o PontificiaUniversidadJaverianaCali funciones.o menu.o criterio.o persona.o estudiante.o profesor.o acta.o universidad.o main.o
funciones: archivos/funciones.cpp librerias/funciones.h
		g++ -c archivos/funciones.cpp
menu: archivos/menu.cpp librerias/menu.h
		g++ -c archivos/menu.cpp
criterio: archivos/criterio.cpp librerias/criterio.h
		g++ -c archivos/criterio.cpp
persona: archivos/persona.cpp librerias/persona.h
		g++ -c archivos/persona.cpp
estudiante: archivos/estudiante.cpp librerias/estudiante.h
		g++ -c archivos/estudiante.cpp
profesor: archivos/profesor.cpp librerias/profesor.h
		g++ -c archivos/profesor.cpp
acta: archivos/acta.cpp librerias/acta.h
		g++ -c archivos/acta.cpp
universidad: archivos/universidad.cpp librerias/universidad.h
		g++ -c archivos/universidad.cpp
main: archivos/main.cpp librerias/funciones.h librerias/menu.h librerias/criterio.h librerias/persona.h librerias/estudiante.h librerias/profesor.h librerias/acta.h librerias/universidad.h
		g++ -c archivos/main.cpp
