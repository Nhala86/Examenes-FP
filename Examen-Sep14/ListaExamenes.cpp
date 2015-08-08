
#include"ListaExamenes.h"
using namespace std;


void inicializar (tListaExamenes & listaExamenes){
	listaExamenes.examen = new tExamen [MAX_EXAM];
	listaExamenes.contador = 0;
}

void estadisticaNotas (const tListaExamenes & listaExamenes, tArrayCalificaciones & arrayCalificaciones){
	/**
	int notas = 0, s = 0, a = 0, b = 0, n = 0, x = 0;
	for(int i = 0; i < listaExamenes.contador; i++){
		notas = listaExamenes.examen[i].notaNumerica;
		if(notas < 5){
			s = s + 1;
		}
		else if(notas >= 5 || notas < 6){
			a = a + 1;
		}
		else if(notas >= 6 || notas < 7){
			b = b + 1;
		}
		else if( notas >= 7 || notas < 9){
			n = n + 1;
		}
		else x = x + 1;
	}
	cout << "SS/ " << s << setw(4) << "AP/ " << a << setw(4) << "B/ " << b << setw(4) << "NT/ " << n << setw(4) << "SB/ " << x << endl;
	return notas;
	**/

	for(int j = 0; j <5; j++)
		arrayCalificaciones[j] = 0; //inicializar el array

		for(int i = 0; i < listaExamenes.contador; i++){
			double nota = listaExamenes.examen[i].notaNumerica;

		if(nota < 5) arrayCalificaciones[0]++;
		else if(nota >=5 && nota < 6) arrayCalificaciones[1]++;
		else if(nota >=6 && nota < 7) arrayCalificaciones[2]++;
		else if(nota >=7 && nota < 9) arrayCalificaciones[3]++;
		else arrayCalificaciones[4]++;
}


}


void muestraLista (const tListaExamenes & listaExamenes){
	for (int i = 0; i < listaExamenes.contador; i++){
		muestra (listaExamenes.examen[i]);
	}
}


void muestra (const tListaExamenes & listaExamenes){
		tArrayCalificaciones arrayCalificaciones; //necesario para mostrar las notas globales de la clase.

		for(int i = 0; i < listaExamenes.contador; i++){
			muestra (listaExamenes.examen[i]);
		}
    estadisticaNotas (listaExamenes, arrayCalificaciones);

		//Aprovechando la funcion de "estadisticaNotas" mostramos en un cout las calificaciones de todos los alumnos
		cout << "SS:" << arrayCalificaciones[0] << " - AP:" << arrayCalificaciones[1] << " - B:" << arrayCalificaciones[2] << " - NT:" << arrayCalificaciones[3] << " - SB:" << arrayCalificaciones[4] << endl;

}

void insertaNota (tListaExamenes & listaExamenes, const tExamen & examen){
	if(listaExamenes.contador < MAX_EXAM){
		listaExamenes.examen[listaExamenes.contador] = examen;
		listaExamenes.contador++;
	}
}

void destruye (tListaExamenes & listaExamenes){
	delete [] listaExamenes.examen;
}
