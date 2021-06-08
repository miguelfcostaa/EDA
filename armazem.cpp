#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "Armazem.h"


using namespace std;

string* stock() {
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


armazem* criaArmazem() {
	armazem* ap = new armazem[50];
	ap->prodarm = criaProdutos(ap, 50);
	return ap;
}


prod* criaProdutos(armazem* ap, int Nproduts) {
	prod* produts = new prod[Nproduts];
	string* nomep = produtos();
	string* fornecedor = fornecedores();
	string* Area = areas();
	for (int i = 0; i < Nproduts; i++) {
		int n = rand() % 100; int f = rand() % 15; int z = rand() % 16;
		produts[i].produto = nomep[n];
		produts[i].fornecedores = fornecedor[f];
		produts[i].preco = preco();
		produts[i].area = Area[z];
		produts[i].vendido = false;
		ap->n_produtos++;
	}
	return produts;
}


void addProdutos(armazem* ap) {
	prod* produ = criaProdutos(ap, 10);
	ap->prodarm = produ;
}


void mostraArmazem(armazem* ap, sector* sectores) {
	cout << endl << "Armazem:" << endl;
	for (int i = 0; i < ap->n_produtos; i++) {
		cout << "Produto: " << ap->prodarm[i].produto;
		cout << " | Preço: " << ap->prodarm[i].preco << " Euros " << " | ";
		cout << "Area: " << ap->prodarm[i].area << endl;
	}
}


void removeProdutos(armazem* ap) {
	for (int i = 0; i < ap->n_produtos - 1; i++) {
		ap->prodarm[i].produto = ap->prodarm[i + 1].produto;
		ap->prodarm[i].preco = ap->prodarm[i + 1].preco;
	}
	ap->n_produtos--;
}



prod* removeProdArm(armazem* ap, int Nproduto, prod* produt, sector* sectores) {
	prod* produ = new prod[Nproduto];
	for (int f = 0; f < Nproduto; f++) {
		produ[f].produto = ap->prodarm[f].produto;
		produ[f].preco = ap->prodarm[f].preco;
		removeProdutos(ap);
	}
	return produ;
}
