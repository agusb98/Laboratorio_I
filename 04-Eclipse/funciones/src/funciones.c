/*
 ============================================================================
 Name        : funciones.c
 Author      : agusb
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

float Suma(float a, float b);
float Resta(float a, float b);
float Multiplicacion(float a, float b);
float Division(float a, float b);

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

//FUNCIONES

float Suma(float a, float b){
    return a + b;
}

float Resta(float a, float b){
    return a - b;
}

float Multiplicacion(float a, float b){
    return a * b;
}

float Division(float a, float b){
    if(b == 0){
        return 0;
    }
    return a / b;
}
