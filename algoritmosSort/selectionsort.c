//Complexidade assintotica O(N^2)
//Comportamento normalmente entre (N^2)/2
//ele percorre o vetor, armazena o menor valor e bota na posição "j", depois incrementa o "j " e busca o menor valor novamente
//ele n é estavel , ele n preserva a ordem original do vetor

#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void selectionsort(int *v, int l ,int r){
    if( l == r)return;
    int min = l;
    for(int i = l+1 ; i<r ; i++){
        if(v[min]>v[i]) min = i;
    }
    swap(&v[min], &v[l]);
    
    for(int i = 0; i<10 ; i++){
    printf("%d ", v[i]);}
    printf("\n");
    selectionsort(v, l+1, r);
}


int main(){
    int v[10] = {55, 21, 4, 13, 98, 1, 25, 782, 145, 26};
    selectionsort(v, 0, 10);
    for(int i = 0 ; i<10 ; i++){
        printf("%d ", v[i]);
    }
    return 0;
}
    