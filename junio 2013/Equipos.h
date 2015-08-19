#ifndef Equipos_H
#define Equipos_H

#include"ListaComponentes.h"


const int MAX_EQUIP = 300;
const string CENTINELA = "X";
const string FICHERO = "equipos.txt";

typedef struct{
	string codigo;
	double precio;
	tListaComponentes listaComponentes;
}tEquipo;

typedef struct{
	tEquipo* equipo[MAX_EQUIP]; //array estatico de punteros
	int contador;
}tListaEquipos;

void inicializar(tListaEquipos & listaEquipos);
/**
** carga la información del archivo equipos.txt; para cada
** línea localiza el código de equipo en la lista (si no existe, lo inserta) y añade un
** componente en su lista de componentes con el código, precio y nombre; y actualiza el precio del equipo.
** Devuelve la lista con los datos leídos, o vacía si el archivo no existe.
**/

bool cargaEquipos(tListaEquipos & listaEquipos);

/**
** dada una lista ordenada de equipos y un código, devuelve la posición (índice) para ese código en la lista;
** y si se ha encontrado o no un equipo con ese código.
**/

bool buscaEquipo(tListaEquipos & listaEquipos, string codigo, int & pos);

/**
** dada una lista de equipos y un equipo, añade éste a la lista.
** La lista debe seguir ordenada por código.
**/

void insertaEquipo(tListaEquipos & listaEquipos, string codigo, const tComponente & componente, int pos);

/**
** Muestra la información de un equipo.
**/

void muestraEquipo(tEquipo & equipo);

/**
** Muestra la lista de equipos.
**/

void muestraEquipos(const tListaEquipos & listaEquipos);

/**
** Aplica a todos los componentes el porcentaje de incremento que se proporciona,
** actualizando los precios de los equipos.
**/

void actualiza(const tListaEquipos & listaEquipos);

void destruir(tListaEquipos & listaEquipos);

#endif
