#pragma once
#include <string>

using namespace std;


int length(sector* head);
void inserirInicio(sector* head, char letra, string areas, string nome, int capacidade, int Nproduto, prod* prods);
void inserirFim(sector* head, char letra, string areas, string nome, int capacidade, int Nproduto, prod* prods);
void insereMeio(sector* head, char letra, string areas, string nome, int capacidade, int Nproduto, prod* prods, int pos);
int RemoveNode(string dado, prod* cabeca);