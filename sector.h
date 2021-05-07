#pragma once
#include <string>

using namespace std;

struct prod {
    string produto;
    string fornecedores;
    int preco;
};

struct sector {
    prod* prods;
    char letra;
    string areas;
    string nome;
    int capacidade{};
    int Nproduto{};
};

struct armazem {
    prod* prodarm;
    int n_produtos = 0;
};


string* produtos();
string* nomes(sector* sectores, int i);
string* fornecedores();
int preco();
string* areas();
sector* criasector(sector* sectores, int Nsector, prod* produt, armazem* ap);
void mostraSector(sector* sectores, prod* produt, int Nsector);
prod* criaProdutos(armazem* ap, int Nprodutos);
