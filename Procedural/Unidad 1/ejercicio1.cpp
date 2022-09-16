#include <stdio.h>
#define N 20

void carga_array(int array[N]) {
    int i;
    for(i=0; i<N; i++) {
        array[i] =i;
    }
    return;
}

void busca_cero(int array[N]) {
    int cond,i;
    cond = 0;
    i = 0;
    while (cond< 0 && i < N)
    {
        if(array[i]==0){
            cond = 1;
        }
        i++;
    }
    if(cond==1) {
        printf("En el arreglo hay un cero");
    }
    else printf("En el arreglo no presenta ceros");
    return;
}

void muestra_pares(int array[N]) {
    int i;
    for(i=0; i<N; i++) {
        if(i%2==0) {
            printf("posicion %i numero %i",i,array[i]);
        }
    return;
    }
}

void cuenta_pares(int array[N]) {
    int i, cuenta;
    cuenta = 0;
    printf("Numeros pares en el arreglo");
    for(i=0; i<N; i++) {
        if(array[i]%2==0) {
            cuenta++;
        }
    }
    printf("hay un total de %i numeres pares",cuenta);
    return;
}


int main(){
    int array[N];
    carga_array(array);
    busca_cero(array);
    cuenta_pares(array);
    return 0;
}