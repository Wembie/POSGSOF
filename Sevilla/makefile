all: compilar
compilar: funciones menu criterio persona estudiante profesor acta universidad main
		g++ -o PontificiaUniversidadJaverianaCali funciones.o menu.o criterio.o persona.o estudiante.o profesor.o acta.o universidad.o main.o
funciones: funciones.cpp funciones.h
		g++ -c funciones.cpp
menu: menu.cpp menu.h
		g++ -c menu.cpp
criterio: criterio.cpp criterio.h
		g++ -c criterio.cpp
persona: persona.cpp persona.h
		g++ -c persona.cpp
estudiante: estudiante.cpp estudiante.h
		g++ -c estudiante.cpp
profesor: profesor.cpp profesor.h
		g++ -c profesor.cpp
acta: acta.cpp acta.h
		g++ -c acta.cpp
universidad: universidad.cpp universidad.h
		g++ -c universidad.cpp
main: main.cpp funciones.h menu.h criterio.h persona.h estudiante.h profesor.h acta.h universidad.h
	  g++ -c main.cpp