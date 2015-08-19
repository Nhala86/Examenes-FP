
#include"Modificaciones.h"



void procesar(tListaModificaciones & listaModificaciones, tListaProductos & listaProductos);

int main(){
	tListaModificaciones listaModificaciones;
	tListaProductos listaProductos;
		
	if(cargar(listaProductos) && carga(listaModificaciones)){
		procesar(listaModificaciones, listaProductos);
		guardar (listaProductos);		
	}
	else cout << "la carga no ha sido posible";	
	system("pause");
	return 0;
}




void procesar(tListaModificaciones & listaModificaciones, tListaProductos & listaProductos){
	int posicion;
	for(int i = 0; i < listaModificaciones.contador; i++){
		posicion = buscar(listaProductos, listaModificaciones.modificacion[i].codigo);
		if(posicion != CENTINELA){
			if(listaModificaciones.modificacion[i].operacion == venta){
				listaProductos.producto[posicion].unidades -= listaModificaciones.modificacion[i].unidades;
			}
			else
				listaProductos.producto[posicion].unidades += listaModificaciones.modificacion[i].unidades;
		}		
	}
}
				
			
		
