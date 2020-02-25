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
    char var_1[50], var_2[50], var_3[50], var_4[50];

    if (pFile != NULL && pArrayList != NULL)
    {
        //Hago una primera lectura "fantasma" para leer el titulo el cual no voy a almacenar
        fscanf(pFile, "%[^,],%[^,],%[^\n]\n", var_1, var_2, var_3);

        while(!feof(pFile))     //Mientras no se llege al final del archivo
        {
            int status = fscanf(pFile, "%[^,],%[^,],%[^\n]\n", var_1, var_2, var_3);

            if(status == 3)     //Si status es igual a los 3 datos pedidos a leer
            {
                //Le asigno a "this" las variables leidas casteadas en la funcion

                eEmpleado* this = _setters(var_1, var_2, var_3, var_4);
                if (this != NULL)
                {
                    ll_add(pArrayList, this);    //Agrego "this" al final del array de la lista
                    flag= 1;
                }
            }
        }
        fclose(pFile); //Cierro el archivo
    }
    return flag;
}
