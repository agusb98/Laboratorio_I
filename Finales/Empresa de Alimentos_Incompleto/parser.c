#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "ingredientes.h"
#include "recetas.h"

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
    char var_1[50], var_2[50], var_3[50], var_4[50], var_5[50], var_6[50], var_7[50];

    if (pFile != NULL && pArrayList != NULL)
    {
        //Hago una primera lectura "fantasma" para leer el titulo el cual no voy a almacenar
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", var_1, var_2, var_3, var_4, var_5, var_6, var_7);

        while(!feof(pFile))     //Mientras no se llege al final del archivo
        {
            int status = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", var_1, var_2, var_3, var_4, var_5, var_6, var_7);

            if(status == 7)     //Si status es igual a los 7 datos pedidos a leer
            {
                //Le asigno a "this" las variables leidas casteadas en la funcion

                eIngrediente* this = ingrediente_setters(var_1, var_2, var_3, var_4, var_5, var_6, var_7);
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

int parser_FromText_Recetas(FILE* pFile, LinkedList* pArrayList)
{
    int flag = 0;
    char var_1[50], var_2[200], var_3[50], var_4[50], var_5[50], var_6[50], var_7[50], var_8[50];

    if (pFile != NULL && pArrayList != NULL)
    {
        //Hago una primera lectura "fantasma" para leer el titulo el cual no voy a almacenar
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", var_1, var_2, var_3, var_4, var_5, var_6, var_7, var_8);

        while(!feof(pFile))     //Mientras no se llege al final del archivo
        {
            int status = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", var_1, var_2, var_3, var_4, var_5, var_6, var_7, var_8);

            if(status == 8)     //Si status es igual a los 8 datos pedidos a leer
            {
                //Le asigno a "this" las variables leidas casteadas en la funcion

                eReceta* this = receta_setters(var_1, var_2, var_3, var_4, var_5, var_6, var_7, var_8);
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

