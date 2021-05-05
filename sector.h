#pragma once
#include <string>

using namespace std;


struct sector {
    char letra;
    string areas;
    string nome;
    int capacidade;
    int Nproduto;
};

struct prod {
    int preco ;
    string produto ;
    string fornecedores;
};

string* produtos();
string* nomes(sector* sectores, int i);
int Nproduto(sector* sectores, int Nsector);
int capacidade();
string* areas();
int preco();
int fullcap(sector* sectores, int Nsector);

sector* criasector(sector* sectores, int Nsector);
prod* criaProd(prod* produt, sector* sectores, int Nsector);
void mostraSector(sector* sectores, prod* produt, int Nsector);
