//É um algoritmo de complexidade N, portanto é muito eficiente
//Ele funciona contando as frequencias de cada número, armazenando em um outro lugar, e botando de volta no vetor original
//O radix usa a mesma teoria do counting, porém iremos utilizar ele para contar casa decimais de um número grande
//isso implica entao qque ele é util para ordenar com chaves extensas, como 3812, 194021, 3491, 4501.
//ele avalia o indicie 

#include<stdio.h>
#include<stdlib.h>


typedef int Item;

#define digit(A, B) ()
#define R 8 //n necessariamente será esse tamanho, será o maior valor do vetor
int aux[R]; //vetor auxiliar para colocar as frequencias


#define less(A, B) (A < B)

void countingsort(Item *v, int l, int r){
    int i; int count[R +1];
    for(i = 0; i<=r; i++){
        count[i] = 0; //colocando todos os contadores em 0
    }
    for(i = l ; i <= r; i++){
        count[v[i] +1] ++; // contando as frequencias no vetor de contador
    }
    for(i = 1; i<=r; i++){
        count[i] += count[i-1]; //somando as frequencias anterior com a frequencia atual, até o final do vetor
    }
    for(i = l; i<=r; i++){
        aux[count[v[i]]] = v[i]; //o vetor auxiliar irá receber apenas um dado, colocando ele na sua ultima posição
        count[v[i]]++; //incrementando a posição do count para poder colocar o proximo dado
    }
    for(i = l; i<=r; i++){
        v[i] = aux[i-l]; // colocando o restante dos dados nas posiçoes faltantes
    }


}