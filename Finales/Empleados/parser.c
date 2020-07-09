#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "empleados.h"

/** \brief Parsea los datos desde el archivo (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int parser_FromText(FILE* pFile, LinkedList* pArrayList)
{
    int flag = 0;
    char var_1[50], var_2[50], var_3[50], var_4[50], var_5[50], var_6[50];

    //Hago una primera lectura "fantasma" para leer el titulo el cual no voy a almacenar
    fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", var_1, var_2, var_3, var_4, var_5);

    while(!feof(pFile))     //Mientras no se llege al final del archivo
    {
        int status = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", var_1, var_2, var_3, var_4, var_5);

        if(status == 5)     //Si status es igual a los 5 datos pedidos a leer
        {
            //Le asigno a "this" las variables leidas casteadas en la funcion

            eEmpleado* this = _setters(var_1, var_2, var_3, var_4, var_5, var_6);
            ll_add(pArrayList, this);    //Agrego "this" al final del array de la lista
            flag= 1;
        }
    }
    fclose(pFile); //Cierro el archivo
    return flag;
}

/** \brief Parsea los datos desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int parser_FromBinary(FILE* pFile, LinkedList* pArrayList)
{
    int flag = 0;
    while(!feof(pFile))
    {
        eEmpleado* this = _new();
        int status = fread(this, sizeof(eEmpleado), 1, pFile);

        if(status == 1 && this != NULL)
            ll_add(pArrayList, this);

        else if(status != 1)
        {
            if(!feof(pFile)) //Si aun no se llego al final del archivo lo informo
            {
                printf("\tError al leer el ultimo dato.");
                break;
            }
            else //Si se leyo todo el archivo sin problemas lo informo
            {
                printf("\tDatos Cargados\n\n");
                flag = 1;
            }
        }
    }

    fclose(pFile); //Cierro el archivo
    return flag;
}
