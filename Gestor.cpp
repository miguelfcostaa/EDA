#include <iostream>
#include < stdlib.h >
#include <time.h>
#include <fstream>
#include <string>
#include "armazem.h"
#include "gestor.h"
#include "sector.h"
#include "armazem.h"
#include <algorithm>
#include <iomanip>

using namespace std;



void removeProd(armazem* ap, int Nsector, sector* sectores) {
	string nomeaux;
	cout << "Introduza o produto que deseja eliminar: " << endl;
	getline(cin,nomeaux);
	for (int i = 0; i < Nsector; i++) {
		for (int j = 0; j < sectores[i].Nproduto; j++) {
			if (sectores[i].prods[j].produto == nomeaux) {
				sectores[i].prods[j].produto = sectores[i].prods[j + 1].produto;
				sectores[i].prods[j].preco = sectores[i].prods[j + 1].preco;
				sectores[i].Nproduto--;
				cout << "Produto vendido." << endl;
			}

		}
	}
}

armazem* atualizaPreco(sector* sectores, prod* produt, armazem* ap) {
	string nomeaux;
	int novopreco;
	cout << "Introduza o nome do produto (em vez do espaço utilize '_') : ";
	cin >> nomeaux;
	cout << "Introduza um novo valor para o produto: ";
	cin >> novopreco;
	for (int i = 0; i < ap->n_produtos; i++) {
		if (ap->prodarm[i].produto == nomeaux) {
			ap->prodarm[i].preco = novopreco;
			cout << "O preco foi alterado com sucesso!" << endl;
		}
	}
	return ap;
}

void iniciaCampanha(int Nsector, sector* sectores, prod* produt) {
	int desconto;
	string nomeaux;
	int duracao;
	cout << "Selecione a area para a campanha: ";
	cin >> nomeaux;
	cout << endl << "Introduza o valor do desconto (valores entre 0 e 100): ";
	cin >> desconto;
	cout << endl << "Selecione a duraçao da campanha: ";
	cin >> duracao;
	for (int i = 0; i < Nsector; i++) {
		if (sectores[i].areas == nomeaux) {
			produt[i].preco = produt[i].preco * ((100 - desconto) / 100);
		}
	}
}

void novaArea(armazem* ap) {

}

void imprimeProdutos(sector* sectores, int Nsector, prod* produt, armazem* ap) {
	string* impressao = new string();
	bool sair = false;
	char opcao;
	do {
		cout << "Impressao de produtos" << endl;
		cout << "(1) - Por ordem alfabetica!" << endl;
		cout << "(2) - Por ordem de preco!" << endl;
		cout << "(0) - Voltar!" << endl;
		cin >> opcao;
		cout << endl;
		switch (opcao) {
		case '1':
			ordemAlfabetica(sectores,Nsector,produt,ap);
			break;
		case '2':
			//ordemPreco();
			break;
		case '0':
			sair = true;
			break;
		default:
			cout << "Escolha uma opçao valida!" << endl;
			break;
		}
	} while (!sair);
}

void ordemAlfabetica(sector* sectores, int Nsector, prod* produt, armazem* ap) {
	int j = 0;
	bool swap = true;
	sector* temp = new sector;
	while (swap) {
		swap = false;
		j++;
		for (int l = 0; l < Nsector - j; l++)
		{
			if (produt[l].produto > produt[l + 1].produto) {
				*temp = sectores[l];
				sectores[l] = sectores[l + 1];
				sectores[l + 1] = *temp;
				swap = true;

			}

		}
	}
	delete temp;
	mostraSector(sectores, produt, Nsector);
}


