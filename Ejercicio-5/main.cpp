#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"ListaAlquileres.h"



int main(){
	tListaAlquiler listaAlquiler;
	tListaCoches listaCoches;
	
	leerModelos(listaCoches);
	leerAlquileres(listaAlquiler);
	ordenar(listaAlquiler);
	mostrar (listaAlquiler, listaCoches);
	system("pause");	
	return 0;
}