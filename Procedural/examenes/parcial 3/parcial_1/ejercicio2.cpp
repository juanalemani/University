#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef char cadena[20];

typedef struct tarjeta{
    int numero;
    cadena nombre;
    float cupo;
};

struct nodo{
    int numero;
    cadena nombre;
    struct nodo *sig;
};

typedef struct nodo *puntero;


void insertar_tarjeta(FILE *archi){
    tarjeta tarj;
    archi = fopen("tarjetas.dat", "ab");
    if(archi == NULL){
        printf("Error al abrir el archivo");
        exit(1);
    }
    printf("Ingrese el numero de tarjeta: ");
    scanf("%i", &tarj.numero);
    printf("Ingrese el nombre del titular: ");
    gets(tarj.nombre);
    fflush(stdin);
    printf("Ingrese el cupo de la tarjeta: ");
    scanf("%f", &tarj.cupo);
    fwrite(&tarj, sizeof(tarjeta), 1, archi);
    fclose(archi);
}

void crear(FILE *archi, puntero &cabeza){
    tarjeta aux;
    puntero nuevo;
    archi = fopen("tarjetas.dat", "rb");
    if(archi == NULL){
        printf("Error al abrir el archivo");
    }else{
        while(fread(&aux, sizeof(tarjeta), 1, archi)){            
            if(aux.cupo > 400000){
                nuevo = (puntero)malloc(sizeof(struct nodo));
                nuevo->numero = aux.numero;
                strcpy(nuevo->nombre, aux.nombre);
                nuevo->sig = cabeza;
                cabeza = nuevo;
            }        
        }
    }
    fclose(archi);
}

void eliminar(puntero &cabeza, int num){
    puntero aux;
    if(cabeza != NULL){
        if(cabeza->numero == num){
            aux = cabeza;
            cabeza = cabeza->sig;
            free(aux);
        }else{
            eliminar(cabeza->sig, num);
        }
    }    
}
void nuevoArchivo(puntero cabeza, FILE *archi){
    if(cabeza!=NULL){
        fwrite(cabeza, sizeof(struct nodo), 1, archi);        
    }
    nuevoArchivo(cabeza->sig, archi);
}

int main(){
    FILE*archi;
    puntero cabeza;
    cabeza=NULL;
    int num;
    insertar_tarjeta(archi);
    crear(archi, cabeza);
    printf("Ingrese el numero de tarjeta a eliminar: ");
    scanf("%i", &num);
    fflush(stdin);
    eliminar(cabeza, num);
    FILE *archi;
    archi = fopen("tarjetas2.dat", "ab");
    nuevoArchivo(cabeza, archi); 
    fclose(archi);
    return 0;
}    