#include <iostream>
#include "sector.h"
#include <string>
#include <fstream>
#include "armazem.h"


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
		ap[i].armazem_produtos = lines[i];
		ap[i].n_produtos = i;
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

void mostraArmazem(armazem* ap) {
	for (int i = 0; i < 50; i++) {
		cout << "Produto: " << ap[i].armazem_produtos;
		cout << " | Preço: " << ap[i].preco << endl;
	}
}
