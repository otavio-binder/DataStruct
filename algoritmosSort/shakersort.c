//eh uma variação do bubblesort, um pouco mais eficiente
//complexidade O(n^2/2)
//quando coloca o elemento mais leve em cima, bota o elemento mais pesado no fundo na volta

#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void shakersort(int *v, int l, int r){
    int max = r;
    for(int j = l; j<r ; j++){
    for(int i = l; i<r ; i++){
        if(v[i+1]<v[i]){
            swap(&v[i+1], &v[i]);
        }
        }
        if(v[max]<v[j]) v[j] = v[max];
        swap(&max, &r);
        max--;
    }
    for(int i = 0; i<10 ; i++){
    printf("%d ", v[i]);}
}

int main(){
    int v[10] = {55, 21, 4, 13, 98, 1, 25, 782, 145, 26};
    shakersort(v, 0, 9);
}