#include <iostream>
#include <string>
#include <fstream>
#include "sector.h"
#include "armazem.h"
#include "gestor.h"


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


armazem* criaArmazem(armazem* ap) {
	string* lines = stock();
	for (int i = 0; i < 50; i++) {
		int z = rand() % 100;
		ap[i].armazem_produtos = lines[z];
		ap[i].preco = preco();
	}
	return ap;
}


/*
void addProdutos(armazem* ap) {
	prod* produt = criaProd(5);
	armazem->stock = prod;
}
*/

int n_produtos(int n, int m) {
	int n_produtos = 0;
	n_produtos = n_produtos + n;
	n_produtos = n_produtos - m;
	return n_produtos;
}

void mostraArmazem(armazem* ap, prod* produt) {
	for (int i = 0; i < n_produtos(50,0); i++) {
		cout << "Produto: " << ap[i].armazem_produtos;
		cout << " | Preço: " << ap[i].preco << endl;
	}
}

void removeProdutos(armazem*ap) {
	for (int i = 1; i < n_produtos(0, 0); i++) {
		ap[i].armazem_produtos = ap[i - 1].armazem_produtos;
		ap[i].preco = ap[i - 1].preco;
		n_produtos(0, 1);
	}
}

prod* removeProdArm(armazem*ap,prod*produt) {
	for (int i = 0; i < n_produtos(0, 0); i++) {
		produt[i].preco = ap[i].preco;
		produt[i].produto = ap[i].armazem_produtos;
	}
	return produt;
}

