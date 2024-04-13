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
            COMPLEXIDADE CONSTANTE
            OperaÃ§Ãµes bÃ¡sicas:
                vazia
                tamanho
                primeiro - busca_inicio
                ultimo - busca_fim
                enfileira - insere_fim 
                desenfileira - remove_inicio

    ImplementaÃ§Ã£o com lista encadeada
        Com cabeÃ§a

        ind vazia(head *lista)
            Complexidade - constante

        int tamanho(head *lista)
            Complexidade - constante

        node *primeiro(head *lista)
            Devolve o primeiro elemento da lista
            Elemento mais velho da fila
            Complexidade - constante


        node *ultimo(head *lista)
            Devolve o Ãºltimo elemento da lista
            Elemento mais novo da fila
            Complexidade - constante

            
        void enfileira(head *lista, node *novo)
            Insere no fim da lista
            Complexidade - busca pelo Ãºltimo


        Item desenfileira(head *lista)
            Remove o elemento mais velho 
            free
            Complexidade - constante

    DEQUE
        Uma fila dupla (= deque, pronuncia-se deck) permite inserÃ§Ã£o e remoÃ§Ã£o em qualquer das duas pontas
*/

/*
 * Tipos abstrato de dados
 *  FIFO - first in first out
 *  FILA
 */


typedef int Item;

typedef struct registro node;
struct registro {
    Item info; 
    node *prox;
};

//tipo head
typedef struct cabeca head;
struct cabeca {
    int num_itens;
    node *prox;
    node *ultimo;
};


head * criar_lista();
node *criar_no(Item);

int vazia(head *);
int tamanho(head *); 

node *primeiro(head *); 
node *ultimo(head *);

void enfileira(head *, Item); //insere_fim
Item desenfileira(head *);  //remove_inicio .. busca_inicio .. remove_no



head * criar_lista()
{
    head *le = malloc(sizeof(head));
    le->num_itens = 0;
    le->prox = NULL;
    le->ultimo = NULL;
    return le;
}

node *criar_no(Item x)
{
    node *no = malloc(sizeof(node));
    no->prox = NULL;
    no->info = x;
    return no;
}

int vazia(head *p)
{ 
    return (p->prox==NULL); 
}

int tamanho(head *lista) 
{
    return lista->num_itens;
}

node *primeiro(head *lista) 
{
    return lista->prox;
}
 
node *ultimo(head *lista)
{
    return lista->ultimo;
}
  
void enfileira(head *lista, Item x) 
{
    node *novo = criar_no(x);
    if(novo){
        
        novo->prox = NULL;
        
        //cabeca != node
        if(!vazia(lista)) lista->ultimo->prox = novo;
        else lista->prox = novo;

        lista->ultimo = novo;
        lista->num_itens++;

        
        
    }
}

Item desenfileira(head *lista)
{
    node *lixo = primeiro(lista);
    lista->prox = lista->prox->prox;

    //cabeca != node
    if(lixo == lista->ultimo) lista->ultimo = NULL;
    lista->num_itens--;

    Item x = lixo->info;
    free(lixo);
    return x;
}




///////////////////////////////////////////////////
///////////////////////////////////////////////////
void imprime(head *lista){
    printf("%d itens\n", lista->num_itens);
    
    node *a = lista->prox;
    while(a!=NULL) {
        printf("%3d", a->info);
        a = a->prox;
    }
    
    if(lista->ultimo) printf("\nÃºltimo item: %d", lista->ultimo->info);
    printf("\n\n");
}



#define N 6
void distancias_do_inicio(int mapa[][N], head *fila_cidades, int inicio, int *distancia)
{
    for(int cidade=0; cidade<N; cidade++) distancia[cidade] = N; //infinito
        
    enfileira(fila_cidades, inicio);
    distancia[inicio] = 0;
    while(!vazia(fila_cidades)){
    
        inicio = desenfileira(fila_cidades);
        
        for(int cidade=0; cidade<N; cidade++)
        {
            if(mapa[inicio][cidade]==1 && distancia[cidade]>=N)
            {
                distancia[cidade] = distancia[inicio] + 1;
                enfileira(fila_cidades, cidade);
            }
        }
    }
}

///////////////////////////////////////////////////
///////////////////////////////////////////////////
int main(){
    head *cidades = criar_lista();
    int dist[N];
    int mapa[N][N] ={ {0, 1, 0, 0, 0, 0},
                      {0, 0, 1, 0, 0, 0},
                      {0, 0, 0, 0, 1, 0},
                      {0, 0, 1, 0, 1, 0},
                      {1, 0, 0, 0, 0, 0},
                      {0, 1, 0, 0, 0, 0}};
                      
    
    
    
    distancias_do_inicio(mapa, cidades, 3, dist);
    
    printf("DistÃ¢ncias:\n");
    for(int cidade=0; cidade<N; cidade++)
    {
        printf("3-%d = %d\n", cidade, dist[cidade]);
    }
    printf("\n");
    
    return 0;
}