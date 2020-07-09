#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "entregas.h"
#include "utn.h"

eEntregas* _new()
{
    eEntregas* this = malloc(sizeof(eEntregas)); //Creo un nuevo entregas con memodia dinamica "malloc"
    if(this == NULL)
    {
        printf("Almacenamiento lleno.\n");
        exit(EXIT_FAILURE); //De ser NULL salgo
    }
    else //De lo contrario parseo a 0 y cadena vacia las variables
    {
        this->id = 0;
        strcpy(this->tipo, "");
        this->cantidad = 0;
        this->precio = 0;
    }
    return this; //Retorno el puntero a la estructura creada
}

eEntregas* _setters(char* idStr,char* tipoStr, char* cantidadStr, char* precioStr)
{
    eEntregas* this = _new();
    int flag = 0;

    if(_setId(this,atoi(idStr)))
        flag=1;

    if(_setTipo(this,tipoStr) && flag)
        flag=1;

    if(_setCantidad(this,atoi(cantidadStr)))
        flag=1;

    if(_setPrecio(this,atof(precioStr)) && flag)
        flag=1;

    if(!flag)
    {
        printf("\nError al cargar datos, revise la lista.\n");
        free(this);
    }

    return this;
}

int _getters(eEntregas* this, int* id, char* tipo, int* cantidad, float* precio)
{
    int flag = 0;
    if (this != NULL)
    {
        if (_getId(this, id))
            flag = 1;
        if (_getTipo(this, tipo) && flag)
            flag = 1;
        if (_getCantidad(this, cantidad) && flag)
            flag = 1;
        if (_getPrecio(this, precio) && flag)
            flag = 1;
    }
    return flag;
}

int _setId(eEntregas* this,int id)
{
    int flag = 0;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        flag=1;
    }
    return flag;
}

int _getId(eEntregas* this,int* id)
{
    int flag = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        flag=1;
    }
    return flag;
}

int _setTipo(eEntregas* this,char* tipo)
{
    int flag=0;
    if(this != NULL)
    {
        strncpy(this->tipo, tipo, sizeof(this->tipo));
        flag=1;
    }
    return flag;
}

int _getTipo(eEntregas* this,char* tipo)
{
    int flag = 0;
    if (this != NULL)
    {
        strncpy(tipo, this->tipo, sizeof(this->tipo));
        flag = 1;
    }
    return flag;
}

int _setCantidad(eEntregas* this,int cantidad)
{
    int flag = 0;
    if(this != NULL && cantidad >= 0)
    {
        this->cantidad = cantidad;
        flag=1;
    }
    return flag;
}

int _getCantidad(eEntregas* this,int* cantidad)
{
    int flag = 0;
    if(this != NULL && cantidad != NULL)
    {
        *cantidad = this->cantidad;
        flag=1;
    }
    return flag;
}

int _setPrecio(eEntregas* this,float precio)
{
    int flag=0;
    if(this != NULL && precio > 0)
    {
        this->precio = precio;
        flag=1;
    }
    return flag;
}

int _getPrecio(eEntregas* this,float* precio)
{
    int flag = 0;
    if(this != NULL && precio != NULL)
    {
        *precio = this->precio;
        flag=1;
    }
    return flag;
}

int _show(eEntregas* this)
{
    int flag = 0, id, cantidad;
    float precio;
    char tipo[50];

    if (_getters(this, &id, tipo, &cantidad, &precio))
    {
        printf(" %3d | %8s | %3d | $%.1f \n", id, tipo, cantidad, precio);
        flag = 1;
    }
    return flag;
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
    int flag = -2;

    if(punteroA != NULL && punteroB != NULL)
    {
        int id_A, id_B;

        _getId(punteroA, &id_A);
        _getId(punteroB, &id_B);

        if((id_A) < (id_B)) //Si id de A en menor que id de B cambio al bandera flag a 1
            flag = 1 ;
        else if((id_A) == (id_B)) //Si id de A igual que id de B dejo la bandera igual
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

        _getTipo(punteroA, aux_A);
        _getTipo(punteroB, aux_B);
        flag = strcmp(aux_A, aux_B);
    }
    return flag;
}

int bultos_Total(void* this)
{
    int total = 0, cantidad;
    if (this != NULL)
    {
        for(int i=0; i<ll_len(this); i++) //Recorro el array de datos
        {
            void* aux = (void*)ll_get(this, i); //Le asigno al puntero void "this" lo que retorna "ll_get()"
            if (aux != NULL)
            {
                _getCantidad(aux, &cantidad);
                total += cantidad;
            }
        }
    }
    else
        total = -1;
    return total;
}

float importe_Total(void* this)
{
    float total = 0, importe;
    if (this != NULL)
    {
        for(int i=0; i<ll_len(this); i++) //Recorro el array de datos
        {
            void* aux = (void*)ll_get(this, i); //Le asigno al puntero void "this" lo que retorna "ll_get()"
            if (aux != NULL)
            {
                _getPrecio(aux, &importe);
                total += importe;
            }
        }
    }
    else
        total = -1;
    return total;
}

int tipo_1(void* this)
{
    int flag = 0;
    char tipo[50];
    if (this != NULL)
    {
        _getTipo(this, tipo);
        if (strcmp(tipo, "GOLD") == 0)
            flag = 1;
    }
    return flag;
}

int tipo_2(void* this)
{
    int flag = 0;
    char tipo[50];
    if (this != NULL)
    {
        _getTipo(this, tipo);
        if (strcmp(tipo, "REGULAR") == 0)
            flag = 1;
    }
    return flag;
}

int tipo_3(void* this)
{
    int flag = 0;
    char tipo[50];
    if (this != NULL)
    {
        _getTipo(this, tipo);
        if (strcmp(tipo, "PLUS") == 0)
            flag = 1;
    }
    return flag;
}
