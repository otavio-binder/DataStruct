//algoritmo de ordenação com O(LogN)
//ordena vetores com a visualizaçao de sua arvores, onde o pai é maior que seus filho
//i fica na posição do pai e 2*i eh seu filho a esqueda e 2*i +1 é seu filho a direita
typedef int Item;

typedef struct heap
{
 Item *v;
 int size;
}heap;

#define less(A, B) (A < B)
#define exch(A, B) { Item t=A; A=B; B=t; }

heap *heap_new(int capacidade){
    heap *heapnew = malloc(sizeof(heap));
    newheap->v = malloc(sizeof(Item)* capacidade);
    newheap->size = 0;

}

void fixup(heap *h, int i){
    int pai= i/2;
    while(i > 1 && less(h->v[i], h->vv[pai])){
    exch(h->v[i], h->v[pai]);
    i = i/2;
}
}

void insert(heap *h, int new){
    h->v[h->size +1] = new;
    h->size ++;
    fixup(h, h->size);
}

Item top(heap *h){ return h->v[1];}

void fixdown(heap *h, int i){
    int child;
    while (i*2 <= h->size){
        child = 2*i;

    if(child != h->size && h->v[child] < h->v[child + 1]){ //a meu filho n ta no final e meu filho da esquerda é menor do que o da direita?
        child++; // se for, meu filho vira o da direita
    }
    if(h->v[i] < h->v[child]) { //o meu pai é menor que meu filho?
        
        exch(h->v[i], h->v[child]); // se for trocarei-me com o meu pai
        i = child; //e me tornarei o filho do meu filho
    }
    else break;

    }
}

void remover(heap *h){
    exch(h->v[1], h->v[h->size]); //trocando a raiz com o ultimo elemento
     h->size--;
    fixdown(h, 1);
}

void heapfy(heap *h){
    for(int i = 1; i<=h->size, i++){
        fixup(h, i);
    }
}