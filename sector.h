#pragma once
#include <string>

using namespace std;

struct sector {
	char letra;
	string nome;
	int capacidade;
	int Nprodutos;
	string produtos;
	string areas;
};

sector* criasector(sector* sectores, int Nsector);
void mostraSector(sector* sectores, int Nsector);
