#include"ListaProductos.h"

void inicializar (tListaProductos & listaProductos){
	listaProductos.contador = 0;
}

int buscar(const tListaProductos & listaProductos, int codigo){
	int posicion;
	bool esEncontrado = false;
	int ini = 0, mitad, fin = listaProductos.contador - 1;
	
	while((ini <= fin) && !esEncontrado){
		mitad = (ini + fin) / 2;
		if(codigo < listaProductos.producto[mitad].codigo){
			fin = mitad - 1;
		}
		else if(listaProductos.producto[mitad].codigo < codigo){
			ini = mitad + 1;
		}
		else esEncontrado = true;
	}
	if(esEncontrado) posicion = mitad;
	else posicion = CENTINELA;
	return posicion; 
}

bool cargar (tListaProductos & listaProductos){
	bool ok = false;
	bool centinela = false;
	
	
	ifstream archivo;
	archivo.open("inventario.txt");
	
	if(archivo.is_open()){
		inicializar(listaProductos);
			tProducto producto;
			while(crearProducto(archivo,producto) && listaProductos.contador < MAX_PROD){
				insertarProducto(producto, listaProductos);
			}
			ok = true;
			archivo.close();
	}
	return ok;
}

bool crearProducto(ifstream & archivo,tProducto & producto){
	bool esProducto = false;
	
		archivo >> producto.codigo;
		if(producto.codigo != CENTINELA){
			archivo >> producto.nombre;
			archivo >> producto.unidades;
			archivo >> producto.precio;
			esProducto = true;
		}
	return esProducto;
}

void insertarProducto (const tProducto & producto, tListaProductos & listaProductos){
	listaProductos.producto[listaProductos.contador] = producto;
	listaProductos.contador++;

}

void guardar(const tListaProductos & listaProductos){
	ofstream archivo;
	archivo.open("inventario2.txt");
	if(archivo.is_open()){
		for (int i = 0; i < listaProductos.contador; i++){
			archivo << listaProductos.producto[i].codigo << " ";
			archivo << listaProductos.producto[i].nombre  << " ";
			archivo << listaProductos.producto[i].unidades  << " ";
			archivo << listaProductos.producto[i].precio << endl;
		}
	}
	archivo << CENTINELA;
	archivo.close();	
}
