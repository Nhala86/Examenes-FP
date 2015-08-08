#ifndef Examenes_H
#define Examenes_H

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

/**
typedef struct{
	int ano;
	int mes;
	int dia;
}tFecha;
**/
typedef struct{
	//tFecha fecha; muy complicado de momento
	string fecha;
	double notaNumerica;
	string notaCualitativa;
}tExamen;


/**
** Dado un examen muestra su información con el siguiente formato: 2014/09/01 – 9.0 - SB
**/

void muestra (const tExamen & examen);


/**
** Dada una nota numérica, devuelve su calificación cualitativa (<5: SS; >= 5 y < 6: AP; >=6 y < 7: B; >=7 y < 9: NT; >= 9 y <=10: SB).

OJO: dada una NOTA NUMERICA, no el examen entero!!
**/

//string notaCualitativa (const tExamen & examen);
string notaCualitativa (int notaNumerica);

#endif