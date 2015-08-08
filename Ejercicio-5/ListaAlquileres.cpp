
#include"ListaAlquileres.h"

void inicializar(tListaAlquiler & listaAlquiler){
	listaAlquiler.contador = 0;
}

bool leerAlquileres(tListaAlquiler & listaAlquiler){
	ifstream fichero;
	inicializar(listaAlquiler);
	fichero.open(ARCHIVO);
	int codigo;
	bool esLeido = fichero.is_open();
	if(esLeido){
		tAlquiler temp;
		fichero >> codigo;
		while(codigo != FINAL && listaAlquiler.contador < MAX_ALQUI){
			temp.codigo = codigo;
			fichero >> temp.fecha;
			fichero >> temp.numAlquiler;
			
			listaAlquiler.alquiler[listaAlquiler.contador] = temp;
			listaAlquiler.contador++;
			
			fichero >> codigo;
		}
	}
	else{
		cout << "NO se ha podido abrir el alquiler de coches";
	}
	fichero.close();
	return esLeido;
}


void ordenar(tListaAlquiler & listaAlquiler){
	bool intercambio = true;
	int i = 0;
	
	while((i < listaAlquiler.contador-1) && intercambio){
		intercambio = false;
		for(int j = listaAlquiler.contador - 1; j > i; j--){
			if(listaAlquiler.alquiler[j].fecha < listaAlquiler.alquiler[j-1].fecha){
				tAlquiler temp;
				temp = listaAlquiler.alquiler[j];
				listaAlquiler.alquiler[j] = listaAlquiler.alquiler[j-1];
				listaAlquiler.alquiler[j-1] = temp;
				intercambio = true;
			}
		}
		if(intercambio) i++;
	}
}

void mostrar (const tListaAlquiler & listaAlquiler, const tListaCoches & listaCoches){
	for (int i = 0; i < listaAlquiler.contador; i++){
			mostrarAlquiler(listaAlquiler.alquiler[i],listaCoches);
	}
}

void mostrarAlquiler(const tAlquiler& alquiler,const tListaCoches & listaCoches){
	int pos;
	cout << alquiler.fecha << " "; 
	if (buscar(listaCoches, alquiler.codigo ,pos))				//Se compara en la lista de modelos el codigo del alquiler para conocer su nombre, nos devuelve la posicion en la lista de modelos del codigo que buscamos
		cout << setw(20) << left << listaCoches.coche[pos].modelo 	//se escribe el nombre del modelo acudiendo a la posicion de la lista segun el codigo del alquiler
			 << " " << alquiler.dias << " dia(s)\n"; 
	else
		cout << "Error: Modelo inexistente\n";
}

