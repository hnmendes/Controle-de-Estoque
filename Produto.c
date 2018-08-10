#include "produto.h"

#define PRODUTMAX 1000

typedef struct{

    int id;
    char nome[100];
    char tipo[100];
    double preco;
    int quantidade;
    int mesValidade;
    int anoValidade;
    int ativo;


}Produto;


Produto produtos[PRODUTMAX];
int produtoCadastradoQtd = 0;


void addProduto(){

    Produto produto;

    system("cls");

    printf("--------------CADASTRO DE PRODUTO-------------------\n\n\n");

    printf("Digite um identificador numerico de produto: \n\n");
    scanf("%d",&produto.id);
    getchar();

    while(checaIdProduto(produto.id) == 1){
        printf("\nIdentificador de produto já cadastrado, por favor insira outro:\n\n");
        scanf("%d",&produto.id);
        getchar();
    }

    printf("\nDigite o nome do produto: \n\n");
    fgets(produto.nome,100,stdin);

    while(checaNomeProduto(produto.nome) == 1){
        printf("\nNome de produto já cadastrado, por favor insira outro:\n\n");
        fgets(produto.nome,100,stdin);
    }

    printf("\nDigite o tipo do produto: \n\n");
    fgets(produto.tipo,100,stdin);


    printf("\nDigite o preço do produto: \n\n");
    scanf("%lf",&produto.preco);

    printf("\nDigite a quantidade do produto: \n\n");
    scanf("%d",&produto.quantidade);

    printf("\nDigite o mês de validade do produto: \n\n");
    scanf("%d",&produto.mesValidade);

    printf("\nDigite o ano de validade do produto: \n\n");
    scanf("%d",&produto.anoValidade);

    produto.ativo = 1;

    produtos[produtoCadastradoQtd] = produto;

    produtoCadastradoQtd++;

    printf("\n\nProduto cadastrado com sucesso.");

    getchar();

}

int checaIdProduto(int id){          //Checa se o id do produto já está cadastrado

    int i = 0;

    for(i = 0; i < PRODUTMAX; i++){
        if(produtos[i].id == id){
            return 1;
        }
    }

    return 0;
}

int checaNomeProduto(char nome[100]){

    int i = 0;

    for(i = 0; i < PRODUTMAX; i++){
        if(strcmp(produtos[i].nome,nome) == 0){
            return 1;
        }
    }

    return 0;
}

void imprimirProdutos(){

    int i = 0;

    system("cls");
    printf("\n\n\n-----------Produtos-------------\n\n\n");

    for(i = 0; i < PRODUTMAX; i++){
        if(produtos[i].ativo == 1){

            printf("Id: %d\n\n",produtos[i].id);
            printf("Nome: %s\n",produtos[i].nome);
            printf("Tipo: %s\n",produtos[i].tipo);
            printf("Preco: %.2lf\n",produtos[i].preco);
            printf("\nQuantidade: %d\n",produtos[i].quantidade);
            printf("\nMes de validade: %d\n",produtos[i].mesValidade);
            printf("\nAno de validade: %d\n",produtos[i].anoValidade);
            printf("\n\n--------------------------------\n\n");

        }
    }
}

void editProduto(){

    int op, id;
    char nome[100];

    printf("\n\n--------Editar Produto-----------\n\n\n");
    printf("Digite 1 se quiser editar o produto pelo id ou digite 2 se quiser procurar\npelo nome do produto que quer adicionar, digite outro número para sair:\n\n");

    scanf("%d",&op);

    if(op == 1){
        printf("\n\nDigite o id do produto que deseja editar:\n\n");
        scanf("%d",&id);

        while(checaIdProduto(id) != 1){
            printf("\n\nProduto não encontrado. Por favor, digite um id válido.");
            scanf("%d",&id);
        }

        editPorId(id);

    }else if(op == 2){
        printf("\n\nDigite o nome do produto que deseja editar:\n\n");
        fgets(nome,100,stdin);

        while(checaNomeProduto(nome)!= 1){
            printf("\n\nProduto não encontrado. Por favor, digite um id válido.");
            fgets(nome,100,stdin);
        }

        editPorNome(nome);

    }


}

void editPorId(int id){

    int i = 0;

    for(i = 0; i < PRODUTMAX; i++){

        if(produtos[i].id == id){
            printf("\n\nProduto encontrado.\n\n");

            printf("\nDigite o nome do produto: \n\n");
            fgets(produtos[i].nome,100,stdin);

            while(checaNomeProduto(produtos[i].nome) == 1){
                printf("\nNome de produto já cadastrado, por favor insira outro:\n\n");
                fgets(produtos[i].nome,100,stdin);
            }

            printf("\nDigite o tipo do produto: \n\n");
            fgets(produtos[i].tipo,100,stdin);

            printf("\nDigite o preço do produto: \n\n");
            scanf("%lf",&produtos[i].preco);

            printf("\nDigite a quantidade do produto: \n\n");
            scanf("%d",&produtos[i].quantidade);

            printf("\nDigite o mês de validade do produto: \n\n");
            scanf("%d",&produtos[i].mesValidade);

            printf("\nDigite o ano de validade do produto: \n\n");
            scanf("%d",&produtos[i].anoValidade);

            printf("\n\nProduto editado com sucesso.\n\n");
        }
    }

}

void editPorNome(char nome[100]){

    int i = 0;


    for(i = 0; i < PRODUTMAX; i++){
        if(strcmp(produtos[i].nome,nome) == 0){
            printf("\n\nProduto encontrado.\n\n");

            printf("\nDigite o nome do produto: \n\n");
            fgets(produtos[i].nome,100,stdin);

            while(checaNomeProduto(produtos[i].nome) == 1){
                printf("\nNome de produto já cadastrado, por favor insira outro:\n\n");
                fgets(produtos[i].nome,100,stdin);
            }

            printf("\nDigite o tipo do produto: \n\n");
            fgets(produtos[i].tipo,100,stdin);

            printf("\nDigite o preço do produto: \n\n");
            scanf("%lf",&produtos[i].preco);

            printf("\nDigite a quantidade do produto: \n\n");
            scanf("%d",&produtos[i].quantidade);

            printf("\nDigite o mês de validade do produto: \n\n");
            scanf("%d",&produtos[i].mesValidade);

            printf("\nDigite o ano de validade do produto: \n\n");
            scanf("%d",&produtos[i].anoValidade);

            printf("\n\nProduto editado com sucesso.\n\n");
        }
    }

}

void editQuantidade(int id){

    int i = 0;

    for(i = 0; i < PRODUTMAX; i++){
        if(id == produtos[i].id){

            printf("\n\nProduto encontrado.\n\n");

            printf("\nDigite a quantidade do produto: \n\n");
            scanf("%d",&produtos[i].quantidade);

        }
    }

}
