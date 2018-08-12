#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


//------------------Constantes--------------
                                          //
#define PRODUTMAX 1000  //MAX produtos    //
#define ADMMAX 2        //MAX de adms     //
#define CLIENTEMAX 1000 //MAX de clientes //
                                          //
//------------------------------------------


//-----------------Estruturas---------------
                                          //
typedef struct Admin{                     //
                                          //
    char usuario[10];                        //
    char senha[10];                          //
                                          //
}Admin;                                   //
                                          //
                                          //
typedef struct{                           //
                                          //
    int id;                               //
    char nome[100];                       //
    char tipo[100];                       //
    double preco;                         //
    int quantidade;                       //
    int ativo;                            //
                                          //
                                          //
}Produto;                                 //
                                          //
                                          //
typedef struct{                           //
                                          //
    char nome[100];                       //
    char email[100];                      //
    char senha[50];                       //
    char empresa[100];                    //
    int ativo;                            //
                                          //
}Cliente;                                 //
                                          //
//-----------------------------------------


//---------------Vetores-------------------
                                         //
Admin adms[ADMMAX];                      //
Produto produtos[PRODUTMAX];             //
Cliente clientes[CLIENTEMAX];            //
                                         //
//-----------------------------------------
                                                                                //

//-------Quantidade de cadastro------------
                                         //
int admCadastroQtd = 0;                  //
int produtoCadastradoQtd = 0;            //
int clienteCadastradoQtd = 0;            //
                                         //
//-----------------------------------------


//-------------Funções e Procedimentos----------------
void menuPadrao();                                   //
//Admin                                              //
                                                     //
void cadastroAdmin();                                //
void loginAdmin();                                   //
int checaCadastroAdmin(char usuario[10]);            //
int checaLoginAdmin(char login[10], char senha[10]); //
void menuAdmin(char login[10]);
void imprimirAdmins();                      //
                                                     //
//Produto                                            //
                                                     //
void addProduto();                                   //
int checaIdProduto(int id);                          //
int checaNomeProduto(char nome[100]);                //
void imprimirProdutos();                             //
void editProduto();
void editQtdProduto();                               //
                                                     //


int main(){

    adms[0]=(Admin){"teste","123"};

    produtos[0] = (Produto){1,"produto1","bebida",12.80,128,1};
    produtos[1] = (Produto){2,"produto2","bebida",12.80,128,1};
    produtos[2] = (Produto){3,"produto3","bebida",12.80,128,1};
    produtos[3] = (Produto){4,"produto4","bebida",12.80,128,1};
    produtos[4] = (Produto){5,"produto5","bebida",12.80,128,1};
    produtos[5] = (Produto){6,"produto6","bebida",12.80,128,1};
    produtos[6] = (Produto){7,"produto7","bebida",12.80,128,1};
    produtos[7] = (Produto){8,"produto8","bebida",12.80,128,1};
    produtos[8] = (Produto){9,"produto9","bebida",12.80,128,1};
    produtos[9] = (Produto){10,"produto10","bebida",12.80,128,1};
    produtos[10] = (Produto){11,"produto11","bebida",12.80,128,1};
    produtos[11] = (Produto){12,"produto12","bebida",12.80,128,1};
    produtos[12] = (Produto){13,"produto13","bebida",12.80,128,1};
    produtos[13] = (Produto){14,"produto14","bebida",12.80,128,1};
    produtos[14] = (Produto){15,"produto15","bebida",12.80,128,1};
    produtos[15] = (Produto){16,"produto16","bebida",12.80,128,1};
    produtos[16] = (Produto){17,"produto17","bebida",12.80,128,1};
    produtos[17] = (Produto){18,"produto18","bebida",12.80,128,1};
    produtos[18] = (Produto){19,"produto19","bebida",12.80,128,1};
    produtos[19] = (Produto){20,"produto20","bebida",12.80,128,1};
    produtos[20] = (Produto){21,"produto21","bebida",12.80,128,1};
    produtos[21] = (Produto){22,"produto22","bebida",12.80,128,1};
    produtos[22] = (Produto){23,"produto23","bebida",12.80,128,1};
    produtos[23] = (Produto){24,"produto24","bebida",12.80,128,1};
    produtos[24] = (Produto){25,"produto25","bebida",12.80,128,1};
    produtos[25] = (Produto){26,"produto26","bebida",12.80,128,1};
    produtos[26] = (Produto){27,"produto27","bebida",12.80,128,1};
    produtos[27] = (Produto){28,"produto28","bebida",12.80,128,1};
    produtos[28] = (Produto){29,"produto29","bebida",12.80,128,1};
    produtos[29] = (Produto){30,"produto30","bebida",12.80,128,1};
    produtos[30] = (Produto){31,"produto31","bebida",12.80,128,1};

    produtoCadastradoQtd = 31;

    menuPadrao();

    return 0;
}

