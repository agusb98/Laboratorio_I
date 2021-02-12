/*
 ============================================================================
 Name        : biblioteca.c
 Author      : agusb
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "library/calculadora.h"

int main(){
    float result;
    float num_one = 0;
    float num_two = 0;
    char operator;

    printf(" ** CALCULADORA ** \n\n");

    printf("Primer Numero: ");
    fflush(stdout);
    scanf("%f", &num_one);

    printf("Segundo Numero: ");
    fflush(stdout);
    scanf("%f", &num_two);

    printf("Operador: ");
    fflush(stdout);
    scanf("%s", &operator);

    switch (operator){
        case '-':
            result = Resta(num_one, num_two);
            break;

        case '*':
            result = Multiplicacion(num_one, num_two);
            break;

        case '/':
            result = Division(num_one, num_two);
            break;

        default:
            result = Suma(num_one, num_two);
            break;
    }

    printf(" ** Resultado: %1.f ** ", result);
    return EXIT_SUCCESS;
}
