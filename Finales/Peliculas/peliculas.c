#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "peliculas.h"
#include "utn.h"

ePelicula* _new()
{
    ePelicula* this = malloc(sizeof(ePelicula)); //Creo un nuevo empleados con memodia dinamica "malloc"
    if(this == NULL)
    {
        printf("Almacenamiento lleno.\n");
        exit(EXIT_FAILURE); //De ser NULL salgo
    }
    else //De lo contrario parseo a 0 y cadena vacia las variables
    {
        this->id = 0;
        strcpy(this->titulo, "");
        this->anio = 0;
        strcpy(this->categoria, "");
    }
    return this; //Retorno el puntero a la estructura creada
}

ePelicula* _setters(char* var_1, char* var_2, char* var_3, char* var_4)
{
    ePelicula* this = _new();
    if (this != NULL)
    {
        if (!_setId(this,atoi(var_1)))
            this = NULL;

        if( !_setTitulo(this,var_2))
            this = NULL;

        if( !_setAnio(this,atoi(var_3)) )
            this = NULL;

        if( !_setCategoria(this,var_4))
            this = NULL;

        if(this == NULL)
        {
            printf("\nError al cargar datos, revise la lista.\n");
            free(this);
        }
    }
    return this;
}

int _getters(ePelicula* this, int* var_1, char* var_2, int* var_3, char* var_4)
{
    if (this != NULL)
    {
        if (!_getId(this, var_1))
            return 0;

        if (!_getTitulo(this, var_2))
            return 0;

        if (!_getAnio(this, var_3))
            return 0;

        if (!_getCategoria(this, var_4))
            return 0;
        return 1;
    }
    return 0;
}

int _setId(ePelicula* this,int id)
{
    int flag = 0;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        flag=1;
    }
    return flag;
}

int _getId(ePelicula* this,int* id)
{
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        return 1;
    }
    return 0;
}

int _setTitulo(ePelicula* this,char* titulo)
{
    if(this != NULL)
    {
        strncpy(this->titulo, titulo, sizeof(this->titulo));
        return 1;
    }
    return 0;
}

int _getTitulo(ePelicula* this,char* titulo)
{
    if (this != NULL)
    {
        strncpy(titulo, this->titulo, sizeof(this->titulo));
        return 1;
    }
    return 0;
}

int _setAnio(ePelicula* this,int anio)
{
    if(this != NULL && anio > 0)
    {
        this->anio = anio;
        return 1;
    }
    return 0;
}

int _getAnio(ePelicula* this,int* anio)
{
    int flag = 0;
    if(this != NULL && anio != NULL)
    {
        *anio = this->anio;
        flag=1;
    }
    return flag;
}

int _setCategoria(ePelicula* this,char* categoria)
{
    if(this != NULL)
    {
        strncpy(this->categoria, categoria, sizeof(this->categoria));
        return 1;
    }
    return 0;
}

int _getCategoria(ePelicula* this,char* categoria)
{
    if (this != NULL)
    {
        strncpy(categoria, this->categoria, sizeof(this->categoria));
        return 1;
    }
    return 0;
}

int _show(ePelicula* this)
{
    int var_1, var_3;
    char var_2[sizeof(this->titulo)], var_4[sizeof(this->categoria)];

    if (this != NULL && _getters(this, &var_1, var_2, &var_3, var_4))
    {
        printf(" %3d | %8s | %2d | %8s \n", var_1, var_2, var_3, var_4);
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
        ePelicula* pA = (ePelicula*) punteroA;
        ePelicula* pB = (ePelicula*) punteroB;

        char aux_A[sizeof(pA->titulo)];
        char aux_B[sizeof(pB->titulo)];

        _getTitulo(pA, aux_A);
        _getTitulo(pB, aux_B);
        flag = strcmp(aux_A, aux_B);
    }
    return flag;
}


LinkedList* depurarPeliculas (LinkedList* this)
{
    LinkedList* list = ll_newLinkedList();
    int id_1, id_2;
    char categoria_1[200], categoria_2[200], categoria_final[200], var_1[10], var_3[10];

    if(this != NULL && list != NULL)   //si el array no es nulo
    {
        for(int i=0; i<ll_len(this); i++) //recorre epliclar
        {
            ePelicula* peli1 = ll_get(this, i); //pelicula 1
            ePelicula* peli2 = ll_get(this, i+1); // pelicula 2
            _getId(peli1, &id_1); //id pelicula 1
            _getId(peli2, &id_2); //id pelicula 2

            if(id_1 == id_2) //si son el mismo id
            {
                _getCategoria(peli1, categoria_1); //genero pelicula 1
                _getCategoria(peli2, categoria_2); //genero pelicula 2
                strcpy(categoria_final, categoria_1);
                strcat(categoria_final, " | ");
                strcat(categoria_final, categoria_2);

                _setCategoria(peli1, categoria_final);
                ll_remove(this, i+1);

                itoa(peli1->id, var_1, 10);
                itoa(peli1->anio, var_3, 10);
                ePelicula* pelicula= _setters(var_1, peli1->titulo, var_3, categoria_final);
                ll_add(list, pelicula);

                for(int j=0; j<ll_len(this); j++) //recorre epliclar
                {
                    ePelicula* peli1 = ll_get(this, j); //pelicula 1
                    _getId(peli1, &id_1); //id pelicula 1
                    ePelicula* peli2 = ll_get(this, j+1); // pelicula 2
                    _getId(peli2, &id_2); //id pelicula 2

                    if(id_1 == id_2) //si son el mismo id
                    {
                        _getCategoria(peli1, categoria_1); //genero pelicula 1
                        _getCategoria(peli2, categoria_2); //genero pelicula 2
                        strcpy(categoria_final, categoria_1);
                        strcat(categoria_final, " | ");
                        strcat(categoria_final, categoria_2);

                        _setCategoria(peli1, categoria_final);
                        ll_remove(this, j+1);

                        itoa(peli1->id, var_1, 10);
                        itoa(peli1->anio, var_3, 10);
                        ePelicula* pelicula= _setters(var_1, peli1->titulo, var_3, categoria_final);
                        ll_add(list, pelicula);
                        break;
                    }
                }
            }
        }
    }
    return list;
}

int filterByCategoria (void* this, void* aux)
{
    char categoria[200];
    if (this != NULL && aux != NULL)
    {
        _getCategoria(this, categoria);
        if (strstr(categoria, aux) != NULL)
            return 1;
    }
    return 0;
}










