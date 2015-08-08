
#include"Examenes.h"
using namespace std;

void muestra (const tExamen & examen){
	//cout << examen.fecha.ano << "/" << examen.fecha.mes << "/" << examen.fecha.dia << setw(2) << "-" << setw(2) << examen.notaNumerica << setw(2) << "-" << setw(2) << notaCualitativa(examen) << endl;
	cout << examen.fecha << setw(2) << "-" << setw(2) << examen.notaNumerica << setw(2) << "-" << setw(2) << notaCualitativa(examen.notaNumerica) << endl;

}


string notaCualitativa (int notaNumerica){
	string notaC;
	//int notaN = 0;
	//notaN = examen.notaNumerica;
	//notaC = examen.notaCualitativa;
	if(notaNumerica < 5) notaC == "SS";
	else if(notaNumerica >= 5 || notaNumerica < 6) notaC == "AP";
	else if(notaNumerica >= 6 || notaNumerica < 7) notaC == "B";
	else if(notaNumerica >= 7 || notaNumerica < 9) notaC == "NT";
	else notaC = "SB";
	return notaC;
}