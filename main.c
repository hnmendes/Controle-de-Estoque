#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>


//------------------Constantes--------------
                                          //
#define PRODUTMAX 1000  //MAX produtos    //
#define ADMMAX 2        //MAX de adms     //
#define CLIENTEMAX 1000 //MAX de clientes //
#define COMPRAMAX 100                     //
//------------------------------------------


//-----------------Estruturas---------------
                                          //
typedef struct{                           //
                                          //
    char usuario[10];                     //
    char senha[10];                       //
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

typedef struct{

    int idProduto;
    int quantidadeProduto;
    float precoTotal;

}Compra;

                                          //
typedef struct{                           //
                                          //
    char nome[100];                       //
    char email[100];                      //
    char senha[50];                       //
    char empresa[100];                    //
    Compra compras[COMPRAMAX];            //
    int quantCompras;                     //
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
//Cliente

int checarEmail(char email[100]);
void cadastroCliente();
void imprimirClientes();
void compraProduto(char email[100]);
Cliente * clienteByEmail(char email[100]);
void loginCliente();
int comprarProdutoById(int id,int quantidade,Cliente* cli);
void impressaoTeste(char email[100]);
char* getNomeProdutoById(int id);
void criaArquivo(char *nomeArq, char email[100]);
void lerArquivo();




int main(){

    setlocale(LC_ALL, "Portuguese");

    adms[0]=(Admin){"admin","123"};

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

    //menuPadrao();

    strcpy(clientes[0].nome,"henrique");
    strcpy(clientes[0].email,"henrique");
    strcpy(clientes[0].empresa,"henrique");
    strcpy(clientes[0].senha,"henrique");
    clientes[0].ativo = 1;

    clienteCadastradoQtd++;

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
            loginCliente();
            break;

        case 3:
            cadastroCliente();
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
        system("pause");


    }else{

        printf("\n\nDigite o login do admin:\n\n");
        scanf("%s",&adm.usuario);
        fflush(stdin);

        while(checaCadastroAdmin(adm.usuario) == 1){
            printf("\n\nO nome de usuário já existe, por favor digite outro:\n\n");
            scanf("%s",&adm.usuario);
            fflush(stdin);
        }

        printf("\n\nDigite a senha do admin:\n\n");
        scanf("%s",&adm.senha);
        fflush(stdin);

        adms[admCadastroQtd] = adm;

        admCadastroQtd++;

        printf("\n\nAdministrador cadastrado com sucesso.");

        system("pause");
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

    system("cls");
    printf("-----------LOGIN------------");

    printf("\n\nDigite o login do admin:\n\n");
    scanf("%s",&login);
    fflush(stdin);

    printf("\n\nDigite a senha do admin:\n\n");
    scanf("%s",&senha);
    fflush(stdin);

    printf("\n");
    printf("-----------------------------");

    if(checaLoginAdmin(login,senha) == 1){

        menuAdmin(login);

    }else{

        printf("\n\n\nLogin ou senha incorretos, ou a conta de adm informada nao existe.\n\n");

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

    system("cls");

    printf("\n\n");

    system("cls");

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
            system("cls");
            menuPadrao();
            break;
     }


}



//Produto

void addProduto(){

    Produto produto;

    system("cls");

    printf("--------------CADASTRO DE PRODUTO-------------------\n\n\n");

    printf("Digite um identificador numerico de produto: \n\n");
    scanf("%d",&produto.id);
    fflush(stdin);

    while(checaIdProduto(produto.id) == 1){
        printf("\nIdentificador de produto já cadastrado, por favor insira outro:\n\n");
        scanf("%d",&produto.id);
        fflush(stdin);
    }

    printf("\nDigite o nome do produto: \n\n");
    fgets(produto.nome,100,stdin);
    fflush(stdin);
    fflush(stdin);

    while(checaNomeProduto(produto.nome) == 1){
        printf("\nNome de produto já cadastrado, por favor insira outro:\n\n");
        fgets(produto.nome,100,stdin);
        fflush(stdin);
        fflush(stdin);
    }

    fflush(stdin);
    printf("\nDigite o tipo do produto: \n\n");
    fgets(produto.tipo,100,stdin);
    fflush(stdin);


    printf("\nDigite o preço do produto: \n\n");
    scanf("%lf",&produto.preco);
    fflush(stdin);

    printf("\nDigite a quantidade do produto: \n\n");
    scanf("%d",&produto.quantidade);
    fflush(stdin);

    produto.ativo = 1;

    produtos[produtoCadastradoQtd] = produto;

    produtoCadastradoQtd++;

    printf("\n\nProduto cadastrado com sucesso.");

    system("pause");

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

char* getNomeProdutoById(int id){

    int i = 0;

    for(i = 0; i < produtoCadastradoQtd; i++){
        if(produtos[i].id == id){
            return produtos[i].nome;
        }
    }

    return NULL;

}

void imprimirProdutos(){

    int i = 0, cont = 0, pagina = 1, op = 0;

    system("cls");

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
            cont++;

            if(cont == 15){
                printf("\n\nPagina [%d]\n",pagina);
                printf("\n\nDigite 1 para proxima página ou 0 para sair.");
                scanf("%d",&op);
                if(op == 0){
                    break;
                }
                cont = 0;
                pagina++;
                system("pause");
                system("cls");

            }

        }
    }

    system("pause");
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
        fflush(stdin);

        while(checaIdProduto(id) != 1){
            printf("\n\nProduto não encontrado. Por favor, digite um id válido.");
            scanf("%d",&id);
            fflush(stdin);
        }

        editPorId(id);
        fflush(stdin);

    }else if(op == 2){
        printf("\n\nDigite o nome do produto que deseja editar:\n\n");
        fgets(nome,100,stdin);
        fflush(stdin);
        fflush(stdin);

        while(checaNomeProduto(nome)!= 1){
            printf("\n\nProduto não encontrado. Por favor, digite um id válido.");
            fgets(nome,100,stdin);
            fflush(stdin);
            fflush(stdin);

        }

        editPorNome(nome);
        fflush(stdin);
        fflush(stdin);

    }


}

