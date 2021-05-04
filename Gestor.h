#pragma once
#include "sector.h"
#include "armazem.h"


void removeProd(prod* produt, armazem* ap);
int atualizaPreco(sector* sectores, int Nsector, prod* produt, armazem* ap);
void iniciarCampanha(int Nsector, sector* sectores, prod* produt);
//void gravarSuper();
//void carregaSuper();
void imprimeProdutos();
//void novaArea();
//void MostraReg();
//void alteraArea();
//void voltar();

void gestor(sector* sectores, int Nsector, prod* produt, armazem* ap);
