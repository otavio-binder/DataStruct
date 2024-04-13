#include <stdio.h>
#include <stdlib.h>

/*
    FILAS
        TIPO ABSTRATO DE DADOS
            Conjunto de dados encapsulados como um objeto, com um comportamento bem definido
            Esconder internamente as estruturas de dados e a lÃ³gica nos procedimentos
            Ocultamento de informaÃ§Ã£o (caixa preta)
            ManipulaÃ§Ã£o da fila somente atravÃ©s da funÃ§Ãµes
        
        FIFO (first-in first-out) 
            Primeiro elemento inserido Ã© o primeiro a ser processado/retirado
            OperaÃ§Ãµes/funÃ§Ãµes para acesso aos elementos (fechado/caixa preta)
            InserÃ§Ãµes no fim, remoÃ§Ãµes no inÃ­cio
            OperaÃ§Ãµes bÃ¡sicas:
                vazia
                tamanho
                primeiro - busca_inicio
                ultimo - busca_fim
                enfileira - insere_fim 
                desenfileira - remove_inicio
        
    ImplementaÃ§Ã£o com lista estÃ¡tica 
        https://www.ime.usp.br/~pf/algoritmos/aulas/fila.html



    fila[p..u-1]

       0     p                                   u            N-1
 	|     | 111 | 222 | 333 | 444 | 555 | 666 |      |      |     |

    p - inicio da fila
    u - fim da fila

*/

#define N 10
int fila[N];
int p, u;

void criar_fila ()
{
   p = u = 0;
}

int vazia()
{
   return p >= u;
}


int desenfileira()
{
   return fila[p++];
}

void enfileira (int y)
{
   fila[u++] = y;
}

void imprime()
{
    printf("p=%d : u=%d\n", p, u);
    for(int i=p; i<u; i++) printf("%3d", fila[i]);
    printf("\n");
}

void imprime_memoria(int fim)
{
    printf("\nmemoria a partir do endereÃ§o apontado por fila\n");
    for(int i=0; i<fim; i++) printf("%3d", fila[i]);
    printf("\n");
    printf("=================================================\n\n");
}

int main()
{
    criar_fila();
    for(int i=0; i<10; i++) enfileira(i);

    imprime();
    //imprime_memoria(12);

    for(int i=p; i<3; i++) desenfileira();

    imprime();
    //imprime_memoria(12);

    
    //enfileira(-1);

    //imprime();
    //imprime_memoria(12);
    
    
    
    return 0;
}