void editPorId(int id){

    int i = 0;

    for(i = 0; i < produtoCadastradoQtd; i++){

        if(produtos[i].id == id){
            printf("\n\nProduto encontrado.\n\n");

            printf("\nDigite o nome do produto: \n\n");
            fgets(produtos[i].nome,100,stdin);
            fflush(stdin);
            fflush(stdin);

            while(checaNomeProduto(produtos[i].nome) == 1){
                printf("\nNome de produto já cadastrado, por favor insira outro:\n\n");
                fgets(produtos[i].nome,100,stdin);
                fflush(stdin);
                fflush(stdin);
            }

            printf("\nDigite o tipo do produto: \n\n");
            fgets(produtos[i].tipo,100,stdin);
            fflush(stdin);
            fflush(stdin);

            printf("\nDigite o preço do produto: \n\n");
            scanf("%lf",&produtos[i].preco);
            fflush(stdin);
            fflush(stdin);

            printf("\nDigite a quantidade do produto: \n\n");
            scanf("%d",&produtos[i].quantidade);
            fflush(stdin);
            fflush(stdin);

            printf("\n\nProduto editado com sucesso.\n\n");


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
            fflush(stdin);
            fflush(stdin);

            while(checaNomeProduto(produtos[i].nome) == 1){
                printf("\nNome de produto já cadastrado, por favor insira outro:\n\n");
                fgets(produtos[i].nome,100,stdin);
                fflush(stdin);
                fflush(stdin);
            }

            printf("\nDigite o tipo do produto: \n\n");
            fgets(produtos[i].tipo,100,stdin);
            fflush(stdin);
            fflush(stdin);

            printf("\nDigite o preço do produto: \n\n");
            scanf("%lf",&produtos[i].preco);
            fflush(stdin);
            fflush(stdin);

            printf("\nDigite a quantidade do produto: \n\n");
            scanf("%d",&produtos[i].quantidade);
            fflush(stdin);
            fflush(stdin);

            printf("\n\nProduto editado com sucesso.\n\n");

            system("pause");
        }
    }

}

