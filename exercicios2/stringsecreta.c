/*#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(){
    int code, i=0;
    char vet[1001];
    while(scanf("%x", &code)!= EOF){
        vet[i] = code;
        i++;
    }
    printf("em inteiro é %d\n", code);  
    for(int j = 0; j<i ; j++){  
    printf("o codigo é: %c\n",(char)(vet[j]+'0')); //+'0' eh pra transformar pra tabela ascii
    }
}codigo q eu fiz q ta meio certo*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int vet[1001], i = 0;
    char *pvet;
    while (scanf("%x", &vet[i]) == 1 ) i++;

    *pvet = &vet[i];

    printf("%s", pvet);

    return 0 ;
    
}