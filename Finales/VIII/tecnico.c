#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "tecnico.h"
#include "utn.h"

eLlamada* _new()
{
    eLlamada* this = malloc(sizeof(eLlamada)); //Creo un nuevo empleados con memodia dinamica "malloc"
    if(this == NULL)
    {
        printf("Almacenamiento lleno.\n");
        exit(EXIT_FAILURE); //De ser NULL salgo
    }
    else //De lo contrario parseo a 0 y cadena vacia las variables
    {
        this->id_Llamada = 0;
        strcpy(this->fecha, "");
        this->numero_Cliente = 0;
        this->id_Problema = 0;
        strcpy(this->solucionado, "");
    }
    return this; //Retorno el puntero a la estructura creada
}

eLlamada* _setters(char* var_1, char* var_2, char* var_3, char* var_4, char* var_5)
{
    eLlamada* this = _new();
    if (this != NULL)
    {
        if (!_setId_Llamada(this,atoi(var_1)))
            this = NULL;

        if( !_setFecha(this,var_2))
            this = NULL;

        if( !_setNumero_Cliente(this,atof(var_3)) )
            this = NULL;

        if (!_setId_Problema(this,atoi(var_4)))
            this = NULL;

        if( !_setSolucion(this,var_5))
            this = NULL;

        if(this == NULL)
        {
            printf("\nError al cargar datos, revise la lista.\n");
            free(this);
        }
    }
    return this;
}

int _getters(eLlamada* this, int* var_1, char* var_2, float* var_3, char* var_4, char* var_5)
{
    if (this != NULL)
    {
        if (!_getId_Llamada(this, var_1))
            return 0;

        if (!_getFecha(this, var_2))
            return 0;

        if (!_getNumero_Cliente(this, var_3))
            return 0;

        if (!_getId_Problema(this, var_4))
            return 0;

        if (!_getSolucion(this, var_5))
            return 0;
        return 1;
    }
    return 0;
}

int _setId_Llamada(eLlamada* this,int id_Llamada)
{
    int flag = 0;
    if(this != NULL && id_Llamada >= 0)
    {
        this->id_Llamada = id_Llamada;
        flag=1;
    }
    return flag;
}

int _getId_Llamada(eLlamada* this,int* id_Llamada)
{
    if(this != NULL && id_Llamada != NULL)
    {
        *id_Llamada = this->id_Llamada;
        return 1;
    }
    return 0;
}

int _setFecha(eLlamada* this,char* fecha)
{
    if(this != NULL)
    {
        strncpy(this->fecha, fecha, sizeof(this->fecha));
        return 1;
    }
    return 0;
}

int _getFecha(eLlamada* this,char* fecha)
{
    if (this != NULL)
    {
        strncpy(fecha, this->fecha, sizeof(this->fecha));
        return 1;
    }
    return 0;
}

int _setNumero_Cliente(eLlamada* this,float numero_Cliente)
{
    if(this != NULL && numero_Cliente > 0)
    {
        this->numero_Cliente = numero_Cliente;
        return 1;
    }
    return 0;
}

int _getNumero_Cliente(eLlamada* this,float* numero_Cliente)
{
    int flag = 0;
    if(this != NULL && numero_Cliente != NULL)
    {
        *numero_Cliente = this->numero_Cliente;
        flag=1;
    }
    return flag;
}

int _setId_Problema(eLlamada* this,int id_Problema)
{
    int flag=0;
    if(this != NULL && id_Problema >= 0)
    {
        this->id_Problema = id_Problema;
        flag=1;
    }
    return flag;
}

int _getId_Problema(eLlamada* this,char* id_Problema)
{
    if (this != NULL && id_Problema != NULL)
    {
        switch(this->id_Problema)
        {
        case 1:
            strncpy(id_Problema, "No enciende PC", 50);
            break;
        case 2:
            strncpy(id_Problema, "No funciona mouse", 50);
            break;
        case 3:
            strncpy(id_Problema, "No funciona teclado", 50);
            break;
        case 4:
            strncpy(id_Problema, "No hay internet", 50);
            break;
        case 5:
            strncpy(id_Problema, "No funciona telefono", 50);
            break;
        }
        return 1;
    }
    return 0;
}

int _setSolucion(eLlamada* this,char* solucion)
{
    if(this != NULL)
    {
        strncpy(this->solucionado, solucion, sizeof(this->solucionado));
        return 1;
    }
    return 0;
}

int _getSolucion(eLlamada* this,char* solucion)
{
    if (this != NULL)
    {
        strncpy(solucion, this->solucionado, sizeof(this->solucionado));
        return 1;
    }
    return 0;
}

int _show(eLlamada* this)
{
    int var_1;
    float var_3;
    char var_2[sizeof(this->fecha)], var_4[50], var_5[sizeof(this->solucionado)];

    if (this != NULL && _getters(this, &var_1, var_2, &var_3, var_4, var_5))
    {
        printf(" %3d | %8s | %.0f | %8s | %8s \n", var_1, var_2, var_3, var_4, var_5);
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

        _getId_Llamada(punteroA, &id_A);
        _getId_Llamada(punteroB, &id_B);

        if((id_A) < (id_B)) //Si id de A en menor que id de B cambio al bandera flag a 1
            return 1;
        else if((id_A) == (id_B)) //Si id de A igual que id de B dejo la bandera igual
            return 0;
        else
            return -1;
    }
    return -2;
}

int filter_1 (void* this)
{
    char problema[50];
    if (this != NULL)
    {
        _getId_Problema(this, problema);
        if (!strcmp(problema, "No enciende PC"))
            return 1;
    }
    return 0;
}

int filter_2 (void* this)
{
    char problema[50];
    if (this != NULL)
    {
        _getId_Problema(this, problema);
        if (!strcmp(problema, "No funciona mouse"))
            return 1;
    }
    return 0;
}

int filter_3 (void* this)
{
    char problema[50];
    if (this != NULL)
    {
        _getId_Problema(this, problema);
        if (!strcmp(problema, "No funciona teclado"))
            return 1;
    }
    return 0;
}

int filter_4 (void* this)
{
    char problema[50];
    if (this != NULL)
    {
        _getId_Problema(this, problema);
        if (!strcmp(problema, "No hay internet"))
            return 1;
    }
    return 0;
}

int filter_5 (void* this)
{
    char problema[50];
    if (this != NULL)
    {
        _getId_Problema(this, problema);
        if (!strcmp(problema, "No funciona telefono"))
            return 1;
    }
    return 0;
}