void gravarsuper(string gravac, sector* sectores, int Nsector, prod* produt) {
	fstream ficheiro;
	string res = to_string(Nsector) + "\n";
	for (int i = 0; i < sectores->Nproduto; i++) {
		res = res + "Sector: " + sectores[i].letra + " | Responsavel: " + sectores[i].nome + " | Capacidade: " + to_string(sectores[i].capacidade) + " | Produtos: " + to_string(sectores[i].Nproduto) + " | Area: " + sectores[i].areas + "\n" + "Produto : " + sectores[i].prods[i].produto + " | Preco : " + to_string(sectores[i].prods->preco) + " Euros" + "\n" + "-----------------------------------------------------";
		
	}
	ficheiro.open(gravac, ifstream::out);
	ficheiro << res;
	ficheiro.close();
	cout << "O supermercado foi guardado com sucesso." << endl;
	cout << endl;
}


void alteraArea(armazem* ap, sector* sectores, int Nsector) {
	string area = "";
	int c;
	cout << "Qual o sector que deseja alterar?(letra maiuscula): ";
	cin >> c;
	cin.ignore();
	cout << endl << "Escolha uma das areas abaixo:" << endl;
	areas();
	getline(cin, area);
	for (int i = 0; i < Nsector; i++) {
		if (sectores[i].letra == c) {
			sectores[i].areas = area;
			for (int j = 0; j < sectores[i].Nproduto; j++) {
				for (int k = 0; k < ap->n_produtos; k++) {
					sectores[i].prods[j].produto = ap->prodarm[k].produto;
					sectores[i].prods[j].preco = ap->prodarm[k].preco;
					ap->n_produtos--;
					removeProdutos(ap);
				}
			}
		}
	}
}


void mostraregisto(sector* sectores, int Nsector) {
	string nomeaux;
	cout << "Qual o responsavel de sector do qual deseja ver o registo de vendas? ";
	cin >> nomeaux;
	for (int i = 0; i < Nsector; i++) {
		if (nomeaux == sectores[i].nome) {
			cout << "Foram vendidos os seguintes produtos: " << endl;
			for (int j = 0; j < sectores[i].Nproduto; j++) {
				if (sectores[i].prods[j].vendido == true) {
					cout << sectores[i].prods[j].produto << endl;
				}
			}
		}
	}
	cout << endl;
}

void gestor(sector* sectores, int Nsector, prod* produt, armazem* ap) {
	bool sair = false;
	char opcao;
	do
	{
		cout << "***** Bem Vindo Gestor *****" << endl;
		cout << "(1) - Remover Produtos" << endl;
		cout << "(2) - Atualizar Preço" << endl;
		cout << "(3) - Iniciar Campanha" << endl;
		cout << "(4) - Gravar Supermercado" << endl;
		cout << "(5) - Carregar Supermercado" << endl;
		cout << "(6) - Imprimir Produtos" << endl;
		cout << "(7) - Criar nova área" << endl;
		cout << "(8) - Mostrar registo de vendas" << endl;
		cout << "(9) - Alterar área" << endl;
		cout << "(0) - Voltar" << endl;
		cout << "Selecione a sua opção:" << endl;
		cin >> opcao;
		cout << endl;
		switch (opcao) {
		case '1':
			removeProd(ap,Nsector,sectores);
			mostraSector(sectores, produt, Nsector);
			break;
		case '2':
			atualizaPreco(sectores, produt, ap);
			mostraArmazem(ap, sectores);
			cout << endl;
			break;
		case '3':
			iniciaCampanha(Nsector, sectores, produt);
			break;
		case '4':
			gravarsuper("gravacao.txt", sectores, Nsector, produt);
			break;
		case '5':
			//carregaSuper();
			break;
		case '6':
			imprimeProdutos(sectores, Nsector, produt, ap);
			break;
		case '7':
			//novaArea();
			break;
		case '8':
			mostraregisto(sectores, Nsector);
			break;
		case '9':
			alteraArea(ap, sectores, Nsector);
			break;
		case '0':
			cout << "Escolheu a opção Voltar." << endl;
			sair = true;
			break;
		default:
			cout << "Escolha uma opcao valida." << endl;
		}
	} while (!sair);

}
