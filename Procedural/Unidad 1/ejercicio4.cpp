#include <stdio.h>
#include <string.h>
#define N 50
#defien M 22

typedef struct{
    int cod;
    float precio;
    int stock;
}producto;

typedef struct{
    char name[20];
    int num;
    int count;
}proveedor;

void carga_productos(producto prod[N]){
    int i;
    for(i=0;i<N;i++){
        printf("Ingrese el codigo del producto: ");
        scanf("%i", &prod[i].cod);
        printf("Ingrese el precio del producto: ");
        scanf("%f", &prod[i].precio);
        printf("Ingrese el stock del producto: ");
        scanf("%i", &prod[i].stock);
    }
}

void carga_proveedores(proveedor prov[M]){
    int i;
    for(i=0;i<M;i++){
        printf("Ingrese el nombre del proveedor: ");
        scanf("%s", prov[i].name);
        printf("Ingrese el numero de proveedor: ");
        scanf("%i", &prov[i].num);
        prov[i].count=0;
    }
}

void ventas(producto prod[N], proveedor prov[M]){
    int cod, prove, cant;
    printf("Ingrese el codigo del producto: (cero para salir) ");
    scanf("%i", &cod);
    while(cod != 0){
        printf("Ingrese el numero de proveedor: ");
        scanf("%i", &prove);
        printf("Ingrese la catidad de unidades vendidas: ");
        scanf("%i", &cant);
        prod[cod].stock - cant;
        prov[prove].count ++;
        printf("Ingrese el codigo del producto: (cero para salir) ");
        scanf("%i", &cod);
    }
}

mostrar_inversion(producto prod[N]){
    int i;
    for(i=0;i<N;i++){
        printf("El producto %i hay una inversion de %f", prod[i].cod , prod[i].precio*prod[i].stock);
    }
}

int contar_mejores(proveedor proveedores[M]){
    int i ,cont;
    cont = 0;
    for|i=0;i<M;i++){
        if(proveedores[i].count > 10){
            cont ++;
        }
    }
    return cont;
}

void carga_subarray(proveedor proveedores[M], proveedor mejores[M] , int cant ){
    int i, j;
    j=0;
    for(i=0;i<M;i++){
        if(proveedores[i].count > 10){
            mejores[j] = proveedores[i];
            j++;
        }
    }
}

void mostrar_sub(proveedor mejores[M], int cant){
    int i;
    for(i=0;i<cant;i++){
        printf("El proveedor %s con codigo %i vendio mas de 10 productos", mejores[i].name, mejores[i].num);
    }
}

void buscar_proveedor(proveedor mejores[M], int cant , chat nombre[20]){
    int i;
    i = 0;
    while(i < M){
        if(strcmp(mejores[i].name, nombre) == 0){
            printf("El proveedor %s con codigo %i realizo %i ventas", mejores[i].name, mejores[i].num, mejores[i].count);
        }
        i++;
    }
    if (i == M){
        printf("No se encontro el proveedor");
    }
}

int main(){
    producto productos[N];
    proveedor proveedores[M];
    proveedor mejores_proveedores[M];
    int cant;
    char nombre[20];
    carga_productos(productos);
    carga_proveedores(proveedores);
    ventas(productos, proveedores);
    mostrar_inversion(productos);
    cant  = contar_mejores(proveedores);
    carga_subarray(proveedores, mejores_proveedores, cant);
    mostrar_sub(mejores_proveedores, cant);
    printf("Ingrese el nombre del proveedor a buscar: ");
    gets(nombre);
    buscar_proveedor(mejores_proveedores, cant , nombre);
    return 0;
}