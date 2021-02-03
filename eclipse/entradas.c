#include <stdio.h>
#include <stdlib.h>

int main(){
    float num_one = 0;
    float num_two = 0;
    
    printf("CALCULADORA\n\n");

    printf("Primer Operador: ");
    scanf("%f", &num_one);

    printf("Segundo Operador: ");
    scanf("%f", &num_two);

    printf("Resultado Suma: %1.f", num_one + num_two);
    
    return EXIT_SUCCESS;
}