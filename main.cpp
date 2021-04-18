#include <iostream>
#include < stdlib.h >
#include <time.h>
#include <locale>
#include <string>
#include "Gestor.h"
#include "sector.h"


using namespace std;


int main() {
	locale::global(locale());
	char escolha;
	int Nsector = rand() % 12 + 8;
	sector* sectores = new sector[Nsector];
	criasector(sectores, Nsector);
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
		}
	} while (!sair);
	return 0;
}


