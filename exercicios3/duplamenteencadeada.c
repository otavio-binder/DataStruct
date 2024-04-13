#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    int dado;
    struct No *prox, *ant;
}No;

typedef struct fila{
    No *inicio;
    No *fim;
}fila;

void cria_lista_inserindo_fim(fila *f, int dado){
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = dado;//atribuindo valor ao novo nó, que eh o novo
    if(f->inicio == NULL){ //significa que a lista ta vazia
    f->inicio = novo;
    f->fim = novo;
    novo->prox = NULL;
    } else{
        novo->ant = f->fim; //o anterior ao novo será o atual fim da fila
        f->fim->prox = novo; //então ele será o prox da fila tambem
        novo = f->fim; //entao ele será o ultima da fila 
        novo->prox = NULL; // e apontara pro nulo
    }
}

void imprime_fila(No*p){
    if(p == NULL) return;
    printf("valor armazenado %d\n", p->dado);
    return imprime_fila(p->prox);
}
int main(){
    fila *f;
    f = malloc(sizeof(fila));
    f->fim = NULL;
    f->inicio= NULL;
    cria_lista_inserindo_fim(f, 1);
    cria_lista_inserindo_fim(f, 2);
    cria_lista_inserindo_fim(f, 3);
    imprime_fila(f->inicio);
    return 0;
}