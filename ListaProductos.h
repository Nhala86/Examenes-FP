#ifndef "ListaProductos_H"
#define "ListaProductos_H"

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

/**
OJO!!

la tListaProd contine un tProductoPtr pero esta delcaracion esta incompleta ,ya que en ninguna parte declaras
que es un "tProductoPtr". Por otro lado, la "ListaProductos" usa SEGURO el modulo "Producto.h", si no lo incluyes,
no funcionara. Actualmente lo tienes en "ListaProductos.cpp" pero los includes anidades es mejor que se alojen
en las cabeceras ".h" por cuestiones de enlazado.

Para punteros, te seria mas sencillo declarar los "productos" como punteros a productos, que es en esencia lo que
tienes ya, salvo por el hecho de que te ahorrarias declarar "tProductoPtr"
**/

const int MAX_Produc = 50;

typedef struct{
	tProductoPtr productos;
	int contador;
}tListaProd;

/**
** Dada una lista de productos y un producto a�ade el producto al final de la lista. 
** Si la lista est� llena, se ignora el nuevo producto.
**/

void insertaProd (tListaProd & productos, tProducto & producto);

/**
** Dada una lista de productos muestra sus productos en la pantalla.
**/

void muestra (const tListaProd & productos);

/**
** Dada una lista de productos devuelve el total de esas ventas.
**/

double totalVentas (tListaProd & productos);

/**
** Dada una lista de productos libera la memoria din�mica que usa.
**/

void destrye (tListaProd & productos);

#endif