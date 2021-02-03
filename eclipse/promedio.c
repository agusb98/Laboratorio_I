#include <stdio.h>
#include <stdlib.h>

int main(){
    float num;
    float acum = 0;
    int status = 1;
    int len = 0;
    
    printf("PROMEDIO\n\n");

    do{
        printf("Ingrese numero: ");
        scanf("%f", &num);
        acum += num;
        len++;

        printf("Continuar? (1 or 0): ");
        scanf("%d", &status);
    } while (status == 1);
    
    printf("\nPromedio: %1.f", acum / len);
    return EXIT_SUCCESS;
}