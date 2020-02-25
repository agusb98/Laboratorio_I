#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "dominios.h"
#include "utn.h"

eDominio* _new()
{
    eDominio* this = malloc(sizeof(eDominio)); //Creo un nuevo dominios con memodia dinamica "malloc"
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
        strcpy(this->tipo, "");
    }
    return this; //Retorno el puntero a la estructura creada
}

eDominio* _setters(char* var_1, char* var_2, char* var_3, char* var_4)
{
    eDominio* this = _new();
    if (this != NULL)
    {
        if (!_setId(this,atoi(var_1)))
            this = NULL;

        if( !_setDominio(this,var_2))
            this = NULL;

        if( !_setAnio(this,atoi(var_3)) )
            this = NULL;

        if(!_setTipo(this, var_4))
            this = NULL;

        if(this == NULL)
        {
            printf("\nError al cargar datos, revise la lista.\n");
            free(this);
        }
    }
    return this;
}

int _getters(eDominio* this, int* var_1, char* var_2, int* var_3, char* var_4)
{
    if (this != NULL)
    {
        if (!_getId(this, var_1))
            return 0;
        if (!_getDominio(this, var_2))
            return 0;
        if (!_getAnio(this, var_3))
            return 0;
        if (!_getTipo(this, var_4))
            return 0;
        return 1;
    }
    return 0;
}

int _setId(eDominio* this,int id)
{
    int flag = 0;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        flag=1;
    }
    return flag;
}

int _getId(eDominio* this,int* id)
{
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        return 1;
    }
    return 0;
}

int _setDominio(eDominio* this,char* dominio)
{
    if(this != NULL)
    {
        strncpy(this->dominio, dominio, sizeof(this->dominio));
        return 1;
    }
    return 0;
}

int _getDominio(eDominio* this,char* dominio)
{
    if (this != NULL)
    {
        strncpy(dominio, this->dominio, sizeof(this->dominio));
        return 1;
    }
    return 0;
}

int _setTipo(eDominio* this,char* tipo)
{
    if(this != NULL)
    {
        strncpy(this->tipo, tipo, sizeof(this->tipo));
        return 1;
    }
    return 0;
}

int _getTipo(eDominio* this,char* tipo)
{
    if (this != NULL)
    {
        strncpy(tipo, this->tipo, sizeof(this->tipo));
        return 1;
    }
    return 0;
}

int _setAnio(eDominio* this,int anio)
{
    int flag=0;
    if(this != NULL && anio >= 0)
    {
        this->anio = anio;
        flag=1;
    }
    return flag;
}

int _getAnio(eDominio* this,int* anio)
{
    if (this != NULL && anio != NULL)
    {
        *anio = this->anio;
        return 1;
    }
    return 0;
}

int _show(eDominio* this)
{
    int var_1, var_3;
    char var_2[50], var_4[50];

    if (this != NULL && _getters(this, &var_1, var_2, &var_3, var_4))
    {
        printf(" %3d | %8s | %5d | %8s \n", var_1, var_2, var_3, var_4);
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

int _sortById(void* punteroA, void* punteroB)
{

    if(punteroA != NULL && punteroB != NULL)
    {
        int id_A, id_B;

        _getId(punteroA, &id_A);
        _getId(punteroB, &id_B);

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
int _sortByNombre(void* punteroA, void* punteroB)
{
    int flag = 0;
    if(punteroA != NULL && punteroB != NULL)
    {
        char aux_A[50];
        char aux_B[50];

        _getDominio(punteroA, aux_A);
        _getDominio(punteroB, aux_B);
        flag = strcmp(aux_A, aux_B);
    }
    return flag;
}

int _mapTipo (void* this)
{
    char dominio[50];
    if (this != NULL)
    {
        _getDominio(this, dominio);
        if (esMoto(dominio))
            _setTipo(this, "M");
        else
            _setTipo(this, "A");

        return 1;
    }
    return 0;
}

int filter_1 (void* this)
{
    char dominio[50];
    if (this != NULL)
    {
        _getDominio(this, dominio);
        if (esMoto(dominio))
            return 1;
    }
    return 0;
}

int filter_2 (void* this)
{
    char dominio[50];
    if (this != NULL)
    {
        _getDominio(this, dominio);
        if (!esMoto(dominio))
            return 1;
    }
    return 0;
}








