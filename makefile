all: compilar
compilar: menu acta persona estudiante jurado main
		g++ -o menu.o acta.o persona.o estudiante.o jurado.o main.o
menu: menu.cpp menu.h
		g++ -c menu.cpp
acta: acta.cpp acta.h
		g++ -c acta.cpp
persona: persona.cpp persona.h
		g++ -c persona.cpp
estudiante: estudiante.cpp estudiante.h
		g++ -c estudiante.cpp
jurado: jurado.cpp jurado.h
		g++ -c jurado.cpp
main: main.cpp menu.h acta.h persona.h estudiante.h jurado.h
	  g++ -c main.cpp