#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    int item;
    struct No *prox;
}No;

typedef struct pilha
{
    No *inicio;
    No *fim;
}pilha;

void cria_pilha(pilha *f1, int item){
    No *new = (No*) malloc(sizeof(No));
    new->item = item;
    new->prox = NULL;
    if(f1->inicio == NULL){
        printf("A pilha ta vazia, bo colocar coisa\n");
        new->prox = NULL;
        f1->inicio = new;
        f1->fim = new;
    } else{
        new->prox = f1->inicio;
        f1->inicio = new;
    }
    return ;
}

void printar(No *aux){
    if(aux == NULL) return;
    printf("valores contidos %d\n", aux->item);
    return printar(aux->prox);
}

int remove_pilha(pilha *f1){
    if(f1->inicio == NULL) return 0; //pilha vazia
    if(f1->inicio->prox == NULL) f1->inicio == NULL; //pilha tem apenas uma elemento
    f1->inicio = f1->inicio->prox; //a pilha ira ignorar o dado anterior
    return 0;
}

int main(){
    pilha *f1;
    f1 = malloc(sizeof(pilha));
    f1->inicio = NULL;
    f1->fim == NULL;
    cria_pilha(f1, 1);
    cria_pilha(f1, 2);
    cria_pilha(f1, 3);
    printar(f1->inicio);
    printf("removendo as paradas\n");
    remove_pilha(f1);
    printar(f1->inicio);
    return 0;
}