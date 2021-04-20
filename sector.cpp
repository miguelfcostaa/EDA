#include <stdlib.h>
#include<iostream>
#include <time.h>
#include <fstream>
#include <string>
#include "sector.h"

using namespace std;

//Dar o nome do responsavel
string* nomes(sector* sectores, int i) {
	string* nome = new string[30];
	cout << "Insira o nome do responsavel do sector " << sectores[i].letra << " : ";
	return nome;
}

//Dar a capacidade do sector
int capacidade() {
	int Ncapacidade = rand() % 10 + 5;
	return Ncapacidade;
}


int Nprodutos() {
	return 0;
};

//Ler a lista dos produtos
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

//Ler a lista das areas
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

//Funcao para criar os sectores
sector* criasector(sector* sectores, int Nsector) {
	char* letra = new char[26]{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	for (int i = 0; i < Nsector; i++) {
		sectores[i].letra = letra[i];
		string* name = nomes(sectores, i);
		sectores[i].nome = name[i];
		sectores[i].capacidade = capacidade();
		sectores[i].Nprodutos = Nprodutos();
		string* line = produtos();
		sectores[i].produtos = line[i];
		string* lines = areas();
		sectores[i].areas = lines[i];
		cin.ignore();
		cin.get();
	}
	return sectores;
}

//Funcao para mostrar os sectores
void mostraSector(sector* sectores, int Nsector) {
	for (int i = 0; i < Nsector; i++) {
		cout << "Sector : " << sectores[i].letra << "  |  Responsavel : " << sectores[i].nome << "  |  Capacidade : " << sectores[i].capacidade << "  |  Ocupação : " << sectores[i].Nprodutos << "  |  Área : " << sectores[i].areas << endl;
		cout << "Produto : " << sectores[i].produtos << "  |  Preço : " << endl;
		cout << endl;
	}
}
