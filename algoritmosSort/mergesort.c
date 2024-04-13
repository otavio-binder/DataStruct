//O mergesort já é mais eficiente, ele consiste em ir dividindo os vetores, até torna-lo unitarios
//logo apos isso vamos percorrendo vetor por vetor, ordenando e juntando eles novamente até ordena-lo por inteiro
//normalmente se usa uma abordagem recursiva da função, para facilitar e otimizar o seu funcionamento

#include<stdio.h>
#include<stdlib.h>

void merge(int *v, int l, int m, int r){
    int *v2 = malloc(sizeof(int)*(r-l+1)); //reservando espaço para o outro vetor
    int k = 0, i = l, j = m +1; // definindo os sentinelas
    while(i <= m && j <= r){ // ordenando os vetores
        if(v[i]<v[j]) v2[k++] = v[i++];
        else v2[k++] = v[j++];
    }
    while(i <= m) v2[k++] = v[i++]; //copiando os ultimos elementos para dentro do vetor
    while(j <= r) v2[k++] = v[j++]; //copiando os ultimos elementos para dentro do vetor
    k = 0;
   for(i = l ; i<=r ; i++) v[i] = v2[k++]; //devolvendo tudo pro vetor original
   free(v2);
}

void mergesort(int *v, int l, int r){ //chamda para dividir ao meio
    if(r<=l) return;
    int meio = (r+l)/2;
    mergesort(v, l, meio); //chamada para dividir a primeira metadade
    mergesort(v, meio+1, r); //chamada para dividir a segunda metade
    merge(v, l, meio, r); // chamada para ordenar e ir ordenando
    
}

int main(){
    int v[10] = {55, 21, 4, 13, 98, 1, 25, 782, 145, 26};
    mergesort(v, 0, 9);
    for(int i = 0 ; i<10 ; i++){
        printf("%d ", v[i]);
}
return 0;
}