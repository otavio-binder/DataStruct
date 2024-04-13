#include<stdio.h>
#include<stdlib.h>
//definindo os elementos da lista
typedef struct celula{
int dado;
struct celula *prox;

} celula;
//criando a lista
void criar(){
celula cabeca;
celula *atual = &cabeca;
celula *temporario;
for(int i = 0; i < 5; i++){
    temporario = malloc(sizeof(celula));
    temporario -> dado = i;

    atual -> prox = temporario;
    atual = temporario;
}
}
 busca(celula *le, int x){
    *aux = le->novo;
    while(aux != NULL && x>1){
        aux = novo->prox;
        x--;
 }
    if(x != 1) aux = NULL;
    return aux;

}
