#pragma once
#include <string>

using namespace std;

struct sector {
	char letra[26];
	int nome;
	int capacidade;
	int Nprodutos;
	string produtos;
	string areas;
};

sector* criasector(sector* sectores, int Nsector);
void mostraSector(sector* sectores, int Nsector);
