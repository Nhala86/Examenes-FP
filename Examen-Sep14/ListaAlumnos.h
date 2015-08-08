#ifndef ListaAlumnos_H
#define ListaAlumnos_H

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"ListaExamenes.h"
using namespace std;

const int MAX_ALUMNOS = 100;
const string CENTINELA = "XXX";

typedef int tArrayCalificacionesAlumnos[5];//necesaria para las estadisticas

typedef struct{
	string nif;
	tListaExamenes listaExamenes;
}tAlumno;

typedef struct{
	tAlumno* alumno[MAX_ALUMNOS];
	int contador;
}tListaAlumnos;


void inicializar (tListaAlumnos & listaAlumnos);

/**
** Dada una lista de alumnos, devuelve una array estático de cinco posiciones
** donde cada posición representa respectivamente el número de suspensos, aprobados, bienes, notables y sobresalientes
** de todos los exámenes existentes.
**/

void totalEstadisticas (tListaAlumnos & listaAlumnos);


/**
** Dada una lista de alumnos muestra en la pantalla los exámenes de cada alumno y sus estadísticas, así como al final las estadísticas totales.
**/

void muestra (tListaAlumnos & listaAlumnos);


/**
** Dada una lista de alumnos y un NIF, localiza en la lista un alumno con ese NIF.
** Si lo encuentra devuelve la posición que ocupa, si no lo encuentra devuelve la posición que debería de ocupar.
** La búsqueda se hará iterativa y de la forma más eficiente.
**/

bool busca (tListaAlumnos & listaAlumnos, string nif, int & posicion);


/**
** Dada una lista de alumnos, un NIF y un examen, y una posición,
** inserta un nuevo alumno con ese NIF (y ese examen como primer examen) en la lista de alumnos en la posición dada.
** Si la lista está llena, se ignora el nuevo alumno.
**/

void insertaAlumno (tListaAlumnos & listaAlumnos, string nif, int pos, const tExamen & examen);


/**
** Carga en una lista de alumnos los exámenes del archivo datos.txt,
** que contiene en cada línea la información de un examen: NIF, fecha, y nota numérica.
** El archivo termina con XXX como NIF.
** Se lee cada examen y se localiza el alumno.
** Si no existe, se añade a la lista de alumnos (manteniendo el orden de NIFs). Si existe, se añade el examen a la lista del alumno.
**/

void carga (ifstream & archivo, tListaAlumnos & listaAlumnos);


/**
** Dada una lista de alumnos libera la memoria dinámica que utiliza.
**/

void destruye (tListaAlumnos & listaAlumnos);

#endif