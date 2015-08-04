
#include"ListaClientes.h"

using namespace std;

void inicializar (tListaClientes & listaclientes){
	for(int i = 0; i < MAX_CLIENTES; i++){
		listaclientes.cliente[i] = nullptr;
	}
	clientes.contador = 0;
}

bool encuentra (const tListaClientes & listaclientes, string codigo, int & posicion){
	int ini = 0, fin = listaclientes.contador - 1, mitad;
	bool oK = false;
	while((ini <= fin) && !oK){
		mitad = (ini + fin)/ 2;
		if (codigo < listaclientes.cliente[mitad]->nif){
			fin = mitad - 1;
		}
		else if (listaclientes.cliente[mitad->nif < codigo]){
			ini = mitad + 1;
		}
		else oK = true;
	}
	if(oK) posicion = mitad;
	else posicion = ini;
	return oK;
}

double totalVentas (tListaClientes & listaclientes){
	double totalVenta;
	for(int i =0; i < listaclientes.contador; i++){
		totalVenta += totalVentas (listaclientes.cliente[i]-> producto);
	}
	return totalVenta;
}

void insertar (tListaClientes & listaclientes, int pos, int nuevo){ // ordenacion de arrays por insercion
	for (int i = 1; i < MAX_CLIENTES, i++){
		nuevo = listaclientes.cliente[i]->nif;
		pos = 0;
		while((pos < i) && !(listaclientes.cliente[pos]->nif > nuevo)){
			pos++;
		}
		for (int j = i; j > pos; j--){
			listaclientes.cliente[j]->nif = listaclientes.cliente[j - 1]->nif;
		}
		listaclientes.cliente[pos]->nif = nuevo;
	}
}

void carga (ifstream fichero, tListaClientes & listaclientes){
	int posicion;
	string nif;
	
	inicializar (listaclientes);
	fichero >> nif;
	while(nif != CENTINELA){
		tProducto producto;
		fichero >> codigo;
		fichero >> precio;
		fichero >> unidades;
		if(encuentra(listaclientes, codigo, posicion)){
			listaclientes.cliente[posicion] = listaclientes.cliente[posicion - 1];
		}
		listaclientes.cliente[posicion] = new tCliente(cliente);
		insertaProd(listaclientes.cliente[posicion]->producto, producto);
		listaclientes.contador++;
	}
}

void muestra (const tListaClientes & listaclientes){
	for(int i = 0; i < listaclientes.contador; i++){
		cout << "----------------------------------------------" << endl;
		cout << "Cliente: " << listaclientes.cliente[i]->nif << endl;
		muestra (listaclientes.cliente[i]->productos);
		cout << "----------------------------------------------" << endl;
	}
	cout << "Total Ventas: " << totalVentas (listaclientes) << endl;
}

void destruye (tListaClientes & listaclientes){
	for(int i = 0; i < listaclientes.contador; i++){
		destruye (listaclientes.cliente[i]->nif);
		delete listaclientes.cliente;
	}	
}