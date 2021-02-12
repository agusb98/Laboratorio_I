#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colour.h"
#include "servis.h"
#include "utn.h"


/** \brief find a Colour by Id en returns the index position in array.
 *
 * \param eColour colour[]
 * \param len int
 * \param id int
 * \return Return colour index position or (-1) if [colour not found]
 *
 */

int findColourById(eColour colour[], int len,int id)
{
    int flag= -1;
    for (int i=0; i<len; i++)
    {
        if (colour[i].id == id)
        {
            flag = i;
            break;
        }
    }
    return flag;
}

/** \brief print the content of colours array
 *
 * \param eColour colour[]
 * \param len int
 * \return void
 *
 */

void printColours(eColour colour[], int len)
{
    printf(">> Colores\n\n");
    printf("ID   | NOMBRE \n\n");

    for (int i=0; i<len; i++)
        printColour(colour[i]);

    printf("\n\n");
}

/** \brief print the content of a colour
 *
 * \param eColour x
 * \return void
 *
 */

void printColour(eColour x)
{
    printf("%2d | %6s \n", x.id, x.name);
}

/** \brief search a determinate colour by id in the list of colours
 *
 * \param eColour colour[]
 * \param lent int
 * \return Return colour index position or (-1) if [colour not found]
 *
 */

int colour_getIdInList(eColour colour[], int len)
{
    int id, valid, flag= -1;

    printColours(colour, len);
    valid = getValidInt("ID: ","Fuera de Rango\n", &id, 5000, len+5000, 3);

    if (!valid && findColourById(colour, len, id) != -1)
        flag= id;

    return flag;
}

/** \brief create colours to see if program run OK
 *
 * \param eColour y[]
 * \return void
 *
 */

void colour_hardcore(eColour y[])
{
    eColour x[]={
   {5000, "Negro"},
   {5001, "Blanco"},
   {5002, "Gris"},
   {5003, "Rojo"},
   {5004, "Azul"}
   };

    for(int i=0; i<5; i++)
    {
        y[i] = x[i];
    }
}


