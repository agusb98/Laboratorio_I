#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Dominio.h"
#include "utn.h"

eDominio* dominio_new()
{
    eDominio* this = malloc(sizeof(eDominio)); //Creo un nuevo dato con memodia dinamica "malloc"
    if(this == NULL)
    {
        printf("Almacenamiento lleno.\n");
        exit(EXIT_FAILURE); //De ser NULL salgo
    }
    else //De lo contrario parseo a 0 y cadena vacia las variables
    {
        this->id = 0;
        strcpy(this->dominio, "");
        this->anio = 0;
        this->tipo = ' ';
    }
    return this; //Retorno el puntero a la estructura creada
}

eDominio* dominio_setters(char* idStr,char* dominioStr,char* anioStr, char* tipoStr)
{
    eDominio* this =dominio_new();
    int flag = 0;

    if(dominio_setId(this,atoi(idStr)))
        flag=1;

    if(dominio_setDominio(this,dominioStr) && flag)
        flag=1;

    if(dominio_setAnio(this,atoi(anioStr)) && flag)
        flag=1;

    if(dominio_setTipo(this,*tipoStr) && flag)
        flag=1;

    if(!flag)
    {
        printf("\nError al cargar datos, revise la lista.\n");
        free(this);
    }

    return this;
}

int dominio_getters(eDominio* this, int* id, char* dominio, int* anio, char* tipo)
{
    int flag = 0;
    if (this != NULL)
    {
        if (dominio_getId(this, id))
            flag = 1;
        if (dominio_getDominio(this, dominio) && flag)
            flag = 1;
        if (dominio_getAnio(this, anio) && flag)
            flag = 1;
        if (dominio_getTipo(this, tipo) && flag)
            flag = 1;
    }
    return flag;
}

int dominio_setId(eDominio* this,int id)
{
    int flag = 0;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        flag=1;
    }
    return flag;
}

int dominio_getId(eDominio* this,int* id)
{
    int flag = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        flag=1;
    }
    return flag;
}

int dominio_setDominio(eDominio* this,char* dominio)
{
    int flag=0;
    if(this != NULL)
    {
        strncpy(this->dominio, dominio, 50);
        flag=1;
    }
    return flag;
}

int dominio_getDominio(eDominio* this,char* dominio)
{
    int flag = 0;
    if (this != NULL)
    {
        strncpy(dominio, this->dominio, 50);
        flag = 1;
    }
    return flag;
}

int dominio_setAnio(eDominio* this,int anio)
{
    int flag=0;
    if(this != NULL && anio >= 0)
    {
        this->anio = anio;
        flag=1;
    }
    return flag;
}

int dominio_getAnio(eDominio* this,int* anio)
{
    int flag = 0;
    if(this != NULL && anio != NULL)
    {
        *anio = this->anio;
        flag=1;
    }
    return flag;
}


int dominio_setTipo(eDominio* this,char tipo)
{
    int flag=0;
    if(this != NULL)
    {
        this->tipo = tipo;
        flag=1;
    }
    return flag;
}

int dominio_getTipo(eDominio* this,char* tipo)
{
    int flag = 0;
    if(this != NULL && tipo != NULL)
    {
        *tipo = this->tipo;
        flag=1;
    }
    return flag;
}

int dominio_show(eDominio* this)
{
    int id, flag = 0, anio;
    char dominio[50], tipo;

    if (dominio_getters(this, &id, dominio, &anio, &tipo))
    {
        printf(" %3d | %2s | %4d | %c\n", id, dominio, anio, tipo);
        flag = 1;
    }
    return flag;
}

/** \brief sort dominio in list by their id
 *
 * \param void* dominioA
 * \param void* dominioB
 * \return int (1) if OK - (0) If NULL pointer
 *
 */

int dominio_sortById(void* dominioA, void* dominioB)
{
    int flag = 0;

    if(dominioA != NULL && dominioB != NULL)
    {
        eDominio* auxA = (eDominio*) dominioA; //Casteo la estructura dominioA puntero
        eDominio* auxB = (eDominio*) dominioB; //Casteo la estructura dominioA puntero

        if((auxA->id) < (auxB->id)) //Si id de A en menor que id de B cambio al bandera flag a 1
            flag = 1 ;

        else if((auxA->id) == (auxB->id)) //Si id de A igual que id de B dejo la bandera igual
            flag = 0;

        else
            flag = -1;
    }
    return flag;
}

/** \brief sort in list by their dominio
 *
 * \param void* dominioA
 * \param void* dominioB
 * \return int (1) if OK - (0) If NULL pointer
 *
 */

int dominio_sortByPatente(void* dominioA, void* dominioB)
{
    int flag = 0;
    if(dominioA != NULL && dominioB != NULL)
    {
        eDominio* auxA = (eDominio*) dominioA; //Casteo la estructura dominioA puntero
        eDominio* auxB = (eDominio*) dominioB; //Casteo la estructura dominioA puntero
        flag = strcmp(auxA->dominio, auxB->dominio);
    }
    return flag;
}

/** \brief Asigna el salario del empleado dependiendo de las horas trabajadas
 *
 * \param void* auxDominio
 * \param float *salary
 * \return Retorna -1 si hay error y si no 0.
 *
 */

void dominio_mapTipo(void* this)
{
    char dominio[50];
    if (this != NULL)
    {
        dominio_getDominio(this, dominio);
        if (esMoto(dominio))
            dominio_setTipo(this, 'M');
        else
            dominio_setTipo(this, 'A');
    }
}

int dominio_filterMotos(void* this)
{
    eDominio* aux = (eDominio*)this;
    int retorno = 0;
    char tipo;
    dominio_getTipo(aux, &tipo);

    if (tipo == 'M')
        retorno = 1;
    return retorno;
}

int dominio_filterAutos(void* this)
{
    eDominio* aux = (eDominio*)this;
    int retorno = 0;
    char tipo;
    dominio_getTipo(aux, &tipo);

    if (tipo == 'A')
        retorno = 1;
    return retorno;
}
