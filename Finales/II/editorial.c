#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "editorial.h"
#include "utn.h"

eEditorial* _new()
{
    eEditorial* this = malloc(sizeof(eEditorial)); //Creo un nuevo editorial con memodia dinamica "malloc"
    if(this == NULL)
    {
        printf("Almacenamiento lleno.\n");
        exit(EXIT_FAILURE); //De ser NULL salgo
    }
    else //De lo contrario parseo a 0 y cadena vacia las variables
    {
        this->var_1 = 0;
        strcpy(this->var_2, "");
        strcpy(this->var_3, "");
        this->var_4 = 0;
        this->var_5 = 0;
    }
    return this; //Retorno el puntero a la estructura creada
}

eEditorial* _setters(char* var_1,char* var_2, char* var_3, char* var_4, char* var_5)
{
    eEditorial* this = _new();
    int flag = 0;

    if(_setId(this,atoi(var_1)))
        flag=1;

    if(_setTitulo(this,var_2) && flag)
        flag=1;

    if(_setAutor(this,var_3) && flag)
        flag=1;

    if(_setPrecio(this,atof(var_4)) && flag)
        flag=1;

    if(_setIdEditorial(this,atoi(var_5)) && flag)
        flag=1;

    if(!flag)
    {
        printf("\nError al cargar datos, revise la lista.\n");
        free(this);
    }

    return this;
}

int _getters(eEditorial* this, int* var_1, char* var_2, char* var_3, float* var_4, char* var_5)
{
    int flag = 0;
    if (this != NULL)
    {
        if (_getId(this, var_1))
            flag = 1;
        if (_getTitulo(this, var_2) && flag)
            flag = 1;
        if (_getAutor(this, var_3) && flag)
            flag = 1;
        if (_getPrecio(this, var_4) && flag)
            flag = 1;
        if (_getIdEditorial(this, var_5) && flag)
            flag = 1;
    }
    return flag;
}

int _setId(eEditorial* this,int var_1)
{
    int flag = 0;
    if(this != NULL && var_1 >= 0)
    {
        this->var_1 = var_1;
        flag=1;
    }
    return flag;
}

int _getId(eEditorial* this,int* var_1)
{
    int flag = 0;
    if(this != NULL && var_1 != NULL)
    {
        *var_1 = this->var_1;
        flag=1;
    }
    return flag;
}

int _setTitulo(eEditorial* this,char* var_2)
{
    int flag=0;
    if(this != NULL)
    {
        strncpy(this->var_2, var_2, 50);
        flag=1;
    }
    return flag;
}

int _getTitulo(eEditorial* this,char* var_2)
{
    int flag = 0;
    if (this != NULL)
    {
        strncpy(var_2, this->var_2, 50);
        flag = 1;
    }
    return flag;
}

int _setAutor(eEditorial* this,char* var_3)
{
    int flag=0;
    if(this != NULL)
    {
        strncpy(this->var_3, var_3, 50);
        flag=1;
    }
    return flag;
}

int _getAutor(eEditorial* this,char* var_3)
{
    int flag = 0;
    if (this != NULL)
    {
        strncpy(var_3, this->var_3, 50);
        flag = 1;
    }
    return flag;
}

int _setIdEditorial(eEditorial* this,int var_5)
{
    int flag=0;
    if(this != NULL && var_5 >= 0)
    {
        this->var_5 = var_5;
        flag=1;
    }
    return flag;
}

int _getIdEditorial(eEditorial* this,char* var_5)
{
    int flag = 0;
    if (this != NULL && var_5 != NULL)
    {
        switch(this->var_5)
        {
        case 1:
            strncpy(var_5, "PLANETA", 50);
            break;
        case 2:
            strncpy(var_5, "SIGLO XXI EDITORES", 50);
            break;
        case 3:
            strncpy(var_5, "PEARSON", 50);
            break;
        case 4:
            strncpy(var_5, "MINOTAURO", 50);
            break;
        case 5:
            strncpy(var_5, "SALAMANDRA", 50);
            break;
        case 6:
            strncpy(var_5, "PENGUIN BOOKS", 50);
            break;
        }
        flag = 1;
    }
    return flag;
}


int _setPrecio(eEditorial* this,float var_4)
{
    int flag=0;
    if(this != NULL && var_4 > 0)
    {
        this->var_4 = var_4;
        flag=1;
    }
    return flag;
}

int _getPrecio(eEditorial* this,float* var_4)
{
    int flag = 0;
    if(this != NULL && var_4 != NULL)
    {
        *var_4 = this->var_4;
        flag=1;
    }
    return flag;
}

int _show(eEditorial* this)
{
    int flag = 0, var_1;
    float var_4;
    char var_2[50], var_3[50], var_5[50];

    if (_getters(this, &var_1, var_2, var_3, &var_4, var_5))
    {
        printf(" %3d | %8s | %8s | $%.1f | %8s  \n", var_1, var_2, var_3, var_4, var_5);
        flag = 1;
    }
    return flag;
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
    int flag = -2;

    if(punteroA != NULL && punteroB != NULL)
    {
        int id_A, id_B;

        _getId(punteroA, &id_A);
        _getId(punteroB, &id_B);

        if((id_A) < (id_B)) //Si var_1 de A en menor que var_1 de B cambio al bandera flag a 1
            flag = 1 ;
        else if((id_A) == (id_B)) //Si var_1 de A igual que var_1 de B dejo la bandera igual
            flag = 0;
        else
            flag = -1;
    }
    return flag;
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

        _getTitulo(punteroA, aux_A);
        _getTitulo(punteroB, aux_B);
        flag = strcmp(aux_A, aux_B);
    }
    return flag;
}
/** \brief Asigna el var_4 de det libros
 *
 * \param void* this
 * \return Retorna -1 si hay error y si no 0.
 *
 */
void _mapPrecio(void* this)
{
    float var_4;
    char var_5[50];
    if (this != NULL)
    {
        _getIdEditorial(this, var_5);
        _getPrecio(this, &var_4);

        if(!strcmp(var_5, "PLANETA"))
            _setPrecio(this, var_4 - var_4 * 0.2);

        else if(!strcmp(var_5, "SIGLO XXI EDITORES"))
            _setPrecio(this, var_4 - var_4 * 0.1);
    }
}

int _filter_1(void* this)
{
    eEditorial* aux = (eEditorial*)this;
    char var_5[50];
    int retorno = 0;
    if (this != NULL)
    {
        _getIdEditorial(aux, var_5);

        if(!strcmp(var_5, "PLANETA"))
            retorno = 1;
    }
    return retorno;
}

int _filter_2(void* this)
{
    eEditorial* aux = (eEditorial*)this;
    char var_5[50];
    int retorno = 0;
    if (this != NULL)
    {
        _getIdEditorial(aux, var_5);

        if(!strcmp(var_5, "SIGLO XXI EDITORES"))
            retorno = 1;
    }
    return retorno;
}
