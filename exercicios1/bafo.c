#include <stdio.h>

int main(){
    int rodada, anf, bnf, i, sa, sb, aux=0;
    scanf("%d", &rodada);
    while (rodada != 0) //; o erro era o ponto e virgula
    {   
        sa = 0;
        sb = 0;
        for(i=0 ; i<rodada; i++){
            scanf("%d %d", &anf, &bnf);
            sa += anf;
            sb += bnf;
        }
        aux++;   
        printf("Teste %d\n",aux);
        if(sa>sb){
            printf("Aldo\n\n");
        }
        else{ // Ã© bom colocar um if(sa<sb) para caso de testes escondidos
            printf("Beto\n\n"); // adicionei mais um \n para pular duas veze
        }
        scanf("%d", &rodada);
     }

}
