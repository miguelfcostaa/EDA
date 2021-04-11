#include <iostream>
#include < stdlib.h >
#include <time.h>
#include <locale>
#include "Gestor.h"
#include "Setores.h"


using namespace std;


int main() {
	locale::global(locale(""));
	int escolha = -1;
	cout << "(s) Seguinte   |   (g)Gestão   |   (n)Sair" << endl;
	cin >> escolha;
	if (escolha == 's') {
		sector();
	}
	else if (escolha == 'g') {
		Gestor();
	}
	else if (escolha == 'n') {

	}
	return 0;
}
