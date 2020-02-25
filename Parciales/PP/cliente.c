#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"

/** \brief find a Client by Id en returns the index position in array.
 *
 * \param eClient client[]
 * \param len int
 * \param id int
 * \return Return client index position or (-1) if [client not found]
 *
 */

int findClientById(eClient client[], int len,int id)
{
    int flag= -1;
    for (int i=0; i<len; i++)
    {
        if (client[i].id == id)
        {
            flag = i;
            break;
        }
    }
    return flag;
}

/** \brief find a Client by ID car en returns the index position in array.
 *
 * \param eClient client[]
 * \param len int
 * \param id int
 * \return Return client index position or (-1) if [client not found]
 *
 */

int findClientByIdCar(eClient client[], int len,int id)
{
    int flag= -1;
    for (int i=0; i<len; i++)
    {
        if (client[i].id_auto == id)
        {
            flag = i;
            break;
        }
    }
    return flag;
}


/** \brief print the content of clients array
 *
 * \param eClient client[]
 * \param len int
 * \return int
 *
 */

int printClients(eClient client[], int len)
{
    printf(">> Clientes\n\n");
    printf("ID |     NOMBRE       | SEXO \n\n");

    for (int i=0; i<len; i++)
        printClient(client[i]);

    printf("\n\n");
    return 0;
}

/** \brief print the content of a client
 *
 * \param eClient x
 * \return void
 *
 */

void printClient(eClient x)
{
    printf("%2d | %16s | %2s \n", x.id, x.name, x.sex);
}

/** \brief search a determinate client by id in the list of clients
 *
 * \param eClient client[]
 * \param lent int
 * \return Return client index position or (-1) if [client not found]
 *
 */

int client_getIdInList(eClient client[], int len)
{
    int id, valid, flag= -1;

    printClients(client, len);
    valid = getValidInt("ID: ","Fuera de Rango\n", &id, 1, len+5, 3);

    if (!valid && findClientById(client, len, id) != -1)
        flag= id;

    return flag;
}

/** \brief create clients to see if program run OK
 *
 * \param eClient y[]
 * \return void
 *
 */

void client_hardcore(eClient y[])
{
    eClient x[]=
    {
        {1, 1, "Carlos Baute", "m"},
        {2, 2, "Monica Santa", "f"},
        {3, 3, "Roberto Inka", "m"},
        {4, 4, "Carla Fea", "f"},
        {5, 5, "Pablo Luna", "m"},
        {6, 6, "Pedro Albarez", "m"},
        {7, 7, "Gimena Baron", "f"},
        {8, 8, "Adrian Gomez", "m"},
        {9, 9, "Federica Jose", "f"},
        {10, 10, "Julian Yorin", "m"},
        {11, 11, "Leandro Baez", "m"},
        {12, 12, "Agustina Gimenez", "f"},
        {13, 13, "Agustin kopin", "m"},
        {14, 14, "Keyla Saenz", "f"},
        {15, 15, "Pablo Pekus", "m"},
        {16, 16, "Carlos Quintera", "m"},
        {17, 17, "Monica Diabla", "f"},
        {18, 18, "Pablo Bruno", "m"},
        {19, 19, "Raquel Fea", "f"},
        {20, 20, "Pedro Nunez", "m"},
        {21, 21, "Julieta Linda", "f"},
        {22, 22, "Jose Staffo", "m"},
    };

    for(int i=0; i<22; i++)
    {
        y[i] = x[i];
    }
}
