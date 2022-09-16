/*  Ejercicio 2
Dada la frase "Programcion Procedural 2021", leerla desde un teclado en una cadena de caracteres
a) Remplezar el 1 por un cero
b) Copiar la palabra "Programacion" a una nueva cadena de caracteres.
c) contar la cantidad de vocales de la frase */

#include <stdio.h>
#include <string.h>

void intercambio( char text[50]){
    char *p;
    p = strstr(text,"2");
    *p = '1';
    printf("%s",text);
	return;    
}

void copia(char text[50],char new_text[50]){
    strncpy(new_text,text,12);
    printf("La nueva cadena es: %s \n", new_text);
    return;
}

void cuenta_vocales(char text[50]){
    int cant,i;
    cant = 0;
    for( i = 0 ; i < 50 ; i++){
        if(text[i] == 'a' || text[i] == 'e' || text[i] == 'i'|| text[i] == 'o' || text[i] == 'u' ){
            cant ++;
        }
    }
    printf("Hay un total de %i vocales", cant);
}

int main(){
    char text[50], new_text[50];
    printf("Ingrese el Texto: ");
    fgets(text,50,stdin);
    printf("%s",text);
    intercambio(text);
    copia(text, new_text);
    cuenta_vocales(text);

}