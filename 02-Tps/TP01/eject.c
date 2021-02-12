#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "eject.h"

/** \brief Print main
 *
 * \param
 * \param
 * \return option choosed
 *
 */

int principalMain(float num1, float num2){
    system("cls");
    printf(">>Menu de Opciones\n");
    printf("\n1_ Ingresar 1er operando (A = %.1f)", num1);
    printf("\n2_ Ingresar 2do operando (B = %.1f)", num2);
    printf("\n3_ Calcular todas las operaciones");
    printf("\n4_ Informar resultados");
    printf("\n5_ Salir");

    fflush(stdin);
    return getInt("\n\nIngrese opcion: ");
}

/** \brief Print kind of calculates that programme is able to do
 *
 * \param
 * \param
 * \return void
 *
 */

void calculate_operations(float num1,float num2)
{
    printf("\n>>Menu de Calculos\n");
    printf("\n\t Calcula la suma (%.1f + %.1f)", num1, num2);
    printf("\n\t Calcula la resta (%.1f - %.1f)", num1, num2);

    if (num2 != 0)
        printf("\n\t Calcula la division (%.1f / %.1f)", num1, num2);

    else
        printf("\n\t No se puede dividir por 0");

    printf("\n\t Calcula la multiplicacion (%.1f * %.1f)", num1, num2);

    if (validFactorial(num1) && validFactorial(num2))
        printf("\n\t Calcula la factorizacion (%.1f) y (%.1f)", num1, num2);
    else
        printf("\n\t No se puede sacar factorial del Operando Ingresado");

    printf("\n\n");
}

/** \brief Calculate all operations
 *
 * \param
 * \param
 * \return void
 *
 */

void report_operations(float num1,float num2)
{
    printf("\n>>Menu de Informes\n");
    printf("\n\t El resultado de %.1f + %.1f es: %.1f", num1, num2, sum(num1, num2));
    printf("\n\t El resultado de %.1f - %.1f es: %.1f", num1, num2, rest(num1, num2));

    if (num2 != 0)
    printf("\n\t El resultado de %.1f / %.1f es: %.1f", num1, num2, division(num1, num2));

        else
            printf("\n\t No es posible dividir por cero");

    printf("\n\t El resultado de %.1f * %.1f es: %.1f", num1, num2, multiplicate(num1, num2));

    if (validFactorial(num1) && validFactorial(num2))
        printf("\n\t El resultado de %.1f! es: %d y %.1f! es: %d", num1, factorial(num1), num2, factorial(num2));
    else
        printf("\n\t No se puede sacar factorial del Operando Ingresado");

    printf("\n\n");
}

/** \brief Sum two variables type float
 *
 * \param
 * \param
 * \return float answer
 *
 */

float sum(float num1,float num2)
{
    float result = (num1 + num2);
    return result;
}

/** \brief Rest two variables type float
 *
 * \param
 * \param
 * \return float answer
 *
 */

float rest(float num1,float num2)
{
    float result = (num1 - num2);
    return result;
}

/** \brief Div two variables type float
 *
 * \param
 * \param
 * \return float answer
 *
 */

float division(float num1,float num2)
{
    float result = (num1 / num2);
    return result;
}

/** \brief Multiplicate two variables type float
 *
 * \param
 * \param
 * \return float answer
 *
 */

float multiplicate(float num1,float num2)
{
    float result = (num1 * num2);
    return result;
}

/** \brief Take factorial number type float
 *
 * \param int aux
 * \param int result
 * \return int answer
 *
 */

int factorial(float a)
{
    int aux, result = 1;
    aux = (int)a;

        for(int i=1 ; i<=aux; i++)
            result *= i;

    return result;
}

/** \brief Valid if the number is type int
 *
 * \param aux
 * \param
 * \return (1)Ok - (0) number is not type int
 *
 */

int validFactorial(float a)
{
    int aux = (int)a;
    int flag=1;

    if (!a) //El factorial de 0 es 1
        return 1;

    if(a < 1 || a != aux)
        flag=0; //Caso de numero negativo o flotante

    return flag;
}