//Cliente

void menuPadrao(){

    int op = 0;

    printf("\n\nBem vindo ao sistema de controle de estoque.\n\n");

    printf("'---------------------------[MENU]-------------------------------'\n");
    printf("'                                                                '\n");
    printf("'   Digite [1] para logar-se como admin                          '\n");
    printf("'   Digite [2] para logar-se como cliente                        '\n");
    printf("'   Digite [3] para cadastrar-se como cliente                    '\n");
    printf("'                                                                '\n");
    printf("'   Digite [0] para sair do sistema de controle de estoque       '\n");
    printf("'                                                                '\n");
    printf("'----------------------------------------------------------------'\n");
    printf("\n\n\n\n");

    scanf("%d",&op);

    switch(op){

        case 1:
            loginAdmin();
            break;

        case 2:
            //loginCliente();
            break;

        case 3:
            //cadastrarCliente();
            break;

    }


}

//Admin

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

        getchar();
    }


    printf("\n\n\n");
}


void imprimirAdmins(Admin *adm){

    int i = 0;

    for(i = 0; i < admCadastroQtd; i++){
        printf("\nlogin = %s\n",adm[i].usuario);
        printf("\nsenha = %s\n",adm[i].senha);
    }

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

        loginAdmin();

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

    system("clear");

    printf("\n\n");

    getchar();

    system("clear");

    printf("\n\n\n");

    printf("Bem vindo, %s",login);

    printf("\n\n\n\n");


    printf("'-------------------------[MENU ADMIN]---------------------------'\n");
    printf("'                                                                '\n");
    printf("'   Digite [1] para adicionar um produto                         '\n");
    printf("'   Digite [2] para editar a quantidade de um produto em estoque '\n");
    printf("'   Digite [3] para editar atributos de um produto em estoque    '\n");
    printf("'   Digite [4] para remover um produto em estoque                '\n");
    printf("'   Digite [5] para adicionar uma nova conta de admin            '\n");
    printf("'   Digite [6] para imprimir todos produtos                      '\n");
    printf("'                                                                '\n");
    printf("'   Digite [0] para sair do menu adm                             '\n");
    printf("'                                                                '\n");
    printf("'----------------------------------------------------------------'\n");

     printf("\n\n\n\n");

     scanf("%d",&op);

     switch(op){

        case 1:
            addProduto();
            menuAdmin(login);
            break;

        case 2:
            editQtdProduto();
            menuAdmin(login);
            break;

        case 3:
            editProduto();
            menuAdmin(login);
            break;

        case 4:
            removeProduto();
            menuAdmin(login);
            break;

        case 5:
            cadastroAdmin();
            menuAdmin(login);
            break;

        case 6:
            imprimirProdutos();
            menuAdmin(login);
            break;

        default:
            system("clear");
            menuPadrao();
            break;
     }


}



//Produto

void addProduto(){

    Produto produto;

    system("clear");

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

    produto.ativo = 1;

    produtos[produtoCadastradoQtd] = produto;

    produtoCadastradoQtd++;

    printf("\n\nProduto cadastrado com sucesso.");

    getchar();

}

int checaIdProduto(int id){          //Checa se o id do produto já está cadastrado

    int i = 0;

    for(i = 0; i < produtoCadastradoQtd; i++){
        if(produtos[i].id == id){
            return 1;
        }
    }

    return 0;
}

int checaNomeProduto(char nome[100]){

    int i = 0;

    for(i = 0; i < produtoCadastradoQtd; i++){
        if(strcmp(produtos[i].nome,nome) == 0){
            return 1;
        }
    }

    return 0;
}

void imprimirProdutos(){

    int i = 0, cont = 0, pagina = 1;

    system("clear");

    printf("\n-----------Produtos-------------\n");

    for(i = 0; i < produtoCadastradoQtd; i++){

        if(produtos[i].ativo == 1){
            printf("\n\n------------------------------\n");
            printf("Id: %d\n",produtos[i].id);
            printf("Nome: %s\n",produtos[i].nome);
            printf("Tipo: %s\n",produtos[i].tipo);
            printf("Preco: %.2lf\n",produtos[i].preco);
            printf("Quantidade: %d\n",produtos[i].quantidade);
            printf("--------------------------------\n\n");
            getchar();
            cont++;

            if(cont == 15){
                getchar();
                printf("\n\nPagina [%d]\n",pagina);
                cont = 0;
                pagina++;
                getchar();
                system("clear");
            }

        }
    }
}


