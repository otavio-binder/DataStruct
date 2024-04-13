#include<stdio.h>

int main(){
    int rodada, figA, figB, sa, sb, aux, i;
    scanf("%d", &rodada);
    while(rodada != 0){
        sa= 0;
        sb= 0;
        for(i =0 ; i<rodada; i++){
            scanf("%d %d", &figA, &figB);
            sa += figA;
            sb += figB;
        }
        printf("Teste %d\n", aux);
        if(sa>sb){
            printf("Aldo\n");
        }
        else{
            printf("Beto\n");
        }

     }
    return 0;
 }