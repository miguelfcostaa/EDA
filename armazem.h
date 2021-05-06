#pragma once
#include <string>

using namespace std;

struct armazem {
	string armazem_produtos = "Vazio";
	int n_produtos = 0;
	int preco = 0;
};

armazem* criaArmazem(armazem* ap);
string* stock();
void mostraArmazem(armazem* ap);
