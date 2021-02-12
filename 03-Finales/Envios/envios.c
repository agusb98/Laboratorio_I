#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "envios.h"
#include "utn.h"

eEnvio* _new()
{
    eEnvio* this = malloc(sizeof(eEnvio)); //Creo un nuevo empleados con memodia dinamica "malloc"
    if(this == NULL)
    {
        printf("Almacenamiento lleno.\n");
        exit(EXIT_FAILURE); //De ser NULL salgo
    }
    else //De lo contrario parseo a 0 y cadena vacia las variables
    {
        this->var_1 = 0;
        strcpy(this->var_2, "");
        this->var_3 = 0;
        this->var_4 = 0;
        this->var_5 = 0;
    }
    return this; //Retorno el puntero a la estructura creada
}

eEnvio* _setters(char* var_1, char* var_2, char* var_3, char* var_4, char* var_5)
{
    eEnvio* this = _new();
    if (this != NULL)
    {
        if (!_setId(this,atoi(var_1)))
            this = NULL;

        if( !_setNombre(this,var_2))
            this = NULL;

        if( !_setKilometros(this,atof(var_3)))
            this = NULL;

        if( !_setTipo(this,atoi(var_4)))
            this = NULL;

        if( !_setPrecio(this,atof(var_5)))
            this = NULL;

        if(this == NULL)
        {
            printf("\nError al cargar datos, revise la lista.\n");
            free(this);
        }
    }
    return this;
}

int _getters(eEnvio* this, int* var_1, char* var_2, float* var_3, char* var_4, float* var_5)
{
    if (this != NULL)
    {
        if (!_getId(this, var_1))
            return 0;

        if (!_getNombre(this, var_2))
            return 0;

        if (!_getKilometros(this, var_3))
            return 0;

        if (!_getTipo(this, var_4))
            return 0;

        if (!_getPrecio(this, var_5))
            return 0;
        else
            return 1;
    }
    return 0;
}

int _setId(eEnvio* this,int var_1)
{
    int flag = 0;
    if(this != NULL && var_1 >= 0)
    {
        this->var_1 = var_1;
        flag=1;
    }
    return flag;
}

int _getId(eEnvio* this,int* var_1)
{
    if(this != NULL && var_1 != NULL)
    {
        *var_1 = this->var_1;
        return 1;
    }
    return 0;
}

int _setNombre(eEnvio* this,char* var_2)
{
    if(this != NULL)
    {
        strncpy(this->var_2, var_2, sizeof(this->var_2));
        return 1;
    }
    return 0;
}

int _getNombre(eEnvio* this,char* var_2)
{
    if (this != NULL)
    {
        strncpy(var_2, this->var_2, sizeof(this->var_2));
        return 1;
    }
    return 0;
}

int _setKilometros(eEnvio* this,float var_3)
{
    if(this != NULL && var_3 > 0)
    {
        this->var_3 = var_3;
        return 1;
    }
    return 0;
}

int _getKilometros(eEnvio* this,float* var_3)
{
    int flag = 0;
    if(this != NULL && var_3 != NULL)
    {
        *var_3 = this->var_3;
        flag=1;
    }
    return flag;
}

int _setPrecio(eEnvio* this,float var_5)
{
    if(this != NULL)
    {
        if (var_5 < 0)
            var_5 = 0;

        this->var_5 = var_5;
        return 1;
    }
    return 0;
}

int _getPrecio(eEnvio* this,float* var_5)
{
    int flag = 0;
    if(this != NULL && var_5 != NULL)
    {
        *var_5 = this->var_5;
        flag=1;
    }
    return flag;
}

int _setTipo(eEnvio* this,int var_4)
{
    if(this != NULL && var_4 > 0)
    {
        this->var_4 = var_4;
        return 1;
    }
    return 0;
}

int _getTipo(eEnvio* this,char* var_4)
{
    if (this != NULL)
    {
        switch(this->var_4)
        {
        case 1:
            strcpy(var_4, "Normal");
            break;
        case 2:
            strcpy(var_4, "Express");
            break;
        case 3:
            strcpy(var_4, "Segun Disponibilidad");
            break;
        }
        return 1;
    }
    return 0;
}

int _show(eEnvio* this)
{
    int var_1;
    char var_2[sizeof(this->var_2)], var_4[50];
    float var_3, var_5;

    if (this != NULL && _getters(this, &var_1, var_2, &var_3, var_4, &var_5))
    {
        printf(" %3d | %8s | %.1f | %8s | %.1f \n", var_1, var_2, var_3, var_4, var_5);
        return 1;
    }
    return 0;
}

/** \brief sort envios in list by their var_1
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

        if((id_A) < (id_B)) //Si var_1 de A en menor que var_1 de B cambio al bandera flag a 1
            return 1;
        else if((id_A) == (id_B)) //Si var_1 de A igual que var_1 de B dejo la bandera igual
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
        eEnvio* pA = (eEnvio*) punteroA;
        eEnvio* pB = (eEnvio*) punteroB;

        char aux_A[sizeof(pA->var_2)];
        char aux_B[sizeof(pB->var_2)];

        _getNombre(pA, aux_A);
        _getNombre(pB, aux_B);
        flag = strcmp(aux_A, aux_B);
    }
    return flag;
}

int _mapPrecio (void* this)
{
    float var_3;
    float var_5;
    if (this != NULL)
    {
        eEnvio* pA = (eEnvio*) this;
        _getPrecio(pA, &var_5);
        _getKilometros(pA, &var_3);
        if (var_5 < 50)
            _setPrecio(pA, var_3 * 67);
        else
            _setPrecio(pA, var_3 * 80);

        _getPrecio(pA, &var_5);
        switch (pA->var_4)
        {
        case 1:
            _setPrecio(pA, var_5 + 330);
            break;
        case 2:
            _setPrecio(pA, var_5 + 560);
            break;
        case 3:
            _setPrecio(pA, var_5 + 80);
            break;
        }
        return 1;
    }
    return 0;
}










