
#include"Equipos.h"

int main(){
	tEquipo equipo;
	tListaEquipos listaEquipos;

	inicializar(listaEquipos);
	if(cargaEquipos(listaEquipos)){
		muestraEquipos(listaEquipos);
		system("pause");
		system("cls");
		actualiza(listaEquipos);
		muestraEquipos(listaEquipos);
		//destruir(listaEquipos, lista);
	}
    else cout << "Error" << endl;
	system("pause");
	return 0;
}
