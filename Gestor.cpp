#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "gestor.h"


using namespace std;

void gestor() {
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
		string p;
		int m;
		switch (opcao) {
		case '1':
			cout << "Qual é o produto que pertende remover: ";
			cin >> p;
			removeProd();
			break;
		case '2':
		//	cout << "Qual é o produto que pertende alterar o preço: " << p << endl;
		//	cin >> p;
		//	cout << "Qual é o novo preço do produto: " << m << endl;
		//	cin >> m;
			//atualizaPreco();

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
			cout << "Escolheu a opcao Voltar." << endl;
			sair = true;
			break;
		default:
			cout << "Escolha uma opcao valida." << endl;
		}
	} while (!sair);

}
