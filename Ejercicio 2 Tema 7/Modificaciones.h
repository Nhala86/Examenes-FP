#ifndef Modificaciones_H
#define Modificaciones_H


#include"ListaProductos.h"


const int MAX_MOD = 50;

typedef enum {venta, compra, devolucion}tOperacion;

typedef struct {
	int codigo;
	tOperacion operacion;
	int unidades;
}tModificacion;

typedef struct{
	tModificacion modificacion[10];
	int contador;
}tListaModificaciones;

void inicializar (tListaModificaciones & listaModificaciones);

bool carga (tListaModificaciones & listaModificaciones);

tOperacion charToOperacion (char operacion);

bool crearModificiacion(ifstream & archivo , tModificacion & modificacion);

void insertarModificacion(tListaModificaciones & listaModificaciones, const tModificacion & modificacion);
#endif