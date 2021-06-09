#pragma once
#include <string>
#include "sector.h"
#include "armazem.h"

void removeProd(armazem* ap, int Nsector, sector* sectores);
armazem* atualizaPreco(sector* sectores, prod* produt, armazem* ap);
void iniciaCampanha(int Nsector, sector* sectores, prod* produt);
void ordemAlfabetica(sector* sectores, int Nsector, prod* produt, armazem* ap);
void gravarsuper(string gravac, sector* sectores, int Nsector, prod* produt);
void carregaSuper(string caminho_ficheiro, int Nsector);
void novaArea(string area, int Nsector, armazem* ap, sector* sectores);
void imprimeProdutos(sector* sectores, int Nsector, prod* produt, armazem* ap);
void mostraregisto(sector* sectores, int Nsector);
void gestor(sector* sectores, int Nsector, prod* produt, armazem* ap);
