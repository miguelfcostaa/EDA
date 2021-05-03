#include <iostream>
#include "sector.h"
#include <string>
#include <fstream>
#include "armazem.h"


using namespace std;


string* produtoss() {
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


armazem* criaArmazem(armazem* ap, prod* produt) {
	string* lines = produtoss();
	for (int i = 0; i < 50; i++) {
		ap[i].armazem_produtos = lines[i];
	}
	return ap;
}

/*
void addProdutos(armazem* ap) {
	prod* produt = criaProd(5);
	armazem->stock = prod;
}
*/
