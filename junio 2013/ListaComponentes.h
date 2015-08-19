#ifndef ListaCompenentes_H
#define ListaComponentes_H

#include"Componentes.h"

const double IVA = 21;
const int MAX_COMP = 20;


typedef struct{
	tComponente* componentes; //array dinamico
	int contador;
}tListaComponentes;

void inicializar(tListaComponentes & listaComponentes);

/**
** dado un equipo y un componente, añade éste último a
**la lista de componentes del equipo y actualiza el precio del equipo.
**/

bool insertaComponente(tListaComponentes & listaComponentes, const tComponente & componente);

void mostrar(const tListaComponentes & listaComponentes);

double totalPrecio(tListaComponentes & listaComponentes);

void destruir(tListaComponentes & listaComponentes);

#endif
