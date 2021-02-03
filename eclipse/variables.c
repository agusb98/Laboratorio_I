#include <stdio.h>
#include <stdlib.h>

int main(){
    int num = 33;
    float flotante = 31.9;
    char letra = 'a';
    char cadena_letras[100] = "Carlos";

    printf("Numero: %d\n", num);
    printf("Flotante: %f\n", flotante);
    printf("Letra: %c\n", letra);
    printf("String: %s\n", cadena_letras);
    
    return EXIT_SUCCESS;
}