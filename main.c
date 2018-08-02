#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define AdmQtd 2


//Estrutura homogênia do admin.

struct Admin{

    char usuario[10];
    char senha[10];

};

typedef struct Admin Admin;


//Estrutura homogênia do cliente.

struct Cliente{

    char nome[100];
    char email[100];
    char senha[50];
    char empresa[100];

};

typedef struct Cliente Cliente;


//Estrutura Homogênia de Produto


struct Produto{

    int id;
    char nome[100];
    char tipo[100];
    double preco;
    int quantidade;
    int diaFabricacao;
    int mesFabricacao;
    int anoFabricacao;


};

typedef struct Produto Produto;


//------------------------------FUNÇÕES E PROCEDIMENTOS-----------------------------------\\


Admin adms[2];


int main(){

    menuAdmin("Henrique");


    return 0;
}


//------PARTE DE FUNÇÕES E PROCEDIMENTOS DO ADMINISTRADOR------------\\



void cadastroAdmin(Admin *adm){

    system("clear");
    printf("----------------CADASTRO--------------------");

    printf("\n\nDigite o login do admin:\n\n");
    scanf("%s",&adm->usuario);

    printf("\n\nDigite a senha do admin:\n\n");
    scanf("%s",&adm->senha);

    printf("\n");
    printf("--------------------------------------------");
}



void loginAdmin(){

    char login[10],senha[10];

    system("clear");
    printf("-----------LOGIN------------");

    printf("\n\nDigite o login do admin:\n\n");
    scanf("%s",&login);

    printf("\n\nDigite a senha do admin:\n\n");
    scanf("%s",&senha);

    printf("\n");
    printf("-----------------------------");

    if(checaLoginAdmin(login,senha) == 1){

        menuAdmin(login);

    }else{

        printf("\n\n\nLogin ou senha incorretos, ou a conta de adm informada nao existe.");

        system("pause");

        loginAdmin(adms);

    }
}

//int checaCadastroAdmin();

    //Falta implementar pra checar se o usuario já existe no array.
//

int checaLoginAdmin(char login[10], char senha[10]){

    int i = 0;

    for(i = 0; i < AdmQtd; i++){

        if(strcmp(adms[i].usuario, login) == 0 && strcmp(adms[i].senha,senha) == 0){ //Checa se existe dentro do array o login e a senha digitados pelo usuario.

            return 1; //Retorna 1 se foi encontrado

        }
    }

    return 0;

}

void menuAdmin(char login[10]){

    int op = 0;

    system("clear");

    printf("\n\n");

    printf("Logado com sucesso.");

    getchar();

    system("clear");

    printf("\n\n\n");

    printf("Bem vindo, %s",login);

    printf("\n\n\n\n");


    printf("'-------------------------[MENU ADMIN]---------------------------'\n");
    printf("'                                                                '\n");
    printf("'   Digite 1 para adcionar um produto                            '\n");
    printf("'   Digite 2 para editar a quantidade de um produto em estoque   '\n");
    printf("'   Digite 3 para editar atributos de um produto em estoque      '\n");
    printf("'   Digite 4 para remover um produto em estoque                  '\n");
    printf("'                                                                '\n");
    printf("'   Digite 0 para sair do menu adm                               '\n");
    printf("'                                                                '\n");
    printf("'----------------------------------------------------------------'\n");

     printf("\n\n\n\n");

     scanf("%d",&op);

     switch(op){

        case 1:
            //addProduto();
            break;

        case 2:
            //editQtdProduto();
            break;

        case 3:
            //editAttrProduto();
            break;

        case 4:
            //delProduto();
            break;

        case 0:
            //menuPadrao();
            break;
     }


}


//----------PARTE DE FUNÇÕES E PROCEDIMENTOS DO PRODUTO--------------\\


//addProduto(Produto *estoque);
    //Aqui sera o procedimento de adcionar o produto.
    //Validar se o produto já existe pelo ID, caso exista, impedir de adcionar
    //Ao adcionar um produto, ao final, perguntar se quer adcionar mais
//


//editQtdProduto(Produto *estoque);
    //Aqui sera o procedimento de editar a quantidade de produto.
    //Pedir o id do produto desejado
    //Perguntar se deseja adicionar mais ou remover determinada quantidade.
    //Informar a quantidade daquele Produto
    //Validar se o que o usuario digitou foi um numero menor do que 0, caso for, pedir pra o mesmo digitar um valor acima de 0
//


//editAttrProduto(Produto *estoque);
    //Aqui sera o procedimento de editar os atributos daquele determinado produto, como nome, descricao etc... Exceto a quantidade
    //Um formulario de edição.
    //Validar algum campo que precisar.
//


//delProduto(Produto *estoque);
    //Aqui será o procedimento de remover um produto.
    //Pedir o id ou nome.
    //Checar se o usuário quer realmente remover aquele produto, mostrando informaçoes do mesmo.
    //Caso a escolha for positiva, remover o produto do estoque
//



