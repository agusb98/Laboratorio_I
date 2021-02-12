#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* this;
    int flag = 0;
    int status; //Contador de lectura
    char auxId[50], auxName[50], auxHoursWorked[50], auxSalary[50];

    //Hago una primera lectura "fantasma" para leer el titulo el cual no voy a almacenar
    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxName, auxHoursWorked, auxSalary);

    while(!feof(pFile))     //Mientras no se llege al final del archivo
    {
        status = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxName, auxHoursWorked, auxSalary);

        if(status == 4)     //Si status es igual a los 4 datos pedidos a leer
        {
            //Le asigno a "this" las variables leidas casteadas en la funcion

            this = employee_newParametros(auxId, auxName, auxHoursWorked, auxSalary);
            ll_add(pArrayListEmployee, this);    //Agrego "this" al final del array de empleados
            flag= 1;
        }
    }
    fclose(pFile); //Cierro el archivo
    return flag;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* this; //Creo un nuevo empleado
    int status; //Contador de lectura
    int flag = 0;

    while(!feof(pFile))
    {
        this = employee_new();
        status = fread(this, sizeof(Employee), 1, pFile);

        if(status == 1 && this != NULL)
            ll_add(pArrayListEmployee, this);

        else if(status != 1)
        {
            if(!feof(pFile)) //Si aun no se llego al final del archivo lo informo
            {
                printf("\tError al leer el ultimo dato.");
                break;
            }
            else //Si se leyo todo el archivo sin problemas lo informo
            {
                printf("\tEmpleados Cargados\n\n");
                flag = 1;
            }
        }
    }

    fclose(pFile); //Cierro el archivo
    return flag;
}
