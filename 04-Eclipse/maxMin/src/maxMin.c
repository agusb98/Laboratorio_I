#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    float min = INT_MAX;
    float max = INT_MIN;
    float num;
    int len = 5;

    printf("MAXIMO Y MINIMO\n\n");
/*
    for (int i = 0; i < len; i++){
        printf("Ingrese numero: ");
        fflush(stdout);
        scanf("%f", &num);

        if(num > max){
            max = num;
        }
        else if(num < min){
            min = num;
        }
    }
*/
    int status = 1;

    do{
        printf("Ingrese numero: ");
        fflush(stdout);
        scanf("%f", &num);

        if(num > max){
            max = num;
        }
        if(num < min){
            min = num;
        }

        printf("Continuar? (1 or 0): ");
        fflush(stdout);
        scanf("%d", &status);
    } while (status == 1);

    printf("\n ** Maximo: %1.f - Minimo: %1.f ** ", max, min);

    return EXIT_SUCCESS;
}
