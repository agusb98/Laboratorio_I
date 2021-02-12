#include <stdio.h>
#include <stdlib.h>

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