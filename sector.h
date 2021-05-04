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

prod* criaProd(sector* sectores, prod* produt, int Nsector);


sector* criasector(sector* sectores, int Nsector);
void mostraSector(sector* sectores, prod* produt, int Nsector);
