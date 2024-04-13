//o primeiro insertionsort, funciona com um bubble indo da direita para a esquerda, e outro da esquerda para direita
/*O segundo insertion, funciona fixando um sentinela na primeira posiçao com o priemiro for
logo em seguida, vamos percorrendo o vetor em seções, armazenando o o menor valor e inserindo ele*/

#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void insertionsort1(int *v, int l, int r){ //maneira ineficiente, eh um bubble indo e outro voltando
    for(int i = l+1 ; i <= r ; i++){
        for(int j = i ; j>l ; j--){
            if(v[j]<v[j-1]) swap(&v[j], &v[j-1]);
        }
    }
    for(int i = 0; i<=12; i++){
    printf("%d ", v[i]);}
    printf("\n");
}

void insertionsort2(int *v, int l, int r){//maneira eficiente, seguramos o valor ao inves de fazer trocas desenecessárias
    for(int i = r; i>l ; i--){
        if(v[i]<v[i-1]) swap(&v[i], &v[i-1]);
    }
    for(int j = l+2 ; j <= r ; j++){
        int aux = v[j];
        while(aux < v[j-1]){
            v[j]= v[j-1];
            j--;
        } 
        v[j] = aux;
    }
    for(int i = 0; i<=12 ; i++){
    printf("%d ", v[i]);}
    
}


int main(){
    int v[12] = {3, 4, 2, 10, 1, 12, 5, 18, 21, 54, 312, 56};
    insertionsort1(v, 0, 11);
    insertionsort2(v, 0, 11);
}