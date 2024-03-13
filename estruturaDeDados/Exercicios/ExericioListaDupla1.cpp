#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <ctype.h>
// #include <math.h>
// #include <time.h>

#define INICIO "------------INICIO------------" 
#define RESULTADO "------------RESULTADO------------"
#define CORTE "------------------------"

typedef char string[40];

typedef struct tipoFilme {
    int anoProducao;
    string titulo;
    tipoFilme *ante; //ponteiro para o filme anterior
    tipoFilme *prox; //ponteiro para o proximo filme
}Tfilme;

typedef struct tipoLista{
    Tfilme *primeiro; //inicio
    Tfilme *ultimo; //fim
    int total; //Quantidade de registros na lista
}Tlista;

Tlista lista; //variavel global

void inicializa(Tlista *lista){
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->total = 0;
}

void digitarDados(Tfilme *elementoNovo){
    printf("Digite o titulo do filme: ");
    scanf(" %39[^\n]s", elementoNovo->titulo);
    printf("Digite o ano de produção do final: ");
    scanf("%d", &elementoNovo->anoProducao);
}

// void insere(Tlista *lista, string titulo, int ano){
//     Tfilme *novo = (Tfilme *)malloc(sizeof(Tfilme));
//     Tfilme *atual;
//     int flag = 0;
//     novo->anoProducao = ano;
//     strcpy(novo->titulo,titulo);
//     novo->prox = NULL;
//     novo->ante = NULL;

//     if (lista->primeiro == NULL){
//         //Lista encontra-se vazia.
//         //Inserir o primeiro e unico elemento da lista ate agora
//         lista->primeiro = novo;
//         lista->ultimo = novo;
//         flag = 1;
//     }else{
//         //Lista ja possui pelo menos 1 elemento
//         atual = lista->primeiro;
//         while (atual != NULL){
//             if (strcmp(atual->titulo,novo->titulo) > 0){
//                 //encontrada a posiçao para a inserçao do novo Tfilme
//                 flag = 1;
                
//                 if (atual == lista->primeiro){
//                     //Inserir novo no inicio da lista
//                     novo->prox = atual;
//                     atual->ante = novo;
//                     lista->primeiro = novo;
//                 }else{
//                     //Inserir novo no meio da lista
//                     novo->prox = atual;
//                     novo->ante = atual->ante;
//                     atual->ante->prox = novo;
//                     atual->ante = novo;
//                 }
//                 break;
//             }
//             atual = atual->prox; //move para o próximo elemento
//         }
//         if (flag == 0){
//             //inserir o novo como o ultimo Tfilme da lista
//             lista->ultimo->prox = novo;
//             novo->ante = lista->ultimo;
//             lista->ultimo = novo;
//         }
//     }
//     lista->total++;
// }

void insere(Tlista *lista){
    Tfilme *novo = (Tfilme *)malloc(sizeof(Tfilme));
    Tfilme *atual;
    int flag = 0;
    digitarDados(novo);
    novo->prox = NULL;
    novo->ante = NULL;
    if (lista->primeiro == NULL){
        //Lista encontra-se vazia.
        //Inserir o primeiro e unico elemento da lista ate agora
        lista->primeiro = novo;
        lista->ultimo = novo;
        flag = 1;
    }else{
        //Lista ja possui pelo menos 1 elemento
        atual = lista->primeiro;
        while (atual != NULL){
            if (strcmp(atual->titulo,novo->titulo) > 0){
                //encontrada a posiçao para a inserçao do novo Tfilme
                flag = 1;
                
                if (atual == lista->primeiro){
                    //Inserir novo no inicio da lista
                    novo->prox = atual;
                    atual->ante = novo;
                    lista->primeiro = novo;
                }else{
                    //Inserir novo no meio da lista
                    novo->prox = atual;
                    novo->ante = atual->ante;
                    atual->ante->prox = novo;
                    atual->ante = novo;
                }
                break;
            }
            atual = atual->prox; //move para o próximo elemento
        }
        if (flag == 0){
            //inserir o novo como o ultimo Tfilme da lista
            lista->ultimo->prox = novo;
            novo->ante = lista->ultimo;
            lista->ultimo = novo;
        }
    }
    lista->total++;
}

int pedirOpcao(){
    int op;
    printf("\n%s\n", INICIO);
    do{
        printf("1 - Inserir na Lista\n");
        printf("2 - Exibe Lista\n");
        printf("3 - Excluir da Lista\n");
        printf("4 - Sair\n");
        printf("Digite a opção: ");
        scanf("%d", &op);
        printf("%s\n", CORTE);
    } while ((op < 1)||(op > 4));
    return op;
}

//=================================================
int main(){
    int op;
    // char nome[40];
    int repete = 0;
    inicializa(&lista);   
     do{
        op = pedirOpcao();
        switch (op){
        case 1:
            // numInseri = pedirNum();
            insere(&lista);
            break;
        case 2:
            // exibeLista(lista); 
            break;
        case 3:
            // numInseri = pedirNum2();
            // pedirNome(nome);
            // excluirLista(&lista,nome);
            break;
        case 4:
            repete = 1;
            break;
        default:
            break;
        }
    } while (repete == 0); 
    return 0;
}

//================================================