
#include"ListaClientes.h"

using namespace std;

void inicializar (tListaClientes & listaclientes){
	for(int i = 0; i < MAX_CLIENTES; i++){
		listaclientes.cliente[i] = nullptr;
	}
	listaclientes.contador = 0;
}

bool encuentra (const tListaClientes & listaclientes, string codigo, int & posicion){
	int ini = 0, fin = listaclientes.contador - 1, mitad;
	bool oK = false;
	while((ini <= fin) && !oK){
		mitad = (ini + fin)/ 2;
		if (codigo < listaclientes.cliente[mitad]->nif){
			fin = mitad - 1;
		}
		else if (listaclientes.cliente[mitad]->nif < codigo){
			ini = mitad + 1;
		}
		else oK = true;
	}
	if(oK) posicion = mitad;
	else posicion = ini;
	return oK;
}

double totalVentas (const tListaClientes & listaclientes){
	double totalVenta;
	for(int i =0; i < listaclientes.contador; i++){
		totalVenta += totalVentas (listaclientes.cliente[i]->listaProductos);
	}
	return totalVenta;
}

void insertar (tListaClientes & listaclientes, int pos, int nuevo, const tProducto & producto){ 
	tCliente cliente;
	string nif;
	cliente.nif = nif;
	inicializar (cliente.listaProductos);
	
	for (int i = listaclientes.contador; i > pos; i--){
		listaclientes.cliente[i] = listaclientes.cliente[i - 1];
	}
	listaclientes.cliente[pos] = new tCliente(cliente);
	insertaProd (listaclientes.cliente[pos]->listaProductos, producto); // AQUI ESTA EL ERROR, NO CONSIGO SOLUCIONARLO
	listaclientes.contador++;
}

void carga (ifstream & fichero, tListaClientes & listaclientes){
	int posicion, nuevo;
	string nif;
	tProducto producto;
	inicializar (listaclientes);
	fichero >> nif;
	while(nif != CENTINELA){		
		fichero >> producto.codigo;
		fichero >> producto.precio;
		fichero >> producto.unidades;
		if(encuentra(listaclientes, nif, posicion)){
			listaclientes.cliente[posicion] = listaclientes.cliente[posicion - 1];
		}
		insertar (listaclientes, posicion, nuevo, producto);
		insertaProd(listaclientes.cliente[posicion]->listaProductos, producto);
		listaclientes.contador++;
	}
}

void muestra (const tListaClientes & listaclientes){
	for(int i = 0; i < listaclientes.contador; i++){
		cout << "----------------------------------------------" << endl;
		cout << "Cliente: " << listaclientes.cliente[i]->nif << endl;
		muestra (listaclientes.cliente[i]->listaProductos);
		cout << "----------------------------------------------" << endl;
	}
	cout << "Total Ventas: " << totalVentas (listaclientes) << endl;
}

void destruye (tListaClientes & listaclientes){
	for(int i = 0; i < listaclientes.contador; i++){
		destruye (listaclientes.cliente[i]->listaProductos);
		delete listaclientes.cliente[i];
	}	
}