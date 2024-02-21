#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define INICIO "------------INICIO------------" 
#define RESULTADO "------------RESULTADO------------"
#define CORTE "------------------------"

struct TElemento{
    int valor;
    struct TElemento *prox; 
};
typedef struct TElemento TElemento;

struct TLista{
    TElemento *inicio;
    TElemento *fim;
    int total;    
};
typedef struct TLista Tlista;

void inicializa(Tlista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->total = 0;
}

void inserir(Tlista *lista, int valor){
    int inseriu = 0;
    TElemento *novo = (TElemento *)malloc(sizeof(TElemento));
    novo->valor = valor;
    novo->prox = NULL;
    if (lista->inicio == NULL){
        //Lista encontra-se vazia.
        //Inserir o primeiro e unico elemento da lista ate agora
        lista->inicio = novo;
        lista->fim = novo;
        lista->total = 1;
        inseriu = 1;
    }else{
        //Lista ja possui pelo menos 1 elemento
        TElemento *atual = lista->inicio;
        TElemento *anterior = NULL;
        while (atual != NULL){
            if (atual->valor >= novo->valor){
                if (anterior == NULL){
                    //Inserir novo antes do primeiro da lista
                    novo->prox = atual;
                    lista->inicio = novo;
                }else{
                    //Inserir no meio da lista
                    novo->prox = atual;
                    anterior->prox = novo;
                }
                inseriu = 1;
                lista->total++;
                break;
            }
            anterior = atual;
            atual = atual->prox; //move para o próximo elemento
        }
    }
    if (!inseriu){
        //Inserir elemento no fim da lista
        lista->fim->prox = novo;
        lista->fim = novo;
        lista->total++;
    }
    
}

void exibeLista(Tlista lista){
    TElemento *atual = lista.inicio;
    int cont = 0;
    printf("\n\n\n\t\t===| EXIBE LISTA COMPLETA |===\n\n");
    while (atual != NULL){
        printf("\n%s\n", RESULTADO);
        printf("Numero do %d da lista e: (%d)\n", ++cont, atual->valor);
        atual = atual->prox;
    }
    printf("%s\n", CORTE);

}

int pedirOpcao(){
    int op;
    printf("\n%s\n", INICIO);
    do{
        printf("1 - Inserir na Lista\n");
        printf("2 - Exibe Lista\n");
        printf("3 - Sair\n");
        printf("Digite a opção: ");
        scanf("%d", &op);
        printf("%s\n", CORTE);
    } while ((op < 1)||(op > 3));
    return op;
}

int pedirNum(){
    int num;
    do{
        printf("Digite um numero para ser inserido: ");
        scanf("%d", &num);
    } while (num < 0);
    return num;
}

Tlista lista; //variavel global

//=================================================
int main(){
    int op, numInseri;
    int repete = 0;
    inicializa(&lista);
    do{
        op = pedirOpcao();
        switch (op){
        case 1:
            numInseri = pedirNum();
            inserir(&lista,numInseri);
            break;
        case 2:
            exibeLista(lista);
            break;
        case 3:
            repete = 1;
            break;
        default:
            break;
        }
    } while (repete == 0);
    return 0;
}

//Lista Simplesmente Encadeada
//19-02-2024
//
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct tipoElemento {
// 	int valor;
// 	tipoElemento *prox;
// }TElemento;

// typedef struct tipoLista {
//     TElemento *inicio;
//     TElemento *fim;
//     int total;
// }TLista;

// TLista lista; //variável global

// void inicializa(TLista *L);
// void insere(TLista *L;int valor);


// int main(){
// 	inicializa(&lista);
	
// }
// //==============================================
// void inicializa(TLista *L){
// 	L->inicio = NULL;
// 	L->fim = NULL;
// 	L->total = 0;
// }
// //===============================================
// void insere(TLista *L;int valor){
// 	TElemento *novo = (TElemento *)malloc(sizeof(TElemento));
	
// 	novo->valor = valor;
// 	novo->prox = NULL;
	
// 	if(L->inicio == NULL){
// 		//Lista encontra-se vazia.
// 		L->inicio = novo;
// 		L->fim = novo;
// 		L->total = 1;
// 	} else {
// 		//Lista possui pelo menos um elemento.
// 		TElemento *atual = L->inicio;
// 		TElemento *anterior = NULL;
		
// 		while(atual != NULL){
// 			if(atual->valor >= novo->valor)	{
// 				if(anterior == NULL){
// 					//Inserir novo como primeiro da lista.
// 					novo->prox = atual;
// 					L->inicio = novo;
// 				}else{
// 					//inserir no meio da lista
// 					novo->prox = atual;
// 					anterior->prox = novo;
// 				}
// 				break;
// 			}
// 			anterior = atual;
// 			atual = atual->prox; //move para o próximo elemento
// 		}//while
// 		L->total++;
// 	}//if
	
// }
// //===============================================