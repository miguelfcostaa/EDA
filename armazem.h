#pragma once
#include <string>

using namespace std;

struct armazem {
	string armazem_produtos;
	int n_produtos;
};

armazem* criaArmazem(armazem* ap, prod* produt);
