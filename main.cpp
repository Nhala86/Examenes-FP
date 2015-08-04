
#include<iostream>
#include<string>
#include<fstream>
#include"ListaClientes.h"
using namespace std;

int main(){
	tListaClientes listaclientes; //un nombre mas represaentativo seria mas facil de manejar ej: listaClientes
	
	carga (ARCHIVO, listaclientes);
	muestra (listaclientes);
	system("pause");
	destruye (listaclientes);
	
	return 0;	
}