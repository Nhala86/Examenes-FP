#include"Componentes.h"

void mostrar(const tComponente & componente){
	cout << componente.codigo << setw(5) <<  componente.nombre << setw(5) << componente.precio << endl;
}

void leerComponete(ifstream & archivo, tComponente & componente){
	archivo >> componente.codigo;
	archivo >> componente.precio;
	getline(archivo, componente.nombre);
}
