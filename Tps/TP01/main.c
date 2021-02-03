#include <stdio.h>
#include <stdlib.h>
#include "eject.h"
#include "utn.h"

int main()
{

    printf("hola feo");
    return 0;

    int exit=0, flag1=0, flag2=0;
    float num1=0, num2=0;

    do
    {
        switch(principalMain(num1, num2))
        {
        case 1:
            if (!getValidFloat("1er Operando: ", "Fuera de Rango\n", &num1, -99999999, 99999999, 3))
            {
                flag1=1;
                printf("Numero Ingresado correctamente\n\n");
            }
            break;
        case 2:
            if (!getValidFloat("2do Operando: ", "Fuera de Rango\n", &num2, -99999999, 99999999, 3))
            {
                flag2=1;
                printf("Numero Ingresado correctamente\n\n");
                break;
            }
        case 3:
            if (flag1 && flag2)
                calculate_operations(num1, num2);
            else
                    printf("Ingrese Operador\n");
            break;
        case 4:
            if (flag1 && flag2)
                    report_operations(num1, num2);
            else
                    printf("Ingrese Operador\n");
            break;
        case 5:
            exit=1;
            break;
        default:
            break;
        }
        system("pause");
    }
    while(!exit);

    return 0;
}
