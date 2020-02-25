#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "servis.h"

/** \brief find a Servis by Id en returns the index position in array.
 *
 * \param eServis servis[]
 * \param len int
 * \param id int
 * \return Return servis index position or (-1) if [servis not found]
 *
 */

int findServisById(eServis servis[], int len,int id)
{
    int flag= -1;
    for (int i=0; i<len; i++)
    {
        if (servis[i].id == id)
        {
            flag = i;
            break;
        }
    }
    return flag;
}


/** \brief print the content of clients array
 *
 * \param eServis servis[]
 * \param len int
 * \return int
 *
 */

int printServises(eServis servis[], int len)
{
    printf(">> Servicios\n\n");
    printf("ID    |DESCRIPTION| PRECIO \n\n");

    for (int i=0; i<len; i++)
            printServis(servis[i]);

    printf("\n\n");
    return 0;
}

/** \brief print the content of a servis
 *
 * \param eServis x
 * \return void
 *
 */

void printServis(eServis x)
{
    printf("%2d | %9s | $%.1f \n", x.id, x.description, x.price);
}

/** \brief search a determinate servis by id in the list of clients
 *
 * \param eServis servis[]
 * \param lent int
 * \return Return servis index position or (-1) if [servis not found]
 *
 */

int servis_getIdInList(eServis servis[], int len)
{
    int id, valid, flag= -1;

    printServises(servis, len);
    valid = getValidInt("ID: ","Fuera de Rango\n", &id, 20000, len+20000, 3);

    if (!valid && findServisById(servis, len, id) != -1)
        flag= id;

    return flag;
}

/** \brief create services to see if program run OK
 *
 * \param eServis y[]
 * \return void
 *
 */

void servis_hardcore(eServis y[])
{
    eServis x[]={
   {20000, "Lavado", 250},
   {20001, "Pulido", 300},
   {20002, "Encerado", 400},
   {20003, "Completo", 600},
   {20004, "Teflonado", 800}
   };

    for(int i=0; i<5; i++)
    {
        y[i] = x[i];
    }
}

int servis_getEncerado(eServis servis[], int len)
{
    int flag= -1;
    for (int i=0; i<len; i++)
    {
        if (servis[i].id == 20002)
        {
            flag = 20002;
            break;
        }
    }
    return flag;
}
