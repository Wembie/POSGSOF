all: compilar
compilar: menu criterio acta persona estudiante profesor universidad main
		g++ -o menu.o criterio.o acta.o persona.o estudiante.o jurado.o universidad.o main.o
menu: menu.cpp menu.h
		g++ -c menu.cpp
criterio: criterio.cpp criterio.h
		g++ -c criterio.cpp
acta: acta.cpp acta.h
		g++ -c acta.cpp
persona: persona.cpp persona.h
		g++ -c persona.cpp
estudiante: estudiante.cpp estudiante.h
		g++ -c estudiante.cpp
profesor: profesor.cpp profesor.h
		g++ -c profesor.cpp
universidad: universidad.cpp universidad.h
		g++ -c universidad.cpp
main: main.cpp menu.h acta.h persona.h estudiante.h jurado.h
	  g++ -c main.cpp