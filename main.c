#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>


//Estrutura homogênia do admin.

struct Admin{

    char usuario[10];
    char senha[10];

};

typedef struct Admin Admin;

//---------------------------------------------------------------\\


//Estrutura homogênia do cliente.

struct Cliente{

    char nome[100];
    char email[100];
    char senha[50];
    char empresa[100];

};

typedef struct Cliente Cliente;

//----------------------------------------------------------------\\


//Estrutura Homogênia de Produto


struct Produto{

    char nome[100];
    char tipo[100];
    char codBarra[13];
    double preco;
    int diaFabricacao;
    int mesFabricacao;
    int anoFabricacao;


};

typedef struct Produto Produto;

//-----------------------------------------------------------------\\

Admin adm[2];



int main(){




    return 0;
}




void cadastroAdmin(Admin *adm){
    printf("----------------CADASTRO--------------------");
    printf("\n\nDigite o login do admin:\n\n");
    scanf("%s",&adm->usuario);
    printf("\n\nDigite a senha do admin:\n\n");
    scanf("%s",&adm->senha);
    printf("\n");
    printf("--------------------------------------------");
}

void loginAdmin(Admin *adm){
    printf("----------------LOGIN------------------------");
    printf("\n\nDigite o login do admin:\n\n");
    scanf("%s",&adm->usuario);
    printf("\n\nDigite a senha do admin:\n\n");
    scanf("%s",&adm->senha);
    printf("\n");
    printf("----------------------------------------------");
}


void cadastro
