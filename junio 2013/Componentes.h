#ifndef Compenentes_H
#define Componentes_H

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>


using namespace std;

typedef struct{
	string codigo;
	string nombre;
	double precio;
}tComponente;

void mostrar(const tComponente & componente);

void leerComponete(ifstream & archivo, tComponente & componente);

#endif
