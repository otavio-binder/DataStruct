//Complexidade assintotica O(N^2) com n^2/2 comparaçoes e n^2/2 trocas
//Caso o vetor esteja ordenado, ele irá verificar ele inteiro até o final, mas com a condição de parada ele n faz isso (L17)
//ele funciona no principio de flutuar os menores numeros para o topo e os numeros mais pesados para baixo
#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void bubblesort(int *v, int l, int r){
    for(int j = l; j<r ; j++){
    for(int i = l; i<r ; i++){
        if(v[i+1]<v[i]){
            swap(&v[i+1], &v[i]);
        }
        }
    }
    for(int i = 0; i<14 ; i++){
    printf("%d ", v[i]);}
}

int main(){
    int v[14] = {3, 1100, 93, 45, 27, 15, 3980, 7, 49, 343, 501, 2, 34, 69 };
    bubblesort(v, 0, 13);
}