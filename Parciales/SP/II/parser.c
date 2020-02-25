#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Dominio.h"

/** \brief Parsea los datos los datos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int parser_FromText(FILE* pFile, LinkedList* pArrayList)
{
    Dominio* this;
    int flag = 0;
    int status; //Contador de lectura
    char auxId[50], auxDominio[50], auxAnio[50], auxTipo[50];

    //Hago una primera lectura "fantasma" para leer el titulo el cual no voy a almacenar
    fscanf(pFile, "%[^,],%[^,],%[^\n]\n", auxId, auxDominio, auxAnio);

    while(!feof(pFile))     //Mientras no se llege al final del archivo
    {
        status = fscanf(pFile, "%[^,],%[^,],%[^\n]\n", auxId, auxDominio, auxAnio);

        if(status == 3)     //Si status es igual a los 3 datos pedidos a leer
        {
            //Le asigno a "this" las variables leidas casteadas en la funcion

            this = dominio_setters(auxId, auxDominio, auxAnio, auxTipo);
            ll_add(pArrayList, this);    //Agrego "this" al final del array de empleados
            flag= 1;
        }
    }
    fclose(pFile); //Cierro el archivo
    return flag;
}

/** \brief Parsea los datos los datos desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int parser_FromBinary(FILE* pFile, LinkedList* pArrayList)
{
    Dominio* this; //Creo un nuevo empleado
    int status; //Contador de lectura
    int flag = 0;

    while(!feof(pFile))
    {
        this = dominio_new();
        status = fread(this, sizeof(Dominio), 1, pFile);

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
