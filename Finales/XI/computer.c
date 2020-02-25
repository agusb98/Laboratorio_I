#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "computer.h"
#include "utn.h"

eComputer* _new()
{
    eComputer* this = malloc(sizeof(eComputer)); //Creo un nuevo empleados con memodia dinamica "malloc"
    if(this == NULL)
    {
        printf("Almacenamiento lleno.\n");
        exit(EXIT_FAILURE); //De ser NULL salgo
    }
    else //De lo contrario parseo a 0 y cadena vacia las variables
    {
        this->id = 0;
        strcpy(this->descripcion, "");
        this->precio = 0;
        this->idTipo = 0;
        this->oferta = 0;
    }
    return this; //Retorno el puntero a la estructura creada
}

eComputer* _setters(char* id, char* descripcion, char* precio, char* idTipo, char* oferta)
{
    eComputer* this = _new();
    if (this != NULL)
    {
        if (!_setId(this,atoi(id)))
            this = NULL;

        if( !_setDescripcion(this,descripcion))
            this = NULL;

        if( !_setPrecio(this,atof(precio)))
            this = NULL;

        if( !_setTipo(this,atoi(idTipo)))
            this = NULL;

        if( !_setOferta(this,atof(oferta)))
            this = NULL;

        if(this == NULL)
        {
            printf("\nError al cargar datos, revise la lista.\n");
            free(this);
        }
    }
    return this;
}

int _getters(eComputer* this, int* id, char* descripcion, float* precio, char* idTipo, float* oferta)
{
    if (this != NULL)
    {
        if (!_getId(this, id))
            return 0;

        if (!_getDescripcion(this, descripcion))
            return 0;

        if (!_getPrecio(this, precio))
            return 0;

        if (!_getTipo(this, idTipo))
            return 0;

        if (!_getOferta(this, oferta))
            return 0;

        return 1;
    }
    return 0;
}

int _setId(eComputer* this,int id)
{
    int flag = 0;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        flag=1;
    }
    return flag;
}

int _getId(eComputer* this,int* id)
{
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        return 1;
    }
    return 0;
}

int _setDescripcion(eComputer* this,char* descripcion)
{
    if(this != NULL)
    {
        strncpy(this->descripcion, descripcion, sizeof(this->descripcion));
        return 1;
    }
    return 0;
}

int _getDescripcion(eComputer* this,char* descripcion)
{
    if (this != NULL)
    {
        strncpy(descripcion, this->descripcion, sizeof(this->descripcion));
        return 1;
    }
    return 0;
}

int _setPrecio(eComputer* this,float precio)
{
    if(this != NULL && precio > 0)
    {
        this->precio = precio;
        return 1;
    }
    return 0;
}

int _getPrecio(eComputer* this,float* precio)
{
    int flag = 0;
    if(this != NULL && precio != NULL)
    {
        *precio = this->precio;
        flag=1;
    }
    return flag;
}

int _setTipo(eComputer* this,int idTipo)
{
    if(this != NULL && idTipo > 0)
    {
        this->idTipo = idTipo;
        return 1;
    }
    return 0;
}

int _getTipo(eComputer* this,char* idTipo)
{
    if (this != NULL)
    {
        switch(this->idTipo)
        {
        case 1:
            strcpy(idTipo, "DESKTOP");
            break;
        case 2:
            strcpy(idTipo, "LAPTOP");
            break;
        }
        return 1;
    }
    return 0;
}

int _setOferta(eComputer* this,float oferta)
{
    if(this != NULL)
    {
        this->oferta = oferta;
        return 1;
    }
    return 0;
}

int _getOferta(eComputer* this,float* oferta)
{
    int flag = 0;
    if(this != NULL && oferta != NULL)
    {
        *oferta = this->oferta;
        flag=1;
    }
    return flag;
}

int _show(eComputer* this)
{
    int id;
    char descripcion[sizeof(this->descripcion)], idTipo[200];
    float precio, oferta;

    if (this != NULL && _getters(this, &id, descripcion, &precio, idTipo, &oferta))
    {
        printf(" %3d | %8s | %.1f | %8s | %.1f \n", id, descripcion, precio, idTipo, oferta);
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

/** \brief Asigna el sueldo de determinado puntero
 *
 * \param void* this
 * \return (1) if OK - (0) if this is NULL pointer
 *
 */

int _mapPrecio (void* this)
{
    char tipo[200];
    float precio;
    if (this != NULL)
    {
        eComputer* pA = (eComputer*) this;
        _getTipo(pA, tipo);
        _getPrecio(pA, &precio);

        if (precio > 20000 && !strcmp("DESKTOP", tipo))
            _setOferta(pA, precio * 0.5);
        else
            _setOferta(pA, 0);

        return 1;
    }
    return 0;
}


/** \brief Asigna el sueldo de determinado puntero
 *
 * \param void* this
 * \return (1) if OK - (-1) if this is NULL pointer - (0) if cant find
 *
 */

int _filterDesktop(void* this)
{
    eComputer* pA = (eComputer*) this;
    char tipo[200];
    int flag = 0;

    if (pA != NULL)
    {
        _getTipo(pA, tipo);

        if(!strcmp(tipo, "DESKTOP"))
            flag = 1;
    }
    return flag;
}









