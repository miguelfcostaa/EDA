#pragma once
#include "sector.h"
#include <string>

using namespace std;

armazem* criaArmazem(armazem* ap);
string* stock();
int n_produtos(int n, int m);
void mostraArmazem(armazem* ap, prod* produt);
void removeProdutos(armazem* ap);
prod* removeProdArm(armazem*ap,prod*produt);
