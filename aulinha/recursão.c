/* caso eu queira digitar muito eu tenho q usar essa budega aqui ->*/
//Recursão
//É a propriedade daquilo que pode se repetir varias vezes
//Dependencia entre os elementos do conjunto -> elemento atual depende da determinaçao de um elemento anterior ou posterior
//NECESSITA DE UMA CONDIÇAO DE PARADA PARA TERMINAR A RECURSAO 
//São implementados através de funções, basicamente é uma função chamando uma função, e isso vira uma putaria legal tipo a do ponteiro
//Isso leva ao stack, que forma o empilhamento

//Ex: fatorial iterativo

int n = 3;
int x = n;
int t = 1;
while(n>0){
     t *= n;
     n--
 }
printf("%d! = %d\n", x , t);


//Ex: fatorial recursivo
int fat(int n){
    if(n == 0){ 
        return 1;
    }
    return n * fat(n-1);
}
//chamando a função
int x = fat(3); 
// o processo de stack começa

//fiboacci recursivo
int fib(int n){
    if (n == 0) return 0 ;
    if (n == 1) return 1;
    return fib(n-1) + fib(n-2);
}
//chamando a funçao
int a = fib(3);

/* VALIDANDO DOS ALGORITMOS RECURSIVOS*/
//a sequencia recursiva precisa ser finita
/*METODO DA INDUÇÃO FINITA: provar propriedades que sao verdadeira para uma sequencia de objetos
Passo base
passo indutivo ou hipotese da indução*/
//Ex::FUNÇAO PARA ACHAR O MAIOR NUMERO
int max(int n, int v[]){
    if (n==1) return v[0];
    else{
        int x = max(n-1, v);
        //x é o maior em v[0.. n-2]
        if (x> v[n-1]) return x;
        else return v[n-1];
    }
}

//EFICACIA X EFICIENCIA EM FIBONACCI
//eficiencia
int p2(int n) //chamada da funcao
{
    int i, f1 = 1, f2 = 1, soma;
    for(i=3; i<=n; i++){
        soma = f1+f2;
        f1 =f2;
        f2 = soma;
    }
    return f2;
}