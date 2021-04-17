#include <stdlib.h>
#include<iostream>
#include <time.h>
#include <fstream>
#include <string>
#include "Setores.h"

using namespace std;




int letra(int i) {
//{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	return 0;
}

int nome(int nome) {
	cout << "Insira o nome do responsavel do sector " << letra << " : ";
	cin >> nome;
	cout << endl;
	return nome;
}

void capacidade(int capacidade) {
	capacidade = rand() % 10 + 5;
}

void ocupacao() {

}

string produto() {
	ifstream produto("nome.txt");
	string line;
	while (produto.good()) {
		getline(produto, line);
		line = produto.get();
		cout << line;
	}
	produto.close();
	return line;
}

string area() {
	ifstream area("areas.txt");
	string line;
	while (area.good()) {
		getline(area, line);
		line = area.get();
		cout << line;
	}
	area.close();
	return line;
}


int sector(int Nsector) {
	for (int i = 0; i < Nsector; i++) {
		cout << "Sector : " << letra << "  |  Responsavel : " << nome << "  |  Capacidade : " << capacidade << "  |  Ocupação : " << ocupacao << "  |  Área : " << area << endl;
		cout << "Produto : " << produto << "  |  Preço : " << endl;

	}
	return 0;
}
