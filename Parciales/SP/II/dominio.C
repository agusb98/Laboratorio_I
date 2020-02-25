#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Dominio.h"
#include "utn.h"

Dominio* dominio_new()
{
    Dominio* this = malloc(sizeof(Dominio)); //Creo un nuevo empleado con memodia dinamica "malloc"
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
        this->tipo = '-';
    }
    return this; //Retorno el puntero a la estructura creada
}

Dominio* dominio_setters(char* idStr,char* dominioStr,char* anioStr, char* tipoStr)
{
    Dominio* this = dominio_new();
    int flag = 0;

    if(dominio_setAnio(this,atoi(anioStr)))
        flag=1;

    if(dominio_setId(this,atoi(idStr)) && flag)
        flag=1;

    if(dominio_setDominio(this,dominioStr) && flag)
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

int dominio_getters(Dominio* this, int* id, char* dominio, int* anio, char* tipo)
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

int dominio_setId(Dominio* this,int id)
{
    int flag = 0;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        flag=1;
    }
    return flag;
}

int dominio_getId(Dominio* this,int* id)
{
    int flag = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        flag=1;
    }
    return flag;
}

int dominio_setDominio(Dominio* this,char* dominio)
{
    int flag=0;
    if(this != NULL)
    {
        strncpy(this->dominio, dominio, 50);
        flag=1;
    }
    return flag;
}

int dominio_getDominio(Dominio* this,char* dominio)
{
    int flag = 0;
    if (this != NULL)
    {
        strncpy(dominio, this->dominio, 50);
        flag = 1;
    }
    return flag;
}

int dominio_setAnio(Dominio* this,int anio)
{
    int flag=0;
    if(this != NULL && anio > 1940 && anio < 2020)
    {
        this->anio = anio;
        flag=1;
    }
    return flag;
}

int dominio_getAnio(Dominio* this,int* anio)
{
    int flag = 0;
    if(this != NULL && anio != NULL)
    {
        *anio = this->anio;
        flag=1;
    }
    return flag;
}


int dominio_setTipo(Dominio* this,char tipo)
{
    int flag=0;
    if(this != NULL)
    {
        this->tipo = tipo;
        flag=1;
    }
    return flag;
}

int dominio_getTipo(Dominio* this,char* tipo)
{
    int flag = 0;
    if (this != NULL && tipo != NULL)
    {
        *tipo = this->tipo;
        flag = 1;
    }
    return flag;
}

/*
int employee_getIndexInList(LinkedList* pArray)
{
    char id[128];
    int flag= -1;
    if(pArray != NULL)
    {
        controller_List(pArray);
        int valid = getStringNumeros("ID: ", id);
        int index = employee_findById(pArray, id);

        if (valid == 1 && index != -1)
            flag = index;
    }
    return flag;
}
*/

int dominio_show(Dominio* this)
{
    int auxId, auxAnio, flag = 0;
    char auxTipo, auxDominio[50];

    if (dominio_getters(this, &auxId, auxDominio, &auxAnio, &auxTipo))
    {
        printf(" %3d | %2s | %2d | %c \n", auxId, auxDominio, auxAnio, auxTipo);
        flag = 1;
    }
    return flag;
}
/*
int employee_findById(LinkedList* pArray, char* idStr)
{
    Dominio* this; //Puntero a estructura
    int flag = -1;
    int id = atoi(idStr); //Variable ID casteada a entero

    if(pArray != NULL)
    {
        for(int i=0; i<ll_len(pArray); i++) //Recorro el array en busca del ID ingresado
        {
            this = (Dominio*)ll_get(pArray, i);     //Le asigno a this la estructura que retorna ll_get()
            if(this->id == id)   //Si se encuentra el id ingresado se cambia la bandera y se rompe l iteraccion
            {
                flag = i;
                break;
            }
        }
    }
    return flag;
}
*/
/** \brief sort employees in list by their id
 *
 * \param void* employeeA
 * \param void* employeeB
 * \return int (1) if OK - (0) If NULL pointer
 *
 */

int employee_SortById(void* employeeA, void* employeeB)
{
    int flag = 0;
    Dominio* empA; //Puntero a la estructura empA
    Dominio* empB; //Puntero a la estructura empB

    if(employeeA != NULL && employeeB != NULL)
    {
        empA = (Dominio*) employeeA; //Casteo la estructura employeeA puntero
        empB = (Dominio*) employeeB; //Casteo la estructura employeeA puntero

        if((empA->id) < (empB->id)) //Si id de A en menor que id de B cambio al bandera flag a 1
            flag = 1 ;

        else if((empA->id) == (empB->id)) //Si id de A igual que id de B dejo la bandera igual
            flag = 0;

        else
            flag = -1;
    }
    return flag;
}

