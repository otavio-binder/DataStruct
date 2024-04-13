#include<stdio.h>

int main(){
    int vet[10];
    int i, d, maior, contador;
    contador = 0;
    for(i=0; i<5; i++){
        scanf("%d", &vet[i]);
        if(vet[i]>vet[i-1]){
            maior = vet[0];
        } // atribuindo o valor do vetor a varivavel maior
        if(vet[i]>maior){ // se o vet[i] for maior do q o vet
            maior = vet[i];
        }
        if(vet[i] == maior){ //atribuindo o contador
            contador++;
        }
    }
    printf("MAUIRRRRRRRRRR %d\n", maior);
    printf("ele foi escrito %d", contador);
 }