void editQtdProduto(){

    int id = 0, qtdProduto = 0, i = 0;

    system("cls");

    printf("\n---------EDITAR QUANTIDADE DO PRODUTO--------\n\n\n");

    printf("Digite o identificador do produto que deseja editar sua quantidade:\n\n");
    scanf("%d",&id);

    printf("\n\n");


    for(i = 0; i < produtoCadastradoQtd; i++){

        if(produtos[i].id == id){

            printf("\nProduto encontrado, sua quantidade é de %d digite\na quantidade que deseja editar:\n\n",produtos[i].quantidade);
            scanf("%d",&qtdProduto);
            fflush(stdin);
            fflush(stdin);

            while(qtdProduto < 0){
                printf("\n\nPara adicionar uma quantidade, o valor deve ser positivo :\n\n");
                scanf("%d",&qtdProduto);
                fflush(stdin);
                fflush(stdin);
            }

            produtos[i].quantidade = qtdProduto;

            printf("\n\nProduto alterado com sucesso. A nova quantidade deste produto em estoque é de : %d", produtos[i].quantidade);

            system("pause");

        }else{

            while(checaIdProduto(id) != 1){
                printf("\nProduto não encontrado, digite um id válido:\n\n");
                scanf("%d",&id);
                fflush(stdin);
                fflush(stdin);
            }

        }
    }

}

