#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale>
#include <string>
#include <fstream>
#include "armazem.h"
#include "sector.h"
#include "gestor.h"


using namespace std;

int main() {
    locale::global(locale(""));

    srand((unsigned int)time(NULL));
    int Nsector = rand() % 5 + 8;                //numero random de 8 a 12

    sector* sectores = new sector[Nsector];      //criar object para a struct sectores
    prod* produt = new prod;                     //criar object para a struct produtos
    armazem* ap = criaArmazem();             //criar object para a struct armazem

    cout << "Existem " << Nsector << " sectores." << endl;
    criasector(sectores, Nsector, produt, ap);        //criar os sectores antes de                              

    mostraArmazem(ap, sectores);
    cout << endl;
    mostraSector(sectores, produt, Nsector);

    ifstream ficheiro("gravacao.txt");

    char escolha;
    bool sair = false;
    do {
        cout << "(s)eguinte ************* (g)estão" << endl;
        cin >> escolha;
        cout << endl;
        switch (escolha) {
        case 's':
            addProdutos(ap);
            mostraSector(sectores, produt, Nsector);
            prodVend(sectores, Nsector);
            cout << endl << "------------------------- VERIFICACAO DA VENDA ----------------------------------------" << endl;
            prodVend(sectores, Nsector);
            mostraSector(sectores, produt, Nsector);
            break;
        case 'g':
            gestor(sectores, Nsector, produt, ap);
            break;
        case 'n':
            sair = true;
            break;
        default:
            cout << "Escolha uma opção válida" << endl;
            break;
        }
    } while (!sair);
    return 0;
}