#pragma once
#include "sector.h"
#include "armazem.h"


void removeProd();
int atualizaPreco(sector* sectores, int Nsector, prod* produt, armazem* ap);
void iniciaCamp();
void gravarSuper();
void carregaSuper();
void imprimeProd();
void novaArea();
void MostraReg();
void alteraArea();
void voltar();

void gestor(sector* sectores, int Nsector, prod* produt, armazem* ap);
