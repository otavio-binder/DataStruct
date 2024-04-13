// string são vetores de char, entao todas vez que usarmos strings teremos que usar um vetor lotado de char
//strings sempre tem que ter o espaço reservado para o '\0' que indica o final de uma string
//para poder ler o espaço entre as palavra usarmos o [^\n] isso permite que leiamos até a quebra de linha
//EXEMPLO: scanf(" %80[^\n]", diretorio aonde está armazenado a palavra)
//Ex:

//colocar sempre um a mais para o \0

//Ex de ler uma string em C

#include<stdio.h>
#include<string.h>//blibioteca que usaremos para poder utilizar funçoes da string

int main(void)
{
  char nome[61];
  
  printf("Digite seu nome: ");
  scanf("%s", nome); //aqui iremos armazenar a string onde o cara vai digitar
  
  printf("O nome armazenado foi: %s", nome);
  
  return 0;
}

//caso eu quisse colocar meu nome completo teria que por o [^\n]
int main(void)
{
  char nome[61];
  
  printf("Digite seu nome: ");
  scanf("[^\n]%s", nome); //aqui iremos armazenar a string onde o cara vai digitar
  
  printf("O nome armazenado foi: %s", nome);
  
  return 0;
}

//agora iremos bota um code para percorre um vetor e escrever a string
//esse code primeiro printa a palavra "string" e depois soletra ela
#include <stdio.h>
#include <string.h>
int main(void)
{
  int i;
  
  //declarando e atribuindo valores no vetor de char
        //texto[7] usa 6 caracteres úteis + 1 caracter para o finalizador
  char texto[7] = "string";
  
  printf("Valor da variavel texto = %s\n", texto);
  
  //Percorrendo o vetor de char e mostrando
  //cada elemento individualmente
  for (i=0; i<6; i++)
  {
    printf("Valor do elemento %d da string = %c\n",i, texto[i]);
  }
  
  return 0;
}

//existem funçoes de string as quais podem facilitar nossa vida, aqui estão elas.
strncpy(string_destino, string_origem, tamanho);// serve para copiar outra string
//Ex:
#include <stdio.h>
#include <string.h> //necessário para strcpy
int main (void)
{
  char nome[15];
  
  strcpy(nome, "Fulano de Tal");
  //strcpy(string_destino, string_origem);
  //note que a string de destino é nome
  //a string de origem é "Fulano de Tal"
  
  printf("Nome = %s", nome);
  return 0;
}
//-----------------------------
strncat(string_destino, string_origem, tamanho); 
/*Realiza a concatenação do conteúdo de uma variável a outra,
porém, deve ser especificado o tamanho a ser concatenado.
Ambas devem ser strings.*/
//Ex:
#include <stdio.h>
#include <string.h>//necessário para strncat
#include <conio.h>
int main (void)
{
  char str1[20] = "Curso";
  char str2[17] = " de programacao C";
  
  strncat(str1, str2, 15);
  //concatena a string1 com 15 posições da string2
  
  printf("str1 = %s\n", str1);
  //Será exibido Curso de Programação
  
  getch();
  return 0;
}
//------------------------------------------------------
strcat(string_destino, string_origem);
/* Realiza a concatenação do conteúdo de uma variável a outra.
Ambas devem ser strings.*/
#include <stdio.h>
#include <string.h>//necessário para strcat
int main (void)
{
  char str[10] = "Curso";
  strcat(str, " de C");
  //Concatena a string " de C" com o conteúdo da string str
  
  printf("str = %s\n", str);
  //Será exibido curso de C
  return 0;
}
//---------------------------------------------------
strlen(string); // variavel do tipo inteiro, determina o tamanho de uma string
//Ex:
#include <stdio.h>
#include <string.h>//necessário para strlen
int main (void)
{
  char str[5] = "Curso";
  int tamanho;
  
  tamanho = strlen(str);
  
  printf("O tamanho da string %s vale %d\n", str, tamanho);
  return 0;
}
//----------------------------------------
strcmp(string1, string2);
/*variável do tipo inteiro = strcmp(string1, string2);

Compara o conteúdo de duas strings;

Possíveis valores de retorno:

0: conteúdo das strings são iguais

< 0: conteúdo da string1 é menor do que string2

> 0: conteúdo da string1 é maior do que string2*/
#include <stdio.h>
#include <string.h>//necessário para strcmp
int main (void)
{
  char str1[4] = "abc";
  char str2[4] = "abd";
  int retorno;
  
  retorno = strcmp(str1, str2);
  printf("retorno = %d\n", retorno);
  //mostra o retorno da função strcmp  
  
  return 0;
}
//---------------------------------------
strncmp(string1, string2, tamanho);//variavel do tipo inteiro
/*Também faz a comparação do conteúdo de duas strings, porém, deve ser especificado o tamanho a ser comparado;

Possíveis valores de retorno:

0: conteúdo das strings são iguais

< 0: conteúdo da string1 é menor do que string2

> 0: conteúdo da string1 é maior do que string2

Exemplo de programa usando strncmp:*/
#include <stdio.h>
#include <string.h>//necessário para strncmp;
int main (void)
{
  char str1[15] = "Curso de C";
  char str2[15] = "Curso de Java";
  int retorno;
  
  retorno = strncmp(str1, str2, 5);
  
  printf("retorno = %d\n", retorno);
  
  return 0;
}
//--------------------------------------------------
strok()
/*A função strtok() permite dividir uma string em partes.

Utiliza um ou mais delimitadores para separar a string em questão.
O retorno de strtok é um ponteiro para o início de uma substring.Caso não encontre nenhuma substring strtok retorna NULL.
O delimitador (separador) é o caracter que indica onde dividir a string.*/
#include <stdio.h>
#include <string.h>//necessário para strtok;
int main (void)
{
  
  char texto1[50]="Fulano de Tal,Rua X.123,Centro,Cidade Y";
  char *t;
  
  t = strtok(texto1," ");
  
  while(texto1 != NULL)
  {
    printf("%s\n",t);
    t=strtok(NULL," ");
  }
        
  system("pause");  //pausa na tela, somente para Windows
  return(0);
}