/** \brief sort employees in list by their name
 *
 * \param void* dominioA
 * \param void* dominioB
 * \return int (1) if OK - (0) If NULL pointer
 *
 */

int dominio_SortByDominio(void* dominioA, void* dominioB)
{
    int flag = 0;
    Dominio* empA; //Puntero a la estructura empA
    Dominio* empB; //Puntero a la estructura empB

    if(dominioA != NULL && dominioB != NULL)
    {
        empA = (Dominio*) dominioA; //Casteo la estructura dominioA puntero
        empB = (Dominio*) dominioB; //Casteo la estructura dominioA puntero
        flag = strcmp(empA->dominio, empB->dominio);
    }
    return flag;
}

/** \brief sort employees in list by their hours in work
 *
 * \param void* employeeA
 * \param void* employeeB
 * \return int (1) if OK - (0) If NULL pointer
 *
 */
/*
int employee_SortByHoursWorked(void* employeeA, void* employeeB)
{
    int flag = 0;
    Dominio* empA; //Puntero a la estructura empA
    Dominio* empB; //Puntero a la estructura empB

    if(employeeA != NULL && employeeB != NULL)
    {
        empA = (Dominio*) employeeA; //Casteo la estructura employeeA puntero
        empB = (Dominio*) employeeB; //Casteo la estructura employeeA puntero

        if((empA->hoursWorked) < (empB->hoursWorked)) //Si hoursWorked de A en menor que hoursWorked de B cambio al bandera flag a 1
            flag = 1 ;

        else if((empA->hoursWorked) == (empB->hoursWorked)) //Si hoursWorked de A igual que hoursWorked de B dejo la bandera igual
            flag = 0;

        else
            flag = -1;
    }
    return flag;
}

 * \brief sort employees in list by their salary
 *
 * \param void* employeeA
 * \param void* employeeB
 * \return int (1) if OK - (0) If NULL pointer
 *
 */
/*
int employee_SortBySalary(void* employeeA, void* employeeB)
{
    int flag = 0;
    Dominio* empA; //Puntero a la estructura empA
    Dominio* empB; //Puntero a la estructura empB

    if(employeeA != NULL && employeeB != NULL)
    {
        empA = (Dominio*) employeeA; //Casteo la estructura employeeA puntero
        empB = (Dominio*) employeeB; //Casteo la estructura employeeA puntero

        if((empA->salary) < (empB->salary)) //Si salary de A en menor que salary de B cambio al bandera flag a 1
            flag = 1;

        else if((empA->salary) == (empB->salary)) //Si salary de A igual que salary de B dejo la bandera igual
            flag = 0;

        else
            flag = -1;
    }
    return flag;
}
*/

int dominio_filterByAnio(void* auxDominio, char* anio)
{
    int retorno = 0, auxAnio;
    Dominio* aux = (Dominio*) auxDominio;
    dominio_getAnio(aux, &auxAnio);

    if(auxAnio >= atoi(anio))
        retorno = 1;
    return retorno;
}

int dominio_filterById(void* auxDominio, char* id)
{
    int retorno = 0, auxId;
    Dominio* aux = (Dominio*) auxDominio;
    dominio_getId(aux, &auxId);

    if(auxId >= atoi(id))
        retorno = 1;
    return retorno;
}

int dominio_filterByTipo(void* auxDominio, char* tipo)
{
    Dominio* aux = (Dominio*)auxDominio;
    char auxTipo;
    dominio_getTipo(aux, &auxTipo);
    int retorno = 0;

    if (auxTipo == *tipo)
        retorno = 1;
    return retorno;
}

/** \brief Asigna el salario del empleado dependiendo de las horas trabajadas
 *
 * \param void* auxDominio
 * \param float *salary
 * \return Retorna -1 si hay error y si no 0.
 *
 */

int dominio_mapTipo(void* auxDominio, char *tipo)
{
    int flag = 0;
    char dominio[128];
    dominio_getDominio(auxDominio, dominio);

    if(esMoto(dominio) == 1)
        *tipo = 'M';
    else if(esMoto(dominio) == 0)
        *tipo = 'A';
    else
        flag = -1;

    return flag;
}

int dominio_filterCars(void* auxDominio)
{
    Dominio* aux = (Dominio*)auxDominio;
    char auxTipo;
    dominio_getTipo(aux, &auxTipo);
    int retorno = 0;

    if (auxTipo == 'A')
        retorno = 1;
    return retorno;
}

int dominio_filterMotos(void* auxDominio)
{
    Dominio* aux = (Dominio*)auxDominio;
    char auxTipo;
    dominio_getTipo(aux, &auxTipo);
    int retorno = 0;

    if (auxTipo == 'M')
        retorno = 1;
    return retorno;
}
