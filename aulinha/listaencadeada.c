#include <stdio.h>
#include <stdlib.h>

/*
 * Tipos de dados dos elementos da lista
 *  Item: tipo do conteÃºdo dos nÃ³s
 *  node: tipo de cada nÃ³
 *  head: tipo da cabeÃ§a da lista
 */
 
typedef int Item;

//tipo node
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

//elementos bÃ¡sicos
head *criar_lista();
node *criar_no(Item x);
int vazia(head *p);

//funÃ§Ãµes auxiliares
node *busca_node_n(head *lista, int n);
node *busca_node_ant_node(head *lista, node *ref);
node *busca_node_ant_item(head *lista, Item x);

//inserÃ§Ã£o de nÃ³s jÃ¡ criados
int insere_inicio(head *lista, node *novo);
int insere_fim(head *lista, node *novo);

int insere_depois(head *lista, node *ref, node *novo);
int insere_antes(head *lista, node *ref, node *novo);

int insere_depois_pos(head *lista, node *novo, int n);
int insere_antes_pos(head *lista, node *novo, int n);

//criaÃ§Ã£o e inserÃ§Ã£o de nÃ³s 
void insere_item_inicio(head *lista, Item x);
void insere_item_fim(head *lista, Item x);

void insere_item_depois(head *lista, node *ref, Item x);
void insere_item_antes(head *lista, node *ref, Item x);

void insere_item_pos(head *lista, Item x, int n);
void insere_item_depois_pos(head *lista, Item x, int n);
void insere_item_antes_pos(head *lista, Item x, int n);

//remoÃ§Ã£o de nÃ³s referenciados
void remove_inicio(head *lista);
void remove_depois(head *lista, node *ref);
void remove_depois_pos(head *lista, int n);

//remoÃ§Ã£o de nÃ³s com conteÃºdo especÃ­fico
void remove_item(head *lista, Item x);


///////////////////////////////////////////////////
///////////////////////////////////////////////////

//criar lista
head * criar_lista()
{
    head *le = malloc(sizeof(head));
    le->num_itens = 0;
    le->prox = NULL;
    le->ultimo = NULL;
    return le;
}

//criar nÃ³
node * criar_no(Item x)
{
    node *no = malloc(sizeof(no));
    no->prox = NULL;
    no->info = x;
    return no;
}

//lista vazia
int vazia(head *p){ return (p->prox==NULL); }

///////////////////////////////////////////////////
///////////////////////////////////////////////////



///////////////////////////////////////////////////
///////////////////////////////////////////////////

//busca nÃ³ na posiÃ§Ã£o n
node *busca_node_n(head *lista, int n)
{
    node *aux = lista->prox;
    while(aux != NULL && n>1){
        aux = aux->prox;
        n--;
    }
    if(n!=1) aux = NULL;
    
    return aux;
}

//busca nÃ³ anterior a um nÃ³
node *busca_node_ant_node(head *lista, node *atual)
{
    node *anterior = lista->prox;
    while(anterior != NULL && anterior->prox!=atual){
        anterior = anterior->prox;
    }
    return anterior;
}

//busca nÃ³ anterior a um item
node *busca_node_ant_item(head *lista, Item x)
{
    node *atual = lista->prox;
    node *anterior = NULL;
    while(atual != NULL && atual->info!=x){
        anterior = atual;
        atual= atual->prox;
    }
    if(atual==NULL) anterior == NULL;
    
    return anterior;
}

///////////////////////////////////////////////////
///////////////////////////////////////////////////




///////////////////////////////////////////////////
///////////////////////////////////////////////////

///////////////////////////////////////////////////
//insere um nÃ³ no inicio da lista
int insere_inicio(head *lista, node *novo)
{  

    if(vazia(lista)) lista->ultimo = novo;
    lista->num_itens++;
    
    novo->prox = lista->prox;    
    lista->prox = novo;
    
    return 1;
}

//insere um nÃ³ no final da lista
int insere_fim(head *lista, node *novo)
{
    if(novo) {
        if(vazia(lista)) return insere_inicio(lista, novo);
        
        novo->prox = NULL;
        
        lista->ultimo->prox = novo;
        lista->ultimo = novo;
        lista->num_itens++;
        
        return 1;
    }
    return 0;
}


///////////////////////////////////////////////////
//insere um nÃ³ depois de outro nÃ³
int insere_depois(head *lista, node *ref, node *novo)
{
    if(ref && novo){
      if(lista->ultimo == ref) 
        return insere_fim(lista, novo);
      
      novo->prox = ref->prox;
      ref->prox = novo;
        
      lista->num_itens++;
      
      return 1;
    }
    return 0;
}


int insere_antes(head *lista, node *ref, node *novo)
{
    if(lista->prox == ref)
        return insere_inicio(lista, novo);
    
    node *anterior = busca_node_ant_node(lista, ref);
    return insere_depois(lista, anterior, novo);
}


