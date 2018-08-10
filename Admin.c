#include "admin.h"

#define ADMMAX 2

typedef struct Admin{

    char usuario[10];
    char senha[10];

}Admin;

Admin adms[ADMMAX];     //Vetor de administradores.
int admCadastroQtd = 0; //Checagem de quantos administradores têm cadastrados.

void cadastroAdmin(){

    Admin adm;

    system("cls");
    printf("\n\n----------------CADASTRO--------------------");

    if(admCadastroQtd == 2){

        fflush(stdin);
        printf("\n\nO limite de cadastro de administradores foi excedido.");
        getchar();
        getchar();

    }else{

        printf("\n\nDigite o login do admin:\n\n");
        scanf("%s",&adm.usuario);

        while(checaCadastroAdmin(adm.usuario) == 1){
            printf("\n\nO nome de usuário já existe, por favor digite outro:\n\n");
            scanf("%s",&adm.usuario);
        }

        printf("\n\nDigite a senha do admin:\n\n");
        scanf("%s",&adm.senha);

        adms[admCadastroQtd] = adm;

        admCadastroQtd++;

        printf("\n\nAdministrador cadastrado com sucesso.");

        system("read");
    }


    printf("\n\n\n");
}



void loginAdmin(){

    char login[10],senha[10];

    system("cls");
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

int checaCadastroAdmin(char usuario[10]){

    int i;

    for(i = 0; i < ADMMAX; i++){
        if(strcmp(usuario,adms[i].usuario) == 0){
            return 1;
        }
    }

    return 0;

    //Falta implementar pra checar se o usuario já existe no array.
}

int checaLoginAdmin(char login[10], char senha[10]){

    int i = 0;

    for(i = 0; i < ADMMAX; i++){

        if(strcmp(adms[i].usuario, login) == 0 && strcmp(adms[i].senha,senha) == 0){ //Checa se existe dentro do array o login e a senha digitados pelo usuario.

            return 1; //Retorna 1 se foi encontrado

        }
    }

    return 0;

}

void menuAdmin(char login[10]){

    int op = 0;

    system("cls");

    printf("\n\n");

    getchar();

    system("cls");

    printf("\n\n\n");

    printf("Bem vindo, %s",login);

    printf("\n\n\n\n");


    printf("'-------------------------[MENU ADMIN]---------------------------'\n");
    printf("'                                                                '\n");
    printf("'   Digite 1 para adcionar um produto                            '\n");
    printf("'   Digite 2 para editar a quantidade de um produto em estoque   '\n");
    printf("'   Digite 3 para editar atributos de um produto em estoque      '\n");
    printf("'   Digite 4 para remover um produto em estoque                  '\n");
    printf("'   Digite 5 para adicionar uma nova conta de admin              '\n");
    printf("'                                                                '\n");
    printf("'   Digite 0 para sair do menu adm                               '\n");
    printf("'                                                                '\n");
    printf("'----------------------------------------------------------------'\n");

     printf("\n\n\n\n");

     scanf("%d",&op);

     switch(op){

        case 1:
            addProduto();
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

        case 5:
            cadastroAdmin();
            menuAdmin(login);
            break;

        default:
            //menuPadrao();
            break;
     }


}

