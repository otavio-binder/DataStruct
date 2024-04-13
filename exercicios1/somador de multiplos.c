#include<stdio.h>
int main(){
    int divisor, i, soma, posi_vet;
    soma = 0;
    posi_vet = 0;
    printf("digite seu numero \n");
    scanf("%d", &divisor);
    printf("seu divisor é %d \n", divisor);
    int vet[divisor];
    for(i = 1; i<divisor; i++){ //dividindo as caralhada toda :)
        if(divisor%i == 0){
            vet[posi_vet] = i; //add elemento ao vetor            
            printf("%d \n", i); // printando os valores
            posi_vet++;    
                }
    for(i=0; i<divisor ; i++){
    // soma = soma + vet[i]; SAO IGUAIS CACETA QUE ISSO PORRA TO MALUKO
        printf("%d\n", vet[posi_vet]);
        soma += vet[posi_vet]; 
    
    }
    printf("%d\n", soma); //TA QUASE ACABANDO
    return 0; // a funçao tem q retornar algo neh burrao
        
    }
}
//ta errado esse aqui