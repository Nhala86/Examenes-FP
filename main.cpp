
#include<iostream>
#include<string>
#include<fstream>
#include"ListaClientes.h"
using namespace std;

int main(){
	tListaClientes clientes;
	
	carga (clientes);
	muestra (clientes);
	system("pause");
	destruye (clientes);
	
	return 0;	
}