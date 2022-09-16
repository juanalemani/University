/* Ejercicio 3
 Generar un arreglo de registros que posea las siguiente informacion de 10 alumnos de procedural
- Nombre
- Apellido
- DNI
a) cargar los datos de los alumnos
b) listar los alumnos cargados
c) Indicar cuantos alumnos tienen DNI mayor a 40 millones
*/

#include <stdio.h>
#include <string.h>
#define N 2

struct alumno {
char nombre[50];
char apellido[50];
int dni;
};

void carga(struct alumno alumnos[N]){
    int i;
    for(i = 0 ; i < N ; i++ ){
        printf("Ingrese el nombre del Alumno: ");
        fflush(stdin);
        fgets(alumnos[i].nombre, 50 , stdin);
        printf("Ingrese el apellido del Alumno: ");
        fflush(stdin);
        fgets(alumnos[i].apellido, 50 , stdin);
        printf("Ingrese el DNI del Alumno: ");
        fflush(stdin);
        scanf("%i",&alumnos[i].dni);
    }
}

void mostrar(struct alumno alumnos[N]){
    int i;
    for(i = 0 ; i < N ; i++){
        printf("Alumno Inscripto #%i",i + 1);
        printf("Nombre: %s",alumnos[i].nombre);
        printf("Apellido: %s",alumnos[i].apellido);
        printf("DNI: %i", alumnos[i].dni);
    }
}

void mostrarDni(struct alumno alumnos[N]){
    int count,i;
    count = 0;
    for( i = 0 ; i < N ; i++){
        if(alumnos[i].dni > 40000){
            count += 1;
        }
    }
    printf("Hay un total de %i alumnos con DNI mayor a 40.000", count);

}

int main(){
    struct alumno alumnos[N];
    carga(alumnos);
    mostrar(alumnos);
    mostrarDni(alumnos);
    return 0;
}