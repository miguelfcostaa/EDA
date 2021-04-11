#include <iostream>
#include < stdlib.h >
#include <time.h>
#include <locale>

using namespace std;

int main() {
	locale::global(locale(""));
	int escolha = -1;
	cout << "(s) Seguinte   |   (g) Gestão   |   (n) Sair" << endl;
	cin >> escolha;
	if (escolha == 's') {

	}
	else if (escolha == 'g') {

	}
	else if (escolha == 'n') {

	}
	return 0;
}
