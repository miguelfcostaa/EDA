#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale>
#include <string>
#include "gestor.h"
#include "sector.h"


using namespace std;

int main() {
	locale::global(locale());
	int Nsector = rand() % 12 + 8;	//numero random de 8 a 12
	cout << Nsector << endl;
	sector* sectores = new sector[Nsector];	//criar object para a struct
	criasector(sectores, Nsector);	//criar os sectores antes de mostrar
	char escolha;
	bool sair = false;
	do {
		cout << "(s) Seguinte   |   (g)Gestão   |   (n)Sair" << endl;
		cin >> escolha;
		switch (escolha) {
		case 's':
			mostraSector(sectores, Nsector);
			break;
		case 'g':
			gestor();
			break;
		case 'n':
			sair = true;
			break;
		default:
			cout << "Escolha uma opçâo válida" << endl;
			break;
		}
	} while (!sair);
	return 0;
}
