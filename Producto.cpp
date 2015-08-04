
#include "Producto.h"

using namespace std;


/**
Es importante discernir cuando un PARAMETRO se pasa como copia o como lectura, en este caso, leemos los datos del producto
pero no vamos a modificar nada, asi que hay que pasarlo como lectura (const tProducto & producto)
**/

void muestra(const tProducto & producto){
	cout << producto.codigo << setw (3) << " - " << producto.unidades << setw (2) << " x " << setw (2) << producto.precio << " = " << totalVenta (producto) << endl;
}

/**
Cuidado con la dicotomía del lenguaje natural. Si lees con cuidado veras que la descripcion de la funcion dice:

"Dado un producto DEVUELVE el total de la venta de ese producto"

En otras palabras, significa que RECIBE un parametro (const tProducto & producto), que lo pasamos solo como copia,
ya que no lo vamos a modificar, solo queremos acceder al dato. Y DEVOLVEMOS otro parametro, notese que este 
procedimiento no devuelve nada (ningun void lo hace). Asi que aunque la funcion es correcta en funcionamiento
esta mal como RESULTADO.

**/

double totalVenta (tProducto & producto){
	double total;
	total = producto.precio * producto.unidades;
	return total;
}