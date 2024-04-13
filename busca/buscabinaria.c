//encontrar um elemento dentro de um vetor
/*a bucas binaria soh pode ser usada em um vetor ordenada, ela divide o vetor ao meio, comparar o indicie do meio do vetor 
ver se o indicie que está sendo procurado eh menor ou maior*/
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
    for(int i = 0; i<16 ; i++){
    printf("%d ", v[i]);}
    printf("\n");
}

void mergesort(int *v, int l, int r){ //chamda para dividir ao meio
    if(r<=l) return;
    int meio = (r+l)/2;
    mergesort(v, l, meio); //chamada para dividir a primeira metadade
    mergesort(v, meio+1, r); //chamada para dividir a segunda metade
    merge(v, l, meio, r); // chamada para ordenar e ir ordenando
    
}

int buscabinaria(int *v, int comeco, int fim, int objetivo){ //iremos retornar o indicie do elemento que estamos procurando
    int meio = (comeco+fim)/2;

    if(comeco>fim) return -1;

    if(v[meio] < objetivo){
    return buscabinaria(v, meio+1, fim, objetivo);
    }

    else if(objetivo< v[meio]){
    return buscabinaria(v, comeco, meio-1, objetivo);
    }

    else if(objetivo == v[meio]) return objetivo;
}

int main(){
    int v[16] = {735, 732, 758, 149, 251, 148, 356, 845, 196, 236, 372, 460, 144, 934, 295, 139};
    mergesort(v ,0 , 15);
    int inde = buscabinaria(v, 0, 15, 372);
    printf("esse EH A PORRO  DO index %d", inde);
    return 0 ;
}