void removeProduto(){

    int i = 0, id = 0, op = 0;
    char nome[100], tipo[100];

    system("cls");

    printf("\n---------REMOVER PRODUTO--------\n\n\n");
    printf("Se deseja remover produto pelo id digite [1], se desejar remover pelo nome[2]:\n\n");
    scanf("%d",&op);
    fflush(stdin);
    fflush(stdin);

    if(op == 1){
        printf("\n\nDigite um id válido:\n\n");
        scanf("%d",&id);

        while(checaIdProduto(id) != 1){
            printf("\n\nId digitado não existe, por favor, digite um id válido: \n");
            scanf("%d",&id);
        }

        if(removeProdutoById(id) == 1){
            printf("\n\nProduto removido com sucesso.\n");
            system("pause");

        }else{

            printf("\nErro na remoção do produto, por favor contate a administração.\n\n");
            system("pause");

        }

    }else if(op == 2){
        printf("\n\nDigite um nome válido:\n\n");
        scanf("%s",&nome);
        fflush(stdin);
        fflush(stdin);

        while(checaNomeProduto(nome) != 1){
            printf("\n\nNome digitado não existe, por favor, digite um nome válido: \n");
            scanf("%s",&nome);
            fflush(stdin);
        }

        if(removeProdutoByNome(nome) == 1){
            printf("\n\nProduto removido com sucesso.\n");
            system("pause");

        }else{

            printf("\nErro na remoção do produto, por favor contate a administração.\n\n");

            system("pause");

        }
    }else{
        printf("\n\nOpção inválida!!\n\n");
        system("pause");
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


void cadastroCliente(){

    Cliente cliente;

    system("cls");

    printf("\n\n---------CADASTRO DE CLIENTE---------\n\n");

    printf("Digite o nome do cliente:\n\n");
    fgets(cliente.nome,100,stdin);
    fflush(stdin);
    fflush(stdin);

    printf("\n\nDigite o seu email:\n\n");
    fgets(cliente.email,100,stdin);
    fflush(stdin);
    fflush(stdin);

    printf("\n\nDigite o nome da empresa associada:\n\n");
    fgets(cliente.empresa,100,stdin);
    fflush(stdin);
    fflush(stdin);

    printf("\n\nDigite sua senha:\n\n");
    fgets(cliente.senha,100,stdin);
    fflush(stdin);
    fflush(stdin);

    cliente.ativo = 1;

    cliente.quantCompras = 0;

    clientes[clienteCadastradoQtd] = cliente;

    clienteCadastradoQtd += 1;

    printf("\n\nCliente cadastrado com sucesso!\n\n");
    system("pause");

}


void imprimirClientes(){

    int i = 0;

    system("cls");

    printf("\n\nLista de Clientes cadastrados:\n\n\n\n");

    for(i = 0; i < clienteCadastradoQtd; i++){

        if(clientes[i].ativo == 1){

            printf("Nome: %s\n\n",clientes[i].nome);
            printf("Email: %s\n\n",clientes[i].email);
            printf("Empresa: %s\n\n",clientes[i].empresa);
            printf("Senha: %s\n\n",clientes[i].senha);
            printf("---------------------------------\n\n\n");

        }

    }

}


int checarEmail(char email[100]){

    int i = 0;

    for(i = 0; i < CLIENTEMAX; i++){
        if(strcmp(email,clientes[i].email) == 0){
            return 1;
        }
    }

    return 0;
}

void loginCliente(){

    char email[100],senha[100];

    system("cls");
    printf("-----------LOGIN------------");

    printf("\n\nDigite o login do cliente:\n\n");
    scanf("%s",&email);
    fflush(stdin);
    fflush(stdin);

    printf("\n\nDigite a senha do cliente:\n\n");
    scanf("%s",&senha);
    fflush(stdin);
    fflush(stdin);

    printf("\n");
    printf("-----------------------------");

    if(checaLoginCliente(email,senha) == 1){

        menuCliente(email);

    }else{

        printf("\n\n\nLogin ou senha incorretos, ou a conta de cliente informada nao existe.\n\n");

        system("pause");

        loginCliente();

    }
}


int checaLoginCliente(char email[100], char senha[100]){

    int i = 0;

    for(i = 0; i < ADMMAX; i++){

        if(strcmp(clientes[i].email, email) == 0 && strcmp(clientes[i].senha,senha) == 0){ //Checa se existe dentro do array o login e a senha digitados pelo usuario.

            return 1; //Retorna 1 se foi encontrado

        }
    }

    return 0;

}


void menuCliente(char email[100]){

    int op = 0;

    system("cls");

    printf("\n\n\n");

    printf("Bem vindo, %s",email);

    printf("\n\n\n\n");


    printf("'-------------------------[MENU CLIENTE]-------------------------'\n");
    printf("'                                                                '\n");
    printf("'   Digite [1] para comprar um produto                           '\n");
    printf("'   Digite [2] para listar produtos em estoque                   '\n");
    printf("'   Digite [3] para finalizar compra e gerar nota fiscal         '\n");
    printf("'   Digite [4] para ver e imprimir a nota fiscal                 '\n");
    printf("'                                                                '\n");
    printf("'   Digite [0] para sair do menu cliente                         '\n");
    printf("'                                                                '\n");
    printf("'----------------------------------------------------------------'\n");

     printf("\n\n\n\n");

     scanf("%d",&op);

     switch(op){

        case 1:
            imprimirProdutos();
            compraProduto(email);
            menuCliente(email);
            break;

        case 2:
            imprimirProdutos();
            menuCliente(email);
            break;

        case 3:
            finalizarCompra(email);
            menuCliente(email);
            break;

        case 4:
            lerArquivo();
            menuCliente(email);
            break;

        default:
            system("cls");
            menuPadrao();
            break;
     }


}


//CadastrarCliente();
//LoginCliente();
//VerListaDeProduto();
//ComprarProdutoById();
int comprarProdutoById(int id,int quantidade, Cliente* cli){

    int i = 0;

    for(i = 0; i < produtoCadastradoQtd; i++){

        if(produtos[i].id == id){

            produtos[i].quantidade -= quantidade;

            cli->compras[cli->quantCompras].idProduto = id;

            cli->compras[cli->quantCompras].quantidadeProduto = quantidade;

            cli->compras[cli->quantCompras].precoTotal = quantidade * produtos[i].preco;

            cli->quantCompras++;

            return 1;
        }
    }

    return 0;

}


Cliente * clienteByEmail(char email[100]){

    Cliente cli;

    int i = 0;

    for(i = 0; i < clienteCadastradoQtd; i++){
        if(strcmp(email,clientes[i].email) == 0){
            return &clientes[i];
        }
    }

    return NULL;

}

void compraProduto(char email[100]){

    int id = 0,quantidade = 0, resposta = 0;

    system("cls");

    printf("\n\nDigite o id do produto que deseja comprar:\n\n");
    scanf("%d",&id);

    printf("\n\nDigite a quantidade do produto que deseja comprar:\n\n");
    scanf("%d",&quantidade);

    resposta = comprarProdutoById(id,quantidade,clienteByEmail(email));

    if(resposta == 1){
        printf("\n\nProduto comprado com sucesso.\n\n");
        system("pause");
    }else{
        printf("\n\nOcorreu um erro, contate os administradores.\n\n");
        system("pause");
    }

}

void impressaoTeste(char email[100]){

    int i = 0;
    Cliente * c;

    c = clienteByEmail(email);

    for(i = 0; i < c->quantCompras; i++){

        printf("\nId: %d\n",c->compras[i].idProduto);
        printf("\n\nPreco total: %f\n",c->compras[i].precoTotal);
        printf("\n\nQuantidade: %d\n\n\n\n",c->compras[i].quantidadeProduto);

    }


    system("pause");


}

void finalizarCompra(char email[100]){

    int op = 0;

    printf("\n\nDeseja realmente finalizar a conta e gerar a nota fiscal?(Digite 1 para sim, 0 para não)\n\n");
    scanf("%d",&op);

    if(op == 1){

        criaArquivo("notaFiscal.txt",email);

        system("pause");
    }else{
        menuCliente(email);
    }

}


void criaArquivo(char *nomeArq, char email[100]){

    FILE *arq;

    Cliente *cli;

    cli = clienteByEmail(email);

    int dia,mes,ano,i,qtdCompras = cli->quantCompras;
    float total = 0.0;
    struct tm *local;
    time_t t;


    t= time(NULL);
    local=localtime(&t);

    dia=local->tm_mday;
    mes=local->tm_mon+1;
    ano=local->tm_year+1900;

    arq = fopen(nomeArq,"w");

    if(arq == NULL){

        printf("\nErro na abertura do arquivo.\n");

        system("pause");



    }else{

        fputs("----------NOTA FISCAL-----------\n\n",arq);
        fprintf(arq,"Nome do comprador: %s\n\nData: %d/%d/%d\n\nEmpresa associada: %s\n\n",cli->nome,dia,mes,ano,cli->empresa);
        fprintf(arq,"\n\nItens comprados:\n\n");

        for(i = 0; i < qtdCompras; i++){
            fprintf(arq,"\n\nID: %d   Nome: %s   Quantidade comprada: %d   Valor: R$ %.2f\n\n",cli->compras[i].idProduto, getNomeProdutoById(cli->compras[i].idProduto),cli->compras[i].quantidadeProduto, cli->compras[i].precoTotal);
            total += cli->compras[i].precoTotal;
            fprintf(arq,"\n\n");

        }


        fprintf(arq,"\n\nTotal:                                                   R$ %.2f\n\n",total);
        printf("\n\nNota Fiscal gerada com sucesso.\n\n");
        system("pause");

    }



    fclose(arq);


}

void lerArquivo(){

    FILE* arq;
    char ch;
    int op;

	arq = fopen("notaFiscal.txt", "r");
	if(arq == NULL)
	    printf("Erro, nao foi possivel abrir o arquivo\n");
	else
	    while( (ch=fgetc(arq))!= EOF )
            putchar(ch);

    printf("\n\nVocê deseja imprimir a nota fiscal? (1 para Sim, 0 para não)\n\n");
    scanf("%d",&op);

    if(op == 1){
        system("notepad /p notaFiscal.txt");
    }

    system("pause");

	fclose(arq);
}
