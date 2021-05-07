#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale>
#include <string>
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

    criasector(sectores, Nsector, produt, ap);        //criar os sectores antes de                              
    cout << endl;

    mostraArmazem(ap);
    mostraSector(sectores, produt, Nsector);

    char escolha;
    bool sair = false;
    do {
        cout << "(s) Seguinte   |   (g)Gestão   |   (n)Sair" << endl;
        cin >> escolha;
        switch (escolha) {
        case 's':
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
