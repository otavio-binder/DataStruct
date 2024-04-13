#include<stdio.h>

int main(){
    int comprimento, d_pedagio, c_km, v_pedagio, total;
    scanf("%d %d", &comprimento, &d_pedagio); //pegando valores
    scanf("%d %d", &c_km, &v_pedagio);
    total =(c_km*comprimento)+((comprimento/d_pedagio)*v_pedagio);
    printf("%d", total);
    return 0;
}