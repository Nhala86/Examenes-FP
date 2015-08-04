#ifndef ListaClientes_H
#define ListaClientes_H

#include<iostream>
#include<string>
#include<fstream>
#include"ListaProductos.h"
using namespace std;

const int MAX_CLIENTES = 100;
const string CENTINELA = "XXX";

typedef struct{
	string nif;
	tListaProd listaProductos; //este nombre te generara confusion mas adelante, es mejor dejar nombres claro ej: listaProductos
}tCliente;

typedef struct{
	tCliente* cliente[MAX_CLIENTES]; //esto es un array dinamico de puunteros, se pide un array estatico de punteros
	int contador;
}tListaClientes;

/**
** Inicializo la lista de clientes
**/

void inicializar (tListaClientes & listaclientes);

/**
** Dada una lista de clientes y un NIF localiza en la lista un cliente con ese NIF. Hará uso del algoritmo recursivo de búsqueda binaria.
**/

bool encuentra (const tListaClientes & listaclientes, string codigo, int & posicion);

/**
** Dada una lista de clientes devuelve el total de las ventas.
**/

double totalVentas (tListaClientes & listaclientes);

/**
** Dada una lista de clientes, un NIF y un producto, añade un nuevo cliente con ese NIF (y ese producto como primera venta) en la lista de clientes.
** La lista de clientes debe seguir estando ordenada por NIF tras insertar. Si la lista está llena, se ignora el nuevo cliente.
**/

void insertar (tListaClientes & listaclientes, int pos, int nuevo); //tipo int no es adecuado, ademas se le pasan 3 PARAMETROS, no 1

/**
** Dada una lista de clientes, carga en ella la información de un archivo datos.txt que contiene en cada línea la información de una venta: NIF del cliente, código de producto, precio y unidades vendidas.
** El subprograma lee cada venta y localiza el cliente con el NIF. Si no existe se añade uno nuevo a la lista de clientes con ese primer producto.
** Si existe, se aña-de el producto a la lista de productos del cliente existente.
**/

void carga (ifstream fichero, tListaClientes & listaclientes);

/**
** Dada una lista de clientes muestra sus ventas en la pantalla. Termi-na mostrando el total de las ventas.
**/

void muestra (const tListaClientes & listaclientes);

/**
** Dada una lista de clientes libera la memoria dinámica que utiliza.
**/

void destruye (tListaClientes & listaclientes); //vois??? XD



#endif