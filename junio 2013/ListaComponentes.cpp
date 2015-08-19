#include"ListaComponentes.h"

void inicializar(tListaComponentes & listaComponentes){
		listaComponentes.componentes = new tComponente[MAX_COMP];
	listaComponentes.contador = 0;
}

bool insertaComponente(tListaComponentes & listaComponentes, const tComponente & componente){
	bool esInsertado = false;
	if(listaComponentes.contador < MAX_COMP && !esInsertado){
		listaComponentes.componentes[listaComponentes.contador] = componente;
		listaComponentes.contador++;
		esInsertado = true;
	}
	return esInsertado;
}

void mostrar(const tListaComponentes & listaComponentes){
	for(int i = 0; i < listaComponentes.contador; i++){
		mostrar(listaComponentes.componentes[i]);
	}
}


double totalPrecio(tListaComponentes & listaComponentes){
	double precio = 0;
	for(int i = 0; i < listaComponentes.contador; i++){
		precio += listaComponentes.componentes[i].precio;
	}
	precio += precio*IVA/100;
	return precio;
}

void destruir(tListaComponentes & listaComponentes){
	delete [] listaComponentes.componentes;
}
