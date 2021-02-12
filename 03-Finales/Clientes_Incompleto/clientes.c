#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "clientes.h"
#include "utn.h"

eCliente* cliente_new()
{
    eCliente* this = malloc(sizeof(eCliente)); //Creo una nueva identidad con memodia dinamica "malloc"
    if(this == NULL)
    {
        printf("Almacenamiento lleno.\n");
        exit(EXIT_FAILURE); //De ser NULL salgo
    }
    else //De lo contrario parseo a 0 y cadena vacia las variables
    {
        this->id = 0;
        strcpy(this->nombre, "");
        strcpy(this->sexo, "");
        this->numeroTelefonico = 0;
        this->importe = 0;
    }
    return this; //Retorno el puntero a la estructura creada
}

eCliente* cliente_setters(char* var_1, char* var_2, char* var_3, char* var_4, char* var_5)
{
    eCliente* this = cliente_new();
    if (this != NULL)
    {
        if (!cliente_setId(this,atoi(var_1)))
            this = NULL;

        if( !cliente_setNombre(this,var_2))
            this = NULL;

        if( !cliente_setSexo(this,var_3))
            this = NULL;

        if (!cliente_setNumeroTelefonico(this,atof(var_4)))
            this = NULL;

        if (!cliente_setImporte(this,atof(var_5)))
            this = NULL;

        if(this == NULL)
        {
            printf("\nError al cargar datos, revise la lista.\n");
            free(this);
        }
    }
    return this;
}

int cliente_getters(eCliente* this, int* var_1, char* var_2, char* var_3, float* var_4, float* var_5)
{
    if (this != NULL)
    {
        if (!cliente_getId(this, var_1))
            return 0;
        if (!cliente_getNombre(this, var_2))
            return 0;
        if (!cliente_getSexo(this, var_3))
            return 0;
        if (!cliente_getNumeroTelefonico(this, var_4))
            return 0;
        if (!cliente_getImporte(this, var_5))
            return 0;
        return 1;
    }
    return 0;
}

int cliente_setId(eCliente* this,int id)
{
    int flag = 0;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        flag=1;
    }
    return flag;
}

int cliente_getId(eCliente* this,int* id)
{
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        return 1;
    }
    return 0;
}

int cliente_setNombre(eCliente* this,char* nombre)
{
    if(this != NULL)
    {
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        return 1;
    }
    return 0;
}

int cliente_getNombre(eCliente* this,char* nombre)
{
    if (this != NULL)
    {
        strncpy(nombre, this->nombre, sizeof(this->nombre));
        return 1;
    }
    return 0;
}

int cliente_setSexo(eCliente* this,char* sexo)
{
    if(this != NULL)
    {
        strncpy(this->sexo, sexo, sizeof(this->sexo));
        return 1;
    }
    return 0;
}

int cliente_getSexo(eCliente* this,char* sexo)
{
    if (this != NULL)
    {
        strncpy(sexo, this->sexo, sizeof(this->sexo));
        return 1;
    }
    return 0;
}

int cliente_setNumeroTelefonico(eCliente* this,float numeroTelefonico)
{
    int flag=0;
    if(this != NULL && numeroTelefonico >= 0)
    {
        this->numeroTelefonico = numeroTelefonico;
        flag=1;
    }
    return flag;
}

int cliente_getNumeroTelefonico(eCliente* this,float* numeroTelefonico)
{
    if (this != NULL && numeroTelefonico != NULL)
    {
        *numeroTelefonico = this->numeroTelefonico;
        return 1;
    }
    return 0;
}

int cliente_setImporte(eCliente* this,float importe)
{
    int flag=0;
    if(this != NULL && importe >= 0)
    {
        this->importe = importe;
        flag=1;
    }
    return flag;
}

int cliente_getImporte(eCliente* this,float* importe)
{
    if (this != NULL && importe != NULL)
    {
        *importe = this->importe;
        return 1;
    }
    return 0;
}

int cliente_show(eCliente* this)
{
    int var_1;
    char var_2[50], var_3[50];
    float var_4, var_5;

    if (this != NULL && cliente_getters(this, &var_1, var_2, var_3, &var_4, &var_5))
    {
        printf(" %3d | %8s | %2s | %.0f | %.1f \n", var_1, var_2, var_3, var_4, var_5);
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

int cliente_sortById(void* punteroA, void* punteroB)
{

    if(punteroA != NULL && punteroB != NULL)
    {
        int id_A, id_B;

        cliente_getId(punteroA, &id_A);
        cliente_getId(punteroB, &id_B);

        if((id_A) > (id_B)) //Si id de A en menor que id de B cambio al bandera flag a 1
            return 1;
        else if((id_A) == (id_B)) //Si id de A igual que id de B dejo la bandera igual
            return 0;
        else
            return -1;
    }
    return -2;
}

/** \brief sort in list by their name
 *
 * \param void* punteroA
 * \param void* punteroB
 * \return int (1) if OK - (0) If NULL pointer
 *
 */
int cliente_sortByNombre(void* punteroA, void* punteroB)
{
    int flag = 0;
    if(punteroA != NULL && punteroB != NULL)
    {
        char aux_A[50];
        char aux_B[50];

        cliente_getNombre(punteroA, aux_A);
        cliente_getNombre(punteroB, aux_B);
        flag = strcmp(aux_A, aux_B);
    }
    return flag;
}

int cliente_freeID (LinkedList* this)
{
    if (this != NULL)
    {
        int max = 0, id;
        for (int i=0; i<ll_len(this); i++)
        {
            eCliente* list = ll_get(this, i);
            cliente_getId(list, &id);

            if (id >= max)
                max = id;
        }
        return (max + 1);
    }
    return 0;
}

