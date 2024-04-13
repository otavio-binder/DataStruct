#include<stdio.h>

//LISTAS
/*LISTA ESTASTICAS
-conjunto do mesmo tipo de dado
-Espaço consecutivo na memoria RAM
-ACESSO ALEATORIO: qualquer posiçao pode ser acessada facilmente atraves de um index
-Nome -> corresponde ao endereço de memoria
-Tamanho fixo(stack) ou alocado dinamicamente(heap)
ISSO SAO TUDO VETORES MENOR*/
/*LISTAS ENCADEADAS
-Conjunto de nós -> item+link para outro nó
-Mais adequado para manipulações do que acessos:
.--Maior eficiencia para rearranjar os itens(reapontamentos)
.--Nao tem acesso direto aos intens 
-Operaçoes: buscar, inserir, remover*/

//Exemplificação:
typedef int item;

typedef struct registro node;
struct registro{
    item info;
    node *prox;
};

//LISTA ENCADEADAS COM CABEÇA E SEM CABEÇA:
//era pra ter um ex mas n peguei
