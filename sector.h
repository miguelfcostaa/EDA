#pragma once
#include <string>

using namespace std;

struct sector {
    char letra;
    string nome;
    int capacidade;
    int Nproduto;
    string areas;
    struct prod;
};

struct prod {
    int preco;
    string produto;
};

prod* criaProd(sector* sectores, prod* produt, int Nsector);
int preco();

sector* criasector(sector* sectores, int Nsector);
void mostraSector(sector* sectores, prod* produt, int Nsector);
