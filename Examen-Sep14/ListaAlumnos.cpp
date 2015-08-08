
#include"ListaAlumnos.h"
using namespace std;

void inicializar (tListaAlumnos & listaAlumnos){
	listaAlumnos.contador = 0;

	for(int i = 0; i < MAX_ALUMNOS; i++)
		listaAlumnos.alumno[i]= nullptr;

}

void totalEstadisticas (tListaAlumnos & listaAlumnos, tArrayCalificacionesAlumnos & arrayCalificacionesAlumnos){
	/**
	int s = 0, a = 0, b = 0, n = 0, x = 0;
	for(int i = 0; i < listaAlumnos.contador; i++){
		if(listaAlumnos.alumno[listaAlumnos.contador].listaExamenes.examen[i]->notaCualitativa == "SS"){
			s[0] = s + 1;
		}
		else if(listaAlumnos.alumno[listaAlumnos.contador].listaExamenes.examen[i]->notaCualitativa == "AP"){
			a[1] = a + 1;
		}
		else if(listaAlumnos.alumno[listaAlumnos.contador].listaExamenes.examen[i]->notaCualitativa == "B"){
			b[2] = b + 1;
		}
		else if(listaAlumnos.alumno[listaAlumnos.contador].listaExamenes.examen[i]->notaCualitativa == "NT"){
			n[3] = n + 1;
		}
		else if (listaAlumnos.alumno[listaAlumnos.contador].listaExamenes.examen[i]->notaCualitativa == "SB"){
			x[4] = x + 1;
		}
	}
	cout << "SS/ " << s << setw(4) << "AP/ " << a << setw(4) << "B/ " << b << setw(4) << "NT/ " << n << setw(4) << "SB/ " << x << endl;
	return s;
	**/
	for(int j = 0; j <5; j++)
	arrayCalificacionesAlumnos[j] = 0; //inicializar el array

	for(int i = 0; i < listaAlumnos.contador; i++){
		for(int k = 0; k < listaAlumnos.alumno[i]->listaExamenes.contador; k++){
			double nota = listaAlumnos.alumno[i]->listaExamenes.examen[k].notaNumerica;

			if(nota < 5) arrayCalificacionesAlumnos[0]++;
			else if(nota >=5 && nota < 6) arrayCalificacionesAlumnos[1]++;
			else if(nota >=6 && nota < 7) arrayCalificacionesAlumnos[2]++;
			else if(nota >=7 && nota < 9) arrayCalificacionesAlumnos[3]++;
			else arrayCalificacionesAlumnos[4]++;
		}
	}
}


void muestra (tListaAlumnos & listaAlumnos){
		tArrayCalificacionesAlumnos arrayCalificacionesAlumnos;//necesario para las estadisitcas globales
	for(int i = 0; i < listaAlumnos.contador; i++){
		cout << "-------------------------------------------------------------------" << endl;
		cout << "NIF: " << listaAlumnos.alumno[i]->nif << endl;
		muestra(listaAlumnos.alumno[i]->listaExamenes);
		cout << "-------------------------------------------------------------------" << endl;
	}
	/**
	cout << "Total: " /*<< totalEstadisticas (listaAlumnos);
	*/
	totalEstadisticas(listaAlumnos, arrayCalificacionesAlumnos);
	cout << "Total : ";
	cout << "SS:" << arrayCalificacionesAlumnos[0] << "  AP: " << arrayCalificacionesAlumnos[1] << "  B:" << arrayCalificacionesAlumnos[2] << "  NT:" << arrayCalificacionesAlumnos[3] << " SB:" << arrayCalificacionesAlumnos[4] << endl;


}


bool busca (tListaAlumnos & listaAlumnos, string nif, int & posicion){
	int ini = 0, mitad, fin = listaAlumnos.contador - 1;
	bool oK = false;
	while((ini <= fin) && !oK){
		mitad = (ini + fin)/2;
		if(nif < listaAlumnos.alumno[mitad]->nif){
			fin = mitad - 1;
		}
		else if (listaAlumnos.alumno[mitad]->nif < nif){
			ini = mitad + 1;
		}
		else oK = true;
	}
	if(oK) posicion = mitad;
	else posicion = ini;
	return oK;
}

void insertaAlumno (tListaAlumnos & listaAlumnos, string nif, int pos, const tExamen & examen){
	tAlumno alumno;

	alumno.nif = nif;
	inicializar(alumno.listaExamenes);
	alumno.listaExamenes.examen[0] = examen;
	alumno.listaExamenes.contador++;

	for(int i = listaAlumnos.contador; i > pos; i--){ // no es i<pos, es i > pos
		listaAlumnos.alumno[i] = listaAlumnos.alumno[i - 1];
	}
		listaAlumnos.alumno[pos] = new tAlumno (alumno); //esto genera la excepcion del programa, HAY QUE ARREGLARLO

//	insertaNota (listaAlumnos.alumno[pos]->listaExamenes, examen); la reutilizacion de codigo a veces es contraproducente
		listaAlumnos.contador++;
}

void carga (ifstream & archivo, tListaAlumnos & listaAlumnos){
	tExamen examen;
	string nif, fecha;
	int posicion;
	//string codigo; no lo necesitas, el criterio de busqueda es el nif en si mismo
	//	inicializar (listaAlumnos); esto mejor en el main

	archivo >> nif;
	while(nif != CENTINELA && listaAlumnos.contador < MAX_ALUMNOS){
		archivo >> examen.fecha;
		archivo >> examen.notaNumerica;
		examen.notaCualitativa = notaCualitativa(examen.notaNumerica);//La idea es reaprovechar tu codigo siemrpe que se pueda
		//archivo >> examen.notaCualitativa;	cada linea son 3 datos. NIF, FECHA, NOTA, esta cuarta linea que pides
		if(!busca(listaAlumnos, nif, posicion)){
			insertaAlumno(listaAlumnos, nif, posicion, examen);
		}
		else {
			insertaNota(listaAlumnos.alumno[posicion]->listaExamenes, examen);
		}
		archivo >> nif;
	}
}

void destruye (tListaAlumnos & listaAlumnos){
	for(int i = 0; i < listaAlumnos.contador; i++){
		destruye (listaAlumnos.alumno[i]->listaExamenes);
		delete listaAlumnos.alumno[i];
		//delete [] listaAlumnos.alumno[i];
	}
}
