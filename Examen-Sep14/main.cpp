#include<iostream>
#include<fstream>
#include<string>
#include"ListaAlumnos.h"
using namespace std;

const string FICHERO = "datos.txt";

int main(){
	tListaAlumnos listaAlumnos;
	inicializar (listaAlumnos);
	ifstream archivo;
	archivo.open(FICHERO);

	if(!archivo.is_open()){
		cout << "Error, archivo no abierto";
	}
	else{
		carga (archivo, listaAlumnos);
		muestra (listaAlumnos);
		destruye (listaAlumnos);
	}
	system("pause");

	return 0;
}


