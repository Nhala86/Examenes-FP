#include"Modificaciones.h"

void inicializar (tListaModificaciones & listaModificaciones){
	listaModificaciones.contador = 0;
}

bool carga (tListaModificaciones & listaModificaciones){
	bool ok = false;
	ifstream archivo;
	archivo.open("modificaciones.txt");
	if(archivo.is_open()){
		inicializar(listaModificaciones);
		tModificacion modificacion;
		
		while(listaModificaciones.contador < MAX_MOD && crearModificiacion(archivo, modificacion)){
			insertarModificacion(listaModificaciones, modificacion);
		}
		ok = true;
	}
	return ok;
}

bool crearModificiacion(ifstream & archivo , tModificacion & modificacion){
	
	char operacion;
	bool esModificacion = false;
	archivo >> modificacion.codigo;
	if(modificacion.codigo != CENTINELA){
		archivo >> operacion;
		modificacion.operacion = charToOperacion(operacion);
		archivo >> modificacion.unidades;
		esModificacion = true;
	}
	return esModificacion;
}

tOperacion charToOperacion (char operacion){
	
	tOperacion tipoOperacion;
	
	if(operacion == 'V') tipoOperacion = venta;
	else if(operacion == 'C') tipoOperacion = compra;
	else tipoOperacion = devolucion;
	
	return tipoOperacion;
}
	
void insertarModificacion(tListaModificaciones & listaModificaciones, const tModificacion & modificacion){
	listaModificaciones.modificacion[listaModificaciones.contador] = modificacion;
	listaModificaciones.contador++;
	}