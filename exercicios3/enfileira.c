#include<stdio.h>
#include<stdlib.h>

typedef struct No{ //criando os nos da fila 
    int dado;
    struct No *prox; //ponteiro que aponta pro proximo no
}No;

typedef struct Fila{
    No *inicio; //def o inicio
    No *fim; // def o fim

}Fila;

void insere_fim(Fila *f1, int dado){
    No *novo = (No*) malloc(sizeof(No)); // reservando o espaço para a criaçao do no
    novo->dado = dado; //atribuindo valor ao novo no
    novo->prox = NULL; //certificando que ele eh o ultimo da fila
    if(novo != NULL){ // caso ele exista
        if(f1->inicio == NULL){ //se a fila for vazia
            f1->inicio = novo; //o iniciio receberá o novo
            f1->fim = novo; // e o seu fim será ele tbm
        }else{ //mas caso nao seja o unico elemento da lista
            f1->fim->prox = novo; // o proximo do final da fila será o novo
            f1->fim = novo; // e consequentemente será o final
        }
    }
}

int remove_inicio(Fila *f1){
    if(f1->inicio == NULL) return 0; //se a fila for vazia, parar
    if(f1->inicio->prox == NULL) f1->inicio = NULL; //se a fila soh tiver um elemento, ele será removido
    f1->inicio = f1->inicio->prox;/*atualizando o valor, agora o antigo segundo valor será o primeiro,
    já que o antigo primeiro foi removido*/
}

void printafila(No *aux){
    if(aux == NULL) return;
    printf("valor: %d\n", aux->dado);
    return printafila(aux->prox);
}

int main(){
    Fila *f1;
    f1 = malloc(sizeof(Fila));
    f1->inicio = NULL;
    f1->fim = NULL;
    insere_fim(f1, 10);
    insere_fim(f1, 20);
    insere_fim(f1, 30);
    insere_fim(f1, 40);
    printafila(f1->inicio);
    printf("removendo o primeiro\n");
    remove_inicio(f1);
    printafila(f1->inicio);
    return 0;
}