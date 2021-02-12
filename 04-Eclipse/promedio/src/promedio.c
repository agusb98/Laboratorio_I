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
        fflush(stdout);		//Necesario para que continue ejecutandose luego de presionar enter
        scanf("%f", &num);
        acum += num;
        len++;

        printf("Continuar? (1 or 0): ");
        fflush(stdout);
        scanf("%d", &status);
    } while (status == 1);

    printf("\n ** Promedio: %1.f ** ", acum / len);
    return EXIT_SUCCESS;
}
