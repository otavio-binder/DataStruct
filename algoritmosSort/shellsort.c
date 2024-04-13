//Shell sort é uma algoritmo elementar, mas muito mais eficiente que os outros elementares
//ele é uma otimização do insertion, que faz saltos nas suas comaparações
//sua complexidade é imprevisivel em casos medios, mas geralmente é O(n^2) nos piores e O(n log^2 n)
#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void insertionH(int *v, int l, int r, int h){
    for(int i = l+h ; i<=r; i++){
        int j = i;
        int temp = v[i];
        while(j >= l && v[j-h]> temp){
           if(v[j] < v[j-h]){ 
            v[j] = v[j-h];
            j = j-h;
        }

    }
}
}

void shellsort(int *v, int l, int r){
    int h;
    for(int h = 1; h <= (r-l)/9; h = 3*h+1){
        for( ; h>0; h = h/3){
        insertionH(v, l, r, h);
    }}

}

int main(){
    int v[25] = {55, 21, 4, 13, 98, 1, 25, 782, 145, 26, 85, 313, 9412, 32, 124, 4532, 3412, 563, 5123, 214, 521, 61, 234, 918};
    shellsort(v, 0, 25);
    for(int i = 0 ; i<25 ; i++){
        printf("%d ", v[i]);
    }
    return 0;
}