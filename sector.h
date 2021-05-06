#pragma once
#include <string>

using namespace std;

struct prod {
    int preco;
    string produto;
    string fornecedores;
};

struct sector {
    prod* prods;
    char letra;
    string areas;
    string nome;
    int capacidade;
    int Nproduto;
};

struct armazem {
    string armazem_produtos;
    int n_produtos;
    int preco;
};



string* produtos();
string* nomes(sector* sectores, int i);
int Nproduto(sector* sectores, int Nsector);
int capacidade();
string* areas();
int preco();
//int fullcap(sector* sectores, int Nsector);

sector* criasector(sector* sectores, int Nsector, prod* produt, armazem* ap);
//prod* criaProd(sector*sectores,prod*produt);
void mostraSector(sector* sectores, prod* produt, int Nsector);
