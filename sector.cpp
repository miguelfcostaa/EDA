#include <stdlib.h>
#include<iostream>
#include <time.h>
#include <fstream>
#include <string>
#include "sector.h"

using namespace std;

int nomes() {
	int i;
	sector* sectores;
	int nome;
	cout << "Insira o nome do responsavel do sector " << sectores[i].letra << " : ";
	cin >> nome;
	cout << endl;
	return nome;
}

int capacidade() {
	int Ncapacidade = rand() % 10 + 5;
	return Ncapacidade;
}

int Nprodutos(){
	return 0;
};

string* produtos() {
	ifstream produto("nome.txt");
	string l;
	string* line = new string[24];
	int i = 0;
	if (produto.is_open()) {
		while (getline(produto, l)) {
			line[i] = l;
			i++;
		}
		produto.close();
	}
	return line;
}


string* areas() {
	ifstream area("areas.txt");
	string l;
	string* line = new string[24];
	int i = 0;
	if (area.is_open()) {
		while (getline(area, l)) {
			line[i] = l;
			i++;
		}
		area.close();
	}
	return line;
}

sector* criasector(sector* sectores, int Nsector) {
	char* alfa = new char[26] { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	string* line = produtos();
	string* lines = areas();
	for (int i = 0; i < Nsector; i++) {
		sectores[i].letra = alfa[i];
		sectores[i].nome = nomes();
		sectores[i].capacidade = capacidade();
		sectores[i].Nprodutos = Nprodutos();
		sectores[i].produtos = line[i];
		sectores[i].areas = lines[i];
	}
	return sectores;
}

void mostraSector(sector* sectores, int Nsector) {
	for (int i = 0; i < Nsector; i++) {
		cout << "Sector : " << sectores[i].letra << "  |  Responsavel : " << sectores[i].nome << "  |  Capacidade : " << sectores[i].capacidade << "  |  Ocupação : " << sectores[i].Nprodutos << "  |  Área : " << sectores[i].areas << endl;
		cout << "Produto : " << sectores[i].produtos << "  |  Preço : " << endl;
		cout << endl;
	}
}
