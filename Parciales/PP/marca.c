#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cars.h"
#include "utn.h"
#include "marca.h"

/** \brief find a Marca by Id en returns the index position in array.
 *
 * \param eMarca marca[]
 * \param len int
 * \param id int
 * \return Return marca index position or (-1) if [marca not found]
 *
 */

int findMarcaById(eMarca marca[], int len,int id)
{
    int flag= -1;
    for (int i=0; i<len; i++)
    {
        if (marca[i].id == id)
        {
            flag = i;
            break;
        }
    }
    return flag;
}


/** \brief search a determinate marca by id in the list of marcas
 *
 * \param eMarca marca[]
 * \param lent int
 * \return Return marca index position or (-1) if [marca not found]
 *
 */

int marca_getIdInList(eMarca marca[], int len)
{
    int id, valid, flag= -1;

    printMarcas(marca, len);
    valid = getValidInt("ID: ","Fuera de Rango\n", &id, 1000, len+1000, 3);

    if (!valid && findMarcaById(marca, len, id) != -1)
        flag= id;

    return flag;
}

/** \brief print the content of marcas array
 *
 * \param eMarca marca[]
 * \param len int
 * \return void
 *
 */

void printMarcas(eMarca marca[], int len)
{
    printf(">> MARCAS\n\n");
    printf("ID   |  NOMBRE  \n\n");

    for (int i=0; i<len; i++)
            printMarca(marca[i]);
    printf("\n\n");
}

/** \brief print the content of a marca
 *
 * \param eMarca x
 * \return void
 *
 */

void printMarca(eMarca x)
{
    printf("%2d | %7s \n", x.id, x.description);
}

/** \brief search a determinate marca by id in the list of clients
 *
 * \param eMarca marca[]
 * \param lent int
 * \return void
 *
 */

int marca_getMarcaInList(eMarca marca[], int len)
{
    int id, valid, flag= -1;

    printMarcas(marca, len);
    valid = getValidInt("ID: ","Fuera de Rango\n", &id, 2000, len+2001, 3);

    if (!valid && findMarcaById(marca, len, id) != -1)
        flag= id;

    return flag;
}

/** \brief create marcas of cars to see if program run OK
 *
 * \param eMarca y[]
 * \return void
 *
 */

void marca_hardcore(eMarca y[])
{
    eMarca x[]={
   {1000, "Renault"},
   {1001, "Fiat"},
   {1002, "Ford"},
   {1003, "Chevrolet"},
   {1004, "Peugeot"}
   };
    for(int i=0; i<5; i++)
    {
        y[i] = x[i];
    }
}
