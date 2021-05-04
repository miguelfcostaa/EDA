#include <iostream>
#include < stdlib.h >
#include <time.h>
#include "Gestor.h"
#include <fstream>
#include <string>
#include "sector.h"
#include "armazem.h"

using namespace std;


int atualizaPreco(sector* sectores, int Nsector, prod* produt, armazem* ap) {
	string nomeaux;
	for (int i = 0; i < Nsector; i++) {
		cout << "Introduza o nome do produto: ";
		cin >> nomeaux;
		if (nomeaux == ap[i].armazem_produtos) {
			cout << "Introduza um novo valor para o produto: ";
			cin >> produt[i].preco;
		}
		else
			cout << "Nao existe esse produto no armazem." << endl;
	}
	return 0;
}

void removeProd(prod* produt, armazem* ap) {
	string nomeaux;
	cout << "Introduza o produto que deseja eleminar: " << endl;
	cin >> nomeaux;
	for (int i = 0; i < ap[i].n_produtos; i++) {//o ap[i].n_produtos nao faz sentido algum 
		if (ap[i].armazem_produtos == nomeaux) {
			ap[i].armazem_produtos = "Vazio";
			ap[i].preco = 0;
		}
	}
}

void iniciarCampanha(int Nsector, sector* sectores, prod* produt) {//FALTA A duraçao 
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

void imprimeProdutos() {
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
			//ordemAlfabetica();
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
			removeProd(produt, ap);
			break;
		case '2':
			atualizaPreco(sectores, Nsector, produt, ap);
			break;
		case '3':
			//iniciaCamp();
			break;
		case '4':
			//gravarSuper();
			break;
		case '5':
			//carregaSuper();
			break;
		case '6':
			//imprimeProd();
			break;
		case '7':
			//novaArea();
			break;
		case '8':
			//MostraReg();
			break;
		case '9':
			//alteraArea();
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

