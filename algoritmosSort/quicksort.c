//esse eh um dos algoritmos de ordenação eficientes
//ele tem complexidade de O(nlogn)

#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int separa(int *v, int l, int r){
    int pivo = v[r];
    int j = l;
    for(int i = l; i<r ; i++){
        if(v[i]<= pivo){
             swap(&v[i], &v[j]);
             j++;
        }
    }
    swap(&v[r], &v[j]);
    return j;
}

int separa2(int *v, int l, int r){
    int pivo = v[r];
    int j = l-1;
    int i = r;
    while(true){
        while(v[++j] < pivo);
        while(pivo < v[--i]) if (i == l) break;
        if(j>=i) break;
        swap(&v[i], v[j]);
    }
    swap(&v[i], &v[r]);
    return i;
}

void quicksortpadrao(int *v, int l, int r){
    int j;
    if(r <= l) return;
    j = separa(v, l, r);
    quicksort(v, l, j-1);
    quicksort(v, j+1, r);

}

void quicksortMedianaDe3(int *v, int l, int r){
    int j;
    if(r <= l) return;
    if(v[(l+r)/2]>v[r]) swap(&v[(l+r)/2], &v[r]);
    if(v[(l+r)/2]<v[l]) swap(&v[(l+r)/2], &v[l]);
    if(v[(l+r)/2]<v[r]) swap(&v[(l+r)/2], &v[r]);
    j = separa(v, l, r);
    quicksort(v, l, j-1);
    quicksort(v, j+1, r);
}