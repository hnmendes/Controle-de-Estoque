#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Estrutura homogênia do admin.

struct Admin{
    int id;
    char usuario[10];
    char senha[10];
};

typedef struct Admin Admin;

//---------------------------------------------------------------\\


//Estrutura homogênia do cliente.

struct Cliente{
    int id;
    char nome[100];
    char email[100];
    char senha[50];
    char empresa[100];

}

typedef struct Cliente Cliente;

//----------------------------------------------------------------\\






int main()
{
    printf("Hello world!\n");
    return 0;
}
