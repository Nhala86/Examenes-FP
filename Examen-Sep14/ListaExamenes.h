#ifndef ListaExamenes_H
#define ListaExamenes_H

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"Examenes.h"
using namespace std;

const int MAX_EXAM = 50;

typedef struct{
	tExamen* examen;
	int contador;
}tListaExamenes;

/**
La manera mas sencilla y rapida a la hora de acumular cosas como calificaciones, es un array de enteros, de tantas
posiciones como elementos vayas a contar (muy util en ejercicios tipo "cuenta el numero de cada tipo de letra de una frase").
Para este caso tenemos 5 opciones asi que tenemos un array de 5 enteros. Que es lo que se pide en el enunciado de la funcion
**/
typedef int tArrayCalificaciones[5];


void inicializar (tListaExamenes & listaExamenes);

/**
** Dada una lista de exámenes devuelve un array estático de cinco posiciones
** donde cada posición representa el número de suspensos, aprobados, bienes, notables y sobresalientes de la lista de exámenes.
**/

//La reemplazamos por un tipo void
void estadisticaNotas (const tListaExamenes & listaExamenes, tArrayCalificaciones & arrayCalificaciones);

/**
** Dada una lista de exámenes y una posición muestra en pantalla los exámenes a partir de esa posición. Se implementará de forma recursiva.
**/

void muestraLista (const tListaExamenes & listaExamenes);


/**
** Muestra en pantalla una lista de exámenes junto a sus estadísticas
**/

void muestra (const tListaExamenes & listaExamenes);


/**
** Dada una lista de exámenes y un examen añade el examen al final de la lista. Si la lista está llena, se ignora el nuevo examen.
**/

void insertaNota (tListaExamenes & listaExamenes, const tExamen & examen);

/**
** Dada una lista de exámenes libera la memoria dinámica que usa.
**/

void destruye (tListaExamenes & listaExamenes);

#endif
