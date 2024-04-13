#include<stdio.h>

int main()
{
    printf("Olá Rose\n");
    int v[2];
    v[0]= 5;
    v[1]= 7;
    //primeiro valor
    printf("v[o] = %d\n", v[0]); //valor da variável
    printf("v[o] = %ld\n", (long int) &v[0]); //decimal
    printf("v[o] = %p\n", (void*) &v[0]); // hexadecimal
    //segundo valor
    printf("v[1] = %d\n", v[1]); //valor da variável
    printf("v[1] = %ld\n", (long int) &v[1]); //decimal
    printf("v[1] = %p\n", (void*) &v[1]); // hexadecimal

    //definindo um ponteiro
    int i;
    int *p;
    p = NULL;
    p = &i; //p aponda para i, p referencia a variavel i logo em seguida

    i = 5
    printf("%d\n", *p) // imprima o valor de i

  

    return 0;
}
//trocando valores

    void troca (int *p, int *q){
        int temp;
        temp = *p;//conteudo de temp = conteudo apontado por p
        *p = *q; // conteudo de p = conteudo apontado por q
        *q = temp;// conteudo de q = conteudo de temp
    }

    //funçoes importantes: malloc, realloc, calloc e free
    void *malloc(size_t size);
    void free(void *ptr);
    void *calloc(size_t nmemb, size_t size);
    void *realloc(void *ptr, size_t size);

//Exemplo aqui caraio
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[32];
    int age;
} Person;


int main() {
    Person person;
    Person* pPerson = &person;
    pPerson->age = 18;
    char name[32] = "mateus";
    strcpy(pPerson->name, name);
    printf("%s\n", pPerson->name);

    return 0;
}
    