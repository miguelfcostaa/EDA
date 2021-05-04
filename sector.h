#pragma once
#include <string>

using namespace std;

/*
struct sector {
    struct prod {
        prod* preco = 0;
        string produto = "Vazio";
        string fornecedores;
    };
    char letra = ' ';
    string areas;
    string nome;
    int capacidade = 0;
    int Nproduto = 0;
};

sector::prod* novo = new sector::prod();
*/

struct sector {
    char letra = ' ';
    string areas;
    string nome;
    int capacidade = 0;
    int Nproduto = 0;
};

struct prod {
    int preco = 0;
    string produto = "Vazio";
    string fornecedores;
};


int fullcapacidade(sector* sectores, int Nsector);
string* produtos();
string* nomes(sector* sectores, int i);
int capacidade();
int Nproduto(sector* sectores, int Nsector);
string* areas();
sector* criasector(sector* sectores, int Nsector);
prod* criaProd(sector* sectores, prod* produt, int Nsector);

void mostraSector(sector* sectores, prod* produt, int Nsector);
