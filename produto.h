#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


void addProduto();

int checaIdProduto(int id);

int checaNomeProduto(char nome[100]);

void imprimirProdutos();

void editProduto();


#endif // PRODUTO_H_INCLUDED
