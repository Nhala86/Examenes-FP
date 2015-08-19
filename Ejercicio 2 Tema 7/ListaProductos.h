#ifndef ListaProductos_H
#define ListaProductos_H

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

const int CENTINELA = -1;
const int MAX_PROD = 50;


typedef struct {
	int codigo;
	string nombre;
	int unidades;
	double precio;
}tProducto;

typedef struct{
	tProducto producto[MAX_PROD];
	int contador;
}tListaProductos;


void inicializar (tListaProductos & listaProductos);

int buscar(const tListaProductos & listaProductos, int codigo);

bool cargar (tListaProductos & listaProductos);

void guardar(const tListaProductos & listaProductos);

void insertarProducto (const tProducto & producto, tListaProductos & listaProductos);

bool crearProducto(ifstream & archivo,tProducto & producto);

#endif