void editProduto(){

    int op, id;
    char nome[100];

    printf("\n\n--------Editar Produto-----------\n\n\n");
    printf("Digite 1 se quiser editar o produto pelo id ou digite 2 se quiser procurar\npelo nome do produto que quer editar, digite outro número para sair:\n\n");

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

    for(i = 0; i < produtoCadastradoQtd; i++){

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

            printf("\n\nProduto editado com sucesso.\n\n");

            system("read");
        }
    }

}

void editPorNome(char nome[100]){

    int i = 0;


    for(i = 0; i < produtoCadastradoQtd; i++){
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

            printf("\n\nProduto editado com sucesso.\n\n");

            system("read");
        }
    }

}



void editQtdProduto(){

    int id = 0, qtdProduto = 0, i = 0;

    system("clear");

    printf("\n---------EDITAR QUANTIDADE DO PRODUTO--------\n\n\n");

    printf("Digite o identificador do produto que deseja editar sua quantidade:\n\n");
    scanf("%d",&id);

    printf("\n\n");


    for(i = 0; i < produtoCadastradoQtd; i++){

        if(produtos[i].id == id){

            printf("\nProduto encontrado, sua quantidade é de %d digite\na quantidade que deseja editar:\n\n",produtos[i].quantidade);
            scanf("%d",&qtdProduto);

            while(qtdProduto < 0){
                printf("\n\nPara adicionar uma quantidade, o valor deve ser positivo :\n\n");
                scanf("%d",&qtdProduto);
            }

            produtos[i].quantidade = qtdProduto;

            printf("\n\nProduto alterado com sucesso. A nova quantidade deste produto em estoque é de : %d", produtos[i].quantidade);

            getchar();

        }else{

            while(checaIdProduto(id) != 1){
                printf("\nProduto não encontrado, digite um id válido:\n\n");
                scanf("%d",&id);
            }

        }
    }

}


void removeProduto(){

    int i = 0, id = 0, op = 0;
    char nome[100], tipo[100];

    system("clear");

    printf("\n---------REMOVER PRODUTO--------\n\n\n");
    printf("Se deseja remover produto pelo id digite [1], se desejar remover pelo nome[2]:\n\n");
    scanf("%d",&op);

    if(op == 1){
        printf("\n\nDigite um id válido:\n\n");
        scanf("%d",&id);

        while(checaIdProduto(id) != 1){
            printf("\n\nId digitado não existe, por favor, digite um id válido: \n");
            scanf("%d",&id);
        }

        if(removeProdutoById(id) == 1){
            printf("\n\nProduto removido com sucesso.\n");
            getchar();

        }else{

            printf("\nErro na remoção do produto, por favor contate a administração.\n\n");
            getchar();

        }

    }else if(op == 2){
        printf("\n\nDigite um nome válido:\n\n");
        scanf("%s",&nome);
        //getchar();
        fflush(stdin);

        while(checaNomeProduto(nome) != 1){
            printf("\n\nNome digitado não existe, por favor, digite um nome válido: \n");
            scanf("%s",&nome);
            fflush(stdin);
        }

        if(removeProdutoByNome(nome) == 1){
            printf("\n\nProduto removido com sucesso.\n");
            getchar();
            getchar();
        }else{

            printf("\nErro na remoção do produto, por favor contate a administração.\n\n");

            getchar();getchar();

        }
    }else{
        printf("\n\nOpção inválida!!\n\n");
        getchar();
        getchar();
    }

}

int removeProdutoById(int id){

    int i = 0;

    for(i = 0; i < produtoCadastradoQtd; i++){

        if(produtos[i].id == id){

            produtos[i].id = 0;
            produtos[i].ativo = 0;
            strcpy(produtos[i].nome,"");
            produtos[i].preco = 0.0;
            produtos[i].quantidade = 0;
            strcpy(produtos[i].tipo,"");

            return 1;
        }
    }

    return 0;

}

int removeProdutoByNome(char nome[100]){

    int i = 0;

    for(i = 0; i < produtoCadastradoQtd; i++){

        if(strcmp(produtos[i].nome,nome) == 0){

            produtos[i].id = 0;
            produtos[i].ativo = 0;
            strcpy(produtos[i].nome,"");
            produtos[i].preco = 0.0;
            produtos[i].quantidade = 0;
            strcpy(produtos[i].tipo,"");

            return 1;
        }
    }

    return 0;
}


//CLIENTE



