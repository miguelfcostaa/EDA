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
    double preco;
    string produto;
};

prod* criaProd(sector* sectores, prod* produt, int Nsector);
//int prec(prod* produt);
int prec(sector* sectores, prod* produt, int Nsector);

sector* criasector(sector* sectores, int Nsector);
void mostraSector(sector* sectores, prod* produt, int Nsector);
