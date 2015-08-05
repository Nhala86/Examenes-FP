#ifndef Producto_H
#define Producto_H

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

typedef struct{
	string codigo;
	double precio;
	int unidades;
}tProducto;



/**
** Dado un producto muestra su informaci�n en la pantalla con el si-guiente formato (c�digo � unidades x precio = total)
**/

void muestra(const tProducto & producto);

/**
** Dado un producto devuelve el total de la venta de ese producto.
**/

double totalVenta (const tProducto & producto);


#endif
