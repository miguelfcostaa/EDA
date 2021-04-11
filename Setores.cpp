#include <stdlib.h>
#include<iostream>
#include <time.h>
#include <fstream>

using namespace std;


int sector() {

	cout << "Sector : " << letra << "  |  Responsavel : " << nome << "  |  Capacidade : " << capacidade << "  |  Produto : " << produto << "  |  Área : " << area << endl;
	cout << "Produto : " << produto << "  |  Preço : " << endl;

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
