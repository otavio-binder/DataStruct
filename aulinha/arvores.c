/*podemos dizer que a arvore tem uma hierarquia nos dados armazenados nela
Exs de usos:
*/

//criando um no da arvore
typedef struct No
{
    int dado;
    struct No *direita, *esquerda; 
}No;
