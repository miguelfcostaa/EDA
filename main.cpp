#include <iostream>
#include < stdlib.h >
#include <time.h>
#include <locale>
#include "Gestor.h"
#include "sector.h"


using namespace std;


int main() {
	locale::global(locale(""));
	char escolha;
	int Nsector = rand() % 12 + 8;
	bool sair = false;
	do {
		cout << "(s) Seguinte   |   (g)Gestão   |   (n)Sair" << endl;
		cin >> escolha;
		switch (escolha) {
		case 's':
			sector(Nsector);
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


