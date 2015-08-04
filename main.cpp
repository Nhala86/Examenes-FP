
#include<iostream>
#include<string>
#include<fstream>
#include"ListaClientes.h"
using namespace std;
const string ARCHIVO = "datos.txt";

int main(){
	tListaClientes listaclientes; //un nombre mas represaentativo seria mas facil de manejar ej: listaClientes
	ifstream fichero;
	fichero.open(ARCHIVO);
	
	if(!fichero.is_open()){
		cout << "Error";
	}
	else{
		carga (fichero, listaclientes);
		muestra (listaclientes);
		fichero.close();
		destruye (listaclientes);
	}	
	system("pause");	
	return 0;	
}