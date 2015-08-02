
#include "Producto.h"

using namespace std;

void muestra(tProducto & producto){
	cout << producto.codigo << setw (3) << " - " << producto.unidades << setw (2) << " x " << setw (2) << producto.precio << " = " << totalVenta (producto) << endl;
}


void totalVenta (tProducto & producto){
	total = producto.precio * producto.unidades;
}