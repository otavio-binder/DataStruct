//encontrar um elemento dentro de um vetor
/*a busca de arvore binaria, ao contrario da busca binaria, ela n precisa ter os elementos ordenados, mas sim se o 5 for a raiz
da arvore, todos os elementos a sua esquerda devem ser menor do que ele, e a direita maior do que ele*/
#include<stdio.h>
#include<stdlib.h>

typedef int Key;

typedef struct{
    Key key;
    int item;
}Item;

#define key(A) ((A).key)
#define lesskey(A, B) ((A) < (B))
#define less(A, B) (lesskey(key(A), key(B)))


typedef struct Node
{
    Node *left, *right;
    Item item;
}Node;


Node *inserir(Node* root, Item item){
    if(root == NULL){ // Se a árvore estiver vazia
    Node* novo = malloc(sizeof(Node)); //iremos criar um novo nó
    novo->right = NULL; // fazendo seus apontadores serem nulos
    novo->left = NULL;
    novo->item = item; // e receber o valor do item colocado
    return root; //retornando ele
    }
    if(less(root->item, item)){ //se o antigo item é menor do que o novo item sendo colocado
    root-> right = inserir(root->right, item); //iremos inserir ele na direita, e chamamos a função novamente para verificar o NULL
    }
    else if(less(item, root->item)){//se novo item é menor do que o antigo
    root->left = inserir(root->left, item);// ele será colocado na esquerda,  e chamamos a função novamente para verificar o NULL
    }
    else root->item = item;//se ele n for menor e nem maior, ele é igual, entao apenas retornamos o valor

    return root;

}

Node *buscaArvore(Node *root, Key k){
    if(root == NULL) return NULL; //Se a arvore estiver vazia, n tem o que buscar

    Key actualkey = key(root->item); //definindo uma variavel com a chave atual sendo a chave do item

    if(lesskey(actualkey, k)){ //se a chave atual é menor que a chave procurada
    root-> right = buscaArvore(root->right, k); //iremos procurar na direita, e chamamos a função novamente para verificar o NULL
    }
    else if(lesskey(k, actualkey)){//se a chave atual é maior que a chave procurada
    root->left = buscaArvore(root->left, k);//iremos procurar na esquerda, e chamamos a função novamente para verificar o NULL
    }
    else return root;//se n eles são iguais e achamos o que queriamos
}


Node *minNode(Node* root){
    if(root->left == NULL){ //se a esquerda do meu nó aponta pro nulo, chegamos no menor
        return root; //chegamos no elemento mais ao fundo
    } 
    return minNode(root->left); // se n, faço tudo de novo sempre indo para a esquerda
}


Node *deletemin(Node *root){
    if(root->left == NULL){ //se a esquerda do meu nó aponta pro nulo, chegamos no menor
    return root->right; // entao apenas iremos ignorar a existencia dele
    }
    root->left = deletemin(root->left); // caso n tenhamos chego no fim, iremos devolver o valor para a função até achar
    return root; // e iremos retornar o valor do galho
}

Node *remocaoArvore(Node *root, Key k){
    if(root == NULL) return NULL; // se a arvore estiver vazia, n tem o que remover

    Key actualkey = key(root->item); //definindo uma variavel com a chave atual sendo a chave do item

    if(lesskey(actualkey, k)){ //se a chave atual é menor que a chave procurada
    root->right = remocaoArvore(root->right, k);//iremos atrás na subarvore direita
    }
    else if(lesskey(k, actualkey)){ //se a chave atual é maior que a chave procurada
    root->left = remocaoArvore(root->left, k);//iremos atrás na subarvore esquerda
    }
    else{ //se nao for nenhum dos dois, encontramos o que queriamos
        if(root->right == NULL){ //se a subarvore direita do no for nula
            Node *aux = root->left;//guardaremos o filho a esquerda para n ser perdido
            free(root); //deletamos seu pai
            return aux;// e retornamos o filho
        }
        else if(root->left == NULL){ //se a subarvore esquerda for nula
            Node *aux = root->right; //guardamos o filho da direita
            free(root); //matamos o pai
            return aux; // e retornamos o filho a drieta
        }
    }

    Node *aux = root; //se nenhuma subarvore for nula, guardamos o valor do nó
    root = minNode(root->right); //encontramos o menor valor a direita da subarvore, o menor dos maiores, e colocamos ele com a raiz
    root->left = aux->left; //fazemos o filho a esquerda da nova raiz, ser o filho da antiga raiz
    root->right = deletemin(aux->right); 
    free(root);
    return aux;
}