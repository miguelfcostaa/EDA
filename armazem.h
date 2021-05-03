#pragma once
#include <string>

using namespace std;

struct armazem {
	string armazem_produtos = "Vazio";
	int n_produtos = 0;
};

armazem* criaArmazem(armazem* ap, prod* produt);
string* stock();
void mostraArmazem(armazem* ap, prod* produt);
