#include <stdlib.h>
#include<iostream>
#include <time.h>
#include <fstream>
#include <string>
#include "sector.h"

using namespace std;


//Ler o file dos produtos linha a linha
string* produtos() {
	ifstream produto("nomes.txt");
	string l;
	string* lines = new string[100];
	int i = 0;
	if (produto.is_open()) {
		while (getline(produto, l)) {
			lines[i] = l;
			i++;
		}
		produto.close();

	}
	return lines;
}



//Dar o nome do responsavel
string* nomes(sector* sectores, int i) {
	string* nome = new string[30];
	cout << "Insira o nome do responsavel do sector " << sectores[i].letra << " : ";
	cin >> sectores[i].nome;
	return nome;
}

//Dar a capacidade do sector
int capacidade() {
	int Ncapacidade = rand() % 5 + 5;
	return Ncapacidade;
}

int Nproduto(sector* sectores, int Nsector) {
	for (int i = 0; i < Nsector; i++) {
		int Nprodutos = rand() % sectores[i].capacidade + 1;
		return Nprodutos;
	}
	return 0;
}


//Ler a lista das areas
string* areas() {
	ifstream area("area.txt");
	string l;
	string* line = new string[16];
	int i = 0;
	if (area.is_open()) {
		while (getline(area, l)) {
			//cout << "HELOOOO" << endl;
			line[i] = l;
			i++;
		}
		area.close();
	}
	return line;
}


//Funcao para criar os sectores
sector* criasector(sector* sectores, int Nsector) {
	char* letra = new char[26]{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M' };
	for (int i = 0; i < Nsector; i++) {
		sectores[i].letra = letra[i];
		string* name = nomes(sectores, i);
		sectores[i].capacidade = capacidade();
		sectores[i].Nproduto = Nproduto(sectores, Nsector);
		string* lines = areas();
		sectores[i].areas = lines[i];
	}
	return sectores;
}

int fullcapacidade(sector* sectores, int Nsector) {
	int aux = 0;
	for (int i = 0; i < Nsector; i++) {
		aux = aux + sectores[i].capacidade;
	}
	return aux;
}

prod* criaProd(sector* sectores, prod* produt, int Nsector) {
	for (int i = 0; i < fullcapacidade(sectores,Nsector); i++) {
			produt[50].preco = 2 * (rand() % 40 + 1);
			string* line = produtos();
			produt[0].produto = line[i];
	}
	return produt;
}



//Funcao para mostrar os sectores
void mostraSector(sector* sectores, prod* produt, int Nsector) {
	cout << endl;
	for (int i = 0; i < Nsector; i++) {
		cout << "Sector : " << sectores[i].letra << "  |  Responsavel : " << sectores[i].nome << "  |  Capacidade : " << sectores[i].capacidade << "  |  Produtos : " << sectores[i].Nproduto << "  |  Área : " << sectores[i].areas << endl;
		for (int j = 0; j < sectores[i].Nproduto; j++) {
			cout << "Produto : " << produt[j].produto;
			cout << "  |  Preço : " << produt[j].preco << " Euros" << endl;
			cin.ignore();
		}
		cout << endl << "-----------------------------------------------------" << endl;
	}
	cout << endl;
}
