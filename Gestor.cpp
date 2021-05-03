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
			//removeProd();
			//cout << "Qual é o produto que pertende remover: ";
			//cout << endl;
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

