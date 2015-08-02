
#include<iostream>
#include<string>
#include<fstream>
#include"ListaClientes.h"
using namespace std;

int main(){
	tListaClientes clientes; //un nombre mas represaentativo seria mas facil de manejar ej: listaClientes
	
	carga (clientes);
	muestra (clientes);
	system("pause");
	destruye (clientes);
	
	return 0;	
}