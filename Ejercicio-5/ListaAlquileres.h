#ifndef ListaAlquileres_H
#define ListaAlquileres_H

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"ListaCoches.h"


const int MAX_ALQUI = 100;
const string ARCHIVO = "rent.txt";
const int FINAL = -1;
typedef struct{
	int codigo;
	string fecha;
	int numAlquiler;
}tAlquiler;

typedef struct{
	tAlquiler alquiler;
	int contador;
}tListaAlquiler;

void inicializar (tListaAlquiler & listaAlquiler);


/**
** Carga la información del archivo rent.txt en la lista de alquileres; devuelve true si se ha podido abrir el archivo y false
** en caso contrario. La lista de alquileres sólo contendrá la información de este archivo.
**/

bool leerAlquileres(tListaAlquiler & listaAlquiler);


/**
** Ordena la lista de alquileres por orden de fecha (menor a mayor).
**/

void ordenar(tListaAlquiler & listaAlquiler);


/**
** Dadas ambas listas, muestra la relación de alquileres con el formato mostrado arriba; si no se encuentra un código de coche se
** notificará el error.
**/



void mostrar (const tListaAlquiler & listaAlquiler, const tListaCoches & listaCoches);

void mostrarAlquiler(const tAlquiler& alquiler,const tListaCoches & listaCoches);

#endif