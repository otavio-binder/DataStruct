#include<stdio.h>
#include<stdlib.h>

int somador(int numero, int soma){
    if(numero == 0) return soma;
    soma += numero%10;
    numero = numero/10;
    somador(numero, soma);
}

int main(){
    int numero, soma=0;
    scanf("%d", &numero);
    printf("teu nuemro ae %d\n", numero);
    printf("o resultado da soma %d\n", somador(numero, soma));
    return 0;
}