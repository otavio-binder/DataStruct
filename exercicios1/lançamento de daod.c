#include<stdio.h>

int main(){
    int d1, d2, n, i;
    i = 0;
    printf("quantidade de vezes que irá lançar:\n");
    scanf("%d", &n);
    while(i < n){
        printf("digite os valores dos dados\n");
        scanf("%d", &d1);
        scanf("%d", &d2);
        if(d1 > d2){
            printf("o primeiro valor é maior que o segundo\n");
    }
        else if(d1 < d2){
            printf("o segundo o valor é maior que o primeiro\n");
    }
        else{
            printf("os valores são iguais\n");
    }
    i++;
    }   
}