#ifndef ListaCoches_H
#define ListaCoches_H

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

const int MAX_COCHES = 20;
const int CENTINELA = -1;
const string FICHERO = "coches.txt";

typedef struct{
	int codigo;
	string modelo;
}tCoche;

typedef struct{
	tCoche coche;
	int contador;
}tListaCoches;

void inicializar(tListaCoches & listaCoches);
/** 
** Carga la información del archivo coches.txt en la lista de coches; devuelve true si se ha podido abrir el archivo y false en caso
** contrario. La lista de coches sólo contendrá la información de este archivo.
**/

bool leerModelos(tListaCoches & listaCoches);

/**
** Mostrar lista de coches;
**/

void mostrar (const tListaCoches & listaCoches);

void insertarCoche(tListaCoches & listaCoches, tCoche & coche);

/**
** Dada la lista de coches y un código, devuelve la posición (índice) del elemento de la lista de coches con ese código; si no se
** encuentra el código devuelve ‐1. Debe implementarse como búsqueda binaria.
**/

bool buscar(tCoche & coche, int & posicion, int codigo, tListaCoches & listaCoches);

bool leerCoche (ifstream & archivo, tCoche & coche);

#endif