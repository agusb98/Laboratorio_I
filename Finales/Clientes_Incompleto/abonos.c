#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "abonos.h"
#include "clientes.h"
#include "utn.h"

eAbono* abono_new()
{
    eAbono* this = malloc(sizeof(eAbono)); //Creo una nueva identidad con memodia dinamica "malloc"
    if(this == NULL)
    {
        printf("Almacenamiento lleno.\n");
        exit(EXIT_FAILURE); //De ser NULL salgo
    }
    else //De lo contrario parseo a 0 y cadena vacia las variables
    {
        this->id = 0;
        this->tipo = 0;
        this->idCliente = 0;
        this->importeFinal = 0;
    }
    return this; //Retorno el puntero a la estructura creada
}

eAbono* abono_setters(char* var_1, char* var_2, char* var_3, char* var_4)
{
    eAbono* this = abono_new();
    if (this != NULL)
    {
        if (!abono_setId(this,atoi(var_1)))
            this = NULL;

        if( !abono_setTipo(this,atoi(var_2)))
            this = NULL;

        if( !abono_setIdCliente(this,atoi(var_3)))
            this = NULL;

        if (!abono_setImporteFinal(this,atof(var_4)))
            this = NULL;

        if(this == NULL)
        {
            printf("\nError al cargar datos, revise la lista.\n");
            free(this);
        }
    }
    return this;
}

int abono_setId(eAbono* this,int id)
{
    int flag = 0;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        flag=1;
    }
    return flag;
}

int abono_getId(eAbono* this,int* id)
{
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        return 1;
    }
    return 0;
}

int abono_setTipo(eAbono* this,int tipo)
{
    int flag = 0;
    if(this != NULL && tipo >= 0)
    {
        this->tipo = tipo;
        flag=1;
    }
    return flag;
}

int abono_getTipo(eAbono* this,char* tipo)
{
    if(this != NULL && tipo != NULL)
    {
        if (this->tipo == 1)
            strncpy(tipo, "PERSONAL", 50);
        else if (this->tipo > 1 && this->tipo < 5)
            strncpy(tipo, "FAMILIAR", 50);
        else
            strncpy(tipo, "CORPORATIVO", 50);
        return 1;
    }
    return 0;
}

int abono_setIdCliente(eAbono* this,int idCliente)
{
    int flag = 0;
    if(this != NULL && idCliente >= 0)
    {
        this->idCliente = idCliente;
        flag=1;
    }
    return flag;
}

int abono_getIdCliente(eAbono* this,int* idCliente)
{
    if(this != NULL && idCliente != NULL)
    {
        *idCliente = this->idCliente;
        return 1;
    }
    return 0;
}

int abono_setImporteFinal(eAbono* this,float importeFinal)
{
    int flag=0;
    if(this != NULL && importeFinal >= 0)
    {
        this->importeFinal = importeFinal;
        flag=1;
    }
    return flag;
}

int abono_getImporteFinal(eAbono* this,float* importeFinal)
{
    if (this != NULL && importeFinal != NULL)
    {
        *importeFinal = this->importeFinal;
        return 1;
    }
    return 0;
}

int abono_show(eAbono* this, LinkedList* client)
{
    int id_1, id_2, var_6;
    float var_4, var_5;
    char var_2[50], var_3[50], var_7[50];

    if (this != NULL && client != NULL)
    {
        abono_getIdCliente(this, &id_1);
        for (int i=0; i<ll_len(client); i++)
        {
            eCliente* aux = ll_get(client, i);
            cliente_getId(aux, &id_2);
            if (id_1 == id_2)
            {
                cliente_getNombre(aux, var_2);
                cliente_getSexo(aux, var_3);
                cliente_getNumeroTelefonico(aux, &var_4);
                abono_getImporteFinal(this, &var_5);
                abono_getId(this, &var_6);
                abono_getTipo(this, var_7);

                printf(" %3d | %8s | %3s | %.0f | %.1f | %3d | %8s \n", id_1, var_2, var_3, var_4, var_5, var_6, var_7);
            }
        }
        return 1;
    }
    return 0;
}

/** \brief sort envios in list by their id
 *
 * \param void* punteroA
 * \param void* punteroB
 * \return int (-1) si punteroA menor a punteroB
               (0) si punteroA igual a punteroB
               (1) si punteroA manor a punteroB
               (-2) If NULL pointer
 *
 */

int abono_sortByImport(void* punteroA, void* punteroB)
{
    if(punteroA != NULL && punteroB != NULL)
    {
        float id_A, id_B;

        abono_getImporteFinal(punteroA, &id_A);
        abono_getImporteFinal(punteroB, &id_B);

        if((id_A) > (id_B)) //Si id de A en menor que id de B cambio al bandera flag a 1
            return 1;
        else if((id_A) == (id_B)) //Si id de A igual que id de B dejo la bandera igual
            return 0;
        else
            return -1;
    }
    return -2;
}

/** \brief sort envios in list by their id
 *
 * \param void* punteroA
 * \param void* punteroB
 * \return int (-1) si punteroA menor a punteroB
               (0) si punteroA igual a punteroB
               (1) si punteroA manor a punteroB
               (-2) If NULL pointer
 *
 */

int abono_sortByID(void* punteroA, void* punteroB)
{
    if(punteroA != NULL && punteroB != NULL)
    {
        int id_A, id_B;

        abono_getId(punteroA, &id_A);
        abono_getId(punteroB, &id_B);

        if((id_A) > (id_B)) //Si id de A en menor que id de B cambio al bandera flag a 1
            return 1;
        else if((id_A) == (id_B)) //Si id de A igual que id de B dejo la bandera igual
            return 0;
        else
            return -1;
    }
    return -2;
}

