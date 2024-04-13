#include<stdio.h>

int main(){
    int xm, ym, xd, yd, xc, yc;
    scanf("%d %d %d %d", &xm, &ym, &xd, &yd);
    xc = xm - xd;
    yc = ym - yd;
    int cruzamentos = xc + yc;
    if(cruzamentos<0){ 
        cruzamentos = (cruzamentos*(-1));}
    printf("%i", cruzamentos);
    return 0;
}