#include <stdio.h>

int main(){
    int a, soma, media;
    soma = 0;
    int i;
    for(i=0; i<10; i++){
        printf("digite o valor\n");
        scanf("%d", &a);
        soma = soma + a;
    }
    media = soma/10;
    printf("%d", media);
    return 0;
    
}
