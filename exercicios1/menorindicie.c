#include<stdio.h>

int main(){
    int A, b, i, maior, menor;
    int vet[A];
    scanf("%d", &A);
    for(i=0; i<A; i++){
        scanf("%d", &vet[i]);
        if(vet[i]>vet[maior]){
            vet[maior] = vet[i];
        }
        if(vet[i]<vet[menor]){
            vet[menor] = vet[i];
        }
    }
    printf("menor, %d\n", vet[menor]);
    printf("maior, %d\n", vet[maior]);

}