///////////////////////////////////////////////////
//insere elemento depois de uma posiÃ§Ã£o
int insere_depois_pos(head *lista, node *novo, int n)
{
    node *aux = busca_node_n(lista, n);
    return insere_depois(lista, aux, novo);
} 


//insere elemento antes de uma posiÃ§Ã£o
int insere_antes_pos(head *lista, node *novo, int n)
{
    if(n==1)
        return insere_inicio(lista, novo);
    
    return insere_depois_pos(lista, novo, n-1);
    
}

//Por que esta versÃ£o nÃ£o Ã© interessante?
int insere_antes_pos_v2(head *lista, node *novo, int n)
{
    node *aux = busca_node_n(lista, n);
    return insere_antes(lista, aux, novo);
}
    

///////////////////////////////////////////////////
//cria e insere novo elemento no inÃ­cio
void insere_item_inicio(head *lista, Item x)
{
    node *novo = criar_no(x);
    if(!insere_inicio(lista, novo)) free(novo);
}


//cria e insere novo elemento no fim 
void insere_item_fim(head *lista, Item x)
{
    node *novo = criar_no(x);
    if(!insere_fim(lista, novo)) free(novo);
}


///////////////////////////////////////////////////
//cria e insere novo elemento depois de outro elemento
void insere_item_depois(head *lista, node *ref, Item x) 
{
    node *novo = criar_no(x);
    if(!insere_depois(lista, ref, novo)) free(novo);
}

//cria e insere novo elemento antes de outro elemento
void insere_item_antes(head *lista, node *ref, Item x)
{
    node *novo = criar_no(x);
    if(!insere_antes(lista, ref, novo)) free(novo); 
}
    

//cria e insere novo elemento depois de uma posiÃ§Ã£o
void insere_item_depois_pos(head *lista, Item x, int n) 
{
    node *novo = criar_no(x);
    if(!insere_depois_pos(lista, novo, n)) free(novo);
}

//cria e insere novo elemento antes de uma posiÃ§Ã£o
void insere_item_antes_pos(head *lista, Item x, int n)
{
    node *novo = criar_no(x);
    if(!insere_antes_pos(lista, novo, n)) free(novo); 
}
        
///////////////////////////////////////////////////
///////////////////////////////////////////////////




///////////////////////////////////////////////////
///////////////////////////////////////////////////
//remove o elemento do inÃ­cio
void remove_inicio(head *lista)
{
    if(!vazia(lista)){
      node *lixo = lista->prox;
      lista->prox = lixo->prox;
      
      if(lixo == lista->ultimo) lista->ultimo = NULL;
      lista->num_itens--;

      free(lixo);
    }
}

//remove elemento depois de um nÃ³
void remove_depois(head *lista, node *ref)
{
    if(!vazia(lista) && ref->prox){
      node *lixo = ref->prox;
      ref->prox = lixo->prox;
      
      if(lixo == lista->ultimo) lista->ultimo = ref;
      lista->num_itens--;

      free(lixo);
    }
}

//remove elemento depois de uma posiÃ§Ã£o
void remove_depois_pos(head *lista, int n)
{
    if(!vazia(lista)) {
      node *ref = busca_node_n(lista, n);
      if(ref!=NULL) remove_depois(lista, ref);
    }
}

//Por que remove_fim nÃ£o Ã© interessante?


///////////////////////////////////////////////////
//apaga elemento com determinado valor
void remove_item(head *lista, Item x)
{
    if(!vazia(lista)) {
      if(lista->prox->info==x) remove_inicio(lista); 
      else {
        node *anterior = busca_node_ant_item(lista, x);
        if(anterior!=NULL) remove_depois(lista, anterior);
      }
    }
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




///////////////////////////////////////////////////
///////////////////////////////////////////////////
int main(){
  head *le = criar_lista();
  
  for(int i=0; i<10; i++) {
    insere_item_inicio(le, i);  
  }
  imprime(le);
  
  for(int i=0; i<5; i++) {
    insere_item_fim(le, i);  
  }
  imprime(le);
  
  printf("Inserindo -9 apÃ³s a posiÃ§Ã£o 5\n");
  insere_item_depois_pos(le, -9, 5);
  imprime(le);
  
  printf("Inserindo -8 apÃ³s a posiÃ§Ã£o 1\n");
  insere_item_antes_pos(le, -8, 1);
  imprime(le);
  
  printf("Removendo primeiro elemento\n");
  remove_inicio(le);
  imprime(le);
  
  printf("Removendo item 0\n");
  remove_item(le, 0);
  imprime(le);
  
  printf("Removendo Ãºltimo elemento\n");
  remove_depois_pos(le, le->num_itens-1);
  imprime(le);
  
  return 0;
}