#include"Equipos.h"

void inicializar(tListaEquipos & listaEquipos){
	for(int i = 0; i > MAX_EQUIP; i++){
		listaEquipos.equipo[i] = nullptr;
	}
	listaEquipos.contador = 0;
}

bool cargaEquipos(tListaEquipos & listaEquipos){
	int pos;
	string codigo;
	bool cargado = false;
	ifstream archivo;
	archivo.open(FICHERO);
	if(archivo.is_open()){

		archivo >> codigo;
		while(codigo != CENTINELA){
			tComponente componente;

			if(buscaEquipo(listaEquipos, codigo, pos)){
				leerComponete(archivo, componente);
				insertaComponente(listaEquipos.equipo[pos]->listaComponentes, componente);
			}

			else{
				leerComponete(archivo, componente);
				insertaEquipo(listaEquipos, codigo, componente, pos);
			}

			archivo >>codigo;
		}

		cargado = true;
	}
	archivo.close();
	return cargado;
}



bool buscaEquipo(tListaEquipos & listaEquipos, string codigo, int & pos){
	int ini = 0, mitad, fin = listaEquipos.contador - 1;
	bool esEncontrado = false;
	while((ini <= fin) && !esEncontrado){
		mitad = (ini + fin)/2;
		if(codigo < listaEquipos.equipo[mitad]->codigo){
			fin = mitad - 1;
		}
		else if (listaEquipos.equipo[mitad]->codigo < codigo){
			ini = mitad + 1;
		}
		else esEncontrado = true;
	}
	if(esEncontrado) pos = mitad;
	else pos = ini;
	return esEncontrado;
}



void insertaEquipo(tListaEquipos & listaEquipos, string codigo, const tComponente & componente, int pos){

		tEquipo equipo;
		equipo.codigo = codigo;
		inicializar(equipo.listaComponentes);
		insertaComponente(equipo.listaComponentes, componente);
		equipo.precio = totalPrecio(equipo.listaComponentes);

		for(int i = listaEquipos.contador; i > pos; i--){
			listaEquipos.equipo[i] = listaEquipos.equipo[i - 1];
		}
		listaEquipos.equipo[pos] = new tEquipo (equipo);
		listaEquipos.contador++;

}


void muestraEquipo(tEquipo & equipo){
	cout << equipo.codigo << endl;
	mostrar(equipo.listaComponentes);
	equipo.precio = totalPrecio(equipo.listaComponentes);
	cout << "Precio de equipo: " << equipo.precio << endl;
}


void muestraEquipos(const tListaEquipos & listaEquipos){
	for(int i = 0; i < listaEquipos.contador; i++)
		muestraEquipo(*listaEquipos.equipo[i]);
}


void destruir(tListaEquipos & listaEquipos){
	for(int i = 0; i < listaEquipos.contador; i++)
		destruir(listaEquipos.equipo[i]->listaComponentes);

		delete listaEquipos.equipo[MAX_EQUIP];
}

void actualiza(const tListaEquipos & listaEquipos){
	double  incremento, nuevo;
	cout << "Introduzca el incremento de porcentaje de precio para los componentes: ";
	cin >> incremento;
	cin.sync();

	for(int i = 0; i < listaEquipos.contador; i++)
		for(int j = 0; j < listaEquipos.equipo[i]->listaComponentes.contador; j++){
			nuevo = listaEquipos.equipo[i]->listaComponentes.componentes[j].precio;
			nuevo += nuevo*incremento/100;
			listaEquipos.equipo[i]->listaComponentes.componentes[j].precio = nuevo;
		}
}
