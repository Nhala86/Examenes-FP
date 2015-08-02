#ifndef "ListaProductos_H"
#define "ListaProductos_H"

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

const int MAX_Produc = 50;

typedef struct{
	tProductoPtr productos;
	int contador;
}tListaProd;

/**
** Dada una lista de productos y un producto añade el producto al final de la lista. 
** Si la lista está llena, se ignora el nuevo producto.
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
** Dada una lista de productos libera la memoria dinámica que usa.
**/

void destrye (tListaProd & productos);

#endif