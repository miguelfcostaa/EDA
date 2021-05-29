#pragma once
#include <string>
#include "sector.h"
#include "armazem.h"

void removeProd(armazem* ap, int Nsector, sector* sectores);
armazem* atualizaPreco(sector* sectores, int Nsector, prod* produt, armazem* ap);
void iniciarCampanha(int Nsector, sector* sectores, prod* produt);
void ordemAlfabetica(sector* sectores, int Nsector, prod* produt, armazem* ap);
void gravarsuper(string gravac, sector* sectores, int Nsector, prod* produt);
//void carregaSuper();
void imprimeProdutos(sector* sectores, int Nsector, prod* produt, armazem* ap);
//void novaArea();
void mostraregisto(sector* sectores, int Nsector);
void alteraArea(armazem* ap, sector* sectores, int Nsector);
void gestor(sector* sectores, int Nsector, prod* produt, armazem* ap);
