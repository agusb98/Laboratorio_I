#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "empleados.h"
#include "utn.h"

eEmpleado* _new()
{
    eEmpleado* this = malloc(sizeof(eEmpleado)); //Creo un nuevo empleados con memodia dinamica "malloc"
    if(this == NULL)
    {
        printf("Almacenamiento lleno.\n");
        exit(EXIT_FAILURE); //De ser NULL salgo
    }
    else //De lo contrario parseo a 0 y cadena vacia las variables
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }
    return this; //Retorno el puntero a la estructura creada
}

eEmpleado* _setters(char* var_1, char* var_2, char* var_3, char* var_4)
{
    eEmpleado* this = _new();
    if (this != NULL)
    {
        if (!_setId(this,atoi(var_1)))
            this = NULL;

        if( !_setNombre(this,var_2))
            this = NULL;

        if( !_setHorasTrabajadas(this,atoi(var_3)) )
            this = NULL;

        if(!_setSueldo(this,atof(var_4)))
            this = NULL;

        if(this == NULL)
        {
            printf("\nError al cargar datos, revise la lista.\n");
            free(this);
        }
    }
    return this;
}

int _getters(eEmpleado* this, int* var_1, char* var_2, int* var_3, float* var_4)
{
    if (this != NULL)
    {
        if (!_getId(this, var_1))
            return 0;
        if (!_getNombre(this, var_2))
            return 0;
        if (!_getHorasTrabajadas(this, var_3))
            return 0;
        if (!_getSueldo(this, var_4))
            return 0;
        return 1;
    }
    return 0;
}

int _setId(eEmpleado* this,int id)
{
    int flag = 0;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        flag=1;
    }
    return flag;
}

int _getId(eEmpleado* this,int* id)
{
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        return 1;
    }
    return 0;
}

int _setNombre(eEmpleado* this,char* nombre)
{
    if(this != NULL)
    {
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        return 1;
    }
    return 0;
}

int _getNombre(eEmpleado* this,char* nombre)
{
    if (this != NULL)
    {
        strncpy(nombre, this->nombre, sizeof(this->nombre));
        return 1;
    }
    return 0;
}

int _setHorasTrabajadas(eEmpleado* this,int horasTrabajadas)
{
    int flag=0;
    if(this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        flag=1;
    }
    return flag;
}

int _getHorasTrabajadas(eEmpleado* this,int* horasTrabajadas)
{
    if (this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        return 1;
    }
    return 0;
}

int _setSueldo(eEmpleado* this,float sueldo)
{
    int flag=0;
    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        flag=1;
    }
    return flag;
}

int _getSueldo(eEmpleado* this,float* sueldo)
{
    if (this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        return 1;
    }
    return 0;
}

int _show(eEmpleado* this)
{
    int var_1, var_3;
    float var_4;
    char var_2[sizeof(this->nombre)];

    if (this != NULL && _getters(this, &var_1, var_2, &var_3, &var_4))
    {
        printf(" %3d | %8s | %5d | %.1f \n", var_1, var_2, var_3, var_4);
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

        if((id_A) < (id_B)) //Si id de A en menor que id de B cambio al bandera flag a 1
            return 1;
        else if((id_A) == (id_B)) //Si id de A igual que id de B dejo la bandera igual
            return 0;
        else
            return -1;
    }
    return -2;
}

int _mapSueldo (void* this)
{
    int aux;
    if (this != NULL)
    {
        _getHorasTrabajadas(this, &aux);
        if (aux <= 176)
            _setSueldo(this, 180 * aux);
        else if (aux >= 177 && aux <= 208)
            _setSueldo(this, 270 * aux);
        else if (aux >= 209 && aux <= 240)
            _setSueldo(this, 360 * aux);

        return 1;
    }
    return 0;
}








