#pragma once
#include "sector.h"
#include <string>

using namespace std;

string* stock();
armazem* criaArmazem();
void addProdutos(armazem* ap);
void mostraArmazem(armazem* ap, sector* sectores);
void removeProdutos(armazem* ap);
prod* removeProdArm(armazem* ap, int Nproduto, prod* produt, sector* sectores);