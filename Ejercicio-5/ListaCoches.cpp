
#include"ListaCoches.h"


void inicializar(tListaCoches & listaCoches){
	listaCoches.contador = 0;
}

bool leerModelos(tListaCoches & listaCoches){
	ifstream archivo;
	tCoche coche;
	archivo.open(FICHERO);
	bool esLeido = archivo.is_open();
	if(esLeido){
		inicializar(listaCoches);
		while(leerCoche(archivo, listaCoches.coche) && listaCoches.contador < MAX_COCHES){			
			insertarCoche(listaCoches, coche);
		}
	}
	else{
		cout << "No se ha podido leer el archivo";
	}
	archivo.close();
	return esLeido;
}

bool buscar(tCoche & coche, int & posicion, int codigo, tListaCoches & listaCoches){
	int ini = 0, mitad, fin = listaCoches.contador - 1;
	bool esEncontrado = false;
	while((ini <= fin) && !esEncontrado){
		mitad = (ini + fin) / 2;
		if(codigo < coche[mitad].codigo){
			fin = mitad - 1;
		}
		else if(coche[mitad].codigo < codigo){
			ini = mitad + 1;
		}
		else esEncontrado = true;
	}
	if(esEncontrado) posicion = mitad;
	else posicion = ini;
	return esEncontrado;	
}

void mostrar (const tListaCoches & listaCoches, const tCoche & coche){
	for(int i = 0; i < listaCoches.contador; i++){
		cout << coche.modelo[i] << endl;
	}	
}

bool leerCoche (ifstream & archivo, tCoche & coche){
	bool ok = false;
	int codigo;
			archivo >> codigo;
			if(codigo != CENTINELA){
			coche.codigo = codigo;
			archivo >> coche.modelo;
			ok = true;
			}
		return ok;
}
void insertarCoche(tListaCoches & listaCoches, tCoche & coche){
		listaCoches.coche[listaCoches.contador] = coche;
		listaCoches.contador++;
}