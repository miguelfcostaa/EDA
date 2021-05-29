#include "armazem.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "sector.h"

using namespace std;


//Ler o file dos produtos linha a linha
string* produtos() {
	ifstream produto("nomes_.txt");
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

string* fornecedores() { // retorna uma lista com os fornecedores
	ifstream pFicheiro("fornecedores.txt");
	string p;
	string* list = new string[16];
	int i = 0;
	if (pFicheiro.is_open()) {
		while (getline(pFicheiro, p)) {
			list[i] = p;
			i++;
		}
		pFicheiro.close();
	}
	return list;
}

//Dar o nome do responsavel
string* nomes(sector* sectores, int i) {
	string* nome = new string[30];
	cout << "Insira o nome do responsavel do sector " << sectores[i].letra << " : ";
	cin >> sectores[i].nome;
	return nome;
}


int preco() {
	int n = rand() % 40 + 1;
	return n * 2;
}


//Ler a lista das areas
string* areas() {
	ifstream area("area.txt");
	string l;
	string* line = new string[16];
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

void prodVend(sector* sectores, int Nsector) {
	int vend;  //probailidade de 25% 
	for (int i = 0; i < Nsector; i++) {
		for (int j = 0; j < sectores[i].Nproduto; j++) {
			vend = rand() % 4 + 1;
			if (vend == 1) {
				sectores[i].prods[j].vendido = true;
				sectores[i].prods[j].vendido = sectores[i].prods[j + 1].vendido;
				sectores[i].Nproduto--;
			}
		}
	}

}

//Funcao para criar os sectores
sector* criasector(sector* sectores, int Nsector, prod* produt, armazem* ap) {
	int aux = 0;
	int capacidade; int Nproduto;
	char* letra = new char[26]{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M' };
	for (int i = 0; i < Nsector; i++) {
		capacidade = rand() % 5 + 5;
		Nproduto = rand() % capacidade + 1;
		int a = rand() % 16;
		string* lines = areas();
		string* produ = produtos();
		sectores[i].letra = letra[i];
		string* name = nomes(sectores, i);
		sectores[i].capacidade = capacidade;
		sectores[i].Nproduto = Nproduto;
		sectores[i].areas = lines[a];
		sectores[i].prods = removeProdArm(ap,Nproduto,produt,sectores);
		produt[i].preco = preco();
	}
	return sectores;
}


//Funcao para mostrar os sectores
void mostraSector(sector* sectores, prod* produt, int Nsector) {
	cout << endl;
	int aux = 0;
	for (int i = 0; i < Nsector; i++) {
		cout << endl << "Sector : " << sectores[i].letra << "  | ";
		cout << "Responsavel: " << sectores[i].nome << " | ";
		cout << "Capacidade: " << sectores[i].capacidade << " | ";
		cout << "Produtos: " << sectores[i].Nproduto << " | ";
		cout << "Área: " << sectores[i].areas << endl;
		for (int j = 0; j < sectores[i].Nproduto; j++) {
			cout << "Produto : " << sectores[i].prods[j].produto << "  |  Preço : " << sectores[i].prods[j].preco << " Euros" << endl;
		}
		cout << endl << "------------------------------------------------------------------------------" << endl;
	}
	cout << endl;
}
